#pragma once
#include "AST/Nodes/Node.h"
#include "AST/Nodes/Expression.h"

namespace AST
{
	class CFlowControlStatement : public CNode
	{
	public:
		typedef std::shared_ptr<CFlowControlStatement> TPointer;

		struct EType
		{
			enum Enum
			{
				Continue,
				Break,
				Return,
				Discard
			};
		};

		CFlowControlStatement(EType::Enum type)
			: m_Type(type)
		{}

		CFlowControlStatement(EType::Enum type, CExpression::TPointer returnExpression)
			: m_Type(EType::Return)
			, m_ReturnExpression(returnExpression)
		{}

	private:
		EType::Enum m_Type;
		CExpression::TPointer m_ReturnExpression;
	};
}
