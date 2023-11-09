/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

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

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 1






/* First part of user prologue.  */
#line 69 "../lexer/theme-parser.y"

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

#include "theme-parser.h"
ThemeWidget *rofi_theme = NULL;
void yyerror(YYLTYPE *yylloc, const char *what, const char* s);
int yylex (YYSTYPE *, YYLTYPE *);


static int check_in_range ( double index, double low, double high, YYLTYPE *loc )
{
    if ( index > high || index < low ) {
        gchar *str = g_strdup_printf("Value out of range: \n\t\tValue: X = %.2lf;\n\t\tRange: %.2lf <= X <= %.2lf.", index, low, high );
        yyerror ( loc, loc->filename, str);
        g_free(str);
        return FALSE;
    }

    return TRUE;
}

static double hue2rgb ( double p, double q, double t )
{
    t += (t<0)?1.0:0.0;
    t -= (t>1)?1.0:0.0;
    if ( t < (1/6.0) ) {
         return p + (q - p) * 6 * t;
    }
    if ( t < (1/2.0) ) {
         return q;
    }
    if ( t < (2/3.0) ) {
        return p + (q - p) * (2/3.0 - t) * 6;
    }
    return p;
}
static ThemeColor hsl_to_rgb ( double h, double s, double l )
{
    ThemeColor colour;
    colour.alpha = 1.0;

    if (s < 0.001 && s > -0.001) {
        colour.red = colour.green = colour.blue = l; // achromatic
    } else {

        double q = l < 0.5 ? l * (1 + s) : l + s - l * s;
        double p = 2 * l - q;
        colour.red   = hue2rgb(p, q, h + 1/3.0);
        colour.green = hue2rgb(p, q, h);
        colour.blue  = hue2rgb(p, q, h - 1/3.0);
    }

    return colour;
}
static ThemeColor hwb_to_rgb ( double h, double w, double b )
{
    ThemeColor retv = hsl_to_rgb ( h, 1.0, 0.5);
    retv.red   *= ( 1. - w - b );
    retv.red   += w;
    retv.green *= ( 1. - w - b );
    retv.green += w;
    retv.blue  *= ( 1. - w - b );
    retv.blue += w;
    return retv;
}

#line 127 "lexer/theme-parser.c"

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

#include "lexer/theme-parser.h"

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;



#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX \
  (PTRDIFF_MAX < SIZE_MAX ? PTRDIFF_MAX : YY_CAST (ptrdiff_t, SIZE_MAX))

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
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

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0)  \
            || 4 < __GNUC__ + (7 <= __GNUC_MINOR__)))
   /* _Noreturn works as-is.  */
# elif 2 < __GNUC__ + (8 <= __GNUC_MINOR__) || 0x5110 <= __SUNPRO_C
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   671

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  104
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  161
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  329
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 15
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token number (for yychar).  */
#define YYMAXUTOK   351
/* YYUNDEFTOK -- Symbol number (for yytoken) that denotes an unknown
   token.  */
#define YYUNDEFTOK  2

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                         \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   324,   324,   343,   344,   348,   351,   360,   363,   370,
     386,   393,   407,   421,   435,   449,   463,   480,   481,   485,
     487,   491,   508,   528,   529,   533,   537,   544,   548,   553,
     559,   563,   569,   572,   576,   580,   584,   588,   592,   596,
     600,   604,   608,   612,   616,   621,   625,   629,   633,   637,
     641,   646,   652,   658,   664,   675,   676,   677,   678,   681,
     682,   683,   684,   688,   691,   700,   701,   705,   706,   711,
     716,   719,   724,   737,   738,   739,   740,   741,   744,   745,
     748,   749,   757,   758,   762,   763,   764,   765,   766,   767,
     768,   769,   774,   782,   787,   795,   803,   811,   825,   831,
     837,   843,   850,   856,   862,   867,   873,   879,   885,   891,
     897,   904,   913,   921,   932,   933,   934,   935,   936,   943,
     944,   945,   953,   963,   973,   983,   993,   999,  1005,  1013,
    1021,  1027,  1033,  1036,  1040,  1046,  1047,  1050,  1051,  1054,
    1055,  1056,  1057,  1058,  1062,  1063,  1067,  1068,  1072,  1073,
    1077,  1078,  1079,  1084,  1088,  1089,  1092,  1098,  1099,  1100,
    1104,  1105
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "$undefined", "\"error from file parser\"",
  "\"invalid property value\"", "\"invalid property name\"",
  "\"invalid element name\"", "\"invalid defaults name\"",
  "\"invalid import value\"",
  "\"invalid argb color. Requires 8 (not 7) elements: argb:AARRGGBB.\"",
  "\"Integer number\"", "\"Floating-point number\"",
  "\"UTF-8 encode string\"", "\"Media type\"", "\"Character\"",
  "\"property name\"", "\"Color value by name\"", "\"Element name\"",
  "\"Boolean value (true or false)\"", "\"Hexidecimal color value\"",
  "\"Reference\"", "\"Name of element\"", "\"Center\"", "\"East\"",
  "\"West\"", "\"North\"", "\"South\"", "\"@media\"", "\"None\"",
  "\"Bold\"", "\"Italic\"", "\"Underline\"", "\"Strikethrough\"",
  "\"Dash\"", "\"Solid\"", "\"Uppercase\"", "\"Capitalize\"",
  "\"Lowercase\"", "\"pixels\"", "\"mm\"", "\"em\"", "\"ch\"", "\"%\"",
  "\"Degrees\"", "\"Gradians\"", "\"Radians\"", "\"Turns\"",
  "\"Horizontal\"", "\"Vertical\"", "\"Default\"", "\"Pointer\"",
  "\"Text\"", "\"rgb[a] colorscheme\"", "\"hsl colorscheme\"",
  "\"hwb colorscheme\"", "\"cmyk colorscheme\"", "\"an URL\"",
  "\"an WIDTH\"", "\"an HEIGHT\"", "\"an BOTH\"", "\"an TO\"",
  "\"an LEFT\"", "\"an RIGHT\"", "\"an TOP\"", "\"an BOTTOM\"",
  "\"a linear gradient\"", "\"Parent left ('(')\"",
  "\"Parent right (')')\"", "\"comma separator (',')\"",
  "\"Optional comma separator (',')\"", "\"forward slash ('/')\"",
  "\"Percent sign ('%')\"", "\"List open ('[')\"", "\"List close (']')\"",
  "\"Add ('+')\"", "\"Subtract ('-')\"", "\"Multiply ('*')\"",
  "\"Max ('max')\"", "\"Min ('min')\"", "\"Min ('round')\"",
  "\"Min ('floor')\"", "\"Min ('ceil')\"", "\"calc\"",
  "\"bracket open ('{')\"", "\"bracket close ('}')\"",
  "\"property separator (':')\"", "\"property close (';')\"",
  "\"Name separator (' ' or '.')\"", "\"Selector separator (',')\"",
  "\"Element section ('# {name} { ... }')\"", "\"White space\"",
  "\"Default settings section ( '* { ... }')\"", "\"Configuration block\"",
  "\"Reset Theme\"", "\"Transparent\"", "\"Inherit\"", "\"Width\"",
  "\"Height\"", "\"Min\"", "\"Monitor-ID\"", "\"Max\"", "\"-\"", "\"var\"",
  "\"env\"", "$accept", "t_main", "t_name_prefix_optional",
  "t_entry_list_included", "t_entry_list",
  "t_config_property_list_optional", "t_config_property_list",
  "t_config_property", "t_property_list_optional", "t_property_list",
  "t_property", "t_property_element", "t_property_direction",
  "t_property_scale_type", "t_color_list",
  "t_property_element_list_optional", "t_property_element_list",
  "t_property_position", "t_property_position_ew",
  "t_property_position_sn", "t_property_highlight_styles",
  "t_property_highlight_style", "t_property_distance_zero",
  "t_property_distance_unit", "t_property_distance_unit_math",
  "t_property_distance_unit_math2", "t_property_distance_unit_math3",
  "t_property_distance", "t_property_unit", "t_property_line_style",
  "t_property_color", "t_property_color_opt_alpha_c",
  "t_property_color_opt_alpha_ws", "t_property_color_value_angle",
  "t_property_color_value_unit", "t_property_color_value",
  "t_property_orientation", "t_property_cursor", "t_property_name",
  "t_entry_name_path_selectors", "t_entry_name_path",
  "t_property_name_list", YY_NULLPTR
};
#endif

