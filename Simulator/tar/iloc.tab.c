/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 18 "iloc.y"

  #define YYERROR_VERBOSE 

  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include "instruction.h"
  #include "machine.h"

  extern int yylex(void);
  char token[256];

  #define MAX_ERROR_MESSAGE_LENGTH 100

  Operands* new_operands(void);
  Operand* append_operands(Operand*,Operand*);
  int verify_args(Opcode*,int,int,int,int);

  extern char yytext[];

  extern int line_counter;
  extern Opcode* current_opcode;

  /* This function must be defined */
  void yyerror(char*);

  /* If an error is encountered during parsing this is changed to 1 */
  int error_found = 0;

  /* Pointer to the first instruction */
  Instruction* first_instruction;

  /* Pointer to the end of the instruction list */
  Instruction* EndOfList;

  /* address for data initializations */
  int Start;


#line 111 "iloc.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "iloc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OPEN_BRACKET = 3,               /* OPEN_BRACKET  */
  YYSYMBOL_CLOSE_BRACKET = 4,              /* CLOSE_BRACKET  */
  YYSYMBOL_SEMICOLON = 5,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 6,                      /* COMMA  */
  YYSYMBOL_ARROW = 7,                      /* ARROW  */
  YYSYMBOL_OPCODE = 8,                     /* OPCODE  */
  YYSYMBOL_DOUTPUT = 9,                    /* DOUTPUT  */
  YYSYMBOL_REGISTER = 10,                  /* REGISTER  */
  YYSYMBOL_NUMBER = 11,                    /* NUMBER  */
  YYSYMBOL_LABEL = 12,                     /* LABEL  */
  YYSYMBOL_TARGET = 13,                    /* TARGET  */
  YYSYMBOL_DATA_CHAR = 14,                 /* DATA_CHAR  */
  YYSYMBOL_DATA_INT = 15,                  /* DATA_INT  */
  YYSYMBOL_YYACCEPT = 16,                  /* $accept  */
  YYSYMBOL_iloc_program = 17,              /* iloc_program  */
  YYSYMBOL_instruction_list = 18,          /* instruction_list  */
  YYSYMBOL_instruction = 19,               /* instruction  */
  YYSYMBOL_operation_list = 20,            /* operation_list  */
  YYSYMBOL_operation = 21,                 /* operation  */
  YYSYMBOL_the_opcode = 22,                /* the_opcode  */
  YYSYMBOL_operand_list = 23,              /* operand_list  */
  YYSYMBOL_reg = 24,                       /* reg  */
  YYSYMBOL_const = 25,                     /* const  */
  YYSYMBOL_lbl = 26,                       /* lbl  */
  YYSYMBOL_label_def = 27,                 /* label_def  */
  YYSYMBOL_data_defs = 28,                 /* data_defs  */
  YYSYMBOL_data_def = 29,                  /* data_def  */
  YYSYMBOL_listofchar = 30,                /* listofchar  */
  YYSYMBOL_listofint = 31,                 /* listofint  */
  YYSYMBOL_charinit = 32,                  /* charinit  */
  YYSYMBOL_intinit = 33,                   /* intinit  */
  YYSYMBOL_addr = 34                       /* addr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   46

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  16
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  37
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  54

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   270


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   108,   108,   112,   118,   123,   130,   136,   146,   152,
     160,   164,   171,   185,   197,   209,   222,   228,   234,   241,
     247,   254,   260,   269,   279,   288,   296,   305,   306,   309,
     310,   313,   314,   317,   318,   321,   327,   333
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "OPEN_BRACKET",
  "CLOSE_BRACKET", "SEMICOLON", "COMMA", "ARROW", "OPCODE", "DOUTPUT",
  "REGISTER", "NUMBER", "LABEL", "TARGET", "DATA_CHAR", "DATA_INT",
  "$accept", "iloc_program", "instruction_list", "instruction",
  "operation_list", "operation", "the_opcode", "operand_list", "reg",
  "const", "lbl", "label_def", "data_defs", "data_def", "listofchar",
  "listofint", "charinit", "intinit", "addr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-22)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       4,     0,   -22,   -22,     9,     9,    11,     1,   -22,   -22,
      24,     2,     4,   -22,    17,     8,   -22,     3,    21,   -22,
     -22,     2,    18,   -22,   -22,   -22,    30,    32,    33,    34,
     -22,     1,   -22,   -22,     0,   -22,     3,   -22,   -22,    21,
     -22,   -22,   -22,    18,    18,    18,    18,   -22,   -22,   -22,
     -22,   -22,   -22,   -22
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    16,    26,     0,     0,     0,     2,     4,     8,
      15,     0,     0,    28,     0,    10,    37,     0,     0,     1,
       6,     0,     0,    23,    24,    25,    13,    17,    19,    21,
       5,     3,    27,     9,     0,    35,    29,    32,    36,    30,
      34,     7,    14,     0,     0,     0,     0,    11,    31,    33,
      12,    18,    20,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -22,   -22,    29,    -5,    10,    -1,   -22,   -21,   -22,   -22,
     -22,    -4,   -22,    31,   -22,   -22,     6,     7,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,     8,    14,     9,    10,    26,    27,    28,
      29,    11,    12,    13,    36,    39,    37,    40,    17
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      15,    42,    20,    21,     1,     1,    30,     1,     2,     2,
       2,    19,     2,    34,     3,    35,    41,     3,     4,     5,
      16,    33,    50,    51,    52,    53,    20,    21,    23,    24,
      25,    22,    38,    15,    23,    24,    25,    43,    44,    45,
      46,    31,    48,    32,    47,    18,    49
};

static const yytype_int8 yycheck[] =
{
       1,    22,     7,     7,     3,     3,    11,     3,     8,     8,
       8,     0,     8,     5,    13,    12,    21,    13,    14,    15,
      11,     4,    43,    44,    45,    46,    31,    31,    10,    11,
      12,     7,    11,    34,    10,    11,    12,     7,     6,     6,
       6,    12,    36,    12,    34,     5,    39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     8,    13,    14,    15,    17,    18,    19,    21,
      22,    27,    28,    29,    20,    21,    11,    34,    34,     0,
      19,    27,     7,    10,    11,    12,    23,    24,    25,    26,
      19,    18,    29,     4,     5,    12,    30,    32,    11,    31,
      33,    19,    23,     7,     6,     6,     6,    20,    32,    33,
      23,    23,    23,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    16,    17,    17,    18,    18,    18,    18,    19,    19,
      20,    20,    21,    21,    21,    21,    22,    23,    23,    23,
      23,    23,    23,    24,    25,    26,    27,    28,    28,    29,
      29,    30,    30,    31,    31,    32,    33,    34
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     3,     1,     3,
       1,     3,     4,     2,     3,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     2,     1,     3,
       3,     2,     1,     2,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* iloc_program: instruction_list  */
