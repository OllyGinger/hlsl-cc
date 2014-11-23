#pragma once
#include "AST/Nodes/Node.h"

namespace AST
{
	class CStructSpecifier : public CNode
	{
	public:
		typedef std::shared_ptr<CStructSpecifier> TPointer;
		CStructSpecifier(TString identifier)
			: m_Name(identifier)
		{}

		CStructSpecifier(TString identifier, TString parent)
			: m_Name(identifier)
			, m_ParentName(parent)
		{}

		TString GetName() const { return m_Name; }
		TString GetParentName() const  { return m_ParentName; }
	private:
		TString m_Name;
		TString m_ParentName;
	};
}