#define YYPACT_NINF (-212)
#define YYTABLE_NINF (-120)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -212,    12,   -79,    16,  -212,  -212,   -50,  -212,   -53,   -51,
     115,    16,    40,    75,    75,  -212,    47,    29,    25,  -212,
      50,    75,  -212,    51,    68,    75,  -212,  -212,    51,    93,
      75,   115,   141,    -3,  -212,  -212,   177,  -212,  -212,    75,
      75,    76,    29,  -212,   -13,    97,   123,   116,    17,   181,
    -212,  -212,   128,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,  -212,  -212,   138,   145,   150,   157,   168,   180,
     271,   204,  -212,  -212,   212,   220,   249,  -212,    69,   132,
     577,  -212,    11,    30,  -212,  -212,  -212,   253,  -212,  -212,
     285,   268,   272,   274,    73,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,   134,  -212,   134,   167,  -212,   174,   167,   167,
     167,   342,     7,  -212,   204,  -212,   283,   290,    36,   338,
     357,  -212,  -212,  -212,  -212,  -212,   217,   181,    11,  -212,
    -212,   277,  -212,  -212,  -212,   293,   344,  -212,  -212,  -212,
    -212,  -212,   292,    24,   299,    53,   286,    61,    72,   171,
     284,   186,  -212,   296,  -212,   443,   273,   181,    36,  -212,
      99,   230,   196,   193,   529,   304,    11,  -212,    22,    59,
      82,   356,   311,  -212,   374,   380,    74,   167,   167,  -212,
    -212,  -212,  -212,   167,   167,   167,   167,  -212,    87,  -212,
    -212,  -212,  -212,   323,  -212,    26,    26,  -212,   204,  -212,
    -212,  -212,   261,    36,    36,    36,    36,    36,   134,    36,
      36,    36,    36,    36,   309,   529,   329,   529,  -212,   126,
    -212,  -212,  -212,   330,   331,   128,   332,   167,   328,   333,
     128,   334,   128,   335,   167,  -212,  -212,  -212,  -212,   347,
      26,  -212,   242,  -212,  -212,  -212,  -212,    99,    99,  -212,
     230,   230,   230,   230,   230,  -212,   348,   337,   349,  -212,
     350,   336,   351,   410,   353,   167,   167,   354,   167,   359,
     167,   128,  -212,   266,  -212,   341,  -212,   345,   352,  -212,
    -212,   360,   362,   361,   360,  -212,   360,  -212,   365,   367,
    -212,  -212,  -212,  -212,   152,   167,   369,   167,   128,   370,
     371,   167,  -212,   156,  -212,  -212,  -212,   372,   373,  -212,
    -212,   360,  -212,   360,  -212,   375,   377,  -212,  -212
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     2,     5,     1,     8,     0,     3,     0,     0,
       0,     6,     0,    23,    17,   157,     0,   154,     0,   153,
       0,    24,    25,     0,     0,    18,    19,    21,   160,     0,
      23,   156,   159,     0,    10,    26,     0,     7,    20,    23,
       0,     0,   155,   158,     0,     0,     0,     0,    33,    34,
      35,    36,   137,    38,   132,    37,    73,    78,    79,    80,
      81,    84,    85,    88,    86,    87,    89,    91,    90,   148,
     149,   150,   151,   152,     0,     0,     0,     0,     0,     0,
      65,     0,   133,    32,     0,     0,     0,    43,    74,    75,
      45,    82,     0,    39,    46,    48,    49,     0,   161,     9,
       0,     0,     0,     0,     0,   121,   120,   114,   115,   116,
     117,   118,   119,    92,   119,     0,   134,     0,     0,     0,
       0,     0,     0,    68,    69,    67,     0,    66,     0,     0,
       0,    27,    76,    77,    83,    44,   119,     0,    40,    93,
      22,     0,     8,     8,     8,     0,     0,   111,   112,   147,
     146,   138,   145,   147,     0,     0,   139,     0,     0,     0,
       0,     0,    63,     0,    47,     0,    95,     0,     0,   101,
     104,   110,     0,     0,     0,     0,    41,     8,     4,     4,
       4,     0,     0,   144,     0,     0,     0,     0,     0,   140,
     142,   141,   143,     0,     0,     0,     0,    50,     0,    56,
      55,    57,    58,     0,    52,     0,     0,    71,    72,    70,
      94,    96,     0,     0,     0,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    42,     4,
      11,    12,    14,     0,     0,   137,     0,     0,     0,     0,
     137,     0,   137,     0,     0,    62,    60,    61,    59,     0,
       0,    64,     0,    97,    99,   100,    98,   102,   103,   113,
     106,   105,   107,   108,   109,    28,     0,     0,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   137,    51,     0,    54,     0,    30,     0,     0,     8,
     123,   135,     0,     0,   135,   130,   135,   127,     0,     0,
      53,    29,    31,     8,     4,     0,     0,     0,   137,     0,
       0,     0,   129,     4,    16,   136,   122,     0,     0,   131,
     126,   135,    15,   135,   125,     0,     0,   128,   124
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -212,  -212,  -212,  -212,    -5,  -212,  -212,   416,    92,  -212,
      23,   -78,  -212,  -212,  -117,  -212,  -212,  -212,   358,   368,
    -212,   355,   -73,   102,   133,    46,   278,   -72,   -39,  -101,
     -87,   -59,  -211,     4,  -119,  -113,  -212,  -212,   140,  -212,
     417,  -212
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    10,     2,     3,    24,    25,    26,    20,    21,
      22,    86,   203,   249,   161,   126,   127,    87,    88,    89,
      90,    91,    92,   169,   170,   171,   172,    93,   112,   113,
      94,   306,   116,   155,   151,   152,    95,    96,    23,    16,
      17,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      11,   158,   125,   135,   154,   156,   156,    44,    45,   156,
     114,   147,     4,   148,     5,    46,    12,   149,   150,   138,
     139,   136,   137,    52,   272,   100,    54,  -119,  -119,   277,
      13,   279,    14,    -4,   184,   162,   188,    27,   194,   196,
     -93,   -93,    52,     6,    35,    54,   166,   167,    27,     6,
     105,   106,   175,    18,   101,   107,   108,   109,   110,    74,
      75,    76,    77,   149,   150,   176,   139,   160,   239,   240,
     299,   149,   150,   238,   241,   242,   243,   244,    74,    75,
      76,    77,   149,   150,   149,   150,     6,   209,   111,   252,
      19,   145,   185,    81,    59,    60,   226,   318,   114,  -119,
      47,    82,   168,   228,   139,     7,   230,     8,     9,     6,
      33,     7,   -93,     8,     9,   245,    32,   259,   251,   162,
      82,   187,    41,   157,   274,   281,   163,   210,   211,   193,
      30,    97,    15,   283,    34,    31,    36,   178,   179,   180,
     195,   146,   237,   231,   246,   247,   248,   266,     7,   268,
       8,     9,    37,     6,    28,    57,    58,   294,    43,   296,
      99,   298,   293,   162,   102,    28,   232,   105,   106,   213,
     214,     7,   229,     8,     9,   215,    39,   149,   150,     6,
      98,    40,   104,     6,   153,   150,   315,    48,    49,    50,
     103,    51,   321,    52,   317,    53,    54,    55,   115,    56,
      57,    58,    59,    60,   117,    61,    62,    63,    64,    65,
     269,   118,    66,    67,    68,     7,   119,     8,     9,   107,
     108,   109,   110,   120,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,   121,   309,   314,   310,   197,   198,
     322,     7,    79,     8,     9,     7,   122,     8,     9,    80,
     105,   106,   111,   204,   205,   107,   108,   109,   110,    81,
     224,   225,   325,   218,   326,   260,   261,   262,   263,   264,
     128,    82,    83,   219,   220,   221,   222,   223,   129,    84,
      85,    48,    49,    50,   304,    51,   130,    52,   111,    53,
      54,    55,   123,    56,    57,    58,    59,    60,   313,    61,
      62,    63,    64,    65,   216,   217,    66,    67,    68,   284,
     205,   107,   108,   109,   110,   254,   255,   256,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,   253,   189,
     190,   191,   192,   300,   205,   131,    79,   140,   219,   220,
     221,   222,   223,    80,   111,   199,   200,   201,   202,   257,
     258,   142,   141,   124,   159,   143,   164,   144,   165,   173,
     177,   181,   182,   183,   206,    82,    83,    48,    49,    50,
     186,    51,   227,    52,   233,    53,    54,    55,   234,    56,
      57,    58,    59,    60,   235,    61,    62,    63,    64,    65,
     236,   250,    66,    67,    68,   265,   267,   270,   271,   275,
     273,   276,   278,   280,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,   282,   285,   287,   288,   290,   289,
     291,   295,    79,   286,   292,   174,   297,   301,   305,    80,
     307,   302,   308,   311,   312,   303,   316,   319,   320,    81,
     324,    38,   327,   323,   328,   134,   212,   133,    42,     0,
       0,    82,    83,    48,    49,    50,   132,    51,     0,    52,
       0,    53,    54,    55,   207,    56,    57,    58,    59,    60,
       0,    61,    62,    63,    64,    65,     0,     0,    66,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
       0,     0,     0,     0,     0,     0,     0,     0,    79,     0,
       0,     0,     0,     0,     0,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   208,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    82,    83,    48,
      49,    50,     0,    51,     0,    52,     0,    53,    54,    55,
       0,    56,    57,    58,    59,    60,     0,    61,    62,    63,
      64,    65,     0,     0,    66,    67,    68,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,     0,     0,     0,     0,
       0,     0,     0,    52,    79,     0,    54,     0,     0,     0,
       0,    80,     0,     0,     0,    61,    62,    63,    64,    65,
       0,    81,    66,    67,    68,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    83,     0,     0,     0,     0,    74,
      75,    76,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82
};

