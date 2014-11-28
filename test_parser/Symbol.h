#pragma once
#include <memory>
#include <string>
#include <llvm/IR/Value.h>

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

	CSymbol(EType type, const TString& identifier)
		: m_Identifier(identifier)
		, m_Type(type)
	{}

	CSymbol(EType type, const TString& identifier, llvm::Value* irValue)
		: m_Identifier(identifier)
		, m_Type(type)
		, m_IRValue(irValue)
	{}

	TString GetIdentifier() const { return m_Identifier; }
	EType GetType() const { return m_Type; }
	llvm::Value* GetIRValue() const { return m_IRValue; }

private:
	TString m_Identifier;
	EType m_Type;

	llvm::Value* m_IRValue;
};



class CVariable : public CSymbol
{
public:
	CVariable(const TString& identifier)
		: CSymbol(CSymbol::Variable, identifier)
	{}
};



class CFunction : public CSymbol
{
public:
	typedef std::shared_ptr<CFunction> TPointer;

	CFunction(const TString& identifier)
		: CSymbol(CSymbol::Function, identifier)
	{}
};


class CType : public CSymbol
{
public:
	typedef std::shared_ptr<CType> TPointer;

	CType(const TString& identifier)
		: CSymbol(CSymbol::Type, identifier)
	{}
};