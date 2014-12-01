/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */


	#include "AST/AST.h"
	#include "AST/ParserType.h"
	#include "parser.hpp"
    #include <cstdio>
    #include <cstdlib>
	AST::CNode *programBlock; /* the top level root node of our final AST */

	#define YYLEX_PARAM state->scanner
	
	void yyerror(YYLTYPE *loc, void *st, const char *s) { std::printf("Error: %s\n", s); }
	extern int yylex(YYSTYPE * lvalp, YYLTYPE*,  void*);



# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
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

/* Copy the second part of user declarations.  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   7225

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  234
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  382
/* YYNRULES -- Number of states.  */
#define YYNSTATES  579

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   464

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   218,     2,     2,     2,   222,   225,     2,
     210,   211,   220,   216,   215,   217,   214,   221,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   229,   231,
     223,   230,   224,   228,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   212,     2,   213,   226,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   232,   227,   233,   219,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    18,
      20,    22,    24,    26,    28,    30,    32,    36,    38,    43,
      45,    49,    52,    55,    57,    59,    61,    65,    68,    71,
      74,    76,    79,    83,    86,    88,    90,    92,    95,    98,
     101,   103,   106,   110,   113,   115,   118,   121,   124,   129,
     131,   133,   135,   137,   139,   143,   147,   151,   153,   157,
     161,   163,   167,   171,   173,   177,   181,   185,   189,   191,
     195,   199,   201,   205,   207,   211,   213,   217,   219,   223,
     225,   229,   231,   237,   239,   243,   245,   247,   249,   251,
     253,   255,   257,   259,   261,   263,   265,   267,   271,   273,
     276,   281,   283,   286,   288,   291,   296,   298,   300,   303,
     307,   311,   316,   319,   324,   329,   332,   340,   344,   348,
     353,   356,   359,   361,   365,   368,   370,   372,   374,   377,
     380,   382,   384,   386,   388,   390,   392,   394,   398,   404,
     408,   416,   422,   428,   430,   433,   438,   441,   448,   453,
     458,   461,   463,   466,   471,   473,   477,   479,   483,   485,
     487,   489,   491,   494,   497,   499,   501,   503,   505,   508,
     510,   513,   516,   520,   522,   524,   526,   529,   531,   533,
     536,   539,   541,   543,   545,   547,   550,   553,   555,   557,
     559,   562,   564,   566,   570,   574,   579,   584,   586,   588,
     595,   600,   605,   612,   619,   621,   623,   625,   627,   629,
     631,   633,   635,   637,   639,   641,   643,   645,   647,   649,
     651,   653,   655,   657,   659,   661,   663,   665,   667,   669,
     671,   673,   675,   677,   679,   681,   683,   685,   687,   689,
     691,   693,   695,   697,   699,   701,   703,   705,   707,   709,
     711,   713,   715,   717,   719,   721,   723,   725,   727,   729,
     731,   733,   735,   737,   739,   741,   743,   745,   747,   749,
     751,   753,   755,   757,   759,   761,   763,   765,   767,   769,
     771,   773,   775,   777,   779,   785,   793,   798,   803,   810,
     814,   820,   822,   825,   829,   831,   834,   836,   839,   842,
     844,   846,   850,   852,   854,   858,   865,   870,   875,   877,
     881,   883,   887,   890,   892,   894,   896,   899,   902,   904,
     906,   908,   910,   912,   914,   917,   918,   923,   925,   927,
     930,   934,   936,   939,   941,   944,   950,   954,   956,   958,
     963,   969,   972,   976,   980,   983,   985,   988,   991,   994,
     996,   999,  1005,  1013,  1020,  1022,  1024,  1026,  1027,  1030,
    1034,  1037,  1040,  1043,  1047,  1050,  1052,  1054,  1056,  1058,
    1060,  1064,  1068,  1072,  1079,  1086,  1089,  1091,  1094,  1098,
    1100,  1103,  1105
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     235,     0,    -1,    -1,   236,   238,    -1,   144,    -1,   145,
      -1,   146,    -1,   336,    -1,   238,   336,    -1,   144,    -1,
     146,    -1,   239,    -1,   140,    -1,   141,    -1,   139,    -1,
     142,    -1,   210,   269,   211,    -1,   240,    -1,   241,   212,
     242,   213,    -1,   243,    -1,   241,   214,   237,    -1,   241,
     119,    -1,   241,   120,    -1,   269,    -1,   244,    -1,   245,
      -1,   241,   214,   250,    -1,   247,   211,    -1,   246,   211,
      -1,   248,     9,    -1,   248,    -1,   248,   267,    -1,   247,
     215,   267,    -1,   249,   210,    -1,   292,    -1,   239,    -1,
     147,    -1,   252,   211,    -1,   251,   211,    -1,   253,     9,
      -1,   253,    -1,   253,   267,    -1,   252,   215,   267,    -1,
     239,   210,    -1,   241,    -1,   119,   254,    -1,   120,   254,
      -1,   255,   254,    -1,   210,   295,   211,   254,    -1,   216,
      -1,   217,    -1,   218,    -1,   219,    -1,   254,    -1,   256,
     220,   254,    -1,   256,   221,   254,    -1,   256,   222,   254,
      -1,   256,    -1,   257,   216,   256,    -1,   257,   217,   256,
      -1,   257,    -1,   258,   127,   257,    -1,   258,   128,   257,
      -1,   258,    -1,   259,   223,   258,    -1,   259,   224,   258,
      -1,   259,   121,   258,    -1,   259,   122,   258,    -1,   259,
      -1,   260,   123,   259,    -1,   260,   124,   259,    -1,   260,
      -1,   261,   225,   260,    -1,   261,    -1,   262,   226,   261,
      -1,   262,    -1,   263,   227,   262,    -1,   263,    -1,   264,
     125,   263,    -1,   264,    -1,   265,   126,   264,    -1,   265,
      -1,   265,   228,   269,   229,   267,    -1,   266,    -1,   254,
     268,   267,    -1,   230,    -1,   129,    -1,   130,    -1,   132,
      -1,   131,    -1,   138,    -1,   133,    -1,   134,    -1,   135,
      -1,   136,    -1,   137,    -1,   267,    -1,   269,   215,   267,
      -1,   266,    -1,   274,   231,    -1,    99,   301,   293,   231,
      -1,   271,    -1,   282,   231,    -1,   272,    -1,   275,   211,
      -1,   275,   211,   229,   237,    -1,   277,    -1,   276,    -1,
     277,   279,    -1,   276,   215,   279,    -1,   284,   239,   210,
      -1,   157,   284,   239,   210,    -1,   292,   237,    -1,   292,
     237,   230,   270,    -1,   292,   237,   229,   237,    -1,   292,
     310,    -1,   292,   237,   212,   270,   213,   229,   237,    -1,
     289,   280,   278,    -1,   280,   289,   278,    -1,   289,   280,
     289,   278,    -1,   280,   278,    -1,   289,   278,    -1,   278,
      -1,   289,   280,   281,    -1,   280,   281,    -1,    82,    -1,
      83,    -1,    84,    -1,    82,    83,    -1,    83,    82,    -1,
      72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,
     292,    -1,   283,    -1,   282,   215,   237,    -1,   282,   215,
     237,   212,   213,    -1,   282,   215,   310,    -1,   282,   215,
     237,   212,   213,   230,   311,    -1,   282,   215,   310,   230,
     311,    -1,   282,   215,   237,   230,   311,    -1,   284,    -1,
     284,   237,    -1,   284,   237,   212,   213,    -1,   284,   310,
      -1,   284,   237,   212,   213,   230,   311,    -1,   284,   310,
     230,   311,    -1,   284,   237,   230,   311,    -1,    88,   239,
      -1,   292,    -1,   290,   292,    -1,   209,   210,   286,   211,
      -1,   287,    -1,   286,   215,   287,    -1,   237,    -1,   237,
     230,   140,    -1,    90,    -1,    89,    -1,    91,    -1,   288,
      -1,    87,   288,    -1,   288,    87,    -1,    87,    -1,     3,
      -1,   291,    -1,   285,    -1,   285,   291,    -1,   288,    -1,
     288,   291,    -1,    88,   291,    -1,    88,   288,   291,    -1,
      88,    -1,     3,    -1,    86,    -1,    87,    86,    -1,    82,
      -1,    83,    -1,    87,    82,    -1,    87,    83,    -1,    85,
      -1,   207,    -1,   208,    -1,   161,    -1,     3,   161,    -1,
     161,     3,    -1,    92,    -1,    93,    -1,   293,    -1,   301,
     293,    -1,   295,    -1,   294,    -1,   295,   212,   213,    -1,
     294,   212,   213,    -1,   295,   212,   270,   213,    -1,   294,
     212,   270,   213,    -1,   296,    -1,   297,    -1,   297,   223,
     296,   215,   140,   224,    -1,   297,   223,   296,   224,    -1,
     298,   223,   145,   224,    -1,   299,   223,   145,   215,   140,
     224,    -1,   300,   223,   145,   215,   140,   224,    -1,   302,
      -1,   145,    -1,     9,    -1,     5,    -1,     6,    -1,   167,
      -1,     7,    -1,     8,    -1,     4,    -1,    33,    -1,    34,
      -1,    35,    -1,    39,    -1,    40,    -1,    41,    -1,    36,
      -1,    37,    -1,    38,    -1,    24,    -1,    25,    -1,    26,
      -1,    27,    -1,    28,    -1,    29,    -1,    30,    -1,    31,
      -1,    32,    -1,    42,    -1,    43,    -1,    44,    -1,    45,
      -1,    46,    -1,    47,    -1,    48,    -1,    49,    -1,    50,
      -1,    51,    -1,    52,    -1,    53,    -1,    54,    -1,    55,
      -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,    60,
      -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,    65,
      -1,    66,    -1,    67,    -1,    68,    -1,   117,    -1,   118,
      -1,   100,    -1,   102,    -1,   103,    -1,   106,    -1,   107,
      -1,   110,    -1,   111,    -1,   112,    -1,   115,    -1,   116,
      -1,   101,    -1,   104,    -1,   105,    -1,   108,    -1,   109,
      -1,   114,    -1,    77,    -1,    78,    -1,    79,    -1,    80,
      -1,    81,    -1,    97,    -1,    96,    -1,    95,    -1,    21,
     237,   232,   304,   233,    -1,    21,   237,   229,   145,   232,
     304,   233,    -1,    21,   232,   304,   233,    -1,    21,   237,
     232,   233,    -1,    21,   237,   229,   145,   232,   233,    -1,
      21,   232,   233,    -1,    22,   237,   232,   304,   233,    -1,
     305,    -1,   304,   305,    -1,   306,   308,   231,    -1,   292,
      -1,   307,   292,    -1,   288,    -1,    87,   288,    -1,   288,
      87,    -1,    87,    -1,   309,    -1,   308,   215,   309,    -1,
     237,    -1,   310,    -1,   237,   229,   237,    -1,   237,   212,
     270,   213,   229,   237,    -1,   237,   212,   270,   213,    -1,
     310,   212,   270,   213,    -1,   267,    -1,   232,   312,   233,
      -1,   311,    -1,   312,   215,   311,    -1,   312,   215,    -1,
     273,    -1,   316,    -1,   315,    -1,   340,   316,    -1,   340,
     315,    -1,   313,    -1,   321,    -1,   322,    -1,   325,    -1,
     331,    -1,   335,    -1,   232,   233,    -1,    -1,   232,   317,
     320,   233,    -1,   319,    -1,   315,    -1,   232,   233,    -1,
     232,   320,   233,    -1,   314,    -1,   320,   314,    -1,   231,
      -1,   269,   231,    -1,    16,   210,   269,   211,   323,    -1,
     314,    14,   314,    -1,   314,    -1,   269,    -1,   284,   237,
     230,   311,    -1,    19,   210,   269,   211,   326,    -1,   232,
     233,    -1,   232,   330,   233,    -1,   176,   269,   229,    -1,
      20,   229,    -1,   327,    -1,   328,   327,    -1,   328,   314,
      -1,   329,   314,    -1,   329,    -1,   330,   329,    -1,    13,
     210,   324,   211,   318,    -1,    12,   314,    13,   210,   269,
     211,   231,    -1,    15,   210,   332,   334,   211,   318,    -1,
     321,    -1,   313,    -1,   324,    -1,    -1,   333,   231,    -1,
     333,   231,   269,    -1,    11,   231,    -1,    10,   231,    -1,
      18,   231,    -1,    18,   269,   231,    -1,    17,   231,    -1,
     341,    -1,   342,    -1,   270,    -1,   143,    -1,   337,    -1,
     338,   215,   337,    -1,   212,   237,   213,    -1,   212,   296,
     213,    -1,   212,   237,   210,   338,   211,   213,    -1,   212,
     296,   210,   338,   211,   213,    -1,   340,   339,    -1,   339,
      -1,   274,   319,    -1,   340,   274,   319,    -1,   271,    -1,
     282,   231,    -1,   272,    -1,   303,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   193,   193,   193,   204,   205,   206,   210,   217,   227,
     228,   232,   237,   243,   249,   255,   261,   268,   269,   274,
     278,   284,   289,   297,   301,   305,   306,   314,   315,   319,
     320,   324,   330,   342,   346,   351,   357,   366,   367,   371,
     372,   376,   382,   394,   404,   405,   410,   415,   420,   430,
     431,   432,   433,   437,   438,   443,   448,   456,   457,   462,
     470,   471,   476,   484,   485,   490,   495,   500,   508,   509,
     514,   522,   523,   531,   532,   540,   541,   549,   550,   558,
     559,   567,   568,   576,   577,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   599,   603,   621,   625,
     633,   640,   644,   648,   655,   658,   666,   667,   671,   676,
     684,   692,   703,   713,   724,   735,   747,   763,   770,   777,
     785,   790,   795,   796,   806,   817,   822,   827,   833,   839,
     845,   850,   855,   860,   865,   873,   877,   878,   888,   898,
     907,   917,   926,   940,   945,   953,   961,   969,   977,   986,
     994,  1006,  1011,  1019,  1026,  1027,  1034,  1038,  1045,  1049,
    1053,  1060,  1061,  1065,  1069,  1073,  1080,  1081,  1082,  1086,
    1087,  1091,  1095,  1099,  1106,  1110,  1114,  1118,  1122,  1126,
    1130,  1134,  1138,  1142,  1146,  1150,  1154,  1158,  1162,  1169,
    1173,  1180,  1181,  1185,  1191,  1196,  1202,  1209,  1214,  1219,
    1225,  1230,  1235,  1241,  1246,  1251,  1259,  1260,  1261,  1262,
    1263,  1264,  1265,  1266,  1267,  1268,  1269,  1270,  1271,  1272,
    1273,  1274,  1275,  1276,  1277,  1278,  1279,  1280,  1281,  1282,
    1283,  1284,  1285,  1286,  1287,  1288,  1289,  1290,  1291,  1292,
    1293,  1294,  1295,  1296,  1297,  1298,  1299,  1300,  1301,  1302,
    1303,  1304,  1305,  1306,  1307,  1308,  1309,  1310,  1311,  1312,
    1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,
    1327,  1328,  1329,  1330,  1331,  1332,  1336,  1337,  1338,  1342,
    1346,  1350,  1353,  1356,  1362,  1369,  1374,  1379,  1386,  1393,
    1401,  1409,  1415,  1423,  1432,  1437,  1445,  1446,  1450,  1454,
    1461,  1467,  1475,  1481,  1485,  1492,  1501,  1506,  1514,  1515,
    1523,  1528,  1533,  1540,  1546,  1547,  1548,  1552,  1560,  1561,
    1562,  1563,  1564,  1565,  1569,  1576,  1575,  1588,  1589,  1593,
    1598,  1606,  1611,  1619,  1624,  1632,  1640,  1645,  1653,  1657,
    1674,  1681,  1685,  1692,  1696,  1703,  1707,  1714,  1718,  1725,
    1729,  1736,  1740,  1744,  1751,  1752,  1756,  1758,  1764,  1768,
    1776,  1781,  1786,  1791,  1796,  1804,  1805,  1809,  1813,  1820,
    1824,  1831,  1835,  1839,  1843,  1850,  1855,  1862,  1868,  1880,
    1884,  1888,  1892
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_CONST", "TOK_BOOL", "TOK_FLOAT",
  "TOK_HALF", "TOK_INT", "TOK_UINT", "TOK_VOID", "TOK_BREAK",
  "TOK_CONTINUE", "TOK_DO", "TOK_WHILE", "TOK_ELSE", "TOK_FOR", "TOK_IF",
  "TOK_DISCARD", "TOK_RETURN", "TOK_SWITCH", "TOK_DEFAULT", "TOK_STRUCT",
  "TOK_CBUFFER", "TOK_INTERFACE", "TOK_BOOL_VEC2", "TOK_BOOL_VEC3",
  "TOK_BOOL_VEC4", "TOK_INT_VEC2", "TOK_INT_VEC3", "TOK_INT_VEC4",
  "TOK_UINT_VEC2", "TOK_UINT_VEC3", "TOK_UINT_VEC4", "TOK_FLOAT_VEC2",
  "TOK_FLOAT_VEC3", "TOK_FLOAT_VEC4", "TOK_FIXED_VEC2", "TOK_FIXED_VEC3",
  "TOK_FIXED_VEC4", "TOK_HALF_VEC2", "TOK_HALF_VEC3", "TOK_HALF_VEC4",
  "TOK_FLOAT_VEC2X2", "TOK_FLOAT_VEC2X3", "TOK_FLOAT_VEC2X4",
  "TOK_FLOAT_VEC3X2", "TOK_FLOAT_VEC3X3", "TOK_FLOAT_VEC3X4",
  "TOK_FLOAT_VEC4X2", "TOK_FLOAT_VEC4X3", "TOK_FLOAT_VEC4X4",
  "TOK_HALF_VEC2X2", "TOK_HALF_VEC2X3", "TOK_HALF_VEC2X4",
  "TOK_HALF_VEC3X2", "TOK_HALF_VEC3X3", "TOK_HALF_VEC3X4",
  "TOK_HALF_VEC4X2", "TOK_HALF_VEC4X3", "TOK_HALF_VEC4X4",
  "TOK_FIXED_VEC2X2", "TOK_FIXED_VEC2X3", "TOK_FIXED_VEC2X4",
  "TOK_FIXED_VEC3X2", "TOK_FIXED_VEC3X3", "TOK_FIXED_VEC3X4",
  "TOK_FIXED_VEC4X2", "TOK_FIXED_VEC4X3", "TOK_FIXED_VEC4X4",
  "TOK_DOUBLE_VEC2", "TOK_DOUBLE_VEC3", "TOK_DOUBLE_VEC4", "TOK_POINT",
  "TOK_LINE", "TOK_TRIANGLE", "TOK_LINEADJ", "TOK_TRIANGLEADJ",
  "TOK_POINTSTREAM", "TOK_LINESTREAM", "TOK_TRIANGLESTREAM",
  "TOK_INPUTPATCH", "TOK_OUTPUTPATCH", "TOK_IN", "TOK_OUT", "TOK_INOUT",
  "TOK_UNIFORM", "TOK_VARYING", "TOK_CENTROID", "TOK_INVARIANT",
  "TOK_NOINTERPOLATION", "TOK_LINEAR", "TOK_NOPERSPECTIVE",
  "TOK_GLOBALLYCOHERENT", "TOK_SHARED", "TOK_GROUPSHARED", "TOK_LOWP",
  "TOK_MEDIUMP", "TOK_HIGHP", "TOK_SUPERP", "TOK_PRECISION", "TOK_BUFFER",
  "TOK_RWBUFFER", "TOK_TEXTURE1D", "TOK_TEXTURE1D_ARRAY",
  "TOK_RWTEXTURE1D", "TOK_RWTEXTURE1D_ARRAY", "TOK_TEXTURE2D",
  "TOK_TEXTURE2D_ARRAY", "TOK_RWTEXTURE2D", "TOK_RWTEXTURE2D_ARRAY",
  "TOK_TEXTURE2DMS", "TOK_TEXTURE2DMS_ARRAY", "TOK_TEXTURE3D",
  "TOK_TEXTURE3D_ARRAY", "TOK_RWTEXTURE3D", "TOK_TEXTURECUBE",
  "TOK_TEXTURECUBE_ARRAY", "TOK_SAMPLERSTATE", "TOK_SAMPLER_CMP_STATE",
  "TOK_INCREMENT", "TOK_DECREMENT", "TOK_LE", "TOK_GE", "TOK_EQ",
  "TOK_NEQ", "TOK_BOOL_AND", "TOK_BOOL_OR", "TOK_LSHIFT", "TOK_RSHIFT",
  "TOK_MULTIPLY_ASSIGN", "TOK_DIVIDE_ASSIGN", "TOK_ADD_ASSIGN",
  "TOK_MOD_ASSIGN", "TOK_LSHIFT_ASSIGN", "TOK_RSHIFT_ASSIGN",
  "TOK_AND_ASSIGN", "TOK_XOR_ASSIGN", "TOK_OR_ASSIGN",
  "TOK_SUBTRACT_ASSIGN", "TOK_FLOAT_CONSTANT", "TOK_INT_CONSTANT",
  "TOK_UINT_CONSTANT", "TOK_BOOL_CONSTANT", "TOK_STRING_CONSTANT",
  "TOK_IDENTIFIER", "TOK_TYPE_IDENTIFIER", "TOK_NEW_IDENTIFIER",
  "TOK_FIELD_SELECTION", "TOK_ASM", "TOK_CLASS", "TOK_UNION", "TOK_ENUM",
  "TOK_TYPEDEF", "TOK_TEMPLATE", "TOK_THIS", "TOK_PACKED", "TOK_GOTO",
  "TOK_INLINE", "TOK_NOINLINE", "TOK_VOLATILE", "TOK_PUBLIC", "TOK_STATIC",
  "TOK_EXTERN", "TOK_EXTERNAL", "TOK_LONG", "TOK_SHORT", "TOK_DOUBLE",
  "TOK_FIXED", "TOK_UNSIGNED", "TOK_SAMPLER2DRECT", "TOK_SAMPLER3DRECT",
  "TOK_SAMPLER2DRECTSHADOW", "TOK_SIZEOF", "TOK_CAST", "TOK_NAMESPACE",
  "TOK_USING", "TOK_CASE", "TOK_COMMON", "TOK_PARTITION", "TOK_ACTIVE",
  "TOK_SAMPLERBUFFER", "TOK_FILTER", "TOK_IMAGE1D", "TOK_IMAGE2D",
  "TOK_IMAGE3D", "TOK_IMAGECUBE", "TOK_IMAGE1DARRAY", "TOK_IMAGE2DARRAY",
  "TOK_IIMAGE1D", "TOK_IIMAGE2D", "TOK_IIMAGE3D", "TOK_IIMAGECUBE",
  "TOK_IIMAGE1DARRAY", "TOK_IIMAGE2DARRAY", "TOK_UIMAGE1D", "TOK_UIMAGE2D",
  "TOK_UIMAGE3D", "TOK_UIMAGECUBE", "TOK_UIMAGE1DARRAY",
  "TOK_UIMAGE2DARRAY", "TOK_IMAGE1DSHADOW", "TOK_IMAGE2DSHADOW",
  "TOK_IMAGEBUFFER", "TOK_IIMAGEBUFFER", "TOK_UIMAGEBUFFER",
  "TOK_IMAGE1DARRAYSHADOW", "TOK_IMAGE2DARRAYSHADOW", "TOK_ROWMAJOR",
  "TOK_COLUMNMAJOR", "TOK_LAYOUT", "'('", "')'", "'['", "']'", "'.'",
  "','", "'+'", "'-'", "'!'", "'~'", "'*'", "'/'", "'%'", "'<'", "'>'",
  "'&'", "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "translation_unit", "$@1", "any_identifier", "external_declaration_list",
  "variable_identifier", "primary_expression", "postfix_expression",
  "integer_expression", "function_call", "function_call_or_method",
  "function_call_generic", "function_call_header_no_parameters",
  "function_call_header_with_parameters", "function_call_header",
  "function_identifier", "method_call_generic",
  "method_call_header_no_parameters", "method_call_header_with_parameters",
  "method_call_header", "unary_expression", "unary_operator",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "function_decl", "precision_decl",
  "declaration", "function_prototype", "function_declarator",
  "function_header_with_parameters", "function_header",
  "parameter_declarator", "parameter_declaration", "parameter_qualifier",
  "parameter_type_specifier", "init_declarator_list", "single_declaration",
  "fully_specified_type", "layout_qualifier", "layout_qualifier_id_list",
  "layout_qualifier_id", "interpolation_qualifier",
  "parameter_type_qualifier", "type_qualifier", "storage_qualifier",
  "type_specifier", "type_specifier_no_prec", "type_specifier_array",
  "type_specifier_nonarray", "basic_type_specifier_nonarray",
  "texture_type_specifier_nonarray",
  "outputstream_type_specifier_nonarray",
  "inputpatch_type_specifier_nonarray",
  "outputpatch_type_specifier_nonarray", "precision_qualifier",
  "struct_specifier", "cbuffer_declaration", "struct_declaration_list",
  "struct_declaration", "struct_type_specifier", "struct_type_qualifier",
  "struct_declarator_list", "struct_declarator", "array_identifier",
  "initializer", "initializer_list", "declaration_statement", "statement",
  "simple_statement", "compound_statement", "$@2",
  "statement_no_new_scope", "compound_statement_no_new_scope",
  "statement_list", "expression_statement", "selection_statement",
  "selection_rest_statement", "condition", "switch_statement",
  "switch_body", "case_label", "case_label_list", "case_statement",
  "case_statement_list", "iteration_statement", "for_init_statement",
  "conditionopt", "for_rest_statement", "jump_statement",
  "external_declaration", "attribute_arg", "attribute_arg_list",
  "attribute", "attribute_list", "function_definition",
  "global_declaration", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
      40,    41,    91,    93,    46,    44,    43,    45,    33,   126,
      42,    47,    37,    60,    62,    38,    94,   124,    63,    58,
      61,    59,   123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   234,   236,   235,   237,   237,   237,   238,   238,   239,
     239,   240,   240,   240,   240,   240,   240,   241,   241,   241,
     241,   241,   241,   242,   243,   244,   244,   245,   245,   246,
     246,   247,   247,   248,   249,   249,   249,   250,   250,   251,
     251,   252,   252,   253,   254,   254,   254,   254,   254,   255,
     255,   255,   255,   256,   256,   256,   256,   257,   257,   257,
     258,   258,   258,   259,   259,   259,   259,   259,   260,   260,
     260,   261,   261,   262,   262,   263,   263,   264,   264,   265,
     265,   266,   266,   267,   267,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   269,   269,   270,   271,
     272,   273,   273,   273,   274,   274,   275,   275,   276,   276,
     277,   277,   278,   278,   278,   278,   278,   279,   279,   279,
     279,   279,   279,   279,   279,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   281,   282,   282,   282,   282,
     282,   282,   282,   283,   283,   283,   283,   283,   283,   283,
     283,   284,   284,   285,   286,   286,   287,   287,   288,   288,
     288,   289,   289,   289,   289,   289,   290,   290,   290,   290,
     290,   290,   290,   290,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   292,
     292,   293,   293,   294,   294,   294,   294,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   298,   298,   298,   299,
     300,   301,   301,   301,   302,   302,   302,   302,   302,   302,
     303,   304,   304,   305,   306,   306,   307,   307,   307,   307,
     308,   308,   309,   309,   309,   309,   310,   310,   311,   311,
     312,   312,   312,   313,   314,   314,   314,   314,   315,   315,
     315,   315,   315,   315,   316,   317,   316,   318,   318,   319,
     319,   320,   320,   321,   321,   322,   323,   323,   324,   324,
     325,   326,   326,   327,   327,   328,   328,   329,   329,   330,
     330,   331,   331,   331,   332,   332,   333,   333,   334,   334,
     335,   335,   335,   335,   335,   336,   336,   337,   337,   338,
     338,   339,   339,   339,   339,   340,   340,   341,   341,   342,
     342,   342,   342
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     4,     1,
       3,     2,     2,     1,     1,     1,     3,     2,     2,     2,
       1,     2,     3,     2,     1,     1,     1,     2,     2,     2,
       1,     2,     3,     2,     1,     2,     2,     2,     4,     1,
       1,     1,     1,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       4,     1,     2,     1,     2,     4,     1,     1,     2,     3,
       3,     4,     2,     4,     4,     2,     7,     3,     3,     4,
       2,     2,     1,     3,     2,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     5,     3,
       7,     5,     5,     1,     2,     4,     2,     6,     4,     4,
       2,     1,     2,     4,     1,     3,     1,     3,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     2,     1,
       2,     2,     3,     1,     1,     1,     2,     1,     1,     2,
       2,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       2,     1,     1,     3,     3,     4,     4,     1,     1,     6,
       4,     4,     6,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     7,     4,     4,     6,     3,
       5,     1,     2,     3,     1,     2,     1,     2,     2,     1,
       1,     3,     1,     1,     3,     6,     4,     4,     1,     3,
       1,     3,     2,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     2,     0,     4,     1,     1,     2,
       3,     1,     2,     1,     2,     5,     3,     1,     1,     4,
       5,     2,     3,     3,     2,     1,     2,     2,     2,     1,
       2,     5,     7,     6,     1,     1,     1,     0,     2,     3,
       2,     2,     2,     3,     2,     1,     1,     1,     1,     1,
       3,     3,     3,     6,     6,     2,     1,     2,     3,     1,
       2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     1,   174,   212,   207,   208,   210,   211,
     206,     0,     0,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   213,   214,   215,   219,   220,   221,   216,   217,
     218,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   276,   277,
     278,   279,   280,   177,   178,   181,   175,     0,   173,   159,
     158,   160,   187,   188,   283,   282,   281,     0,   260,   270,
     261,   262,   271,   272,   263,   264,   273,   274,   265,   266,
     267,   275,   268,   269,   258,   259,   205,     0,   184,   209,
     182,   183,     0,     0,     3,   379,   381,     0,     0,   107,
     106,     0,   136,   143,   167,   169,     0,   166,   151,   189,
     192,   191,   197,   198,     0,     0,     0,     0,   204,   382,
       7,   376,     0,   365,   366,   185,     4,     5,     6,     0,
       0,     0,   179,   180,   176,     9,    10,   150,     0,   171,
       0,   173,     0,   186,     0,     0,     0,     8,    99,     0,
     377,   104,     0,   165,   130,   131,   132,   133,   134,   125,
     126,   127,   164,   122,   108,     0,   161,     0,     0,     0,
     380,     4,     6,   144,     0,   146,   168,   170,   152,     0,
       0,     0,     0,     0,     0,   190,     0,     0,   375,   299,
     289,   296,   294,     0,   291,     0,     0,     0,     0,     0,
     172,     0,     0,   156,     0,   154,     0,   371,     0,   372,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    12,    13,    15,    36,     0,    49,    50,    51,
      52,   333,   325,   329,    11,    17,    44,    19,    24,    25,
       0,     0,    30,     0,    53,     0,    57,    60,    63,    68,
      71,    73,    75,    77,    79,    81,    83,    96,     0,   101,
     103,   313,     0,     0,   151,   318,   331,   315,   314,     0,
     319,   320,   321,   322,   323,     0,     0,   109,   128,   129,
     162,   120,   124,     0,   135,   163,   121,     0,   112,   115,
     137,   139,     0,     0,   110,     0,     0,   194,    53,    98,
       0,    34,   193,     0,     0,     0,     0,     0,   378,   297,
     298,   286,   292,   302,     0,   300,   303,   295,     0,   287,
       0,     0,   100,   111,     0,   153,     0,   368,   367,   369,
       0,     0,   361,   360,     0,     0,     0,     0,   364,   362,
       0,     0,    45,    46,     0,   191,   324,     0,    21,    22,
       0,     0,    28,    27,     0,   206,    31,    33,    86,    87,
      89,    88,    91,    92,    93,    94,    95,    90,    85,     0,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   334,   102,   330,   332,   317,   316,   105,   118,   117,
     123,     0,     0,     0,     0,     0,     0,     0,   145,     0,
       0,   308,   149,     0,   148,   196,   195,     0,   200,   201,
       0,     0,     0,     0,     0,   293,     0,   284,   290,   157,
     155,     0,     0,     0,     0,   338,     0,     0,   355,   354,
     357,     0,   363,     0,    16,     0,     0,     0,    23,    20,
       0,    26,     0,     0,    40,    32,    84,    54,    55,    56,
      58,    59,    61,    62,    66,    67,    64,    65,    69,    70,
      72,    74,    76,    78,    80,     0,    97,   119,     0,   114,
     113,   138,   142,   141,     0,   306,   310,     0,   307,     0,
       0,     0,     0,   304,   301,   288,     0,   373,   370,   374,
       0,     0,     0,   356,     0,     0,     0,     0,    48,   326,
      18,    43,    38,    37,     0,   206,    41,     0,   306,     0,
     147,   312,   309,   199,   202,   203,   306,   285,     0,     0,
     328,   351,   327,   358,     0,   337,   335,     0,   340,    42,
      82,     0,   140,   311,     0,     0,   339,   359,   353,     0,
       0,     0,   341,   345,     0,   349,     0,   116,   305,   352,
     336,   344,     0,   347,   346,   348,   342,   350,   343
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   213,   104,   244,   245,   246,   457,   247,
     248,   249,   250,   251,   252,   253,   461,   462,   463,   464,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   379,   268,   338,   269,   270,   271,
     272,   108,   109,   110,   173,   174,   175,   292,   273,   112,
     113,   114,   214,   215,   115,   177,   116,   117,   311,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     203,   204,   205,   206,   324,   325,   299,   422,   497,   275,
     276,   277,   278,   357,   541,   542,   279,   280,   281,   546,
     447,   282,   548,   563,   564,   565,   566,   283,   450,   514,
     515,   284,   130,   339,   340,   131,   285,   133,   134
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -277
static const yytype_int16 yypact[] =
{
    -277,    54,  5483,  -277,  -105,  -277,  -277,  -277,  -277,  -277,
    -277,  -112,    77,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,    76,   230,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,   133,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  5861,    82,  -277,
    -277,  -277,  -120,  6914,  5483,  -277,  -277,  -113,   -98,  -116,
    6050,  -152,  -277,   102,   357,   357,  6626,  -277,  -277,  -277,
    -108,  -106,  -277,   -76,   -69,   -59,   -51,  6770,  -277,  -277,
    -277,  -277,  5672,  -277,  -277,  -277,  -277,  -277,  -277,  2007,
    -186,   -41,  -277,  -277,  -277,  -277,  -277,  -277,   357,  -277,
    6770,   389,   -66,  -277,    77,   -57,   -47,  -277,  -277,   638,
    -277,   -36,  6050,  -277,  -277,  -277,  -277,  -277,  -277,   117,
     123,  -277,   160,  -277,  -277,  6194,   121,  6338,    77,    77,
    -277,     9,    21,  -163,    47,  -161,  -277,  -277,  -277,  3891,
    4090,  7058,   122,   129,   130,  -277,    30,   -66,  -277,   160,
    -277,   192,  -277,  2152,  -277,    77,  6626,   135,  2297,  6482,
    -277,    50,    72,    56,  -115,  -277,  4289,  -277,  4289,  -277,
      61,    63,  1561,    75,    86,    87,    69,  3458,    92,  4886,
    4886,  -277,  -277,  -277,  -277,  -277,  4886,  -277,  -277,  -277,
    -277,  -277,    71,  -277,    96,  -277,   -81,  -277,  -277,  -277,
      97,  -110,  5085,   104,    80,  4886,    34,   -14,    55,   -97,
     111,    62,    81,    91,   199,  -119,  -277,  -277,  -150,  -277,
    -277,  -277,    94,  -149,   116,  -277,  -277,  -277,  -277,   869,
    -277,  -277,  -277,  -277,  -277,  1561,    77,  -277,  -277,  -277,
    -277,  -277,  -277,  6626,    77,  -277,  -277,  6194,  -182,   118,
    -160,  -159,  4488,  3242,  -277,  4886,  3242,  -277,  -277,  -277,
     119,  -277,  -277,   120,  -132,   107,   124,   125,  -277,  -277,
    -277,  -277,  -277,  -170,  -147,  -277,   118,  -277,   103,  -277,
    2442,  2587,  -277,  -277,   194,  -277,    77,  -277,  -277,  -277,
    -100,   -50,  -277,  -277,   323,  3675,  3026,  4886,  -277,  -277,
    -142,  4886,  -277,  -277,   -37,    14,  -277,  1561,  -277,  -277,
    4886,   102,  -277,  -277,  4886,   131,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  4886,
    -277,  4886,  4886,  4886,  4886,  4886,  4886,  4886,  4886,  4886,
    4886,  4886,  4886,  4886,  4886,  4886,  4886,  4886,  4886,  4886,
    4886,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  6626,  4886,    77,  4886,  4687,  3242,  3242,   115,   136,
    3242,  -277,  -277,   137,  -277,  -277,  -277,   208,  -277,  -277,
     212,   213,  4886,    77,    77,  -277,  2732,  -277,  -277,  -277,
    -277,   141,  4289,   144,   151,   147,    77,   152,  -277,  -277,
    3675,   -34,  -277,   -31,  -277,  4886,  1100,   153,   147,  -277,
     154,  -277,   157,   -26,  5284,  -277,  -277,  -277,  -277,  -277,
      34,    34,   -14,   -14,    55,    55,    55,    55,   -97,   -97,
     111,    62,    81,    91,   199,  -171,  -277,  -277,   156,  -277,
    -277,   140,  -277,  -277,  3242,  -277,  -277,  -158,  -277,   148,
     149,   155,   162,  -277,  -277,  -277,  2877,  -277,  -277,  -277,
    4886,   150,  1791,  -277,   134,   166,  1561,   146,  -277,  -277,
    -277,  -277,  -277,  -277,  4886,   170,  -277,  4886,   159,  3242,
    -277,  3242,  -277,  -277,  -277,  -277,   161,  -277,   -23,  3242,
    -277,  -277,  -277,  4886,  1791,   368,  -277,    -9,  -277,  -277,
    -277,    77,  -277,  -277,    77,   158,  -277,   147,  -277,  1561,
     164,  4886,  -277,  -277,  1331,  1561,    -6,  -277,  -277,  -277,
    -277,  -277,  -138,  -277,  -277,  -277,  -277,  1561,  -277
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -277,  -277,  -277,   -10,  -277,   -58,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
     197,  -277,  -141,  -117,  -192,  -121,   -11,    -1,   -12,     1,
     -13,  -277,  -154,  -127,  -277,  -205,  -173,    13,    19,  -277,
      18,  -277,  -277,  -277,  -148,   233,   219,   108,    24,  -277,
     -92,  -277,  -277,    65,   -65,  -156,  -277,   -27,    -2,   -90,
    -277,   163,   -75,  -277,  -277,  -277,  -277,   329,  -277,  -277,
    -196,  -195,  -277,  -277,  -277,   -24,  -107,  -230,  -277,    68,
    -218,  -276,   126,  -277,  -137,   -84,    51,    70,  -277,  -277,
     -33,  -277,  -277,  -146,  -277,  -145,  -277,  -277,  -277,  -277,
    -277,  -277,   315,   -22,   204,  -114,    48,  -277,  -277
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -40
static const yytype_int16 yytable[] =
{
     118,   140,   141,   148,   344,   152,   185,   398,   322,   405,
     147,   560,   330,   331,   560,   105,   310,   313,   198,   293,
     107,   106,   350,   160,   388,   389,   111,   291,   156,   296,
     412,   354,   136,   137,   138,   309,   309,   195,   358,   359,
     197,   149,   432,   207,   400,   176,   208,   413,   414,   302,
     132,   305,   415,   305,     3,   184,   135,   531,   527,   433,
     211,   404,   309,   179,   309,   400,   179,   303,   434,   306,
     416,   417,   301,   400,   201,   532,   424,   400,   145,   180,
     146,   401,   402,   427,   435,   153,   148,   186,   187,   452,
     154,   578,   428,   155,   212,   118,   335,   176,   326,   162,
     336,   363,   118,   183,   189,   364,   190,   290,   178,   399,
     176,   441,   318,   161,   188,   442,   314,   105,   158,   159,
     139,   210,   107,   106,   149,   366,   390,   391,   111,   419,
     118,   360,   423,   361,   319,   322,   322,   202,   201,   184,
     445,   411,   451,   201,   201,   408,   453,   191,   309,   409,
     196,   309,   132,   216,   192,   458,   217,   274,   142,   143,
     178,   443,   144,   218,   193,   442,   219,   561,   298,   300,
     561,   198,   194,   294,   454,   178,   421,   516,   400,   421,
     517,   400,   386,   387,   400,   523,   492,   493,   555,   524,
     496,   209,   400,   286,   485,   323,   474,   475,   476,   477,
     288,   202,   384,   385,   327,   289,   202,   202,   295,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,    -9,
     274,   136,   137,   138,   562,   455,   190,   576,    74,    75,
      76,   -10,   176,     4,   392,   393,   540,   465,   404,   488,
     506,   490,   419,   470,   471,   445,   181,   137,   182,    69,
      70,    71,   466,   446,   381,   382,   383,   304,   309,   502,
     309,   309,   159,   487,   530,   201,   201,   315,   540,   472,
     473,   478,   479,   486,   316,   317,   407,   274,   309,   320,
     328,   332,   333,   274,   298,   345,   334,   394,   309,   421,
     421,   178,   342,   421,   343,   294,   346,   347,   545,   552,
     348,   553,   351,   460,   356,   538,   -35,   395,   362,   556,
     378,   322,    63,    64,   367,    65,    66,    67,   396,    69,
      70,    71,    72,    73,   397,   158,   -34,   326,   202,   202,
     305,   429,   425,   426,   439,   436,   444,   526,   557,   430,
     431,   570,   -29,   274,   274,   494,   573,   575,   499,   495,
     498,   459,   500,   501,   507,   274,   572,   509,   446,   575,
       4,   510,   400,   512,   521,   543,   520,   421,   522,   528,
     529,   201,   533,   534,   145,   536,   146,   544,   547,   535,
     539,   -39,   559,   480,   482,   484,   308,   308,   551,   569,
     554,    98,     4,   571,   481,   287,   297,   549,   483,   355,
     550,   440,   421,   489,   421,   410,   150,   558,   456,   178,
     504,   406,   421,   308,   448,   308,   449,   513,   574,   157,
     508,   577,   341,   503,   323,     0,   352,   353,     0,     0,
       0,     0,     0,     0,   202,     0,   511,   100,   101,    63,
      64,   201,    65,    66,    67,     0,     0,     0,   274,    72,
      73,     0,   380,     0,   274,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    63,    64,     0,    65,    66,    67,     0,    69,    70,
      71,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   308,
       0,     0,   308,     0,   202,     0,     0,     0,     0,     0,
     274,     0,     0,     0,   274,     0,     0,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   567,   274,     0,   568,     0,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,     0,   274,     0,     0,
       0,     0,   274,   274,   100,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,     0,   467,   468,
     469,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   100,   101,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   308,
       0,   308,   308,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   308,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   308,
       0,     4,     5,     6,     7,     8,     9,    10,   220,   221,
     222,   223,   518,   224,   225,   226,   227,   228,     0,    11,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    59,    60,    61,    62,
      63,    64,     0,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,    94,    95,   229,   230,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   231,   232,   233,
     234,     0,   145,    96,   146,   235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,     0,     0,     0,    98,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,   101,   102,   236,     0,
     103,     0,     0,     0,   237,   238,   239,   240,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   241,
     242,   243,     4,     5,     6,     7,     8,     9,    10,   220,
     221,   222,   223,     0,   224,   225,   226,   227,   228,     0,
      11,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,    63,    64,     0,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,    91,    92,    93,    94,    95,   229,   230,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   231,   232,
     233,   234,     0,   145,    96,   146,   235,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    97,     0,     0,     0,
      98,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   101,   102,   236,
       0,   103,     0,     0,     0,   237,   238,   239,   240,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     241,   242,   403,     4,     5,     6,     7,     8,     9,    10,
     220,   221,   222,   223,     0,   224,   225,   226,   227,   228,
       0,    11,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,    60,
      61,    62,    63,    64,     0,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,    94,    95,   229,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   231,
     232,   233,   234,     0,   145,    96,   146,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,     0,     0,
       0,    98,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     236,     0,   103,     0,     0,     0,   237,   238,   239,   240,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   241,   242,   519,     4,     5,     6,     7,     8,     9,
      10,   220,   221,   222,   223,     0,   224,   225,   226,   227,
     228,   560,    11,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,    92,    93,    94,    95,
     229,   230,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     231,   232,   233,   234,     0,   145,    96,   146,   235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,    98,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,   561,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   236,     0,   103,     0,     0,     0,   237,   238,   239,
     240,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   241,   242,     4,     5,     6,     7,     8,     9,
      10,   220,   221,   222,   223,     0,   224,   225,   226,   227,
     228,     0,    11,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,    92,    93,    94,    95,
     229,   230,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     231,   232,   233,   234,     0,   145,    96,   146,   235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,    98,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   236,     0,   103,     0,     0,     0,   237,   238,   239,
     240,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   241,   242,     4,     5,     6,     7,     8,     9,
      10,   220,   221,   222,   223,     0,   224,   225,   226,   227,
     228,     0,    11,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,    92,    93,    94,    95,
     229,   230,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     231,   232,   233,   234,     0,   145,    96,   146,   235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,    98,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   236,     0,     0,     0,     0,     0,   237,   238,   239,
     240,     5,     6,     7,     8,     9,    10,     0,     0,     0,
       0,     0,   241,   159,     0,     0,     0,     0,    11,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,   199,     0,    69,    70,    71,     0,
       0,     0,    74,    75,    76,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,     0,     0,     0,     5,     6,     7,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    99,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,    62,     0,     0,     0,     0,     0,   199,
     200,    69,    70,    71,     0,     0,     0,    74,    75,    76,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     5,     6,     7,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    99,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,   199,   321,    69,    70,    71,     0,
       0,     0,    74,    75,    76,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,     0,     0,     0,     5,     6,     7,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    99,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,    62,     0,     0,     0,     0,     0,   199,
     329,    69,    70,    71,     0,     0,     0,    74,    75,    76,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     5,     6,     7,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    99,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,   199,   437,    69,    70,    71,     0,
       0,     0,    74,    75,    76,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,     0,     0,     0,     5,     6,     7,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    99,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,    62,     0,     0,     0,     0,     0,   199,
     438,    69,    70,    71,     0,     0,     0,    74,    75,    76,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     5,     6,     7,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,    99,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,   199,   505,    69,    70,    71,     0,
       0,     0,    74,    75,    76,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,     0,     0,     0,     0,     0,     0,     4,
       5,     6,     7,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,    11,     0,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    61,    62,    63,    64,
     537,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      91,    92,    93,    94,    95,   229,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   231,   232,   233,   234,     0,
     145,    96,   146,   235,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,     0,     0,    98,     0,     0,
       0,     0,     0,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   236,     0,     0,     0,
       0,     0,   237,   238,   239,   240,     5,     6,     7,     8,
       9,    10,     0,     0,     0,     0,     0,   241,     0,     0,
       0,     0,     0,    11,     0,     0,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,    92,    93,    94,
      95,   229,   230,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   231,   232,   233,   234,     0,   145,    96,   146,   235,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,     0,     0,     0,     0,   237,   238,
     239,   240,     5,     6,     7,     8,     9,    10,     0,     0,
       0,     0,     0,     0,   420,     0,     0,     0,     0,    11,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    75,    76,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,    94,    95,   229,   230,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   231,   232,   233,
     234,     0,   145,    96,   146,   235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,     0,     0,   237,   238,   239,   240,     4,     5,
       6,     7,     8,     9,    10,     0,     0,     0,     0,   349,
       0,     0,     0,     0,     0,     0,    11,     0,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,    63,    64,     0,
      65,    66,    67,   151,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,    91,
      92,    93,    94,    95,   229,   230,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   231,   232,   233,   234,     0,   145,
      96,   146,   235,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    98,     0,     0,     0,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   236,     0,     0,     0,     0,
       0,   237,   238,   239,   240,     5,     6,     7,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    75,    76,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,    92,    93,    94,    95,
     229,   230,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     231,   232,   233,   234,     0,   145,    96,   146,   235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
       0,   236,     0,     0,   307,     0,     0,   237,   238,   239,
     240,    11,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    76,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,    94,    95,   229,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   231,
     232,   233,   234,     0,   145,    96,   146,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,     0,
     236,     0,     0,   312,     0,     0,   237,   238,   239,   240,
      11,     0,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    74,    75,    76,     0,     0,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,    91,    92,    93,    94,    95,   229,   230,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   231,   232,
     233,   234,   337,   145,    96,   146,   235,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    99,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,    10,     0,   236,
       0,     0,     0,     0,     0,   237,   238,   239,   240,    11,
       0,     0,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    59,    60,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    75,    76,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,    94,    95,   229,   230,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   231,   232,   233,
     234,     0,   145,    96,   146,   235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,    10,     0,   236,     0,
       0,   418,     0,     0,   237,   238,   239,   240,    11,     0,
       0,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,    76,     0,     0,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,    91,    92,    93,    94,    95,   229,   230,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   231,   232,   233,   234,
       0,   145,    96,   146,   235,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,     0,   236,     0,     0,
     491,     0,     0,   237,   238,   239,   240,    11,     0,     0,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    61,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    75,    76,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      91,    92,    93,    94,    95,   229,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   231,   232,   233,   234,     0,
     145,    96,   146,   235,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     8,     9,   365,     0,   236,     0,     0,     0,
       0,     0,   237,   238,   239,   240,    11,     0,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    75,    76,     0,     0,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,    91,
      92,    93,    94,    95,   229,   230,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   231,   232,   233,   234,     0,   145,
      96,   146,   235,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,   525,     0,   236,     0,     0,     0,     0,
       0,   237,   238,   239,   240,    11,     0,     0,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     0,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      75,    76,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    91,    92,
      93,    94,    95,   229,   230,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   231,   232,   233,   234,     0,   145,    96,
     146,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,     6,     7,
       8,     9,    10,     0,   236,     0,     0,     0,     0,     0,
     237,   238,   239,   240,    11,    12,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,     0,     0,     0,     0,     0,     0,     0,     0,
      58,    59,    60,    61,    62,    63,    64,     0,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      97,     0,     0,     0,    98,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
     100,   101,   102,    11,     0,   103,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,    62,    63,    64,     0,    65,    66,    67,
     151,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
       0,     0,     0,    98,     0,     0,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     6,     7,     8,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     101,   102,    11,     0,   103,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,    63,    64,     0,    65,    66,    67,   151,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   101,
     102,    11,     0,     0,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,   164,   165,   166,   167,   168,    58,    59,    60,
      61,    62,   169,   170,   171,     0,     0,   172,     0,    69,
      70,    71,     0,     0,     0,    74,    75,    76,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,     0,   163,     5,     6,
       7,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,    99,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     0,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,    61,    62,     0,     0,     0,     0,
       0,   172,     0,    69,    70,    71,     0,     0,     0,    74,
      75,    76,     0,     0,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
       0,     0,     5,     6,     7,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,    99,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,     0,     0,
     164,   165,   166,   167,   168,    58,    59,    60,    61,    62,
     169,   170,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    75,    76,     0,     0,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    96,     0,     0,     5,     6,     7,     8,
       9,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,     0,    99,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      59,    60,    61,    62,     0,     0,     0,     0,     0,   199,
       0,    69,    70,    71,     0,     0,     0,    74,    75,    76,
       0,     0,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,     0,     0,
       5,     6,     7,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,    99,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    60,    61,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    75,    76,     0,     0,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    96,     0,     0,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,    99,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    96,     0,     0,     5,     6,
       7,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    99,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   136,   137,
     138,     0,     5,     6,     7,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    99,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-277)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       2,    11,    12,    68,   222,    97,   113,   126,   203,   285,
      68,    20,   208,   209,    20,     2,   189,   190,   132,   175,
       2,     2,   227,   107,   121,   122,     2,   175,   103,   177,
     212,   236,   144,   145,   146,   189,   190,   127,   119,   120,
     132,    68,   212,   229,   215,   110,   232,   229,   230,   212,
       2,   212,   212,   212,     0,   113,   161,   215,   229,   229,
     150,   279,   216,   215,   218,   215,   215,   230,   215,   230,
     230,   230,   179,   215,   139,   233,   306,   215,   144,   231,
     146,   231,   231,   215,   231,     3,   151,   114,   115,   231,
     210,   229,   224,   103,   152,    97,   211,   162,   205,   215,
     215,   211,   104,   113,   212,   215,   212,   172,   110,   228,
     175,   211,   196,   211,   116,   215,   191,   104,   231,   232,
     232,   148,   104,   104,   151,   252,   223,   224,   104,   302,
     132,   212,   305,   214,   199,   330,   331,   139,   203,   197,
     345,   297,   347,   208,   209,   293,   351,   223,   302,   297,
     132,   305,   104,   210,   223,   360,   213,   159,    82,    83,
     162,   211,    86,   210,   223,   215,   213,   176,   178,   179,
     176,   285,   223,   175,   211,   177,   303,   211,   215,   306,
     211,   215,   127,   128,   215,   211,   416,   417,   211,   215,
     420,   232,   215,   229,   399,   205,   388,   389,   390,   391,
      83,   203,   216,   217,   206,    82,   208,   209,    87,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   210,
     222,   144,   145,   146,   233,   211,   212,   233,    95,    96,
      97,   210,   297,     3,   123,   124,   512,   364,   456,   412,
     436,   414,   415,   384,   385,   450,   144,   145,   146,    89,
      90,    91,   379,   345,   220,   221,   222,   210,   412,   432,
     414,   415,   232,   411,   494,   330,   331,   145,   544,   386,
     387,   392,   393,   400,   145,   145,   286,   279,   432,    87,
     145,   231,   210,   285,   294,   210,   230,   225,   442,   416,
     417,   293,   231,   420,   231,   297,   210,   210,   516,   529,
     231,   531,   210,   361,   233,   510,   210,   226,   211,   539,
     230,   506,    82,    83,   210,    85,    86,    87,   227,    89,
      90,    91,    92,    93,   125,   231,   210,   434,   330,   331,
     212,   224,   213,   213,   140,   232,    13,   464,   543,   215,
     215,   559,   211,   345,   346,   230,   564,   565,   140,   213,
     213,   361,   140,   140,   213,   357,   561,   213,   450,   577,
       3,   210,   215,   211,   210,   231,   213,   494,   211,   213,
     230,   436,   224,   224,   144,   213,   146,   211,   232,   224,
     230,   211,    14,   394,   396,   398,   189,   190,   229,   231,
     229,   161,     3,   229,   395,   162,   177,   524,   397,   236,
     527,   336,   529,   413,   531,   297,    77,   544,   357,   411,
     434,   285,   539,   216,   346,   218,   346,   450,   564,   104,
     442,   566,   218,   433,   434,    -1,   229,   230,    -1,    -1,
      -1,    -1,    -1,    -1,   436,    -1,   446,   207,   208,    82,
      83,   506,    85,    86,    87,    -1,    -1,    -1,   450,    92,
      93,    -1,   255,    -1,   456,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    83,    -1,    85,    86,    87,    -1,    89,    90,
      91,    92,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   302,
      -1,    -1,   305,    -1,   506,    -1,    -1,    -1,    -1,    -1,
     512,    -1,    -1,    -1,   516,    -1,    -1,    -1,   161,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   551,   544,    -1,   554,    -1,    -1,    -1,    -1,    -1,
     161,    -1,    -1,    -1,    -1,    -1,    -1,   559,    -1,    -1,
      -1,    -1,   564,   565,   207,   208,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   577,    -1,    -1,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   207,   208,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   412,
      -1,   414,   415,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   432,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,   455,    15,    16,    17,    18,    19,    -1,    21,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,
      82,    83,    -1,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    -1,    95,    96,    97,    -1,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,    -1,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,   161,
      -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   207,   208,   209,   210,    -1,
     212,    -1,    -1,    -1,   216,   217,   218,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,
     232,   233,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    -1,    15,    16,    17,    18,    19,    -1,
      21,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    95,    96,    97,    -1,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,    -1,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,    -1,
     161,    -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   207,   208,   209,   210,
      -1,   212,    -1,    -1,    -1,   216,   217,   218,   219,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     231,   232,   233,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    -1,    15,    16,    17,    18,    19,
      -1,    21,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    81,    82,    83,    -1,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    -1,    95,    96,    97,    -1,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,    -1,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,    -1,
      -1,   161,    -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,   209,
     210,    -1,   212,    -1,    -1,    -1,   216,   217,   218,   219,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   231,   232,   233,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,    83,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,   141,   142,    -1,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
     209,   210,    -1,   212,    -1,    -1,    -1,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   232,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    -1,    21,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,    83,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,   141,   142,    -1,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
     209,   210,    -1,   212,    -1,    -1,    -1,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   231,   232,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    15,    16,    17,    18,
      19,    -1,    21,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,    83,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    -1,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,   141,   142,    -1,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,    -1,
      -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
     209,   210,    -1,    -1,    -1,    -1,    -1,   216,   217,   218,
     219,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,   231,   232,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    89,    90,    91,    -1,
      -1,    -1,    95,    96,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,    -1,    -1,    -1,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,   167,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,    87,
     233,    89,    90,    91,    -1,    -1,    -1,    95,    96,    97,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,
      -1,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,   167,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,    -1,
      -1,    -1,    -1,    -1,    87,   233,    89,    90,    91,    -1,
      -1,    -1,    95,    96,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,    -1,    -1,    -1,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,   167,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,    87,
     233,    89,    90,    91,    -1,    -1,    -1,    95,    96,    97,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,
      -1,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,   167,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,    -1,
      -1,    -1,    -1,    -1,    87,   233,    89,    90,    91,    -1,
      -1,    -1,    95,    96,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,    -1,    -1,    -1,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,   167,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,    87,
     233,    89,    90,    91,    -1,    -1,    -1,    95,    96,    97,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,
      -1,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,   167,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,    -1,
      -1,    -1,    -1,    -1,    87,   233,    89,    90,    91,    -1,
      -1,    -1,    95,    96,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,    -1,    -1,    21,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    81,    82,    83,
     233,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      -1,    95,    96,    97,    -1,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,    -1,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,   161,    -1,    -1,
      -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   207,   208,   209,   210,    -1,    -1,    -1,
      -1,    -1,   216,   217,   218,   219,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    -1,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   139,   140,   141,   142,    -1,   144,   145,   146,   147,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,    -1,    -1,    -1,    -1,    -1,   216,   217,
     218,   219,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,   232,    -1,    -1,    -1,    -1,    21,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,    -1,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,
      -1,    -1,    -1,    -1,   216,   217,   218,   219,     3,     4,
       5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,   231,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    80,    81,    82,    83,    -1,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      95,    96,    97,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,   141,   142,    -1,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,    -1,    -1,    -1,
      -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   207,   208,   209,   210,    -1,    -1,    -1,    -1,
      -1,   216,   217,   218,   219,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    96,    97,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,   140,   141,   142,    -1,   144,   145,   146,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,     9,
      -1,   210,    -1,    -1,   213,    -1,    -1,   216,   217,   218,
     219,    21,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    96,    97,    -1,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,
     140,   141,   142,    -1,   144,   145,   146,   147,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,     6,     7,     8,     9,    -1,
     210,    -1,    -1,   213,    -1,    -1,   216,   217,   218,   219,
      21,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    96,    97,    -1,    -1,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    -1,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,
     141,   142,   143,   144,   145,   146,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,     6,     7,     8,     9,    -1,   210,
      -1,    -1,    -1,    -1,    -1,   216,   217,   218,   219,    21,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,
     142,    -1,   144,   145,   146,   147,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,     7,     8,     9,    -1,   210,    -1,
      -1,   213,    -1,    -1,   216,   217,   218,   219,    21,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    96,    97,    -1,    -1,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      -1,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,
      -1,   144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,     6,     7,     8,     9,    -1,   210,    -1,    -1,
     213,    -1,    -1,   216,   217,   218,   219,    21,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    -1,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   139,   140,   141,   142,    -1,
     144,   145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,     7,     8,     9,    -1,   210,    -1,    -1,    -1,
      -1,    -1,   216,   217,   218,   219,    21,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    80,    81,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    96,    97,    -1,    -1,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,    -1,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   139,   140,   141,   142,    -1,   144,
     145,   146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
       6,     7,     8,     9,    -1,   210,    -1,    -1,    -1,    -1,
      -1,   216,   217,   218,   219,    21,    -1,    -1,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      96,    97,    -1,    -1,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   139,   140,   141,   142,    -1,   144,   145,
     146,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,     9,    -1,   210,    -1,    -1,    -1,    -1,    -1,
     216,   217,   218,   219,    21,    22,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    80,    81,    82,    83,    -1,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    95,    96,
      97,    -1,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    -1,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     157,    -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,
     167,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     207,   208,   209,    21,    -1,   212,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    82,    83,    -1,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    -1,    95,    96,    97,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   157,
      -1,    -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,   167,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
     208,   209,    21,    -1,   212,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,    83,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    95,    96,    97,    -1,
      -1,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,    -1,   114,   115,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,    -1,    -1,    -1,    -1,    -1,   167,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,   208,
     209,    21,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    -1,    -1,    87,    -1,    89,
      90,    91,    -1,    -1,    -1,    95,    96,    97,    -1,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,    -1,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,   167,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    89,    90,    91,    -1,    -1,    -1,    95,
      96,    97,    -1,    -1,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    -1,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,
      -1,    -1,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,   167,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    -1,    -1,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    96,    97,    -1,    -1,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    -1,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,    -1,    -1,     4,     5,     6,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    -1,   167,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    89,    90,    91,    -1,    -1,    -1,    95,    96,    97,
      -1,    -1,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    -1,   114,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,
       4,     5,     6,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,   167,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    96,    97,    -1,    -1,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    -1,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   145,    -1,    -1,     4,     5,     6,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    -1,   167,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   145,    -1,    -1,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,   145,
     146,    -1,     4,     5,     6,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   167
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   235,   236,     0,     3,     4,     5,     6,     7,     8,
       9,    21,    22,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    77,    78,
      79,    80,    81,    82,    83,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    95,    96,    97,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   114,   115,   116,   117,   118,   145,   157,   161,   167,
     207,   208,   209,   212,   238,   271,   272,   274,   275,   276,
     277,   282,   283,   284,   285,   288,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     336,   339,   340,   341,   342,   161,   144,   145,   146,   232,
     237,   237,    82,    83,    86,   144,   146,   239,   288,   291,
     301,    88,   284,     3,   210,   237,   296,   336,   231,   232,
     319,   211,   215,     3,    72,    73,    74,    75,    76,    82,
      83,    84,    87,   278,   279,   280,   288,   289,   292,   215,
     231,   144,   146,   237,   239,   310,   291,   291,   292,   212,
     212,   223,   223,   223,   223,   293,   274,   284,   339,    87,
     233,   288,   292,   304,   305,   306,   307,   229,   232,   232,
     291,   293,   239,   237,   286,   287,   210,   213,   210,   213,
      10,    11,    12,    13,    15,    16,    17,    18,    19,   119,
     120,   139,   140,   141,   142,   147,   210,   216,   217,   218,
     219,   231,   232,   233,   239,   240,   241,   243,   244,   245,
     246,   247,   248,   249,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   269,   271,
     272,   273,   274,   282,   292,   313,   314,   315,   316,   320,
     321,   322,   325,   331,   335,   340,   229,   279,    83,    82,
     288,   278,   281,   289,   292,    87,   278,   280,   237,   310,
     237,   310,   212,   230,   210,   212,   230,   213,   254,   266,
     270,   292,   213,   270,   296,   145,   145,   145,   319,   288,
      87,   233,   305,   237,   308,   309,   310,   292,   145,   233,
     304,   304,   231,   210,   230,   211,   215,   143,   270,   337,
     338,   338,   231,   231,   314,   210,   210,   210,   231,   231,
     269,   210,   254,   254,   269,   295,   233,   317,   119,   120,
     212,   214,   211,   211,   215,     9,   267,   210,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   230,   268,
     254,   220,   221,   222,   216,   217,   127,   128,   121,   122,
     223,   224,   123,   124,   225,   226,   227,   125,   126,   228,
     215,   231,   231,   233,   314,   315,   316,   237,   278,   278,
     281,   289,   212,   229,   230,   212,   230,   230,   213,   270,
     232,   267,   311,   270,   311,   213,   213,   215,   224,   224,
     215,   215,   212,   229,   215,   231,   232,   233,   233,   140,
     287,   211,   215,   211,    13,   269,   284,   324,   313,   321,
     332,   269,   231,   269,   211,   211,   320,   242,   269,   237,
     239,   250,   251,   252,   253,   267,   267,   254,   254,   254,
     256,   256,   257,   257,   258,   258,   258,   258,   259,   259,
     260,   261,   262,   263,   264,   269,   267,   278,   270,   237,
     270,   213,   311,   311,   230,   213,   311,   312,   213,   140,
     140,   140,   270,   237,   309,   233,   304,   213,   337,   213,
     210,   237,   211,   324,   333,   334,   211,   211,   254,   233,
     213,   210,   211,   211,   215,     9,   267,   229,   213,   230,
     311,   215,   233,   224,   224,   224,   213,   233,   269,   230,
     315,   318,   319,   231,   211,   314,   323,   232,   326,   267,
     267,   229,   311,   311,   229,   211,   311,   269,   318,    14,
      20,   176,   233,   327,   328,   329,   330,   237,   237,   231,
     314,   229,   269,   314,   327,   314,   233,   329,   229
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (&yylloc, state, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, scanner)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, state); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, struct THLSLParserState *state)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, state)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    struct THLSLParserState *state;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (state);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, struct THLSLParserState *state)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, state)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    struct THLSLParserState *state;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, state);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, struct THLSLParserState *state)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, state)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    struct THLSLParserState *state;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , state);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, state); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, struct THLSLParserState *state)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, state)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    struct THLSLParserState *state;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (state);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (struct THLSLParserState *state)
#else
int
yyparse (state)
    struct THLSLParserState *state;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc = yyloc_default;


    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */

