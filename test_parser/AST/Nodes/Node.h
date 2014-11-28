#pragma once
#include "AST/AST.h"
#include <list>

namespace AST
{
	struct CSourceLocation
	{
		CSourceLocation()
		: SourceFile("<Unknown>")
		, Line(0)
		, Column(0)
		{}

		TString SourceFile;
		uint32_t Line;
		uint32_t Column;
	};

	class IVisitor;

	class CNode : public std::enable_shared_from_this<CNode>
	{
	public:
		typedef std::shared_ptr<CNode> TPointer;
		typedef std::list<TPointer> TSubNodeList;

		virtual bool VisitNodes(class IVisitor* visitor);

		CSourceLocation GetSourceLocation() const;
		void SetSourceLocation(const char *pSourceFile, uint32_t line, uint32_t column);
		void SetSourceLocation(const struct YYLTYPE &location);

		void AddLink(CNode::TPointer node);
		void AddSelfLink();
		void AddAttribute(CNode::TPointer node);

	protected:
		// Don't allow instantiations of the base class
		CNode();

	protected:
		CSourceLocation m_SourceLocation;
		TSubNodeList m_Links;
		TSubNodeList m_Attributes;
	};

}