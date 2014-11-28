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

		CExpression::TPointer GetCondition() const { return m_Condition; }
		void SetCondition(CExpression::TPointer val) { m_Condition = val; }

		CNode::TPointer GetThen() const { return m_Then; }
		void SetThen(CNode::TPointer val) { m_Then = val; }

		CNode::TPointer GetElse() const { return m_Else; }
		void SetElse(CNode::TPointer val) { m_Else = val; }

		virtual bool VisitNodes(class IVisitor* visitor) override;

	private:
		CExpression::TPointer m_Condition;
		CNode::TPointer m_Then;
		CNode::TPointer m_Else;
	};
}
