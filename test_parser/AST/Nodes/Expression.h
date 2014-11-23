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

		inline void MakeIdentifier(TString identifier) 
		{ 
			m_Operator = EOperator::Identifier;  
			m_Identifier = identifier; 
		}

		inline void MakeIntConstant(int32_t constant)
		{
			m_Operator = EOperator::IntConstant;
			m_Expression.IntConstant = constant;
		}

		inline void MakeUIntConstant(int32_t constant)
		{
			m_Operator = EOperator::UIntConstant;
			m_Expression.UIntConstant = constant;
		}

		inline void MakeFloatConstant(float constant)
		{
			m_Operator = EOperator::FloatConstant;
			m_Expression.FloatConstant = constant;
		}

		inline void MakeBoolConstant(bool constant)
		{
			m_Operator = EOperator::BoolConstant;
			m_Expression.BoolConstant = constant;
		}

		inline void SetIdentifier(TString identifier)
		{
			m_Identifier = identifier;
		}

	private:
		typedef std::array<CExpression::TPointer, 3> TSubExpressionList;

		TSubExpressionList m_SubExpressions;
		TString m_Identifier;
		CTypeSpecifier::TPointer m_TypeSpecifier;
		EOperator::Enum m_Operator;

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