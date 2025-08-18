#!/bin/bash
SCRIPT_DIR=$(cd $(dirname "${BASH_SOURCE[0]}") >/dev/null && pwd)

python scripts/coasm_gen.py -i coasm_isa.md -o generated --antlr --generate-cpp-header

