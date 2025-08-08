# COASM Instruction Set Architecture (ISA) Definition

This document defines the COASM (Custom Optimized Assembly) instruction set architecture.

## Instruction Mnemonics (for coasm.g4 lexer)

These are the top-level instruction names recognized by the assembler/parser.

- NOP
- MOV
- LD
- ST
- ADD
- SUB
- MUL
- DIV
- MAD
- AND
- OR
- XOR
- NOT
- SHL
- SHR
- SETP
- SELP
- CVT
- RCP
- SQRT
- RSQRT
- SIN
- COS
- EX2
- LG2
- REM
- ABS
- MIN
- MAX
- NEG
- CLZ
- PRMT
- CNOT
- S_BRANCH
- T_CBRANCH_TCCNZ
- T_CBRANCH_TCCZ
- T_EXIT
- CALL
- CALLP
- BAR
- RED
- ATOM
- TEX
- VMAD
- VMAX
- VMIN
- VSET
- DP4A
- CHOP
- ... (Add more as defined)

---

## Instruction Encoding Formats

### Format Encoding Summary

Each instruction format is identified by a unique bit pattern in the most significant bits of the instruction word.

| Name  | Encoding (MSB -> LSB)          | Description                   |
| :---- | :----------------------------- | :---------------------------- |
| DSS   | `01------ -------- -------- --------` | 2-src, 1-dst ALU operations   |
| DABC  | `00------ -------- -------- --------` | 3-src, 1-dst operations (e.g., MAD) |
| MEM   | `100----- -------- -------- --------` | Memory load/store operations |
| CTRL  | `1010---- -------- -------- --------` | Control flow operations       |
| SFU   | `1011---- -------- -------- --------` | Special Function Unit ops     |
| CVT   | `1100---- -------- -------- --------` | Type conversion operations   |
| ...   | ...                            | ...                           |

*(Note: The exact bit positions and masks depend on the final 32-bit instruction layout.)*

### Field Character Codes

To simplify field definitions, each common field type is assigned a single-character code:

| Code | Field Type         | Description                          |
| :--: | :----------------- | :----------------------------------- |
| `0`  | `src0`             | Primary source operand register      |
| `1`  | `src1`             | Secondary source operand register     |
| `2`  | `src2`             | Tertiary source operand register      |
| `3`  | `src3`             | Quaternary source operand register    |
| `d`  | `dst`              | Destination operand register         |
| `p`  | `pred`             | Predicate register selector           |
| `x`  | `opcode`           | Operation code within the format      |
| `m`  | `imm`              | Immediate value flag or component     |
| `s`  | `space`            | Address space specifier               |
| `a`  | `addr`             | Address register or component         |
| `c`  | `carry`            | Carry-in/out flag                     |
| `-`  | *Padding/Reserved* | Unused or reserved bits               |
| `u`  | *Unused*           | Bits not yet assigned in this layout  |
| ...  | ...                | ...                                   |

*(Note: Codes can be reused contextually if field roles change slightly between formats.)*

### Format Field Layouts (Global View)

These layouts describe the bit organization *within* an instruction word for each format. They use the character codes defined above to show the role of each bit segment.

- **DSS:** `--pp0000 00111111 ddddddmm mxxxxxxx`
- **DABC:** `--pp0000 11111122 22223333 333xxxxx`
- **MEM:** `---ppsss aaaaaaaa 11111122 22xxxxxx`
- **CTRL:** `----pp-- tttttttt llllllll ----xxxx`
- **SFU:** `---ppfff 00000000 dddddd-- ---xxxxx`
- **CVT:** `---ppttt fffddd-- -------- ---xxxxx`
- ...(Add layouts for other defined formats)

*(Legend: Characters represent field roles as per the table above. `-` represents padding/reserved/unused bits.)*

---

## Detailed Instruction Definitions

Instructions are grouped by their primary format.

### Instructions using DSS Format

| Mnemonic | Opcode (within DSS) | Type      | Description                   | Notes                          |
| :------- | :------------------ | :-------- | :---------------------------- | :----------------------------- |
| ADD      | `0x1`               | `INT_OP`  | Integer Addition              | dst = src0 + src1              |
| MUL      | `0x2`               | `INT_MUL_OP`| Integer Multiplication       | dst = src0 * src1              |
| SUB      | `0x3`               | `INT_OP`  | Integer Subtraction           | dst = src0 - src1              |
| AND      | `0x4`               | `INT_LOGIC_OP` | Bitwise AND              | dst = src0 & src1              |
| OR       | `0x5`               | `INT_LOGIC_OP` | Bitwise OR               | dst = src0 | src1               |
| XOR      | `0x6`               | `INT_LOGIC_OP` | Bitwise XOR              | dst = src0 ^ src1              |
| SHL      | `0x7`               | `INT_OP`  | Shift Left Logical            | dst = src0 << src1             |
| SHR      | `0x8`               | `INT_OP`  | Shift Right Logical/Arithmetic | dst = src0 >> src1             |
| MOV      | `0xF`               | `INT_OP`  | Move/Register Copy             | dst = src0                     |
| SETP     | `0xE`               | `INT_OP`  | Set Predicate (Compare)       | p_dst = (src0 OP src1)         |
| ...      | ...                 | ...       | ...                           | ...                            |

