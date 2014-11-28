#pragma once
#include "AST/Nodes/Node.h"

namespace AST
{
	class CCompoundStatement : public CNode
	{
	public:
		typedef std::shared_ptr<CCompoundStatement> TPointer;
		typedef std::list<CNode::TPointer> TStatementList;

		CCompoundStatement(bool newScope, CNode::TPointer initialStatement)
			: m_Scope(newScope)
		{
			m_Statements.push_back(initialStatement);
		}

		CCompoundStatement(bool newScope, TStatementList&& statements)
			: m_Statements(std::move(statements))
			, m_Scope(newScope)
		{}

		CCompoundStatement(bool newScope)
			: m_Scope(newScope)
		{}

		inline TStatementList& GetStatementList() { return m_Statements; }
		virtual bool VisitNodes(class IVisitor* visitor) override;

	private:
		TStatementList m_Statements;
		bool m_Scope;
	};
}
