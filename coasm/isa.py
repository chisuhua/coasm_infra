# coasm/isa.py
"""Enhanced core data models and loading logic for COASM ISA."""

import sys
from typing import Dict, List, Optional, Tuple, Any, Union, Set
from dataclasses import dataclass, asdict, field
import hashlib

# --- Data Models ---
@dataclass(frozen=True)
class InstructionField:
    """Represents a single field within an instruction format."""
    name: str
    bit_start: int
    bit_width: int

    def bit_end(self) -> int: return self.bit_start + self.bit_width - 1
    def mask(self) -> int: return ((1 << self.bit_width) - 1) << self.bit_start

@dataclass(frozen=True)
class InstructionFormat:
    """Represents an instruction encoding format."""
    name: str
    encoding_bit_start: int
    encoding_width: int
    encoding_value: int
    fields: Tuple[InstructionField, ...] = field(default_factory=tuple)
    def get_encoding_value_hex(self) -> str: return f"0x{self.encoding_value:X}"
    def get_field_by_name(self, name: str) -> Optional[InstructionField]:
        return next((f for f in self.fields if f.name == name), None)

@dataclass(frozen=True)
class InstructionType:
    """Represents an instruction type/category."""
    name: str
    value: int

@dataclass(frozen=True)
class Instruction:
    """Represents a detailed instruction definition."""
    mnemonic: str
    format_name: str
    opcode: int
    type_name: str
    dst_reg: int
    def get_opcode_hex(self) -> str: return f"0x{self.opcode:X}"

# --- ISA Container Class ---
class ISAModel:
    def __init__(self):
        self.instructions_list: List[str] = []
        self.formats_dict: Dict[str, InstructionFormat] = {}
        self.types_dict: Dict[str, InstructionType] = {}
        self.instructions_details_dict: Dict[str, Instruction] = {}
        self._validated: bool = False
        self._validation_errors: List[str] = []
        self._checksum: Optional[str] = None

    def get_instructions(self) -> List[str]: return self.instructions_list
    def get_format(self, name: str) -> Optional[InstructionFormat]: return self.formats_dict.get(name)
    def get_all_formats(self) -> Dict[str, InstructionFormat]: return self.formats_dict
    def get_type(self, name: str) -> Optional[InstructionType]: return self.types_dict.get(name)
    def get_all_types(self) -> Dict[str, InstructionType]: return self.types_dict
    def get_instruction(self, mnemonic: str) -> Optional[Instruction]: return self.instructions_details_dict.get(mnemonic)
    def get_all_instructions(self) -> Dict[str, Instruction]: return self.instructions_details_dict

    def validate(self, strict: bool = False) -> bool:
        if self._validated:
            if self._validation_errors:
                if strict: raise ValueError(f"ISA Model validation failed (cached):\n" + "\n".join(self._validation_errors))
                return False
            return True
        self._validation_errors = []
        print("Starting ISA model validation...")
        # Basic validation checks would go here (omitted for brevity)
        # Check format references in instructions_details
        format_names: Set[str] = set(self.formats_dict.keys())
        type_names: Set[str] = set(self.types_dict.keys())
        for mnemonic, instr in self.instructions_details_dict.items():
            if instr.format_name not in format_names:
                self._validation_errors.append(f"Instruction '{mnemonic}': References undefined format '{instr.format_name}'")
            if instr.type_name not in type_names:
                self._validation_errors.append(f"Instruction '{mnemonic}': References undefined type '{instr.type_name}'")
        detail_keys = set(self.instructions_details_dict.keys())
        list_keys = set(self.instructions_list)
        missing_in_details = list_keys - detail_keys
        if missing_in_details:
             self._validation_errors.append(f"Instructions in 'instructions' list but missing from 'instructions_details': {missing_in_details}")
        self._validated = True
        if self._validation_errors:
            error_msg = "ISA Model validation failed:\n" + "\n".join(self._validation_errors)
            print(error_msg, file=sys.stderr)
            if strict: raise ValueError(error_msg)
            return False
        else:
            print("ISA model validation passed.")
            try:
                import json
                data_to_hash = {k: v for k, v in asdict(self).items() if k != '_checksum'} # Exclude checksum
                self._checksum = hashlib.sha256(json.dumps(data_to_hash, sort_keys=True, default=str).encode('utf-8')).hexdigest()
                print(f"ISA model checksum (SHA256): {self._checksum[:16]}...")
            except Exception as e:
                print(f"Warning: Could not calculate ISA model checksum: {e}", file=sys.stderr)
            return True

    def is_valid(self) -> bool:
        if not self._validated: return self.validate(strict=False)
        return len(self._validation_errors) == 0

    def get_validation_errors(self) -> List[str]:
        if not self._validated: self.validate(strict=False)
        return self._validation_errors.copy()

    def get_checksum(self) -> Optional[str]:
        if not self._validated: self.validate(strict=False)
        return self._checksum