### Instructions using DABC Format

| Mnemonic | Opcode (within DABC) | Type      | Description                   | Notes                          |
| :------- | :------------------- | :-------- | :---------------------------- | :----------------------------- |
| MAD      | `0x0`                | `INT_MUL_OP`| Multiply-Add                | dst = (src0 * src1) + src2     |
| ...      | ...                  | ...       | ...                           | ...                            |

### Instructions using MEM Format

| Mnemonic | Opcode (within MEM) | Type     | Description                   | Notes                          |
| :------- | :------------------ | :------- | :---------------------------- | :----------------------------- |
| LD       | `0x0`               | `MEM_OP` | Load from memory              | dst = [address]                |
| ST       | `0x1`               | `MEM_OP` | Store to memory               | [address] = src                |
| ...      | ...                 | ...      | ...                           | ...                            |

### Instructions using CTRL Format

| Mnemonic        | Opcode (within CTRL) | Type      | Description                   | Notes                          |
| :-------------- | :------------------- | :-------- | :---------------------------- | :----------------------------- |
| S_BRANCH        | `0x00`               | `CTRL_OP` | Unconditional Branch          | PC = target                    |
| T_CBRANCH_TCCNZ | `0x01`               | `CTRL_OP` | Conditional Branch if Pred!=0 | If p_src != 0: PC = target      |
| T_CBRANCH_TCCZ  | `0x02`               | `CTRL_OP` | Conditional Branch if Pred==0 | If p_src == 0: PC = target      |
| T_EXIT          | `0x3F`               | `CTRL_OP` | Thread Exit/Return            | Return from kernel/thread      |
| ...             | ...                  | ...       | ...                           | ...                            |

### Instructions using SFU Format

| Mnemonic | Opcode (within SFU) | Type     | Description                   | Notes                          |
| :------- | :------------------- | :------- | :---------------------------- | :----------------------------- |
| RCP      | `0x01`               | `SFU_OP` | Reciprocal                    | dst = 1.0 / src0               |
| SQRT     | `0x02`               | `SFU_OP` | Square Root                   | dst = sqrt(src0)               |
| SIN      | `0x03`               | `SFU_OP` | Sine                          | dst = sin(src0)                |
| COS      | `0x04`               | `SFU_OP` | Cosine                        | dst = cos(src0)                |
| ...      | ...                  | ...      | ...                           | ...                            |

### Instructions using CVT Format

| Mnemonic | Opcode (within CVT) | Type     | Description                   | Notes                          |
| :------- | :------------------ | :------- | :---------------------------- | :----------------------------- |
| CVT      | `0x0`               | `CONV_OP`| Convert Type                  | dst = convert(src0)           |
| ...      | ...                 | ...      | ...                           | ...                            |

*(Continue defining tables for other formats like SFU, CVT, etc., as needed.)*

---

## Instruction Types/Categories

Used for organizing instructions, potentially influencing scheduling or function units.

| Name        | Value | Description                          |
| :---------- | :---- | :----------------------------------- |
| `INT_OP`    | 0     | Integer arithmetic/logic             |
| `INT_LOGIC_OP`| 1   | Specific subset for logic (AND, OR, XOR) |
| `INT_MUL_OP`| 2     | Specific subset for multiplication   |
| `SP_OP`     | 3     | Single-Precision Floating Point     |
| `DP_OP`     | 4     | Double-Precision Floating Point     |
| `SFU_OP`    | 5     | Special Function Unit operations     |
| `CTRL_OP`   | 6     | Control Flow operations              |
| `MEM_OP`    | 7     | Memory operations                    |
| `ATOM_OP`   | 8     | Atomic operations                    |
| `CONV_OP`   | 9     | Conversion operations                |
| `TEX_OP`    | 10    | Texture operations                   |
| `VIDEO_OP`  | 11    | Video-specific operations            |
| `NOP_OP`    | 12    | No-operation                         |
| ...         | ...   | ...                                  |

---
