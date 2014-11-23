#pragma once
#include "AST/Nodes/Node.h"
#include "AST/Nodes/Expression.h"

namespace AST
{
	class CSelectionStatement : public CNode
	{
	public:
		typedef std::shared_ptr<CSelectionStatement> TPointer;

		CSelectionStatement(CExpression::TPointer condition, CNode::TPointer then, CNode::TPointer els)
			: m_Condition(condition)
			, m_Then(then)
			, m_Else(els)
		{}

	private:
		CExpression::TPointer m_Condition;
		CNode::TPointer m_Then;
		CNode::TPointer m_Else;
	};
}
