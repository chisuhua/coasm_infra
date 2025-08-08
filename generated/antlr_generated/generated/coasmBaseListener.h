
// Generated from generated/coasm.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "coasmListener.h"


/**
 * This class provides an empty implementation of coasmListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  coasmBaseListener : public coasmListener {
public:

  virtual void enterProg(coasmParser::ProgContext * /*ctx*/) override { }
  virtual void exitProg(coasmParser::ProgContext * /*ctx*/) override { }

  virtual void enterDirectiveLine(coasmParser::DirectiveLineContext * /*ctx*/) override { }
  virtual void exitDirectiveLine(coasmParser::DirectiveLineContext * /*ctx*/) override { }

  virtual void enterLabelLine(coasmParser::LabelLineContext * /*ctx*/) override { }
  virtual void exitLabelLine(coasmParser::LabelLineContext * /*ctx*/) override { }

  virtual void enterInstructionLine(coasmParser::InstructionLineContext * /*ctx*/) override { }
  virtual void exitInstructionLine(coasmParser::InstructionLineContext * /*ctx*/) override { }

  virtual void enterBlockLine(coasmParser::BlockLineContext * /*ctx*/) override { }
  virtual void exitBlockLine(coasmParser::BlockLineContext * /*ctx*/) override { }

  virtual void enterCommentLine(coasmParser::CommentLineContext * /*ctx*/) override { }
  virtual void exitCommentLine(coasmParser::CommentLineContext * /*ctx*/) override { }

  virtual void enterEmptyLine(coasmParser::EmptyLineContext * /*ctx*/) override { }
  virtual void exitEmptyLine(coasmParser::EmptyLineContext * /*ctx*/) override { }

  virtual void enterDirective(coasmParser::DirectiveContext * /*ctx*/) override { }
  virtual void exitDirective(coasmParser::DirectiveContext * /*ctx*/) override { }

  virtual void enterSection_directive(coasmParser::Section_directiveContext * /*ctx*/) override { }
  virtual void exitSection_directive(coasmParser::Section_directiveContext * /*ctx*/) override { }

  virtual void enterKernel_metadata_start(coasmParser::Kernel_metadata_startContext * /*ctx*/) override { }
  virtual void exitKernel_metadata_start(coasmParser::Kernel_metadata_startContext * /*ctx*/) override { }

  virtual void enterKernel_metadata_item(coasmParser::Kernel_metadata_itemContext * /*ctx*/) override { }
  virtual void exitKernel_metadata_item(coasmParser::Kernel_metadata_itemContext * /*ctx*/) override { }

  virtual void enterMetadata_entry_line(coasmParser::Metadata_entry_lineContext * /*ctx*/) override { }
  virtual void exitMetadata_entry_line(coasmParser::Metadata_entry_lineContext * /*ctx*/) override { }

  virtual void enterMetadata_key(coasmParser::Metadata_keyContext * /*ctx*/) override { }
  virtual void exitMetadata_key(coasmParser::Metadata_keyContext * /*ctx*/) override { }

  virtual void enterMetadata_value(coasmParser::Metadata_valueContext * /*ctx*/) override { }
  virtual void exitMetadata_value(coasmParser::Metadata_valueContext * /*ctx*/) override { }

  virtual void enterLabel(coasmParser::LabelContext * /*ctx*/) override { }
  virtual void exitLabel(coasmParser::LabelContext * /*ctx*/) override { }

  virtual void enterBlock(coasmParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(coasmParser::BlockContext * /*ctx*/) override { }

  virtual void enterInstruction(coasmParser::InstructionContext * /*ctx*/) override { }
  virtual void exitInstruction(coasmParser::InstructionContext * /*ctx*/) override { }

  virtual void enterInstruction_suffix(coasmParser::Instruction_suffixContext * /*ctx*/) override { }
  virtual void exitInstruction_suffix(coasmParser::Instruction_suffixContext * /*ctx*/) override { }

  virtual void enterOperands(coasmParser::OperandsContext * /*ctx*/) override { }
  virtual void exitOperands(coasmParser::OperandsContext * /*ctx*/) override { }

  virtual void enterRegisterOperand(coasmParser::RegisterOperandContext * /*ctx*/) override { }
  virtual void exitRegisterOperand(coasmParser::RegisterOperandContext * /*ctx*/) override { }

  virtual void enterSpecialRegisterOperand(coasmParser::SpecialRegisterOperandContext * /*ctx*/) override { }
  virtual void exitSpecialRegisterOperand(coasmParser::SpecialRegisterOperandContext * /*ctx*/) override { }

  virtual void enterImmediateOperand(coasmParser::ImmediateOperandContext * /*ctx*/) override { }
  virtual void exitImmediateOperand(coasmParser::ImmediateOperandContext * /*ctx*/) override { }

  virtual void enterMemoryOperand(coasmParser::MemoryOperandContext * /*ctx*/) override { }
  virtual void exitMemoryOperand(coasmParser::MemoryOperandContext * /*ctx*/) override { }

  virtual void enterIdentifierOperand(coasmParser::IdentifierOperandContext * /*ctx*/) override { }
  virtual void exitIdentifierOperand(coasmParser::IdentifierOperandContext * /*ctx*/) override { }

  virtual void enterImmediate(coasmParser::ImmediateContext * /*ctx*/) override { }
  virtual void exitImmediate(coasmParser::ImmediateContext * /*ctx*/) override { }

  virtual void enterMemory_operand(coasmParser::Memory_operandContext * /*ctx*/) override { }
  virtual void exitMemory_operand(coasmParser::Memory_operandContext * /*ctx*/) override { }

  virtual void enterMemory_address(coasmParser::Memory_addressContext * /*ctx*/) override { }
  virtual void exitMemory_address(coasmParser::Memory_addressContext * /*ctx*/) override { }

  virtual void enterLine_comment(coasmParser::Line_commentContext * /*ctx*/) override { }
  virtual void exitLine_comment(coasmParser::Line_commentContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

