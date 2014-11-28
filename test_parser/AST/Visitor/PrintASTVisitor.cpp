#include "AST/Visitor/PrintASTVisitor.h"

namespace AST
{
	bool CPrintASTVisitor::VisitAttribute(CAttribute::TPointer attribute)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitAttributeArgument(CAttributeArgument::TPointer attributeArgument)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitCompoundStatement(CCompoundStatement::TPointer compoundStatement)
	{
		Indent();
		m_OutputStream << "CompoundStatement ";
		OutputSourceLocation(compoundStatement);
		m_OutputStream << "\n";
		return true;
	}

	bool CPrintASTVisitor::VisitDecleration(CDecleration::TPointer decleration)
	{
		Indent();
		m_OutputStream << "Declaration ";
		OutputSourceLocation(decleration);

		m_OutputStream << " " << decleration->GetIdentifier();

		if (decleration->IsArray())
		{
			m_OutputStream << "[]";
		}

		m_OutputStream << "\n";
		return true;
	}

	bool CPrintASTVisitor::VisitDeclerationList(CDecleratorList::TPointer declerationList)
	{
		Indent();
		m_OutputStream << "DecleratorList ";
		OutputSourceLocation(declerationList);
		m_OutputStream << "\n";
		return true;
	}

	bool CPrintASTVisitor::VisitExpression(CExpression::TPointer expression)
	{
		Indent();
		m_OutputStream << "Expression ";
		OutputSourceLocation(expression);

		EOperator::Enum op = expression->GetOperator();
		m_OutputStream << " " << EOperator::ToString(op) << " ";

		switch (op)
		{
		case EOperator::IntConstant:
			m_OutputStream << expression->GetExpression().u.IntConstant;
			break;
		case EOperator::UIntConstant:
			m_OutputStream << expression->GetExpression().u.UIntConstant;
			break;
		case EOperator::FloatConstant:
			m_OutputStream << expression->GetExpression().u.FloatConstant;
			break;
		case EOperator::BoolConstant:
			m_OutputStream << expression->GetExpression().u.BoolConstant;
			break;

		case EOperator::Identifier:
			m_OutputStream << expression->GetIdentifier();
			break;
		}
		m_OutputStream << "\n";
		return true;
	}

	bool CPrintASTVisitor::VisitExpressionStatement(CExpressionStatement::TPointer expressionStatement)
	{
		// Pass
		return true;
	}

	bool CPrintASTVisitor::VisitBinaryExpression(CBinaryExpression::TPointer binaryExpression)
	{
		Indent();
		m_OutputStream << "BinaryExpression ";
		OutputSourceLocation(binaryExpression);
		m_OutputStream << "\n";
		return true;
	}

	bool CPrintASTVisitor::VisitFunctionExpression(CFunctionExpression::TPointer functionExpression)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitInitialiserListExpression(CInitialiserListExpression::TPointer initialiserListExpression)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitFlowControlStatement(CFlowControlStatement::TPointer flowControlStatement)
	{
		Indent();
		m_OutputStream << "FlowControlStatement ";
		OutputSourceLocation(flowControlStatement);

		m_OutputStream << " " << CFlowControlStatement::EType::ToString(flowControlStatement->GetType());
		m_OutputStream << "\n";
		return true;
	}

	bool CPrintASTVisitor::VisitFunction(CFunction::TPointer func)
	{
		Indent();
		m_OutputStream << "FunctionPrototype ";
		OutputSourceLocation(func);

		// Print the return type
		CFullySpecifiedType::TPointer returnType = func->GetReturnType();
		CTypeSpecifier::TPointer returnTypeSpecifier = returnType->GetTypeSpecifier();
		m_OutputStream << " " << returnTypeSpecifier->GetTypeName() << " ";

		// Function name
		m_OutputStream << func->GetIdentifier();
		m_OutputStream << "(";

		// Print the params
		auto funcParams = func->GetParameters();
		size_t numFuncParams = funcParams.size();
		size_t paramIt = 0;
		for (auto param : funcParams)
		{
			CFullySpecifiedType::TPointer paramType = param->GetType();
			CTypeSpecifier::TPointer paramTypeSpecifier = paramType->GetTypeSpecifier();

			m_OutputStream << paramTypeSpecifier->GetTypeName() << " ";
			m_OutputStream << param->GetIdentifier();

			if (paramIt < numFuncParams-1)
			{
				m_OutputStream << ", ";
			}
			
			paramIt++;
		}
		m_OutputStream << ")\n";
		return true;
	}

