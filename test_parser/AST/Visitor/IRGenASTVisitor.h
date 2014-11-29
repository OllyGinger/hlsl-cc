#pragma once
#include "AST/Visitor/Visitor.h"
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>

#include <stack>

namespace AST
{
	class CIRGenASTVisitor : public IVisitor
	{
	public:
		CIRGenASTVisitor();
		~CIRGenASTVisitor();

		virtual bool VisitAttribute(CAttribute::TPointer attribute) override;
		virtual bool VisitAttributeArgument(CAttributeArgument::TPointer attributeArgument) override;
		virtual bool VisitCompoundStatement(CCompoundStatement::TPointer compoundStatement) override;
		virtual bool VisitDecleration(CDecleration::TPointer decleration) override;
		virtual bool VisitDeclerationList(CDecleratorList::TPointer declerationList) override;
		virtual bool VisitExpression(CExpression::TPointer expression) override;
		virtual bool VisitExpressionStatement(CExpressionStatement::TPointer expressionStatement) override;
		virtual bool VisitBinaryExpression(CBinaryExpression::TPointer binaryExpression) override;
		virtual bool VisitFunctionExpression(CFunctionExpression::TPointer functionExpression) override;
		virtual bool VisitInitialiserListExpression(CInitialiserListExpression::TPointer initialiserListExpression) override;
		virtual bool VisitFlowControlStatement(CFlowControlStatement::TPointer flowControlStatement) override;
		virtual bool VisitFunction(CFunction::TPointer func) override;
		virtual bool VisitFunctionDefinition(CFunctionDefinition::TPointer functionDefinition) override;
		virtual bool VisitIterationStatement(CIterationStatement::TPointer iterationStatement) override;
		virtual bool VisitParameterDeclerator(CParameterDeclerator::TPointer parameterDeclerator) override;
		virtual bool VisitPrecisionType(CPrecisionType::TPointer precisionType) override;
		virtual bool VisitSelectionStatement(CSelectionStatement::TPointer selectionStatement) override;
		virtual bool VisitStructSpecifier(CStructSpecifier::TPointer structSpecifier) override;
		virtual bool VisitCBufferSpecifier(CCBufferSpecifier::TPointer cBufferSpecifier) override;
		virtual bool VisitSwitchStatement(CSwitchStatement::TPointer switchStatement) override;
		virtual bool VisitSwitchBody(CSwitchBody::TPointer switchBody) override;
		virtual bool VisitCaseLabel(CCaseLabel::TPointer caseLabel) override;
		virtual bool VisitCaseLabelList(CCaseLabelList::TPointer caseLabelList) override;
		virtual bool VisitCaseStatement(CCaseStatement::TPointer caseStatement) override;
		virtual bool VisitCaseStatementList(CCaseStatementList::TPointer caseStatementList) override;
		virtual bool VisitTypeSpecifier(CTypeSpecifier::TPointer typeSpecifier) override;
		virtual bool VisitFullySpecifiedType(CFullySpecifiedType::TPointer fullySpecifiedType) override;

		llvm::Module* GetModule() const { return m_Module; }

		llvm::Function* m_func;

	protected:
		virtual void PushBlockScope(llvm::BasicBlock* block);
		virtual void PopBlockScope();

	private:
		llvm::Type* TypeOf(CFullySpecifiedType::TPointer type);
		llvm::Type* TypeOf(CTypeSpecifier::TPointer type);
		llvm::BasicBlock* GetCurrentScopeBlock() const { return m_BlockStack.top(); }

		llvm::Instruction::BinaryOps GetBinaryOpInstructionForValues(EOperator::Enum op, llvm::Value* lhs, llvm::Value* rhs);

	private:
		CSymbolTable m_SymbolTable;
		llvm::Module* m_Module;
		llvm::IRBuilder<> m_IRBuilder;
		std::stack<llvm::BasicBlock*> m_BlockStack;
		llvm::Value* m_LastValue;
	};
}