#line 109 "iloc.y"
                 {
		     first_instruction = (yyvsp[0].inst_ptr);
		 }
#line 1161 "iloc.tab.c"
    break;

  case 3: /* iloc_program: data_defs instruction_list  */
#line 113 "iloc.y"
                 {
		     first_instruction = (yyvsp[0].inst_ptr);
		 }
#line 1169 "iloc.tab.c"
    break;

  case 4: /* instruction_list: instruction  */
#line 119 "iloc.y"
                 {
		     (yyval.inst_ptr) = (yyvsp[0].inst_ptr);
		     EndOfList = (yyvsp[0].inst_ptr);
		 }
#line 1178 "iloc.tab.c"
    break;

  case 5: /* instruction_list: label_def instruction  */
#line 124 "iloc.y"
                 {
		     Label* label_definition = get_label((yyvsp[-1].ival));
		     label_definition->target = (yyvsp[0].inst_ptr);
		     (yyval.inst_ptr) = (yyvsp[0].inst_ptr);
		     EndOfList = (yyvsp[0].inst_ptr);
		 }
#line 1189 "iloc.tab.c"
    break;

  case 6: /* instruction_list: instruction_list instruction  */
#line 131 "iloc.y"
                 {
		     EndOfList->next = (yyvsp[0].inst_ptr);
		     EndOfList = (yyvsp[0].inst_ptr);
		     (yyval.inst_ptr) = (yyvsp[-1].inst_ptr);
		 }
