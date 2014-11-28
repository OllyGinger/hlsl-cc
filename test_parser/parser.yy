%{
	#include "AST/AST.h"
	#include "AST/ParserType.h"
	#include "parser.hpp"
    #include <cstdio>
    #include <cstdlib>
	AST::CNode *programBlock; /* the top level root node of our final AST */

	#define YYLEX_PARAM state->scanner
	
	void yyerror(YYLTYPE *loc, void *st, const char *s) { std::printf("Error: %s\n", s); }
	extern int yylex(YYSTYPE * lvalp, YYLTYPE*,  void*);
%}



%pure-parser
%error-verbose
%locations
%initial-action {
   @$.first_line = 1;
   @$.first_column = 1;
   @$.last_line = 1;
   @$.last_column = 1;
}
%lex-param   {void *scanner}
%parse-param {struct THLSLParserState *state}

%token TOK_CONST TOK_BOOL TOK_FLOAT TOK_HALF TOK_INT TOK_UINT TOK_VOID
%token TOK_BREAK TOK_CONTINUE TOK_DO TOK_WHILE TOK_ELSE TOK_FOR TOK_IF TOK_DISCARD TOK_RETURN TOK_SWITCH TOK_DEFAULT TOK_STRUCT TOK_CBUFFER TOK_INTERFACE
%token TOK_BOOL_VEC2 TOK_BOOL_VEC3 TOK_BOOL_VEC4
%token TOK_INT_VEC2 TOK_INT_VEC3 TOK_INT_VEC4
%token TOK_UINT_VEC2 TOK_UINT_VEC3 TOK_UINT_VEC4
%token TOK_FLOAT_VEC2 TOK_FLOAT_VEC3 TOK_FLOAT_VEC4
%token TOK_FIXED_VEC2 TOK_FIXED_VEC3 TOK_FIXED_VEC4
%token TOK_HALF_VEC2 TOK_HALF_VEC3 TOK_HALF_VEC4
%token TOK_FLOAT_VEC2X2 TOK_FLOAT_VEC2X3 TOK_FLOAT_VEC2X4
%token TOK_FLOAT_VEC3X2 TOK_FLOAT_VEC3X3 TOK_FLOAT_VEC3X4
%token TOK_FLOAT_VEC4X2 TOK_FLOAT_VEC4X3 TOK_FLOAT_VEC4X4
%token TOK_HALF_VEC2X2 TOK_HALF_VEC2X3 TOK_HALF_VEC2X4
%token TOK_HALF_VEC3X2 TOK_HALF_VEC3X3 TOK_HALF_VEC3X4
%token TOK_HALF_VEC4X2 TOK_HALF_VEC4X3 TOK_HALF_VEC4X4
%token TOK_FIXED_VEC2X2 TOK_FIXED_VEC2X3 TOK_FIXED_VEC2X4
%token TOK_FIXED_VEC3X2 TOK_FIXED_VEC3X3 TOK_FIXED_VEC3X4
%token TOK_FIXED_VEC4X2 TOK_FIXED_VEC4X3 TOK_FIXED_VEC4X4
%token TOK_DOUBLE_VEC2 TOK_DOUBLE_VEC3 TOK_DOUBLE_VEC4

%token TOK_POINT TOK_LINE TOK_TRIANGLE TOK_LINEADJ TOK_TRIANGLEADJ TOK_POINTSTREAM TOK_LINESTREAM TOK_TRIANGLESTREAM
%token TOK_INPUTPATCH TOK_OUTPUTPATCH
%token TOK_IN TOK_OUT TOK_INOUT TOK_UNIFORM TOK_VARYING TOK_CENTROID TOK_INVARIANT TOK_NOINTERPOLATION TOK_LINEAR TOK_NOPERSPECTIVE TOK_GLOBALLYCOHERENT TOK_SHARED TOK_GROUPSHARED
%token TOK_LOWP TOK_MEDIUMP TOK_HIGHP TOK_SUPERP TOK_PRECISION

%token TOK_BUFFER TOK_RWBUFFER
%token TOK_TEXTURE1D TOK_TEXTURE1D_ARRAY TOK_RWTEXTURE1D TOK_RWTEXTURE1D_ARRAY
%token TOK_TEXTURE2D TOK_TEXTURE2D_ARRAY TOK_RWTEXTURE2D TOK_RWTEXTURE2D_ARRAY
%token TOK_TEXTURE2DMS TOK_TEXTURE2DMS_ARRAY
%token TOK_TEXTURE3D TOK_TEXTURE3D_ARRAY TOK_RWTEXTURE3D
%token TOK_TEXTURECUBE TOK_TEXTURECUBE_ARRAY
%token TOK_SAMPLERSTATE TOK_SAMPLER_CMP_STATE

%token TOK_INCREMENT TOK_DECREMENT TOK_LE TOK_GE TOK_EQ TOK_NEQ TOK_BOOL_AND TOK_BOOL_OR TOK_LSHIFT TOK_RSHIFT
%token TOK_MULTIPLY_ASSIGN TOK_DIVIDE_ASSIGN TOK_ADD_ASSIGN TOK_MOD_ASSIGN TOK_LSHIFT_ASSIGN TOK_RSHIFT_ASSIGN TOK_AND_ASSIGN TOK_XOR_ASSIGN TOK_OR_ASSIGN TOK_SUBTRACT_ASSIGN

%token <real> TOK_FLOAT_CONSTANT
%token <number> TOK_INT_CONSTANT TOK_UINT_CONSTANT TOK_BOOL_CONSTANT
%token <string> TOK_STRING_CONSTANT
%token <identifier> TOK_IDENTIFIER TOK_TYPE_IDENTIFIER TOK_NEW_IDENTIFIER
%type <identifier> any_identifier
%token <identifier> TOK_FIELD_SELECTION

%token TOK_ASM TOK_CLASS TOK_UNION TOK_ENUM TOK_TYPEDEF TOK_TEMPLATE TOK_THIS TOK_PACKED TOK_GOTO
%token TOK_INLINE TOK_NOINLINE TOK_VOLATILE TOK_PUBLIC TOK_STATIC TOK_EXTERN TOK_EXTERNAL
%token TOK_LONG TOK_SHORT TOK_DOUBLE TOK_FIXED TOK_UNSIGNED 
%token TOK_SAMPLER2DRECT TOK_SAMPLER3DRECT TOK_SAMPLER2DRECTSHADOW
%token TOK_SIZEOF TOK_CAST TOK_NAMESPACE TOK_USING
%token TOK_CASE TOK_COMMON TOK_PARTITION TOK_ACTIVE TOK_SAMPLERBUFFER TOK_FILTER
%token TOK_IMAGE1D  TOK_IMAGE2D  TOK_IMAGE3D  TOK_IMAGECUBE  TOK_IMAGE1DARRAY  TOK_IMAGE2DARRAY
%token TOK_IIMAGE1D TOK_IIMAGE2D TOK_IIMAGE3D TOK_IIMAGECUBE TOK_IIMAGE1DARRAY TOK_IIMAGE2DARRAY
%token TOK_UIMAGE1D TOK_UIMAGE2D TOK_UIMAGE3D TOK_UIMAGECUBE TOK_UIMAGE1DARRAY TOK_UIMAGE2DARRAY
%token TOK_IMAGE1DSHADOW TOK_IMAGE2DSHADOW TOK_IMAGEBUFFER TOK_IIMAGEBUFFER TOK_UIMAGEBUFFER
%token TOK_IMAGE1DARRAYSHADOW TOK_IMAGE2DARRAYSHADOW
%token TOK_ROWMAJOR TOK_COLUMNMAJOR TOK_LAYOUT

