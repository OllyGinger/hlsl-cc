#pragma once
#include <memory>
#include <string>

class CSymbol
{
public:
	typedef std::shared_ptr<CSymbol> TPointer;
	typedef std::string TString;

	CSymbol(const TString &identifier)
		: m_Identifier(identifier)
	{}

	TString GetIdentifier() const { return m_Identifier; }

private:
	TString m_Identifier;
};



class CVariable : public CSymbol
{
public:
	typedef std::shared_ptr<CVariable> TPointer;

	CVariable(const TString &identifier)
		: CSymbol(identifier)
	{}
};



class CFunction : public CSymbol
{
public:
	typedef std::shared_ptr<CFunction> TPointer;

	CFunction(const TString &identifier)
		: CSymbol(identifier)
	{}
};


class CType : public CSymbol
{
public:
	typedef std::shared_ptr<CType> TPointer;

	CType(const TString &identifier)
		: CSymbol(identifier)
	{}
};