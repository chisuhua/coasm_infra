
// Generated from generated/coasm.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "coasmParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by coasmParser.
 */
class  coasmListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProg(coasmParser::ProgContext *ctx) = 0;
  virtual void exitProg(coasmParser::ProgContext *ctx) = 0;

  virtual void enterDirectiveLine(coasmParser::DirectiveLineContext *ctx) = 0;
  virtual void exitDirectiveLine(coasmParser::DirectiveLineContext *ctx) = 0;

  virtual void enterLabelLine(coasmParser::LabelLineContext *ctx) = 0;
  virtual void exitLabelLine(coasmParser::LabelLineContext *ctx) = 0;

  virtual void enterInstructionLine(coasmParser::InstructionLineContext *ctx) = 0;
  virtual void exitInstructionLine(coasmParser::InstructionLineContext *ctx) = 0;

  virtual void enterBlockLine(coasmParser::BlockLineContext *ctx) = 0;
  virtual void exitBlockLine(coasmParser::BlockLineContext *ctx) = 0;

  virtual void enterCommentLine(coasmParser::CommentLineContext *ctx) = 0;
  virtual void exitCommentLine(coasmParser::CommentLineContext *ctx) = 0;

  virtual void enterEmptyLine(coasmParser::EmptyLineContext *ctx) = 0;
  virtual void exitEmptyLine(coasmParser::EmptyLineContext *ctx) = 0;

  virtual void enterDirective(coasmParser::DirectiveContext *ctx) = 0;
  virtual void exitDirective(coasmParser::DirectiveContext *ctx) = 0;

  virtual void enterSection_directive(coasmParser::Section_directiveContext *ctx) = 0;
  virtual void exitSection_directive(coasmParser::Section_directiveContext *ctx) = 0;

  virtual void enterKernel_metadata_start(coasmParser::Kernel_metadata_startContext *ctx) = 0;
  virtual void exitKernel_metadata_start(coasmParser::Kernel_metadata_startContext *ctx) = 0;

  virtual void enterKernel_metadata_item(coasmParser::Kernel_metadata_itemContext *ctx) = 0;
  virtual void exitKernel_metadata_item(coasmParser::Kernel_metadata_itemContext *ctx) = 0;

  virtual void enterMetadata_entry_line(coasmParser::Metadata_entry_lineContext *ctx) = 0;
  virtual void exitMetadata_entry_line(coasmParser::Metadata_entry_lineContext *ctx) = 0;

  virtual void enterMetadata_key(coasmParser::Metadata_keyContext *ctx) = 0;
  virtual void exitMetadata_key(coasmParser::Metadata_keyContext *ctx) = 0;

  virtual void enterMetadata_value(coasmParser::Metadata_valueContext *ctx) = 0;
  virtual void exitMetadata_value(coasmParser::Metadata_valueContext *ctx) = 0;

  virtual void enterLabel(coasmParser::LabelContext *ctx) = 0;
  virtual void exitLabel(coasmParser::LabelContext *ctx) = 0;

  virtual void enterBlock(coasmParser::BlockContext *ctx) = 0;
  virtual void exitBlock(coasmParser::BlockContext *ctx) = 0;

  virtual void enterInstruction(coasmParser::InstructionContext *ctx) = 0;
  virtual void exitInstruction(coasmParser::InstructionContext *ctx) = 0;

  virtual void enterInstruction_suffix(coasmParser::Instruction_suffixContext *ctx) = 0;
  virtual void exitInstruction_suffix(coasmParser::Instruction_suffixContext *ctx) = 0;

  virtual void enterOperands(coasmParser::OperandsContext *ctx) = 0;
  virtual void exitOperands(coasmParser::OperandsContext *ctx) = 0;

  virtual void enterRegisterOperand(coasmParser::RegisterOperandContext *ctx) = 0;
  virtual void exitRegisterOperand(coasmParser::RegisterOperandContext *ctx) = 0;

  virtual void enterSpecialRegisterOperand(coasmParser::SpecialRegisterOperandContext *ctx) = 0;
  virtual void exitSpecialRegisterOperand(coasmParser::SpecialRegisterOperandContext *ctx) = 0;

  virtual void enterImmediateOperand(coasmParser::ImmediateOperandContext *ctx) = 0;
  virtual void exitImmediateOperand(coasmParser::ImmediateOperandContext *ctx) = 0;

  virtual void enterMemoryOperand(coasmParser::MemoryOperandContext *ctx) = 0;
  virtual void exitMemoryOperand(coasmParser::MemoryOperandContext *ctx) = 0;

  virtual void enterIdentifierOperand(coasmParser::IdentifierOperandContext *ctx) = 0;
  virtual void exitIdentifierOperand(coasmParser::IdentifierOperandContext *ctx) = 0;

  virtual void enterImmediate(coasmParser::ImmediateContext *ctx) = 0;
  virtual void exitImmediate(coasmParser::ImmediateContext *ctx) = 0;

  virtual void enterMemory_operand(coasmParser::Memory_operandContext *ctx) = 0;
  virtual void exitMemory_operand(coasmParser::Memory_operandContext *ctx) = 0;

  virtual void enterMemory_address(coasmParser::Memory_addressContext *ctx) = 0;
  virtual void exitMemory_address(coasmParser::Memory_addressContext *ctx) = 0;

  virtual void enterLine_comment(coasmParser::Line_commentContext *ctx) = 0;
  virtual void exitLine_comment(coasmParser::Line_commentContext *ctx) = 0;


};

