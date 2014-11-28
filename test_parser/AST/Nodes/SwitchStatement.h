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

		virtual bool VisitNodes(class IVisitor* visitor) override;

	private:
		CExpression::TPointer m_Test;
		CNode::TPointer m_Body;
	};


	class CSwitchBody : public CNode
	{
	public:
		typedef std::shared_ptr<CSwitchBody> TPointer;

		virtual bool VisitNodes(class IVisitor* visitor) override;
	};


	class CCaseLabel : public CNode
	{
	public:
		typedef std::shared_ptr<CCaseLabel> TPointer;

		virtual bool VisitNodes(class IVisitor* visitor) override;
	};


	class CCaseLabelList : public CNode
	{
	public:
		typedef std::shared_ptr<CCaseLabelList> TPointer;

		virtual bool VisitNodes(class IVisitor* visitor) override;
	};


	class CCaseStatement : public CNode
	{
	public:
		typedef std::shared_ptr<CCaseStatement> TPointer;

		virtual bool VisitNodes(class IVisitor* visitor) override;
	};


	class CCaseStatementList : public CNode
	{
	public:
		typedef std::shared_ptr<CCaseStatementList> TPointer;

		virtual bool VisitNodes(class IVisitor* visitor) override;
	};
}
