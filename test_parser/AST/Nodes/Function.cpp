#include "AST/Nodes/Function.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CFunction::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitFunction(std::static_pointer_cast<CFunction>(shared_from_this()));
	}

	bool CFunctionDefinition::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitFunctionDefinition(std::static_pointer_cast<CFunctionDefinition>(shared_from_this()));
	}
}
