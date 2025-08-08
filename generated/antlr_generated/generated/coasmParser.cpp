
// Generated from generated/coasm.g4 by ANTLR 4.13.2


#include "coasmListener.h"

#include "coasmParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct CoasmParserStaticData final {
  CoasmParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  CoasmParserStaticData(const CoasmParserStaticData&) = delete;
  CoasmParserStaticData(CoasmParserStaticData&&) = delete;
  CoasmParserStaticData& operator=(const CoasmParserStaticData&) = delete;
  CoasmParserStaticData& operator=(CoasmParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag coasmParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<CoasmParserStaticData> coasmParserStaticData = nullptr;

void coasmParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (coasmParserStaticData != nullptr) {
    return;
  }
#else
  assert(coasmParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<CoasmParserStaticData>(
    std::vector<std::string>{
      "prog", "line", "directive", "section_directive", "kernel_metadata_start", 
      "kernel_metadata_item", "metadata_entry_line", "metadata_key", "metadata_value", 
      "label", "block", "instruction", "instruction_suffix", "operands", 
      "operand", "immediate", "memory_operand", "memory_address", "line_comment"
    },
    std::vector<std::string>{
      "", "'.text'", "'.global'", "'.type'", "'.start_kernel'", "'opu.kernels:'", 
      "'opu.version:'", "", "", "", "'.shared_memsize'", "'.private_memsize'", 
      "'.cmem_size'", "'.bar_used'", "'.kernel_ctrl'", "'.kernel_mode'", 
      "'.local_framesize'", "", "'.args'", "'.shared'", "'.address_space'", 
      "'.offset'", "'.size'", "'.value_kind'", "'.args:'", "'.shared:'", 
      "", "", "", "", "", "", "", "", "", "", "", "", "", "'%'", "'.'", 
      "':'", "','", "'['", "']'", "'{'", "'}'", "'+'", "", "'@'", "", "'function'", 
      "';'"
    },
    std::vector<std::string>{
      "", "TEXT_DIRECTIVE", "GLOBAL_DIRECTIVE", "TYPE_DIRECTIVE", "START_KERNEL", 
      "COASM_KERNELS_DIRECTIVE", "COASM_VERSION_DIRECTIVE", "VERSION_NUMBER", 
      "DASH", "WHITESPACE", "SHARED_MEMSIZE", "PRIVATE_MEMSIZE", "CMEM_SIZE", 
      "BAR_USED", "KERNEL_CTRL", "KERNEL_MODE", "LOCAL_FRAMESIZE", "NAME", 
      "ARGS", "SHARED", "ADDRESS_SPACE", "OFFSET", "SIZE", "VALUE_KIND", 
      "ARGS_START", "SHARED_START", "ARG_NAME_DIRECTIVE", "SHARED_NAME_DIRECTIVE", 
      "ADDRESS_SPACE_TYPE", "VALUE_KIND_TYPE", "OPCODE", "REGISTER", "SPECIAL_REGISTER", 
      "IDENTIFIER", "STRING_LITERAL", "INTEGER_LITERAL", "HEX_LITERAL", 
      "FLOAT_LITERAL", "SIGN", "PERCENT", "DOT", "COLON", "COMMA", "LEFT_BRACKET", 
      "RIGHT_BRACKET", "LEFT_BRACE", "RIGHT_BRACE", "PLUS", "MINUS", "AT_SYMBOL", 
      "TYPE_ATTR", "FUNCTION_KEYWORD", "SEMICOLON", "LINE_COMMENT", "BLOCK_COMMENT", 
      "NEWLINE", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,56,181,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,1,0,5,0,40,8,0,10,0,12,0,43,
  	9,0,1,0,1,0,1,1,1,1,3,1,49,8,1,1,1,3,1,52,8,1,1,1,1,1,3,1,56,8,1,1,1,
  	3,1,59,8,1,1,1,3,1,62,8,1,1,1,1,1,3,1,66,8,1,1,1,3,1,69,8,1,1,1,1,1,3,
  	1,73,8,1,1,1,3,1,76,8,1,1,1,1,1,3,1,80,8,1,1,1,3,1,83,8,1,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,3,2,93,8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,102,8,
  	3,1,4,1,4,1,5,1,5,1,5,4,5,109,8,5,11,5,12,5,110,1,6,3,6,114,8,6,1,6,1,
  	6,1,6,1,6,3,6,120,8,6,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,9,1,10,1,10,5,
  	10,133,8,10,10,10,12,10,136,9,10,1,10,1,10,1,11,1,11,3,11,142,8,11,1,
  	11,3,11,145,8,11,1,12,1,12,1,12,1,13,1,13,1,13,5,13,153,8,13,10,13,12,
  	13,156,9,13,1,14,1,14,1,14,1,14,1,14,3,14,163,8,14,1,15,1,15,1,16,1,16,
  	1,16,1,16,1,17,1,17,1,17,5,17,174,8,17,10,17,12,17,177,9,17,1,18,1,18,
  	1,18,0,0,19,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,0,2,1,
  	0,33,37,1,0,35,37,196,0,41,1,0,0,0,2,82,1,0,0,0,4,92,1,0,0,0,6,101,1,
  	0,0,0,8,103,1,0,0,0,10,105,1,0,0,0,12,113,1,0,0,0,14,123,1,0,0,0,16,125,
  	1,0,0,0,18,127,1,0,0,0,20,130,1,0,0,0,22,139,1,0,0,0,24,146,1,0,0,0,26,
  	149,1,0,0,0,28,162,1,0,0,0,30,164,1,0,0,0,32,166,1,0,0,0,34,170,1,0,0,
  	0,36,178,1,0,0,0,38,40,3,2,1,0,39,38,1,0,0,0,40,43,1,0,0,0,41,39,1,0,
  	0,0,41,42,1,0,0,0,42,44,1,0,0,0,43,41,1,0,0,0,44,45,5,0,0,1,45,1,1,0,
  	0,0,46,48,3,4,2,0,47,49,3,36,18,0,48,47,1,0,0,0,48,49,1,0,0,0,49,51,1,
  	0,0,0,50,52,5,55,0,0,51,50,1,0,0,0,51,52,1,0,0,0,52,83,1,0,0,0,53,55,
  	3,18,9,0,54,56,3,36,18,0,55,54,1,0,0,0,55,56,1,0,0,0,56,58,1,0,0,0,57,
  	59,5,55,0,0,58,57,1,0,0,0,58,59,1,0,0,0,59,83,1,0,0,0,60,62,3,18,9,0,
  	61,60,1,0,0,0,61,62,1,0,0,0,62,63,1,0,0,0,63,65,3,22,11,0,64,66,3,36,
  	18,0,65,64,1,0,0,0,65,66,1,0,0,0,66,68,1,0,0,0,67,69,5,55,0,0,68,67,1,
  	0,0,0,68,69,1,0,0,0,69,83,1,0,0,0,70,72,3,20,10,0,71,73,3,36,18,0,72,
  	71,1,0,0,0,72,73,1,0,0,0,73,75,1,0,0,0,74,76,5,55,0,0,75,74,1,0,0,0,75,
  	76,1,0,0,0,76,83,1,0,0,0,77,79,3,36,18,0,78,80,5,55,0,0,79,78,1,0,0,0,
  	79,80,1,0,0,0,80,83,1,0,0,0,81,83,5,55,0,0,82,46,1,0,0,0,82,53,1,0,0,
  	0,82,61,1,0,0,0,82,70,1,0,0,0,82,77,1,0,0,0,82,81,1,0,0,0,83,3,1,0,0,
  	0,84,93,3,6,3,0,85,86,5,4,0,0,86,93,5,33,0,0,87,93,3,8,4,0,88,93,3,10,
  	5,0,89,93,5,6,0,0,90,91,5,7,0,0,91,93,5,35,0,0,92,84,1,0,0,0,92,85,1,
  	0,0,0,92,87,1,0,0,0,92,88,1,0,0,0,92,89,1,0,0,0,92,90,1,0,0,0,93,5,1,
  	0,0,0,94,102,5,1,0,0,95,96,5,2,0,0,96,102,5,33,0,0,97,98,5,3,0,0,98,99,
  	5,33,0,0,99,100,5,42,0,0,100,102,5,50,0,0,101,94,1,0,0,0,101,95,1,0,0,
  	0,101,97,1,0,0,0,102,7,1,0,0,0,103,104,5,5,0,0,104,9,1,0,0,0,105,106,
  	5,8,0,0,106,108,5,55,0,0,107,109,3,12,6,0,108,107,1,0,0,0,109,110,1,0,
  	0,0,110,108,1,0,0,0,110,111,1,0,0,0,111,11,1,0,0,0,112,114,5,9,0,0,113,
  	112,1,0,0,0,113,114,1,0,0,0,114,115,1,0,0,0,115,116,3,14,7,0,116,119,
  	5,41,0,0,117,118,5,9,0,0,118,120,3,16,8,0,119,117,1,0,0,0,119,120,1,0,
  	0,0,120,121,1,0,0,0,121,122,5,55,0,0,122,13,1,0,0,0,123,124,5,33,0,0,
  	124,15,1,0,0,0,125,126,7,0,0,0,126,17,1,0,0,0,127,128,5,33,0,0,128,129,
  	5,41,0,0,129,19,1,0,0,0,130,134,5,45,0,0,131,133,3,2,1,0,132,131,1,0,
  	0,0,133,136,1,0,0,0,134,132,1,0,0,0,134,135,1,0,0,0,135,137,1,0,0,0,136,
  	134,1,0,0,0,137,138,5,46,0,0,138,21,1,0,0,0,139,141,5,30,0,0,140,142,
  	3,24,12,0,141,140,1,0,0,0,141,142,1,0,0,0,142,144,1,0,0,0,143,145,3,26,
  	13,0,144,143,1,0,0,0,144,145,1,0,0,0,145,23,1,0,0,0,146,147,5,40,0,0,
  	147,148,5,33,0,0,148,25,1,0,0,0,149,154,3,28,14,0,150,151,5,42,0,0,151,
  	153,3,28,14,0,152,150,1,0,0,0,153,156,1,0,0,0,154,152,1,0,0,0,154,155,
  	1,0,0,0,155,27,1,0,0,0,156,154,1,0,0,0,157,163,5,31,0,0,158,163,5,32,
  	0,0,159,163,3,30,15,0,160,163,3,32,16,0,161,163,5,33,0,0,162,157,1,0,
  	0,0,162,158,1,0,0,0,162,159,1,0,0,0,162,160,1,0,0,0,162,161,1,0,0,0,163,
  	29,1,0,0,0,164,165,7,1,0,0,165,31,1,0,0,0,166,167,5,43,0,0,167,168,3,
  	34,17,0,168,169,5,44,0,0,169,33,1,0,0,0,170,175,3,28,14,0,171,172,5,47,
  	0,0,172,174,3,28,14,0,173,171,1,0,0,0,174,177,1,0,0,0,175,173,1,0,0,0,
  	175,176,1,0,0,0,176,35,1,0,0,0,177,175,1,0,0,0,178,179,5,53,0,0,179,37,
  	1,0,0,0,23,41,48,51,55,58,61,65,68,72,75,79,82,92,101,110,113,119,134,
  	141,144,154,162,175
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  coasmParserStaticData = std::move(staticData);
}

}

coasmParser::coasmParser(TokenStream *input) : coasmParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

coasmParser::coasmParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  coasmParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *coasmParserStaticData->atn, coasmParserStaticData->decisionToDFA, coasmParserStaticData->sharedContextCache, options);
}

