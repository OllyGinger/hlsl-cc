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

		CFunction(TString identifier, CFullySpecifiedType::TPointer returnType)
			: m_Identifier(identifier)
			, m_ReturnType(returnType)
		{}

		inline void AddParameter(CNode::TPointer param)
		{
			m_Parameters.push_back(param);
		}

	private:
		TString m_Identifier;
		TString m_ReturnSemantic;
		CFullySpecifiedType::TPointer m_ReturnType;

		TSubNodeList m_Parameters;
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
