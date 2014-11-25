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
			m_ArraySize(arraySizeExpression), 
			m_Initialiser(initialiser)
		{}

		TString GetIdentifier() const { return m_Identifier; }
		CExpression::TPointer GetArraySize() const { return m_ArraySize; }
		CExpression::TPointer GetInitialiser() const { return m_Initialiser; }
		void SetInitialiser(CExpression::TPointer val) { m_Initialiser = val; }

	private:
		TString m_Identifier;
		TString m_Semantic;

		bool m_IsArray;
		bool m_IsUnsizedArray;
		CExpression::TPointer m_ArraySize;
		CExpression::TPointer m_Initialiser;
		
	};


	class CDecleratorList : public CNode
	{
	public:
		typedef std::shared_ptr<CDecleratorList> TPointer;

		CDecleratorList(CFullySpecifiedType::TPointer type)
			: m_Type(type)
		{}

		inline void AddDecleration(CNode::TPointer param)	{ m_Declerations.push_back(param); }
		bool GetInvariant() const { return m_Invariant; }
		void SetInvariant(bool val) { m_Invariant = val; }

	private:
		CFullySpecifiedType::TPointer m_Type;
		TSubNodeList m_Declerations;
		bool m_Invariant;
	};
}