#line 1199 "iloc.tab.c"
    break;

  case 7: /* instruction_list: instruction_list label_def instruction  */
#line 137 "iloc.y"
                 {
		     Label* label_definition = get_label((yyvsp[-1].ival));
		     label_definition->target = (yyvsp[0].inst_ptr);
		     EndOfList->next = (yyvsp[0].inst_ptr);
		     EndOfList = (yyvsp[0].inst_ptr);
		     (yyval.inst_ptr) = (yyvsp[-2].inst_ptr);
		 }
#line 1211 "iloc.tab.c"
    break;

  case 8: /* instruction: operation  */
#line 147 "iloc.y"
                 {
		     (yyval.inst_ptr) = malloc(sizeof(Instruction));
		     (yyval.inst_ptr)->operations = (yyvsp[0].op_ptr);
		     (yyval.inst_ptr)->next = NULL;
		 }
#line 1221 "iloc.tab.c"
    break;

  case 9: /* instruction: OPEN_BRACKET operation_list CLOSE_BRACKET  */
#line 153 "iloc.y"
                 {
		     (yyval.inst_ptr) = malloc(sizeof(Instruction));
		     (yyval.inst_ptr)->operations = (yyvsp[-1].op_ptr);
		     (yyval.inst_ptr)->next = NULL;
		 }
#line 1231 "iloc.tab.c"
    break;

  case 10: /* operation_list: operation  */
#line 161 "iloc.y"
                 {
		     (yyval.op_ptr) = (yyvsp[0].op_ptr);
		 }
#line 1239 "iloc.tab.c"
    break;

  case 11: /* operation_list: operation SEMICOLON operation_list  */
#line 165 "iloc.y"
                 {
		     (yyvsp[-2].op_ptr)->next = (yyvsp[0].op_ptr);
		     (yyval.op_ptr) = (yyvsp[-2].op_ptr);
		 }
#line 1248 "iloc.tab.c"
    break;

  case 12: /* operation: the_opcode operand_list ARROW operand_list  */
#line 172 "iloc.y"
                 {
		     verify_args((yyvsp[-3].opcode_ptr),(yyvsp[-2].operands_ptr)->num_regs,(yyvsp[-2].operands_ptr)->num_consts+(yyvsp[0].operands_ptr)->num_consts,
				 (yyvsp[-2].operands_ptr)->num_labels+(yyvsp[0].operands_ptr)->num_labels,(yyvsp[0].operands_ptr)->num_regs);
		     (yyval.op_ptr) = malloc(sizeof(Operation));
		     (yyval.op_ptr)->opcode = (yyvsp[-3].opcode_ptr)->name;
		     (yyval.op_ptr)->srcs = (yyvsp[-2].operands_ptr)->regs;
		     (yyval.op_ptr)->consts = append_operands((yyvsp[-2].operands_ptr)->consts,(yyvsp[0].operands_ptr)->consts);
		     (yyval.op_ptr)->labels = append_operands((yyvsp[-2].operands_ptr)->labels,(yyvsp[0].operands_ptr)->labels);
		     (yyval.op_ptr)->defs = (yyvsp[0].operands_ptr)->regs;
		     (yyval.op_ptr)->next = NULL;
		     free((yyvsp[-2].operands_ptr));
		     free((yyvsp[0].operands_ptr));
		 }
#line 1266 "iloc.tab.c"
    break;

  case 13: /* operation: the_opcode operand_list  */
