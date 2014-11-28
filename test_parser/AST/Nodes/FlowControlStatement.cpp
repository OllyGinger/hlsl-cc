#include "AST/Nodes/FlowControlStatement.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CFlowControlStatement::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitFlowControlStatement(std::static_pointer_cast<CFlowControlStatement>(shared_from_this()));

		visitor->PushScope();
		m_ReturnExpression->VisitNodes(visitor);
		visitor->PopScope();
		return true;
	}
}
