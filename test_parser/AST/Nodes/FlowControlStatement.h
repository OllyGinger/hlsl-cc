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
				Discard,

				Noof,
			};

			static const char* const ToString(Enum op)
			{
				static const char* const types[] =
				{
					"continue",
					"break",
					"return",
					"discard",
				};

				static_assert(sizeof(types) / sizeof(types[0]) == Enum::Noof,
					"Number of strings doesn't match number of enumerations");
				return types[op];
			}
		};

		CFlowControlStatement(EType::Enum type)
			: m_Type(type)
		{}

		CFlowControlStatement(EType::Enum type, CExpression::TPointer returnExpression)
			: m_Type(EType::Return)
			, m_ReturnExpression(returnExpression)
		{}

		inline EType::Enum GetType() const { return m_Type; }
		inline CExpression::TPointer GetExpression() const { return m_ReturnExpression; }
		virtual bool VisitNodes(class IVisitor* visitor) override;

	private:
		EType::Enum m_Type;
		CExpression::TPointer m_ReturnExpression;
	};
}
