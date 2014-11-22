%{
#include <string>
#include "node.h"
#include "parser.hpp"

#define SAVE_TOKEN  			yylval->string = new std::string(yytext, yyleng)

static int literal_integer(char *text, int len, YYSTYPE *lval, YYLTYPE *lloc, int base)
{
   bool is_uint = (text[len - 1] == 'u' ||
		   text[len - 1] == 'U');
   const char *digits = text;

   /* Skip "0x" */
   if (base == 16)
      digits += 2;

#ifdef _MSC_VER
   unsigned __int64 value = _strtoui64(digits, NULL, base);
#else
   unsigned long long value = strtoull(digits, NULL, base);
#endif

   lval->iNumber = (int)value;

   if (value > UINT_MAX) 
   {
      	/* Note that signed 0xffffffff is valid, not out of range! */
		printf("Literal value '%s' out of range\n", text);
   } 
   else if (base == 10 && !is_uint && (unsigned)value > (unsigned)INT_MAX + 1) 
   {
		/* Tries to catch unintentionally providing a negative value.
		* Note that -2147483648 is parsed as -(2147483648), so we don't
		* want to warn for INT_MAX.
		*/
		printf("Signed literal value '%s' is interpreted as %d\n", text, lval->iNumber);
   }
   return is_uint ? TOK_UINT_CONSTANT : TOK_INT_CONSTANT;
}

#define LITERAL_INTEGER(base) \
   literal_integer(yytext, yyleng, yylval, yylloc, base)

#define LITERAL_FLOAT \
	{	\
		yylval->fReal = strtod(yytext, NULL); \
		return TOK_FLOAT_CONSTANT; \
	}

%}

%option noyywrap

%%

[ \t\r]										;
\n											{ yylineno++; yycolumn = 0; }
			
const										return TOK_CONST;
bool										return TOK_BOOL;
float										return TOK_FLOAT;
float1										return TOK_FLOAT;
half										return TOK_HALF;
int											return TOK_INT;
uint										return TOK_UINT;
			

break										return TOK_BREAK;
continue									return TOK_CONTINUE;
do											return TOK_DO;
while										return TOK_WHILE;
else										return TOK_ELSE;
for											return TOK_FOR;
if											return TOK_IF;
discard										return TOK_DISCARD;
return										return TOK_RETURN;
struct										return TOK_STRUCT;
cbuffer										return TOK_CBUFFER;
void										return TOK_VOID;
			

bool2										return TOK_BOOL_VEC2;
bool3										return TOK_BOOL_VEC3;
bool4										return TOK_BOOL_VEC4;
int2										return TOK_INT_VEC2;
int3										return TOK_INT_VEC3;
int4										return TOK_INT_VEC4;
uint2										return TOK_UINT_VEC2;
uint3										return TOK_UINT_VEC3;
uint4										return TOK_UINT_VEC4;
float2										return TOK_FLOAT_VEC2;
float3										return TOK_FLOAT_VEC3;
float4										return TOK_FLOAT_VEC4;
float2x2									return TOK_FLOAT_VEC2X2;
float2x3									return TOK_FLOAT_VEC2X3;
float2x4									return TOK_FLOAT_VEC2X4;
float3x2									return TOK_FLOAT_VEC3X2;
float3x3									return TOK_FLOAT_VEC3X3;
float3x4									return TOK_FLOAT_VEC3X4;
float4x2									return TOK_FLOAT_VEC4X2;
float4x3									return TOK_FLOAT_VEC4X3;
float4x4									return TOK_FLOAT_VEC4X4;


point										return TOK_POINT;
line										return TOK_LINE;
triangle									return TOK_TRIANGLE;
lineadj										return TOK_LINEADJ;
triangleadj									return TOK_TRIANGLEADJ;
PointStream									return TOK_POINTSTREAM;
LineStream									return TOK_LINESTREAM;
TriangleStream								return TOK_TRIANGLESTREAM;
							
InputPatch									return TOK_INPUTPATCH;
OutputPatch									return TOK_OUTPUTPATCH;

