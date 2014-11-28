#include "AST/Nodes/Declaration.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CParameterDeclerator::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitParameterDeclerator(std::static_pointer_cast<CParameterDeclerator>(shared_from_this()));
	}
}
