# coasm/utils.py
"""Utility functions for the COASM library (working with files, external tools)."""

import sys
import json
import os
from typing import Dict, Any, List
from .isa import ISAModel, load_isa_from_dsl, compare_isa_models, dump_isa_model_to_dict

def dump_isa_model_to_file(model: ISAModel, filepath: str, format: str = 'json') -> None:
    """Dumps the ISA model to a file."""
    if format.lower() != 'json':
        raise ValueError("Only 'json' format is currently supported for dumping.")

    try:
        data_dict = dump_isa_model_to_dict(model)
        with open(filepath, 'w') as f:
            json.dump(data_dict, f, indent=4, default=str) # default=str handles non-serializable objects if any slip through
        print(f"ISA model successfully dumped to '{filepath}'")
    except Exception as e:
        print(f"Error dumping ISA model to '{filepath}': {e}", file=sys.stderr)
        raise

def compare_isa_model_files(filepath1: str, filepath2: str) -> Dict[str, List[str]]:
    """Compares two ISA models loaded from .dsl files."""
    try:
        if not os.path.exists(filepath1):
             raise FileNotFoundError(f"File not found: {filepath1}")
        if not os.path.exists(filepath2):
             raise FileNotFoundError(f"File not found: {filepath2}")

        model1 = load_isa_from_dsl(filepath1)
        model2 = load_isa_from_dsl(filepath2)
        return compare_isa_models(model1, model2)
    except Exception as e:
        print(f"Error comparing ISA model files '{filepath1}' and '{filepath2}': {e}", file=sys.stderr)
        raise

# Example usage function
def example_utils():
     # Example: Compare two versions of the ISA
    # diff = compare_isa_model_files('coasm_isa_v1.dsl', 'coasm_isa_v2.dsl')
    # if not any(diff.values()):
    #     print("No differences found between the two ISA definitions.")
    # else:
    #     print("Differences found:")
    #     for category, items in diff.items():
    #         if items:
    #             print(f"  {category.capitalize()}:")
    #             for item in items:
    #                 print(f"    - {item}")

    # Example: Dump current model
    # model = load_isa_from_dsl('coasm_isa.dsl')
    # dump_isa_model_to_file(model, 'isa_dump.json')
    pass
