#pragma once
#include "AST/Nodes/Node.h"

namespace AST
{
	class CCompoundStatement : public CNode
	{
	public:
		typedef std::shared_ptr<CCompoundStatement> TPointer;

		CCompoundStatement(int32_t scope, CNode::TPointer statements)
			: m_Statements(statements)
			, m_Scope(scope)
		{}

	private:
		CNode::TPointer m_Statements;
		int32_t m_Scope;
	};
}