#line 186 "iloc.y"
                 {
		     verify_args((yyvsp[-1].opcode_ptr),(yyvsp[0].operands_ptr)->num_regs,(yyvsp[0].operands_ptr)->num_consts,(yyvsp[0].operands_ptr)->num_labels,0);
		     (yyval.op_ptr) = malloc(sizeof(Operation));
		     (yyval.op_ptr)->opcode = (yyvsp[-1].opcode_ptr)->name;
		     (yyval.op_ptr)->srcs = (yyvsp[0].operands_ptr)->regs;
		     (yyval.op_ptr)->consts = (yyvsp[0].operands_ptr)->consts;
		     (yyval.op_ptr)->labels = (yyvsp[0].operands_ptr)->labels;
		     (yyval.op_ptr)->defs = NULL;
		     (yyval.op_ptr)->next = NULL;
		     free((yyvsp[0].operands_ptr));
		 }
#line 1282 "iloc.tab.c"
    break;

  case 14: /* operation: the_opcode ARROW operand_list  */
#line 198 "iloc.y"
                 {
		     verify_args((yyvsp[-2].opcode_ptr),0,(yyvsp[0].operands_ptr)->num_consts,(yyvsp[0].operands_ptr)->num_labels,(yyvsp[0].operands_ptr)->num_regs);
		     (yyval.op_ptr) = malloc(sizeof(Operation));
		     (yyval.op_ptr)->opcode = (yyvsp[-2].opcode_ptr)->name;
		     (yyval.op_ptr)->srcs = NULL;
		     (yyval.op_ptr)->consts = (yyvsp[0].operands_ptr)->consts;
		     (yyval.op_ptr)->labels = (yyvsp[0].operands_ptr)->labels;
		     (yyval.op_ptr)->defs = (yyvsp[0].operands_ptr)->regs;
		     (yyval.op_ptr)->next = NULL;
		     free((yyvsp[0].operands_ptr));
		 }
#line 1298 "iloc.tab.c"
    break;

  case 15: /* operation: the_opcode  */
#line 210 "iloc.y"
                 {
		     verify_args((yyvsp[0].opcode_ptr),0,0,0,0);
		     (yyval.op_ptr) = malloc(sizeof(Operation));
		     (yyval.op_ptr)->opcode = (yyvsp[0].opcode_ptr)->name;
		     (yyval.op_ptr)->srcs = NULL;
		     (yyval.op_ptr)->consts = NULL;
		     (yyval.op_ptr)->labels = NULL;
		     (yyval.op_ptr)->defs = NULL;
		     (yyval.op_ptr)->next = NULL;
		 }
#line 1313 "iloc.tab.c"
    break;

  case 16: /* the_opcode: OPCODE  */
#line 223 "iloc.y"
                 {
		     (yyval.opcode_ptr) = current_opcode;
		 }
#line 1321 "iloc.tab.c"
    break;

  case 17: /* operand_list: reg  */
#line 229 "iloc.y"
                 {
		     (yyval.operands_ptr) = new_operands();
		     (yyval.operands_ptr)->num_regs = 1;
		     (yyval.operands_ptr)->regs = (yyvsp[0].operand_ptr);
		 }
#line 1331 "iloc.tab.c"
    break;

  case 18: /* operand_list: reg COMMA operand_list  */
#line 235 "iloc.y"
                 {
		     (yyval.operands_ptr) = (yyvsp[0].operands_ptr);
		     (yyval.operands_ptr)->num_regs += 1;
		     (yyvsp[-2].operand_ptr)->next = (yyval.operands_ptr)->regs;
		     (yyval.operands_ptr)->regs = (yyvsp[-2].operand_ptr);
		 }
#line 1342 "iloc.tab.c"
    break;

  case 19: /* operand_list: const  */
#line 242 "iloc.y"
                 {
		     (yyval.operands_ptr) = new_operands();
		     (yyval.operands_ptr)->num_consts = 1;
		     (yyval.operands_ptr)->consts = (yyvsp[0].operand_ptr);
		 }
#line 1352 "iloc.tab.c"
    break;

  case 20: /* operand_list: const COMMA operand_list  */