coasmParser::~coasmParser() {
  delete _interpreter;
}

const atn::ATN& coasmParser::getATN() const {
  return *coasmParserStaticData->atn;
}

std::string coasmParser::getGrammarFileName() const {
  return "coasm.g4";
}

const std::vector<std::string>& coasmParser::getRuleNames() const {
  return coasmParserStaticData->ruleNames;
}

const dfa::Vocabulary& coasmParser::getVocabulary() const {
  return coasmParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView coasmParser::getSerializedATN() const {
  return coasmParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

coasmParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* coasmParser::ProgContext::EOF() {
  return getToken(coasmParser::EOF, 0);
}

std::vector<coasmParser::LineContext *> coasmParser::ProgContext::line() {
  return getRuleContexts<coasmParser::LineContext>();
}

coasmParser::LineContext* coasmParser::ProgContext::line(size_t i) {
  return getRuleContext<coasmParser::LineContext>(i);
}


size_t coasmParser::ProgContext::getRuleIndex() const {
  return coasmParser::RuleProg;
}

void coasmParser::ProgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProg(this);
}

void coasmParser::ProgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProg(this);
}

coasmParser::ProgContext* coasmParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, coasmParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 45071190309470718) != 0)) {
      setState(38);
      line();
      setState(43);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(44);
    match(coasmParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

coasmParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t coasmParser::LineContext::getRuleIndex() const {
  return coasmParser::RuleLine;
}

void coasmParser::LineContext::copyFrom(LineContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CommentLineContext ------------------------------------------------------------------

coasmParser::Line_commentContext* coasmParser::CommentLineContext::line_comment() {
  return getRuleContext<coasmParser::Line_commentContext>(0);
}

tree::TerminalNode* coasmParser::CommentLineContext::NEWLINE() {
  return getToken(coasmParser::NEWLINE, 0);
}

coasmParser::CommentLineContext::CommentLineContext(LineContext *ctx) { copyFrom(ctx); }

void coasmParser::CommentLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommentLine(this);
}
void coasmParser::CommentLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommentLine(this);
}
//----------------- InstructionLineContext ------------------------------------------------------------------

coasmParser::InstructionContext* coasmParser::InstructionLineContext::instruction() {
  return getRuleContext<coasmParser::InstructionContext>(0);
}

coasmParser::LabelContext* coasmParser::InstructionLineContext::label() {
  return getRuleContext<coasmParser::LabelContext>(0);
}

coasmParser::Line_commentContext* coasmParser::InstructionLineContext::line_comment() {
  return getRuleContext<coasmParser::Line_commentContext>(0);
}

tree::TerminalNode* coasmParser::InstructionLineContext::NEWLINE() {
  return getToken(coasmParser::NEWLINE, 0);
}

coasmParser::InstructionLineContext::InstructionLineContext(LineContext *ctx) { copyFrom(ctx); }

void coasmParser::InstructionLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstructionLine(this);
}
void coasmParser::InstructionLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstructionLine(this);
}
//----------------- EmptyLineContext ------------------------------------------------------------------

