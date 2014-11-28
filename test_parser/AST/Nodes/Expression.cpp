#include "AST/Nodes/Expression.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CExpression::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitExpression(std::static_pointer_cast<CExpression>(shared_from_this()));
	}

	bool CExpressionStatement::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitExpressionStatement(std::static_pointer_cast<CExpressionStatement>(shared_from_this()));
	}

	bool CBinaryExpression::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitBinaryExpression(std::static_pointer_cast<CBinaryExpression>(shared_from_this()));
	}

	bool CFunctionExpression::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitFunctionExpression(std::static_pointer_cast<CFunctionExpression>(shared_from_this()));
	}

	bool CInitialiserListExpression::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitInitialiserListExpression(std::static_pointer_cast<CInitialiserListExpression>(shared_from_this()));
	}
}
