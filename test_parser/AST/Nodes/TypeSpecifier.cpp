#include "AST/Nodes/TypeSpecifier.h"
#include "AST/Nodes/PrecisionType.h"

namespace AST
{
	CTypeSpecifier::CTypeSpecifier(TString name)
		: m_TypeName(name)
		, m_TextureMSNumSamples(1)
		, m_PatchSize(0)
		, m_IsArray(false)
		, m_IsUnSizedArray(false)
		, m_Precision(EPrecision::None)
	{}

	CTypeSpecifier::CTypeSpecifier(TString name, TString innerTypeName)
		: m_TypeName(name)
		, m_InnerTypeName(innerTypeName)
		, m_TextureMSNumSamples(1)
		, m_PatchSize(0)
		, m_IsArray(false)
		, m_IsUnSizedArray(false)
	{}

	CTypeSpecifier::CTypeSpecifier(TString name, const CPrecisionType* innerTypeName)
		: m_TypeName(name)
		, m_InnerTypeName(innerTypeName->GetName())
		, m_TextureMSNumSamples(1)
		, m_PatchSize(0)
		, m_IsArray(false)
		, m_IsUnSizedArray(false)
		, m_Precision(innerTypeName->GetPrecision())
	{}

	CTypeSpecifier::CTypeSpecifier(const CPrecisionType* innerTypeName)
		: m_TypeName(innerTypeName->GetName())
		, m_InnerTypeName(innerTypeName->GetName())
		, m_TextureMSNumSamples(1)
		, m_PatchSize(0)
		, m_IsArray(false)
		, m_IsUnSizedArray(false)
		, m_Precision(innerTypeName->GetPrecision())
	{}

	CTypeSpecifier::CTypeSpecifier(CStructSpecifier::TPointer structure)
		: m_TypeName(structure->GetName())
		, m_TextureMSNumSamples(1)
		, m_PatchSize(0)
		, m_IsArray(false)
		, m_IsUnSizedArray(false)
		, m_Structure(structure)
		, m_Precision(EPrecision::None)
	{}

}