tree::TerminalNode* coasmParser::EmptyLineContext::NEWLINE() {
  return getToken(coasmParser::NEWLINE, 0);
}

coasmParser::EmptyLineContext::EmptyLineContext(LineContext *ctx) { copyFrom(ctx); }

void coasmParser::EmptyLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmptyLine(this);
}
void coasmParser::EmptyLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmptyLine(this);
}
//----------------- DirectiveLineContext ------------------------------------------------------------------

coasmParser::DirectiveContext* coasmParser::DirectiveLineContext::directive() {
  return getRuleContext<coasmParser::DirectiveContext>(0);
}

coasmParser::Line_commentContext* coasmParser::DirectiveLineContext::line_comment() {
  return getRuleContext<coasmParser::Line_commentContext>(0);
}

tree::TerminalNode* coasmParser::DirectiveLineContext::NEWLINE() {
  return getToken(coasmParser::NEWLINE, 0);
}

coasmParser::DirectiveLineContext::DirectiveLineContext(LineContext *ctx) { copyFrom(ctx); }

void coasmParser::DirectiveLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirectiveLine(this);
}
void coasmParser::DirectiveLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirectiveLine(this);
}
//----------------- LabelLineContext ------------------------------------------------------------------

coasmParser::LabelContext* coasmParser::LabelLineContext::label() {
  return getRuleContext<coasmParser::LabelContext>(0);
}

coasmParser::Line_commentContext* coasmParser::LabelLineContext::line_comment() {
  return getRuleContext<coasmParser::Line_commentContext>(0);
}

tree::TerminalNode* coasmParser::LabelLineContext::NEWLINE() {
  return getToken(coasmParser::NEWLINE, 0);
}

coasmParser::LabelLineContext::LabelLineContext(LineContext *ctx) { copyFrom(ctx); }

void coasmParser::LabelLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabelLine(this);
}
void coasmParser::LabelLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabelLine(this);
}
//----------------- BlockLineContext ------------------------------------------------------------------

coasmParser::BlockContext* coasmParser::BlockLineContext::block() {
  return getRuleContext<coasmParser::BlockContext>(0);
}

coasmParser::Line_commentContext* coasmParser::BlockLineContext::line_comment() {
  return getRuleContext<coasmParser::Line_commentContext>(0);
}

tree::TerminalNode* coasmParser::BlockLineContext::NEWLINE() {
  return getToken(coasmParser::NEWLINE, 0);
}

