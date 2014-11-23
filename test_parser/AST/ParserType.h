#pragma once
#include "AST/Nodes/Attribute.h"
#include "AST/Nodes/CompoundStatement.h"
#include "AST/Nodes/Declaration.h"
#include "AST/Nodes/Expression.h"
#include "AST/Nodes/FlowControlStatement.h"
#include "AST/Nodes/Function.h"
#include "AST/Nodes/IterationStatement.h"
#include "AST/Nodes/ParameterDeclerator.h"
#include "AST/Nodes/SelectionStatement.h"
#include "AST/Nodes/StructSpecifier.h"
#include "AST/Nodes/SwitchStatement.h"
#include "AST/Nodes/TypeSpecifier.h"

struct YYSTYPE
{
	std::string string;
	std::string identifier;
	int number;
	double real;

	AST::CNode::TPointer node;
	AST::CTypeSpecifier::TPointer typeSpecifier;
	AST::TTypeQualifier typeQualifier;
	AST::CFullySpecifiedType::TPointer fullySpecifiedType;
	AST::CFunction::TPointer function;
	AST::CParameterDeclerator::TPointer parameterDeclerator;
	AST::CFunctionDefinition::TPointer functionDefinition;
	AST::CCompoundStatement::TPointer compoundStatement;
	AST::CExpression::TPointer expression;
	AST::CDecleratorList::TPointer decleratorList;
	AST::CStructSpecifier::TPointer structSpecifier;
	AST::CDecleration::TPointer declaration;
	AST::CSwitchBody::TPointer switchBody;
	AST::CCaseLabel::TPointer caseLabel;
	AST::CCaseLabelList::TPointer caseLabelList;
	AST::CCaseStatement::TPointer caseStatement;
	AST::CCaseStatementList::TPointer caseStatementList;
	AST::CAttribute::TPointer attribute;
	AST::CAttributeArgument::TPointer attributeArg;
};
