#pragma once
#include "AST/Nodes/Node.h"
#include "AST/Nodes/Expression.h"

namespace AST
{
	class CAttribute : public CNode
	{
	public:
		typedef std::shared_ptr<CAttribute> TPointer;
		CAttribute(TString name)
			: m_Name(name)
		{}

		TString GetName() const { return m_Name; }

	private:
		TString m_Name;
	};


	class CAttributeArgument : public CNode
	{
	public:
		typedef std::shared_ptr<CAttributeArgument> TPointer;
		CAttributeArgument(TString argument)
			: m_IsString(true)
			, m_StringArgument(argument)
		{}

		CAttributeArgument(CExpression::TPointer argument)
			: m_IsString(false)
			, m_ExpressionArgument(argument)
		{}

	private:
		TString m_StringArgument;
		CExpression::TPointer m_ExpressionArgument;
		bool m_IsString;
	};
}
