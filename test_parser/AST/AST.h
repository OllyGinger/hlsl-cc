#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include <stdint.h>

struct YYLTYPE;

struct THLSLParserState
{
	void *scanner;
};

namespace AST
{
	typedef std::string TString;
}