static const yytype_int16 yycheck[] =
{
       5,   120,    80,    90,   117,   118,   119,    10,    11,   122,
      49,   112,     0,   114,    93,    18,    66,    10,    11,    92,
      92,    10,    11,    16,   235,    38,    19,    10,    11,   240,
      83,   242,    83,    17,    10,   122,   155,    14,   157,   158,
      10,    11,    16,    27,    21,    19,    10,    11,    25,    27,
      33,    34,   130,    13,    67,    38,    39,    40,    41,    52,
      53,    54,    55,    10,    11,   138,   138,    60,   187,   188,
     281,    10,    11,   186,   193,   194,   195,   196,    52,    53,
      54,    55,    10,    11,    10,    11,    27,   165,    71,   206,
      15,    18,    68,    82,    25,    26,   174,   308,   137,    82,
     103,    94,    66,   176,   176,    89,    84,    91,    92,    27,
      85,    89,    82,    91,    92,    28,    87,   218,   205,   206,
      94,    68,    30,   119,   237,   244,   122,   166,   167,    68,
      83,    39,    17,   250,    84,    88,    85,   142,   143,   144,
      68,    68,    68,    84,    57,    58,    59,   225,    89,   227,
      91,    92,    84,    27,    14,    23,    24,   276,    17,   278,
      84,   280,   275,   250,    67,    25,    84,    33,    34,    70,
      71,    89,   177,    91,    92,    76,    83,    10,    11,    27,
      40,    88,    66,    27,    10,    11,   305,    10,    11,    12,
      67,    14,   311,    16,   307,    18,    19,    20,    70,    22,
      23,    24,    25,    26,    66,    28,    29,    30,    31,    32,
      84,    66,    35,    36,    37,    89,    66,    91,    92,    38,
      39,    40,    41,    66,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    66,   294,    84,   296,    67,    68,
      84,    89,    65,    91,    92,    89,    66,    91,    92,    72,
      33,    34,    71,    67,    68,    38,    39,    40,    41,    82,
      67,    68,   321,    67,   323,   219,   220,   221,   222,   223,
      66,    94,    95,    77,    78,    79,    80,    81,    66,   102,
     103,    10,    11,    12,   289,    14,    66,    16,    71,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   303,    28,
      29,    30,    31,    32,    74,    75,    35,    36,    37,    67,
      68,    38,    39,    40,    41,   213,   214,   215,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    67,    43,
      44,    45,    46,    67,    68,    86,    65,    84,    77,    78,
      79,    80,    81,    72,    71,    61,    62,    63,    64,   216,
     217,    83,    67,    82,    12,    83,    73,    83,    68,    21,
      83,    68,    18,    71,    68,    94,    95,    10,    11,    12,
      71,    14,    68,    16,    18,    18,    19,    20,    67,    22,
      23,    24,    25,    26,    10,    28,    29,    30,    31,    32,
      10,    68,    35,    36,    37,    86,    67,    67,    67,    71,
      68,    68,    68,    68,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    67,    67,    67,    67,    67,    83,
      10,    67,    65,    86,    71,    68,    67,    86,    68,    72,
      68,    86,    71,    68,    67,    83,    67,    67,    67,    82,
      67,    25,    67,    71,    67,    90,   168,    89,    31,    -1,
      -1,    94,    95,    10,    11,    12,    88,    14,    -1,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    28,    29,    30,    31,    32,    -1,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    95,    10,
      11,    12,    -1,    14,    -1,    16,    -1,    18,    19,    20,
      -1,    22,    23,    24,    25,    26,    -1,    28,    29,    30,
      31,    32,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    65,    -1,    19,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      -1,    82,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    95,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   105,   107,   108,     0,    93,    27,    89,    91,    92,
     106,   108,    66,    83,    83,    17,   143,   144,    13,    15,
     112,   113,   114,   142,   109,   110,   111,   114,   142,   145,
      83,    88,    87,    85,    84,   114,    85,    84,   111,    83,
      88,   112,   144,    17,    10,    11,    18,   103,    10,    11,
      12,    14,    16,    18,    19,    20,    22,    23,    24,    25,
      26,    28,    29,    30,    31,    32,    35,    36,    37,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    65,
      72,    82,    94,    95,   102,   103,   115,   121,   122,   123,
     124,   125,   126,   131,   134,   140,   141,   112,   142,    84,
      38,    67,    67,    67,    66,    33,    34,    38,    39,    40,
      41,    71,   132,   133,   132,    70,   136,    66,    66,    66,
      66,    66,    66,    21,    82,   115,   119,   120,    66,    66,
      66,    86,   123,   122,   125,   134,    10,    11,   126,   131,
      84,    67,    83,    83,    83,    18,    68,   133,   133,    10,
      11,   138,   139,    10,   139,   137,   139,   137,   138,    12,
      60,   118,   134,   137,    73,    68,    10,    11,    66,   127,
     128,   129,   130,    21,    68,   115,   126,    83,   108,   108,
     108,    68,    18,    71,    10,    68,    71,    68,   138,    43,
      44,    45,    46,    68,   138,    68,   138,    67,    68,    61,
      62,    63,    64,   116,    67,    68,    68,    21,    82,   115,
     132,   132,   130,    70,    71,    76,    74,    75,    67,    77,
      78,    79,    80,    81,    67,    68,   115,    68,   126,   108,
      84,    84,    84,    18,    67,    10,    10,    68,   139,   138,
     138,   138,   138,   138,   138,    28,    57,    58,    59,   117,
      68,   134,   118,    67,   127,   127,   127,   128,   128,   133,
     129,   129,   129,   129,   129,    86,   115,    67,   115,    84,
      67,    67,   136,    68,   139,    71,    68,   136,    68,   136,
      68,   138,    67,   118,    67,    67,    86,    67,    67,    83,
      67,    10,    71,   139,   138,    67,   138,    67,   138,   136,
      67,    86,    86,    83,   108,    68,   135,    68,    71,   135,
     135,    68,    67,   108,    84,   138,    67,   139,   136,    67,
      67,   138,    84,    71,    67,   135,   135,    67,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   104,   105,   106,   106,   107,   107,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   114,   114,
     114,   114,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   116,   116,   116,   116,   117,
     117,   117,   117,   118,   118,   119,   119,   120,   120,   120,
     120,   120,   120,   121,   121,   121,   121,   121,   122,   122,
     123,   123,   124,   124,   125,   125,   125,   125,   125,   125,
     125,   125,   126,   126,   127,   127,   127,   127,   128,   128,
     128,   128,   129,   129,   129,   130,   130,   130,   130,   130,
     130,   131,   131,   131,   132,   132,   132,   132,   132,   133,
     133,   133,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   135,   135,   136,   136,   137,
     137,   137,   137,   137,   138,   138,   139,   139,   140,   140,
     141,   141,   141,   142,   143,   143,   143,   144,   144,   144,
     145,   145
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     1,     3,     5,     0,     6,
       5,    10,    10,    11,    10,    15,    14,     0,     1,     1,
       2,     1,     4,     0,     1,     1,     2,     4,     7,     9,
       8,     9,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     4,     1,     2,     1,     1,     3,     1,     1,
       4,     6,     4,     7,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     1,     1,     1,     1,
       3,     3,     3,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     2,     1,     2,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     3,
       1,     3,     3,     5,     1,     1,     1,     1,     1,     0,
       1,     1,     9,     7,    12,    10,     9,     7,    11,     8,
       7,     9,     1,     1,     2,     0,     2,     0,     2,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     1,     3,     2,
       1,     3
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,    95,     0
};

/* Error token number */
#define YYTERROR 1


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
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
    while (0)
#endif

# define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)



#undef yynerrs
#define yynerrs (yystackp->yyerrcnt)
#undef yychar
#define yychar (yystackp->yyrawchar)
#undef yylval
#define yylval (yystackp->yyval)
#undef yylloc
#define yylloc (yystackp->yyloc)


static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif



/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char *what)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (what);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char *what)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp, what);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Type, Value, Location, what);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

struct yyGLRStack;
static void yypstack (struct yyGLRStack* yystackp, ptrdiff_t yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (struct yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif


#if YYERROR_VERBOSE

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static ptrdiff_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      ptrdiff_t yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return YY_CAST (ptrdiff_t, strlen (yystr));
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers. */
typedef int yyStateNum;

/** Rule numbers. */
typedef int yyRuleNum;

/** Grammar symbol. */
typedef int yySymbol;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  ptrdiff_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  ptrdiff_t yysize;
  ptrdiff_t yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;
  /* To compute the location of the error token.  */
  yyGLRStackItem yyerror_range[3];

  int yyerrcnt;
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  ptrdiff_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, YYLTYPE *yylocp, const char *what, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yylocp, what, yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  return yytoken == YYEMPTY ? "" : yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      else
        /* The effect of using yysval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yySymbol
yygetToken (int *yycharp, yyGLRStack* yystackp, const char *what)
{
  yySymbol yytoken;
  YYUSE (what);
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token: "));
      *yycharp = yylex (&yylval, &yylloc);
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = yytoken = YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp, YYLTYPE *yylocp, const char *what)
{
  yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow;
  YYUSE (yyvalp);
  YYUSE (yylocp);
  YYUSE (what);
  YYUSE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (yylocp, what, YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  /* Default location. */
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;

  switch (yyn)
    {
  case 2:
#line 324 "../lexer/theme-parser.y"
                        {
    // Dummy at this point.
    if ( rofi_theme == NULL ) {
      rofi_theme_reset();
    }

    rofi_theme_widget_add_properties ( rofi_theme, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.theme)->properties );
    for ( unsigned int i = 0; i < (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.theme)->num_widgets; i++ ) {
        ThemeWidget *d = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.theme)->widgets[i];
        rofi_theme_parse_merge_widgets(rofi_theme, d);
    }
    rofi_theme_free ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.theme) );
}
#line 1552 "lexer/theme-parser.c"
    break;

  case 3:
#line 343 "../lexer/theme-parser.y"
                {}
#line 1558 "lexer/theme-parser.c"
    break;

  case 4:
#line 344 "../lexer/theme-parser.y"
         {}
#line 1564 "lexer/theme-parser.c"
    break;

  case 5:
#line 348 "../lexer/theme-parser.y"
             {
  ((*yyvalp).theme) =(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.theme);
}
#line 1572 "lexer/theme-parser.c"
    break;

  case 6:
#line 351 "../lexer/theme-parser.y"
                                                   {

    rofi_theme_reset();
    rofi_theme_free((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.theme));
    ((*yyvalp).theme) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.theme);
}
#line 1583 "lexer/theme-parser.c"
    break;

  case 7:
#line 360 "../lexer/theme-parser.y"
                                                                              {
  ((*yyvalp).theme) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.theme);
}
#line 1591 "lexer/theme-parser.c"
    break;

  case 8:
#line 363 "../lexer/theme-parser.y"
        {
    ((*yyvalp).theme) = g_slice_new0 ( ThemeWidget );
    if ( rofi_configuration == NULL ) {
      rofi_configuration       = g_slice_new0 ( ThemeWidget );
      rofi_configuration->name = g_strdup ( "Root" );
    }
  }
#line 1603 "lexer/theme-parser.c"
    break;

  case 9:
#line 371 "../lexer/theme-parser.y"
{
    for ( GList *liter = g_list_first ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.list)); liter; liter = g_list_next ( liter ) ) {
        ThemeWidget *widget = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.theme);
        for ( GList *iter = g_list_first ( (GList*)liter->data ); widget && iter ; iter = g_list_next ( iter ) ) {
            widget = rofi_theme_find_or_create_name ( widget, iter->data );
        }
        g_list_free_full ( (GList*)liter->data, g_free );
        widget->set = TRUE;
        rofi_theme_widget_add_properties ( widget, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list));
    }
    if ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) ) {
        g_hash_table_destroy ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) );
    }
    g_list_free ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.list) );
}
#line 1623 "lexer/theme-parser.c"
    break;

  case 10:
#line 386 "../lexer/theme-parser.y"
                                                                     {
    ThemeWidget *widget = rofi_theme_find_or_create_name ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.theme), "*" );
    rofi_theme_widget_add_properties (widget, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list));
    if ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) ) {
        g_hash_table_destroy ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) );
    }
}
#line 1635 "lexer/theme-parser.c"
    break;

  case 11:
#line 393 "../lexer/theme-parser.y"
                                                                                                            {
    gchar *name = g_strdup_printf("@media ( %s: %d )",(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.sval), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.ival));
    ThemeWidget *widget = rofi_theme_find_or_create_name ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval.theme), name );
    widget->set = TRUE;
    widget->media = g_slice_new0(ThemeMedia);
    widget->media->type = rofi_theme_parse_media_type ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.sval) );
    widget->media->value = (double)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.ival);
    for ( unsigned int i = 0; i < (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->num_widgets; i++ ) {
        ThemeWidget *d = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->widgets[i];
        rofi_theme_parse_merge_widgets(widget, d);
    }
    g_free ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.sval) );
    g_free ( name );
}
#line 1654 "lexer/theme-parser.c"
    break;

  case 12:
