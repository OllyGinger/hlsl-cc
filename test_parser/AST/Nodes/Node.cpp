#include "AST/Nodes/Node.h"
#include "parser.hpp"

namespace AST
{
	CNode::CNode() {}

	CSourceLocation CNode::GetSourceLocation() const
	{
		return m_SourceLocation;
	}

	void CNode::SetSourceLocation(const char *pSourceFile, uint32_t line, uint32_t column)
	{
		m_SourceLocation.SourceFile = std::string(pSourceFile);
		m_SourceLocation.Line = line;
		m_SourceLocation.Column = column;
	}

	void CNode::SetSourceLocation(const struct YYLTYPE &location)
	{
		//m_SourceLocation.SourceFile = location.
		m_SourceLocation.Line = location.first_line;
		m_SourceLocation.Column = location.first_column;
	}

	void CNode::AddLink(CNode::TPointer node)
	{
		m_Links.push_back(node);
	}


	void CNode::AddSelfLink()
	{
		AddLink(shared_from_this());
	}

	void CNode::AddAttribute(CNode::TPointer node)
	{
		m_Attributes.push_back(node);
	}

	bool CNode::VisitNodes(class IVisitor* visitor)
	{
		for (auto link : m_Links)
		{
			link->VisitNodes(visitor);
		}

		return true;
	}
}

