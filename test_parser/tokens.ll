%{
#include <string>
#include "AST/AST.h"
#include "AST/ParserType.h"
#include "parser.hpp"

static int classify_identifier(struct THLSLParserState *state, const char *name);

#define YY_USER_ACTION            \
   do {               \
      yylloc->first_column = yycolumn + 1;      \
      yylloc->first_line = yylineno + 1;      \
      yycolumn += yyleng;         \
   } while(0);

//#define YY_USER_INIT yylineno = 0; yycolumn = 0;

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

   lval->number = (int)value;

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
        printf("Signed literal value '%s' is interpreted as %d\n", text, lval->number);
   }
   return is_uint ? TOK_UINT_CONSTANT : TOK_INT_CONSTANT;
}

#define LITERAL_INTEGER(base) \
   literal_integer(yytext, yyleng, yylval, yylloc, base)

#define LITERAL_FLOAT \
    {   \
        yylval->real = strtod(yytext, NULL); \
        return TOK_FLOAT_CONSTANT; \
    }

%}

%option bison-bridge bison-locations reentrant noyywrap
%option nounput noyy_top_state
%option never-interactive
%option extra-type="struct THLSLParserState *"

%%

[ \r\t]                                     ;
\n                                          { yylineno++; yycolumn = 0; }
            
const                                       return TOK_CONST;
bool                                        return TOK_BOOL;
float                                       return TOK_FLOAT;
float1                                      return TOK_FLOAT;
half                                        return TOK_HALF;
int                                         return TOK_INT;
uint                                        return TOK_UINT;
void                                        return TOK_VOID;          

break                                       return TOK_BREAK;
continue                                    return TOK_CONTINUE;
do                                          return TOK_DO;
while                                       return TOK_WHILE;
else                                        return TOK_ELSE;
for                                         return TOK_FOR;
if                                          return TOK_IF;
discard                                     return TOK_DISCARD;
return                                      return TOK_RETURN;
struct                                      return TOK_STRUCT;
cbuffer                                     return TOK_CBUFFER;
         

bool2                                       return TOK_BOOL_VEC2;
bool3                                       return TOK_BOOL_VEC3;
bool4                                       return TOK_BOOL_VEC4;
int2                                        return TOK_INT_VEC2;
int3                                        return TOK_INT_VEC3;
int4                                        return TOK_INT_VEC4;
uint2                                       return TOK_UINT_VEC2;
uint3                                       return TOK_UINT_VEC3;
uint4                                       return TOK_UINT_VEC4;
float2                                      return TOK_FLOAT_VEC2;
float3                                      return TOK_FLOAT_VEC3;
float4                                      return TOK_FLOAT_VEC4;
float2x2                                    return TOK_FLOAT_VEC2X2;
float2x3                                    return TOK_FLOAT_VEC2X3;
float2x4                                    return TOK_FLOAT_VEC2X4;
float3x2                                    return TOK_FLOAT_VEC3X2;
float3x3                                    return TOK_FLOAT_VEC3X3;
float3x4                                    return TOK_FLOAT_VEC3X4;
float4x2                                    return TOK_FLOAT_VEC4X2;
float4x3                                    return TOK_FLOAT_VEC4X3;
float4x4                                    return TOK_FLOAT_VEC4X4;


point                                       return TOK_POINT;
line                                        return TOK_LINE;
triangle                                    return TOK_TRIANGLE;
lineadj                                     return TOK_LINEADJ;
triangleadj                                 return TOK_TRIANGLEADJ;
PointStream                                 return TOK_POINTSTREAM;
LineStream                                  return TOK_LINESTREAM;
TriangleStream                              return TOK_TRIANGLESTREAM;
                            
InputPatch                                  return TOK_INPUTPATCH;
OutputPatch                                 return TOK_OUTPUTPATCH;

in                                          return TOK_IN;
out                                         return TOK_OUT;
inout                                       return TOK_INOUT;
uniform                                     return TOK_UNIFORM;
varying                                     return TOK_VARYING;
centroid                                    return TOK_CENTROID;
invariant                                   return TOK_INVARIANT;
nointerpolation                             return TOK_NOINTERPOLATION;
linear                                      return TOK_LINEAR;
noperspective                               return TOK_NOPERSPECTIVE;
globallycoherent                            return TOK_GLOBALLYCOHERENT;
groupshared                                 return TOK_GROUPSHARED;

row_major                                   return TOK_ROWMAJOR;
column_major                                return TOK_COLUMNMAJOR;