#line 407 "../lexer/theme-parser.y"
                                                                                                               {
    gchar *name = g_strdup_printf("@media ( %s: %f )",(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.sval), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval));
    ThemeWidget *widget = rofi_theme_find_or_create_name ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval.theme), name );
    widget->set = TRUE;
    widget->media = g_slice_new0(ThemeMedia);
    widget->media->type = rofi_theme_parse_media_type ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.sval) );
    widget->media->value = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval);
    for ( unsigned int i = 0; i < (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->num_widgets; i++ ) {
        ThemeWidget *d = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->widgets[i];
        rofi_theme_parse_merge_widgets(widget, d);
    }
    g_free ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.sval) );
    g_free ( name );
}
#line 1673 "lexer/theme-parser.c"
    break;

  case 13:
#line 421 "../lexer/theme-parser.y"
                                                                                                                      {
    gchar *name = g_strdup_printf("@media ( %s: %d px )",(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.sval), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.ival));
    ThemeWidget *widget = rofi_theme_find_or_create_name ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-10)].yystate.yysemantics.yysval.theme), name );
    widget->set = TRUE;
    widget->media = g_slice_new0(ThemeMedia);
    widget->media->type = rofi_theme_parse_media_type ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.sval) );
    widget->media->value = (double)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.ival);
    for ( unsigned int i = 0; i < (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->num_widgets; i++ ) {
        ThemeWidget *d = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->widgets[i];
        rofi_theme_parse_merge_widgets(widget, d);
    }
    g_free ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.sval) );
    g_free ( name );
}
#line 1692 "lexer/theme-parser.c"
    break;

  case 14:
#line 435 "../lexer/theme-parser.y"
                                                                                                                {
    gchar *name = g_strdup_printf("@media ( %s: %s )",(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.sval), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.bval)?"true":"false");
    ThemeWidget *widget = rofi_theme_find_or_create_name ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval.theme), name );
    widget->set = TRUE;
    widget->media = g_slice_new0(ThemeMedia);
    widget->media->type = rofi_theme_parse_media_type ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.sval) );
    widget->media->boolv = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.bval);
    for ( unsigned int i = 0; i < (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->num_widgets; i++ ) {
        ThemeWidget *d = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->widgets[i];
        rofi_theme_parse_merge_widgets(widget, d);
    }
    g_free ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.sval) );
    g_free ( name );
}
#line 1711 "lexer/theme-parser.c"
    break;

  case 15:
#line 449 "../lexer/theme-parser.y"
                                                                                                                                                                           {
    gchar *name = g_strdup_printf("@media ( %s: %s )",(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-11)].yystate.yysemantics.yysval.sval), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.bval)?"true":"false");
    ThemeWidget *widget = rofi_theme_find_or_create_name ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-14)].yystate.yysemantics.yysval.theme), name );
    widget->set = TRUE;
    widget->media = g_slice_new0(ThemeMedia);
    widget->media->type = rofi_theme_parse_media_type ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-11)].yystate.yysemantics.yysval.sval) );
    widget->media->boolv = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.bval);
    for ( unsigned int i = 0; i < (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->num_widgets; i++ ) {
        ThemeWidget *d = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->widgets[i];
        rofi_theme_parse_merge_widgets(widget, d);
    }
    g_free ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-11)].yystate.yysemantics.yysval.sval) );
    g_free ( name );
}
#line 1730 "lexer/theme-parser.c"
    break;

  case 16:
#line 463 "../lexer/theme-parser.y"
                                                                                                                                                                 {
    gchar *name = g_strdup_printf("@media ( %s: %s )",(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-10)].yystate.yysemantics.yysval.sval), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.bval)?"true":"false");
    ThemeWidget *widget = rofi_theme_find_or_create_name ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-13)].yystate.yysemantics.yysval.theme), name );
    widget->set = TRUE;
    widget->media = g_slice_new0(ThemeMedia);
    widget->media->type = rofi_theme_parse_media_type ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-10)].yystate.yysemantics.yysval.sval) );
    widget->media->boolv = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.bval);
    for ( unsigned int i = 0; i < (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->num_widgets; i++ ) {
        ThemeWidget *d = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.theme)->widgets[i];
        rofi_theme_parse_merge_widgets(widget, d);
    }
    g_free ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-10)].yystate.yysemantics.yysval.sval) );
    g_free ( name );
}
#line 1749 "lexer/theme-parser.c"
    break;

  case 17:
#line 480 "../lexer/theme-parser.y"
         {}
#line 1755 "lexer/theme-parser.c"
    break;

  case 19:
#line 485 "../lexer/theme-parser.y"
                    {
}
#line 1762 "lexer/theme-parser.c"
    break;

  case 20:
#line 487 "../lexer/theme-parser.y"
                                             {
}
#line 1769 "lexer/theme-parser.c"
    break;

  case 21:
#line 491 "../lexer/theme-parser.y"
             {
    char *error = NULL;
    if ( config_parse_set_property ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property), &error ) ) {
        // TODO Generate error.
#ifdef FATAL_CONFIG_ERROR
        yyerror ( &((*yylocp)), (*yylocp).filename, error );
#else
        g_warning("%s:%d:%d: %s\n", (*yylocp).filename, (*yylocp).first_line, (*yylocp).first_column, error);
        GString *str = g_string_new("");
        g_string_append_printf(str,"%s:%d:%d: %s\n", (*yylocp).filename, (*yylocp).first_line, (*yylocp).first_column, error);
        rofi_add_error_message(str);
#endif
        g_free(error);
    }
    // We don't keep any reference to this after this point, so the property can be free'ed.
    rofi_theme_property_free ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property) );
}
#line 1791 "lexer/theme-parser.c"
    break;

  case 22:
#line 509 "../lexer/theme-parser.y"
{
  
  for ( GList *iter = g_list_first( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.list)) ; iter; iter = g_list_next(iter)){
    ThemeWidget *widget = rofi_configuration;
    widget = rofi_theme_find_or_create_name ( widget, iter->data );
    widget->set = TRUE;
    rofi_theme_widget_add_properties ( widget, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list));
  }
  if ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) ) {
    g_hash_table_destroy ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property_list) );
  }
  g_list_free_full ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.list), g_free );
}
#line 1809 "lexer/theme-parser.c"
    break;

  case 23:
#line 528 "../lexer/theme-parser.y"
                   { ((*yyvalp).property_list) = NULL; }
#line 1815 "lexer/theme-parser.c"
    break;

  case 24:
#line 529 "../lexer/theme-parser.y"
                            { ((*yyvalp).property_list) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property_list); }
#line 1821 "lexer/theme-parser.c"
    break;

  case 25:
#line 533 "../lexer/theme-parser.y"
             {
    ((*yyvalp).property_list) = g_hash_table_new_full ( g_str_hash, g_str_equal, NULL, (GDestroyNotify)rofi_theme_property_free );
    g_hash_table_replace ( ((*yyvalp).property_list), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property)->name, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property) );
  }
#line 1830 "lexer/theme-parser.c"
    break;

  case 26:
#line 537 "../lexer/theme-parser.y"
                             {
    // Old will be free'ed, and key/value will be replaced.
    g_hash_table_replace ( ((*yyvalp).property_list), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property)->name, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property) );
  }
#line 1839 "lexer/theme-parser.c"
    break;

  case 27:
#line 544 "../lexer/theme-parser.y"
                                                     {
    ((*yyvalp).property) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.property);
    ((*yyvalp).property)->name = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.sval);
   }
#line 1848 "lexer/theme-parser.c"
    break;

  case 28:
#line 548 "../lexer/theme-parser.y"
                                                                                      {
        ((*yyvalp).property) = rofi_theme_property_create ( P_LINK );
        ((*yyvalp).property)->name = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.sval);
        ((*yyvalp).property)->value.link.name = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.sval);
    }
#line 1858 "lexer/theme-parser.c"
    break;

  case 29:
#line 553 "../lexer/theme-parser.y"
                                                                                                                 {
        ((*yyvalp).property) = rofi_theme_property_create ( P_LINK );
        ((*yyvalp).property)->name = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval.sval);
        ((*yyvalp).property)->value.link.name = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.sval);
        ((*yyvalp).property)->value.link.def_value = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.property);
    }
#line 1869 "lexer/theme-parser.c"
    break;

  case 30:
#line 559 "../lexer/theme-parser.y"
                                                                                                      {
  ((*yyvalp).property) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.property);
  ((*yyvalp).property)->name = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.sval);
}
#line 1878 "lexer/theme-parser.c"
    break;

  case 31:
#line 563 "../lexer/theme-parser.y"
                                                                                                                         {
  ((*yyvalp).property) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.property);
  ((*yyvalp).property)->name = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval.sval);
}
#line 1887 "lexer/theme-parser.c"
    break;

  case 32:
#line 569 "../lexer/theme-parser.y"
              {
        ((*yyvalp).property) = rofi_theme_property_create ( P_INHERIT );
    }
#line 1895 "lexer/theme-parser.c"
    break;

  case 33:
#line 572 "../lexer/theme-parser.y"
          {
        ((*yyvalp).property) = rofi_theme_property_create ( P_INTEGER );
        ((*yyvalp).property)->value.i = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
    }
#line 1904 "lexer/theme-parser.c"
    break;

  case 34:
#line 576 "../lexer/theme-parser.y"
             {
        ((*yyvalp).property) = rofi_theme_property_create ( P_DOUBLE );
        ((*yyvalp).property)->value.f = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval);
    }
#line 1913 "lexer/theme-parser.c"
    break;

  case 35:
#line 580 "../lexer/theme-parser.y"
             {
        ((*yyvalp).property) = rofi_theme_property_create ( P_STRING );
        ((*yyvalp).property)->value.s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval);
    }
#line 1922 "lexer/theme-parser.c"
    break;

  case 36:
#line 584 "../lexer/theme-parser.y"
           {
        ((*yyvalp).property) = rofi_theme_property_create ( P_CHAR );
        ((*yyvalp).property)->value.c = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.cval);
    }
#line 1931 "lexer/theme-parser.c"
    break;

  case 37:
