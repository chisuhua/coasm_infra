
// Generated from generated/coasm.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  coasmLexer : public antlr4::Lexer {
public:
  enum {
    TEXT_DIRECTIVE = 1, GLOBAL_DIRECTIVE = 2, TYPE_DIRECTIVE = 3, START_KERNEL = 4, 
    COASM_KERNELS_DIRECTIVE = 5, COASM_VERSION_DIRECTIVE = 6, VERSION_NUMBER = 7, 
    DASH = 8, WHITESPACE = 9, SHARED_MEMSIZE = 10, PRIVATE_MEMSIZE = 11, 
    CMEM_SIZE = 12, BAR_USED = 13, KERNEL_CTRL = 14, KERNEL_MODE = 15, LOCAL_FRAMESIZE = 16, 
    NAME = 17, ARGS = 18, SHARED = 19, ADDRESS_SPACE = 20, OFFSET = 21, 
    SIZE = 22, VALUE_KIND = 23, ARGS_START = 24, SHARED_START = 25, ARG_NAME_DIRECTIVE = 26, 
    SHARED_NAME_DIRECTIVE = 27, ADDRESS_SPACE_TYPE = 28, VALUE_KIND_TYPE = 29, 
    OPCODE = 30, REGISTER = 31, SPECIAL_REGISTER = 32, IDENTIFIER = 33, 
    STRING_LITERAL = 34, INTEGER_LITERAL = 35, HEX_LITERAL = 36, FLOAT_LITERAL = 37, 
    SIGN = 38, PERCENT = 39, DOT = 40, COLON = 41, COMMA = 42, LEFT_BRACKET = 43, 
    RIGHT_BRACKET = 44, LEFT_BRACE = 45, RIGHT_BRACE = 46, PLUS = 47, MINUS = 48, 
    AT_SYMBOL = 49, TYPE_ATTR = 50, FUNCTION_KEYWORD = 51, SEMICOLON = 52, 
    LINE_COMMENT = 53, BLOCK_COMMENT = 54, NEWLINE = 55, WS = 56
  };

  explicit coasmLexer(antlr4::CharStream *input);

  ~coasmLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