#line 248 "iloc.y"
                 {
		     (yyval.operands_ptr) = (yyvsp[0].operands_ptr);
		     (yyval.operands_ptr)->num_consts += 1;
		     (yyvsp[-2].operand_ptr)->next = (yyval.operands_ptr)->consts;
		     (yyval.operands_ptr)->consts = (yyvsp[-2].operand_ptr);
		 }
#line 1363 "iloc.tab.c"
    break;

  case 21: /* operand_list: lbl  */
#line 255 "iloc.y"
                 {
		     (yyval.operands_ptr) = new_operands();
		     (yyval.operands_ptr)->num_labels = 1;
		     (yyval.operands_ptr)->labels = (yyvsp[0].operand_ptr);
		 }
#line 1373 "iloc.tab.c"
    break;

  case 22: /* operand_list: lbl COMMA operand_list  */
#line 261 "iloc.y"
                 {
		     (yyval.operands_ptr) = (yyvsp[0].operands_ptr);
		     (yyval.operands_ptr)->num_labels += 1;
		     (yyvsp[-2].operand_ptr)->next = (yyval.operands_ptr)->labels;
		     (yyval.operands_ptr)->labels = (yyvsp[-2].operand_ptr);
		 }
#line 1384 "iloc.tab.c"
    break;

  case 23: /* reg: REGISTER  */
#line 270 "iloc.y"
                 {
		     (yyval.operand_ptr) = malloc(sizeof(Operand));
		     //$$->value = (int) strtol(yylval.ival, (char**) NULL, 10);
		     (yyval.operand_ptr)->value = yylval.ival;
		     //printf(" visited reg %d %s\n",(yylval.ival),&yytext[1]);
		     (yyval.operand_ptr)->next = NULL;
		 }
#line 1396 "iloc.tab.c"
    break;

  case 24: /* const: NUMBER  */
#line 280 "iloc.y"
                 {
		     (yyval.operand_ptr) = malloc(sizeof(Operand));
		     (yyval.operand_ptr)->value = yylval.ival;
		     //printf(" \n Const: %d \n", yylval.ival);
		     (yyval.operand_ptr)->next = NULL;
		 }
#line 1407 "iloc.tab.c"
    break;

  case 25: /* lbl: LABEL  */
#line 289 "iloc.y"
                 {
		     (yyval.operand_ptr) = malloc(sizeof(Operand));
		     (yyval.operand_ptr)->value = insert_label(token);
		     (yyval.operand_ptr)->next = NULL;
		 }
#line 1417 "iloc.tab.c"
    break;

  case 26: /* label_def: TARGET  */
#line 297 "iloc.y"
                 {
		   int last_char = strlen(token) - 1; /* take off ':' */
		   token[last_char] = '\0';
		   (yyval.ival) = insert_label(token);
		 }
#line 1427 "iloc.tab.c"
    break;

  case 29: /* data_def: DATA_CHAR addr listofchar  */
#line 309 "iloc.y"
                                           { (yyval.ival) = 0; }
#line 1433 "iloc.tab.c"
    break;

  case 30: /* data_def: DATA_INT addr listofint  */
#line 310 "iloc.y"
                                           { (yyval.ival) = 0; }
#line 1439 "iloc.tab.c"
    break;

  case 32: /* listofchar: charinit  */
#line 314 "iloc.y"
                           { (yyval.ival) = 0; }
#line 1445 "iloc.tab.c"
    break;

  case 35: /* charinit: LABEL  */
#line 321 "iloc.y"
                   { (yyval.cval) = (unsigned int) token[0]; 
		     set_memory(Start,(char) (yyval.cval));
		     Start += 1; /* sizeof character in simulator */
                   }
#line 1454 "iloc.tab.c"
    break;

  case 36: /* intinit: NUMBER  */
#line 327 "iloc.y"
                    { (yyval.ival) = atoi(token); 
                      set_word(Start,(int) (yyval.ival));
		      Start += 4; /* sizeof int in simulator */
                    }
