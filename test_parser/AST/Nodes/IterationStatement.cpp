#include "AST/Nodes/Declaration.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CIterationStatement::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitIterationStatement(std::static_pointer_cast<CIterationStatement>(shared_from_this()));
	}
}
