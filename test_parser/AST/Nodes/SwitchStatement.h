#pragma once
#include "AST/Nodes/Node.h"
#include "AST/Nodes/Expression.h"

namespace AST
{
	class CSwitchStatement : public CNode
	{
	public:
		typedef std::shared_ptr<CSwitchStatement> TPointer;

		CSwitchStatement(CExpression::TPointer test, CNode::TPointer body)
			: m_Test(test)
			, m_Body(body)
		{}

	private:
		CExpression::TPointer m_Test;
		CNode::TPointer m_Body;
	};


	class CSwitchBody : public CNode
	{
	public:
		typedef std::shared_ptr<CSwitchStatement> TPointer;
	};


	class CCaseLabel : public CNode
	{
	public:
		typedef std::shared_ptr<CCaseLabel> TPointer;
	};


	class CCaseLabelList : public CNode
	{
	public:
		typedef std::shared_ptr<CCaseLabelList> TPointer;
	};


	class CCaseStatement : public CNode
	{
	public:
		typedef std::shared_ptr<CCaseStatement> TPointer;
	};


	class CCaseStatementList : public CNode
	{
	public:
		typedef std::shared_ptr<CCaseStatementList> TPointer;
	};
}
