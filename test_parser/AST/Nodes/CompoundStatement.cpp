#include "AST/Nodes/CompoundStatement.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CCompoundStatement::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitCompoundStatement(std::static_pointer_cast<CCompoundStatement>(shared_from_this()));
	}
}