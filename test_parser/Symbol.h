#pragma once
#include <memory>
#include <string>

class CSymbol
{
public:
	typedef std::shared_ptr<CSymbol> TPointer;
	typedef std::string TString;

	enum EType
	{
		Variable,
		Function,
		Type
	};

	CSymbol(EType type, const TString &identifier)
		: m_Identifier(identifier)
		, m_Type(type)
	{}

	TString GetIdentifier() const { return m_Identifier; }
	EType GetType() const { return m_Type; }

private:
	TString m_Identifier;
	EType m_Type;
};



class CVariable : public CSymbol
{
public:
	CVariable(const TString &identifier)
		: CSymbol(CSymbol::Variable, identifier)
	{}
};



class CFunction : public CSymbol
{
public:
	typedef std::shared_ptr<CFunction> TPointer;

	CFunction(const TString &identifier)
		: CSymbol(CSymbol::Function, identifier)
	{}
};


class CType : public CSymbol
{
public:
	typedef std::shared_ptr<CType> TPointer;

	CType(const TString &identifier)
		: CSymbol(CSymbol::Type, identifier)
	{}
};