#include "AST/Nodes/Declaration.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CParameterDeclerator::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitParameterDeclerator(std::static_pointer_cast<CParameterDeclerator>(shared_from_this()));
		
		visitor->PushScope();
		m_Type->VisitNodes(visitor);
		if (m_IsArray)
		{
			m_ArraySize->VisitNodes(visitor);
		}

		if (m_DefaultValue)
		{
			m_DefaultValue->VisitNodes(visitor);
		}
		visitor->PopScope();
		return true;
	}
}
