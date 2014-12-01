#pragma once
#include "AST/Nodes/Node.h"
#include "AST/Nodes/TypeSpecifier.h"

namespace AST
{
	struct EOperator
	{
		enum Enum
		{
			Assign,
			Plus,
			Negative,
			Add,
			Subtract,
			Multiply,
			Divide,
			Modulo,
			LeftShift,
			RightShift,
			LessThan,
			GreaterThan,
			LessOrEqual,
			GreaterOrEqual,
			Equal,
			NotEqual,
			BitwiseAnd,
			BitwiseXOr,
			BitwiseOr,
			BitwiseNot,
			LogicalAnd,
			LogicalXOr,
			LogicalOr,
			LogicalNot,

			MultiplyAssign,
			DivideAssign,
			ModuloAssign,
			AddAssign,
			SubtractAssign,
			LeftShiftAssign,
			RightShiftAssign,
			AndAssign,
			XOrAssign,
			OrAssign,

			Conditional,

			PreIncrement,
			PreDecrement,
			PostIncrement,
			PostDecrement,
			FieldSelection,
			ArrayIndex,

			FunctionCall,
			InitializerList,

			Identifier,
			IntConstant,
			UIntConstant,
			FloatConstant,
			BoolConstant,

			Sequence,

			TypeCast,

			Noof,
		};

		static const char* const ToString(Enum op)
		{
			static const char* const operators[] =
			{
				"=",
				"+",
				"-",
				"+",
				"-",
				"*",
				"/",
				"%",
				"<<",
				">>",
				"<",
				">",
				"<=",
				">=",
				"==",
				"!=",
				"&",
				"^",
				"|",
				"~",
				"&&",
				"^^",
				"||",
				"!",

				"*=",
				"/=",
				"%=",
				"+=",
				"-=",
				"<<=",
				">>=",
				"&=",
				"^=",
				"|=",

				"?:",

				"++",
				"--",
				"++",
				"--",
				".",
				"[]",

				"functionCall",
				"{}",

				"ident",
				"IntConstant",
				"UIntConstant",
				"FloatConstant",
				"BoolConstant",

				"seq",

				"cast"
			};

			static_assert(sizeof(operators) / sizeof(operators[0]) == Enum::Noof,
				"Number of strings doesn't match number of enumerations");
			return operators[op];
		}
	};

	class CExpression : public CNode
	{
	public:
		typedef std::shared_ptr<CExpression> TPointer;
		typedef std::array<CNode::TPointer, 3> TSubExpressionList;

		struct TExpression
		{
			union
			{
				int32_t IntConstant;
				uint32_t UIntConstant;
				float FloatConstant;
				bool BoolConstant;
			} u;
		};
		
		CExpression()
		{}

		CExpression(EOperator::Enum op, CExpression::TPointer exp1, CExpression::TPointer exp2, CExpression::TPointer exp3)
			: m_Operator(op)
		{
			m_SubExpressions[0] = exp1;
			m_SubExpressions[1] = exp2;
			m_SubExpressions[2] = exp3;
		}

		CExpression(EOperator::Enum op, CExpression::TPointer exp1, CExpression::TPointer exp2)
			: m_Operator(op)
		{
			m_SubExpressions[0] = exp1;
			m_SubExpressions[1] = exp2;
		}

		CExpression(EOperator::Enum op, CExpression::TPointer exp1)
			: m_Operator(op)
		{
			m_SubExpressions[0] = exp1;
		}

		CExpression(EOperator::Enum op, CTypeSpecifier::TPointer specifier)
			: m_Operator(op)
		{
			m_SubExpressions[0] = specifier;
		}

		CExpression(EOperator::Enum op)
			: m_Operator(op)
		{
		}

		CExpression(TString identifier)
			: m_Operator(EOperator::Identifier)
			, m_Identifier(identifier)
		{
		}

		inline void MakeIntConstant(int32_t constant)
		{
			m_Operator = EOperator::IntConstant;
			m_Expression.u.IntConstant = constant;
		}

		inline void MakeUIntConstant(int32_t constant)
		{
			m_Operator = EOperator::UIntConstant;
			m_Expression.u.UIntConstant = constant;
		}

		inline void MakeFloatConstant(float constant)
		{
			m_Operator = EOperator::FloatConstant;
			m_Expression.u.FloatConstant = constant;
		}

		inline void MakeBoolConstant(bool constant)
		{
			m_Operator = EOperator::BoolConstant;
			m_Expression.u.BoolConstant = constant;
		}

		inline void SetIdentifier(TString identifier)
		{
			m_Identifier = identifier;
		}

		inline TString GetIdentifier() const
		{
			return m_Identifier;
		}

		inline void SetTypeSpecifier(CTypeSpecifier::TPointer typeSpecifier)
		{
			m_TypeSpecifier = typeSpecifier;
		}

		void AddChildExpression(CNode::TPointer expression)
		{
			m_ChildExpressions.push_back(expression);
		}

		inline EOperator::Enum GetOperator() const { return m_Operator; }
		inline TExpression GetExpression() const { return m_Expression; }
		inline TSubExpressionList& GetSubExpressionList() { return m_SubExpressions; }
		inline TSubNodeList& GetChildExpressionList() { return m_ChildExpressions; }

		virtual bool VisitNodes(class IVisitor* visitor) override;

	private:

		TSubExpressionList m_SubExpressions;
		TString m_Identifier;
		CTypeSpecifier::TPointer m_TypeSpecifier;
		EOperator::Enum m_Operator;
		TSubNodeList m_ChildExpressions;

		TExpression m_Expression;
	};

	class CExpressionStatement : public CNode
	{
	public:
		typedef std::shared_ptr<CExpressionStatement> TPointer;
		CExpressionStatement(CExpression::TPointer expression)
			: m_Expression(expression)
		{}

		virtual bool VisitNodes(class IVisitor* visitor) override;
		CExpression::TPointer GetExpression() const { return m_Expression; }

	private:
		CExpression::TPointer m_Expression;
	};

	class CBinaryExpression : public CExpression
	{
	public:
		typedef std::shared_ptr<CBinaryExpression> TPointer;
		CBinaryExpression(EOperator::Enum op, CExpression::TPointer exprA, CExpression::TPointer exprB)
			: CExpression(op, exprA, exprB)
		{}

		virtual bool VisitNodes(class IVisitor* visitor) override;
	};

	
	class CFunctionExpression : public CExpression
	{
	public:
		typedef std::shared_ptr<CFunctionExpression> TPointer;
		CFunctionExpression(CExpression::TPointer callee)
			: CExpression(EOperator::FunctionCall, callee)
			, m_IsConstructor(false)
		{}

		CFunctionExpression(CTypeSpecifier::TPointer type)
			: CExpression(EOperator::FunctionCall, type)
			, m_IsConstructor(true)
		{}

		bool IsConstructor() const { return m_IsConstructor; }
		virtual bool VisitNodes(class IVisitor* visitor) override;

	private:
		bool m_IsConstructor;
	};


	class CInitialiserListExpression : public CExpression
	{
	public:
		typedef std::shared_ptr<CInitialiserListExpression> TPointer;
		CInitialiserListExpression()
			: CExpression(EOperator::InitializerList, CExpression::TPointer(), CExpression::TPointer(), CExpression::TPointer())
		{}

		virtual bool VisitNodes(class IVisitor* visitor) override;
	};
}