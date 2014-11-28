#include "AST/Nodes/Declaration.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CSelectionStatement::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitSelectionStatement(std::static_pointer_cast<CSelectionStatement>(shared_from_this()));
		
		visitor->PushScope();
		m_Condition->VisitNodes(visitor);
		m_Then->VisitNodes(visitor);

		if (m_Else)
		{
			m_Else->VisitNodes(visitor);
		}
		visitor->PopScope();

		return true;
	}
}