coasmParser::BlockLineContext::BlockLineContext(LineContext *ctx) { copyFrom(ctx); }

void coasmParser::BlockLineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlockLine(this);
}
void coasmParser::BlockLineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlockLine(this);
}
coasmParser::LineContext* coasmParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 2, coasmParser::RuleLine);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(82);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<coasmParser::DirectiveLineContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(46);
      directive();
      setState(48);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
      case 1: {
        setState(47);
        line_comment();
        break;
      }

      default:
        break;
      }
      setState(51);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(50);
        match(coasmParser::NEWLINE);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<coasmParser::LabelLineContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(53);
      label();
      setState(55);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
      case 1: {
        setState(54);
        line_comment();
        break;
      }

      default:
        break;
      }
      setState(58);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
      case 1: {
        setState(57);
        match(coasmParser::NEWLINE);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<coasmParser::InstructionLineContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(61);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == coasmParser::IDENTIFIER) {
        setState(60);
        label();
      }
      setState(63);
      instruction();
      setState(65);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
      case 1: {
        setState(64);
        line_comment();
        break;
      }

      default:
        break;
      }
      setState(68);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
      case 1: {
        setState(67);
        match(coasmParser::NEWLINE);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<coasmParser::BlockLineContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(70);
      block();
      setState(72);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
      case 1: {
        setState(71);
        line_comment();
        break;
      }

      default:
        break;
      }
      setState(75);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
      case 1: {
        setState(74);
        match(coasmParser::NEWLINE);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<coasmParser::CommentLineContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(77);
      line_comment();
      setState(79);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
      case 1: {
        setState(78);
        match(coasmParser::NEWLINE);
        break;
      }

      default:
        break;
      }
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<coasmParser::EmptyLineContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(81);
      match(coasmParser::NEWLINE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectiveContext ------------------------------------------------------------------

coasmParser::DirectiveContext::DirectiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

coasmParser::Section_directiveContext* coasmParser::DirectiveContext::section_directive() {
  return getRuleContext<coasmParser::Section_directiveContext>(0);
}

tree::TerminalNode* coasmParser::DirectiveContext::START_KERNEL() {
  return getToken(coasmParser::START_KERNEL, 0);
}

tree::TerminalNode* coasmParser::DirectiveContext::IDENTIFIER() {
  return getToken(coasmParser::IDENTIFIER, 0);
}

coasmParser::Kernel_metadata_startContext* coasmParser::DirectiveContext::kernel_metadata_start() {
  return getRuleContext<coasmParser::Kernel_metadata_startContext>(0);
}

coasmParser::Kernel_metadata_itemContext* coasmParser::DirectiveContext::kernel_metadata_item() {
  return getRuleContext<coasmParser::Kernel_metadata_itemContext>(0);
}

tree::TerminalNode* coasmParser::DirectiveContext::COASM_VERSION_DIRECTIVE() {
  return getToken(coasmParser::COASM_VERSION_DIRECTIVE, 0);
}

tree::TerminalNode* coasmParser::DirectiveContext::VERSION_NUMBER() {
  return getToken(coasmParser::VERSION_NUMBER, 0);
}

tree::TerminalNode* coasmParser::DirectiveContext::INTEGER_LITERAL() {
  return getToken(coasmParser::INTEGER_LITERAL, 0);
}


size_t coasmParser::DirectiveContext::getRuleIndex() const {
  return coasmParser::RuleDirective;
}

void coasmParser::DirectiveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirective(this);
}

void coasmParser::DirectiveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirective(this);
}

