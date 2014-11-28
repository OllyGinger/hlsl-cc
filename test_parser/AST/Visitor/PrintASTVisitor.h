#pragma once
#include "AST/Visitor/Visitor.h"
#include <ostream>
#include <stack>

namespace AST
{
	class CPrintASTVisitor : public IVisitor
	{
	public:
		CPrintASTVisitor(std::ostream &outputStream) 
			: m_OutputStream(outputStream) 
			, m_Depth(0)
		{}

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

	private:
		inline virtual void PushScope() override { m_Depth++; }
		inline virtual void PopScope() override { m_Depth--; }
		void Indent();
		void OutputSourceLocation(CNode::TPointer node, bool outputFile = false, bool outputLine = true, bool outputCol = true);

	private:
		std::ostream& m_OutputStream;
		uint32_t m_Depth;
	};
}
