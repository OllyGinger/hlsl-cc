#pragma once
#include "AST/Nodes/Node.h"
#include "AST/Nodes/StructSpecifier.h"
#include "AST/Nodes/Precision.h"

namespace AST
{
	class CExpression;
	class CPrecisionType;

	class CTypeSpecifier : public CNode
	{
	public:
		typedef std::shared_ptr<CTypeSpecifier> TPointer;
		CTypeSpecifier::CTypeSpecifier(TString name);
		CTypeSpecifier::CTypeSpecifier(TString name, TString innerTypeName);
		CTypeSpecifier::CTypeSpecifier(TString name, const CPrecisionType* innerTypeName);
		CTypeSpecifier::CTypeSpecifier(const CPrecisionType* innerTypeName);
		CTypeSpecifier::CTypeSpecifier(CStructSpecifier::TPointer structure);

		bool GetIsArray() const { return m_IsArray; }
		void SetIsArray(bool val) { m_IsArray = val; }

		bool GetIsUnSizedArray() const { return m_IsUnSizedArray; }
		void SetIsUnSizedArray(bool val) { m_IsUnSizedArray = val; }

		CExpression* GetArraySize() const { return m_ArraySize; }
		void SetArraySize(CExpression* val) { m_ArraySize = val; }

		int32_t GetTextureMSNumSamples() const { return m_TextureMSNumSamples; }
		void SetTextureMSNumSamples(int32_t val) { m_TextureMSNumSamples = val; }

		int32_t GetPatchSize() const { return m_PatchSize; }
		void SetPatchSize(int32_t val) { m_PatchSize = val; }

		TString GetTypeName() const { return m_TypeName; }
		void SetTypeName(TString val) { m_TypeName = val; }

		CStructSpecifier::TPointer GetStructure() const { return m_Structure; }

		virtual bool VisitNodes(class IVisitor* visitor) override;

	private:
		TString m_TypeName;
		
		TString m_InnerTypeName;
		CStructSpecifier::TPointer m_Structure;

		int32_t m_TextureMSNumSamples;
		
		int32_t m_PatchSize;
		
		bool m_IsArray;
		bool m_IsUnSizedArray;
		
		CExpression* m_ArraySize;
		EPrecision::Enum m_Precision;
	};


	struct TTypeQualifier
	{
		TTypeQualifier()
		{
			Reset();
		}

		inline void Reset()
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
		CFullySpecifiedType(CTypeSpecifier::TPointer specifier)
			: m_Specifier(specifier)
		{}

		CFullySpecifiedType(TTypeQualifier qualifier, CTypeSpecifier::TPointer specifier)
			: m_Specifier(specifier)
			, m_Qualifier(qualifier)
		{}

		inline CTypeSpecifier::TPointer GetTypeSpecifier() const { return m_Specifier; }
		inline void SetQualifier(TTypeQualifier &qualifier) { m_Qualifier = qualifier; }
		virtual bool VisitNodes(class IVisitor* visitor) override;

	private:
		CTypeSpecifier::TPointer m_Specifier;
		TTypeQualifier m_Qualifier;
	};

}