# coasm/dsl_parser.py
"""Parser for the coasm_isa.md (Markdown) format."""

import sys
import re
from typing import Dict, List, Tuple, Any, Union, Optional
# Note: This basic parser uses string manipulation.
# For more robust parsing, consider using the `markdown` library to parse to an AST.

def parse_markdown_dsl(filepath: str) -> Dict[str, Any]:
    """
    Parses the coasm_isa.md file and extracts structured data.
    This is a basic line-by-line parser.
    """
    data: Dict[str, Any] = {
        'instructions': [],
        'formats': {},
        'types': {},
        'instructions_details': {},
        'format_layouts': {} # New: Store global layout lines
    }

    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            lines = [line.rstrip('\n') for line in f]
    except Exception as e:
        print(f"Error reading file '{filepath}': {e}", file=sys.stderr)
        raise

    current_section = None
    current_subsection = None
    collecting_list = False
    collecting_table = False
    current_table_headers: List[str] = []
    current_table_rows: List[List[str]] = []

    i = 0
    while i < len(lines):
        line = lines[i].strip()
        i += 1

        if not line:
            continue

        # --- Detect Sections (##) ---
        if line.startswith('## '):
            current_section = line[3:].strip()
            collecting_list = False
            collecting_table = False
            current_table_headers = []
            current_table_rows = []
            # print(f"[DEBUG] Found section: {current_section}") # Debug
            continue

        # --- Detect Subsections (###) ---
        if line.startswith('### ') and current_section:
            current_subsection = line[4:].strip()
            collecting_list = False
            collecting_table = False
            current_table_headers = []
            current_table_rows = []
            # print(f"[DEBUG] Found subsection: {current_subsection}") # Debug
            
            # Special handling for Global Layout View
            if 'Format Field Layouts' in current_subsection:
                j = i
                layouts_found = False
                while j < len(lines):
                    layout_line = lines[j].strip()
                    if layout_line.startswith('- **') and '**:' in layout_line:
                        match = re.match(r'- \*\*(\w+)\*\*: `(.+)`', layout_line)
                        if match:
                            fmt_name, layout_str = match.groups()
                            data['format_layouts'][fmt_name] = layout_str
                            layouts_found = True
                            # print(f"[DEBUG] Layout for {fmt_name}: {layout_str}") # Debug
                    elif layout_line.startswith('##'):
                        break # Next major section
                    j += 1
                if layouts_found:
                    # print(f"[DEBUG] Finished collecting layouts.") # Debug
                    pass
                i = j # Advance outer loop index
            continue

        # --- Collect Instruction Mnemonics List ---
        if current_section == "Instruction Mnemonics (for coasm.g4 lexer)":
            if line.startswith('- '):
                mnemonic = line[2:].strip().rstrip(',') # Remove trailing comma if present
                if mnemonic and not mnemonic.startswith('(') and not mnemonic.startswith('.'):
                    data['instructions'].append(mnemonic)
                    # print(f"[DEBUG] Added instruction: {mnemonic}") # Debug
            continue

        # --- Detect Tables (| ... |) ---
        if line.startswith('|'):
            if not collecting_table:
                collecting_table = True
                current_table_headers = [h.strip() for h in line.strip('|').split('|')]
                # print(f"[DEBUG] Started table with headers: {current_table_headers}") # Debug
                # Expect separator row next
                if i < len(lines):
                    sep_line = lines[i].strip()
                    if '|' in sep_line and all(c in '|-: ' for c in sep_line):
                        i += 1 # Skip separator row
                continue
            else:
                # Data row
                row_data = [cell.strip() for cell in line.strip('|').split('|')]
                # print(f"[DEBUG] Adding table row: {row_data}") # Debug
                current_table_rows.append(row_data)
                continue
        else:
            # If we were collecting a table and hit a non-table line, finish the table
            if collecting_table and current_table_headers:
                # print(f"[DEBUG] Finishing table collection.") # Debug
                process_collected_table(current_section, current_subsection, current_table_headers, current_table_rows, data)
                collecting_table = False
                current_table_headers = []
                current_table_rows = []
            # Else, continue looking for sections/tables/lists

    # Process any remaining table at the end of the file
    if collecting_table and current_table_headers:
        process_collected_table(current_section, current_subsection, current_table_headers, current_table_rows, data)

    return data

