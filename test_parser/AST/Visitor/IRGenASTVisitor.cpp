#include "AST/Visitor/IRGenASTVisitor.h"
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/PassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Pass.h>
//#include <llvm/ModuleProvider.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/JIT.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/IR/IRPrintingPasses.h>

namespace AST
{
	CIRGenASTVisitor::CIRGenASTVisitor() 
		: m_IRBuilder(llvm::getGlobalContext())
	{
		// For the moment we don't really have a module node in the AST, so create
		// the IR module as the top element here.
		m_Module = new llvm::Module("main_module", llvm::getGlobalContext());
	}


	CIRGenASTVisitor::~CIRGenASTVisitor()
	{
		delete m_Module;
		m_Module = nullptr;
	}


	void CIRGenASTVisitor::PushScope()
	{
		m_SymbolTable.PushScope();
	}

	void CIRGenASTVisitor::PopScope()
	{
		m_SymbolTable.PopScope();
	}

	bool CIRGenASTVisitor::VisitAttribute(CAttribute::TPointer attribute)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitAttributeArgument(CAttributeArgument::TPointer attributeArgument)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitCompoundStatement(CCompoundStatement::TPointer compoundStatement)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitDecleration(CDecleration::TPointer decleration)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitDeclerationList(CDecleratorList::TPointer declerationList)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitExpression(CExpression::TPointer expression)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitExpressionStatement(CExpressionStatement::TPointer expressionStatement)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitBinaryExpression(CBinaryExpression::TPointer binaryExpression)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitFunctionExpression(CFunctionExpression::TPointer functionExpression)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitInitialiserListExpression(CInitialiserListExpression::TPointer initialiserListExpression)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitFlowControlStatement(CFlowControlStatement::TPointer flowControlStatement)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitFunction(CFunction::TPointer func)
	{
		const llvm::Type* returnType = TypeOf(func->GetReturnType());
		//llvm::FunctionType *funcType = llvm::FunctionType::get(returnType,)
		return true;
	}

	bool CIRGenASTVisitor::VisitFunctionDefinition(CFunctionDefinition::TPointer functionDefinition)
	{
		// Pass
		return true;
	}

	bool CIRGenASTVisitor::VisitIterationStatement(CIterationStatement::TPointer iterationStatement)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitParameterDeclerator(CParameterDeclerator::TPointer parameterDeclerator)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitPrecisionType(CPrecisionType::TPointer precisionType)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitSelectionStatement(CSelectionStatement::TPointer selectionStatement)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitStructSpecifier(CStructSpecifier::TPointer structSpecifier)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitCBufferSpecifier(CCBufferSpecifier::TPointer cBufferSpecifier)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitSwitchStatement(CSwitchStatement::TPointer switchStatement)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitSwitchBody(CSwitchBody::TPointer switchBody)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitCaseLabel(CCaseLabel::TPointer caseLabel)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitCaseLabelList(CCaseLabelList::TPointer caseLabelList)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitCaseStatement(CCaseStatement::TPointer caseStatement)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitCaseStatementList(CCaseStatementList::TPointer caseStatementList)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitTypeSpecifier(CTypeSpecifier::TPointer typeSpecifier)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitFullySpecifiedType(CFullySpecifiedType::TPointer fullySpecifiedType)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	const llvm::Type* CIRGenASTVisitor::TypeOf(CFullySpecifiedType::TPointer type)
	{
		CTypeSpecifier::TPointer typeSpecifier = type->GetTypeSpecifier();
		return TypeOf(typeSpecifier);
	}

	const llvm::Type* CIRGenASTVisitor::TypeOf(CTypeSpecifier::TPointer type)
	{
		if (type->GetTypeName() == "int" || type->GetTypeName() == "uint")
		{
			return m_IRBuilder.getInt32Ty();
		}
		else if (type->GetTypeName() == "float")
		{
			return m_IRBuilder.getFloatTy();
		}
		else if (type->GetTypeName() == "bool")
		{
			return m_IRBuilder.getInt1Ty();
		}

		return m_IRBuilder.getVoidTy();
	}

}
