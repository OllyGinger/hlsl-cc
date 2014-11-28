#include "AST/Nodes/Declaration.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CIterationStatement::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitIterationStatement(std::static_pointer_cast<CIterationStatement>(shared_from_this()));
		visitor->PushScope();
		m_RestExpression->VisitNodes(visitor);
		m_Body->VisitNodes(visitor);
		visitor->PopScope();
		return true;
	}
}
