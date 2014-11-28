#include "AST/Nodes/Declaration.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CDecleration::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitDecleration(std::static_pointer_cast<CDecleration>(shared_from_this()));
	}


	bool CDecleratorList::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitDeclerationList(std::static_pointer_cast<CDecleratorList>(shared_from_this()));
	}
}