	bool CPrintASTVisitor::VisitFunctionDefinition(CFunctionDefinition::TPointer functionDefinition)
	{
		Indent();
		m_OutputStream << "FunctionDefinition ";
		OutputSourceLocation(functionDefinition);
		m_OutputStream << "\n";
		return true;
	}

	bool CPrintASTVisitor::VisitIterationStatement(CIterationStatement::TPointer iterationStatement)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitParameterDeclerator(CParameterDeclerator::TPointer parameterDeclerator)
	{
		Indent();
		m_OutputStream << "ParamDeclerator ";
		OutputSourceLocation(parameterDeclerator);

		CFullySpecifiedType::TPointer paramType = parameterDeclerator->GetType();
		CTypeSpecifier::TPointer paramTypeSpecifier = paramType->GetTypeSpecifier();

		m_OutputStream << " " << paramTypeSpecifier->GetTypeName() << " ";
		m_OutputStream << parameterDeclerator->GetIdentifier();
		m_OutputStream << "\n";
		return true;
	}

	bool CPrintASTVisitor::VisitPrecisionType(CPrecisionType::TPointer precisionType)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitSelectionStatement(CSelectionStatement::TPointer selectionStatement)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitStructSpecifier(CStructSpecifier::TPointer structSpecifier)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitCBufferSpecifier(CCBufferSpecifier::TPointer cBufferSpecifier)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitSwitchStatement(CSwitchStatement::TPointer switchStatement)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitSwitchBody(CSwitchBody::TPointer switchBody)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitCaseLabel(CCaseLabel::TPointer caseLabel)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitCaseLabelList(CCaseLabelList::TPointer caseLabelList)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitCaseStatement(CCaseStatement::TPointer caseStatement)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitCaseStatementList(CCaseStatementList::TPointer caseStatementList)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CPrintASTVisitor::VisitTypeSpecifier(CTypeSpecifier::TPointer typeSpecifier)
	{
		Indent();
		m_OutputStream << "FullySpecifiedType ";
		OutputSourceLocation(typeSpecifier);

		m_OutputStream << " " << typeSpecifier->GetTypeName();

		m_OutputStream << "\n";
		return true;
	}

	bool CPrintASTVisitor::VisitFullySpecifiedType(CFullySpecifiedType::TPointer fullySpecifiedType)
	{
		Indent();
		m_OutputStream << "FullySpecifiedType ";
		OutputSourceLocation(fullySpecifiedType);
		m_OutputStream << "\n";
		return true;
	}

	void CPrintASTVisitor::Indent()
	{
		for (uint32_t i = 0; i < m_Depth; i++)
		{
			m_OutputStream << "    ";
		}
	}

	void CPrintASTVisitor::OutputSourceLocation(CNode::TPointer node, bool outputFile /*= false*/,
		bool outputLine /*= true*/, bool outputCol /*= true*/)
	{
		AST::CSourceLocation location = node->GetSourceLocation();
		m_OutputStream << "<";

		if (outputFile)
		{
			m_OutputStream << "file: " << location.SourceFile << ", ";
		}

		if (outputLine)
		{
			m_OutputStream << "line: " << location.Line << ", ";
		}

		if (outputCol)
		{
			m_OutputStream << "col: " << location.Column;
		}

		m_OutputStream << ">";
	}

}
