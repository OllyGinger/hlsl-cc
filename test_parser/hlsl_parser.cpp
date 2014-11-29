// hlsl_parser.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "codegen.h"
#include "node.h"
#include "AST/ParserType.h"
#include "AST/Visitor/PrintASTVisitor.h"
#include "AST/Visitor/IRGenASTVisitor.h"
#include <llvm/PassManager.h>
#include <llvm/Analysis/Passes.h>
#include <llvm/LinkAllPasses.h>

using namespace std;

int yyparse(THLSLParserState *scanner);

typedef void* yyscan_t;
int yylex_init_extra(THLSLParserState *state, yyscan_t* scanner);
void yyset_in(FILE * in_str, yyscan_t yyscanner);
void yyset_debug(int debug, yyscan_t yyscanner);
int yylex_destroy(yyscan_t yyscanner);

int yylex(YYSTYPE *yylval, YYLTYPE *yylloc, void *scanner);



int main(int argc, char **argv)
{
	FILE *myfile = fopen("input.hlsl", "r");
	// make sure it's valid:
	if (!myfile) {
		cout << "I can't open a.snazzle.file!" << endl;
		return -1;
	}

	//extern int yydebug;
	//yydebug = 1;

	THLSLParserState state;
	yylex_init_extra(&state, &state.scanner);
	yyset_in(myfile, state.scanner);
	yyset_debug(0, state.scanner);
	yyparse(&state);
//	yylex_destroy(state.scanner);
	fclose(myfile);

	AST::CNode::TPointer buffer = state.globalNodes.back();

	// Print out the AST to stdout
	AST::CPrintASTVisitor visitor(std::cout);
	buffer->VisitNodes(&visitor);

	// Generate LLVM-IR code
	AST::CIRGenASTVisitor irGenVisitor;
	buffer->VisitNodes(&irGenVisitor);

	// Optimisation pass :D
	llvm::InitializeNativeTarget();
	irGenVisitor.GetModule()->dump();
	llvm::ExecutionEngine* TheExecutionEngine = EngineBuilder(irGenVisitor.GetModule()).create();
	llvm::PassManager passManager;
	passManager.add(llvm::createVerifierPass());
	passManager.add(new llvm::DataLayoutPass(irGenVisitor.GetModule()));
	passManager.add(llvm::createConstantMergePass());
	passManager.add(llvm::createConstantPropagationPass());
	passManager.add(llvm::createDeadStoreEliminationPass());
	passManager.add(llvm::createDeadCodeEliminationPass());
	
	

	llvm::Function* func = irGenVisitor.GetModule()->getFunction("f");
	passManager.run(*irGenVisitor.GetModule());

	irGenVisitor.GetModule()->dump();
	//std::cout << programBlock << std::endl;

// 	CodeGenContext context;
// 	context.generateCode(*programBlock);
// 	context.runCode();

	return 0;
}
