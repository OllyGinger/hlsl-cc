#include "AST/Nodes/Declaration.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CSwitchStatement::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitSwitchStatement(std::static_pointer_cast<CSwitchStatement>(shared_from_this()));
	}

	bool CSwitchBody::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitSwitchBody(std::static_pointer_cast<CSwitchBody>(shared_from_this()));
	}

	bool CCaseLabel::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitCaseLabel(std::static_pointer_cast<CCaseLabel>(shared_from_this()));
	}

	bool CCaseLabelList::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitCaseLabelList(std::static_pointer_cast<CCaseLabelList>(shared_from_this()));
	}

	bool CCaseStatement::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitCaseStatement(std::static_pointer_cast<CCaseStatement>(shared_from_this()));
	}

	bool CCaseStatementList::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitCaseStatementList(std::static_pointer_cast<CCaseStatementList>(shared_from_this()));
	}
}
