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
%type <node> statement_list
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
%type <PrecisionType> basic_type_specifier_nonarray
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
/*%type <selection_rest_statement> selection_rest_statement*/
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
	   
	}
	| external_declaration_list external_declaration
	{
	   
	}
	;

variable_identifier:
	TOK_IDENTIFIER
	| TOK_NEW_IDENTIFIER
	;

primary_expression:
	variable_identifier
	{
		$$ = std::make_shared<AST::CExpression();
		$$->SetLocation(yylloc);
		$$->MakeIdentifier($1);
	}
	| TOK_INT_CONSTANT
	{
		$$ = std::make_shared<AST::CExpression();
		$$->SetLocation(yylloc);
		$$->MakeIntConstant($1);
	}
	| TOK_UINT_CONSTANT
	{
		$$ = std::make_shared<AST::CExpression();
		$$->SetLocation(yylloc);
		$$->MakeUIntConstant($1);
	}
	| TOK_FLOAT_CONSTANT
	{
		$$ = std::make_shared<AST::CExpression();
		$$->SetLocation(yylloc);
		$$->MakeFloatConstant($1);
	}
	| TOK_BOOL_CONSTANT
	{
		$$ = std::make_shared<AST::CExpression();
		$$->SetLocation(yylloc);
		$$->MakeBoolConstant($1);
	}
	| '(' expression ')'
	{
		$$ = $1;
	}
	;

postfix_expression:
	primary_expression
	| postfix_expression '[' integer_expression ']'
	{
		$$ = std::make_shared<AST::CExpression(AST::EOperation::ArrayIndex, $1, $3);
		$$->SetLocation(yylloc);
	}
	| function_call
	{
		$$ = $1;
	}
	| postfix_expression '.' any_identifier
	{
		$$ = std::make_shared<AST::CExpression(AST::EOperation::FieldSelection, $1);
		$$->SetLocation(yylloc);
		$$->SetIdentifier($3);
	}
	| postfix_expression TOK_INCREMENT
	{
		$$ = std::make_shared<AST::CExpression(AST::EOperation::PostIncrement, $1);
		$$->SetLocation(yylloc);
	}
	| postfix_expression TOK_DECREMENT
	{
		$$ = std::make_shared<AST::CExpression(AST::EOperation::PostDecrement, $1);
		$$->SetLocation(yylloc);
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
	   
	}
	| function_call_header_with_parameters ',' assignment_expression
	{
	  
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
	  
   	}
	| variable_identifier
	{
	  
   	}
	| TOK_FIELD_SELECTION
	{
	   
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
	
	   
	}
	| method_call_header_with_parameters ',' assignment_expression
	{
	 
	  
	}
	;

	// Grammar Note: Constructors look like methods, but lexical 
	// analysis recognized most of them as keywords. They are now
	// recognized through "type_specifier".
method_call_header:
	variable_identifier '('
	{
	  
   	}
	;

	// Grammar Note: No traditional style type casts.
unary_expression:
	postfix_expression
	| TOK_INCREMENT unary_expression
	{
	  
	}
	| TOK_DECREMENT unary_expression
	{
	  
	}
	| unary_operator unary_expression
	{
	  
	}
	| '(' type_specifier_nonarray ')' unary_expression
	{
		
	}
	;

	// Grammar Note: No '*' or '&' unary ops. Pointers are not supported.
unary_operator:
	'+'	{  }
	| '-'	{ }
	| '!'	{  }
	| '~'	{  }
	;

multiplicative_expression:
	unary_expression
	| multiplicative_expression '*' unary_expression
	{
	  
	}
	| multiplicative_expression '/' unary_expression
	{
	   
	}
	| multiplicative_expression '%' unary_expression
	{
	  
	}
	;

additive_expression:
	multiplicative_expression
	| additive_expression '+' multiplicative_expression
	{
	  
	}
	| additive_expression '-' multiplicative_expression
	{
	   
	}
	;

shift_expression:
	additive_expression
	| shift_expression TOK_LSHIFT additive_expression
	{
	   
	}
	| shift_expression TOK_RSHIFT additive_expression
	{
	  
	}
	;

relational_expression:
	shift_expression
	| relational_expression '<' shift_expression
	{
	  
	}
	| relational_expression '>' shift_expression
	{
	   
	}
	| relational_expression TOK_LE shift_expression
	{
	  
	}
	| relational_expression TOK_GE shift_expression
	{
	  
	}
	;

equality_expression:
	relational_expression
	| equality_expression TOK_EQ relational_expression
	{
	  
	}
	| equality_expression TOK_NEQ relational_expression
	{
	   
	}
	;

and_expression:
	equality_expression
	| and_expression '&' equality_expression
	{
	 
	}
	;

