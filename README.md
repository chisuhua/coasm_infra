# COASM Infrastructure

A modular framework for defining, parsing, and generating code for the COASM (Custom Optimized Assembly) instruction set architecture.

## Overview

This project provides:

1.  A structured definition format (`coasm_isa.dsl`) for the COASM ISA.
2.  A Python library (`coasm/`) for parsing the definition and representing it as objects.
3.  A code generator (`generator/`) that uses the library to produce files for various tools (e.g., ANTLR parser, assembler, disassembler).
4.  A command-line script (`scripts/coasm_gen.py`) to run the generator.

## Structure

*   `coasm_isa.dsl`: The single source of truth for the ISA definition.
*   `coasm/`: The core Python library.
    *   `isa.py`: Data models (`InstructionFormat`, `Instruction`) and loading logic.
    *   `dsl_parser.py`: Parser for the `coasm_isa.dsl` format.
    *   `utils.py`: Utility functions (dump, compare).
*   `generator/`: Code generation logic.
    *   `generator.py`: Functions to generate specific file types.
    *   `templates/`: Template files (e.g., `coasm.g4.tpl`).
*   `scripts/`: Command-line entry points.
    *   `coasm_gen.py`: The main generator script.
*   `generated/`: (Default) Output directory for generated files (not committed).

## Getting Started

1.  Ensure you have Python 3 installed.
2.  Define your ISA in `coasm_isa.dsl`.
3.  Run the generator script:
    ```bash
    python scripts/coasm_gen.py -i coasm_isa.dsl -o generated
    ```
4.  The generated files will be placed in the `generated/` directory.

## Library Usage (coasm)

The `coasm` package can be imported into other Python projects to programmatically access ISA information.

```python
import coasm

# Load ISA from DSL
instructions, formats, types, details = coasm.load_isa_from_dsl('path/to/coasm_isa.dsl')

# Access data
print(f"Instruction 'V_ADD_F32' format: {details['V_ADD_F32'].format_name}")
print(f"Format 'VOP2' encoding value: {formats['VOP2'].get_encoding_value_hex()}")

# Dump to file for comparison/debugging
coasm.dump_isa_to_file(instructions, formats, types, details, 'dump.json')

# Compare two ISA definitions
# diff = coasm.compare_isa_files('isa_v1.dsl', 'isa_v2.dsl')
# print(diff)
