#pragma once
#include "AST/Nodes/Node.h"
#include "AST/Nodes/Expression.h"
#include "AST/Nodes/Precision.h"

namespace AST
{
	class CPrecisionType : public CNode
	{
	public:
		typedef std::shared_ptr<CPrecisionType> TPointer;

		CPrecisionType(TString name, EPrecision::Enum precision = EPrecision::None)
			: m_Name(name)
			, m_Precision(precision)
		{}

		inline TString GetName() const { return m_Name; }
		inline EPrecision::Enum GetPrecision() const { return m_Precision; }

		static const CPrecisionType Void;
		static const CPrecisionType Float;
		static const CPrecisionType Half;
		static const CPrecisionType Fixed;
		static const CPrecisionType Int;
		static const CPrecisionType UInt;
		static const CPrecisionType Bool;
		static const CPrecisionType Float2;
		static const CPrecisionType Float3;
		static const CPrecisionType Float4;
		static const CPrecisionType Half2;
		static const CPrecisionType Half3;
		static const CPrecisionType Half4;
		static const CPrecisionType Fixed2;
		static const CPrecisionType Fixed3;
		static const CPrecisionType Fixed4;
		static const CPrecisionType Bool2;
		static const CPrecisionType Bool3;
		static const CPrecisionType Bool4;
		static const CPrecisionType Int2;
		static const CPrecisionType Int3;
		static const CPrecisionType Int4;
		static const CPrecisionType UInt2;
		static const CPrecisionType UInt3;
		static const CPrecisionType UInt4;
		static const CPrecisionType Float2x2;
		static const CPrecisionType Float2x3;
		static const CPrecisionType Float2x4;
		static const CPrecisionType Float3x2;
		static const CPrecisionType Float3x3;
		static const CPrecisionType Float3x4;
		static const CPrecisionType Float4x2;
		static const CPrecisionType Float4x3;
		static const CPrecisionType Float4x4;
		static const CPrecisionType Half2x2;
		static const CPrecisionType Half2x3;
		static const CPrecisionType Half2x4;
		static const CPrecisionType Half3x2;
		static const CPrecisionType Half3x3;
		static const CPrecisionType Half3x4;
		static const CPrecisionType Half4x2;
		static const CPrecisionType Half4x3;
		static const CPrecisionType Half4x4;
		static const CPrecisionType Fixed2x2;
		static const CPrecisionType Fixed2x3;
		static const CPrecisionType Fixed2x4;
		static const CPrecisionType Fixed3x2;
		static const CPrecisionType Fixed3x3;
		static const CPrecisionType Fixed3x4;
		static const CPrecisionType Fixed4x2;
		static const CPrecisionType Fixed4x3;
		static const CPrecisionType Fixed4x4;
		static const CPrecisionType SamplerState;
		static const CPrecisionType SamplerComparisonState;

	private:
		TString m_Name;
		EPrecision::Enum m_Precision;
	};
}