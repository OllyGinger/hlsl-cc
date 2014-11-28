#pragma once
#include "AST/Nodes/Node.h"
#include "AST/Nodes/Expression.h"

namespace AST
{
	class CIterationStatement : public CNode
	{
	public:
		typedef std::shared_ptr<CIterationStatement> TPointer;

		struct EType
		{
			enum Enum
			{
				For,
				While,
				DoWhile,
			};
		};

		CIterationStatement(EType::Enum type, CNode::TPointer init, CNode::TPointer cond, CExpression::TPointer rest, CNode::TPointer body)
			: m_Type(type), m_InitStatement(init), m_ConditionStatement(cond), m_RestExpression(rest), m_Body(body)
		{}

		virtual bool VisitNodes(class IVisitor* visitor) override;

	private:
		EType::Enum m_Type;
		CNode::TPointer m_InitStatement;
		CNode::TPointer m_ConditionStatement;
		CExpression::TPointer m_RestExpression;

		CNode::TPointer m_Body;
	};
}
