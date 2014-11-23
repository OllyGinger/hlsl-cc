#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include <stdint.h>
#include "SymbolTable.h"

struct YYLTYPE;

struct THLSLParserState
{
	void *scanner;

	CSymbolTable symbols;
};

namespace AST
{
	typedef std::string TString;
}


