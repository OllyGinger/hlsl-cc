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

		const char* const ToString(Enum op) const
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

				"()",
				"{}",

				"ident",
				"int",
				"uint",
				"float",
				"bool",

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
		CExpression(EOperator::Enum op, CExpression::TPointer exp1, CExpression::TPointer exp2, CExpression::TPointer exp3);

	private:
		typedef std::array<CExpression::TPointer, 3> TSubExpressionList;

		TSubExpressionList m_SubExpressions;
		TString m_Identifier;
		CTypeSpecifier::TPointer m_TypeSpecifier;

		union
		{
			int32_t IntConstant;
			uint32_t UIntConstant;
			float FloatConstant;
			bool BoolConstant;
		} m_Expression;
	};


	class CBineryExpression : public CExpression
	{
	public:
		typedef std::shared_ptr<CBineryExpression> TPointer;
		CBineryExpression(EOperator::Enum op, CExpression::TPointer exprA, CExpression::TPointer exprB)
			: CExpression(op, exprA, exprB, CExpression::TPointer())
		{}
	};

	
	class CFunctionExpression : public CExpression
	{
	public:
		typedef std::shared_ptr<CBineryExpression> TPointer;
		CFunctionExpression(CExpression::TPointer callee)
			: CExpression(EOperator::FunctionCall, callee, CExpression::TPointer(), CExpression::TPointer())
			, m_IsConstructor(false)
		{}

		/*CFunctionExpression(CTypeSpecifier::TPointer type)
			: CExpression(EOperator::FunctionCall, type, CExpression::TPointer(), CExpression::TPointer())
			, m_IsConstructor(true)
		{}*/

		bool IsConstructor() const { return m_IsConstructor; }

	private:
		bool m_IsConstructor;
	};


	class CInitialiserListExpression : public CExpression
	{
	public:
		typedef std::shared_ptr<CBineryExpression> TPointer;
		CInitialiserListExpression()
			: CExpression(EOperator::InitializerList, CExpression::TPointer(), CExpression::TPointer(), CExpression::TPointer())
		{}
	};
}