coasmParser::DirectiveContext* coasmParser::directive() {
  DirectiveContext *_localctx = _tracker.createInstance<DirectiveContext>(_ctx, getState());
  enterRule(_localctx, 4, coasmParser::RuleDirective);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(92);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case coasmParser::TEXT_DIRECTIVE:
      case coasmParser::GLOBAL_DIRECTIVE:
      case coasmParser::TYPE_DIRECTIVE: {
        enterOuterAlt(_localctx, 1);
        setState(84);
        section_directive();
        break;
      }

      case coasmParser::START_KERNEL: {
        enterOuterAlt(_localctx, 2);
        setState(85);
        match(coasmParser::START_KERNEL);
        setState(86);
        match(coasmParser::IDENTIFIER);
        break;
      }

      case coasmParser::COASM_KERNELS_DIRECTIVE: {
        enterOuterAlt(_localctx, 3);
        setState(87);
        kernel_metadata_start();
        break;
      }

      case coasmParser::DASH: {
        enterOuterAlt(_localctx, 4);
        setState(88);
        kernel_metadata_item();
        break;
      }

      case coasmParser::COASM_VERSION_DIRECTIVE: {
        enterOuterAlt(_localctx, 5);
        setState(89);
        match(coasmParser::COASM_VERSION_DIRECTIVE);
        break;
      }

      case coasmParser::VERSION_NUMBER: {
        enterOuterAlt(_localctx, 6);
        setState(90);
        match(coasmParser::VERSION_NUMBER);
        setState(91);
        match(coasmParser::INTEGER_LITERAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Section_directiveContext ------------------------------------------------------------------

coasmParser::Section_directiveContext::Section_directiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* coasmParser::Section_directiveContext::TEXT_DIRECTIVE() {
  return getToken(coasmParser::TEXT_DIRECTIVE, 0);
}

tree::TerminalNode* coasmParser::Section_directiveContext::GLOBAL_DIRECTIVE() {
  return getToken(coasmParser::GLOBAL_DIRECTIVE, 0);
}

tree::TerminalNode* coasmParser::Section_directiveContext::IDENTIFIER() {
  return getToken(coasmParser::IDENTIFIER, 0);
}

tree::TerminalNode* coasmParser::Section_directiveContext::TYPE_DIRECTIVE() {
  return getToken(coasmParser::TYPE_DIRECTIVE, 0);
}

tree::TerminalNode* coasmParser::Section_directiveContext::COMMA() {
  return getToken(coasmParser::COMMA, 0);
}

tree::TerminalNode* coasmParser::Section_directiveContext::TYPE_ATTR() {
  return getToken(coasmParser::TYPE_ATTR, 0);
}


size_t coasmParser::Section_directiveContext::getRuleIndex() const {
  return coasmParser::RuleSection_directive;
}

void coasmParser::Section_directiveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSection_directive(this);
}

void coasmParser::Section_directiveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSection_directive(this);
}

coasmParser::Section_directiveContext* coasmParser::section_directive() {
  Section_directiveContext *_localctx = _tracker.createInstance<Section_directiveContext>(_ctx, getState());
  enterRule(_localctx, 6, coasmParser::RuleSection_directive);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(101);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case coasmParser::TEXT_DIRECTIVE: {
        enterOuterAlt(_localctx, 1);
        setState(94);
        match(coasmParser::TEXT_DIRECTIVE);
        break;
      }

      case coasmParser::GLOBAL_DIRECTIVE: {
        enterOuterAlt(_localctx, 2);
        setState(95);
        match(coasmParser::GLOBAL_DIRECTIVE);
        setState(96);
        match(coasmParser::IDENTIFIER);
        break;
      }

      case coasmParser::TYPE_DIRECTIVE: {
        enterOuterAlt(_localctx, 3);
        setState(97);
        match(coasmParser::TYPE_DIRECTIVE);
        setState(98);
        match(coasmParser::IDENTIFIER);
        setState(99);
        match(coasmParser::COMMA);
        setState(100);
        match(coasmParser::TYPE_ATTR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Kernel_metadata_startContext ------------------------------------------------------------------

coasmParser::Kernel_metadata_startContext::Kernel_metadata_startContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* coasmParser::Kernel_metadata_startContext::COASM_KERNELS_DIRECTIVE() {
  return getToken(coasmParser::COASM_KERNELS_DIRECTIVE, 0);
}


size_t coasmParser::Kernel_metadata_startContext::getRuleIndex() const {
  return coasmParser::RuleKernel_metadata_start;
}

void coasmParser::Kernel_metadata_startContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKernel_metadata_start(this);
}

void coasmParser::Kernel_metadata_startContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKernel_metadata_start(this);
}

coasmParser::Kernel_metadata_startContext* coasmParser::kernel_metadata_start() {
  Kernel_metadata_startContext *_localctx = _tracker.createInstance<Kernel_metadata_startContext>(_ctx, getState());
  enterRule(_localctx, 8, coasmParser::RuleKernel_metadata_start);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(103);
    match(coasmParser::COASM_KERNELS_DIRECTIVE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Kernel_metadata_itemContext ------------------------------------------------------------------

coasmParser::Kernel_metadata_itemContext::Kernel_metadata_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* coasmParser::Kernel_metadata_itemContext::DASH() {
  return getToken(coasmParser::DASH, 0);
}

tree::TerminalNode* coasmParser::Kernel_metadata_itemContext::NEWLINE() {
  return getToken(coasmParser::NEWLINE, 0);
}

std::vector<coasmParser::Metadata_entry_lineContext *> coasmParser::Kernel_metadata_itemContext::metadata_entry_line() {
  return getRuleContexts<coasmParser::Metadata_entry_lineContext>();
}

coasmParser::Metadata_entry_lineContext* coasmParser::Kernel_metadata_itemContext::metadata_entry_line(size_t i) {
  return getRuleContext<coasmParser::Metadata_entry_lineContext>(i);
}


size_t coasmParser::Kernel_metadata_itemContext::getRuleIndex() const {
  return coasmParser::RuleKernel_metadata_item;
}

void coasmParser::Kernel_metadata_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKernel_metadata_item(this);
}

void coasmParser::Kernel_metadata_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKernel_metadata_item(this);
}

coasmParser::Kernel_metadata_itemContext* coasmParser::kernel_metadata_item() {
  Kernel_metadata_itemContext *_localctx = _tracker.createInstance<Kernel_metadata_itemContext>(_ctx, getState());
  enterRule(_localctx, 10, coasmParser::RuleKernel_metadata_item);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(coasmParser::DASH);
    setState(106);
    match(coasmParser::NEWLINE);
    setState(108); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(107);
              metadata_entry_line();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(110); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Metadata_entry_lineContext ------------------------------------------------------------------

coasmParser::Metadata_entry_lineContext::Metadata_entry_lineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

coasmParser::Metadata_keyContext* coasmParser::Metadata_entry_lineContext::metadata_key() {
  return getRuleContext<coasmParser::Metadata_keyContext>(0);
}

tree::TerminalNode* coasmParser::Metadata_entry_lineContext::COLON() {
  return getToken(coasmParser::COLON, 0);
}

tree::TerminalNode* coasmParser::Metadata_entry_lineContext::NEWLINE() {
  return getToken(coasmParser::NEWLINE, 0);
}

std::vector<tree::TerminalNode *> coasmParser::Metadata_entry_lineContext::WHITESPACE() {
  return getTokens(coasmParser::WHITESPACE);
}

tree::TerminalNode* coasmParser::Metadata_entry_lineContext::WHITESPACE(size_t i) {
  return getToken(coasmParser::WHITESPACE, i);
}

coasmParser::Metadata_valueContext* coasmParser::Metadata_entry_lineContext::metadata_value() {
  return getRuleContext<coasmParser::Metadata_valueContext>(0);
}


size_t coasmParser::Metadata_entry_lineContext::getRuleIndex() const {
  return coasmParser::RuleMetadata_entry_line;
}

void coasmParser::Metadata_entry_lineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMetadata_entry_line(this);
}

void coasmParser::Metadata_entry_lineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMetadata_entry_line(this);
}

coasmParser::Metadata_entry_lineContext* coasmParser::metadata_entry_line() {
  Metadata_entry_lineContext *_localctx = _tracker.createInstance<Metadata_entry_lineContext>(_ctx, getState());
  enterRule(_localctx, 12, coasmParser::RuleMetadata_entry_line);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == coasmParser::WHITESPACE) {
      setState(112);
      match(coasmParser::WHITESPACE);
    }
    setState(115);
    metadata_key();
    setState(116);
    match(coasmParser::COLON);
    setState(119);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == coasmParser::WHITESPACE) {
      setState(117);
      match(coasmParser::WHITESPACE);
      setState(118);
      metadata_value();
    }
    setState(121);
    match(coasmParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Metadata_keyContext ------------------------------------------------------------------

coasmParser::Metadata_keyContext::Metadata_keyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* coasmParser::Metadata_keyContext::IDENTIFIER() {
  return getToken(coasmParser::IDENTIFIER, 0);
}


size_t coasmParser::Metadata_keyContext::getRuleIndex() const {
  return coasmParser::RuleMetadata_key;
}

void coasmParser::Metadata_keyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMetadata_key(this);
}

