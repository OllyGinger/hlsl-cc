#pragma once
#include "AST/Nodes/Node.h"
#include "AST/Nodes/Expression.h"
#include "AST/Nodes/TypeSpecifier.h"

namespace AST
{
	class CParameterDeclerator : public CNode
	{
	public:
		typedef std::shared_ptr<CParameterDeclerator> TPointer;

		CParameterDeclerator()
			: m_IsArray(false)
			, m_IsVoid(false)
			, m_IsFormal(false)
		{}

		CFullySpecifiedType::TPointer GetType() const { return m_Type; }
		void SetType(CFullySpecifiedType::TPointer val) { m_Type = val; }

		AST::TString GetIdentifier() const { return m_Identifier; }
		void SetIdentifier(AST::TString val) { m_Identifier = val; }

		AST::TString GetSemantic() const { return m_Semantic; }
		void SetSemantic(AST::TString val) { m_Semantic = val; }

		bool GetIsArray() const { return m_IsArray; }
		void SetIsArray(bool val) { m_IsArray = val; }

		CExpression::TPointer GetArraySize() const { return m_ArraySize; }
		void SetArraySize(CExpression::TPointer val) { m_ArraySize = val; }

		CExpression::TPointer GetDefaultValue() const { return m_DefaultValue; }
		void SetDefaultValue(CExpression::TPointer val) { m_DefaultValue = val; }

		bool GetIsVoid() const { return m_IsVoid; }
		void SetIsVoid(bool val) { m_IsVoid = val; }

		bool GetIsFormal() const { return m_IsFormal; }
		void SetIsFormal(bool val) { m_IsFormal = val; }

	private:
		CFullySpecifiedType::TPointer m_Type;
		TString m_Identifier;
		TString m_Semantic;
		bool m_IsArray;
		CExpression::TPointer m_ArraySize;
		CExpression::TPointer m_DefaultValue;
		bool m_IsVoid;
		bool m_IsFormal;
	};
}