Buffer                                      return TOK_BUFFER;
Texture1D                                   return TOK_TEXTURE1D;
Texture1DArray                              return TOK_TEXTURE1D_ARRAY;
Texture2D                                   return TOK_TEXTURE2D;
Texture2DArray                              return TOK_TEXTURE2D_ARRAY;
Texture2DMS                                 return TOK_TEXTURE2DMS;
Texture2DMSArray                            return TOK_TEXTURE2DMS_ARRAY;
Texture3D                                   return TOK_TEXTURE3D;
TextureCube                                 return TOK_TEXTURECUBE;
TextureCubeArray                            return TOK_TEXTURECUBE_ARRAY;
SamplerState                                return TOK_SAMPLERSTATE;
SamplerComparisonState                      return TOK_SAMPLER_CMP_STATE;

RWBuffer                                    return TOK_RWBUFFER;
RWTexture1D                                 return TOK_RWTEXTURE1D;
RWTexture1DArray                            return TOK_RWTEXTURE1D_ARRAY;
RWTexture2D                                 return TOK_RWTEXTURE2D;
RWTexture2DArray                            return TOK_RWTEXTURE2D_ARRAY;
RWTexture3D                                 return TOK_RWTEXTURE3D;


asm                                         return TOK_ASM;
class                                       return TOK_CLASS;
union                                       return TOK_UNION;
enum                                        return TOK_ENUM;
typedef                                     return TOK_TYPEDEF;
template                                    return TOK_TEMPLATE;
this                                        return TOK_THIS;
packed                                      return TOK_PACKED;
goto                                        return TOK_GOTO;
switch                                      return TOK_SWITCH;
default                                     return TOK_DEFAULT;
inline                                      return TOK_INLINE;
noinline                                    return TOK_NOINLINE;
volatile                                    return TOK_VOLATILE;
public                                      return TOK_PUBLIC;
static                                      return TOK_STATIC;
extern                                      return TOK_EXTERN;
external                                    return TOK_EXTERNAL;
interface                                   return TOK_INTERFACE;
long                                        return TOK_LONG;
short                                       return TOK_SHORT;
double                                      return TOK_DOUBLE;
fixed                                       return TOK_FIXED;
unsigned                                    return TOK_UNSIGNED;
half2                                       return TOK_HALF_VEC2;
half3                                       return TOK_HALF_VEC3;
half4                                       return TOK_HALF_VEC4;
half2x2                                     return TOK_HALF_VEC2X2;
half2x3                                     return TOK_HALF_VEC2X3;
half2x4                                     return TOK_HALF_VEC2X4;
half3x2                                     return TOK_HALF_VEC3X2;
half3x3                                     return TOK_HALF_VEC3X3;
half3x4                                     return TOK_HALF_VEC3X4;
half4x2                                     return TOK_HALF_VEC4X2;
half4x3                                     return TOK_HALF_VEC4X3;
half4x4                                     return TOK_HALF_VEC4X4;
double2                                     return TOK_DOUBLE_VEC2;
double3                                     return TOK_DOUBLE_VEC3;
double4                                     return TOK_DOUBLE_VEC4;
fixed2                                      return TOK_FIXED_VEC2;
fixed3                                      return TOK_FIXED_VEC3;
fixed4                                      return TOK_FIXED_VEC4;
fixed2x2                                    return TOK_FIXED_VEC2X2;
fixed2x3                                    return TOK_FIXED_VEC2X3;
fixed2x4                                    return TOK_FIXED_VEC2X4;
fixed3x2                                    return TOK_FIXED_VEC3X2;
fixed3x3                                    return TOK_FIXED_VEC3X3;
fixed3x4                                    return TOK_FIXED_VEC3X4;
fixed4x2                                    return TOK_FIXED_VEC4X2;
fixed4x3                                    return TOK_FIXED_VEC4X3;
fixed4x4                                    return TOK_FIXED_VEC4X4;
sampler2DRect                               return TOK_SAMPLER2DRECT;
sampler3DRect                               return TOK_SAMPLER3DRECT;
sampler2DRectShadow                         return TOK_SAMPLER2DRECTSHADOW;
sizeof                                      return TOK_SIZEOF;
cast                                        return TOK_CAST;
namespace                                   return TOK_NAMESPACE;
using                                       return TOK_USING;
                                
lowp                                        return TOK_LOWP;
mediump                                     return TOK_MEDIUMP;
highp                                       return TOK_HIGHP;
precision                                   return TOK_PRECISION;
                                