def process_collected_table(section: str, subsection: str, headers: List[str], rows: List[List[str]], data: Dict[str, Any]):
    """Processes a collected table based on its section."""
    # print(f"[DEBUG] Processing table for section '{section}', subsection '{subsection}' with headers {headers}") # Debug

    # --- Instruction Details Tables ---
    if section and "Detailed Instruction Definitions" in section:
        # Determine format from subsection title like "Instructions using DSS Format"
        format_match = re.search(r"Instructions using (\w+) Format", subsection)
        if format_match:
            format_name = format_match.group(1)
            # print(f"[DEBUG] -> Instructions for format: {format_name}") # Debug
            for row in rows:
                if len(row) >= len(headers):
                    instr_data = {}
                    mnemonic = None
                    for i, header in enumerate(headers):
                        cell_value = row[i].strip() if i < len(row) else ""
                        # Simple cleanup of common markdown in cells
                        cell_value = re.sub(r'[`*]', '', cell_value) # Remove backticks, asterisks

                        if 'Mnemonic' in header:
                            mnemonic = cell_value
                        elif 'Opcode' in header:
                            # Extract hex/decimal value
                            opcode_match = re.search(r'(0x[0-9a-fA-F]+|\d+)', cell_value)
                            if opcode_match:
                                try:
                                    if opcode_match.group(1).startswith('0x'):
                                        instr_data['opcode'] = int(opcode_match.group(1), 16)
                                    else:
                                        instr_data['opcode'] = int(opcode_match.group(1))
                                except ValueError:
                                    instr_data['opcode'] = 0
                            else:
                                instr_data['opcode'] = 0
                        elif 'Type' in header:
                            instr_data['type'] = cell_value
                        elif 'Description' in header or 'Notes' in header:
                            # Store if needed for richer model
                            pass
                        else:
                            instr_data[header.lower().replace(' ', '_')] = cell_value

                    if mnemonic:
                        instr_data['format'] = format_name
                        # Heuristic for dst_reg (very basic)
                        dst_write_keywords = ['mov', 'add', 'sub', 'mul', 'ld', 'setp', 'cvt', 'rcp', 'sqrt', 'mad', 'min', 'max']
                        ctrl_keywords = ['branch', 'exit', 'call', 'bar']
                        mnemonic_lower = mnemonic.lower()
                        if any(kw in mnemonic_lower for kw in dst_write_keywords) and not any(ckw in mnemonic_lower for ckw in ctrl_keywords):
                            instr_data['dst_reg'] = 1
                        else:
                            instr_data['dst_reg'] = 0

                        data['instructions_details'][mnemonic] = instr_data
                        # print(f"[DEBUG] Added instruction detail: {mnemonic} -> {instr_data}") # Debug
        else:
             print(f"[WARNING] Could not determine format for instruction table in subsection '{subsection}'", file=sys.stderr)

    # --- Format Encoding Summary Table ---
    elif section and "Format Encoding Summary" in section:
        name_idx = next((i for i, h in enumerate(headers) if 'Name' in h), -1)
        encoding_idx = next((i for i, h in enumerate(headers) if 'Encoding' in h), -1)

        if name_idx != -1 and encoding_idx != -1:
            for row in rows:
                if len(row) > max(name_idx, encoding_idx):
                    name = row[name_idx].strip()
                    encoding_str = row[encoding_idx].strip()
                    # Simple parsing: extract fixed prefix bits
                    # e.g., `01------ -------- -------- --------`
                    # Find first '-' or end to get fixed part
                    fixed_end = len(encoding_str)
                    for k, ch in enumerate(encoding_str):
                        if ch == '-':
                            fixed_end = k
                            break
                    fixed_part = encoding_str[:fixed_end].replace(' ', '').replace('-', '0')
                    if fixed_part:
                        bit_start = 31 # MSB
                        bit_width = len(fixed_part)
                        try:
                            # Interpret fixed part as binary for value
                            enc_value_int = int(fixed_part, 2) if all(c in '01' for c in fixed_part) else 0
                            # print(f"[DEBUG] Parsed format {name}: start={bit_start}, width={bit_width}, value={enc_value_int} ({fixed_part})") # Debug
                            # Placeholder: Assume format details will come from layout or detailed spec
                            # For now, store encoding info
                            data['formats'][name] = {
                                'encoding': (bit_start, bit_width, enc_value_int),
                                'description': '' # Could parse from another column if present
                            }
                        except ValueError as e:
                            print(f"[WARNING] Could not parse encoding value '{fixed_part}' for format '{name}': {e}", file=sys.stderr)
        else:
             print(f"[WARNING] Could not find 'Name' and 'Encoding' columns in format summary table.", file=sys.stderr)

    # --- Instruction Types/Categories Table ---
    elif section and "Instruction Types/Categories" in section:
         name_idx = next((i for i, h in enumerate(headers) if 'Name' in h), -1)
         value_idx = next((i for i, h in enumerate(headers) if 'Value' in h), -1)

         if name_idx != -1 and value_idx != -1:
             for row in rows:
                 if len(row) > max(name_idx, value_idx):
                     name = row[name_idx].strip()
                     value_str = row[value_idx].strip()
                     try:
                         value_int = int(value_str)
                         data['types'][name] = value_int
                         # print(f"[DEBUG] Added type: {name} = {value_int}") # Debug
                     except ValueError:
                         print(f"[WARNING] Could not parse value '{value_str}' for type '{name}'.", file=sys.stderr)
         else:
              print(f"[WARNING] Could not find 'Name' and 'Value' columns in types table.", file=sys.stderr)

    # --- Field Character Codes Table ---
    elif section and "Field Character Codes" in section:
        # This table defines codes. Store for reference/validation if needed.
        # For now, we assume the codes are used correctly in layout lines.
        # Could add validation logic later.
        # print("[DEBUG] Found Field Character Codes table. Storing for reference.") # Debug
        # Processing skipped for basic parser, but data structure is ready if needed.
        pass

    # Add handlers for other tables if needed

# Example usage (conceptual, would be called by isa.py)
if __name__ == "__main__":
    # This would typically be tested by running the coasm_infra tools
    try:
        parsed_data = parse_markdown_dsl("coasm_isa.md")
        import pprint
        pprint.pprint({k: v for k, v in parsed_data.items() if k in ['instructions', 'formats', 'types', 'format_layouts']}) # Show key parts
        print("\n--- Sample Instruction Detail ---")
        sample_instr = next(iter(parsed_data.get('instructions_details', {}).keys()), None)
        if sample_instr:
            print(f"{sample_instr}: {parsed_data['instructions_details'][sample_instr]}")
    except Exception as e:
        print(f"Error in example: {e}")
