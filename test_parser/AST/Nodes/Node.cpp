#include "AST/Nodes/Node.h"

namespace AST
{

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


}

