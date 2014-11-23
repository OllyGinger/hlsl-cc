#pragma once
#include "AST/AST.h"

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

	class CNode
	{
	public:
		typedef std::shared_ptr<CNode> TPointer;

		inline CSourceLocation GetSourceLocation() const;
		inline void SetSourceLocation(const char *pSourceFile, uint32_t line, uint32_t column);

	protected:
		// Don't allow instantiations of the base class
		CNode();

	private:
		CSourceLocation m_SourceLocation;
	};

}