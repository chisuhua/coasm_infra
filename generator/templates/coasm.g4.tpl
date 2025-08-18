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

OPCODE: {{ instructions_placeholder }}
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