# --- Loading and Populating Logic ---
def _populate_isa_model(parsed_data: Dict[str, Any], model: ISAModel):
    """Populates an ISAModel instance with parsed data."""
    model.instructions_list = parsed_data.get('instructions', [])
    formats_data = parsed_data.get('formats', {})
    for name, fmt_data in formats_data.items():
        enc_info = fmt_data.get('encoding', (0, 0, 0))
        enc_val = int(enc_info[2]) if len(enc_info) > 2 else 0
        # Placeholder: fields are not parsed from summary table
        fields_tuple = ()
        model.formats_dict[name] = InstructionFormat(
            name=name,
            encoding_bit_start=int(enc_info[0]) if len(enc_info) > 0 else 0,
            encoding_width=int(enc_info[1]) if len(enc_info) > 1 else 0,
            encoding_value=enc_val,
            fields=fields_tuple
        )
    types_data = parsed_data.get('types', {})
    for name, value in types_data.items():
        try: val_int = int(value)
        except (ValueError, TypeError): val_int = 0; print(f"Warning: Invalid value '{value}' for type '{name}', defaulting to 0.", file=sys.stderr)
        model.types_dict[name] = InstructionType(name, val_int)
    instrs_data = parsed_data.get('instructions_details', {})
    for mnemonic, details in instrs_data.items():
        try: op = int(details.get('opcode', 0))
        except (ValueError, TypeError): op = 0; print(f"Warning: Invalid opcode for instruction '{mnemonic}', defaulting to 0.", file=sys.stderr)
        try: dst_reg = int(details.get('dst_reg', 0))
        except (ValueError, TypeError): dst_reg = 0; print(f"Warning: Invalid dst_reg for instruction '{mnemonic}', defaulting to 0.", file=sys.stderr)
        model.instructions_details_dict[mnemonic] = Instruction(
            mnemonic=mnemonic,
            format_name=details.get('format', 'UNKNOWN'),
            opcode=op,
            type_name=details.get('type', 'UNKNOWN'),
            dst_reg=dst_reg
        )

def load_isa_from_dsl(filepath: str) -> ISAModel:
    """Loads, parses (Markdown), and creates a validated ISAModel from a .md file."""
    print(f"Loading ISA definition from '{filepath}' (Markdown format)...")
    try:
        from coasm.dsl_parser import parse_markdown_dsl
        parsed_data = parse_markdown_dsl(filepath)
    except Exception as e:
        print(f"Error parsing Markdown DSL content in '{filepath}': {e}", file=sys.stderr)
        raise
    print("Populating ISA model from parsed Markdown data...")
    model = ISAModel()
    _populate_isa_model(parsed_data, model)
    print(f"Loaded ISA model with {len(model.instructions_list)} instructions, "
          f"{len(model.formats_dict)} formats, "
          f"{len(model.types_dict)} types, and "
          f"{len(model.instructions_details_dict)} detailed instruction definitions.")
    return model