void coasmParser::Metadata_keyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMetadata_key(this);
}

coasmParser::Metadata_keyContext* coasmParser::metadata_key() {
  Metadata_keyContext *_localctx = _tracker.createInstance<Metadata_keyContext>(_ctx, getState());
  enterRule(_localctx, 14, coasmParser::RuleMetadata_key);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(coasmParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Metadata_valueContext ------------------------------------------------------------------

coasmParser::Metadata_valueContext::Metadata_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* coasmParser::Metadata_valueContext::IDENTIFIER() {
  return getToken(coasmParser::IDENTIFIER, 0);
}

tree::TerminalNode* coasmParser::Metadata_valueContext::INTEGER_LITERAL() {
  return getToken(coasmParser::INTEGER_LITERAL, 0);
}

tree::TerminalNode* coasmParser::Metadata_valueContext::STRING_LITERAL() {
  return getToken(coasmParser::STRING_LITERAL, 0);
}

tree::TerminalNode* coasmParser::Metadata_valueContext::HEX_LITERAL() {
  return getToken(coasmParser::HEX_LITERAL, 0);
}

tree::TerminalNode* coasmParser::Metadata_valueContext::FLOAT_LITERAL() {
  return getToken(coasmParser::FLOAT_LITERAL, 0);
}


size_t coasmParser::Metadata_valueContext::getRuleIndex() const {
  return coasmParser::RuleMetadata_value;
}

void coasmParser::Metadata_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMetadata_value(this);
}

void coasmParser::Metadata_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMetadata_value(this);
}

coasmParser::Metadata_valueContext* coasmParser::metadata_value() {
  Metadata_valueContext *_localctx = _tracker.createInstance<Metadata_valueContext>(_ctx, getState());
  enterRule(_localctx, 16, coasmParser::RuleMetadata_value);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 266287972352) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabelContext ------------------------------------------------------------------

coasmParser::LabelContext::LabelContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* coasmParser::LabelContext::IDENTIFIER() {
  return getToken(coasmParser::IDENTIFIER, 0);
}

tree::TerminalNode* coasmParser::LabelContext::COLON() {
  return getToken(coasmParser::COLON, 0);
}


size_t coasmParser::LabelContext::getRuleIndex() const {
  return coasmParser::RuleLabel;
}

void coasmParser::LabelContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabel(this);
}

void coasmParser::LabelContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabel(this);
}

coasmParser::LabelContext* coasmParser::label() {
  LabelContext *_localctx = _tracker.createInstance<LabelContext>(_ctx, getState());
  enterRule(_localctx, 18, coasmParser::RuleLabel);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(coasmParser::IDENTIFIER);
    setState(128);
    match(coasmParser::COLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

coasmParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* coasmParser::BlockContext::LEFT_BRACE() {
  return getToken(coasmParser::LEFT_BRACE, 0);
}

tree::TerminalNode* coasmParser::BlockContext::RIGHT_BRACE() {
  return getToken(coasmParser::RIGHT_BRACE, 0);
}

std::vector<coasmParser::LineContext *> coasmParser::BlockContext::line() {
  return getRuleContexts<coasmParser::LineContext>();
}

coasmParser::LineContext* coasmParser::BlockContext::line(size_t i) {
  return getRuleContext<coasmParser::LineContext>(i);
}


size_t coasmParser::BlockContext::getRuleIndex() const {
  return coasmParser::RuleBlock;
}

void coasmParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void coasmParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

coasmParser::BlockContext* coasmParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 20, coasmParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    match(coasmParser::LEFT_BRACE);
    setState(134);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 45071190309470718) != 0)) {
      setState(131);
      line();
      setState(136);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(137);
    match(coasmParser::RIGHT_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstructionContext ------------------------------------------------------------------

coasmParser::InstructionContext::InstructionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* coasmParser::InstructionContext::OPCODE() {
  return getToken(coasmParser::OPCODE, 0);
}

coasmParser::Instruction_suffixContext* coasmParser::InstructionContext::instruction_suffix() {
  return getRuleContext<coasmParser::Instruction_suffixContext>(0);
}

coasmParser::OperandsContext* coasmParser::InstructionContext::operands() {
  return getRuleContext<coasmParser::OperandsContext>(0);
}


size_t coasmParser::InstructionContext::getRuleIndex() const {
  return coasmParser::RuleInstruction;
}

void coasmParser::InstructionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstruction(this);
}

void coasmParser::InstructionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstruction(this);
}