#line 588 "../lexer/theme-parser.y"
           {
        ((*yyvalp).property) = rofi_theme_property_create ( P_LINK );
        ((*yyvalp).property)->value.link.name = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval);
    }
#line 1940 "lexer/theme-parser.c"
    break;

  case 38:
#line 592 "../lexer/theme-parser.y"
              {
        ((*yyvalp).property) = rofi_theme_property_create ( P_BOOLEAN );
        ((*yyvalp).property)->value.b = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.bval);
    }
#line 1949 "lexer/theme-parser.c"
    break;

  case 39:
#line 596 "../lexer/theme-parser.y"
                       {
        ((*yyvalp).property) = rofi_theme_property_create ( P_PADDING );
        ((*yyvalp).property)->value.padding = (RofiPadding){ (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance), rofi_theme_property_copy_distance((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance)), rofi_theme_property_copy_distance((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance)), rofi_theme_property_copy_distance((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance)) };
}
#line 1958 "lexer/theme-parser.c"
    break;

  case 40:
#line 600 "../lexer/theme-parser.y"
                                                     {
        ((*yyvalp).property) = rofi_theme_property_create ( P_PADDING );
        ((*yyvalp).property)->value.padding = (RofiPadding){ (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.distance), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance), rofi_theme_property_copy_distance((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.distance)), rofi_theme_property_copy_distance((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance)) };
}
#line 1967 "lexer/theme-parser.c"
    break;

  case 41:
#line 604 "../lexer/theme-parser.y"
                                                                              {
        ((*yyvalp).property) = rofi_theme_property_create ( P_PADDING );
        ((*yyvalp).property)->value.padding = (RofiPadding){ (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.distance), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance), rofi_theme_property_copy_distance((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.distance)) };
}
#line 1976 "lexer/theme-parser.c"
    break;

  case 42:
#line 608 "../lexer/theme-parser.y"
                                                                                                       {
        ((*yyvalp).property) = rofi_theme_property_create ( P_PADDING );
        ((*yyvalp).property)->value.padding = (RofiPadding){ (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.distance), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.distance), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance) };
}
#line 1985 "lexer/theme-parser.c"
    break;

  case 43:
#line 612 "../lexer/theme-parser.y"
                      {
        ((*yyvalp).property) = rofi_theme_property_create ( P_POSITION );
        ((*yyvalp).property)->value.i = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.wloc);
}
#line 1994 "lexer/theme-parser.c"
    break;

  case 44:
#line 616 "../lexer/theme-parser.y"
                                               {
        ((*yyvalp).property) = rofi_theme_property_create ( P_HIGHLIGHT );
        ((*yyvalp).property)->value.highlight.style = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.ival)|ROFI_HL_COLOR;
        ((*yyvalp).property)->value.highlight.color = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.colorval);
}
#line 2004 "lexer/theme-parser.c"
    break;

  case 45:
#line 621 "../lexer/theme-parser.y"
                              {
        ((*yyvalp).property) = rofi_theme_property_create ( P_HIGHLIGHT );
        ((*yyvalp).property)->value.highlight.style = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
}
#line 2013 "lexer/theme-parser.c"
    break;

  case 46:
#line 625 "../lexer/theme-parser.y"
                   {
        ((*yyvalp).property) = rofi_theme_property_create ( P_COLOR );
        ((*yyvalp).property)->value.color = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.colorval);
}
#line 2022 "lexer/theme-parser.c"
    break;

  case 47:
#line 629 "../lexer/theme-parser.y"
                                                            {
        ((*yyvalp).property) = rofi_theme_property_create ( P_LIST );
        ((*yyvalp).property)->value.list = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.list);
}
#line 2031 "lexer/theme-parser.c"
    break;

  case 48:
#line 633 "../lexer/theme-parser.y"
                         {
        ((*yyvalp).property) = rofi_theme_property_create ( P_ORIENTATION );
        ((*yyvalp).property)->value.i = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
}
#line 2040 "lexer/theme-parser.c"
    break;

  case 49:
#line 637 "../lexer/theme-parser.y"
                    {
        ((*yyvalp).property) = rofi_theme_property_create ( P_CURSOR );
        ((*yyvalp).property)->value.i = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
}
#line 2049 "lexer/theme-parser.c"
    break;

  case 50:
#line 641 "../lexer/theme-parser.y"
                                              {
        ((*yyvalp).property) = rofi_theme_property_create ( P_IMAGE );
        ((*yyvalp).property)->value.image.type = ROFI_IMAGE_URL;
        ((*yyvalp).property)->value.image.url  = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.sval);
}
#line 2059 "lexer/theme-parser.c"
    break;

  case 51:
#line 646 "../lexer/theme-parser.y"
                                                                            {
        ((*yyvalp).property) = rofi_theme_property_create ( P_IMAGE );
        ((*yyvalp).property)->value.image.type    = ROFI_IMAGE_URL;
        ((*yyvalp).property)->value.image.url     = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.sval);
        ((*yyvalp).property)->value.image.scaling = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.ival);
}
#line 2070 "lexer/theme-parser.c"
    break;

  case 52:
#line 652 "../lexer/theme-parser.y"
                                                              {
        ((*yyvalp).property) = rofi_theme_property_create ( P_IMAGE );
        ((*yyvalp).property)->value.image.type   = ROFI_IMAGE_LINEAR_GRADIENT;
        ((*yyvalp).property)->value.image.dir    = ROFI_DIRECTION_RIGHT;
        ((*yyvalp).property)->value.image.colors = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.list);
}
#line 2081 "lexer/theme-parser.c"
    break;

  case 53:
#line 658 "../lexer/theme-parser.y"
                                                                                                {
        ((*yyvalp).property) = rofi_theme_property_create ( P_IMAGE );
        ((*yyvalp).property)->value.image.type   = ROFI_IMAGE_LINEAR_GRADIENT;
        ((*yyvalp).property)->value.image.dir    = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.ival);
        ((*yyvalp).property)->value.image.colors = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.list);
}
#line 2092 "lexer/theme-parser.c"
    break;

  case 54:
#line 664 "../lexer/theme-parser.y"
                                                                                                   {
        ((*yyvalp).property) = rofi_theme_property_create ( P_IMAGE );
        ((*yyvalp).property)->value.image.type   = ROFI_IMAGE_LINEAR_GRADIENT;
        ((*yyvalp).property)->value.image.dir    = ROFI_DIRECTION_ANGLE;
        ((*yyvalp).property)->value.image.angle  = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval);
        ((*yyvalp).property)->value.image.colors = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.list);
}
#line 2104 "lexer/theme-parser.c"
    break;

  case 55:
#line 675 "../lexer/theme-parser.y"
            { ((*yyvalp).ival) = ROFI_DIRECTION_RIGHT; }
#line 2110 "lexer/theme-parser.c"
    break;

  case 56:
#line 676 "../lexer/theme-parser.y"
            { ((*yyvalp).ival) = ROFI_DIRECTION_LEFT; }
#line 2116 "lexer/theme-parser.c"
    break;

  case 57:
#line 677 "../lexer/theme-parser.y"
            { ((*yyvalp).ival) = ROFI_DIRECTION_TOP; }
#line 2122 "lexer/theme-parser.c"
    break;

  case 58:
#line 678 "../lexer/theme-parser.y"
            { ((*yyvalp).ival) = ROFI_DIRECTION_BOTTOM; }
#line 2128 "lexer/theme-parser.c"
    break;

  case 59:
#line 681 "../lexer/theme-parser.y"
            { ((*yyvalp).ival) = ROFI_SCALE_BOTH; }
#line 2134 "lexer/theme-parser.c"
    break;

  case 60:
#line 682 "../lexer/theme-parser.y"
            { ((*yyvalp).ival) = ROFI_SCALE_WIDTH; }
#line 2140 "lexer/theme-parser.c"
    break;

  case 61:
#line 683 "../lexer/theme-parser.y"
            { ((*yyvalp).ival) = ROFI_SCALE_HEIGHT; }
#line 2146 "lexer/theme-parser.c"
    break;

  case 62:
#line 684 "../lexer/theme-parser.y"
            { ((*yyvalp).ival) = ROFI_SCALE_NONE; }
#line 2152 "lexer/theme-parser.c"
    break;

  case 63:
#line 688 "../lexer/theme-parser.y"
                   {
    ((*yyvalp).list) = g_list_append ( NULL, g_memdup ( (gconstpointer)&((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.colorval)), sizeof ( ThemeColor )));
}
#line 2160 "lexer/theme-parser.c"
    break;

  case 64:
#line 691 "../lexer/theme-parser.y"
                                        {

    ((*yyvalp).list) = g_list_append ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.list), g_memdup ( (gconstpointer)&((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.colorval)), sizeof ( ThemeColor )));
}
#line 2169 "lexer/theme-parser.c"
    break;

  case 65:
#line 700 "../lexer/theme-parser.y"
         { ((*yyvalp).list) = NULL; }
#line 2175 "lexer/theme-parser.c"
    break;

  case 66:
#line 701 "../lexer/theme-parser.y"
                          { ((*yyvalp).list) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.list); }
#line 2181 "lexer/theme-parser.c"
    break;

  case 67:
#line 705 "../lexer/theme-parser.y"
                     { ((*yyvalp).list) = g_list_append ( NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property)); }
#line 2187 "lexer/theme-parser.c"
    break;

  case 68:
#line 706 "../lexer/theme-parser.y"
            {
  Property *p = rofi_theme_property_create ( P_STRING );
  p->value.s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval);
  ((*yyvalp).list) = g_list_append ( NULL, p);
}
#line 2197 "lexer/theme-parser.c"
    break;

  case 69:
#line 711 "../lexer/theme-parser.y"
         {
  Property *p = rofi_theme_property_create ( P_STRING );
  p->value.s = g_strdup("calc");
  ((*yyvalp).list) = g_list_append ( NULL, p);
}
#line 2207 "lexer/theme-parser.c"
    break;

  case 70:
#line 716 "../lexer/theme-parser.y"
                                                     {
    ((*yyvalp).list) = g_list_append ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.list), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.property) );
}
#line 2215 "lexer/theme-parser.c"
    break;

  case 71:
#line 719 "../lexer/theme-parser.y"
                                            {
  Property *p = rofi_theme_property_create ( P_STRING );
  p->value.s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval);
  ((*yyvalp).list) = g_list_append ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.list), p);
}
#line 2225 "lexer/theme-parser.c"
    break;

  case 72:
#line 724 "../lexer/theme-parser.y"
                                         {
  Property *p = rofi_theme_property_create ( P_STRING );
  p->value.s = g_strdup("calc");
  ((*yyvalp).list) = g_list_append ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.list), p);
}
#line 2235 "lexer/theme-parser.c"
    break;

  case 73:
#line 737 "../lexer/theme-parser.y"
               { ((*yyvalp).wloc) =WL_CENTER;}
#line 2241 "lexer/theme-parser.c"
    break;

  case 76:
#line 740 "../lexer/theme-parser.y"
                                                { ((*yyvalp).wloc) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.wloc)|(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.wloc);}
#line 2247 "lexer/theme-parser.c"
    break;

  case 77:
#line 741 "../lexer/theme-parser.y"
                                                { ((*yyvalp).wloc) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.wloc)|(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.wloc);}
#line 2253 "lexer/theme-parser.c"
    break;

  case 78:
#line 744 "../lexer/theme-parser.y"
               { ((*yyvalp).wloc) = WL_EAST;}
#line 2259 "lexer/theme-parser.c"
    break;

  case 79:
#line 745 "../lexer/theme-parser.y"
               { ((*yyvalp).wloc) = WL_WEST;}
#line 2265 "lexer/theme-parser.c"
    break;

  case 80:
#line 748 "../lexer/theme-parser.y"
               { ((*yyvalp).wloc) = WL_NORTH;}
#line 2271 "lexer/theme-parser.c"
    break;

  case 81:
#line 749 "../lexer/theme-parser.y"
               { ((*yyvalp).wloc) = WL_SOUTH;}
#line 2277 "lexer/theme-parser.c"
    break;

  case 82:
#line 757 "../lexer/theme-parser.y"
                             { ((*yyvalp).ival) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);}
#line 2283 "lexer/theme-parser.c"
    break;

  case 83:
#line 758 "../lexer/theme-parser.y"
                                                         { ((*yyvalp).ival) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.ival)|(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);}
#line 2289 "lexer/theme-parser.c"
    break;

  case 84:
#line 762 "../lexer/theme-parser.y"
                  { ((*yyvalp).ival) = ROFI_HL_NONE; }
#line 2295 "lexer/theme-parser.c"
    break;

  case 85:
#line 763 "../lexer/theme-parser.y"
                  { ((*yyvalp).ival) = ROFI_HL_BOLD; }
#line 2301 "lexer/theme-parser.c"
    break;

  case 86:
#line 764 "../lexer/theme-parser.y"
                  { ((*yyvalp).ival) = ROFI_HL_UNDERLINE; }
#line 2307 "lexer/theme-parser.c"
    break;

  case 87:
#line 765 "../lexer/theme-parser.y"
                  { ((*yyvalp).ival) = ROFI_HL_STRIKETHROUGH; }
#line 2313 "lexer/theme-parser.c"
    break;

  case 88:
#line 766 "../lexer/theme-parser.y"
                  { ((*yyvalp).ival) = ROFI_HL_ITALIC; }
#line 2319 "lexer/theme-parser.c"
    break;

  case 89:
#line 767 "../lexer/theme-parser.y"
                  { ((*yyvalp).ival) = ROFI_HL_UPPERCASE; }
#line 2325 "lexer/theme-parser.c"
    break;

  case 90:
#line 768 "../lexer/theme-parser.y"
                  { ((*yyvalp).ival) = ROFI_HL_LOWERCASE; }
#line 2331 "lexer/theme-parser.c"
    break;

  case 91:
#line 769 "../lexer/theme-parser.y"
                  { ((*yyvalp).ival) = ROFI_HL_CAPITALIZE; }
#line 2337 "lexer/theme-parser.c"
    break;

  case 92:
#line 774 "../lexer/theme-parser.y"
                              {
    ((*yyvalp).distance).base.distance = (double) (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance).base.type     = ROFI_PU_PX;
    ((*yyvalp).distance).base.left     = NULL;
    ((*yyvalp).distance).base.right    = NULL;
    ((*yyvalp).distance).base.modtype  = ROFI_DISTANCE_MODIFIER_NONE;
    ((*yyvalp).distance).style         = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
}
#line 2350 "lexer/theme-parser.c"
    break;

  case 93:
#line 782 "../lexer/theme-parser.y"
                      { ((*yyvalp).distance) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance);}
#line 2356 "lexer/theme-parser.c"
    break;

  case 94:
#line 787 "../lexer/theme-parser.y"
                        {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->distance = (double)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance_unit)->type     = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance_unit)->left     = NULL;
    ((*yyvalp).distance_unit)->right    = NULL;
    ((*yyvalp).distance_unit)->modtype  = ROFI_DISTANCE_MODIFIER_NONE;
}
#line 2369 "lexer/theme-parser.c"
    break;

  case 95:
#line 795 "../lexer/theme-parser.y"
        {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->distance = (double)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance_unit)->type     = ROFI_PU_PX;
    ((*yyvalp).distance_unit)->left     = NULL;
    ((*yyvalp).distance_unit)->right    = NULL;
    ((*yyvalp).distance_unit)->modtype  = ROFI_DISTANCE_MODIFIER_NONE;
}
#line 2382 "lexer/theme-parser.c"
    break;

  case 96:
#line 803 "../lexer/theme-parser.y"
                           {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->distance = (double)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).distance_unit)->type     = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance_unit)->left     = NULL;
    ((*yyvalp).distance_unit)->right    = NULL;
    ((*yyvalp).distance_unit)->modtype  = ROFI_DISTANCE_MODIFIER_NONE;
}
#line 2395 "lexer/theme-parser.c"
    break;

  case 97:
#line 811 "../lexer/theme-parser.y"
                                                              {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->distance = 0;
    ((*yyvalp).distance_unit)->type     = ROFI_PU_PX;
    ((*yyvalp).distance_unit)->left     = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right    = 0;
    ((*yyvalp).distance_unit)->modtype  = ROFI_DISTANCE_MODIFIER_GROUP;
}
#line 2408 "lexer/theme-parser.c"
    break;

  case 98:
#line 825 "../lexer/theme-parser.y"
                                                                             {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left    = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right   = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_MULTIPLY;
}
#line 2419 "lexer/theme-parser.c"
    break;

  case 99:
#line 831 "../lexer/theme-parser.y"
                                                                         {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left    = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right   = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_DIVIDE;
}
#line 2430 "lexer/theme-parser.c"
    break;

  case 100:
#line 837 "../lexer/theme-parser.y"
                                                                   {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left    = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right   = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_MODULO;
}
#line 2441 "lexer/theme-parser.c"
    break;

  case 101:
#line 843 "../lexer/theme-parser.y"
                           {
    ((*yyvalp).distance_unit) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
}
#line 2449 "lexer/theme-parser.c"
    break;

  case 102:
#line 850 "../lexer/theme-parser.y"
                                                                              {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left    = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right   = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_ADD;
}
#line 2460 "lexer/theme-parser.c"
    break;

  case 103:
#line 856 "../lexer/theme-parser.y"
                                                                                   {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left    = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right   = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_SUBTRACT;
}
#line 2471 "lexer/theme-parser.c"
    break;

  case 104:
#line 862 "../lexer/theme-parser.y"
                                 {
    ((*yyvalp).distance_unit) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
}
#line 2479 "lexer/theme-parser.c"
    break;

  case 105:
#line 867 "../lexer/theme-parser.y"
                                                                               {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left    = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right   = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_MIN;
}
#line 2490 "lexer/theme-parser.c"
    break;

  case 106:
#line 873 "../lexer/theme-parser.y"
                                                                               {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left    = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right   = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_MAX;
}
#line 2501 "lexer/theme-parser.c"
    break;

  case 107:
#line 879 "../lexer/theme-parser.y"
                                                                                 {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left    = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right   = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_ROUND;
}
#line 2512 "lexer/theme-parser.c"
    break;

  case 108:
#line 885 "../lexer/theme-parser.y"
                                                                                 {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left    = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right   = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_FLOOR;
}
#line 2523 "lexer/theme-parser.c"
    break;

  case 109:
#line 891 "../lexer/theme-parser.y"
                                                                                {
    ((*yyvalp).distance_unit) = g_slice_new0(RofiDistanceUnit);
    ((*yyvalp).distance_unit)->left    = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->right   = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance_unit)->modtype = ROFI_DISTANCE_MODIFIER_CEIL;
}
#line 2534 "lexer/theme-parser.c"
    break;

  case 110:
#line 897 "../lexer/theme-parser.y"
                                  {
    ((*yyvalp).distance_unit) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.distance_unit);
}
#line 2542 "lexer/theme-parser.c"
    break;

  case 111:
#line 904 "../lexer/theme-parser.y"
                                              {
    ((*yyvalp).distance).base.distance = (double)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance).base.type     = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance).base.left     = NULL;
    ((*yyvalp).distance).base.right    = NULL;
    ((*yyvalp).distance).base.modtype  = ROFI_DISTANCE_MODIFIER_NONE;
    ((*yyvalp).distance).style         = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
}
#line 2555 "lexer/theme-parser.c"
    break;

  case 112:
#line 913 "../lexer/theme-parser.y"
                                                 {
    ((*yyvalp).distance).base.distance = (double)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).distance).base.type     = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.ival);
    ((*yyvalp).distance).base.modtype  = ROFI_DISTANCE_MODIFIER_NONE;
    ((*yyvalp).distance).base.left     = NULL;
    ((*yyvalp).distance).base.right    = NULL;
    ((*yyvalp).distance).style         = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
}
#line 2568 "lexer/theme-parser.c"
    break;

  case 113:
#line 921 "../lexer/theme-parser.y"
                                                                                           {
    ((*yyvalp).distance).base.distance = 0;
    ((*yyvalp).distance).base.type     = ROFI_PU_PX;
    ((*yyvalp).distance).base.left     = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.distance_unit);
    ((*yyvalp).distance).base.right    = NULL;
    ((*yyvalp).distance).base.modtype  = ROFI_DISTANCE_MODIFIER_GROUP;
    ((*yyvalp).distance).style         = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival);
}
#line 2581 "lexer/theme-parser.c"
    break;

  case 114:
#line 932 "../lexer/theme-parser.y"
                 { ((*yyvalp).ival) = ROFI_PU_PX; }