%type <identifier> variable_identifier
%type <node> statement
%type <nodeList> statement_list
%type <node> simple_statement
%type <number> precision_qualifier
%type <typeQualifier> type_qualifier
%type <typeQualifier> storage_qualifier
%type <typeQualifier> interpolation_qualifier
%type <typeQualifier> layout_qualifier
%type <typeQualifier> layout_qualifier_id_list layout_qualifier_id
%type <typeQualifier> struct_type_qualifier
%type <fullySpecifiedType> struct_type_specifier
%type <typeSpecifier> type_specifier
%type <typeSpecifier> type_specifier_no_prec
%type <typeSpecifier> type_specifier_nonarray
%type <typeSpecifier> type_specifier_array
%type <typeSpecifier> precision_decl
%type <precisionType> basic_type_specifier_nonarray
%type <identifier> texture_type_specifier_nonarray
%type <identifier> outputstream_type_specifier_nonarray
%type <identifier> inputpatch_type_specifier_nonarray
%type <identifier> outputpatch_type_specifier_nonarray
%type <fullySpecifiedType> fully_specified_type
%type <function> function_decl
%type <function> function_prototype
%type <function> function_header
%type <function> function_header_with_parameters
%type <function> function_declarator
%type <parameterDeclerator> parameter_declarator
%type <parameterDeclerator> parameter_declaration
%type <typeQualifier> parameter_qualifier
%type <typeQualifier> parameter_type_qualifier
%type <typeSpecifier> parameter_type_specifier
%type <functionDefinition> function_definition
%type <compoundStatement> compound_statement_no_new_scope
%type <compoundStatement> compound_statement
%type <node> statement_no_new_scope
%type <node> expression_statement
%type <expression> expression
%type <expression> primary_expression
%type <expression> assignment_expression
%type <expression> conditional_expression
%type <expression> logical_or_expression
%type <expression> logical_and_expression
%type <expression> inclusive_or_expression
%type <expression> exclusive_or_expression
%type <expression> and_expression
%type <expression> equality_expression
%type <expression> relational_expression
%type <expression> shift_expression
%type <expression> additive_expression
%type <expression> multiplicative_expression
%type <expression> unary_expression
%type <expression> constant_expression
%type <expression> integer_expression
%type <expression> postfix_expression
%type <expression> function_call_header_with_parameters
%type <expression> function_call_header_no_parameters
%type <expression> function_call_header
%type <expression> function_call_generic
%type <expression> function_call_or_method
%type <expression> function_call
%type <expression> method_call_generic
%type <expression> method_call_header_with_parameters
%type <expression> method_call_header_no_parameters
%type <expression> method_call_header
%type <number> assignment_operator
%type <number> unary_operator
%type <expression> function_identifier
%type <node> external_declaration
%type <decleratorList> init_declarator_list
%type <decleratorList> single_declaration
%type <expression> initializer
%type <expression> initializer_list
%type <node> declaration
%type <node> declaration_statement
%type <node> jump_statement
%type <structSpecifier> struct_specifier
%type <node> struct_declaration_list
%type <decleratorList> struct_declaration
%type <declaration> struct_declarator
%type <declaration> struct_declarator_list
%type <node> selection_statement
%type <selectionRestStatement> selection_rest_statement
%type <node> switch_statement
%type <switchBody> switch_body
%type <caseLabelList> case_label_list
%type <caseLabel> case_label
%type <caseStatement> case_statement
%type <caseStatementList> case_statement_list
%type <node> iteration_statement
%type <node> condition
%type <node> conditionopt
%type <node> for_init_statement
/*%type <for_rest_statement> for_rest_statement*/
%type <node> global_declaration
%type <node> cbuffer_declaration
%type <declaration> array_identifier
%type <attribute> attribute
%type <attribute> attribute_list
%type <attributeArg> attribute_arg
%type <attributeArg> attribute_arg_list


/* Operator precedence for mathematical operators */

%%

translation_unit: 
	{
	   
	}
	external_declaration_list
	{
	   
	}
	;


any_identifier:
	TOK_IDENTIFIER
	| TOK_TYPE_IDENTIFIER
	| TOK_NEW_IDENTIFIER
	;

external_declaration_list:
	external_declaration
	{
		if($1 != NULL)
		{
			state->globalNodes.push_back($1);
		}
	}
	| external_declaration_list external_declaration
	{
		if($2 != NULL)
		{
			state->globalNodes.push_back($2);
		}
	}
	;

variable_identifier:
	TOK_IDENTIFIER
	| TOK_NEW_IDENTIFIER
	;

primary_expression:
	variable_identifier
	{
		$$ = std::make_shared<AST::CExpression>($1);
		$$->SetSourceLocation(yylloc);
	}
	| TOK_INT_CONSTANT
	{
		$$ = std::make_shared<AST::CExpression>();
		$$->SetSourceLocation(yylloc);
		$$->MakeIntConstant($1);
	}
	| TOK_UINT_CONSTANT
	{
		$$ = std::make_shared<AST::CExpression>();
		$$->SetSourceLocation(yylloc);
		$$->MakeUIntConstant($1);
	}
	| TOK_FLOAT_CONSTANT
	{
		$$ = std::make_shared<AST::CExpression>();
		$$->SetSourceLocation(yylloc);
		$$->MakeFloatConstant($1);
	}
	| TOK_BOOL_CONSTANT
	{
		$$ = std::make_shared<AST::CExpression>();
		$$->SetSourceLocation(yylloc);
		$$->MakeBoolConstant($1);
	}
	| '(' expression ')'
	{
		$$ = $2;
	}
	;