exclusive_or_expression:
	and_expression
	| exclusive_or_expression '^' and_expression
	{
	  
	}
	;

inclusive_or_expression:
	exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	{
	  
	}
	;

logical_and_expression:
	inclusive_or_expression
	| logical_and_expression TOK_BOOL_AND inclusive_or_expression
	{
	  
	}
	;

logical_or_expression:
	logical_and_expression
	| logical_or_expression TOK_BOOL_OR logical_and_expression
	{
	  
	}
	;

conditional_expression:
	logical_or_expression
	| logical_or_expression '?' expression ':' assignment_expression
	{
	  
	}
	;

assignment_expression:
	conditional_expression
	| unary_expression assignment_operator assignment_expression
	{
	  
	}
	;

assignment_operator:
	'='		{  }
	| TOK_MULTIPLY_ASSIGN	{}
	| TOK_DIVIDE_ASSIGN	{  }
	| TOK_MOD_ASSIGN	{  }
	| TOK_ADD_ASSIGN	{  }
	| TOK_SUBTRACT_ASSIGN	{  }
	| TOK_LSHIFT_ASSIGN	{ }
	| TOK_RSHIFT_ASSIGN	{ }
	| TOK_AND_ASSIGN	{  }
	| TOK_XOR_ASSIGN	{  }
	| TOK_OR_ASSIGN	{ }
	;

expression:
	assignment_expression
	{
	  
	}
	| expression ',' assignment_expression
	{
	  
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
		
	}
	| init_declarator_list ';'
	{
	   
	}
	| precision_decl
	{
	  
	}
	;

function_prototype:
	function_declarator ')'
	{
	}
	| function_declarator ')' ':' any_identifier
	{
		
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
	  
	}
	| type_specifier any_identifier '=' constant_expression
	{
		
	}
	| type_specifier any_identifier ':' any_identifier
	{
	
		
	}
	| type_specifier array_identifier
	{
	   
	}
	| type_specifier any_identifier '[' constant_expression ']' ':' any_identifier
	{
	  
	}
	;

parameter_declaration:
	parameter_type_qualifier parameter_qualifier parameter_declarator
	{
	  
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
	  
	}
	| init_declarator_list ',' any_identifier '[' ']'
	{
	  
	}
	| init_declarator_list ',' array_identifier
	{
	  
	}
	| init_declarator_list ',' any_identifier '[' ']' '=' initializer
	{
	   
	}
	| init_declarator_list ',' array_identifier '=' initializer
	{
	  
	}
	| init_declarator_list ',' any_identifier '=' initializer
	{
	  
	}
	;

	// Grammar Note: No 'enum', or 'typedef'.
single_declaration:
	fully_specified_type
	{
	  
	}
	| fully_specified_type any_identifier
	{
	  
	}
	| fully_specified_type any_identifier '[' ']'
	{
	  
	}
	| fully_specified_type array_identifier
	{
	 
	}
	| fully_specified_type any_identifier '[' ']' '=' initializer
	{
	  
	}
	| fully_specified_type array_identifier '=' initializer
	{
	 
	}
	| fully_specified_type any_identifier '=' initializer
	{
	  
	}
	| TOK_INVARIANT variable_identifier // Vertex only.
	{
	   
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
	 
	}
	;

type_specifier_no_prec:
	type_specifier_nonarray
	| type_specifier_array
	;

type_specifier_array:
	type_specifier_nonarray '[' ']'
	{
	  
	}
	| type_specifier_array '[' ']'
	{
	  
	}
	| type_specifier_nonarray '[' constant_expression ']'
	{
	  
	}
	| type_specifier_array '[' constant_expression ']'
	{
	  
	}
	;

type_specifier_nonarray:
	basic_type_specifier_nonarray
	{
	 
	}
	| texture_type_specifier_nonarray
	{
		
	}
	| texture_type_specifier_nonarray '<' basic_type_specifier_nonarray ',' TOK_INT_CONSTANT '>'
	{
		
	}
	| texture_type_specifier_nonarray '<' basic_type_specifier_nonarray '>'
	{
		
	}
	| outputstream_type_specifier_nonarray '<' TOK_TYPE_IDENTIFIER '>'
	{
		
	}
	| inputpatch_type_specifier_nonarray '<' TOK_TYPE_IDENTIFIER ',' TOK_INT_CONSTANT '>'
	{
		
	}
	| outputpatch_type_specifier_nonarray '<' TOK_TYPE_IDENTIFIER ',' TOK_INT_CONSTANT '>'
	{
		
	}
	| struct_specifier
	{
	  
	}
	| TOK_TYPE_IDENTIFIER
	{
	  
	}
	;