#line 2587 "lexer/theme-parser.c"
    break;

  case 115:
#line 933 "../lexer/theme-parser.y"
                 { ((*yyvalp).ival) = ROFI_PU_MM; }
#line 2593 "lexer/theme-parser.c"
    break;

  case 116:
#line 934 "../lexer/theme-parser.y"
                 { ((*yyvalp).ival) = ROFI_PU_EM; }
#line 2599 "lexer/theme-parser.c"
    break;

  case 117:
#line 935 "../lexer/theme-parser.y"
                 { ((*yyvalp).ival) = ROFI_PU_CH; }
#line 2605 "lexer/theme-parser.c"
    break;

  case 118:
#line 936 "../lexer/theme-parser.y"
                 { ((*yyvalp).ival) = ROFI_PU_PERCENT; }
#line 2611 "lexer/theme-parser.c"
    break;

  case 119:
#line 943 "../lexer/theme-parser.y"
           { ((*yyvalp).ival) = ROFI_HL_SOLID; }
#line 2617 "lexer/theme-parser.c"
    break;

  case 120:
#line 944 "../lexer/theme-parser.y"
           { ((*yyvalp).ival) = ROFI_HL_SOLID; }
#line 2623 "lexer/theme-parser.c"
    break;

  case 121:
#line 945 "../lexer/theme-parser.y"
           { ((*yyvalp).ival) = ROFI_HL_DASH;  }
#line 2629 "lexer/theme-parser.c"
    break;

  case 122:
#line 953 "../lexer/theme-parser.y"
                                                                                                          {
    if ( ! check_in_range((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.ival),0,255, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.ival),0,255, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.ival),0,255, &((*yylocp))) ) { YYABORT; }
    ((*yyvalp).colorval).alpha = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval).red   = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.ival)/255.0;
    ((*yyvalp).colorval).green = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.ival)/255.0;
    ((*yyvalp).colorval).blue  = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.ival)/255.0;
}
#line 2643 "lexer/theme-parser.c"
    break;

  case 123:
#line 963 "../lexer/theme-parser.y"
                                                                                              {
    if ( ! check_in_range((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.ival),0,255, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.ival),0,255, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.ival),0,255, &((*yylocp))) ) { YYABORT; }
    ((*yyvalp).colorval).alpha = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval).red   = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.ival)/255.0;
    ((*yyvalp).colorval).green = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.ival)/255.0;
    ((*yyvalp).colorval).blue  = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.ival)/255.0;
}
#line 2657 "lexer/theme-parser.c"
    break;

  case 124:
#line 973 "../lexer/theme-parser.y"
                                                                                                                                                                                           {
    if ( ! check_in_range((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval.fval),0,100, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.fval),0,100, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval),0,100, &((*yylocp))) ) { YYABORT; }
    ((*yyvalp).colorval).alpha = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval).red   = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-9)].yystate.yysemantics.yysval.fval)/100.0;
    ((*yyvalp).colorval).green = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.fval)/100.0;
    ((*yyvalp).colorval).blue  = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval)/100.0;
}
#line 2671 "lexer/theme-parser.c"
    break;

  case 125:
#line 983 "../lexer/theme-parser.y"
                                                                                                                                                                               {
    if ( ! check_in_range((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.fval),0,100, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.fval),0,100, &((*yylocp))) ) { YYABORT; }
    if ( ! check_in_range((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval),0,100, &((*yylocp))) ) { YYABORT; }
    ((*yyvalp).colorval).alpha = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval).red   = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.fval)/100.0;
    ((*yyvalp).colorval).green = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.fval)/100.0;
    ((*yyvalp).colorval).blue  = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval)/100.0;
}
#line 2685 "lexer/theme-parser.c"
    break;

  case 126:
#line 993 "../lexer/theme-parser.y"
                                                                                                                                                                           {
    double h = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.fval), w = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval), b = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval) = hwb_to_rgb ( h, w, b );
    ((*yyvalp).colorval).alpha = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
}
#line 2695 "lexer/theme-parser.c"
    break;

  case 127:
#line 999 "../lexer/theme-parser.y"
                                                                                                                                                              {
    double h = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval), w = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval), b = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval) = hwb_to_rgb ( h, w, b );
    ((*yyvalp).colorval).alpha = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
}
#line 2705 "lexer/theme-parser.c"
    break;

  case 128:
#line 1005 "../lexer/theme-parser.y"
                                                                                                                                                                                                               {
    ((*yyvalp).colorval).alpha = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
    double c = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval.fval), m = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.fval), y = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval), k = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval).red   = (1.0-c)*(1.0-k);
    ((*yyvalp).colorval).green = (1.0-m)*(1.0-k);
    ((*yyvalp).colorval).blue  = (1.0-y)*(1.0-k);
}
#line 2717 "lexer/theme-parser.c"
    break;

  case 129:
#line 1013 "../lexer/theme-parser.y"
                                                                                                                                                                                          {
    ((*yyvalp).colorval).alpha = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
    double c = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.fval), m = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval), y = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval), k = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval).red   = (1.0-c)*(1.0-k);
    ((*yyvalp).colorval).green = (1.0-m)*(1.0-k);
    ((*yyvalp).colorval).blue  = (1.0-y)*(1.0-k);
}
#line 2729 "lexer/theme-parser.c"
    break;

  case 130:
#line 1021 "../lexer/theme-parser.y"
                                                                                                                                                            {
    double h = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval), s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.fval), l = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval) = hsl_to_rgb ( h, s, l );
    ((*yyvalp).colorval).alpha = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
}
#line 2739 "lexer/theme-parser.c"
    break;

  case 131:
#line 1027 "../lexer/theme-parser.y"
                                                                                                                                                                           {
    double h = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.fval), s = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.fval), l = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.fval);
    ((*yyvalp).colorval) = hsl_to_rgb ( h, s, l );
    ((*yyvalp).colorval).alpha = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);
}
#line 2749 "lexer/theme-parser.c"
    break;

  case 132:
#line 1033 "../lexer/theme-parser.y"
          {
    ((*yyvalp).colorval) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.colorval);
}
#line 2757 "lexer/theme-parser.c"
    break;

  case 133:
#line 1036 "../lexer/theme-parser.y"
                      {
    ((*yyvalp).colorval).alpha = 0.0;
    ((*yyvalp).colorval).red = ((*yyvalp).colorval).green = ((*yyvalp).colorval).blue = 0.0;
}
#line 2766 "lexer/theme-parser.c"
    break;

  case 134:
#line 1040 "../lexer/theme-parser.y"
                                             {
    ((*yyvalp).colorval) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.colorval);
    ((*yyvalp).colorval).alpha  = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval);
}
#line 2775 "lexer/theme-parser.c"
    break;

  case 135:
#line 1046 "../lexer/theme-parser.y"
         { ((*yyvalp).fval) = 1.0; }
#line 2781 "lexer/theme-parser.c"
    break;

  case 136:
#line 1047 "../lexer/theme-parser.y"
                                      { ((*yyvalp).fval) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval);}
#line 2787 "lexer/theme-parser.c"
    break;

  case 137:
#line 1050 "../lexer/theme-parser.y"
         { ((*yyvalp).fval) = 1.0; }
#line 2793 "lexer/theme-parser.c"
    break;

  case 138:
#line 1051 "../lexer/theme-parser.y"
                                              { ((*yyvalp).fval) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval);}
#line 2799 "lexer/theme-parser.c"
    break;

  case 139:
#line 1054 "../lexer/theme-parser.y"
                                      { ((*yyvalp).fval) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval)/360.0;    if ( ! check_in_range ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval), 0, 360, &((*yylocp)))){YYABORT;}}
#line 2805 "lexer/theme-parser.c"
    break;

  case 140:
#line 1055 "../lexer/theme-parser.y"
                                      { ((*yyvalp).fval) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval)/360.0;    if ( ! check_in_range ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval), 0, 360, &((*yylocp)))){YYABORT;}}
#line 2811 "lexer/theme-parser.c"
    break;

  case 141:
#line 1056 "../lexer/theme-parser.y"
                                      { ((*yyvalp).fval) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval)/(2*G_PI); if ( ! check_in_range ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval), 0.0, (2*G_PI), &((*yylocp)))){YYABORT;}}
#line 2817 "lexer/theme-parser.c"
    break;

  case 142:
#line 1057 "../lexer/theme-parser.y"
                                      { ((*yyvalp).fval) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval)/400.0;    if ( ! check_in_range ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval), 0, 400, &((*yylocp)))){YYABORT;}}
#line 2823 "lexer/theme-parser.c"
    break;

  case 143:
#line 1058 "../lexer/theme-parser.y"
                                      { ((*yyvalp).fval) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval);          if ( ! check_in_range ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval), 0.0, 1.0, &((*yylocp)))){YYABORT;}}
#line 2829 "lexer/theme-parser.c"
    break;

  case 144:
#line 1062 "../lexer/theme-parser.y"
                                   { ((*yyvalp).fval) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval)/100.0; if ( !check_in_range ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.fval), 0, 100, &((*yylocp)))){YYABORT;}}
#line 2835 "lexer/theme-parser.c"
    break;

  case 145:
#line 1063 "../lexer/theme-parser.y"
                                   { ((*yyvalp).fval) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval);       if ( !check_in_range ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval), 0.0, 1.0, &((*yylocp)))){YYABORT;}}
#line 2841 "lexer/theme-parser.c"
    break;

  case 146:
#line 1067 "../lexer/theme-parser.y"
           { ((*yyvalp).fval) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.fval); }
#line 2847 "lexer/theme-parser.c"
    break;

  case 147:
#line 1068 "../lexer/theme-parser.y"
           { ((*yyvalp).fval) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.ival); }
#line 2853 "lexer/theme-parser.c"
    break;

  case 148:
#line 1072 "../lexer/theme-parser.y"
                   { ((*yyvalp).ival) = ROFI_ORIENTATION_HORIZONTAL; }
#line 2859 "lexer/theme-parser.c"
    break;

  case 149:
#line 1073 "../lexer/theme-parser.y"
                   { ((*yyvalp).ival) = ROFI_ORIENTATION_VERTICAL;   }
#line 2865 "lexer/theme-parser.c"
    break;

  case 150:
#line 1077 "../lexer/theme-parser.y"
             { ((*yyvalp).ival) = ROFI_CURSOR_DEFAULT; }