postfix_expression:
	primary_expression
	| postfix_expression '[' integer_expression ']'
	{
		$$ = std::make_shared<AST::CExpression>(AST::EOperator::ArrayIndex, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	| function_call
	{
		$$ = $1;
	}
	| postfix_expression '.' any_identifier
	{
		$$ = std::make_shared<AST::CExpression>(AST::EOperator::FieldSelection, $1);
		$$->SetSourceLocation(yylloc);
		$$->SetIdentifier($3);
	}
	| postfix_expression TOK_INCREMENT
	{
		$$ = std::make_shared<AST::CExpression>(AST::EOperator::PostIncrement, $1);
		$$->SetSourceLocation(yylloc);
	}
	| postfix_expression TOK_DECREMENT
	{
		$$ = std::make_shared<AST::CExpression>(AST::EOperator::PostDecrement, $1);
		$$->SetSourceLocation(yylloc);
	}
	;

integer_expression:
	expression
	;

function_call:
	function_call_or_method
	;

function_call_or_method:
	function_call_generic
	| postfix_expression '.' method_call_generic
	{
		$$ = std::make_shared<AST::CExpression>(AST::EOperator::FieldSelection, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	;

function_call_generic:
	function_call_header_with_parameters ')'
	| function_call_header_no_parameters ')'
	;

function_call_header_no_parameters:
	function_call_header TOK_VOID
	| function_call_header
	;

function_call_header_with_parameters:
	function_call_header assignment_expression
	{
		$$ = $1;
		$$->SetSourceLocation(yylloc);
		$$->AddChildExpression($2);
	}
	| function_call_header_with_parameters ',' assignment_expression
	{
		$$ = $1;
		$$->SetSourceLocation(yylloc);
		$$->AddChildExpression($3);
	}
	;

	// Grammar Note: Constructors look like functions, but lexical 
	// analysis recognized most of them as keywords. They are now
	// recognized through "type_specifier".
function_call_header:
	function_identifier '('
	;

function_identifier:
	type_specifier
	{
		$$ = std::make_shared<AST::CFunctionExpression>($1);
		$$->SetSourceLocation(yylloc);
   	}
	| variable_identifier
	{
		AST::CExpression::TPointer callee = std::make_shared<AST::CExpression>($1);
		$$ = std::make_shared<AST::CFunctionExpression>(callee);
		$$->SetSourceLocation(yylloc);
   	}
	| TOK_FIELD_SELECTION
	{
		AST::CExpression::TPointer callee = std::make_shared<AST::CExpression>($1);
		$$ = std::make_shared<AST::CFunctionExpression>(callee);
		$$->SetSourceLocation(yylloc);
   	}
	;

method_call_generic:
	method_call_header_with_parameters ')'
	| method_call_header_no_parameters ')'
	;

method_call_header_no_parameters:
	method_call_header TOK_VOID
	| method_call_header
	;

method_call_header_with_parameters:
	method_call_header assignment_expression
	{
		$$ = $1;
		$$->SetSourceLocation(yylloc);
		$$->AddChildExpression($2);
	}
	| method_call_header_with_parameters ',' assignment_expression
	{
		$$ = $1;
		$$->SetSourceLocation(yylloc);
		$$->AddChildExpression($3);
	}
	;

	// Grammar Note: Constructors look like methods, but lexical 
	// analysis recognized most of them as keywords. They are now
	// recognized through "type_specifier".
method_call_header:
	variable_identifier '('
	{
		AST::CExpression::TPointer callee = std::make_shared<AST::CExpression>($1);
		$$ = std::make_shared<AST::CFunctionExpression>(callee);
		$$->SetSourceLocation(yylloc);
   	}
	;

	// Grammar Note: No traditional style type casts.
unary_expression:
	postfix_expression
	| TOK_INCREMENT unary_expression
	{
		$$ = std::make_shared<AST::CExpression>(AST::EOperator::PreIncrement, $2);
		$$->SetSourceLocation(yylloc);
	}
	| TOK_DECREMENT unary_expression
	{
		$$ = std::make_shared<AST::CExpression>(AST::EOperator::PreDecrement, $2);
		$$->SetSourceLocation(yylloc);
	}
	| unary_operator unary_expression
	{
		$$ = std::make_shared<AST::CExpression>((AST::EOperator::Enum)$1, $2);
		$$->SetSourceLocation(yylloc);
	}
	| '(' type_specifier_nonarray ')' unary_expression
	{
		$$ = std::make_shared<AST::CExpression>(AST::EOperator::TypeCast, $4);
		$$->SetTypeSpecifier($2);
		$$->SetSourceLocation(yylloc);
	}
	;

	// Grammar Note: No '*' or '&' unary ops. Pointers are not supported.
unary_operator:
	'+'		{ $$ = AST::EOperator::Plus; }
	| '-'	{ $$ = AST::EOperator::Negative; }
	| '!'	{ $$ = AST::EOperator::LogicalNot; }
	| '~'	{ $$ = AST::EOperator::BitwiseNot; }
	;

multiplicative_expression:
	unary_expression
	| multiplicative_expression '*' unary_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::Multiply, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	| multiplicative_expression '/' unary_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::Divide, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	| multiplicative_expression '%' unary_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::Modulo, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	;

additive_expression:
	multiplicative_expression
	| additive_expression '+' multiplicative_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::Add, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	| additive_expression '-' multiplicative_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::Subtract, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	;

shift_expression:
	additive_expression
	| shift_expression TOK_LSHIFT additive_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::LeftShift, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	| shift_expression TOK_RSHIFT additive_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::RightShift, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	;

relational_expression:
	shift_expression
	| relational_expression '<' shift_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::LessThan, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	| relational_expression '>' shift_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::GreaterThan, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	| relational_expression TOK_LE shift_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::LessOrEqual, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	| relational_expression TOK_GE shift_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::GreaterOrEqual, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	;

equality_expression:
	relational_expression
	| equality_expression TOK_EQ relational_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::Equal, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	| equality_expression TOK_NEQ relational_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::NotEqual, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	;

and_expression:
	equality_expression
	| and_expression '&' equality_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::BitwiseAnd, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	;

exclusive_or_expression:
	and_expression
	| exclusive_or_expression '^' and_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::BitwiseXOr, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	;

inclusive_or_expression:
	exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::BitwiseOr, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	;

logical_and_expression:
	inclusive_or_expression
	| logical_and_expression TOK_BOOL_AND inclusive_or_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::LogicalAnd, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	;

logical_or_expression:
	logical_and_expression
	| logical_or_expression TOK_BOOL_OR logical_and_expression
	{
		$$ = std::make_shared<AST::CBinaryExpression>(AST::EOperator::LogicalOr, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	;

conditional_expression:
	logical_or_expression
	| logical_or_expression '?' expression ':' assignment_expression
	{
		$$ = std::make_shared<AST::CExpression>(AST::EOperator::Conditional, $1, $3, $5);
		$$->SetSourceLocation(yylloc);
	}
	;

assignment_expression:
	conditional_expression
	| unary_expression assignment_operator assignment_expression
	{
		$$ = std::make_shared<AST::CExpression>((AST::EOperator::Enum)$2, $1, $3);
		$$->SetSourceLocation(yylloc);
	}
	;

assignment_operator:
	'='							{ $$ = AST::EOperator::Assign; }
	| TOK_MULTIPLY_ASSIGN		{ $$ = AST::EOperator::MultiplyAssign; }
	| TOK_DIVIDE_ASSIGN			{ $$ = AST::EOperator::DivideAssign; }
	| TOK_MOD_ASSIGN			{ $$ = AST::EOperator::ModuloAssign; }
	| TOK_ADD_ASSIGN			{ $$ = AST::EOperator::AddAssign; }
	| TOK_SUBTRACT_ASSIGN		{ $$ = AST::EOperator::SubtractAssign; }
	| TOK_LSHIFT_ASSIGN			{ $$ = AST::EOperator::LeftShiftAssign; }
	| TOK_RSHIFT_ASSIGN			{ $$ = AST::EOperator::RightShiftAssign; }
	| TOK_AND_ASSIGN			{ $$ = AST::EOperator::AndAssign; }
	| TOK_XOR_ASSIGN			{ $$ = AST::EOperator::XOrAssign; }
	| TOK_OR_ASSIGN				{ $$ = AST::EOperator::OrAssign; }
	;

expression:
	assignment_expression
	{
		$$ = $1;
	}
	| expression ',' assignment_expression
	{
		if($1->GetOperator() != AST::EOperator::Sequence)
		{
			$$ = std::make_shared<AST::CExpression>(AST::EOperator::Sequence);
			$$->SetSourceLocation(yylloc);
			$$->AddChildExpression($1);
		}
		else
		{
			$$ = $1;
		}

		$$->AddChildExpression($3);
	}
	;

constant_expression:
	conditional_expression
	;

function_decl:
	function_prototype ';'
	{
		state->symbols.PopScope();
		$$ = $1;
	}
	;

precision_decl:
	TOK_PRECISION precision_qualifier type_specifier_no_prec ';'
	{
	  
	}
	;

declaration:
	function_decl
	{
		$$ = $1;
	}
	| init_declarator_list ';'
	{
		$$ = $1;
	}
	| precision_decl
	{
		$$ = $1;
	}
	;

function_prototype:
	function_declarator ')'
	{
	}
	| function_declarator ')' ':' any_identifier
	{
		$$ = $1;
		$$->SetReturnSemantic($4);
	}
	;

function_declarator:
	function_header
	| function_header_with_parameters
	;

function_header_with_parameters:
	function_header parameter_declaration
	{
		$$ = $1;
		$$->AddParameter($2);
	}
	| function_header_with_parameters ',' parameter_declaration
	{
		$$ = $1;
		$$->AddParameter($3);
	}
	;

function_header:
	fully_specified_type variable_identifier '('
	{
		$$ = std::make_shared<AST::CFunction>($2, $1);
		$$->SetSourceLocation(yylloc);

		state->symbols.AddFunction(std::make_shared<CFunction>($2));
		state->symbols.PushScope();
	}
	| TOK_INLINE fully_specified_type variable_identifier '('
	{
		$$ = std::make_shared<AST::CFunction>($3, $2);
		$$->SetSourceLocation(yylloc);

		state->symbols.AddFunction(std::make_shared<CFunction>($3));
		state->symbols.PushScope();
	}
	;

parameter_declarator:
	type_specifier any_identifier
	{
		AST::CFullySpecifiedType::TPointer type = std::make_shared<AST::CFullySpecifiedType>($1);
		type->SetSourceLocation(yylloc);

		$$ = std::make_shared<AST::CParameterDeclerator>();
		$$->SetSourceLocation(yylloc);
		$$->SetIdentifier($2);
		$$->SetType(type);
	}
	| type_specifier any_identifier '=' constant_expression
	{
		AST::CFullySpecifiedType::TPointer type = std::make_shared<AST::CFullySpecifiedType>($1);
		type->SetSourceLocation(yylloc);

		$$ = std::make_shared<AST::CParameterDeclerator>();
		$$->SetSourceLocation(yylloc);
		$$->SetIdentifier($2);
		$$->SetType(type);
		$$->SetDefaultValue($4);
	}
	| type_specifier any_identifier ':' any_identifier
	{
		AST::CFullySpecifiedType::TPointer type = std::make_shared<AST::CFullySpecifiedType>($1);
		type->SetSourceLocation(yylloc);

		$$ = std::make_shared<AST::CParameterDeclerator>();
		$$->SetSourceLocation(yylloc);
		$$->SetIdentifier($2);
		$$->SetType(type);
		$$->SetSemantic($4);
	}
	| type_specifier array_identifier
	{
		AST::CFullySpecifiedType::TPointer type = std::make_shared<AST::CFullySpecifiedType>($1);
		type->SetSourceLocation(yylloc);

		$$ = std::make_shared<AST::CParameterDeclerator>();
		$$->SetSourceLocation(yylloc);
		$$->SetIdentifier($2->GetIdentifier());
		$$->SetType(type);
		$$->SetIsArray(true);
		$$->SetArraySize($2->GetArraySize());
	}
	| type_specifier any_identifier '[' constant_expression ']' ':' any_identifier
	{
		AST::CFullySpecifiedType::TPointer type = std::make_shared<AST::CFullySpecifiedType>($1);
		type->SetSourceLocation(yylloc);

		$$ = std::make_shared<AST::CParameterDeclerator>();
		$$->SetSourceLocation(yylloc);
		$$->SetIdentifier($2);
		$$->SetType(type);
		$$->SetIsArray(true);
		$$->SetArraySize($4);
		$$->SetSemantic($7);
	}
	;

parameter_declaration:
	parameter_type_qualifier parameter_qualifier parameter_declarator
	{
		#pragma message("FIXME")
	}
	| parameter_qualifier parameter_type_qualifier parameter_declarator
	{
	   
	}
	| parameter_type_qualifier parameter_qualifier parameter_type_qualifier parameter_declarator
	{
	  
	}
	| parameter_qualifier parameter_declarator
	{
	  
	}
	| parameter_type_qualifier parameter_declarator
	{
	 
	}
	| parameter_declarator
	| parameter_type_qualifier parameter_qualifier parameter_type_specifier
	{
	  
	}
	| parameter_qualifier parameter_type_specifier
	{
	  
	}
	;

parameter_qualifier:
	TOK_IN
	{
		#pragma message("FIXME")
	}
	| TOK_OUT
	{
	  
	}
	| TOK_INOUT
	{
	  
	}
	| TOK_IN TOK_OUT
	{
	
	}
	| TOK_OUT TOK_IN
	{
		
	}
	| TOK_POINT
	{
		
	}
	| TOK_LINE
	{
		
	}
	| TOK_TRIANGLE
	{
		
	}
	| TOK_LINEADJ
	{
		
	}
	| TOK_TRIANGLEADJ
	{
		
	}
	;

parameter_type_specifier:
	type_specifier
	;

init_declarator_list:
	single_declaration
	| init_declarator_list ',' any_identifier
	{
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>($3, false, AST::CExpression::TPointer(), AST::CExpression::TPointer());
		decleration->SetSourceLocation(yylloc);

		$$ = $1;
		$$->AddDecleration(decleration);

		state->symbols.AddVariable(std::make_shared<CVariable>($3));
	}
	| init_declarator_list ',' any_identifier '[' ']'
	{
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>($3, true, AST::CExpression::TPointer(), AST::CExpression::TPointer());
		decleration->SetSourceLocation(yylloc);

		$$ = $1;
		$$->AddDecleration(decleration);

		state->symbols.AddVariable(std::make_shared<CVariable>($3));
	}
	| init_declarator_list ',' array_identifier
	{
		AST::CDecleration::TPointer decleration = $3;

		$$ = $1;
		$$->AddDecleration(decleration);

		state->symbols.AddVariable(std::make_shared<CVariable>($3->GetIdentifier()));
	}
	| init_declarator_list ',' any_identifier '[' ']' '=' initializer
	{
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>($3, true, AST::CExpression::TPointer(), $7);
		decleration->SetSourceLocation(yylloc);

		$$ = $1;
		$$->AddDecleration(decleration);

		state->symbols.AddVariable(std::make_shared<CVariable>($3));
	}
	| init_declarator_list ',' array_identifier '=' initializer
	{
		AST::CDecleration::TPointer decleration = $3;

		$$ = $1;
		$$->AddDecleration(decleration);

		state->symbols.AddVariable(std::make_shared<CVariable>($3->GetIdentifier()));
	}
	| init_declarator_list ',' any_identifier '=' initializer
	{
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>($3, false, AST::CExpression::TPointer(), $5);
		decleration->SetSourceLocation(yylloc);

		$$ = $1;
		$$->AddDecleration(decleration);

		state->symbols.AddVariable(std::make_shared<CVariable>($3));
	}
	;

	// Grammar Note: No 'enum', or 'typedef'.
single_declaration:
	fully_specified_type
	{
		$$ = std::make_shared<AST::CDecleratorList>($1);
		$$->SetSourceLocation(yylloc);
	}
	| fully_specified_type any_identifier
	{
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>($2, false, AST::CExpression::TPointer(), AST::CExpression::TPointer());

		$$ = std::make_shared<AST::CDecleratorList>($1);
		$$->SetSourceLocation(yylloc);
		$$->AddDecleration(decleration);
	}
	| fully_specified_type any_identifier '[' ']'
	{
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>($2, true, AST::CExpression::TPointer(), AST::CExpression::TPointer());

		$$ = std::make_shared<AST::CDecleratorList>($1);
		$$->SetSourceLocation(yylloc);
		$$->AddDecleration(decleration);
	}
	| fully_specified_type array_identifier
	{
		AST::CDecleration::TPointer decleration = $2;

		$$ = std::make_shared<AST::CDecleratorList>($1);
		$$->SetSourceLocation(yylloc);
		$$->AddDecleration(decleration);
	}
	| fully_specified_type any_identifier '[' ']' '=' initializer
	{
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>($2, true, AST::CExpression::TPointer(), $6);

		$$ = std::make_shared<AST::CDecleratorList>($1);
		$$->SetSourceLocation(yylloc);
		$$->AddDecleration(decleration);
	}
	| fully_specified_type array_identifier '=' initializer
	{
		AST::CDecleration::TPointer decleration = $2;
		decleration->SetInitialiser($4);

		$$ = std::make_shared<AST::CDecleratorList>($1);
		$$->SetSourceLocation(yylloc);
		$$->AddDecleration(decleration);
	}
	| fully_specified_type any_identifier '=' initializer
	{
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>($2, false, AST::CExpression::TPointer(), $4);

		$$ = std::make_shared<AST::CDecleratorList>($1);
		$$->SetSourceLocation(yylloc);
		$$->AddDecleration(decleration);
	}
	| TOK_INVARIANT variable_identifier // Vertex only.
	{
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>($2, false, AST::CExpression::TPointer(), AST::CExpression::TPointer());

		$$ = std::make_shared<AST::CDecleratorList>(AST::CFullySpecifiedType::TPointer());
		$$->SetSourceLocation(yylloc);
		$$->SetInvariant(true);
		$$->AddDecleration(decleration);
	}
	;

fully_specified_type:
	type_specifier
	{
		$$ = std::make_shared<AST::CFullySpecifiedType>($1);
		$$->SetSourceLocation(yylloc);
	}
	| type_qualifier type_specifier
	{
		$$ = std::make_shared<AST::CFullySpecifiedType>($1, $2);
		$$->SetSourceLocation(yylloc);
	}
	;

layout_qualifier:
	TOK_LAYOUT '(' layout_qualifier_id_list ')'
	{
		$$ = $3;
	}
	;

layout_qualifier_id_list:
	layout_qualifier_id
	| layout_qualifier_id_list ',' layout_qualifier_id
	{
	   
	}
	;

layout_qualifier_id:
	any_identifier
	{
	 
	}
	| any_identifier '=' TOK_INT_CONSTANT
	{
	   
	}
	;

interpolation_qualifier:
	TOK_LINEAR
	{
	  
	}
	| TOK_NOINTERPOLATION
	{
	 
	}
	| TOK_NOPERSPECTIVE
	{
	  
	}
	;

parameter_type_qualifier:
	interpolation_qualifier
	| TOK_CENTROID interpolation_qualifier
	{
		
	}
	| interpolation_qualifier TOK_CENTROID
	{
		
	}
	| TOK_CENTROID
	{
	
	}
	| TOK_CONST
	{
	  
	}
	;

type_qualifier:
	storage_qualifier
	| layout_qualifier
	| layout_qualifier storage_qualifier
	{
	  
	}
	| interpolation_qualifier
	| interpolation_qualifier storage_qualifier
	{
	  
	}
	| TOK_INVARIANT storage_qualifier
	{
	  
	}
	| TOK_INVARIANT interpolation_qualifier storage_qualifier
	{
	
	}
	| TOK_INVARIANT
	{
	   
	}
	;

storage_qualifier:
	TOK_CONST
	{
	  
	}
	| TOK_VARYING
	{
	 
	}
	| TOK_CENTROID TOK_VARYING
	{
	 
	}
	| TOK_IN
	{
	 
	}
	| TOK_OUT
	{
	  
	}
	| TOK_CENTROID TOK_IN
	{
	  
	}
	| TOK_CENTROID TOK_OUT
	{
	  
	}
	| TOK_UNIFORM
	{
	  
	}
	| TOK_ROWMAJOR
	{
		
	}
	| TOK_COLUMNMAJOR
	{
		
	}
	| TOK_STATIC
	{
		
	}
	| TOK_CONST TOK_STATIC
	{
		
	}
	| TOK_STATIC TOK_CONST
	{
		
	}
	| TOK_GLOBALLYCOHERENT
	{
		
	}
	| TOK_SHARED
	{
		
	}
	;

type_specifier:
	type_specifier_no_prec
	{
		$$ = $1;
	}
	| precision_qualifier type_specifier_no_prec
	{
		$$ = $2;
	}
	;

type_specifier_no_prec:
	type_specifier_nonarray
	| type_specifier_array
	;

type_specifier_array:
	type_specifier_nonarray '[' ']'
	{
		$$ = $1;
		$$->SetIsArray(true);
		$$->SetIsUnSizedArray(true);
	}
	| type_specifier_array '[' ']'
	{
		$$ = $1;
		$$->SetIsUnSizedArray(true);
	}
	| type_specifier_nonarray '[' constant_expression ']'
	{
		$$ = $1;
		$$->SetIsArray(true);
		$$->SetArraySize($3.get());
	}
	| type_specifier_array '[' constant_expression ']'
	{
	  #pragma message("fix me")
	}
	;

type_specifier_nonarray:
	basic_type_specifier_nonarray
	{
		$$ = std::make_shared<AST::CTypeSpecifier>($1);
		$$->SetSourceLocation(yylloc);
	}
	| texture_type_specifier_nonarray
	{
		$$ = std::make_shared<AST::CTypeSpecifier>("float4");
		$$->SetSourceLocation(yylloc);
	}
	| texture_type_specifier_nonarray '<' basic_type_specifier_nonarray ',' TOK_INT_CONSTANT '>'
	{
		$$ = std::make_shared<AST::CTypeSpecifier>($1, $3);
		$$->SetSourceLocation(yylloc);
		$$->SetTextureMSNumSamples($5);
	}
	| texture_type_specifier_nonarray '<' basic_type_specifier_nonarray '>'
	{
		$$ = std::make_shared<AST::CTypeSpecifier>($1, $3);
		$$->SetSourceLocation(yylloc);
	}
	| outputstream_type_specifier_nonarray '<' TOK_TYPE_IDENTIFIER '>'
	{
		$$ = std::make_shared<AST::CTypeSpecifier>($1, $3);
		$$->SetSourceLocation(yylloc);
	}
	| inputpatch_type_specifier_nonarray '<' TOK_TYPE_IDENTIFIER ',' TOK_INT_CONSTANT '>'
	{
		$$ = std::make_shared<AST::CTypeSpecifier>($1, $3);
		$$->SetSourceLocation(yylloc);
		$$->SetPatchSize($5);
	}
	| outputpatch_type_specifier_nonarray '<' TOK_TYPE_IDENTIFIER ',' TOK_INT_CONSTANT '>'
	{
		$$ = std::make_shared<AST::CTypeSpecifier>($1, $1);
		$$->SetSourceLocation(yylloc);
	}
	| struct_specifier
	{
		$$ = std::make_shared<AST::CTypeSpecifier>($1);
		$$->SetSourceLocation(yylloc);
	}
	| TOK_TYPE_IDENTIFIER
	{
		$$ = std::make_shared<AST::CTypeSpecifier>($1);
		$$->SetSourceLocation(yylloc);
	}
	;

basic_type_specifier_nonarray:
	TOK_VOID					{ $$ = &AST::CPrecisionType::Void; }
	| TOK_FLOAT					{ $$ = &AST::CPrecisionType::Float; }
	| TOK_HALF					{ $$ = &AST::CPrecisionType::Half; }
	| TOK_FIXED					{ $$ = &AST::CPrecisionType::Fixed; }
	| TOK_INT					{ $$ = &AST::CPrecisionType::Int; }
	| TOK_UINT					{ $$ = &AST::CPrecisionType::UInt; }
	| TOK_BOOL					{ $$ = &AST::CPrecisionType::Bool; }
	| TOK_FLOAT_VEC2			{ $$ = &AST::CPrecisionType::Float2; }
	| TOK_FLOAT_VEC3			{ $$ = &AST::CPrecisionType::Float3; }
	| TOK_FLOAT_VEC4			{ $$ = &AST::CPrecisionType::Float4; }
	| TOK_HALF_VEC2				{ $$ = &AST::CPrecisionType::Half2; }
	| TOK_HALF_VEC3				{ $$ = &AST::CPrecisionType::Half3; }
	| TOK_HALF_VEC4				{ $$ = &AST::CPrecisionType::Half4; }
	| TOK_FIXED_VEC2			{ $$ = &AST::CPrecisionType::Fixed2; }
	| TOK_FIXED_VEC3			{ $$ = &AST::CPrecisionType::Fixed3; }
	| TOK_FIXED_VEC4			{ $$ = &AST::CPrecisionType::Fixed4; }
	| TOK_BOOL_VEC2				{ $$ = &AST::CPrecisionType::Bool2; }
	| TOK_BOOL_VEC3				{ $$ = &AST::CPrecisionType::Bool3; }
	| TOK_BOOL_VEC4				{ $$ = &AST::CPrecisionType::Bool4; }
	| TOK_INT_VEC2				{ $$ = &AST::CPrecisionType::Int2; }
	| TOK_INT_VEC3				{ $$ = &AST::CPrecisionType::Int3; }
	| TOK_INT_VEC4				{ $$ = &AST::CPrecisionType::Int4; }
	| TOK_UINT_VEC2				{ $$ = &AST::CPrecisionType::UInt2; }
	| TOK_UINT_VEC3				{ $$ = &AST::CPrecisionType::UInt3; }
	| TOK_UINT_VEC4				{ $$ = &AST::CPrecisionType::UInt4; }
	| TOK_FLOAT_VEC2X2			{ $$ = &AST::CPrecisionType::Float2x2; }
	| TOK_FLOAT_VEC2X3			{ $$ = &AST::CPrecisionType::Float2x3; }
	| TOK_FLOAT_VEC2X4			{ $$ = &AST::CPrecisionType::Float2x4; }
	| TOK_FLOAT_VEC3X2			{ $$ = &AST::CPrecisionType::Float3x2; }
	| TOK_FLOAT_VEC3X3			{ $$ = &AST::CPrecisionType::Float3x3; }
	| TOK_FLOAT_VEC3X4			{ $$ = &AST::CPrecisionType::Float3x4; }
	| TOK_FLOAT_VEC4X2			{ $$ = &AST::CPrecisionType::Float4x2; }
	| TOK_FLOAT_VEC4X3			{ $$ = &AST::CPrecisionType::Float4x3; }
	| TOK_FLOAT_VEC4X4			{ $$ = &AST::CPrecisionType::Float4x4; }
	| TOK_HALF_VEC2X2			{ $$ = &AST::CPrecisionType::Half2x2; }
	| TOK_HALF_VEC2X3			{ $$ = &AST::CPrecisionType::Half2x3; }
	| TOK_HALF_VEC2X4			{ $$ = &AST::CPrecisionType::Half2x4; }
	| TOK_HALF_VEC3X2			{ $$ = &AST::CPrecisionType::Half3x2; }
	| TOK_HALF_VEC3X3			{ $$ = &AST::CPrecisionType::Half3x3; }
	| TOK_HALF_VEC3X4			{ $$ = &AST::CPrecisionType::Half3x4; }
	| TOK_HALF_VEC4X2			{ $$ = &AST::CPrecisionType::Half4x2; }
	| TOK_HALF_VEC4X3			{ $$ = &AST::CPrecisionType::Half4x3; }
	| TOK_HALF_VEC4X4			{ $$ = &AST::CPrecisionType::Half4x4; }
	| TOK_FIXED_VEC2X2			{ $$ = &AST::CPrecisionType::Fixed2x2; }
	| TOK_FIXED_VEC2X3			{ $$ = &AST::CPrecisionType::Fixed2x3; }
	| TOK_FIXED_VEC2X4			{ $$ = &AST::CPrecisionType::Fixed2x4; }
	| TOK_FIXED_VEC3X2			{ $$ = &AST::CPrecisionType::Fixed3x2; }
	| TOK_FIXED_VEC3X3			{ $$ = &AST::CPrecisionType::Fixed3x3; }
	| TOK_FIXED_VEC3X4			{ $$ = &AST::CPrecisionType::Fixed3x4; }
	| TOK_FIXED_VEC4X2			{ $$ = &AST::CPrecisionType::Fixed4x2; }
	| TOK_FIXED_VEC4X3			{ $$ = &AST::CPrecisionType::Fixed4x3; }
	| TOK_FIXED_VEC4X4			{ $$ = &AST::CPrecisionType::Fixed4x4; }
	| TOK_SAMPLERSTATE			{ $$ = &AST::CPrecisionType::SamplerState; }
	| TOK_SAMPLER_CMP_STATE		{ $$ = &AST::CPrecisionType::SamplerComparisonState; }
	;


texture_type_specifier_nonarray:
	TOK_BUFFER					{ $$ = "Buffer"; }
	| TOK_TEXTURE1D				{ $$ = "Texture1D"; }
	| TOK_TEXTURE1D_ARRAY		{ $$ = "Texture1DArray"; }
	| TOK_TEXTURE2D				{ $$ = "Texture2D"; }
	| TOK_TEXTURE2D_ARRAY		{ $$ = "Texture2DArray"; }
	| TOK_TEXTURE2DMS			{ $$ = "Texture2DMS"; }
	| TOK_TEXTURE2DMS_ARRAY		{ $$ = "Texture2DMSArray"; }
	| TOK_TEXTURE3D				{ $$ = "Texture3D"; }
	| TOK_TEXTURECUBE			{ $$ = "TextureCube"; }
	| TOK_TEXTURECUBE_ARRAY		{ $$ = "TextureCubeArray"; }
	| TOK_RWBUFFER				{ $$ = "RWBuffer"; }
	| TOK_RWTEXTURE1D			{ $$ = "RWTexture1D"; }
	| TOK_RWTEXTURE1D_ARRAY		{ $$ = "RWTexture1DArray"; }
	| TOK_RWTEXTURE2D			{ $$ = "RWTexture2D"; }
	| TOK_RWTEXTURE2D_ARRAY		{ $$ = "RWTexture2DArray"; }
	| TOK_RWTEXTURE3D			{ $$ = "RWTexture3D"; }
	;

outputstream_type_specifier_nonarray:
	TOK_POINTSTREAM				{ $$ = "PointStream"; }
	| TOK_LINESTREAM			{ $$ = "LinearStream"; }
	| TOK_TRIANGLESTREAM		{ $$ = "TriangleStream"; }
	;

inputpatch_type_specifier_nonarray:
	TOK_INPUTPATCH				{ $$ = "InputPatch"; }
	;

outputpatch_type_specifier_nonarray:
	TOK_OUTPUTPATCH				{ $$ = "OutputPatch"; }
	;

precision_qualifier:
	TOK_HIGHP	  {
		    
		  }
	| TOK_MEDIUMP {
		    
		  }
	| TOK_LOWP	  {
		    
		  }
	;

struct_specifier:
	TOK_STRUCT any_identifier '{' struct_declaration_list '}'
	{
		$$ = std::make_shared<AST::CStructSpecifier>($2, $4);
		$$->SetSourceLocation(yylloc);

		state->symbols.AddType(std::make_shared<CType>($2));
	}
	| TOK_STRUCT any_identifier ':' TOK_TYPE_IDENTIFIER '{' struct_declaration_list '}'
	{
		$$ = std::make_shared<AST::CStructSpecifier>($2, $4, $6);
		$$->SetSourceLocation(yylloc);
	}
	| TOK_STRUCT '{' struct_declaration_list '}'
	{
		$$ = std::make_shared<AST::CStructSpecifier>("", $3);
		$$->SetSourceLocation(yylloc);
	}
	| TOK_STRUCT any_identifier '{' '}'
	{
		$$ = std::make_shared<AST::CStructSpecifier>($2, AST::CNode::TPointer());
		$$->SetSourceLocation(yylloc);

		state->symbols.AddType(std::make_shared<CType>($2));
	}
	| TOK_STRUCT any_identifier ':' TOK_TYPE_IDENTIFIER '{' '}'
	{
		$$ = std::make_shared<AST::CStructSpecifier>($2, $4, AST::CNode::TPointer());
		$$->SetSourceLocation(yylloc);

		state->symbols.AddType(std::make_shared<CType>($2));
	}
	| TOK_STRUCT '{' '}'
	{
		$$ = std::make_shared<AST::CStructSpecifier>("", AST::CNode::TPointer());
		$$->SetSourceLocation(yylloc);
	}
	;

cbuffer_declaration:
	TOK_CBUFFER any_identifier '{' struct_declaration_list '}'
	{
		$$ = std::make_shared<AST::CCBufferSpecifier>($2, $4);
		$$->SetSourceLocation(yyloc);
	}
	;

struct_declaration_list:
	struct_declaration
	{
		$$ = $1;
		$1->AddSelfLink();
	}
	| struct_declaration_list struct_declaration
	{
		$$ = $1;
		$$->AddLink($2);
	}
	;

struct_declaration:
	struct_type_specifier struct_declarator_list ';'
	{
	   #pragma message("Fix me")
	}
	;

struct_type_specifier:
	type_specifier
	{
		$$ = std::make_shared<AST::CFullySpecifiedType>($1);
		$$->SetSourceLocation(yyloc);
	}
	| struct_type_qualifier type_specifier
	{
		$$ = std::make_shared<AST::CFullySpecifiedType>($1, $2);
		$$->SetSourceLocation(yyloc);
	}
	;

struct_type_qualifier:
	interpolation_qualifier
	| TOK_CENTROID interpolation_qualifier
	{
		#pragma message("Fix em")
	}
	| interpolation_qualifier TOK_CENTROID
	{
		
	}
	| TOK_CENTROID
	{
		
	}
	;

struct_declarator_list:
	struct_declarator
	{
		$$ = $1;
		$1->AddSelfLink();
	}
	| struct_declarator_list ',' struct_declarator
	{
		$$ = $1;
		$$->AddLink($3);
	}
	;

struct_declarator:
	any_identifier
	{
		$$ = std::make_shared<AST::CDecleration>($1, false, AST::CExpression::TPointer(), AST::CExpression::TPointer());
		$$->SetSourceLocation(yyloc);
		state->symbols.AddVariable(std::make_shared<CVariable>($1));
	}
	| array_identifier
	{
		$$ = $1;
	}
	| any_identifier ':' any_identifier
	{
		$$ = std::make_shared<AST::CDecleration>($1, false, AST::CExpression::TPointer(), AST::CExpression::TPointer());
		$$->SetSourceLocation(yyloc);
		$$->SetSemantec($3);
		state->symbols.AddVariable(std::make_shared<CVariable>($1));
	}
	| any_identifier '[' constant_expression ']' ':' any_identifier
	{
		$$ = std::make_shared<AST::CDecleration>($1, true, $3, AST::CExpression::TPointer());
		$$->SetSourceLocation(yyloc);
		$$->SetSemantec($6);
	}
	;

array_identifier:
	any_identifier '[' constant_expression ']'
	{
		$$ = std::make_shared<AST::CDecleration>($1, true, $3, AST::CExpression::TPointer());
		$$->SetSourceLocation(yyloc);
	}
	| array_identifier '[' constant_expression ']'
	{
		$$ = $1;
		$3->AddLink($$->GetArraySize());
		$$->SetArraySize($3);
	}

initializer:
	assignment_expression
	| '{' initializer_list '}'
	{
		$$ = std::make_shared<AST::CInitialiserListExpression>();
		$$->AddChildExpression($2);
	}
	;

initializer_list:
	initializer
	{
		$$ = $1;
		$$->AddSelfLink();
	}
	| initializer_list ',' initializer
	{
		$$ = $1;
		$$->AddLink($3);
	}
	| initializer_list ','
	{
		$$ = $1;
	}
	;

declaration_statement:
	declaration
	;

	// Grammar Note: labeled statements for SWITCH only; 'goto' is not
	// supported.
statement:
	compound_statement	{  }
	| simple_statement
	| attribute_list compound_statement
	{
		#pragma message("Fix")
	}
	| attribute_list simple_statement
	{
		$$ = $2;
		$$->AddAttribute($1);
	}
	;

simple_statement:
	declaration_statement
	| expression_statement
	| selection_statement
	| switch_statement
	| iteration_statement
	| jump_statement
	;

compound_statement:
	'{' '}'
	{
		$$ = std::make_shared<AST::CCompoundStatement>(true);
		$$->SetSourceLocation(yyloc);
		state->symbols.PopScope();
	}
	| '{'
	{
		state->symbols.PushScope();
	}
	statement_list '}'
	{
		$$ = std::make_shared<AST::CCompoundStatement>(true, std::move($3));
		$$->SetSourceLocation(yyloc);
		state->symbols.PopScope();
	}
	;

statement_no_new_scope:
	compound_statement_no_new_scope { $$ = $1; }
	| simple_statement
	;

compound_statement_no_new_scope:
	'{' '}'
	{
		$$ = std::make_shared<AST::CCompoundStatement>(false);
		$$->SetSourceLocation(yyloc);
	}
	| '{' statement_list '}'
	{
		$$ = std::make_shared<AST::CCompoundStatement>(false, std::move($2));
		$$->SetSourceLocation(yyloc);
	}
	;

statement_list:
	statement
	{
		//#pragma message("Fix me2")
		$$.push_back($1);
	}
	| statement_list statement
	{
		#pragma message("Fix me")
		$$.push_back($2);
	}
	;

expression_statement:
	';'
	{
		$$ = std::make_shared<AST::CExpressionStatement>(AST::CExpression::TPointer());
		$$->SetSourceLocation(yyloc);
	}
	| expression ';'
	{
		$$ = std::make_shared<AST::CExpressionStatement>($1);
		$$->SetSourceLocation(yyloc);
	}
	;

selection_statement:
	TOK_IF '(' expression ')' selection_rest_statement
	{
		$$ = std::make_shared<AST::CSelectionStatement>($3, $5.thenStatement, $5.elseStatement);
		$$->SetSourceLocation(yyloc);
	}
	;

selection_rest_statement:
	statement TOK_ELSE statement
	{
		$$.thenStatement = $1;
		$$.elseStatement = $3;
	}
	| statement
	{
		$$.thenStatement = $1;
		$$.elseStatement = AST::CNode::TPointer();
	}
	;

condition:
	expression
	{
		$$ = $1;
	}
	| fully_specified_type any_identifier '=' initializer
	{
		AST::CDecleration::TPointer decl = std::make_shared<AST::CDecleration>($2, false, AST::CExpression::TPointer(), $4);
		decl->SetSourceLocation(yyloc);
		AST::CDecleratorList::TPointer declerator = std::make_shared<AST::CDecleratorList>($1);
		declerator->SetSourceLocation(yyloc);

		declerator->AddDecleration(decl);
		$$ = declerator;
	}
	;

/*
 * siwtch_statement grammar is based on the syntax described in the body
 * of the GLSL spec, not in it's appendix!!!
 */
switch_statement:
	TOK_SWITCH '(' expression ')' switch_body
	{
	  #pragma message("Fix me");
	}
	;

switch_body:
	'{' '}'
	{
	  #pragma message("Fix me");
	}
	| '{' case_statement_list '}'
	{
	 #pragma message("Fix me");
	}
	;

case_label:
	TOK_CASE expression ':'
	{
	  #pragma message("Fix me");
	}
	| TOK_DEFAULT ':'
	{
	  #pragma message("Fix me");
	}
	;

case_label_list:
	case_label
	{
	  #pragma message("Fix me");
	}
	| case_label_list case_label
	{
	   #pragma message("Fix me");
	}
	;

case_statement:
	case_label_list statement
	{
	  #pragma message("Fix me");
	}
	| case_statement statement
	{
	  #pragma message("Fix me");
	}
	;

case_statement_list:
	case_statement
	{
	   #pragma message("Fix me");
	}
	| case_statement_list case_statement
	{
	  #pragma message("Fix me");
	}
	;

iteration_statement:
	TOK_WHILE '(' condition ')' statement_no_new_scope
	{
	  #pragma message("Fix me");
	}
	| TOK_DO statement TOK_WHILE '(' expression ')' ';'
	{
	  #pragma message("Fix me");
	}
	| TOK_FOR '(' for_init_statement for_rest_statement ')' statement_no_new_scope
	{
	 #pragma message("Fix me");
	}
	;

for_init_statement:
	expression_statement
	| declaration_statement
	;

conditionopt:
	condition
	| /* empty */
	{
	  #pragma message("Fix me");
	}
	;

for_rest_statement:
	conditionopt ';'
	{
	 #pragma message("Fix me");
	}
	| conditionopt ';' expression
	{
	 #pragma message("Fix me");
	}
	;

	// Grammar Note: No 'goto'. Gotos are not supported.
jump_statement:
	TOK_CONTINUE ';' 
	{
		$$ = std::make_shared<AST::CFlowControlStatement>(AST::CFlowControlStatement::EType::Continue);
		$$->SetSourceLocation(yyloc);
	}
	| TOK_BREAK ';'
	{
		$$ = std::make_shared<AST::CFlowControlStatement>(AST::CFlowControlStatement::EType::Break);
		$$->SetSourceLocation(yyloc);
	}
	| TOK_RETURN ';'
	{
		$$ = std::make_shared<AST::CFlowControlStatement>(AST::CFlowControlStatement::EType::Return);
		$$->SetSourceLocation(yyloc);
	}
	| TOK_RETURN expression ';'
	{
		$$ = std::make_shared<AST::CFlowControlStatement>(AST::CFlowControlStatement::EType::Return, $2);
		$$->SetSourceLocation(yyloc);
	}
	| TOK_DISCARD ';' // Fragment shader only.
	{
		$$ = std::make_shared<AST::CFlowControlStatement>(AST::CFlowControlStatement::EType::Discard);
		$$->SetSourceLocation(yyloc);
	}
	;

external_declaration:
	function_definition		{ $$ = $1; }
	| global_declaration	{ $$ = $1; }
	;

attribute_arg:
	constant_expression
	{
		#pragma message("Fix me");
	}
	| TOK_STRING_CONSTANT
	{
		#pragma message("Fix me");
	}
	;

attribute_arg_list:
	attribute_arg
	{
		#pragma message("Fix me");
	}
	| attribute_arg_list ',' attribute_arg
	{
	#pragma message("Fix me");
	}
	;

attribute:
	'[' any_identifier ']'
	{
		#pragma message("Fix me");
	}
	| '[' basic_type_specifier_nonarray ']'
	{
		#pragma message("Fix me");
	}
	| '[' any_identifier '(' attribute_arg_list ')' ']'
	{
		#pragma message("Fix me");
	}
	| '[' basic_type_specifier_nonarray '(' attribute_arg_list ')' ']'
	{
		#pragma message("Fix me");
	}
	;

attribute_list:
	attribute_list attribute
	{
		$$ = $1;
		$$->AddLink($2);
	}
	| attribute
	{
		$$ = $1;
	}
	;

function_definition:
	function_prototype compound_statement_no_new_scope
	{
		$$ = std::make_shared<AST::CFunctionDefinition>($1, $2);
		$$->SetSourceLocation(yyloc);
		state->symbols.PopScope();
	}
	| attribute_list function_prototype compound_statement_no_new_scope
	{
		$$ = std::make_shared<AST::CFunctionDefinition>($2, $3);
		$$->SetSourceLocation(yyloc);
		$$->AddAttribute($1);
		state->symbols.PopScope();

		$$->AddAttribute($1);
	}
	;

global_declaration:
	function_decl
	{
		$$ = $1;
	}
	| init_declarator_list ';'
	{
		
	}
	| precision_decl
	{
		$$ = $1;
	}
	| cbuffer_declaration
	{
	   $$ = $1;
	}
	;


%%