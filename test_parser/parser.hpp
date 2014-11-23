/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_CONST = 258,
     TOK_BOOL = 259,
     TOK_FLOAT = 260,
     TOK_HALF = 261,
     TOK_INT = 262,
     TOK_UINT = 263,
     TOK_VOID = 264,
     TOK_BREAK = 265,
     TOK_CONTINUE = 266,
     TOK_DO = 267,
     TOK_WHILE = 268,
     TOK_ELSE = 269,
     TOK_FOR = 270,
     TOK_IF = 271,
     TOK_DISCARD = 272,
     TOK_RETURN = 273,
     TOK_SWITCH = 274,
     TOK_DEFAULT = 275,
     TOK_STRUCT = 276,
     TOK_CBUFFER = 277,
     TOK_INTERFACE = 278,
     TOK_BOOL_VEC2 = 279,
     TOK_BOOL_VEC3 = 280,
     TOK_BOOL_VEC4 = 281,
     TOK_INT_VEC2 = 282,
     TOK_INT_VEC3 = 283,
     TOK_INT_VEC4 = 284,
     TOK_UINT_VEC2 = 285,
     TOK_UINT_VEC3 = 286,
     TOK_UINT_VEC4 = 287,
     TOK_FLOAT_VEC2 = 288,
     TOK_FLOAT_VEC3 = 289,
     TOK_FLOAT_VEC4 = 290,
     TOK_FIXED_VEC2 = 291,
     TOK_FIXED_VEC3 = 292,
     TOK_FIXED_VEC4 = 293,
     TOK_HALF_VEC2 = 294,
     TOK_HALF_VEC3 = 295,
     TOK_HALF_VEC4 = 296,
     TOK_FLOAT_VEC2X2 = 297,
     TOK_FLOAT_VEC2X3 = 298,
     TOK_FLOAT_VEC2X4 = 299,
     TOK_FLOAT_VEC3X2 = 300,
     TOK_FLOAT_VEC3X3 = 301,
     TOK_FLOAT_VEC3X4 = 302,
     TOK_FLOAT_VEC4X2 = 303,
     TOK_FLOAT_VEC4X3 = 304,
     TOK_FLOAT_VEC4X4 = 305,
     TOK_HALF_VEC2X2 = 306,
     TOK_HALF_VEC2X3 = 307,
     TOK_HALF_VEC2X4 = 308,
     TOK_HALF_VEC3X2 = 309,
     TOK_HALF_VEC3X3 = 310,
     TOK_HALF_VEC3X4 = 311,
     TOK_HALF_VEC4X2 = 312,
     TOK_HALF_VEC4X3 = 313,
     TOK_HALF_VEC4X4 = 314,
     TOK_FIXED_VEC2X2 = 315,
     TOK_FIXED_VEC2X3 = 316,
     TOK_FIXED_VEC2X4 = 317,
     TOK_FIXED_VEC3X2 = 318,
     TOK_FIXED_VEC3X3 = 319,
     TOK_FIXED_VEC3X4 = 320,
     TOK_FIXED_VEC4X2 = 321,
     TOK_FIXED_VEC4X3 = 322,
     TOK_FIXED_VEC4X4 = 323,
     TOK_DOUBLE_VEC2 = 324,
     TOK_DOUBLE_VEC3 = 325,
     TOK_DOUBLE_VEC4 = 326,
     TOK_POINT = 327,
     TOK_LINE = 328,
     TOK_TRIANGLE = 329,
     TOK_LINEADJ = 330,
     TOK_TRIANGLEADJ = 331,
     TOK_POINTSTREAM = 332,
     TOK_LINESTREAM = 333,
     TOK_TRIANGLESTREAM = 334,
     TOK_INPUTPATCH = 335,
     TOK_OUTPUTPATCH = 336,
     TOK_IN = 337,
     TOK_OUT = 338,
     TOK_INOUT = 339,
     TOK_UNIFORM = 340,
     TOK_VARYING = 341,
     TOK_CENTROID = 342,
     TOK_INVARIANT = 343,
     TOK_NOINTERPOLATION = 344,
     TOK_LINEAR = 345,
     TOK_NOPERSPECTIVE = 346,
     TOK_GLOBALLYCOHERENT = 347,
     TOK_SHARED = 348,
     TOK_GROUPSHARED = 349,
     TOK_LOWP = 350,
     TOK_MEDIUMP = 351,
     TOK_HIGHP = 352,
     TOK_SUPERP = 353,
     TOK_PRECISION = 354,
     TOK_BUFFER = 355,
     TOK_RWBUFFER = 356,
     TOK_TEXTURE1D = 357,
     TOK_TEXTURE1D_ARRAY = 358,
     TOK_RWTEXTURE1D = 359,
     TOK_RWTEXTURE1D_ARRAY = 360,
     TOK_TEXTURE2D = 361,
     TOK_TEXTURE2D_ARRAY = 362,
     TOK_RWTEXTURE2D = 363,
     TOK_RWTEXTURE2D_ARRAY = 364,
     TOK_TEXTURE2DMS = 365,
     TOK_TEXTURE2DMS_ARRAY = 366,
     TOK_TEXTURE3D = 367,
     TOK_TEXTURE3D_ARRAY = 368,
     TOK_RWTEXTURE3D = 369,
     TOK_TEXTURECUBE = 370,
     TOK_TEXTURECUBE_ARRAY = 371,
     TOK_SAMPLERSTATE = 372,
     TOK_SAMPLER_CMP_STATE = 373,
     TOK_INCREMENT = 374,
     TOK_DECREMENT = 375,
     TOK_LE = 376,
     TOK_GE = 377,
     TOK_EQ = 378,
     TOK_NEQ = 379,
     TOK_BOOL_AND = 380,
     TOK_BOOL_OR = 381,
     TOK_LSHIFT = 382,
     TOK_RSHIFT = 383,
     TOK_MULTIPLY_ASSIGN = 384,
     TOK_DIVIDE_ASSIGN = 385,
     TOK_ADD_ASSIGN = 386,
     TOK_MOD_ASSIGN = 387,
     TOK_LSHIFT_ASSIGN = 388,
     TOK_RSHIFT_ASSIGN = 389,
     TOK_AND_ASSIGN = 390,
     TOK_XOR_ASSIGN = 391,
     TOK_OR_ASSIGN = 392,
     TOK_SUBTRACT_ASSIGN = 393,
     TOK_FLOAT_CONSTANT = 394,
     TOK_INT_CONSTANT = 395,
     TOK_UINT_CONSTANT = 396,
     TOK_BOOL_CONSTANT = 397,
     TOK_STRING_CONSTANT = 398,
     TOK_IDENTIFIER = 399,
     TOK_TYPE_IDENTIFIER = 400,
     TOK_NEW_IDENTIFIER = 401,
     TOK_FIELD_SELECTION = 402,
     TOK_ASM = 403,
     TOK_CLASS = 404,
     TOK_UNION = 405,
     TOK_ENUM = 406,
     TOK_TYPEDEF = 407,
     TOK_TEMPLATE = 408,
     TOK_THIS = 409,
     TOK_PACKED = 410,
     TOK_GOTO = 411,
     TOK_INLINE = 412,
     TOK_NOINLINE = 413,
     TOK_VOLATILE = 414,
     TOK_PUBLIC = 415,
     TOK_STATIC = 416,
     TOK_EXTERN = 417,
     TOK_EXTERNAL = 418,
     TOK_LONG = 419,
     TOK_SHORT = 420,
     TOK_DOUBLE = 421,
     TOK_FIXED = 422,
     TOK_UNSIGNED = 423,
     TOK_SAMPLER2DRECT = 424,
     TOK_SAMPLER3DRECT = 425,
     TOK_SAMPLER2DRECTSHADOW = 426,
     TOK_SIZEOF = 427,
     TOK_CAST = 428,
     TOK_NAMESPACE = 429,
     TOK_USING = 430,
     TOK_CASE = 431,
     TOK_COMMON = 432,
     TOK_PARTITION = 433,
     TOK_ACTIVE = 434,
     TOK_SAMPLERBUFFER = 435,
     TOK_FILTER = 436,
     TOK_IMAGE1D = 437,
     TOK_IMAGE2D = 438,
     TOK_IMAGE3D = 439,
     TOK_IMAGECUBE = 440,
     TOK_IMAGE1DARRAY = 441,
     TOK_IMAGE2DARRAY = 442,
     TOK_IIMAGE1D = 443,
     TOK_IIMAGE2D = 444,
     TOK_IIMAGE3D = 445,
     TOK_IIMAGECUBE = 446,
     TOK_IIMAGE1DARRAY = 447,
     TOK_IIMAGE2DARRAY = 448,
     TOK_UIMAGE1D = 449,
     TOK_UIMAGE2D = 450,
     TOK_UIMAGE3D = 451,
     TOK_UIMAGECUBE = 452,
     TOK_UIMAGE1DARRAY = 453,
     TOK_UIMAGE2DARRAY = 454,
     TOK_IMAGE1DSHADOW = 455,
     TOK_IMAGE2DSHADOW = 456,
     TOK_IMAGEBUFFER = 457,
     TOK_IIMAGEBUFFER = 458,
     TOK_UIMAGEBUFFER = 459,
     TOK_IMAGE1DARRAYSHADOW = 460,
     TOK_IMAGE2DARRAYSHADOW = 461,
     TOK_ROWMAJOR = 462,
     TOK_COLUMNMAJOR = 463,
     TOK_LAYOUT = 464
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (struct THLSLParserState *state);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
