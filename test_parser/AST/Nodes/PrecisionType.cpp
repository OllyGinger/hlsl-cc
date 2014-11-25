#include "AST/Nodes/PrecisionType.h"

namespace AST
{
	const CPrecisionType CPrecisionType::Void("void");
	const CPrecisionType CPrecisionType::Float("float", EPrecision::High);
	const CPrecisionType CPrecisionType::Half("float", EPrecision::Medium);
	const CPrecisionType CPrecisionType::Fixed("float", EPrecision::Low);
	const CPrecisionType CPrecisionType::Int("int");
	const CPrecisionType CPrecisionType::UInt("uint");
	const CPrecisionType CPrecisionType::Bool("bool");
	const CPrecisionType CPrecisionType::Float2("vec2", EPrecision::High);
	const CPrecisionType CPrecisionType::Float3("vec3", EPrecision::High);
	const CPrecisionType CPrecisionType::Float4("vec4", EPrecision::High);
	const CPrecisionType CPrecisionType::Half2("vec2", EPrecision::Medium);
	const CPrecisionType CPrecisionType::Half3("vec3", EPrecision::Medium);
	const CPrecisionType CPrecisionType::Half4("vec4", EPrecision::Medium);
	const CPrecisionType CPrecisionType::Fixed2("vec2", EPrecision::Low);
	const CPrecisionType CPrecisionType::Fixed3("vec3", EPrecision::Low);
	const CPrecisionType CPrecisionType::Fixed4("vec4", EPrecision::Low);
	const CPrecisionType CPrecisionType::Bool2("bvec2");
	const CPrecisionType CPrecisionType::Bool3("bvec3");
	const CPrecisionType CPrecisionType::Bool4("bvec4");
	const CPrecisionType CPrecisionType::Int2("ivec2");
	const CPrecisionType CPrecisionType::Int3("ivec3");
	const CPrecisionType CPrecisionType::Int4("ivec4");
	const CPrecisionType CPrecisionType::UInt2("uvec2");
	const CPrecisionType CPrecisionType::UInt3("uvec3");
	const CPrecisionType CPrecisionType::UInt4("uvec4");
	const CPrecisionType CPrecisionType::Float2x2("mat2", EPrecision::High);
	const CPrecisionType CPrecisionType::Float2x3("mat2x3", EPrecision::High);
	const CPrecisionType CPrecisionType::Float2x4("mat2x4", EPrecision::High);
	const CPrecisionType CPrecisionType::Float3x2("mat3x2", EPrecision::High);
	const CPrecisionType CPrecisionType::Float3x3("mat3", EPrecision::High);
	const CPrecisionType CPrecisionType::Float3x4("mat3x4", EPrecision::High);
	const CPrecisionType CPrecisionType::Float4x2("mat4x2", EPrecision::High);
	const CPrecisionType CPrecisionType::Float4x3("mat4x3", EPrecision::High);
	const CPrecisionType CPrecisionType::Float4x4("mat4", EPrecision::High);
	const CPrecisionType CPrecisionType::Half2x2("mat2", EPrecision::Medium);
	const CPrecisionType CPrecisionType::Half2x3("mat2x3", EPrecision::Medium);
	const CPrecisionType CPrecisionType::Half2x4("mat2x4", EPrecision::Medium);
	const CPrecisionType CPrecisionType::Half3x2("mat3x2", EPrecision::Medium);
	const CPrecisionType CPrecisionType::Half3x3("mat3", EPrecision::Medium);
	const CPrecisionType CPrecisionType::Half3x4("mat3x4", EPrecision::Medium);
	const CPrecisionType CPrecisionType::Half4x2("mat4x2", EPrecision::Medium);
	const CPrecisionType CPrecisionType::Half4x3("mat4x3", EPrecision::Medium);
	const CPrecisionType CPrecisionType::Half4x4("mat4", EPrecision::Medium);
	const CPrecisionType CPrecisionType::Fixed2x2("mat2", EPrecision::Low);
	const CPrecisionType CPrecisionType::Fixed2x3("mat2x3", EPrecision::Low);
	const CPrecisionType CPrecisionType::Fixed2x4("mat2x4", EPrecision::Low);
	const CPrecisionType CPrecisionType::Fixed3x2("mat3x2", EPrecision::Low);
	const CPrecisionType CPrecisionType::Fixed3x3("mat3", EPrecision::Low);
	const CPrecisionType CPrecisionType::Fixed3x4("mat3x4", EPrecision::Low);
	const CPrecisionType CPrecisionType::Fixed4x2("mat4x2", EPrecision::Low);
	const CPrecisionType CPrecisionType::Fixed4x3("mat4x3", EPrecision::Low);
	const CPrecisionType CPrecisionType::Fixed4x4("mat4", EPrecision::Low);
	const CPrecisionType CPrecisionType::SamplerState("samplerSate");
	const CPrecisionType CPrecisionType::SamplerComparisonState("samplerComparisonSate");
}
