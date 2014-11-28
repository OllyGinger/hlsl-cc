#include "AST/Nodes/Declaration.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CDecleration::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitDecleration(std::static_pointer_cast<CDecleration>(shared_from_this()));

		visitor->PushScope();
		if (m_IsArray && m_ArraySize)
		{
			m_ArraySize->VisitNodes(visitor);
		}
		
		if (m_Initialiser)
		{
			m_Initialiser->VisitNodes(visitor);
		}
		visitor->PopScope();

		return true;
	}


	bool CDecleratorList::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitDeclerationList(std::static_pointer_cast<CDecleratorList>(shared_from_this()));

		visitor->PushScope();
		m_Type->VisitNodes(visitor);
		for (auto node : m_Declerations)
		{
			node->VisitNodes(visitor);
		}
		visitor->PopScope();

		for (auto link : m_Links)
		{
			if (link && link.get() != this)
			{
				link->VisitNodes(visitor);
			}
		}
		return true;
	}
}
