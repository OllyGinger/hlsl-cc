#pragma once
#include "AST/Nodes/Node.h"
#include "AST/Nodes/Expression.h"
#include "AST/Nodes/CompoundStatement.h"
#include "AST/Nodes/ParameterDeclerator.h"

namespace AST
{
	class CFunction : public CNode
	{
	public:
		typedef std::shared_ptr<CFunction> TPointer;
		typedef std::list<CParameterDeclerator::TPointer> TParameterList;

		CFunction(TString identifier, CFullySpecifiedType::TPointer returnType)
			: m_Identifier(identifier)
			, m_ReturnType(returnType)
		{}

		inline void AddParameter(CParameterDeclerator::TPointer param)	{ m_Parameters.push_back(param); }
		inline void SetReturnSemantic(TString returnSemantic) { m_ReturnSemantic = returnSemantic; }
		inline CFullySpecifiedType::TPointer GetReturnType() const { return m_ReturnType; }
		inline TString GetIdentifier() const { return m_Identifier; }
		TParameterList GetParameters() const { return m_Parameters; }

		virtual bool VisitNodes(class IVisitor* visitor) override;

	private:
		TString m_Identifier;
		TString m_ReturnSemantic;
		CFullySpecifiedType::TPointer m_ReturnType;

		TParameterList m_Parameters;
		
	};


	class CFunctionDefinition : public CNode
	{
	public:
		typedef std::shared_ptr<CFunctionDefinition> TPointer;
		CFunctionDefinition(CFunction::TPointer prototype, CCompoundStatement::TPointer body)
			: m_Prototype(prototype)
			, m_Body(body)
		{}

		inline CFunction::TPointer GetPrototype() const { return m_Prototype; }
		inline CCompoundStatement::TPointer GetBody() const { return m_Body; }

		virtual bool VisitNodes(class IVisitor* visitor) override;

	private:
		CFunction::TPointer m_Prototype;
		CCompoundStatement::TPointer m_Body;
	};
}