coasmParser::InstructionContext* coasmParser::instruction() {
  InstructionContext *_localctx = _tracker.createInstance<InstructionContext>(_ctx, getState());
  enterRule(_localctx, 22, coasmParser::RuleInstruction);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(coasmParser::OPCODE);
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == coasmParser::DOT) {
      setState(140);
      instruction_suffix();
    }
    setState(144);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(143);
      operands();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Instruction_suffixContext ------------------------------------------------------------------

coasmParser::Instruction_suffixContext::Instruction_suffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* coasmParser::Instruction_suffixContext::DOT() {
  return getToken(coasmParser::DOT, 0);
}

tree::TerminalNode* coasmParser::Instruction_suffixContext::IDENTIFIER() {
  return getToken(coasmParser::IDENTIFIER, 0);
}


size_t coasmParser::Instruction_suffixContext::getRuleIndex() const {
  return coasmParser::RuleInstruction_suffix;
}

void coasmParser::Instruction_suffixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstruction_suffix(this);
}

void coasmParser::Instruction_suffixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstruction_suffix(this);
}

coasmParser::Instruction_suffixContext* coasmParser::instruction_suffix() {
  Instruction_suffixContext *_localctx = _tracker.createInstance<Instruction_suffixContext>(_ctx, getState());
  enterRule(_localctx, 24, coasmParser::RuleInstruction_suffix);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    match(coasmParser::DOT);
    setState(147);
    match(coasmParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperandsContext ------------------------------------------------------------------

coasmParser::OperandsContext::OperandsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<coasmParser::OperandContext *> coasmParser::OperandsContext::operand() {
  return getRuleContexts<coasmParser::OperandContext>();
}

coasmParser::OperandContext* coasmParser::OperandsContext::operand(size_t i) {
  return getRuleContext<coasmParser::OperandContext>(i);
}

std::vector<tree::TerminalNode *> coasmParser::OperandsContext::COMMA() {
  return getTokens(coasmParser::COMMA);
}

tree::TerminalNode* coasmParser::OperandsContext::COMMA(size_t i) {
  return getToken(coasmParser::COMMA, i);
}


size_t coasmParser::OperandsContext::getRuleIndex() const {
  return coasmParser::RuleOperands;
}

void coasmParser::OperandsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperands(this);
}

void coasmParser::OperandsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperands(this);
}

coasmParser::OperandsContext* coasmParser::operands() {
  OperandsContext *_localctx = _tracker.createInstance<OperandsContext>(_ctx, getState());
  enterRule(_localctx, 26, coasmParser::RuleOperands);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    operand();
    setState(154);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == coasmParser::COMMA) {
      setState(150);
      match(coasmParser::COMMA);
      setState(151);
      operand();
      setState(156);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperandContext ------------------------------------------------------------------

coasmParser::OperandContext::OperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t coasmParser::OperandContext::getRuleIndex() const {
  return coasmParser::RuleOperand;
}

void coasmParser::OperandContext::copyFrom(OperandContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RegisterOperandContext ------------------------------------------------------------------

tree::TerminalNode* coasmParser::RegisterOperandContext::REGISTER() {
  return getToken(coasmParser::REGISTER, 0);
}

coasmParser::RegisterOperandContext::RegisterOperandContext(OperandContext *ctx) { copyFrom(ctx); }

void coasmParser::RegisterOperandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegisterOperand(this);
}
void coasmParser::RegisterOperandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegisterOperand(this);
}
//----------------- MemoryOperandContext ------------------------------------------------------------------

coasmParser::Memory_operandContext* coasmParser::MemoryOperandContext::memory_operand() {
  return getRuleContext<coasmParser::Memory_operandContext>(0);
}

coasmParser::MemoryOperandContext::MemoryOperandContext(OperandContext *ctx) { copyFrom(ctx); }

void coasmParser::MemoryOperandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemoryOperand(this);
}
void coasmParser::MemoryOperandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemoryOperand(this);
}
//----------------- IdentifierOperandContext ------------------------------------------------------------------

tree::TerminalNode* coasmParser::IdentifierOperandContext::IDENTIFIER() {
  return getToken(coasmParser::IDENTIFIER, 0);
}

coasmParser::IdentifierOperandContext::IdentifierOperandContext(OperandContext *ctx) { copyFrom(ctx); }

void coasmParser::IdentifierOperandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierOperand(this);
}
void coasmParser::IdentifierOperandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierOperand(this);
}
//----------------- SpecialRegisterOperandContext ------------------------------------------------------------------

tree::TerminalNode* coasmParser::SpecialRegisterOperandContext::SPECIAL_REGISTER() {
  return getToken(coasmParser::SPECIAL_REGISTER, 0);
}

coasmParser::SpecialRegisterOperandContext::SpecialRegisterOperandContext(OperandContext *ctx) { copyFrom(ctx); }

void coasmParser::SpecialRegisterOperandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpecialRegisterOperand(this);
}
void coasmParser::SpecialRegisterOperandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpecialRegisterOperand(this);
}
//----------------- ImmediateOperandContext ------------------------------------------------------------------

coasmParser::ImmediateContext* coasmParser::ImmediateOperandContext::immediate() {
  return getRuleContext<coasmParser::ImmediateContext>(0);
}

coasmParser::ImmediateOperandContext::ImmediateOperandContext(OperandContext *ctx) { copyFrom(ctx); }

