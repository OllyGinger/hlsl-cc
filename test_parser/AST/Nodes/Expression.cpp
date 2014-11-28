#include "AST/Nodes/Expression.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CExpression::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitExpression(std::static_pointer_cast<CExpression>(shared_from_this()));

		visitor->PushScope();
		for (auto subExpression : m_SubExpressions)
		{
			if (subExpression)
			{
				subExpression->VisitNodes(visitor);
			}
		}
		visitor->PopScope();
		return true;
	}

	bool CExpressionStatement::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitExpressionStatement(std::static_pointer_cast<CExpressionStatement>(shared_from_this()));

		visitor->PushScope();
		if (m_Expression)
		{
			m_Expression->VisitNodes(visitor);
		}
		visitor->PopScope();
		return true;
	}

	bool CBinaryExpression::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitBinaryExpression(std::static_pointer_cast<CBinaryExpression>(shared_from_this()));

		visitor->PushScope();
		// Call base
		CExpression::VisitNodes(visitor);
		visitor->PopScope();
		return true;
	}

	bool CFunctionExpression::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitFunctionExpression(std::static_pointer_cast<CFunctionExpression>(shared_from_this()));

		visitor->PushScope();
		// Call base
		CExpression::VisitNodes(visitor);
		visitor->PopScope();
		return true;
	}

	bool CInitialiserListExpression::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitInitialiserListExpression(std::static_pointer_cast<CInitialiserListExpression>(shared_from_this()));

		visitor->PushScope();
		// Call base
		CExpression::VisitNodes(visitor);
		visitor->PopScope();
		return true;
	}
}
