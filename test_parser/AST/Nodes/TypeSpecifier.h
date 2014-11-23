#pragma once
#include "AST/Nodes/Node.h"
#include "AST/Nodes/StructSpecifier.h"
#include "AST/Nodes/Expression.h"

namespace AST
{
	class CExpression;

	class CTypeSpecifier : public CNode
	{
	public:
		
		typedef std::shared_ptr<CTypeSpecifier> TPointer;
		CTypeSpecifier(TString name)
			: m_TypeName(name)
			, m_TextureMSNumSamples(1)
			, m_PatchSize(0)
			, m_IsArray(false)
			, m_IsUnSizedArray(false)
		{}

		CTypeSpecifier(TString name, TString innerTypeName)
			: m_TypeName(name)
			, m_InnerTypeName(innerTypeName)
			, m_TextureMSNumSamples(1)
			, m_PatchSize(0)
			, m_IsArray(false)
			, m_IsUnSizedArray(false)
		{}

		CTypeSpecifier(CStructSpecifier::TPointer structure)
			: m_TypeName(structure->GetName())
			, m_TextureMSNumSamples(1)
			, m_PatchSize(0)
			, m_IsArray(false)
			, m_IsUnSizedArray(false)
			, m_Structure(structure)
		{}

	private:
		TString m_TypeName;
		TString m_InnerTypeName;
		CStructSpecifier::TPointer m_Structure;

		int32_t m_TextureMSNumSamples;
		int32_t m_PatchSize;
		bool m_IsArray;
		bool m_IsUnSizedArray;
		CExpression* m_ArraySize;
	};


	struct TTypeQualifier
	{
		TTypeQualifier()
		{
			Flags.i = 0;
			Location = 0;
		}

		union
		{
			struct  
			{
				unsigned IsStatic : 1;
				unsigned Invariant : 1;
				unsigned Constant : 1;
				unsigned Attribute : 1;
				unsigned Varying : 1;
				unsigned In : 1;
				unsigned Out : 1;
				unsigned Centroid : 1;
				unsigned Uniform : 1;
				unsigned Smooth : 1;
				unsigned Flat : 1;
				unsigned NoPerspective : 1;
				unsigned RowMajor : 1;
				unsigned ColumnMajor : 1;
				unsigned Coherent : 1;
				unsigned Shared : 1;

				unsigned OriginUpperLeft : 1;
				unsigned PixelCenterInteger : 1;

				unsigned ExplicitLocation : 1;

				unsigned DepthAny : 1;
				unsigned DepthGreater : 1;
				unsigned DepthLess : 1;
				unsigned DepthUnchanged : 1;

				unsigned Point : 1;
				unsigned Line : 1;
				unsigned LineAdj : 1;
				unsigned Triangle : 1;
				unsigned TriangleAdj : 1;
			} q;

			unsigned i;
		} Flags;

		uint32_t Location;
	};


	class CFullySpecifiedType : public CNode
	{
	public:
		typedef std::shared_ptr<CFullySpecifiedType> TPointer;

	private:
		CTypeSpecifier::TPointer m_Specifier;
		TTypeQualifier m_Qualifier;
	};

}