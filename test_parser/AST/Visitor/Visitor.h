#pragma once

#include "AST/ParserType.h"

namespace AST
{
	class IVisitor
	{
	public:
		virtual bool VisitAttribute(CAttribute::TPointer attribute) = 0;
		virtual bool VisitAttributeArgument(CAttributeArgument::TPointer attributeArgument) = 0;
		virtual bool VisitCompoundStatement(CCompoundStatement::TPointer compoundStatement) = 0;
		virtual bool VisitDecleration(CDecleration::TPointer decleration) = 0;
		virtual bool VisitDeclerationList(CDecleratorList::TPointer declerationList) = 0;
		virtual bool VisitExpression(CExpression::TPointer expression) = 0;
		virtual bool VisitExpressionStatement(CExpressionStatement::TPointer expressionStatement) = 0;
		virtual bool VisitBinaryExpression(CBinaryExpression::TPointer binaryExpression) = 0;
		virtual bool VisitFunctionExpression(CFunctionExpression::TPointer functionExpression) = 0;
		virtual bool VisitInitialiserListExpression(CInitialiserListExpression::TPointer initialiserListExpression) = 0;
		virtual bool VisitFlowControlStatement(CFlowControlStatement::TPointer flowControlStatement) = 0;
		virtual bool VisitFunction(CFunction::TPointer func) = 0;
		virtual bool VisitFunctionDefinition(CFunctionDefinition::TPointer functionDefinition) = 0;
		virtual bool VisitIterationStatement(CIterationStatement::TPointer iterationStatement) = 0;
		virtual bool VisitParameterDeclerator(CParameterDeclerator::TPointer parameterDeclerator) = 0;
		virtual bool VisitPrecisionType(CPrecisionType::TPointer precisionType) = 0;
		virtual bool VisitSelectionStatement(CSelectionStatement::TPointer selectionStatement) = 0;
		virtual bool VisitStructSpecifier(CStructSpecifier::TPointer structSpecifier) = 0;
		virtual bool VisitCBufferSpecifier(CCBufferSpecifier::TPointer cBufferSpecifier) = 0;
		virtual bool VisitSwitchStatement(CSwitchStatement::TPointer switchStatement) = 0;
		virtual bool VisitSwitchBody(CSwitchBody::TPointer switchBody) = 0;
		virtual bool VisitCaseLabel(CCaseLabel::TPointer caseLabel) = 0;
		virtual bool VisitCaseLabelList(CCaseLabelList::TPointer caseLabelList) = 0;
		virtual bool VisitCaseStatement(CCaseStatement::TPointer caseStatement) = 0;
		virtual bool VisitCaseStatementList(CCaseStatementList::TPointer caseStatementList) = 0;
		virtual bool VisitTypeSpecifier(CTypeSpecifier::TPointer typeSpecifier) = 0;
		virtual bool VisitFullySpecifiedType(CFullySpecifiedType::TPointer fullySpecifiedType) = 0;
	};
}
