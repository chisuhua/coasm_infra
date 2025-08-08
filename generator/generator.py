# generator/generator.py
"""Core logic for generating files from the ISAModel."""

import os
import sys
import subprocess
import tempfile
import shutil
import glob # Add glob for easier file finding

from typing import List, Dict, Any, Optional
try:
    from jinja2 import Environment, FileSystemLoader, Template
except ImportError:
    print("Error: Jinja2 library is required. Please install it using 'pip install jinja2'", file=sys.stderr)
    sys.exit(1)

from coasm.isa import ISAModel, InstructionFormat, InstructionType, Instruction

TEMPLATES_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "templates")
COASM_G4_TEMPLATE_NAME = "coasm.g4.tpl"
COASM_SUMMARY_H_TEMPLATE_NAME = "coasm_summary.h.tpl"

# --- Generation Functions ---
# (generate_g4, generate_opcodes_def, generate_opcodes_fmt_def,
#  generate_instr_structs_h, generate_cpp_summary_header 保持不变或按之前讨论修改)

def generate_g4(isa_model: ISAModel, template_path: str, output_path: str) -> bool:
    """
    Generates the coasm.g4 file using the instructions list from the ISAModel.
    Assumes ISAModel has an is_valid() method and get_instructions() method.
    """
    instructions_list = isa_model.get_instructions()
    if not instructions_list:
        print("Warning: No instructions found for grammar. Creating minimal grammar.")
        instruction_tokens = "'NOP'"
    else:
        instruction_tokens = ' | '.join([f"'{instr}'" for instr in instructions_list])
    try:
        template_dir = os.path.dirname(template_path)
        template_filename = os.path.basename(template_path)

        if not os.path.exists(template_path):
             print(f"Error: Template file '{template_path}' not found.", file=sys.stderr)
             return False

        env = Environment(loader=FileSystemLoader(template_dir))
        template = env.get_template(template_filename)

        # Render the template with the instruction tokens
        # The placeholder in coasm.g4.tpl is {{ instructions_placeholder }}
        rendered_content = template.render(instructions_placeholder=instruction_tokens)

        # Write the rendered content to the output file
        with open(output_path, 'w') as f:
            f.write(rendered_content)

        print(f"Successfully generated '{output_path}' (grammar).")
        return True
    except Exception as e:
        print(f"Error generating '{output_path}': {e}", file=sys.stderr)
        return False

def generate_cpp_summary_header(isa_model: ISAModel, template_path: str, output_path: str) -> bool:
    """Generates a C++ header summarizing key ISA definitions using a Jinja2 template."""
    try:
        template_data = {'instructions': [], 'types': [], 'formats': []}
        instructions_sorted = sorted(isa_model.get_all_instructions().items())
        for i, (mnemonic, _) in enumerate(instructions_sorted):
             template_data['instructions'].append({'name': mnemonic, 'value': i})
        types_sorted = sorted(isa_model.get_all_types().items())
        for name, typ in types_sorted:
            template_data['types'].append({'name': name, 'value': typ.value})
        if "UNKNOWN_TYPE" not in isa_model.get_all_types():
             template_data['types'].append({'name': 'UNKNOWN_TYPE', 'value': 255})
        formats_sorted = sorted(isa_model.get_all_formats().keys())
        for i, name in enumerate(formats_sorted):
            template_data['formats'].append({'name': name, 'value': i})
        if "UNKNOWN_FORMAT" not in isa_model.get_all_formats():
             template_data['formats'].append({'name': 'UNKNOWN_FORMAT', 'value': 255})
        template_dir = os.path.dirname(template_path)
        template_filename = os.path.basename(template_path)
        if not os.path.exists(os.path.join(template_dir, template_filename)):
             print(f"Error: Template file '{template_path}' not found.", file=sys.stderr)
             return False
        env = Environment(loader=FileSystemLoader(template_dir))
        template = env.get_template(template_filename)
        rendered_content = template.render(**template_data)
        with open(output_path, 'w') as f: f.write(rendered_content)
        print(f"Successfully generated '{output_path}' (C++ summary header).")
        return True
    except Exception as e:
        print(f"Error generating '{output_path}': {e}", file=sys.stderr)
        return False


