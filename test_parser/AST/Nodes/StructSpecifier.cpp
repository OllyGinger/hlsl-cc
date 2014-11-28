#include "AST/Nodes/Declaration.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CStructSpecifier::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitStructSpecifier(std::static_pointer_cast<CStructSpecifier>(shared_from_this()));
	}

	bool CCBufferSpecifier::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitCBufferSpecifier(std::static_pointer_cast<CCBufferSpecifier>(shared_from_this()));
	}
}