basic_type_specifier_nonarray:
	TOK_VOID		{  }
	| TOK_FLOAT		{  }
	| TOK_HALF		{ }
	| TOK_FIXED		{  }
	| TOK_INT		{  }
	| TOK_UINT		{  }
	| TOK_BOOL		{  }
	| TOK_FLOAT_VEC2	{  }
	| TOK_FLOAT_VEC3	{  }
	| TOK_FLOAT_VEC4	{  }
	| TOK_HALF_VEC2			{  }
	| TOK_HALF_VEC3			{  }
	| TOK_HALF_VEC4			{  }
	| TOK_FIXED_VEC2			{  }
	| TOK_FIXED_VEC3			{ }
	| TOK_FIXED_VEC4			{ }
	| TOK_BOOL_VEC2			{  }
	| TOK_BOOL_VEC3			{  }
	| TOK_BOOL_VEC4			{  }
	| TOK_INT_VEC2			{ }
	| TOK_INT_VEC3			{ }
	| TOK_INT_VEC4			{ }
	| TOK_UINT_VEC2			{ }
	| TOK_UINT_VEC3			{ }
	| TOK_UINT_VEC4			{ }
	| TOK_FLOAT_VEC2X2		{ }
	| TOK_FLOAT_VEC2X3		{  }
	| TOK_FLOAT_VEC2X4		{  }
	| TOK_FLOAT_VEC3X2		{  }
	| TOK_FLOAT_VEC3X3		{  }
	| TOK_FLOAT_VEC3X4		{  }
	| TOK_FLOAT_VEC4X2		{  }
	| TOK_FLOAT_VEC4X3		{  }
	| TOK_FLOAT_VEC4X4		{  }
	| TOK_HALF_VEC2X2		{ }
	| TOK_HALF_VEC2X3		{ }
	| TOK_HALF_VEC2X4		{ }
	| TOK_HALF_VEC3X2		{ }
	| TOK_HALF_VEC3X3		{ }
	| TOK_HALF_VEC3X4		{ }
	| TOK_HALF_VEC4X2		{ }
	| TOK_HALF_VEC4X3		{ }
	| TOK_HALF_VEC4X4		{ }
	| TOK_FIXED_VEC2X2		{  }
	| TOK_FIXED_VEC2X3		{  }
	| TOK_FIXED_VEC2X4		{  }
	| TOK_FIXED_VEC3X2		{  }
	| TOK_FIXED_VEC3X3		{  }
	| TOK_FIXED_VEC3X4		{  }
	| TOK_FIXED_VEC4X2		{  }
	| TOK_FIXED_VEC4X3		{  }
	| TOK_FIXED_VEC4X4		{  }
	| TOK_SAMPLERSTATE	{  }
	| TOK_SAMPLER_CMP_STATE { }
	;


texture_type_specifier_nonarray:
	TOK_BUFFER					{ }
	| TOK_TEXTURE1D				{ }
	| TOK_TEXTURE1D_ARRAY		{  }
	| TOK_TEXTURE2D				{ }
	| TOK_TEXTURE2D_ARRAY		{  }
	| TOK_TEXTURE2DMS			{ }
	| TOK_TEXTURE2DMS_ARRAY		{  }
	| TOK_TEXTURE3D				{  }
	| TOK_TEXTURECUBE			{  }
	| TOK_TEXTURECUBE_ARRAY		{ }
	| TOK_RWBUFFER				{ }
	| TOK_RWTEXTURE1D			{ }
	| TOK_RWTEXTURE1D_ARRAY		{ }
	| TOK_RWTEXTURE2D			{  }
	| TOK_RWTEXTURE2D_ARRAY		{ }
	| TOK_RWTEXTURE3D			{  }
	;

outputstream_type_specifier_nonarray:
	TOK_POINTSTREAM				{  }
	| TOK_LINESTREAM			{ }
	| TOK_TRIANGLESTREAM		{  }
	;

inputpatch_type_specifier_nonarray:
	TOK_INPUTPATCH				{  }
	;

outputpatch_type_specifier_nonarray:
	TOK_OUTPUTPATCH				{ }
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
	 
	}
	| TOK_STRUCT any_identifier ':' TOK_TYPE_IDENTIFIER '{' struct_declaration_list '}'
	{
	  
	}
	| TOK_STRUCT '{' struct_declaration_list '}'
	{
	 
	}
	| TOK_STRUCT any_identifier '{' '}'
	{
		
	}
	| TOK_STRUCT any_identifier ':' TOK_TYPE_IDENTIFIER '{' '}'
	{
		
	}
	| TOK_STRUCT '{' '}'
	{
		
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
	   
	}
	;

