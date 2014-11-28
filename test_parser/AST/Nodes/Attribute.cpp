#include "AST/Nodes/Attribute.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CAttribute::VisitNodes(IVisitor* visitor)
	{
		visitor->VisitAttribute(std::static_pointer_cast<CAttribute>(shared_from_this()));
		return true;
	}


	bool CAttributeArgument::VisitNodes(IVisitor* visitor)
	{
		visitor->VisitAttributeArgument(std::static_pointer_cast<CAttributeArgument>(shared_from_this()));

		visitor->PushScope();
		m_ExpressionArgument->VisitNodes(visitor);
		visitor->PopScope();
		return true;
	}
}