#line 1463 "iloc.tab.c"
    break;

  case 37: /* addr: NUMBER  */
#line 334 "iloc.y"
             { (yyval.ival) = atoi(token);
               Start = (yyval.ival);
	     }
#line 1471 "iloc.tab.c"
    break;


#line 1475 "iloc.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

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
                      yytoken, &yylval);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 339 "iloc.y"
 /* Support Code */

/* Create a new initialized Operands structure */
Operands* new_operands()
{
    Operands* operands_ptr = malloc(sizeof(Operands));
    operands_ptr->num_regs = 0;
    operands_ptr->regs = NULL;
    operands_ptr->num_consts = 0;
    operands_ptr->consts = NULL;
    operands_ptr->num_labels = 0;
    operands_ptr->labels = NULL;
    
    return(operands_ptr);
}

/* Append the second list of operands to the end of the first */
Operand* append_operands(Operand* list1, Operand* list2)
{
    Operand* start = list1;

    if (!list1)
	return list2;
    
    while(list1->next)
	list1 = list1->next;

    list1->next = list2;

    return(start);
}

/* debugging code -- kdc */
void PrintOperands( Operand *o ) {
  if (!o)
    fprintf(stdout,"<nil>");
  else while( o ) {
      fprintf(stdout,"%d ",o->value);
      o = o->next;
    }
}
void PrintOperation( Operation *op ) {

  fprintf(stdout,"%s:\tsrcs:\t",opcode_specs[op->opcode].string);
  PrintOperands(op->srcs);
  fprintf(stdout,"\n\tconsts:\t");
  PrintOperands(op->consts);
  fprintf(stdout,"\n\tlabels:\t");
  PrintOperands(op->labels);
  fprintf(stdout,"\n\tdefs:\t");
  PrintOperands(op->defs);
  fprintf(stdout,"\n\n");
}

/* Make sure that the operation was called with the correct number and type
   of arguments */
int verify_args(Opcode* operation,int srcs, int consts, int labels, int defs)
{
    char* error_message;

    if (operation->srcs != srcs)
    {
	error_message = malloc(MAX_ERROR_MESSAGE_LENGTH*sizeof(char));
	sprintf(error_message,"%s used with incorrect number of source registers",
		operation->string);
	yyerror(error_message);
	free(error_message);
	return 0;
    }
    
    if (operation->consts != consts)
    {
	error_message = malloc(MAX_ERROR_MESSAGE_LENGTH*sizeof(char));
	sprintf(error_message,"%s used with incorrect number of constants",
		operation->string);
	yyerror(error_message);
	free(error_message);
	return 0;
    }

    if (operation->labels != labels)
    {
	error_message = malloc(MAX_ERROR_MESSAGE_LENGTH*sizeof(char));
	sprintf(error_message,"%s used with incorrect number of labels (%d vs %d)",
		operation->string,operation->labels,labels);
	yyerror(error_message);
	free(error_message);
	return 0;
    }

    if (operation->defs != defs)
    {
	error_message = malloc(MAX_ERROR_MESSAGE_LENGTH*sizeof(char));
	sprintf(error_message,"%s used with incorrect number of defined registers",
		operation->string);
	yyerror(error_message);
	free(error_message);
	return 0;
    }

    return 1;
}
    
	
void yyerror(char* s)
{
  // bad hack to make this friendlier for students
  // Added a check for an empty file in sim.c, but that doesn't catch the case
  // when the input comes via a pipe.
  //
  // So, find the error message.
  if (strcmp(s,"syntax error, unexpected $end") == 0) {
    // empty input file, indicates prior process in the piped command
    // produced no output; hence no input to the simulator
    fprintf(stderr,"Error: \tFile passed to the simulator is empty.\n\n");
    fprintf(stderr,"\tIn a test script, this usually indicates that the\n");
    fprintf(stderr,"\tcomponent under test terminated in an abnormal way.\n\n");
    exit(-1);
  }
  (void) fprintf(stderr, "Line %d: %s\n", line_counter, s);
  error_found = 1;
}

