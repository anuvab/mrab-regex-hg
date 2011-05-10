/*
 * Secret Labs' Regular Expression Engine
 *
 * regular expression matching engine
 *
 * Copyright (c) 1997-2001 by Secret Labs AB.  All rights reserved.
 *
 * NOTE: This file is generated by regex.py.  If you need
 * to change anything in here, edit regex.py and run it.
 *
 * 2010-01-16 mrab Re-written
 */

/* Supports Unicode version 6.0.0. */

#define RE_MAGIC 20100116

#include "_regex_unicode.h"

/* Operators. */
#define RE_OP_FAILURE 0
#define RE_OP_SUCCESS 1
#define RE_OP_ANY 2
#define RE_OP_ANY_ALL 3
#define RE_OP_ANY_ALL_REV 4
#define RE_OP_ANY_REV 5
#define RE_OP_ANY_U 6
#define RE_OP_ANY_U_REV 7
#define RE_OP_ATOMIC 8
#define RE_OP_BIG_BITSET 9
#define RE_OP_BIG_BITSET_REV 10
#define RE_OP_BOUNDARY 11
#define RE_OP_BRANCH 12
#define RE_OP_CHARACTER 13
#define RE_OP_CHARACTER_IGN 14
#define RE_OP_CHARACTER_IGN_REV 15
#define RE_OP_CHARACTER_REV 16
#define RE_OP_DEFAULT_BOUNDARY 17
#define RE_OP_END 18
#define RE_OP_END_GREEDY_REPEAT 19
#define RE_OP_END_GROUP 20
#define RE_OP_END_LAZY_REPEAT 21
#define RE_OP_END_OF_LINE 22
#define RE_OP_END_OF_LINE_U 23
#define RE_OP_END_OF_STRING 24
#define RE_OP_END_OF_STRING_LINE 25
#define RE_OP_END_OF_STRING_LINE_U 26
#define RE_OP_GRAPHEME_BOUNDARY 27
#define RE_OP_GREEDY_REPEAT 28
#define RE_OP_GREEDY_REPEAT_ONE 29
#define RE_OP_GROUP 30
#define RE_OP_GROUP_EXISTS 31
#define RE_OP_LAZY_REPEAT 32
#define RE_OP_LAZY_REPEAT_ONE 33
#define RE_OP_LOOKAROUND 34
#define RE_OP_NEXT 35
#define RE_OP_PROPERTY 36
#define RE_OP_PROPERTY_REV 37
#define RE_OP_REF_GROUP 38
#define RE_OP_REF_GROUP_IGN 39
#define RE_OP_REF_GROUP_IGN_REV 40
#define RE_OP_REF_GROUP_REV 41
#define RE_OP_SEARCH_ANCHOR 42
#define RE_OP_SET_DIFF 43
#define RE_OP_SET_DIFF_REV 44
#define RE_OP_SET_INTER 45
#define RE_OP_SET_INTER_REV 46
#define RE_OP_SET_SYM_DIFF 47
#define RE_OP_SET_SYM_DIFF_REV 48
#define RE_OP_SET_UNION 49
#define RE_OP_SET_UNION_REV 50
#define RE_OP_SMALL_BITSET 51
#define RE_OP_SMALL_BITSET_REV 52
#define RE_OP_START_GROUP 53
#define RE_OP_START_OF_LINE 54
#define RE_OP_START_OF_LINE_U 55
#define RE_OP_START_OF_STRING 56
#define RE_OP_STRING 57
#define RE_OP_STRING_IGN 58
#define RE_OP_STRING_IGN_REV 59
#define RE_OP_STRING_REV 60

char* re_op_text[] = {
    "RE_OP_FAILURE",
    "RE_OP_SUCCESS",
    "RE_OP_ANY",
    "RE_OP_ANY_ALL",
    "RE_OP_ANY_ALL_REV",
    "RE_OP_ANY_REV",
    "RE_OP_ANY_U",
    "RE_OP_ANY_U_REV",
    "RE_OP_ATOMIC",
    "RE_OP_BIG_BITSET",
    "RE_OP_BIG_BITSET_REV",
    "RE_OP_BOUNDARY",
    "RE_OP_BRANCH",
    "RE_OP_CHARACTER",
    "RE_OP_CHARACTER_IGN",
    "RE_OP_CHARACTER_IGN_REV",
    "RE_OP_CHARACTER_REV",
    "RE_OP_DEFAULT_BOUNDARY",
    "RE_OP_END",
    "RE_OP_END_GREEDY_REPEAT",
    "RE_OP_END_GROUP",
    "RE_OP_END_LAZY_REPEAT",
    "RE_OP_END_OF_LINE",
    "RE_OP_END_OF_LINE_U",
    "RE_OP_END_OF_STRING",
    "RE_OP_END_OF_STRING_LINE",
    "RE_OP_END_OF_STRING_LINE_U",
    "RE_OP_GRAPHEME_BOUNDARY",
    "RE_OP_GREEDY_REPEAT",
    "RE_OP_GREEDY_REPEAT_ONE",
    "RE_OP_GROUP",
    "RE_OP_GROUP_EXISTS",
    "RE_OP_LAZY_REPEAT",
    "RE_OP_LAZY_REPEAT_ONE",
    "RE_OP_LOOKAROUND",
    "RE_OP_NEXT",
    "RE_OP_PROPERTY",
    "RE_OP_PROPERTY_REV",
    "RE_OP_REF_GROUP",
    "RE_OP_REF_GROUP_IGN",
    "RE_OP_REF_GROUP_IGN_REV",
    "RE_OP_REF_GROUP_REV",
    "RE_OP_SEARCH_ANCHOR",
    "RE_OP_SET_DIFF",
    "RE_OP_SET_DIFF_REV",
    "RE_OP_SET_INTER",
    "RE_OP_SET_INTER_REV",
    "RE_OP_SET_SYM_DIFF",
    "RE_OP_SET_SYM_DIFF_REV",
    "RE_OP_SET_UNION",
    "RE_OP_SET_UNION_REV",
    "RE_OP_SMALL_BITSET",
    "RE_OP_SMALL_BITSET_REV",
    "RE_OP_START_GROUP",
    "RE_OP_START_OF_LINE",
    "RE_OP_START_OF_LINE_U",
    "RE_OP_START_OF_STRING",
    "RE_OP_STRING",
    "RE_OP_STRING_IGN",
    "RE_OP_STRING_IGN_REV",
    "RE_OP_STRING_REV",
};

#define RE_FLAG_ASCII 0x80
#define RE_FLAG_DEBUG 0x200
#define RE_FLAG_DOTALL 0x10
#define RE_FLAG_IGNORECASE 0x2
#define RE_FLAG_LOCALE 0x4
#define RE_FLAG_MULTILINE 0x8
#define RE_FLAG_NEW 0x100
#define RE_FLAG_REVERSE 0x400
#define RE_FLAG_TEMPLATE 0x1
#define RE_FLAG_UNICODE 0x20
#define RE_FLAG_VERBOSE 0x40
#define RE_FLAG_WORD 0x800
