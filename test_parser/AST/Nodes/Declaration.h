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
		void SetArraySize(CExpression::TPointer arraySize) { m_ArraySize = arraySize; }
		CExpression::TPointer GetInitialiser() const { return m_Initialiser; }
		void SetInitialiser(CExpression::TPointer val) { m_Initialiser = val; }
		void SetSemantec(TString semantec) { m_Semantic = semantec; }
		bool IsArray() const { return m_IsArray; }
		virtual bool VisitNodes(class IVisitor* visitor) override;

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
		inline bool GetInvariant() const { return m_Invariant; }
		inline void SetInvariant(bool val) { m_Invariant = val; }

		inline CFullySpecifiedType::TPointer GetType() const { return m_Type; }
		inline TSubNodeList& GetDeclerations() { return m_Declerations; }

		virtual bool VisitNodes(class IVisitor* visitor) override;

	private:
		CFullySpecifiedType::TPointer m_Type;
		TSubNodeList m_Declerations;
		bool m_Invariant;
	};
}