void coasmParser::ImmediateOperandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImmediateOperand(this);
}
void coasmParser::ImmediateOperandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImmediateOperand(this);
}
coasmParser::OperandContext* coasmParser::operand() {
  OperandContext *_localctx = _tracker.createInstance<OperandContext>(_ctx, getState());
  enterRule(_localctx, 28, coasmParser::RuleOperand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case coasmParser::REGISTER: {
        _localctx = _tracker.createInstance<coasmParser::RegisterOperandContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(157);
        match(coasmParser::REGISTER);
        break;
      }

      case coasmParser::SPECIAL_REGISTER: {
        _localctx = _tracker.createInstance<coasmParser::SpecialRegisterOperandContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(158);
        match(coasmParser::SPECIAL_REGISTER);
        break;
      }

      case coasmParser::INTEGER_LITERAL:
      case coasmParser::HEX_LITERAL:
      case coasmParser::FLOAT_LITERAL: {
        _localctx = _tracker.createInstance<coasmParser::ImmediateOperandContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(159);
        immediate();
        break;
      }

      case coasmParser::LEFT_BRACKET: {
        _localctx = _tracker.createInstance<coasmParser::MemoryOperandContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(160);
        memory_operand();
        break;
      }

      case coasmParser::IDENTIFIER: {
        _localctx = _tracker.createInstance<coasmParser::IdentifierOperandContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(161);
        match(coasmParser::IDENTIFIER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImmediateContext ------------------------------------------------------------------

coasmParser::ImmediateContext::ImmediateContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* coasmParser::ImmediateContext::INTEGER_LITERAL() {
  return getToken(coasmParser::INTEGER_LITERAL, 0);
}

tree::TerminalNode* coasmParser::ImmediateContext::HEX_LITERAL() {
  return getToken(coasmParser::HEX_LITERAL, 0);
}

tree::TerminalNode* coasmParser::ImmediateContext::FLOAT_LITERAL() {
  return getToken(coasmParser::FLOAT_LITERAL, 0);
}


size_t coasmParser::ImmediateContext::getRuleIndex() const {
  return coasmParser::RuleImmediate;
}

void coasmParser::ImmediateContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImmediate(this);
}

void coasmParser::ImmediateContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImmediate(this);
}

coasmParser::ImmediateContext* coasmParser::immediate() {
  ImmediateContext *_localctx = _tracker.createInstance<ImmediateContext>(_ctx, getState());
  enterRule(_localctx, 30, coasmParser::RuleImmediate);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 240518168576) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Memory_operandContext ------------------------------------------------------------------

coasmParser::Memory_operandContext::Memory_operandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* coasmParser::Memory_operandContext::LEFT_BRACKET() {
  return getToken(coasmParser::LEFT_BRACKET, 0);
}

coasmParser::Memory_addressContext* coasmParser::Memory_operandContext::memory_address() {
  return getRuleContext<coasmParser::Memory_addressContext>(0);
}

tree::TerminalNode* coasmParser::Memory_operandContext::RIGHT_BRACKET() {
  return getToken(coasmParser::RIGHT_BRACKET, 0);
}


size_t coasmParser::Memory_operandContext::getRuleIndex() const {
  return coasmParser::RuleMemory_operand;
}

void coasmParser::Memory_operandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemory_operand(this);
}

void coasmParser::Memory_operandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemory_operand(this);
}

coasmParser::Memory_operandContext* coasmParser::memory_operand() {
  Memory_operandContext *_localctx = _tracker.createInstance<Memory_operandContext>(_ctx, getState());
  enterRule(_localctx, 32, coasmParser::RuleMemory_operand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    match(coasmParser::LEFT_BRACKET);
    setState(167);
    memory_address();
    setState(168);
    match(coasmParser::RIGHT_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Memory_addressContext ------------------------------------------------------------------

coasmParser::Memory_addressContext::Memory_addressContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<coasmParser::OperandContext *> coasmParser::Memory_addressContext::operand() {
  return getRuleContexts<coasmParser::OperandContext>();
}

coasmParser::OperandContext* coasmParser::Memory_addressContext::operand(size_t i) {
  return getRuleContext<coasmParser::OperandContext>(i);
}

std::vector<tree::TerminalNode *> coasmParser::Memory_addressContext::PLUS() {
  return getTokens(coasmParser::PLUS);
}

tree::TerminalNode* coasmParser::Memory_addressContext::PLUS(size_t i) {
  return getToken(coasmParser::PLUS, i);
}


size_t coasmParser::Memory_addressContext::getRuleIndex() const {
  return coasmParser::RuleMemory_address;
}

void coasmParser::Memory_addressContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemory_address(this);
}

void coasmParser::Memory_addressContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemory_address(this);
}

coasmParser::Memory_addressContext* coasmParser::memory_address() {
  Memory_addressContext *_localctx = _tracker.createInstance<Memory_addressContext>(_ctx, getState());
  enterRule(_localctx, 34, coasmParser::RuleMemory_address);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(170);
    operand();
    setState(175);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == coasmParser::PLUS) {
      setState(171);
      match(coasmParser::PLUS);
      setState(172);
      operand();
      setState(177);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Line_commentContext ------------------------------------------------------------------

coasmParser::Line_commentContext::Line_commentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* coasmParser::Line_commentContext::LINE_COMMENT() {
  return getToken(coasmParser::LINE_COMMENT, 0);
}


size_t coasmParser::Line_commentContext::getRuleIndex() const {
  return coasmParser::RuleLine_comment;
}

void coasmParser::Line_commentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine_comment(this);
}

void coasmParser::Line_commentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<coasmListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine_comment(this);
}

coasmParser::Line_commentContext* coasmParser::line_comment() {
  Line_commentContext *_localctx = _tracker.createInstance<Line_commentContext>(_ctx, getState());
  enterRule(_localctx, 36, coasmParser::RuleLine_comment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(178);
    match(coasmParser::LINE_COMMENT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void coasmParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  coasmParserInitialize();
#else
  ::antlr4::internal::call_once(coasmParserOnceFlag, coasmParserInitialize);
#endif
}
