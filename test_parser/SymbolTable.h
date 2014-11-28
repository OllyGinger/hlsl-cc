#pragma once
#include "Symbol.h"
#include <memory>
#include <stack>
#include <list>
#include <string>

class CSymbolTableScope
{
public:
	typedef std::shared_ptr<CSymbolTableScope> TPointer;
	typedef std::list<CSymbol::TPointer> TSymbolList;

	~CSymbolTableScope();

	bool AddSymbol(const CSymbol::TPointer& symbol);
	CSymbol::TPointer FindSymbol(CSymbol::TString identifier);

private:
	TSymbolList m_SymbolList;
};

class CSymbolTable
{
public:
	typedef std::stack<CSymbolTableScope::TPointer> TSymbolTableScopeStack;

	CSymbolTable();
	~CSymbolTable();

	void PushScope();
	void PopScope();

	bool AddVariable(CVariable::TPointer variable);
	bool AddFunction(CFunction::TPointer func);
	bool AddType(CType::TPointer type);

	CSymbol::TPointer FindSymbol(CSymbol::TString name);
	CSymbol::TPointer FindVariable(CSymbol::TString name);
	CSymbol::TPointer FindFunction(CSymbol::TString name);
	CSymbol::TPointer FindType(CSymbol::TString name);

	uint32_t GetDepth() const;

private:
	TSymbolTableScopeStack m_ScopeStack;
};
