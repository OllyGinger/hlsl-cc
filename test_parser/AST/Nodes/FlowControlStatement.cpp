#include "AST/Nodes/FlowControlStatement.h"
#include "AST/Visitor/Visitor.h"

namespace AST
{
	bool CFlowControlStatement::VisitNodes(class IVisitor* visitor)
	{
		return visitor->VisitFlowControlStatement(std::static_pointer_cast<CFlowControlStatement>(shared_from_this()));
	}
}
