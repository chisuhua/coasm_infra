grammar coasm;

program : (directive | instruction | label | NEWLINE)* EOF;

instruction
    : OPCODE operandList? NEWLINE
    ;

operandList
    : operand (',' operand)*
    ;

operand
    : register
    | memoryAccess
    | ID
    | INT
    | FLOAT
    ;

register
    : '%' ID
    ;

memoryAccess
    : '[' (register | ID) ('+' (register | ID | INT))? ']'
    ;

OPCODE: 'NOP' | 'MOV' | 'LD' | 'ST' | 'ADD' | 'SUB' | 'MUL' | 'DIV' | 'MAD' | 'AND' | 'OR' | 'XOR' | 'NOT' | 'SHL' | 'SHR' | 'SETP' | 'SELP' | 'CVT' | 'RCP' | 'SQRT' | 'RSQRT' | 'SIN' | 'COS' | 'EX2' | 'LG2' | 'REM' | 'ABS' | 'MIN' | 'MAX' | 'NEG' | 'CLZ' | 'PRMT' | 'CNOT' | 'S_BRANCH' | 'T_CBRANCH_TCCNZ' | 'T_CBRANCH_TCCZ' | 'T_EXIT' | 'CALL' | 'CALLP' | 'BAR' | 'RED' | 'ATOM' | 'TEX' | 'VMAD' | 'VMAX' | 'VMIN' | 'VSET' | 'DP4A' | 'CHOP'
    ;

label
    : ID ':' NEWLINE
    ;

directive
    : '.' ID (ID | STRING)? NEWLINE
    ;

ID
    : [a-zA-Z_.$][a-zA-Z0-9_.$]*
    ;

INT
    : [0-9]+
    ;

FLOAT
    : [0-9]+ '.' [0-9]+
    ;

STRING
    : '"' .*? '"'
    ;

NEWLINE
    : '\r'? '\n'
    ;

WS
    : [ \t]+ -> skip
    ;

COMMENT
    : '//' ~[\r\n]* -> skip
    ;