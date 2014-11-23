#pragma once
#include "AST/Nodes/Node.h"

namespace AST
{
	class CStructSpecifier : public CNode
	{
	public:
		typedef std::shared_ptr<CStructSpecifier> TPointer;
		CStructSpecifier(TString identifier, CNode::TPointer decleratorList)
			: m_Name(identifier)
			, m_DecleratorList(decleratorList)
		{}

		CStructSpecifier(TString identifier, TString parent, CNode::TPointer decleratorList)
			: m_Name(identifier)
			, m_ParentName(parent)
			, m_DecleratorList(decleratorList)
		{}

		TString GetName() const { return m_Name; }
		TString GetParentName() const  { return m_ParentName; }

	private:
		TString m_Name;
		TString m_ParentName;
		CNode::TPointer m_DecleratorList;
	};

	class CCBufferSpecifier : public CNode
	{
	public:
		typedef std::shared_ptr<CCBufferSpecifier> TPointer;
		CCBufferSpecifier(TString identifier, CNode::TPointer decleratorList)
			: m_Name(identifier)
			, m_DecleratorList(decleratorList)
		{}

		TString GetName() const { return m_Name; }
	private:
		TString m_Name;
		CNode::TPointer m_DecleratorList;
	};
}