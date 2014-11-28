#include "AST/Nodes/Function.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CFunction::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitFunction(std::static_pointer_cast<CFunction>(shared_from_this()));
		
		visitor->PushScope();
		for (auto params : m_Parameters)
		{
			params->VisitNodes(visitor);
		}

		m_ReturnType->VisitNodes(visitor);
		visitor->PopScope();
		return true;
	}

	bool CFunctionDefinition::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitFunctionDefinition(std::static_pointer_cast<CFunctionDefinition>(shared_from_this()));

		visitor->PushScope();
		m_Prototype->VisitNodes(visitor);
		m_Body->VisitNodes(visitor);
		visitor->PopScope();
		return true;
	}
}
