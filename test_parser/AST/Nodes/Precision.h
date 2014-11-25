#pragma once
#include <stdint.h>

namespace AST
{
	struct EPrecision
	{
		enum Enum : uint32_t
		{
			None = 0,
			High,
			Medium,
			Low
		};
	};
}