#include "AST/Nodes/CompoundStatement.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CCompoundStatement::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitCompoundStatement(std::static_pointer_cast<CCompoundStatement>(shared_from_this()));
		visitor->PushScope();
		m_Statements->VisitNodes(visitor);
		visitor->PopScope();
		return true;
	}
}