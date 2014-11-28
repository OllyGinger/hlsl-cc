#include "AST/Nodes/TypeSpecifier.h"
#include "AST/Nodes/PrecisionType.h"
#include "AST/Visitor/Visitor.h"

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
		, m_ArraySize(nullptr)
	{}

	CTypeSpecifier::CTypeSpecifier(TString name, const CPrecisionType* innerTypeName)
		: m_TypeName(name)
		, m_InnerTypeName(innerTypeName->GetName())
		, m_TextureMSNumSamples(1)
		, m_PatchSize(0)
		, m_IsArray(false)
		, m_IsUnSizedArray(false)
		, m_Precision(innerTypeName->GetPrecision())
		, m_ArraySize(nullptr)
	{}

	CTypeSpecifier::CTypeSpecifier(const CPrecisionType* innerTypeName)
		: m_TypeName(innerTypeName->GetName())
		, m_InnerTypeName(innerTypeName->GetName())
		, m_TextureMSNumSamples(1)
		, m_PatchSize(0)
		, m_IsArray(false)
		, m_IsUnSizedArray(false)
		, m_Precision(innerTypeName->GetPrecision())
		, m_ArraySize(nullptr)
	{}

	CTypeSpecifier::CTypeSpecifier(CStructSpecifier::TPointer structure)
		: m_TypeName(structure->GetName())
		, m_TextureMSNumSamples(1)
		, m_PatchSize(0)
		, m_IsArray(false)
		, m_IsUnSizedArray(false)
		, m_Structure(structure)
		, m_Precision(EPrecision::None)
		, m_ArraySize(nullptr)
	{}

	bool CTypeSpecifier::VisitNodes(IVisitor* visitor)
	{
		return visitor->VisitTypeSpecifier(std::static_pointer_cast<CTypeSpecifier>(shared_from_this()));
	}

	bool CFullySpecifiedType::VisitNodes(IVisitor* visitor)
	{
		return visitor->VisitFullySpecifiedType(std::static_pointer_cast<CFullySpecifiedType>(shared_from_this()));
	}
}