case                                        return TOK_CASE;
common                                      return TOK_COMMON;
partition                                   return TOK_PARTITION;
active                                      return TOK_ACTIVE;
superp                                      return TOK_SUPERP;
samplerBuffer                               return TOK_SAMPLERBUFFER;
filter                                      return TOK_FILTER;
image1D                                     return TOK_IMAGE1D;
image2D                                     return TOK_IMAGE2D;
image3D                                     return TOK_IMAGE3D;
imageCube                                   return TOK_IMAGECUBE;
iimage1D                                    return TOK_IIMAGE1D;
iimage2D                                    return TOK_IIMAGE2D;
iimage3D                                    return TOK_IIMAGE3D;
iimageCube                                  return TOK_IIMAGECUBE;
uimage1D                                    return TOK_UIMAGE1D;
uimage2D                                    return TOK_UIMAGE2D;
uimage3D                                    return TOK_UIMAGE3D;
uimageCube                                  return TOK_UIMAGECUBE;
image1DArray                                return TOK_IMAGE1DARRAY;
image2DArray                                return TOK_IMAGE2DARRAY;
iimage1DArray                               return TOK_IIMAGE1DARRAY;
iimage2DArray                               return TOK_IIMAGE2DARRAY;
uimage1DArray                               return TOK_UIMAGE1DARRAY;
uimage2DArray                               return TOK_UIMAGE2DARRAY;
image1DShadow                               return TOK_IMAGE1DSHADOW;
image2DShadow                               return TOK_IMAGE2DSHADOW;
image1DArrayShadow                          return TOK_IMAGE1DARRAYSHADOW;
image2DArrayShadow                          return TOK_IMAGE2DARRAYSHADOW;
imageBuffer                                 return TOK_IMAGEBUFFER;
iimageBuffer                                return TOK_IIMAGEBUFFER;
uimageBuffer                                return TOK_UIMAGEBUFFER;


\+\+                                        return TOK_INCREMENT;
--                                          return TOK_DECREMENT;
\<=                                         return TOK_LE;
>=                                          return TOK_GE;
==                                          return TOK_EQ;
!=                                          return TOK_NEQ;
&&                                          return TOK_BOOL_AND;
\|\|                                        return TOK_BOOL_OR;
"<<"                                        return TOK_LSHIFT;
">>"                                        return TOK_RSHIFT;
            
\*=                                         return TOK_MULTIPLY_ASSIGN;
\/=                                         return TOK_DIVIDE_ASSIGN;
\+=                                         return TOK_ADD_ASSIGN;
\%=                                         return TOK_MOD_ASSIGN;
\<\<=                                       return TOK_LSHIFT_ASSIGN;
>>=                                         return TOK_RSHIFT_ASSIGN;
&=                                          return TOK_AND_ASSIGN;
"^="                                        return TOK_XOR_ASSIGN;
\|=                                         return TOK_OR_ASSIGN;
-=                                          return TOK_SUBTRACT_ASSIGN;
            
            
[1-9][0-9]*[uU]?                            return LITERAL_INTEGER(10);
0[xX][0-9a-fA-F]+[uU]?                      return LITERAL_INTEGER(16);
0[0-7]*[uU]?                                return LITERAL_INTEGER(8);
            
\"[^"\n]*\"                                 {
                                                yylval->string = std::string(yytext, yyleng);
                                                return TOK_STRING_CONSTANT;
                                            }

[0-9]+\.[0-9]+([eE][+-]?[0-9]+)?[fF]?       LITERAL_FLOAT
\.[0-9]+([eE][+-]?[0-9]+)?[fF]?             LITERAL_FLOAT
[0-9]+\.([eE][+-]?[0-9]+)?[fF]?             LITERAL_FLOAT
[0-9]+[eE][+-]?[0-9]+[fF]?                  LITERAL_FLOAT
[0-9]+[fF]                                  LITERAL_FLOAT

true                                        {
                                                yylval->number = 1;
                                                return TOK_BOOL_CONSTANT;
                                            }
false                                       {
                                                yylval->number = 0;
                                                return TOK_BOOL_CONSTANT;
                                            }

[_a-zA-Z][_a-zA-Z0-9]*                      { 
												struct THLSLParserState *state = yyextra;
                                                yylval->identifier = std::string(yytext, yyleng);
                                                return classify_identifier(state, yytext);
                                            }

.                                           { return yytext[0]; }

%%

int classify_identifier(struct THLSLParserState *state, const char *name)
{
   if (state->symbols.FindVariable(name) || state->symbols.FindFunction(name))
      return TOK_IDENTIFIER;
   else if (state->symbols.FindType(name))
      return TOK_TYPE_IDENTIFIER;
   else
      return TOK_NEW_IDENTIFIER;
}
