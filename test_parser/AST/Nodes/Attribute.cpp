#include "AST/Nodes/Attribute.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CAttribute::VisitNodes(IVisitor* visitor)
	{
		return visitor->VisitAttribute(std::static_pointer_cast<CAttribute>(shared_from_this()));
	}


	bool CAttributeArgument::VisitNodes(IVisitor* visitor)
	{
		return visitor->VisitAttributeArgument(std::static_pointer_cast<CAttributeArgument>(shared_from_this()));
	}
}
