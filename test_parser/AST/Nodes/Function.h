#pragma once
#include "AST/Nodes/Node.h"
#include "AST/Nodes/Expression.h"
#include "AST/Nodes/CompoundStatement.h"

namespace AST
{
	class CFunction : public CNode
	{
	public:
		typedef std::shared_ptr<CFunction> TPointer;

		CFunction(TString identifier)
			: m_Identifier(identifier)
		{}

	private:
		TString m_Identifier;
		TString m_ReturnSemantic;
		TTypeQualifier m_ReturnType;
	};


	class CFunctionDefinition : public CNode
	{
	public:
		typedef std::shared_ptr<CFunctionDefinition> TPointer;

	private:
		CFunction::TPointer m_Prototype;
		CCompoundStatement::TPointer m_Body;
	};
}
