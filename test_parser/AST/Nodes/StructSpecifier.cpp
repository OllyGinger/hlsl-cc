#include "AST/Nodes/Declaration.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CStructSpecifier::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitStructSpecifier(std::static_pointer_cast<CStructSpecifier>(shared_from_this()));
		
		visitor->PushScope();
		m_DecleratorList->VisitNodes(visitor);
		visitor->PopScope();
		return true;
	}

	bool CCBufferSpecifier::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitCBufferSpecifier(std::static_pointer_cast<CCBufferSpecifier>(shared_from_this()));

		visitor->PushScope();
		m_DecleratorList->VisitNodes(visitor);
		visitor->PopScope();
		return true;
	}
}