{
   yylloc.first_line = 1;
   yylloc.first_column = 1;
   yylloc.last_line = 1;
   yylloc.last_column = 1;
}

  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    {
	   
	}
    break;

  case 3:

    {
	   
	}
    break;

  case 7:

    {
		if((yyvsp[(1) - (1)].node) != NULL)
		{
			state->globalNodes.push_back((yyvsp[(1) - (1)].node));
		}
	}
    break;

  case 8:

    {
		if((yyvsp[(2) - (2)].node) != NULL)
		{
			state->globalNodes.push_back((yyvsp[(2) - (2)].node));
		}
	}
    break;

  case 11:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>((yyvsp[(1) - (1)].identifier));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 12:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>();
		(yyval.expression)->SetSourceLocation(yylloc);
		(yyval.expression)->MakeIntConstant((yyvsp[(1) - (1)].number));
	}
    break;

  case 13:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>();
		(yyval.expression)->SetSourceLocation(yylloc);
		(yyval.expression)->MakeUIntConstant((yyvsp[(1) - (1)].number));
	}
    break;

  case 14:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>();
		(yyval.expression)->SetSourceLocation(yylloc);
		(yyval.expression)->MakeFloatConstant((yyvsp[(1) - (1)].real));
	}
    break;

  case 15:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>();
		(yyval.expression)->SetSourceLocation(yylloc);
		(yyval.expression)->MakeBoolConstant((yyvsp[(1) - (1)].number));
	}
    break;

  case 16:

    {
		(yyval.expression) = (yyvsp[(2) - (3)].expression);
	}
    break;

  case 18:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>(AST::EOperator::ArrayIndex, (yyvsp[(1) - (4)].expression), (yyvsp[(3) - (4)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 19:

    {
		(yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 20:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>(AST::EOperator::FieldSelection, (yyvsp[(1) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
		(yyval.expression)->SetIdentifier((yyvsp[(3) - (3)].identifier));
	}
    break;

  case 21:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>(AST::EOperator::PostIncrement, (yyvsp[(1) - (2)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 22:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>(AST::EOperator::PostDecrement, (yyvsp[(1) - (2)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 26:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>(AST::EOperator::FieldSelection, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 31:

    {
		(yyval.expression) = (yyvsp[(1) - (2)].expression);
		(yyval.expression)->SetSourceLocation(yylloc);
		(yyval.expression)->AddChildExpression((yyvsp[(2) - (2)].expression));
	}
    break;

  case 32:

    {
		(yyval.expression) = (yyvsp[(1) - (3)].expression);
		(yyval.expression)->SetSourceLocation(yylloc);
		(yyval.expression)->AddChildExpression((yyvsp[(3) - (3)].expression));
	}
    break;

  case 34:

    {
		(yyval.expression) = std::make_shared<AST::CFunctionExpression>((yyvsp[(1) - (1)].typeSpecifier));
		(yyval.expression)->SetSourceLocation(yylloc);
   	}
    break;

  case 35:

    {
		AST::CExpression::TPointer callee = std::make_shared<AST::CExpression>((yyvsp[(1) - (1)].identifier));
		(yyval.expression) = std::make_shared<AST::CFunctionExpression>(callee);
		(yyval.expression)->SetSourceLocation(yylloc);
   	}
    break;

  case 36:

    {
		AST::CExpression::TPointer callee = std::make_shared<AST::CExpression>((yyvsp[(1) - (1)].identifier));
		(yyval.expression) = std::make_shared<AST::CFunctionExpression>(callee);
		(yyval.expression)->SetSourceLocation(yylloc);
   	}
    break;

  case 41:

    {
		(yyval.expression) = (yyvsp[(1) - (2)].expression);
		(yyval.expression)->SetSourceLocation(yylloc);
		(yyval.expression)->AddChildExpression((yyvsp[(2) - (2)].expression));
	}
    break;

  case 42:

    {
		(yyval.expression) = (yyvsp[(1) - (3)].expression);
		(yyval.expression)->SetSourceLocation(yylloc);
		(yyval.expression)->AddChildExpression((yyvsp[(3) - (3)].expression));
	}
    break;

  case 43:

    {
		AST::CExpression::TPointer callee = std::make_shared<AST::CExpression>((yyvsp[(1) - (2)].identifier));
		(yyval.expression) = std::make_shared<AST::CFunctionExpression>(callee);
		(yyval.expression)->SetSourceLocation(yylloc);
   	}
    break;

  case 45:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>(AST::EOperator::PreIncrement, (yyvsp[(2) - (2)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 46:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>(AST::EOperator::PreDecrement, (yyvsp[(2) - (2)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 47:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>((AST::EOperator::Enum)(yyvsp[(1) - (2)].number), (yyvsp[(2) - (2)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 48:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>(AST::EOperator::TypeCast, (yyvsp[(4) - (4)].expression));
		(yyval.expression)->SetTypeSpecifier((yyvsp[(2) - (4)].typeSpecifier));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 49:

    { (yyval.number) = AST::EOperator::Plus; }
    break;

  case 50:

    { (yyval.number) = AST::EOperator::Negative; }
    break;

  case 51:

    { (yyval.number) = AST::EOperator::LogicalNot; }
    break;

  case 52:

    { (yyval.number) = AST::EOperator::BitwiseNot; }
    break;

  case 54:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::Multiply, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 55:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::Divide, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 56:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::Modulo, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 58:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::Add, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 59:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::Subtract, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 61:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::LeftShift, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 62:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::RightShift, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 64:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::LessThan, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 65:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::GreaterThan, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 66:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::LessOrEqual, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 67:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::GreaterOrEqual, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 69:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::Equal, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 70:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::NotEqual, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 72:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::BitwiseAnd, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 74:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::BitwiseXOr, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 76:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::BitwiseOr, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 78:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::LogicalAnd, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 80:

    {
		(yyval.expression) = std::make_shared<AST::CBinaryExpression>(AST::EOperator::LogicalOr, (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 82:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>(AST::EOperator::Conditional, (yyvsp[(1) - (5)].expression), (yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 84:

    {
		(yyval.expression) = std::make_shared<AST::CExpression>((AST::EOperator::Enum)(yyvsp[(2) - (3)].number), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression));
		(yyval.expression)->SetSourceLocation(yylloc);
	}
    break;

  case 85:

    { (yyval.number) = AST::EOperator::Assign; }
    break;

  case 86:

    { (yyval.number) = AST::EOperator::MultiplyAssign; }
    break;

  case 87:

    { (yyval.number) = AST::EOperator::DivideAssign; }
    break;

  case 88:

    { (yyval.number) = AST::EOperator::ModuloAssign; }
    break;

  case 89:

    { (yyval.number) = AST::EOperator::AddAssign; }
    break;

  case 90:

    { (yyval.number) = AST::EOperator::SubtractAssign; }
    break;

  case 91:

    { (yyval.number) = AST::EOperator::LeftShiftAssign; }
    break;

  case 92:

    { (yyval.number) = AST::EOperator::RightShiftAssign; }
    break;

  case 93:

    { (yyval.number) = AST::EOperator::AndAssign; }
    break;

  case 94:

    { (yyval.number) = AST::EOperator::XOrAssign; }
    break;

  case 95:

    { (yyval.number) = AST::EOperator::OrAssign; }
    break;

  case 96:

    {
		(yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 97:

    {
		if((yyvsp[(1) - (3)].expression)->GetOperator() != AST::EOperator::Sequence)
		{
			(yyval.expression) = std::make_shared<AST::CExpression>(AST::EOperator::Sequence);
			(yyval.expression)->SetSourceLocation(yylloc);
			(yyval.expression)->AddChildExpression((yyvsp[(1) - (3)].expression));
		}
		else
		{
			(yyval.expression) = (yyvsp[(1) - (3)].expression);
		}

		(yyval.expression)->AddChildExpression((yyvsp[(3) - (3)].expression));
	}
    break;

  case 99:

    {
		state->symbols.PopScope();
		(yyval.function) = (yyvsp[(1) - (2)].function);
	}
    break;

  case 100:

    {
	  
	}
    break;

  case 101:

    {
		(yyval.node) = (yyvsp[(1) - (1)].function);
	}
    break;

  case 102:

    {
		(yyval.node) = (yyvsp[(1) - (2)].decleratorList);
	}
    break;

  case 103:

    {
		(yyval.node) = (yyvsp[(1) - (1)].typeSpecifier);
	}
    break;

  case 104:

    {
	}
    break;

  case 105:

    {
		(yyval.function) = (yyvsp[(1) - (4)].function);
		(yyval.function)->SetReturnSemantic((yyvsp[(4) - (4)].identifier));
	}
    break;

  case 108:

    {
		(yyval.function) = (yyvsp[(1) - (2)].function);
		(yyval.function)->AddParameter((yyvsp[(2) - (2)].parameterDeclerator));
	}
    break;

  case 109:

    {
		(yyval.function) = (yyvsp[(1) - (3)].function);
		(yyval.function)->AddParameter((yyvsp[(3) - (3)].parameterDeclerator));
	}
    break;

  case 110:

    {
		(yyval.function) = std::make_shared<AST::CFunction>((yyvsp[(2) - (3)].identifier), (yyvsp[(1) - (3)].fullySpecifiedType));
		(yyval.function)->SetSourceLocation(yylloc);

		state->symbols.AddFunction(std::make_shared<CFunction>((yyvsp[(2) - (3)].identifier)));
		state->symbols.PushScope();
	}
    break;

  case 111:

    {
		(yyval.function) = std::make_shared<AST::CFunction>((yyvsp[(3) - (4)].identifier), (yyvsp[(2) - (4)].fullySpecifiedType));
		(yyval.function)->SetSourceLocation(yylloc);

		state->symbols.AddFunction(std::make_shared<CFunction>((yyvsp[(3) - (4)].identifier)));
		state->symbols.PushScope();
	}
    break;

  case 112:

    {
		AST::CFullySpecifiedType::TPointer type = std::make_shared<AST::CFullySpecifiedType>((yyvsp[(1) - (2)].typeSpecifier));
		type->SetSourceLocation(yylloc);

		(yyval.parameterDeclerator) = std::make_shared<AST::CParameterDeclerator>();
		(yyval.parameterDeclerator)->SetSourceLocation(yylloc);
		(yyval.parameterDeclerator)->SetIdentifier((yyvsp[(2) - (2)].identifier));
		(yyval.parameterDeclerator)->SetType(type);
	}
    break;

  case 113:

    {
		AST::CFullySpecifiedType::TPointer type = std::make_shared<AST::CFullySpecifiedType>((yyvsp[(1) - (4)].typeSpecifier));
		type->SetSourceLocation(yylloc);

		(yyval.parameterDeclerator) = std::make_shared<AST::CParameterDeclerator>();
		(yyval.parameterDeclerator)->SetSourceLocation(yylloc);
		(yyval.parameterDeclerator)->SetIdentifier((yyvsp[(2) - (4)].identifier));
		(yyval.parameterDeclerator)->SetType(type);
		(yyval.parameterDeclerator)->SetDefaultValue((yyvsp[(4) - (4)].expression));
	}
    break;

  case 114:

    {
		AST::CFullySpecifiedType::TPointer type = std::make_shared<AST::CFullySpecifiedType>((yyvsp[(1) - (4)].typeSpecifier));
		type->SetSourceLocation(yylloc);

		(yyval.parameterDeclerator) = std::make_shared<AST::CParameterDeclerator>();
		(yyval.parameterDeclerator)->SetSourceLocation(yylloc);
		(yyval.parameterDeclerator)->SetIdentifier((yyvsp[(2) - (4)].identifier));
		(yyval.parameterDeclerator)->SetType(type);
		(yyval.parameterDeclerator)->SetSemantic((yyvsp[(4) - (4)].identifier));
	}
    break;

  case 115:

    {
		AST::CFullySpecifiedType::TPointer type = std::make_shared<AST::CFullySpecifiedType>((yyvsp[(1) - (2)].typeSpecifier));
		type->SetSourceLocation(yylloc);

		(yyval.parameterDeclerator) = std::make_shared<AST::CParameterDeclerator>();
		(yyval.parameterDeclerator)->SetSourceLocation(yylloc);
		(yyval.parameterDeclerator)->SetIdentifier((yyvsp[(2) - (2)].declaration)->GetIdentifier());
		(yyval.parameterDeclerator)->SetType(type);
		(yyval.parameterDeclerator)->SetIsArray(true);
		(yyval.parameterDeclerator)->SetArraySize((yyvsp[(2) - (2)].declaration)->GetArraySize());
	}
    break;

  case 116:

    {
		AST::CFullySpecifiedType::TPointer type = std::make_shared<AST::CFullySpecifiedType>((yyvsp[(1) - (7)].typeSpecifier));
		type->SetSourceLocation(yylloc);

		(yyval.parameterDeclerator) = std::make_shared<AST::CParameterDeclerator>();
		(yyval.parameterDeclerator)->SetSourceLocation(yylloc);
		(yyval.parameterDeclerator)->SetIdentifier((yyvsp[(2) - (7)].identifier));
		(yyval.parameterDeclerator)->SetType(type);
		(yyval.parameterDeclerator)->SetIsArray(true);
		(yyval.parameterDeclerator)->SetArraySize((yyvsp[(4) - (7)].expression));
		(yyval.parameterDeclerator)->SetSemantic((yyvsp[(7) - (7)].identifier));
	}
    break;

  case 117:

    {
		(yyvsp[(1) - (3)].typeQualifier).Flags.i |= (yyvsp[(2) - (3)].typeQualifier).Flags.i;

		(yyval.parameterDeclerator) = (yyvsp[(3) - (3)].parameterDeclerator);
		(yyval.parameterDeclerator)->GetType()->SetQualifier((yyvsp[(1) - (3)].typeQualifier));
	}
    break;

  case 118:

    {
		(yyvsp[(1) - (3)].typeQualifier).Flags.i |= (yyvsp[(2) - (3)].typeQualifier).Flags.i;

		(yyval.parameterDeclerator) = (yyvsp[(3) - (3)].parameterDeclerator);
		(yyval.parameterDeclerator)->GetType()->SetQualifier((yyvsp[(1) - (3)].typeQualifier));
	}
    break;

  case 119:

    {
		(yyvsp[(1) - (4)].typeQualifier).Flags.i |= (yyvsp[(2) - (4)].typeQualifier).Flags.i;
		(yyvsp[(1) - (4)].typeQualifier).Flags.i |= (yyvsp[(3) - (4)].typeQualifier).Flags.i;

		(yyval.parameterDeclerator) = (yyvsp[(4) - (4)].parameterDeclerator);
		(yyval.parameterDeclerator)->GetType()->SetQualifier((yyvsp[(1) - (4)].typeQualifier));
	}
    break;

  case 120:

    {
		(yyval.parameterDeclerator) = (yyvsp[(2) - (2)].parameterDeclerator);
		(yyval.parameterDeclerator)->GetType()->SetQualifier((yyvsp[(1) - (2)].typeQualifier));
	}
    break;

  case 121:

    {
		(yyval.parameterDeclerator) = (yyvsp[(2) - (2)].parameterDeclerator);
		(yyval.parameterDeclerator)->GetType()->SetQualifier((yyvsp[(1) - (2)].typeQualifier));
	}
    break;

  case 123:

    {
		(yyvsp[(1) - (3)].typeQualifier).Flags.i |= (yyvsp[(2) - (3)].typeQualifier).Flags.i;

		(yyval.parameterDeclerator) = std::make_shared<AST::CParameterDeclerator>();
		(yyval.parameterDeclerator)->SetSourceLocation(yylloc);
		
		AST::CFullySpecifiedType::TPointer fst = std::make_shared<AST::CFullySpecifiedType>((yyvsp[(1) - (3)].typeQualifier), (yyvsp[(3) - (3)].typeSpecifier));
		(yyval.parameterDeclerator)->SetType(fst);
	}
    break;

  case 124:

    {
		(yyval.parameterDeclerator) = std::make_shared<AST::CParameterDeclerator>();
		(yyval.parameterDeclerator)->SetSourceLocation(yylloc);
		
		AST::CFullySpecifiedType::TPointer fst = std::make_shared<AST::CFullySpecifiedType>((yyvsp[(1) - (2)].typeQualifier), (yyvsp[(2) - (2)].typeSpecifier));
		(yyval.parameterDeclerator)->SetType(fst);
	}
    break;

  case 125:

    {
		(yyval.typeQualifier).Reset();
		(yyval.typeQualifier).Flags.q.In = 1;
	}
    break;

  case 126:

    {
		(yyval.typeQualifier).Reset();
		(yyval.typeQualifier).Flags.q.Out = 1;
	}
    break;

  case 127:

    {
		(yyval.typeQualifier).Reset();
		(yyval.typeQualifier).Flags.q.In = 1;
		(yyval.typeQualifier).Flags.q.Out = 1;
	}
    break;

  case 128:

    {
		(yyval.typeQualifier).Reset();
		(yyval.typeQualifier).Flags.q.In = 1;
		(yyval.typeQualifier).Flags.q.Out = 1;
	}
    break;

  case 129:

    {
		(yyval.typeQualifier).Reset();
		(yyval.typeQualifier).Flags.q.In = 1;
		(yyval.typeQualifier).Flags.q.Out = 1;
	}
    break;

  case 130:

    {
		(yyval.typeQualifier).Reset();
		(yyval.typeQualifier).Flags.q.Point = 1;
	}
    break;

  case 131:

    {
		(yyval.typeQualifier).Reset();
		(yyval.typeQualifier).Flags.q.Line = 1;
	}
    break;

  case 132:

    {
		(yyval.typeQualifier).Reset();
		(yyval.typeQualifier).Flags.q.Triangle = 1;
	}
    break;

  case 133:

    {
		(yyval.typeQualifier).Reset();
		(yyval.typeQualifier).Flags.q.LineAdj = 1;
	}
    break;

  case 134:

    {
		(yyval.typeQualifier).Reset();
		(yyval.typeQualifier).Flags.q.TriangleAdj = 1;
	}
    break;

  case 137:

    {
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>((yyvsp[(3) - (3)].identifier), false, AST::CExpression::TPointer(), AST::CExpression::TPointer());
		decleration->SetSourceLocation(yylloc);

		(yyval.decleratorList) = (yyvsp[(1) - (3)].decleratorList);
		(yyval.decleratorList)->AddDecleration(decleration);

		state->symbols.AddVariable(std::make_shared<CVariable>((yyvsp[(3) - (3)].identifier)));
	}
    break;

  case 138:

    {
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>((yyvsp[(3) - (5)].identifier), true, AST::CExpression::TPointer(), AST::CExpression::TPointer());
		decleration->SetSourceLocation(yylloc);

		(yyval.decleratorList) = (yyvsp[(1) - (5)].decleratorList);
		(yyval.decleratorList)->AddDecleration(decleration);

		state->symbols.AddVariable(std::make_shared<CVariable>((yyvsp[(3) - (5)].identifier)));
	}
    break;

  case 139:

    {
		AST::CDecleration::TPointer decleration = (yyvsp[(3) - (3)].declaration);

		(yyval.decleratorList) = (yyvsp[(1) - (3)].decleratorList);
		(yyval.decleratorList)->AddDecleration(decleration);

		state->symbols.AddVariable(std::make_shared<CVariable>((yyvsp[(3) - (3)].declaration)->GetIdentifier()));
	}
    break;

  case 140:

    {
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>((yyvsp[(3) - (7)].identifier), true, AST::CExpression::TPointer(), (yyvsp[(7) - (7)].expression));
		decleration->SetSourceLocation(yylloc);

		(yyval.decleratorList) = (yyvsp[(1) - (7)].decleratorList);
		(yyval.decleratorList)->AddDecleration(decleration);

		state->symbols.AddVariable(std::make_shared<CVariable>((yyvsp[(3) - (7)].identifier)));
	}
    break;

  case 141:

    {
		AST::CDecleration::TPointer decleration = (yyvsp[(3) - (5)].declaration);

		(yyval.decleratorList) = (yyvsp[(1) - (5)].decleratorList);
		(yyval.decleratorList)->AddDecleration(decleration);

		state->symbols.AddVariable(std::make_shared<CVariable>((yyvsp[(3) - (5)].declaration)->GetIdentifier()));
	}
    break;

  case 142:

    {
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>((yyvsp[(3) - (5)].identifier), false, AST::CExpression::TPointer(), (yyvsp[(5) - (5)].expression));
		decleration->SetSourceLocation(yylloc);

		(yyval.decleratorList) = (yyvsp[(1) - (5)].decleratorList);
		(yyval.decleratorList)->AddDecleration(decleration);

		state->symbols.AddVariable(std::make_shared<CVariable>((yyvsp[(3) - (5)].identifier)));
	}
    break;

  case 143:

    {
		(yyval.decleratorList) = std::make_shared<AST::CDecleratorList>((yyvsp[(1) - (1)].fullySpecifiedType));
		(yyval.decleratorList)->SetSourceLocation(yylloc);
	}
    break;

  case 144:

    {
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>((yyvsp[(2) - (2)].identifier), false, AST::CExpression::TPointer(), AST::CExpression::TPointer());

		(yyval.decleratorList) = std::make_shared<AST::CDecleratorList>((yyvsp[(1) - (2)].fullySpecifiedType));
		(yyval.decleratorList)->SetSourceLocation(yylloc);
		(yyval.decleratorList)->AddDecleration(decleration);
	}
    break;

  case 145:

    {
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>((yyvsp[(2) - (4)].identifier), true, AST::CExpression::TPointer(), AST::CExpression::TPointer());

		(yyval.decleratorList) = std::make_shared<AST::CDecleratorList>((yyvsp[(1) - (4)].fullySpecifiedType));
		(yyval.decleratorList)->SetSourceLocation(yylloc);
		(yyval.decleratorList)->AddDecleration(decleration);
	}
    break;

  case 146:

    {
		AST::CDecleration::TPointer decleration = (yyvsp[(2) - (2)].declaration);

		(yyval.decleratorList) = std::make_shared<AST::CDecleratorList>((yyvsp[(1) - (2)].fullySpecifiedType));
		(yyval.decleratorList)->SetSourceLocation(yylloc);
		(yyval.decleratorList)->AddDecleration(decleration);
	}
    break;

  case 147:

    {
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>((yyvsp[(2) - (6)].identifier), true, AST::CExpression::TPointer(), (yyvsp[(6) - (6)].expression));

		(yyval.decleratorList) = std::make_shared<AST::CDecleratorList>((yyvsp[(1) - (6)].fullySpecifiedType));
		(yyval.decleratorList)->SetSourceLocation(yylloc);
		(yyval.decleratorList)->AddDecleration(decleration);
	}
    break;

  case 148:

    {
		AST::CDecleration::TPointer decleration = (yyvsp[(2) - (4)].declaration);
		decleration->SetInitialiser((yyvsp[(4) - (4)].expression));

		(yyval.decleratorList) = std::make_shared<AST::CDecleratorList>((yyvsp[(1) - (4)].fullySpecifiedType));
		(yyval.decleratorList)->SetSourceLocation(yylloc);
		(yyval.decleratorList)->AddDecleration(decleration);
	}
    break;

  case 149:

    {
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>((yyvsp[(2) - (4)].identifier), false, AST::CExpression::TPointer(), (yyvsp[(4) - (4)].expression));

		(yyval.decleratorList) = std::make_shared<AST::CDecleratorList>((yyvsp[(1) - (4)].fullySpecifiedType));
		(yyval.decleratorList)->SetSourceLocation(yylloc);
		(yyval.decleratorList)->AddDecleration(decleration);
	}
    break;

  case 150:

    {
		AST::CDecleration::TPointer decleration = std::make_shared<AST::CDecleration>((yyvsp[(2) - (2)].identifier), false, AST::CExpression::TPointer(), AST::CExpression::TPointer());

		(yyval.decleratorList) = std::make_shared<AST::CDecleratorList>(AST::CFullySpecifiedType::TPointer());
		(yyval.decleratorList)->SetSourceLocation(yylloc);
		(yyval.decleratorList)->SetInvariant(true);
		(yyval.decleratorList)->AddDecleration(decleration);
	}
    break;

  case 151:

    {
		(yyval.fullySpecifiedType) = std::make_shared<AST::CFullySpecifiedType>((yyvsp[(1) - (1)].typeSpecifier));
		(yyval.fullySpecifiedType)->SetSourceLocation(yylloc);
	}
    break;

  case 152:

    {
		(yyval.fullySpecifiedType) = std::make_shared<AST::CFullySpecifiedType>((yyvsp[(1) - (2)].typeQualifier), (yyvsp[(2) - (2)].typeSpecifier));
		(yyval.fullySpecifiedType)->SetSourceLocation(yylloc);
	}
    break;

  case 153:

    {
		(yyval.typeQualifier) = (yyvsp[(3) - (4)].typeQualifier);
	}
    break;

  case 155:

    {
	   
	}
    break;

  case 156:

    {
	 
	}
    break;

  case 157:

    {
	   
	}
    break;

  case 158:

    {
	  
	}
    break;

  case 159:

    {
	 
	}
    break;

  case 160:

    {
	  
	}
    break;

  case 162:

    {
		
	}
    break;

  case 163:

    {
		
	}
    break;

  case 164:

    {
	
	}
    break;

  case 165:

    {
	  
	}
    break;

  case 168:

    {
	  
	}
    break;

  case 170:

    {
	  
	}
    break;

  case 171:

    {
	  
	}
    break;

  case 172:

    {
	
	}
    break;

  case 173:

    {
	   
	}
    break;

  case 174:

    {
	  
	}
    break;

  case 175:

    {
	 
	}
    break;

  case 176:

    {
	 
	}
    break;

  case 177:

    {
	 
	}
    break;

  case 178:

    {
	  
	}
    break;

  case 179:

    {
	  
	}
    break;

  case 180:

    {
	  
	}
    break;

  case 181:

    {
	  
	}
    break;

  case 182:

    {
		
	}
    break;

  case 183:

    {
		
	}
    break;

  case 184:

    {
		
	}
    break;

  case 185:

    {
		
	}
    break;

  case 186:

    {
		
	}
    break;

  case 187:

    {
		
	}
    break;

  case 188:

    {
		
	}
    break;

  case 189:

    {
		(yyval.typeSpecifier) = (yyvsp[(1) - (1)].typeSpecifier);
	}
    break;

  case 190:

    {
		(yyval.typeSpecifier) = (yyvsp[(2) - (2)].typeSpecifier);
	}
    break;

  case 193:

    {
		(yyval.typeSpecifier) = (yyvsp[(1) - (3)].typeSpecifier);
		(yyval.typeSpecifier)->SetIsArray(true);
		(yyval.typeSpecifier)->SetIsUnSizedArray(true);
	}
    break;

  case 194:

    {
		(yyval.typeSpecifier) = (yyvsp[(1) - (3)].typeSpecifier);
		(yyval.typeSpecifier)->SetIsUnSizedArray(true);
	}
    break;

  case 195:

    {
		(yyval.typeSpecifier) = (yyvsp[(1) - (4)].typeSpecifier);
		(yyval.typeSpecifier)->SetIsArray(true);
		(yyval.typeSpecifier)->SetArraySize((yyvsp[(3) - (4)].expression).get());
	}
    break;

  case 196:

    {
	  #pragma message("fix me")
	}
    break;

  case 197:

    {
		(yyval.typeSpecifier) = std::make_shared<AST::CTypeSpecifier>((yyvsp[(1) - (1)].precisionType));
		(yyval.typeSpecifier)->SetSourceLocation(yylloc);
	}
    break;

  case 198:

    {
		(yyval.typeSpecifier) = std::make_shared<AST::CTypeSpecifier>("float4");
		(yyval.typeSpecifier)->SetSourceLocation(yylloc);
	}
    break;

  case 199:

    {
		(yyval.typeSpecifier) = std::make_shared<AST::CTypeSpecifier>((yyvsp[(1) - (6)].identifier), (yyvsp[(3) - (6)].precisionType));
		(yyval.typeSpecifier)->SetSourceLocation(yylloc);
		(yyval.typeSpecifier)->SetTextureMSNumSamples((yyvsp[(5) - (6)].number));
	}
    break;

  case 200:

    {
		(yyval.typeSpecifier) = std::make_shared<AST::CTypeSpecifier>((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].precisionType));
		(yyval.typeSpecifier)->SetSourceLocation(yylloc);
	}
    break;

  case 201:

    {
		(yyval.typeSpecifier) = std::make_shared<AST::CTypeSpecifier>((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].identifier));
		(yyval.typeSpecifier)->SetSourceLocation(yylloc);
	}
    break;

  case 202:

    {
		(yyval.typeSpecifier) = std::make_shared<AST::CTypeSpecifier>((yyvsp[(1) - (6)].identifier), (yyvsp[(3) - (6)].identifier));
		(yyval.typeSpecifier)->SetSourceLocation(yylloc);
		(yyval.typeSpecifier)->SetPatchSize((yyvsp[(5) - (6)].number));
	}
    break;

  case 203:

    {
		(yyval.typeSpecifier) = std::make_shared<AST::CTypeSpecifier>((yyvsp[(1) - (6)].identifier), (yyvsp[(1) - (6)].identifier));
		(yyval.typeSpecifier)->SetSourceLocation(yylloc);
	}
    break;

  case 204:

    {
		(yyval.typeSpecifier) = std::make_shared<AST::CTypeSpecifier>((yyvsp[(1) - (1)].structSpecifier));
		(yyval.typeSpecifier)->SetSourceLocation(yylloc);
	}
    break;

  case 205:

    {
		(yyval.typeSpecifier) = std::make_shared<AST::CTypeSpecifier>((yyvsp[(1) - (1)].identifier));
		(yyval.typeSpecifier)->SetSourceLocation(yylloc);
	}
    break;

  case 206:

    { (yyval.precisionType) = &AST::CPrecisionType::Void; }
    break;

  case 207:

    { (yyval.precisionType) = &AST::CPrecisionType::Float; }
    break;

  case 208:

    { (yyval.precisionType) = &AST::CPrecisionType::Half; }
    break;

  case 209:

    { (yyval.precisionType) = &AST::CPrecisionType::Fixed; }
    break;

  case 210:

    { (yyval.precisionType) = &AST::CPrecisionType::Int; }
    break;

  case 211:

    { (yyval.precisionType) = &AST::CPrecisionType::UInt; }
    break;

  case 212:

    { (yyval.precisionType) = &AST::CPrecisionType::Bool; }
    break;

  case 213:

    { (yyval.precisionType) = &AST::CPrecisionType::Float2; }
    break;

  case 214:

    { (yyval.precisionType) = &AST::CPrecisionType::Float3; }
    break;

  case 215:

    { (yyval.precisionType) = &AST::CPrecisionType::Float4; }
    break;

  case 216:

    { (yyval.precisionType) = &AST::CPrecisionType::Half2; }
    break;

  case 217:

    { (yyval.precisionType) = &AST::CPrecisionType::Half3; }
    break;

  case 218:

    { (yyval.precisionType) = &AST::CPrecisionType::Half4; }
    break;

  case 219:

    { (yyval.precisionType) = &AST::CPrecisionType::Fixed2; }
    break;

  case 220:

    { (yyval.precisionType) = &AST::CPrecisionType::Fixed3; }
    break;

  case 221:

    { (yyval.precisionType) = &AST::CPrecisionType::Fixed4; }
    break;

  case 222:

    { (yyval.precisionType) = &AST::CPrecisionType::Bool2; }
    break;

  case 223:

    { (yyval.precisionType) = &AST::CPrecisionType::Bool3; }
    break;

  case 224:

    { (yyval.precisionType) = &AST::CPrecisionType::Bool4; }
    break;

  case 225:

    { (yyval.precisionType) = &AST::CPrecisionType::Int2; }
    break;

  case 226:

    { (yyval.precisionType) = &AST::CPrecisionType::Int3; }
    break;

  case 227:

    { (yyval.precisionType) = &AST::CPrecisionType::Int4; }
    break;

  case 228:

    { (yyval.precisionType) = &AST::CPrecisionType::UInt2; }
    break;

  case 229:

    { (yyval.precisionType) = &AST::CPrecisionType::UInt3; }
    break;

  case 230:

    { (yyval.precisionType) = &AST::CPrecisionType::UInt4; }
    break;

  case 231:

    { (yyval.precisionType) = &AST::CPrecisionType::Float2x2; }
    break;

  case 232:

    { (yyval.precisionType) = &AST::CPrecisionType::Float2x3; }
    break;

  case 233:

    { (yyval.precisionType) = &AST::CPrecisionType::Float2x4; }
    break;

  case 234:

    { (yyval.precisionType) = &AST::CPrecisionType::Float3x2; }
    break;

  case 235:

    { (yyval.precisionType) = &AST::CPrecisionType::Float3x3; }
    break;

  case 236:

    { (yyval.precisionType) = &AST::CPrecisionType::Float3x4; }
    break;

  case 237:

    { (yyval.precisionType) = &AST::CPrecisionType::Float4x2; }
    break;

  case 238:

    { (yyval.precisionType) = &AST::CPrecisionType::Float4x3; }
    break;

  case 239:

    { (yyval.precisionType) = &AST::CPrecisionType::Float4x4; }
    break;

  case 240:

    { (yyval.precisionType) = &AST::CPrecisionType::Half2x2; }
    break;

  case 241:

    { (yyval.precisionType) = &AST::CPrecisionType::Half2x3; }
    break;

  case 242:

    { (yyval.precisionType) = &AST::CPrecisionType::Half2x4; }
    break;

  case 243:

    { (yyval.precisionType) = &AST::CPrecisionType::Half3x2; }
    break;

  case 244:

    { (yyval.precisionType) = &AST::CPrecisionType::Half3x3; }
    break;

  case 245:

    { (yyval.precisionType) = &AST::CPrecisionType::Half3x4; }
    break;

  case 246:

    { (yyval.precisionType) = &AST::CPrecisionType::Half4x2; }
    break;

  case 247:

    { (yyval.precisionType) = &AST::CPrecisionType::Half4x3; }
    break;

  case 248:

    { (yyval.precisionType) = &AST::CPrecisionType::Half4x4; }
    break;

  case 249:

    { (yyval.precisionType) = &AST::CPrecisionType::Fixed2x2; }
    break;

  case 250:

    { (yyval.precisionType) = &AST::CPrecisionType::Fixed2x3; }
    break;

  case 251:

    { (yyval.precisionType) = &AST::CPrecisionType::Fixed2x4; }
    break;

  case 252:

    { (yyval.precisionType) = &AST::CPrecisionType::Fixed3x2; }
    break;

  case 253:

    { (yyval.precisionType) = &AST::CPrecisionType::Fixed3x3; }
    break;

  case 254:

    { (yyval.precisionType) = &AST::CPrecisionType::Fixed3x4; }
    break;

  case 255:

    { (yyval.precisionType) = &AST::CPrecisionType::Fixed4x2; }
    break;

  case 256:

    { (yyval.precisionType) = &AST::CPrecisionType::Fixed4x3; }
    break;

  case 257:

    { (yyval.precisionType) = &AST::CPrecisionType::Fixed4x4; }
    break;

  case 258:

    { (yyval.precisionType) = &AST::CPrecisionType::SamplerState; }
    break;

  case 259:

    { (yyval.precisionType) = &AST::CPrecisionType::SamplerComparisonState; }
    break;

  case 260:

    { (yyval.identifier) = "Buffer"; }
    break;

  case 261:

    { (yyval.identifier) = "Texture1D"; }
    break;

  case 262:

    { (yyval.identifier) = "Texture1DArray"; }
    break;

  case 263:

    { (yyval.identifier) = "Texture2D"; }
    break;

  case 264:

    { (yyval.identifier) = "Texture2DArray"; }
    break;

  case 265:

    { (yyval.identifier) = "Texture2DMS"; }
    break;

  case 266:

    { (yyval.identifier) = "Texture2DMSArray"; }
    break;

  case 267:

    { (yyval.identifier) = "Texture3D"; }
    break;

  case 268:

    { (yyval.identifier) = "TextureCube"; }
    break;

  case 269:

    { (yyval.identifier) = "TextureCubeArray"; }
    break;

  case 270:

    { (yyval.identifier) = "RWBuffer"; }
    break;

  case 271:

    { (yyval.identifier) = "RWTexture1D"; }
    break;

  case 272:

    { (yyval.identifier) = "RWTexture1DArray"; }
    break;

  case 273:

    { (yyval.identifier) = "RWTexture2D"; }
    break;

  case 274:

    { (yyval.identifier) = "RWTexture2DArray"; }
    break;

  case 275:

    { (yyval.identifier) = "RWTexture3D"; }
    break;

  case 276:

    { (yyval.identifier) = "PointStream"; }
    break;

  case 277:

    { (yyval.identifier) = "LinearStream"; }
    break;

  case 278:

    { (yyval.identifier) = "TriangleStream"; }
    break;

  case 279:

    { (yyval.identifier) = "InputPatch"; }
    break;

  case 280:

    { (yyval.identifier) = "OutputPatch"; }
    break;

  case 281:

    {
		    
		  }
    break;

  case 282:

    {
		    
		  }
    break;

  case 283:

    {
		    
		  }
    break;

  case 284:

    {
		(yyval.structSpecifier) = std::make_shared<AST::CStructSpecifier>((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].node));
		(yyval.structSpecifier)->SetSourceLocation(yylloc);

		state->symbols.AddType(std::make_shared<CType>((yyvsp[(2) - (5)].identifier)));
	}
    break;

  case 285:

    {
		(yyval.structSpecifier) = std::make_shared<AST::CStructSpecifier>((yyvsp[(2) - (7)].identifier), (yyvsp[(4) - (7)].identifier), (yyvsp[(6) - (7)].node));
		(yyval.structSpecifier)->SetSourceLocation(yylloc);
	}
    break;

  case 286:

    {
		(yyval.structSpecifier) = std::make_shared<AST::CStructSpecifier>("", (yyvsp[(3) - (4)].node));
		(yyval.structSpecifier)->SetSourceLocation(yylloc);
	}
    break;

  case 287:

    {
		(yyval.structSpecifier) = std::make_shared<AST::CStructSpecifier>((yyvsp[(2) - (4)].identifier), AST::CNode::TPointer());
		(yyval.structSpecifier)->SetSourceLocation(yylloc);

		state->symbols.AddType(std::make_shared<CType>((yyvsp[(2) - (4)].identifier)));
	}
    break;

  case 288:

    {
		(yyval.structSpecifier) = std::make_shared<AST::CStructSpecifier>((yyvsp[(2) - (6)].identifier), (yyvsp[(4) - (6)].identifier), AST::CNode::TPointer());
		(yyval.structSpecifier)->SetSourceLocation(yylloc);

		state->symbols.AddType(std::make_shared<CType>((yyvsp[(2) - (6)].identifier)));
	}
    break;

  case 289:

    {
		(yyval.structSpecifier) = std::make_shared<AST::CStructSpecifier>("", AST::CNode::TPointer());
		(yyval.structSpecifier)->SetSourceLocation(yylloc);
	}
    break;

  case 290:

    {
		(yyval.node) = std::make_shared<AST::CCBufferSpecifier>((yyvsp[(2) - (5)].identifier), (yyvsp[(4) - (5)].node));
		(yyval.node)->SetSourceLocation(yyloc);
	}
    break;

  case 291:

    {
	// 1
		(yyval.node) = (yyvsp[(1) - (1)].decleratorList);
		(yyvsp[(1) - (1)].decleratorList)->AddSelfLink();
	}
    break;

  case 292:

    {
		(yyval.node) = (yyvsp[(1) - (2)].node);
		(yyval.node)->AddLink((yyvsp[(2) - (2)].decleratorList));
	}
    break;

  case 293:

    {
	   (yyval.decleratorList) = std::make_shared<AST::CDecleratorList>((yyvsp[(1) - (3)].fullySpecifiedType));
	   (yyval.decleratorList)->SetSourceLocation(yyloc);
	   (yyval.decleratorList)->AddDecleration((yyvsp[(2) - (3)].declaration));
	}
    break;

  case 294:

    {
		(yyval.fullySpecifiedType) = std::make_shared<AST::CFullySpecifiedType>((yyvsp[(1) - (1)].typeSpecifier));
		(yyval.fullySpecifiedType)->SetSourceLocation(yyloc);
	}
    break;

  case 295:

    {
		(yyval.fullySpecifiedType) = std::make_shared<AST::CFullySpecifiedType>((yyvsp[(1) - (2)].typeQualifier), (yyvsp[(2) - (2)].typeSpecifier));
		(yyval.fullySpecifiedType)->SetSourceLocation(yyloc);
	}
    break;

  case 297:

    {
		#pragma message("Fix em")
	}
    break;

  case 298:

    {
		
	}
    break;

  case 299:

    {
		
	}
    break;

  case 300:

    {
	//2
		(yyval.declaration) = (yyvsp[(1) - (1)].declaration);
		(yyvsp[(1) - (1)].declaration)->AddSelfLink();
	}
    break;

  case 301:

    {
		(yyval.declaration) = (yyvsp[(1) - (3)].declaration);
		(yyval.declaration)->AddLink((yyvsp[(3) - (3)].declaration));
	}
    break;

  case 302:

    {
		(yyval.declaration) = std::make_shared<AST::CDecleration>((yyvsp[(1) - (1)].identifier), false, AST::CExpression::TPointer(), AST::CExpression::TPointer());
		(yyval.declaration)->SetSourceLocation(yyloc);
		state->symbols.AddVariable(std::make_shared<CVariable>((yyvsp[(1) - (1)].identifier)));
	}
    break;

  case 303:

    {
		(yyval.declaration) = (yyvsp[(1) - (1)].declaration);
	}
    break;

  case 304:

    {
		(yyval.declaration) = std::make_shared<AST::CDecleration>((yyvsp[(1) - (3)].identifier), false, AST::CExpression::TPointer(), AST::CExpression::TPointer());
		(yyval.declaration)->SetSourceLocation(yyloc);
		(yyval.declaration)->SetSemantec((yyvsp[(3) - (3)].identifier));
		state->symbols.AddVariable(std::make_shared<CVariable>((yyvsp[(1) - (3)].identifier)));
	}
    break;

  case 305:

    {
		(yyval.declaration) = std::make_shared<AST::CDecleration>((yyvsp[(1) - (6)].identifier), true, (yyvsp[(3) - (6)].expression), AST::CExpression::TPointer());
		(yyval.declaration)->SetSourceLocation(yyloc);
		(yyval.declaration)->SetSemantec((yyvsp[(6) - (6)].identifier));
	}
    break;

  case 306:

    {
		(yyval.declaration) = std::make_shared<AST::CDecleration>((yyvsp[(1) - (4)].identifier), true, (yyvsp[(3) - (4)].expression), AST::CExpression::TPointer());
		(yyval.declaration)->SetSourceLocation(yyloc);
	}
    break;

  case 307:

    {
		(yyval.declaration) = (yyvsp[(1) - (4)].declaration);
		(yyvsp[(3) - (4)].expression)->AddLink((yyval.declaration)->GetArraySize());
		(yyval.declaration)->SetArraySize((yyvsp[(3) - (4)].expression));
	}
    break;

  case 309:

    {
		(yyval.expression) = std::make_shared<AST::CInitialiserListExpression>();
		(yyval.expression)->AddChildExpression((yyvsp[(2) - (3)].expression));
	}
    break;

  case 310:

    {
		(yyval.expression) = (yyvsp[(1) - (1)].expression);
		(yyval.expression)->AddSelfLink();
	}
    break;

  case 311:

    {
		(yyval.expression) = (yyvsp[(1) - (3)].expression);
		(yyval.expression)->AddLink((yyvsp[(3) - (3)].expression));
	}
    break;

  case 312:

    {
		(yyval.expression) = (yyvsp[(1) - (2)].expression);
	}
    break;

  case 314:

    {  }
    break;

  case 316:

    {
		#pragma message("Fix")
	}
    break;

  case 317:

    {
		(yyval.node) = (yyvsp[(2) - (2)].node);
		(yyval.node)->AddAttribute((yyvsp[(1) - (2)].attribute));
	}
    break;

  case 324:

    {
		(yyval.compoundStatement) = std::make_shared<AST::CCompoundStatement>(true);
		(yyval.compoundStatement)->SetSourceLocation(yyloc);
		state->symbols.PopScope();
	}
    break;

  case 325:

    {
		state->symbols.PushScope();
	}
    break;

  case 326:

    {
		(yyval.compoundStatement) = std::make_shared<AST::CCompoundStatement>(true, std::move((yyvsp[(3) - (4)].nodeList)));
		(yyval.compoundStatement)->SetSourceLocation(yyloc);
		state->symbols.PopScope();
	}
    break;

  case 327:

    { (yyval.node) = (yyvsp[(1) - (1)].compoundStatement); }
    break;

  case 329:

    {
		(yyval.compoundStatement) = std::make_shared<AST::CCompoundStatement>(false);
		(yyval.compoundStatement)->SetSourceLocation(yyloc);
	}
    break;

  case 330:

    {
		(yyval.compoundStatement) = std::make_shared<AST::CCompoundStatement>(false, std::move((yyvsp[(2) - (3)].nodeList)));
		(yyval.compoundStatement)->SetSourceLocation(yyloc);
	}
    break;

  case 331:

    {
		//#pragma message("Fix me2")
		(yyval.nodeList).push_back((yyvsp[(1) - (1)].node));
	}
    break;

  case 332:

    {
		#pragma message("Fix me")
		(yyval.nodeList).push_back((yyvsp[(2) - (2)].node));
	}
    break;

  case 333:

    {
		(yyval.node) = std::make_shared<AST::CExpressionStatement>(AST::CExpression::TPointer());
		(yyval.node)->SetSourceLocation(yyloc);
	}
    break;

  case 334:

    {
		(yyval.node) = std::make_shared<AST::CExpressionStatement>((yyvsp[(1) - (2)].expression));
		(yyval.node)->SetSourceLocation(yyloc);
	}
    break;

  case 335:

    {
		(yyval.node) = std::make_shared<AST::CSelectionStatement>((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].selectionRestStatement).thenStatement, (yyvsp[(5) - (5)].selectionRestStatement).elseStatement);
		(yyval.node)->SetSourceLocation(yyloc);
	}
    break;

  case 336:

    {
		(yyval.selectionRestStatement).thenStatement = (yyvsp[(1) - (3)].node);
		(yyval.selectionRestStatement).elseStatement = (yyvsp[(3) - (3)].node);
	}
    break;

  case 337:

    {
		(yyval.selectionRestStatement).thenStatement = (yyvsp[(1) - (1)].node);
		(yyval.selectionRestStatement).elseStatement = AST::CNode::TPointer();
	}
    break;

  case 338:

    {
		(yyval.node) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 339:

    {
		AST::CDecleration::TPointer decl = std::make_shared<AST::CDecleration>((yyvsp[(2) - (4)].identifier), false, AST::CExpression::TPointer(), (yyvsp[(4) - (4)].expression));
		decl->SetSourceLocation(yyloc);
		AST::CDecleratorList::TPointer declerator = std::make_shared<AST::CDecleratorList>((yyvsp[(1) - (4)].fullySpecifiedType));
		declerator->SetSourceLocation(yyloc);

		declerator->AddDecleration(decl);
		(yyval.node) = declerator;
	}
    break;

  case 340:

    {
	  #pragma message("Fix me");
	}
    break;

  case 341:

    {
	  #pragma message("Fix me");
	}
    break;

  case 342:

    {
	 #pragma message("Fix me");
	}
    break;

  case 343:

    {
	  #pragma message("Fix me");
	}
    break;

  case 344:

    {
	  #pragma message("Fix me");
	}
    break;

  case 345:

    {
	  #pragma message("Fix me");
	}
    break;

  case 346:

    {
	   #pragma message("Fix me");
	}
    break;

  case 347:

    {
	  #pragma message("Fix me");
	}
    break;

  case 348:

    {
	  #pragma message("Fix me");
	}
    break;

  case 349:

    {
	   #pragma message("Fix me");
	}
    break;

  case 350:

    {
	  #pragma message("Fix me");
	}
    break;

  case 351:

    {
	  #pragma message("Fix me");
	}
    break;

  case 352:

    {
	  #pragma message("Fix me");
	}
    break;

  case 353:

    {
	 #pragma message("Fix me");
	}
    break;

  case 357:

    {
	  #pragma message("Fix me");
	}
    break;

  case 358:

    {
	 #pragma message("Fix me");
	}
    break;

  case 359:

    {
	 #pragma message("Fix me");
	}
    break;

  case 360:

    {
		(yyval.node) = std::make_shared<AST::CFlowControlStatement>(AST::CFlowControlStatement::EType::Continue);
		(yyval.node)->SetSourceLocation(yyloc);
	}
    break;

  case 361:

    {
		(yyval.node) = std::make_shared<AST::CFlowControlStatement>(AST::CFlowControlStatement::EType::Break);
		(yyval.node)->SetSourceLocation(yyloc);
	}
    break;

  case 362:

    {
		(yyval.node) = std::make_shared<AST::CFlowControlStatement>(AST::CFlowControlStatement::EType::Return);
		(yyval.node)->SetSourceLocation(yyloc);
	}
    break;

  case 363:

    {
		(yyval.node) = std::make_shared<AST::CFlowControlStatement>(AST::CFlowControlStatement::EType::Return, (yyvsp[(2) - (3)].expression));
		(yyval.node)->SetSourceLocation(yyloc);
	}
    break;

  case 364:

    {
		(yyval.node) = std::make_shared<AST::CFlowControlStatement>(AST::CFlowControlStatement::EType::Discard);
		(yyval.node)->SetSourceLocation(yyloc);
	}
    break;

  case 365:

    { (yyval.node) = (yyvsp[(1) - (1)].functionDefinition); }
    break;

  case 366:

    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 367:

    {
		#pragma message("Fix me");
	}
    break;

  case 368:

    {
		#pragma message("Fix me");
	}
    break;

  case 369:

    {
		#pragma message("Fix me");
	}
    break;

  case 370:

    {
	#pragma message("Fix me");
	}
    break;

  case 371:

    {
		#pragma message("Fix me");
	}
    break;

  case 372:

    {
		#pragma message("Fix me");
	}
    break;

  case 373:

    {
		#pragma message("Fix me");
	}
    break;

  case 374:

    {
		#pragma message("Fix me");
	}
    break;

  case 375:

    {
		(yyval.attribute) = (yyvsp[(1) - (2)].attribute);
		(yyval.attribute)->AddLink((yyvsp[(2) - (2)].attribute));
	}
    break;

  case 376:

    {
		(yyval.attribute) = (yyvsp[(1) - (1)].attribute);
	}
    break;

  case 377:

    {
		(yyval.functionDefinition) = std::make_shared<AST::CFunctionDefinition>((yyvsp[(1) - (2)].function), (yyvsp[(2) - (2)].compoundStatement));
		(yyval.functionDefinition)->SetSourceLocation(yyloc);
		state->symbols.PopScope();
	}
    break;

  case 378:

    {
		(yyval.functionDefinition) = std::make_shared<AST::CFunctionDefinition>((yyvsp[(2) - (3)].function), (yyvsp[(3) - (3)].compoundStatement));
		(yyval.functionDefinition)->SetSourceLocation(yyloc);
		(yyval.functionDefinition)->AddAttribute((yyvsp[(1) - (3)].attribute));
		state->symbols.PopScope();

		(yyval.functionDefinition)->AddAttribute((yyvsp[(1) - (3)].attribute));
	}
    break;

  case 379:

    {
		(yyval.node) = (yyvsp[(1) - (1)].function);
	}
    break;

  case 380:

    {
		
	}
    break;

  case 381:

    {
		(yyval.node) = (yyvsp[(1) - (1)].typeSpecifier);
	}
    break;

  case 382:

    {
	   (yyval.node) = (yyvsp[(1) - (1)].node);
	}
    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, state, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, state, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc, state);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, state);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, state, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, state);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, state);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



