#include "AST/Nodes/Declaration.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CSwitchStatement::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitSwitchStatement(std::static_pointer_cast<CSwitchStatement>(shared_from_this()));
		
		visitor->PushScope();
		m_Test->VisitNodes(visitor);
		m_Body->VisitNodes(visitor);
		visitor->PopScope();
		return true;
	}

	bool CSwitchBody::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitSwitchBody(std::static_pointer_cast<CSwitchBody>(shared_from_this()));

		return true;
	}

	bool CCaseLabel::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitCaseLabel(std::static_pointer_cast<CCaseLabel>(shared_from_this()));

		return true;
	}

	bool CCaseLabelList::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitCaseLabelList(std::static_pointer_cast<CCaseLabelList>(shared_from_this()));

		return true;
	}

	bool CCaseStatement::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitCaseStatement(std::static_pointer_cast<CCaseStatement>(shared_from_this()));

		return true;
	}

	bool CCaseStatementList::VisitNodes(class IVisitor* visitor)
	{
		visitor->VisitCaseStatementList(std::static_pointer_cast<CCaseStatementList>(shared_from_this()));

		return true;
	}
}