in											return TOK_IN;
out											return TOK_OUT;
inout										return TOK_INOUT;
uniform										return TOK_UNIFORM;
varying										return TOK_VARYING;
centroid									return TOK_CENTROID;
invariant									return TOK_INVARIANT;
nointerpolation 							return TOK_NOINTERPOLATION;
linear 										return TOK_LINEAR;
noperspective								return TOK_NOPERSPECTIVE;
globallycoherent							return TOK_GLOBALLYCOHERENT;
groupshared									return TOK_GROUPSHARED;

row_major									return TOK_ROWMAJOR;
column_major								return TOK_COLUMNMAJOR;

Buffer										return TOK_BUFFER;
Texture1D									return TOK_TEXTURE1D;
Texture1DArray								return TOK_TEXTURE1D_ARRAY;
Texture2D									return TOK_TEXTURE2D;
Texture2DArray								return TOK_TEXTURE2D_ARRAY;
Texture2DMS									return TOK_TEXTURE2DMS;
Texture2DMSArray							return TOK_TEXTURE2DMS_ARRAY;
Texture3D									return TOK_TEXTURE3D;
TextureCube									return TOK_TEXTURECUBE;
TextureCubeArray							return TOK_TEXTURECUBE_ARRAY;
SamplerState								return TOK_SAMPLERSTATE;
SamplerComparisonState 						return TOK_SAMPLER_CMP_STATE;

RWBuffer									return TOK_RWBUFFER;
RWTexture1D									return TOK_RWTEXTURE1D;
RWTexture1DArray							return TOK_RWTEXTURE1D_ARRAY;
RWTexture2D									return TOK_RWTEXTURE2D;
RWTexture2DArray							return TOK_RWTEXTURE2D_ARRAY;
RWTexture3D									return TOK_RWTEXTURE3D;


\+\+										return TOK_INCREMENT;
--											return TOK_DECREMENT;
\<=											return TOK_LE;
>=											return TOK_GE;
==											return TOK_EQ;
!=											return TOK_NEQ;
&&											return TOK_BOOL_AND;
\|\|										return TOK_BOOL_OR;
"<<"										return TOK_LSHIFT;
">>"										return TOK_RSHIFT;
			
\*=											return TOK_MULTIPLY_ASSIGN;
\/=											return TOK_DIVIDE_ASSIGN;
\+=											return TOK_ADD_ASSIGN;
\%=											return TOK_MOD_ASSIGN;
\<\<=										return TOK_LSHIFT_ASSIGN;
>>=											return TOK_RSHIFT_ASSIGN;
&=											return TOK_AND_ASSIGN;
"^="										return TOK_XOR_ASSIGN;
\|=											return TOK_OR_ASSIGN;
-=											return TOK_SUBTRACT_ASSIGN;
			
			
[1-9][0-9]*[uU]?							return LITERAL_INTEGER(10);
0[xX][0-9a-fA-F]+[uU]?						return LITERAL_INTEGER(16);
0[0-7]*[uU]?								return LITERAL_INTEGER(8);
			
\"[^"\n]*\"									{
												yylval->string = new std::string(yytext, yyleng);
												return TOK_STRING_CONSTANT;
											}

[0-9]+\.[0-9]+([eE][+-]?[0-9]+)?[fF]?		LITERAL_FLOAT
\.[0-9]+([eE][+-]?[0-9]+)?[fF]?				LITERAL_FLOAT
[0-9]+\.([eE][+-]?[0-9]+)?[fF]?				LITERAL_FLOAT
[0-9]+[eE][+-]?[0-9]+[fF]?					LITERAL_FLOAT
[0-9]+[fF]									LITERAL_FLOAT

true										{
			    								yylval->iNumber = 1;
			    								return TOK_BOOL_CONSTANT;
											}
false										{
												yylval->iNumber = 0;
												return BOOLCONSTANT;
											}

.											printf("Unknown token!\n"); yyterminate();

%%