def run_antlr(g4_path: str, output_dir: str, language: str = "Cpp", antlr_jar_path: Optional[str] = None) -> bool:
    """
    Runs the ANTLR tool to generate parser/lexer code.
    Note: ANTLR might generate files in a subdirectory of output_dir based on the grammar name.
    """
    # --- Configuration ---
    if not antlr_jar_path:
        # Fallback to environment variable or default path
        antlr_jar_path = os.environ.get("ANTLR_JAR_PATH", "/usr/local/lib/antlr-4.13.1-complete.jar")
        # --- 修改点：更合理的默认路径查找 ---
        # 如果环境变量没设，尝试在常见的安装路径查找
        if not os.path.exists(antlr_jar_path):
             common_paths = [
                 "./antlr4/antlr-4.13.2-complete.jar", # 项目本地
                 "/usr/local/lib/antlr-4.13.2-complete.jar",
                 "/usr/share/java/antlr4/antlr-4.13.2-complete.jar", # Ubuntu/Debian?
                 "/opt/antlr/antlr-4.13.2-complete.jar", # 手动安装到 /opt
                 # 可以根据需要添加更多路径
             ]
             for path in common_paths:
                 if os.path.exists(path):
                     antlr_jar_path = path
                     print(f"Found ANTLR JAR at '{antlr_jar_path}'.", file=sys.stderr) # 可选：提示找到的路径
                     break

    if not os.path.exists(antlr_jar_path):
        print(f"Error: ANTLR JAR not found at '{antlr_jar_path}'. Please set ANTLR_JAR_PATH environment variable or ensure it's in a standard location.", file=sys.stderr)
        return False

    if not os.path.exists(g4_path):
        print(f"Error: Grammar file '{g4_path}' not found.", file=sys.stderr)
        return False

    # Ensure output directory exists
    os.makedirs(output_dir, exist_ok=True)

    # --- Build ANTLR command ---
    cmd = [
        "java", "-jar", antlr_jar_path,
        "-Dlanguage=" + language,
        # Add visitor/listener options if needed by your tools
        # "-visitor", # 如果需要 Visitor 模式
        # "-no-listener", # 如果不需要 Listener 模式 (或者省略此行以生成 Listener)
        "-o", output_dir, # 直接输出到用户指定的目录
        g4_path
    ]

    print(f"Running ANTLR command: {' '.join(cmd)}")

    # --- Execute ANTLR ---
    try:
        # --- 修改点：捕获 stdout 和 stderr ---
        result = subprocess.run(cmd, check=True, capture_output=True, text=True)
        # ANTLR usually outputs to stdout on success
        if result.stdout:
            print("ANTLR Output:", result.stdout)
        print(f"ANTLR successfully generated {language} parser/lexer code in '{output_dir}'.")
        print(f"  (Note: Files might be in a subdirectory like '{output_dir}/<GrammarName>/')")
        return True
    except subprocess.CalledProcessError as e:
        print(f"Error running ANTLR:", file=sys.stderr)
        print(f"Command: {' '.join(e.cmd)}", file=sys.stderr)
        print(f"Return Code: {e.returncode}", file=sys.stderr)
        # --- 修改点：打印 stdout 和 stderr ---
        if e.stdout:
            print(f"Standard Output:\n{e.stdout}", file=sys.stderr)
        if e.stderr: # ANTLR 错误信息通常在 stderr
            print(f"Standard Error:\n{e.stderr}", file=sys.stderr)
        return False
    except FileNotFoundError:
        print(f"Error: Java or ANTLR JAR not found. Check your PATH and ANTLR_JAR_PATH.", file=sys.stderr)
        return False

