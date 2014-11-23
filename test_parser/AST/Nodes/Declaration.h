#pragma once
#include "AST/Nodes/Node.h"
#include "AST/Nodes/Expression.h"

namespace AST
{
	class CDecleration : public CNode
	{
	public:
		typedef std::shared_ptr<CDecleration> TPointer;

		CDecleration(TString identifier, bool isArray, CExpression::TPointer arraySizeExpression, CExpression::TPointer initialiser)
			: m_Identifier(identifier), 
			m_IsArray(isArray), 
			m_IsUnsizedArray(false), 
			m_ArraySizeExp(arraySizeExpression), 
			m_Initialiser(initialiser)
		{}

	private:
		TString m_Identifier;
		TString m_Semantic;

		bool m_IsArray;
		bool m_IsUnsizedArray;
		CExpression::TPointer m_ArraySizeExp;
		CExpression::TPointer m_Initialiser;
	};


	class CDecleratorList : public CNode
	{
	public:
		typedef std::shared_ptr<CDecleratorList> TPointer;

		CDecleratorList(CFullySpecifiedType::TPointer type)
			: m_Type(type)
		{}

	private:
		CFullySpecifiedType::TPointer m_Type;
	};
}
