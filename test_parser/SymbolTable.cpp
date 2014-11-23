#include "SymbolTable.h"


CSymbolTableScope::~CSymbolTableScope()
{
	m_SymbolList.clear();
}

bool CSymbolTableScope::AddSymbol(const CSymbol::TPointer& symbol)
{
	// Can't add multiple symbols with the same name in this scope
	if (FindSymbol(symbol->GetIdentifier()))
	{
		return false;
	}

	m_SymbolList.push_back(symbol);
	return true;
}

CSymbol::TPointer CSymbolTableScope::FindSymbol(CSymbol::TString identifier)
{
	for (CSymbol::TPointer symbol : m_SymbolList)
	{
		if (symbol->GetIdentifier() == identifier)
		{
			return symbol;
		}
	}

	return CSymbol::TPointer();
}


CSymbolTable::CSymbolTable()
{
	// Always need a valid scope
	PushScope();
}


CSymbolTable::~CSymbolTable()
{
	PopScope();
}


void CSymbolTable::PushScope()
{
	CSymbolTableScope::TPointer scope = std::make_shared<CSymbolTableScope>();
	m_ScopeStack.push(scope);
}

void CSymbolTable::PopScope()
{
	m_ScopeStack.pop();
}

uint32_t CSymbolTable::GetDepth() const
{
	return m_ScopeStack.size();
}

bool CSymbolTable::AddVariable(CVariable::TPointer variable)
{
	CSymbolTableScope *currentScope = m_ScopeStack.top().get();
	return currentScope->AddSymbol(variable);
}

bool CSymbolTable::AddFunction(CFunction::TPointer func)
{
	CSymbolTableScope *currentScope = m_ScopeStack.top().get();
	return currentScope->AddSymbol(func);
}

bool CSymbolTable::AddType(CType::TPointer type)
{
	CSymbolTableScope *currentScope = m_ScopeStack.top().get();
	return currentScope->AddSymbol(type);
}

