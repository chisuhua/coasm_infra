#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Command-line interface for the COASM code generator."""

import argparse
import os
import sys

project_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, project_root)

try:
    from coasm.isa import load_isa_from_dsl, ISAModel
    from generator.generator import generate_g4, run_antlr, generate_cpp_summary_header
except ImportError as e:
    print(f"Error importing coasm_infra modules: {e}", file=sys.stderr)
    print("Please ensure the script is run from the coasm_infra project root directory.", file=sys.stderr)
    sys.exit(1)

from generator.generator import TEMPLATES_DIR, COASM_G4_TEMPLATE_NAME, COASM_SUMMARY_H_TEMPLATE_NAME

def main():
    """Main CLI entry point."""
    parser = argparse.ArgumentParser(description="Generate COASM tool files from ISA definition.")
    parser.add_argument("-i", "--input", required=True, help="Path to the coasm_isa.md file")
    parser.add_argument("-o", "--output-dir", default="./generated", help="Output directory for generated files (default: ./generated)")
    parser.add_argument("--antlr", action="store_true", help="Also run ANTLR to generate C++ parser/lexer code")
    parser.add_argument("--antlr-output-dir", default=None, help="Directory for ANTLR-generated C++ files (default: <output-dir>/antlr_generated)")
    parser.add_argument("--generate-cpp-header", action="store_true", help="Generate a C++ summary header (coasm_summary.h)")
    parser.add_argument("--cpp-header-output", default=None, help="Path for the generated C++ summary header (default: <output-dir>/coasm_summary.h)")

    args = parser.parse_args()

    dsl_path = args.input
    output_dir = args.output_dir
    run_antlr_flag = args.antlr
    antlr_output_dir = args.antlr_output_dir
    gen_cpp_header_flag = args.generate_cpp_header
    cpp_header_output = args.cpp_header_output

    os.makedirs(output_dir, exist_ok=True)

    print(f"Loading ISA definition from '{dsl_path}'...")
    try:
        isa_model: ISAModel = load_isa_from_dsl(dsl_path)
        if not isa_model.validate(strict=False):
             print("Warning: Loaded ISA model has validation errors. Proceeding anyway...", file=sys.stderr)
             for err in isa_model.get_validation_errors():
                 print(f"  - {err}", file=sys.stderr)
        else:
             print("ISA model loaded and validated successfully.")
    except Exception as e:
        print(f"Failed to load or validate ISA definition: {e}", file=sys.stderr)
        sys.exit(1)

    print("Generating files...")
    g4_template_path = os.path.join(TEMPLATES_DIR, COASM_G4_TEMPLATE_NAME)
    g4_output_path = os.path.join(output_dir, "coasm.g4")
    g4_generated = False
    try:
        if generate_g4(isa_model, g4_template_path, g4_output_path):
            g4_generated = True
        else:
            raise Exception("generate_g4 returned False")
    except Exception as e:
        print(f"Failed to generate coasm.g4: {e}", file=sys.stderr)
        sys.exit(1)

    if gen_cpp_header_flag and g4_generated:
        cpp_header_output = cpp_header_output or os.path.join(output_dir, "coasm_summary.h")
        cpp_header_template_path = os.path.join(TEMPLATES_DIR, COASM_SUMMARY_H_TEMPLATE_NAME)
        try:
            generate_cpp_summary_header(isa_model, cpp_header_template_path, cpp_header_output)
        except Exception as e:
            print(f"Warning: Failed to generate C++ summary header: {e}", file=sys.stderr)

    if run_antlr_flag and g4_generated:
        if antlr_output_dir is None:
            antlr_output_dir = os.path.join(output_dir, "antlr_generated")
        print(f"Running ANTLR on '{g4_output_path}'...")
        if not run_antlr(g4_output_path, antlr_output_dir, language="Cpp"):
            print("ANTLR generation failed.", file=sys.stderr)
        else:
            print(f"ANTLR C++ code generated in '{antlr_output_dir}'.")

    print("Process completed.")

if __name__ == "__main__":
    main()
