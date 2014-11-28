#include "AST/Nodes/Declaration.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CSelectionStatement::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitSelectionStatement(std::static_pointer_cast<CSelectionStatement>(shared_from_this()));
	}
}
