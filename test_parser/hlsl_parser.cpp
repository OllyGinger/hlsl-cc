// hlsl_parser.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "codegen.h"
#include "node.h"

using namespace std;

extern int yyparse();
extern NBlock* programBlock;
extern FILE* yyin;

int main(int argc, char **argv)
{
	FILE *myfile = fopen("input.hlsl", "r");
	// make sure it's valid:
	if (!myfile) {
		cout << "I can't open a.snazzle.file!" << endl;
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;

	yyparse();
	std::cout << programBlock << std::endl;

	CodeGenContext context;
	context.generateCode(*programBlock);
	context.runCode();

	return 0;
}
