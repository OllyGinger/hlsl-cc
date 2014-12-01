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


	void CIRGenASTVisitor::PushBlockScope(llvm::BasicBlock* block)
	{
		m_IRBuilder.SetInsertPoint(block);
		m_SymbolTable.PushScope();
		m_BlockStack.push(block);
	}

	void CIRGenASTVisitor::PopBlockScope()
	{
		m_BlockStack.pop();
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
		for (auto statement : compoundStatement->GetStatementList())
		{
			statement->VisitNodes(this);
		}
		return true;
	}

	bool CIRGenASTVisitor::VisitDecleration(CDecleration::TPointer decleration)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitDeclerationList(CDecleratorList::TPointer declerationList)
	{
		// The type specifier might contain a structure definition, so generate that 
		// first.
		CFullySpecifiedType::TPointer type = declerationList->GetType();
		type->GetTypeSpecifier()->VisitNodes(this);

		llvm::Type* declListType = TypeOf(type);
		for (auto declaration : declerationList->GetDeclerations())
		{
			llvm::AllocaInst* alloc = new llvm::AllocaInst(declListType, declaration->GetIdentifier(), GetCurrentScopeBlock());
			CSymbol::TPointer declSymbol = std::make_shared<CSymbol>(CSymbol::Variable, declaration->GetIdentifier(), alloc);
			m_SymbolTable.AddVariable(declSymbol);

			// Initialise the value to its default
			CExpression::TPointer initialiser = declaration->GetInitialiser();
			if (initialiser)
			{
				initialiser->VisitNodes(this);
				
				llvm::StoreInst* storeInstruction = new llvm::StoreInst(m_LastValue, alloc, GetCurrentScopeBlock());
			}
		}
		
		return true;
	}

	bool CIRGenASTVisitor::VisitExpression(CExpression::TPointer expression)
	{
		EOperator::Enum op = expression->GetOperator();

		CNode::TPointer exp1 = expression->GetSubExpressionList()[0];
		CNode::TPointer exp2 = expression->GetSubExpressionList()[1];
		CNode::TPointer exp3 = expression->GetSubExpressionList()[2];

		switch (op)
		{
		case EOperator::Assign:
			expression->GetSubExpressionList()[0]->VisitNodes(this);
			expression->GetSubExpressionList()[1]->VisitNodes(this);
			break;
		
		case EOperator::Add:
		case EOperator::Subtract:
		case EOperator::Multiply:
		case EOperator::Divide:
		case EOperator::Modulo:
		case EOperator::LeftShift:
		case EOperator::RightShift:
		case EOperator::BitwiseAnd:
		case EOperator::BitwiseOr:
		case EOperator::BitwiseXOr:
		{
			exp1->VisitNodes(this);
			llvm::Value* lhs = m_LastValue;
			exp2->VisitNodes(this);
			llvm::Value* rhs = m_LastValue;

			llvm::Instruction::BinaryOps instruction = GetBinaryOpInstructionForValues(op, lhs, rhs);
			m_LastValue = llvm::BinaryOperator::Create(instruction, lhs, rhs, "", GetCurrentScopeBlock());
			break;
		}
			

		case EOperator::Identifier:
		{
			CSymbol::TPointer scopedVariable = m_SymbolTable.FindVariable(expression->GetIdentifier());
			m_LastValue = scopedVariable->GetIRValue();
			break;
		}
		case EOperator::IntConstant:
			m_LastValue = llvm::ConstantInt::get(m_IRBuilder.getInt32Ty(), expression->GetExpression().u.IntConstant, true);
			break;
		case EOperator::UIntConstant:
			m_LastValue = llvm::ConstantInt::get(m_IRBuilder.getInt32Ty(), expression->GetExpression().u.UIntConstant, false);
			break;
		case EOperator::FloatConstant:
			m_LastValue = llvm::ConstantFP::get(m_IRBuilder.getFloatTy(), expression->GetExpression().u.FloatConstant);
			break;
		case EOperator::BoolConstant:
			m_LastValue = llvm::ConstantInt::get(m_IRBuilder.getInt8Ty(), expression->GetExpression().u.BoolConstant);
			break;

		default:
			throw std::logic_error("Unimplemented expression");
		}

		return true;
	}

	bool CIRGenASTVisitor::VisitExpressionStatement(CExpressionStatement::TPointer expressionStatement)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitBinaryExpression(CBinaryExpression::TPointer binaryExpression)
	{
		return VisitExpression(binaryExpression);
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
		switch (flowControlStatement->GetType())
		{
		case CFlowControlStatement::EType::Continue:
			break;
		case CFlowControlStatement::EType::Break:
			break;
		case CFlowControlStatement::EType::Return:

			if (flowControlStatement->GetReturnExpression())
			{
				flowControlStatement->GetReturnExpression()->VisitNodes(this);
				llvm::Value* retVal = m_LastValue;
				llvm::Type* retType = m_LastValue->getType();
				if (retType->isPointerTy())
				{
					retVal = new llvm::LoadInst(m_LastValue, "", GetCurrentScopeBlock());
				}		
				
				llvm::ReturnInst::Create(llvm::getGlobalContext(), retVal, GetCurrentScopeBlock());
			}
			else
			{
				llvm::ReturnInst::Create(llvm::getGlobalContext(), GetCurrentScopeBlock());
			}
			
			m_Module->dump();
			break;
		case CFlowControlStatement::EType::Discard:
			break;
		}

		return true;
	}

	bool CIRGenASTVisitor::VisitFunction(CFunction::TPointer func)
	{	
		CFullySpecifiedType::TPointer returnType = func->GetReturnType();
		CTypeSpecifier::TPointer returnTypeSpecifier = returnType->GetTypeSpecifier();
		
		std::vector<llvm::Type*> argTypes;
		auto funcParams = func->GetParameters();
		for (auto param : funcParams)
		{
			CFullySpecifiedType::TPointer paramType = param->GetType();
			CTypeSpecifier::TPointer paramTypeSpecifier = paramType->GetTypeSpecifier();

			argTypes.push_back(TypeOf(paramType));
		}

		llvm::FunctionType* functionType = llvm::FunctionType::get(TypeOf(func->GetReturnType()), argTypes, false);
		llvm::Function* function = llvm::Function::Create(functionType, llvm::GlobalValue::InternalLinkage, func->GetIdentifier(), m_Module);
		llvm::BasicBlock* functionBlock = llvm::BasicBlock::Create(llvm::getGlobalContext(), "entry", function);
		PushBlockScope(functionBlock);
		llvm::Function::arg_iterator irArgs = function->arg_begin();

		m_func = function;

		for (auto param : funcParams)
		{
			//VisitParameterDeclerator(param);
			llvm::Value* pramValue = (irArgs++);
			pramValue->setName(param->GetIdentifier());

			CSymbol::TPointer paramVarSymbol = std::make_shared<CSymbol>(CSymbol::Variable, param->GetIdentifier(), pramValue);
			m_SymbolTable.AddVariable(paramVarSymbol);
		}

		return true;
	}

	bool CIRGenASTVisitor::VisitFunctionDefinition(CFunctionDefinition::TPointer functionDefinition)
	{
		VisitFunction(functionDefinition->GetPrototype());
		VisitCompoundStatement(functionDefinition->GetBody());
		return true;
	}

	bool CIRGenASTVisitor::VisitIterationStatement(CIterationStatement::TPointer iterationStatement)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	bool CIRGenASTVisitor::VisitParameterDeclerator(CParameterDeclerator::TPointer parameterDeclerator)
	{
		llvm::AllocaInst* alloc = new llvm::AllocaInst(TypeOf(parameterDeclerator->GetType()), parameterDeclerator->GetIdentifier(), GetCurrentScopeBlock());

		CSymbol::TPointer paramVarSymbol = std::make_shared<CSymbol>(CSymbol::Variable, parameterDeclerator->GetIdentifier(), alloc);
		m_SymbolTable.AddVariable(paramVarSymbol);

		if (parameterDeclerator->GetDefaultValue())
		{
			/*CExpression::TPointer lhs = std::make_shared<CExpression>(parameterDeclerator->GetIdentifier());
			CExpression::TPointer defaultAssignmentExpression = std::make_shared<CExpression>(EOperator::Assign, lhs, parameterDeclerator->GetDefaultValue());
			defaultAssignmentExpression->VisitNodes(this);*/

			OutputError("Param default values are not yet supported\n");
		}

		return true;
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
		CStructSpecifier::TPointer structure = typeSpecifier->GetStructure();
		if (structure)
		{
			structure->VisitNodes(this);
		}
		return true;
	}

	bool CIRGenASTVisitor::VisitFullySpecifiedType(CFullySpecifiedType::TPointer fullySpecifiedType)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}

	llvm::Type* CIRGenASTVisitor::TypeOf(CFullySpecifiedType::TPointer type)
	{
		CTypeSpecifier::TPointer typeSpecifier = type->GetTypeSpecifier();
		return TypeOf(typeSpecifier);
	}

	llvm::Type* CIRGenASTVisitor::TypeOf(CTypeSpecifier::TPointer type)
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
			return m_IRBuilder.getInt8Ty();
		}

		return m_IRBuilder.getVoidTy();
	}

	llvm::Instruction::BinaryOps CIRGenASTVisitor::GetBinaryOpInstructionForValues(EOperator::Enum op, llvm::Value* lhs, llvm::Value* rhs)
	{
		llvm::Instruction::BinaryOps instruction;
		switch (op)
		{
		case EOperator::Add:
			if (lhs->getType()->isFloatTy() || rhs->getType()->isFloatTy())
			{
				instruction = llvm::Instruction::FAdd;
			}
			else
			{
				instruction = llvm::Instruction::Add;
			}
			break;
		case EOperator::Subtract:
			if (lhs->getType()->isFloatTy() || rhs->getType()->isFloatTy())
			{
				instruction = llvm::Instruction::FSub;
			}
			else
			{
				instruction = llvm::Instruction::Sub;
			}
			break;
		case EOperator::Multiply:
			if (lhs->getType()->isFloatTy() || rhs->getType()->isFloatTy())
			{
				instruction = llvm::Instruction::Mul;
			}
			else
			{
				instruction = llvm::Instruction::Mul;
			}
			break;
		case EOperator::Divide:
			if (lhs->getType()->isFloatTy() || rhs->getType()->isFloatTy())
			{
				instruction = llvm::Instruction::FDiv;
			}
			else
			{
				instruction = llvm::Instruction::SDiv;
			}
			break;
		case EOperator::Modulo:
			if (lhs->getType()->isFloatTy() || rhs->getType()->isFloatTy())
			{
				instruction = llvm::Instruction::FRem;
			}
			else
			{
				instruction = llvm::Instruction::SRem;
			}
			break;
		case EOperator::LeftShift:
			instruction = llvm::Instruction::Shl;
			break;
		case EOperator::RightShift:
			instruction = llvm::Instruction::LShr;
			break;
		case EOperator::BitwiseAnd:
			instruction = llvm::Instruction::And;
			break;
		case EOperator::BitwiseOr:
			instruction = llvm::Instruction::Or;
			break;
		case EOperator::BitwiseXOr:
			instruction = llvm::Instruction::Xor;
			break;
		default:
			throw std::logic_error("Unhandled binary operator instruction");
		}

		return instruction;
	}

}
