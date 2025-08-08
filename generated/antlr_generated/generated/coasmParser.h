
// Generated from generated/coasm.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  coasmParser : public antlr4::Parser {
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

  enum {
    RuleProg = 0, RuleLine = 1, RuleDirective = 2, RuleSection_directive = 3, 
    RuleKernel_metadata_start = 4, RuleKernel_metadata_item = 5, RuleMetadata_entry_line = 6, 
    RuleMetadata_key = 7, RuleMetadata_value = 8, RuleLabel = 9, RuleBlock = 10, 
    RuleInstruction = 11, RuleInstruction_suffix = 12, RuleOperands = 13, 
    RuleOperand = 14, RuleImmediate = 15, RuleMemory_operand = 16, RuleMemory_address = 17, 
    RuleLine_comment = 18
  };

  explicit coasmParser(antlr4::TokenStream *input);

  coasmParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~coasmParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgContext;
  class LineContext;
  class DirectiveContext;
  class Section_directiveContext;
  class Kernel_metadata_startContext;
  class Kernel_metadata_itemContext;
  class Metadata_entry_lineContext;
  class Metadata_keyContext;
  class Metadata_valueContext;
  class LabelContext;
  class BlockContext;
  class InstructionContext;
  class Instruction_suffixContext;
  class OperandsContext;
  class OperandContext;
  class ImmediateContext;
  class Memory_operandContext;
  class Memory_addressContext;
  class Line_commentContext; 

  class  ProgContext : public antlr4::ParserRuleContext {
  public:
    ProgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<LineContext *> line();
    LineContext* line(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgContext* prog();

  class  LineContext : public antlr4::ParserRuleContext {
  public:
    LineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LineContext() = default;
    void copyFrom(LineContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CommentLineContext : public LineContext {
  public:
    CommentLineContext(LineContext *ctx);

    Line_commentContext *line_comment();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  InstructionLineContext : public LineContext {
  public:
    InstructionLineContext(LineContext *ctx);

    InstructionContext *instruction();
    LabelContext *label();
    Line_commentContext *line_comment();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  EmptyLineContext : public LineContext {
  public:
    EmptyLineContext(LineContext *ctx);

    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  DirectiveLineContext : public LineContext {
  public:
    DirectiveLineContext(LineContext *ctx);

    DirectiveContext *directive();
    Line_commentContext *line_comment();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  LabelLineContext : public LineContext {
  public:
    LabelLineContext(LineContext *ctx);

    LabelContext *label();
    Line_commentContext *line_comment();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  BlockLineContext : public LineContext {
  public:
    BlockLineContext(LineContext *ctx);

    BlockContext *block();
    Line_commentContext *line_comment();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  LineContext* line();

  class  DirectiveContext : public antlr4::ParserRuleContext {
  public:
    DirectiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Section_directiveContext *section_directive();
    antlr4::tree::TerminalNode *START_KERNEL();
    antlr4::tree::TerminalNode *IDENTIFIER();
    Kernel_metadata_startContext *kernel_metadata_start();
    Kernel_metadata_itemContext *kernel_metadata_item();
    antlr4::tree::TerminalNode *COASM_VERSION_DIRECTIVE();
    antlr4::tree::TerminalNode *VERSION_NUMBER();
    antlr4::tree::TerminalNode *INTEGER_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  DirectiveContext* directive();

  class  Section_directiveContext : public antlr4::ParserRuleContext {
  public:
    Section_directiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TEXT_DIRECTIVE();
    antlr4::tree::TerminalNode *GLOBAL_DIRECTIVE();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *TYPE_DIRECTIVE();
    antlr4::tree::TerminalNode *COMMA();
    antlr4::tree::TerminalNode *TYPE_ATTR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Section_directiveContext* section_directive();

  class  Kernel_metadata_startContext : public antlr4::ParserRuleContext {
  public:
    Kernel_metadata_startContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *COASM_KERNELS_DIRECTIVE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Kernel_metadata_startContext* kernel_metadata_start();

  class  Kernel_metadata_itemContext : public antlr4::ParserRuleContext {
  public:
    Kernel_metadata_itemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DASH();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<Metadata_entry_lineContext *> metadata_entry_line();
    Metadata_entry_lineContext* metadata_entry_line(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Kernel_metadata_itemContext* kernel_metadata_item();

  class  Metadata_entry_lineContext : public antlr4::ParserRuleContext {
  public:
    Metadata_entry_lineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Metadata_keyContext *metadata_key();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<antlr4::tree::TerminalNode *> WHITESPACE();
    antlr4::tree::TerminalNode* WHITESPACE(size_t i);
    Metadata_valueContext *metadata_value();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Metadata_entry_lineContext* metadata_entry_line();

  class  Metadata_keyContext : public antlr4::ParserRuleContext {
  public:
    Metadata_keyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Metadata_keyContext* metadata_key();

  class  Metadata_valueContext : public antlr4::ParserRuleContext {
  public:
    Metadata_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *INTEGER_LITERAL();
    antlr4::tree::TerminalNode *STRING_LITERAL();
    antlr4::tree::TerminalNode *HEX_LITERAL();
    antlr4::tree::TerminalNode *FLOAT_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Metadata_valueContext* metadata_value();

  class  LabelContext : public antlr4::ParserRuleContext {
  public:
    LabelContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *COLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LabelContext* label();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_BRACE();
    antlr4::tree::TerminalNode *RIGHT_BRACE();
    std::vector<LineContext *> line();
    LineContext* line(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BlockContext* block();

  class  InstructionContext : public antlr4::ParserRuleContext {
  public:
    InstructionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPCODE();
    Instruction_suffixContext *instruction_suffix();
    OperandsContext *operands();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  InstructionContext* instruction();

  class  Instruction_suffixContext : public antlr4::ParserRuleContext {
  public:
    Instruction_suffixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DOT();
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Instruction_suffixContext* instruction_suffix();

  class  OperandsContext : public antlr4::ParserRuleContext {
  public:
    OperandsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OperandContext *> operand();
    OperandContext* operand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  OperandsContext* operands();

  class  OperandContext : public antlr4::ParserRuleContext {
  public:
    OperandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    OperandContext() = default;
    void copyFrom(OperandContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RegisterOperandContext : public OperandContext {
  public:
    RegisterOperandContext(OperandContext *ctx);

    antlr4::tree::TerminalNode *REGISTER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  MemoryOperandContext : public OperandContext {
  public:
    MemoryOperandContext(OperandContext *ctx);

    Memory_operandContext *memory_operand();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  IdentifierOperandContext : public OperandContext {
  public:
    IdentifierOperandContext(OperandContext *ctx);

    antlr4::tree::TerminalNode *IDENTIFIER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  SpecialRegisterOperandContext : public OperandContext {
  public:
    SpecialRegisterOperandContext(OperandContext *ctx);

    antlr4::tree::TerminalNode *SPECIAL_REGISTER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  ImmediateOperandContext : public OperandContext {
  public:
    ImmediateOperandContext(OperandContext *ctx);

    ImmediateContext *immediate();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  OperandContext* operand();

  class  ImmediateContext : public antlr4::ParserRuleContext {
  public:
    ImmediateContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER_LITERAL();
    antlr4::tree::TerminalNode *HEX_LITERAL();
    antlr4::tree::TerminalNode *FLOAT_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ImmediateContext* immediate();

  class  Memory_operandContext : public antlr4::ParserRuleContext {
  public:
    Memory_operandContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LEFT_BRACKET();
    Memory_addressContext *memory_address();
    antlr4::tree::TerminalNode *RIGHT_BRACKET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Memory_operandContext* memory_operand();

  class  Memory_addressContext : public antlr4::ParserRuleContext {
  public:
    Memory_addressContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<OperandContext *> operand();
    OperandContext* operand(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Memory_addressContext* memory_address();

  class  Line_commentContext : public antlr4::ParserRuleContext {
  public:
    Line_commentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LINE_COMMENT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Line_commentContext* line_comment();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

