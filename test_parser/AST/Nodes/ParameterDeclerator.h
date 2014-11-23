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
