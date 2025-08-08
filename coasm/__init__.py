# coasm/__init__.py
"""COASM Infrastructure Core Library."""

from .isa import ISAModel, load_isa_from_dsl, InstructionFormat, InstructionType, Instruction
# Re-export key functions/classes for convenience if needed
# from .utils import dump_isa_to_file, compare_isa_files

__all__ = [
    'ISAModel',
    'load_isa_from_dsl',
    'InstructionFormat',
    'InstructionType',
    'Instruction',
    # 'dump_isa_to_file',
    # 'compare_isa_files'
]

__version__ = '0.1.0'