struct_type_specifier:
	type_specifier
	{
		
	}
	| struct_type_qualifier type_specifier
	{
		
	}
	;

struct_type_qualifier:
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
	;

struct_declarator_list:
	struct_declarator
	{
	  
	}
	| struct_declarator_list ',' struct_declarator
	{
	  
	}
	;

struct_declarator:
	any_identifier
	{
	  
	}
	| array_identifier
	{
	 
	}
	| any_identifier ':' any_identifier
	{
		
	}
	| any_identifier '[' constant_expression ']' ':' any_identifier
	{
	  
	}
	;

array_identifier:
	any_identifier '[' constant_expression ']'
	{
	  
	}
	| array_identifier '[' constant_expression ']'
	{
	  
	}

initializer:
	assignment_expression
	| '{' initializer_list '}'
	{
		
	}
	;

initializer_list:
	initializer
	{
		
	}
	| initializer_list ',' initializer
	{
		
	}
	| initializer_list ','
	{
	
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
		
	}
	| attribute_list simple_statement
	{
		
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
	  
	}
	| '{'
	{
	   
	}
	statement_list '}'
	{
	  
	}
	;

statement_no_new_scope:
	compound_statement_no_new_scope {  }
	| simple_statement
	;

compound_statement_no_new_scope:
	'{' '}'
	{
	  
	}
	| '{' statement_list '}'
	{
	   
	}
	;

statement_list:
	statement
	{
	  
	}
	| statement_list statement
	{
	  
	}
	;

expression_statement:
	';'
	{
	 
	}
	| expression ';'
	{
	 
	}
	;

selection_statement:
	TOK_IF '(' expression ')' selection_rest_statement
	{
	   
	}
	;

selection_rest_statement:
	statement TOK_ELSE statement
	{
	  
	}
	| statement
	{
	  
	}
	;

condition:
	expression
	{
	  
	}
	| fully_specified_type any_identifier '=' initializer
	{
	  
	}
	;

/*
 * siwtch_statement grammar is based on the syntax described in the body
 * of the GLSL spec, not in it's appendix!!!
 */
switch_statement:
	TOK_SWITCH '(' expression ')' switch_body
	{
	  
	}
	;

switch_body:
	'{' '}'
	{
	  
	}
	| '{' case_statement_list '}'
	{
	 
	}
	;

case_label:
	TOK_CASE expression ':'
	{
	  
	}
	| TOK_DEFAULT ':'
	{
	  
	}
	;

case_label_list:
	case_label
	{
	  
	}
	| case_label_list case_label
	{
	   
	}
	;

case_statement:
	case_label_list statement
	{
	  
	}
	| case_statement statement
	{
	  
	}
	;

case_statement_list:
	case_statement
	{
	   
	}
	| case_statement_list case_statement
	{
	  
	}
	;

iteration_statement:
	TOK_WHILE '(' condition ')' statement_no_new_scope
	{
	  
	}
	| TOK_DO statement TOK_WHILE '(' expression ')' ';'
	{
	  
	}
	| TOK_FOR '(' for_init_statement for_rest_statement ')' statement_no_new_scope
	{
	 
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
	  
	}
	;

for_rest_statement:
	conditionopt ';'
	{
	 
	}
	| conditionopt ';' expression
	{
	 
	}
	;

	// Grammar Note: No 'goto'. Gotos are not supported.
jump_statement:
	TOK_CONTINUE ';' 
	{
	 
	}
	| TOK_BREAK ';'
	{
	  
	}
	| TOK_RETURN ';'
	{
	
	}
	| TOK_RETURN expression ';'
	{
	 
	}
	| TOK_DISCARD ';' // Fragment shader only.
	{
	  
	}
	;

external_declaration:
	function_definition	{ }
	| global_declaration { }
	;

attribute_arg:
	constant_expression
	{
		
	}
	| TOK_STRING_CONSTANT
	{
		
	}
	;

attribute_arg_list:
	attribute_arg
	{
	
	}
	| attribute_arg_list ',' attribute_arg
	{

	}
	;

attribute:
	'[' any_identifier ']'
	{
		
	}
	| '[' basic_type_specifier_nonarray ']'
	{
		
	}
	| '[' any_identifier '(' attribute_arg_list ')' ']'
	{
		
	}
	| '[' basic_type_specifier_nonarray '(' attribute_arg_list ')' ']'
	{
		
	}
	;

attribute_list:
	attribute_list attribute
	{
		
	}
	| attribute
	{
		
	}
	;

function_definition:
	function_prototype compound_statement_no_new_scope
	{
	  
	}
	| attribute_list function_prototype compound_statement_no_new_scope
	{
	  
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