#line 2871 "lexer/theme-parser.c"
    break;

  case 151:
#line 1078 "../lexer/theme-parser.y"
             { ((*yyvalp).ival) = ROFI_CURSOR_POINTER; }
#line 2877 "lexer/theme-parser.c"
    break;

  case 152:
#line 1079 "../lexer/theme-parser.y"
             { ((*yyvalp).ival) = ROFI_CURSOR_TEXT; }
#line 2883 "lexer/theme-parser.c"
    break;

  case 153:
#line 1084 "../lexer/theme-parser.y"
              { ((*yyvalp).sval) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval); }
#line 2889 "lexer/theme-parser.c"
    break;

  case 154:
#line 1088 "../lexer/theme-parser.y"
                  { ((*yyvalp).list) = g_list_append  ( NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.list) ); }
#line 2895 "lexer/theme-parser.c"
    break;

  case 155:
#line 1089 "../lexer/theme-parser.y"
                                                       {
    ((*yyvalp).list) = g_list_append ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.list), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.list));
}
#line 2903 "lexer/theme-parser.c"
    break;

  case 156:
#line 1092 "../lexer/theme-parser.y"
                                     {
   ((*yyvalp).list) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.list);
}
#line 2911 "lexer/theme-parser.c"
    break;

  case 157:
#line 1098 "../lexer/theme-parser.y"
               { ((*yyvalp).list) = g_list_append ( NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval) );}
#line 2917 "lexer/theme-parser.c"
    break;

  case 158:
#line 1099 "../lexer/theme-parser.y"
                                          { ((*yyvalp).list) = g_list_append ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.list), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval));}
#line 2923 "lexer/theme-parser.c"
    break;

  case 159:
#line 1100 "../lexer/theme-parser.y"
                            { ((*yyvalp).list) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.list); }
#line 2929 "lexer/theme-parser.c"
    break;

  case 160:
#line 1104 "../lexer/theme-parser.y"
                { ((*yyvalp).list) = g_list_append ( NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval) );}
#line 2935 "lexer/theme-parser.c"
    break;

  case 161:
#line 1105 "../lexer/theme-parser.y"
                                              { ((*yyvalp).list) = g_list_append ( (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.list), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.sval));}
#line 2941 "lexer/theme-parser.c"
    break;


#line 2945 "lexer/theme-parser.c"

      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char *what)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (what);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys, const char *what)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
                &yys->yysemantics.yysval, &yys->yyloc, what);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yystos[yys->yylrState], YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh, what);
        }
    }
}

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yyStateNum yystate, yySymbol yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yyisDefaultedState (yystate)
      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (size_t, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (size_t, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (size_t, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, ptrdiff_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (size_t, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  ptrdiff_t yynewSize;
  ptrdiff_t yyn;
  ptrdiff_t yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (size_t, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, ptrdiff_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  ptrdiff_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, ptrdiff_t yyk, yyStateNum yylrState,
            ptrdiff_t yyposn,
            YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, ptrdiff_t yyk, yyStateNum yylrState,
                 ptrdiff_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, ptrdiff_t yyk,
                 yyRuleNum yyrule, const char *what)
{
  int yynrhs = yyrhsLength (yyrule);
  int yylow = 1;
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yystos[yyvsp[yyi - yynrhs + 1].yystate.yylrState],
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval,
                       &(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yyloc)                       , what);
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp, YYLTYPE *yylocp, const char *what)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      YY_REDUCE_PRINT ((yytrue, yyrhs, yyk, yyrule, what));
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
                           yyvalp, yylocp, what);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      if (yynrhs == 0)
        /* Set default location.  */
        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      YY_REDUCE_PRINT ((yyfalse, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule, what));
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, yylocp, what);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
             yybool yyforceEval, const char *what)
{
  ptrdiff_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yysval;
      YYLTYPE yyloc;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval, &yyloc, what);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1]));
      if (yyflag != yyok)
        return yyflag;
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval, &yyloc);
    }
  else
    {
      ptrdiff_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static ptrdiff_t
yysplitStack (yyGLRStack* yystackp, ptrdiff_t yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      ptrdiff_t state_size = sizeof yystackp->yytops.yystates[0];
      ptrdiff_t half_max_capacity = YYSIZEMAX / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (size_t, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (size_t, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp, const char *what);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp, const char *what)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp, what));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp, what));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp, YYLTYPE *yylocp, const char *what)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp, what);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys, what);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  if (yynrhs == 0)
    /* Set default location.  */
    yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    YYLTYPE yylloc_current = yylloc;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yylloc = yyopt->yyloc;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, yylocp, what);
    yychar = yychar_current;
    yylval = yylval_current;
    yylloc = yylloc_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yytokenName (yystos[yystates[yyi]->yylrState])));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yytokenName (yystos[yystates[yyi]->yylrState]),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1, YYLTYPE *yylocp, const char *what)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (yylocp, what, YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the locations for each of the YYN1 states in *YYSTACKP,
 *  ending at YYS1.  Has no effect on previously resolved states.
 *  The first semantic option of a state is always chosen.  */
static void
yyresolveLocations (yyGLRState *yys1, int yyn1,
                    yyGLRStack *yystackp, const char *what)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp, what);
      if (!yys1->yyresolved)
        {
          yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
          int yynrhs;
          yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
          YY_ASSERT (yyoption);
          yynrhs = yyrhsLength (yyoption->yyrule);
          if (0 < yynrhs)
            {
              yyGLRState *yys;
              int yyn;
              yyresolveLocations (yyoption->yystate, yynrhs,
                                  yystackp, what);
              for (yys = yyoption->yystate, yyn = yynrhs;
                   yyn > 0;
                   yys = yys->yypred, yyn -= 1)
                yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
            }
          else
            {
              /* Both yyresolveAction and yyresolveLocations traverse the GSS
                 in reverse rightmost order.  It is only necessary to invoke
                 yyresolveLocations on a subforest for which yyresolveAction
                 would have been invoked next had an ambiguity not been
                 detected.  Thus the location of the previous state (but not
                 necessarily the previous state itself) is guaranteed to be
                 resolved already.  */
              yyGLRState *yyprevious = yyoption->yystate;
              yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
            }
          YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
        }
    }
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, const char *what)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              yyresolveLocations (yys, 1, yystackp, what);
              return yyreportAmbiguity (yybest, yyp, yylocp, what);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp, what);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                YYLTYPE yydummy;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other, &yydummy, what);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yystos[yys->yylrState],
                                &yysval, yylocp, what);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp, what);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp, const char *what)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             , what));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
                   ptrdiff_t yyposn, YYLTYPE *yylocp, const char *what)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule], what);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yySymbol yytoken = yygetToken (&yychar, yystackp, what);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          while (*yyconflicts != 0)
            {
              YYRESULTTAG yyflag;
              ptrdiff_t yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts], what);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn, yylocp, what));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
              yyconflicts += 1;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction], what);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

static void
yyreportSyntaxError (yyGLRStack* yystackp, const char *what)
{
  if (yystackp->yyerrState != 0)
    return;
#if ! YYERROR_VERBOSE
  yyerror (&yylloc, what, YY_("syntax error"));
#else
  {
  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  ptrdiff_t yysize = 0;

  /* There are many possibilities here to consider:
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
      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      ptrdiff_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
      yysize = yysize0;
      yyarg[yycount++] = yytokenName (yytoken);
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for this
             state because they are default actions.  */
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
                yyarg[yycount++] = yytokenName (yyx);
                {
                  ptrdiff_t yysz = yytnamerr (YY_NULLPTR, yytokenName (yyx));
                  if (YYSIZEMAX - yysize < yysz)
                    yysize_overflow = yytrue;
                  else
                    yysize += yysz;
                }
              }
        }
    }

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    ptrdiff_t yysz = YY_CAST (ptrdiff_t, strlen (yyformat)) - 2 * yycount + 1;
    if (YYSIZEMAX - yysize < yysz)
      yysize_overflow = yytrue;
    else
      yysize += yysz;
  }

  if (!yysize_overflow)
    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (size_t, yysize)));

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yyarg[yyi++]);
              yyformat += 2;
            }
          else
            {
              ++yyp;
              ++yyformat;
            }
        }
      yyerror (&yylloc, what, yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (&yylloc, what, YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
#endif /* YYERROR_VERBOSE */
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp, const char *what)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yySymbol yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, &yylloc, what, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            /* We throw away the lookahead, but the error range
               of the shifted error token must take it into account.  */
            yyGLRState *yys = yystackp->yytops.yystates[0];
            yyGLRStackItem yyerror_range[3];
            yyerror_range[1].yystate.yyloc = yys->yyloc;
            yyerror_range[2].yystate.yyloc = yylloc;
            YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval, &yylloc, what);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar, yystackp, what);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    ptrdiff_t yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, &yylloc, what, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYTERROR;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              /* First adjust its location.*/
              YYLTYPE yyerrloc;
              yystackp->yyerror_range[2].yystate.yyloc = yylloc;
              YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);
              YY_SYMBOL_PRINT ("Shifting", yystos[yyaction],
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval, &yyerrloc);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys, what);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, &yylloc, what, YY_NULLPTR);
}

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char *what)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  ptrdiff_t yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;
  yylloc = yyloc_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode */
      while (yytrue)
        {
          yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack, what);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue, what));
            }
          else
            {
              yySymbol yytoken = yygetToken (&yychar, yystackp, what);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts != 0)
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;                  yyreportSyntaxError (&yystack, what);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue, what));
            }
        }

      while (yytrue)
        {
          yySymbol yytoken_to_shift;
          ptrdiff_t yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn, &yylloc, what));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, &yylloc, what, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack, what));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yystack.yyerror_range[1].yystate.yyloc = yylloc;
              yyreportSyntaxError (&yystack, what);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval, &yylloc);
              YY_DPRINTF ((stderr, "Stack %ld now in state #%d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack, what));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack, what);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (&yylloc, what, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, &yylloc, what);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          ptrdiff_t yysize = yystack.yytops.yysize;
          ptrdiff_t yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys, what);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yyst);
  YY_FPRINTF ((stderr, "\n"));
}

static void
yypstack (yyGLRStack* yystackp, ptrdiff_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    ptrdiff_t yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs
#undef yylloc



#line 1109 "../lexer/theme-parser.y"


