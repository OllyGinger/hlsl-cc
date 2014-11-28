#pragma once
#include "AST/Nodes/Node.h"

namespace AST
{
	class CCompoundStatement : public CNode
	{
	public:
		typedef std::shared_ptr<CCompoundStatement> TPointer;

		CCompoundStatement(bool newScope, CNode::TPointer statements)
			: m_Statements(statements)
			, m_Scope(newScope)
		{}

		virtual bool VisitNodes(class IVisitor* visitor) override;

	private:
		CNode::TPointer m_Statements;
		bool m_Scope;
	};
}
