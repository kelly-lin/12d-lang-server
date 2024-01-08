// Vendored commit cbc4e2f5151ff6d7e022a3c56dfb3adcebaf8c88
#include "parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 172
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 108
#define ALIAS_COUNT 1
#define TOKEN_COUNT 62
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 21
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 28

enum {
  sym_identifier = 1,
  anon_sym_LBRACE = 2,
  anon_sym_RBRACE = 3,
  anon_sym_while = 4,
  anon_sym_LPAREN = 5,
  anon_sym_COMMA = 6,
  anon_sym_RPAREN = 7,
  anon_sym_AMP = 8,
  anon_sym_case = 9,
  anon_sym_default = 10,
  anon_sym_COLON = 11,
  anon_sym_break = 12,
  anon_sym_SEMI = 13,
  anon_sym_continue = 14,
  anon_sym_goto = 15,
  anon_sym_switch = 16,
  anon_sym_if = 17,
  anon_sym_else = 18,
  anon_sym_for = 19,
  anon_sym_BANG = 20,
  anon_sym_DASH = 21,
  anon_sym_PLUS = 22,
  anon_sym_STAR = 23,
  anon_sym_SLASH = 24,
  anon_sym_PERCENT = 25,
  anon_sym_PIPE_PIPE = 26,
  anon_sym_AMP_AMP = 27,
  anon_sym_PIPE = 28,
  anon_sym_CARET = 29,
  anon_sym_EQ_EQ = 30,
  anon_sym_BANG_EQ = 31,
  anon_sym_GT = 32,
  anon_sym_GT_EQ = 33,
  anon_sym_LT_EQ = 34,
  anon_sym_LT = 35,
  anon_sym_LT_LT = 36,
  anon_sym_GT_GT = 37,
  anon_sym_EQ = 38,
  anon_sym_STAR_EQ = 39,
  anon_sym_SLASH_EQ = 40,
  anon_sym_PERCENT_EQ = 41,
  anon_sym_PLUS_EQ = 42,
  anon_sym_DASH_EQ = 43,
  anon_sym_AMP_EQ = 44,
  anon_sym_CARET_EQ = 45,
  anon_sym_PIPE_EQ = 46,
  anon_sym_LBRACK = 47,
  anon_sym_RBRACK = 48,
  anon_sym_DASH_DASH = 49,
  anon_sym_PLUS_PLUS = 50,
  anon_sym_return = 51,
  sym_number_literal = 52,
  anon_sym_DQUOTE = 53,
  aux_sym_string_literal_token1 = 54,
  sym_system_lib_string = 55,
  sym_escape_sequence = 56,
  aux_sym_preproc_include_token1 = 57,
  anon_sym_LF = 58,
  aux_sym_preproc_def_token1 = 59,
  sym_primitive_type = 60,
  sym_comment = 61,
  sym_source_file = 62,
  sym_function_definition = 63,
  sym_compound_statement = 64,
  sym_while_statement = 65,
  sym_parameter_list = 66,
  sym_parameter_declaration = 67,
  sym_pointer_declarator = 68,
  sym__declaration_specifiers = 69,
  sym__type_specifier = 70,
  sym_case_statement = 71,
  sym_break_statement = 72,
  sym_labeled_statement = 73,
  sym_continue_statement = 74,
  sym_goto_statement = 75,
  sym_switch_statement = 76,
  sym_if_statement = 77,
  sym_for_statement = 78,
  sym_unary_expression = 79,
  sym_expression_statement = 80,
  sym_comma_expression = 81,
  sym_call_expression = 82,
  sym_argument_list = 83,
  sym_binary_expression = 84,
  sym_assignment_expression = 85,
  sym_subscript_expression = 86,
  sym_update_expression = 87,
  sym_parenthesized_expression = 88,
  sym_return_statement = 89,
  sym__expression = 90,
  sym__statement_identifier = 91,
  sym_string_literal = 92,
  sym_declaration = 93,
  sym_init_declarator = 94,
  sym_array_declarator = 95,
  sym_function_declarator = 96,
  sym__declarator = 97,
  sym_preproc_include = 98,
  sym_preproc_def = 99,
  sym_preproc_arg = 100,
  aux_sym_source_file_repeat1 = 101,
  aux_sym_compound_statement_repeat1 = 102,
  aux_sym_parameter_list_repeat1 = 103,
  aux_sym_case_statement_repeat1 = 104,
  aux_sym_argument_list_repeat1 = 105,
  aux_sym_string_literal_repeat1 = 106,
  aux_sym_declaration_repeat1 = 107,
  alias_sym_statement_identifier = 108,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_while] = "while",
  [anon_sym_LPAREN] = "(",
  [anon_sym_COMMA] = ",",
  [anon_sym_RPAREN] = ")",
  [anon_sym_AMP] = "&",
  [anon_sym_case] = "case",
  [anon_sym_default] = "default",
  [anon_sym_COLON] = ":",
  [anon_sym_break] = "break",
  [anon_sym_SEMI] = ";",
  [anon_sym_continue] = "continue",
  [anon_sym_goto] = "goto",
  [anon_sym_switch] = "switch",
  [anon_sym_if] = "if",
  [anon_sym_else] = "else",
  [anon_sym_for] = "for",
  [anon_sym_BANG] = "!",
  [anon_sym_DASH] = "-",
  [anon_sym_PLUS] = "+",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_PIPE_PIPE] = "||",
  [anon_sym_AMP_AMP] = "&&",
  [anon_sym_PIPE] = "|",
  [anon_sym_CARET] = "^",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_GT] = ">",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_LT] = "<",
  [anon_sym_LT_LT] = "<<",
  [anon_sym_GT_GT] = ">>",
  [anon_sym_EQ] = "=",
  [anon_sym_STAR_EQ] = "*=",
  [anon_sym_SLASH_EQ] = "/=",
  [anon_sym_PERCENT_EQ] = "%=",
  [anon_sym_PLUS_EQ] = "+=",
  [anon_sym_DASH_EQ] = "-=",
  [anon_sym_AMP_EQ] = "&=",
  [anon_sym_CARET_EQ] = "^=",
  [anon_sym_PIPE_EQ] = "|=",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_DASH_DASH] = "--",
  [anon_sym_PLUS_PLUS] = "++",
  [anon_sym_return] = "return",
  [sym_number_literal] = "number_literal",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_literal_token1] = "string_content",
  [sym_system_lib_string] = "system_lib_string",
  [sym_escape_sequence] = "escape_sequence",
  [aux_sym_preproc_include_token1] = "#include",
  [anon_sym_LF] = "\n",
  [aux_sym_preproc_def_token1] = "#define",
  [sym_primitive_type] = "primitive_type",
  [sym_comment] = "comment",
  [sym_source_file] = "source_file",
  [sym_function_definition] = "function_definition",
  [sym_compound_statement] = "compound_statement",
  [sym_while_statement] = "while_statement",
  [sym_parameter_list] = "parameter_list",
  [sym_parameter_declaration] = "parameter_declaration",
  [sym_pointer_declarator] = "pointer_declarator",
  [sym__declaration_specifiers] = "_declaration_specifiers",
  [sym__type_specifier] = "_type_specifier",
  [sym_case_statement] = "case_statement",
  [sym_break_statement] = "break_statement",
  [sym_labeled_statement] = "labeled_statement",
  [sym_continue_statement] = "continue_statement",
  [sym_goto_statement] = "goto_statement",
  [sym_switch_statement] = "switch_statement",
  [sym_if_statement] = "if_statement",
  [sym_for_statement] = "for_statement",
  [sym_unary_expression] = "unary_expression",
  [sym_expression_statement] = "expression_statement",
  [sym_comma_expression] = "comma_expression",
  [sym_call_expression] = "call_expression",
  [sym_argument_list] = "argument_list",
  [sym_binary_expression] = "binary_expression",
  [sym_assignment_expression] = "assignment_expression",
  [sym_subscript_expression] = "subscript_expression",
  [sym_update_expression] = "update_expression",
  [sym_parenthesized_expression] = "parenthesized_expression",
  [sym_return_statement] = "return_statement",
  [sym__expression] = "_expression",
  [sym__statement_identifier] = "_statement_identifier",
  [sym_string_literal] = "string_literal",
  [sym_declaration] = "declaration",
  [sym_init_declarator] = "init_declarator",
  [sym_array_declarator] = "array_declarator",
  [sym_function_declarator] = "function_declarator",
  [sym__declarator] = "_declarator",
  [sym_preproc_include] = "preproc_include",
  [sym_preproc_def] = "preproc_def",
  [sym_preproc_arg] = "preproc_arg",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_compound_statement_repeat1] = "compound_statement_repeat1",
  [aux_sym_parameter_list_repeat1] = "parameter_list_repeat1",
  [aux_sym_case_statement_repeat1] = "case_statement_repeat1",
  [aux_sym_argument_list_repeat1] = "argument_list_repeat1",
  [aux_sym_string_literal_repeat1] = "string_literal_repeat1",
  [aux_sym_declaration_repeat1] = "declaration_repeat1",
  [alias_sym_statement_identifier] = "statement_identifier",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_case] = anon_sym_case,
  [anon_sym_default] = anon_sym_default,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_break] = anon_sym_break,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_continue] = anon_sym_continue,
  [anon_sym_goto] = anon_sym_goto,
  [anon_sym_switch] = anon_sym_switch,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_for] = anon_sym_for,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_PIPE_PIPE] = anon_sym_PIPE_PIPE,
  [anon_sym_AMP_AMP] = anon_sym_AMP_AMP,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LT_LT] = anon_sym_LT_LT,
  [anon_sym_GT_GT] = anon_sym_GT_GT,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_STAR_EQ] = anon_sym_STAR_EQ,
  [anon_sym_SLASH_EQ] = anon_sym_SLASH_EQ,
  [anon_sym_PERCENT_EQ] = anon_sym_PERCENT_EQ,
  [anon_sym_PLUS_EQ] = anon_sym_PLUS_EQ,
  [anon_sym_DASH_EQ] = anon_sym_DASH_EQ,
  [anon_sym_AMP_EQ] = anon_sym_AMP_EQ,
  [anon_sym_CARET_EQ] = anon_sym_CARET_EQ,
  [anon_sym_PIPE_EQ] = anon_sym_PIPE_EQ,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_DASH_DASH] = anon_sym_DASH_DASH,
  [anon_sym_PLUS_PLUS] = anon_sym_PLUS_PLUS,
  [anon_sym_return] = anon_sym_return,
  [sym_number_literal] = sym_number_literal,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_literal_token1] = aux_sym_string_literal_token1,
  [sym_system_lib_string] = sym_system_lib_string,
  [sym_escape_sequence] = sym_escape_sequence,
  [aux_sym_preproc_include_token1] = aux_sym_preproc_include_token1,
  [anon_sym_LF] = anon_sym_LF,
  [aux_sym_preproc_def_token1] = aux_sym_preproc_def_token1,
  [sym_primitive_type] = sym_primitive_type,
  [sym_comment] = sym_comment,
  [sym_source_file] = sym_source_file,
  [sym_function_definition] = sym_function_definition,
  [sym_compound_statement] = sym_compound_statement,
  [sym_while_statement] = sym_while_statement,
  [sym_parameter_list] = sym_parameter_list,
  [sym_parameter_declaration] = sym_parameter_declaration,
  [sym_pointer_declarator] = sym_pointer_declarator,
  [sym__declaration_specifiers] = sym__declaration_specifiers,
  [sym__type_specifier] = sym__type_specifier,
  [sym_case_statement] = sym_case_statement,
  [sym_break_statement] = sym_break_statement,
  [sym_labeled_statement] = sym_labeled_statement,
  [sym_continue_statement] = sym_continue_statement,
  [sym_goto_statement] = sym_goto_statement,
  [sym_switch_statement] = sym_switch_statement,
  [sym_if_statement] = sym_if_statement,
  [sym_for_statement] = sym_for_statement,
  [sym_unary_expression] = sym_unary_expression,
  [sym_expression_statement] = sym_expression_statement,
  [sym_comma_expression] = sym_comma_expression,
  [sym_call_expression] = sym_call_expression,
  [sym_argument_list] = sym_argument_list,
  [sym_binary_expression] = sym_binary_expression,
  [sym_assignment_expression] = sym_assignment_expression,
  [sym_subscript_expression] = sym_subscript_expression,
  [sym_update_expression] = sym_update_expression,
  [sym_parenthesized_expression] = sym_parenthesized_expression,
  [sym_return_statement] = sym_return_statement,
  [sym__expression] = sym__expression,
  [sym__statement_identifier] = sym__statement_identifier,
  [sym_string_literal] = sym_string_literal,
  [sym_declaration] = sym_declaration,
  [sym_init_declarator] = sym_init_declarator,
  [sym_array_declarator] = sym_array_declarator,
  [sym_function_declarator] = sym_function_declarator,
  [sym__declarator] = sym__declarator,
  [sym_preproc_include] = sym_preproc_include,
  [sym_preproc_def] = sym_preproc_def,
  [sym_preproc_arg] = sym_preproc_arg,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_compound_statement_repeat1] = aux_sym_compound_statement_repeat1,
  [aux_sym_parameter_list_repeat1] = aux_sym_parameter_list_repeat1,
  [aux_sym_case_statement_repeat1] = aux_sym_case_statement_repeat1,
  [aux_sym_argument_list_repeat1] = aux_sym_argument_list_repeat1,
  [aux_sym_string_literal_repeat1] = aux_sym_string_literal_repeat1,
  [aux_sym_declaration_repeat1] = aux_sym_declaration_repeat1,
  [alias_sym_statement_identifier] = alias_sym_statement_identifier,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_while] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_case] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_default] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_break] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_continue] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_goto] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_switch] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_for] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [sym_number_literal] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_literal_token1] = {
    .visible = true,
    .named = true,
  },
  [sym_system_lib_string] = {
    .visible = true,
    .named = true,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_preproc_include_token1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_preproc_def_token1] = {
    .visible = true,
    .named = false,
  },
  [sym_primitive_type] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_function_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_compound_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_while_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter_list] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_pointer_declarator] = {
    .visible = true,
    .named = true,
  },
  [sym__declaration_specifiers] = {
    .visible = false,
    .named = true,
  },
  [sym__type_specifier] = {
    .visible = false,
    .named = true,
    .supertype = true,
  },
  [sym_case_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_break_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_labeled_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_continue_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_goto_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_switch_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_if_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_for_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_unary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_expression_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_comma_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_call_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_argument_list] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_assignment_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_subscript_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_update_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_parenthesized_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_return_statement] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
    .supertype = true,
  },
  [sym__statement_identifier] = {
    .visible = false,
    .named = true,
  },
  [sym_string_literal] = {
    .visible = true,
    .named = true,
  },
  [sym_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_init_declarator] = {
    .visible = true,
    .named = true,
  },
  [sym_array_declarator] = {
    .visible = true,
    .named = true,
  },
  [sym_function_declarator] = {
    .visible = true,
    .named = true,
  },
  [sym__declarator] = {
    .visible = false,
    .named = true,
    .supertype = true,
  },
  [sym_preproc_include] = {
    .visible = true,
    .named = true,
  },
  [sym_preproc_def] = {
    .visible = true,
    .named = true,
  },
  [sym_preproc_arg] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_compound_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameter_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_case_statement_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_argument_list_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_literal_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_declaration_repeat1] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_statement_identifier] = {
    .visible = true,
    .named = true,
  },
};

enum {
  field_alternative = 1,
  field_argument = 2,
  field_arguments = 3,
  field_body = 4,
  field_condition = 5,
  field_consequence = 6,
  field_declarator = 7,
  field_function = 8,
  field_index = 9,
  field_initializer = 10,
  field_label = 11,
  field_left = 12,
  field_name = 13,
  field_operator = 14,
  field_parameters = 15,
  field_path = 16,
  field_right = 17,
  field_size = 18,
  field_type = 19,
  field_update = 20,
  field_value = 21,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_alternative] = "alternative",
  [field_argument] = "argument",
  [field_arguments] = "arguments",
  [field_body] = "body",
  [field_condition] = "condition",
  [field_consequence] = "consequence",
  [field_declarator] = "declarator",
  [field_function] = "function",
  [field_index] = "index",
  [field_initializer] = "initializer",
  [field_label] = "label",
  [field_left] = "left",
  [field_name] = "name",
  [field_operator] = "operator",
  [field_parameters] = "parameters",
  [field_path] = "path",
  [field_right] = "right",
  [field_size] = "size",
  [field_type] = "type",
  [field_update] = "update",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [2] = {.index = 0, .length = 1},
  [4] = {.index = 1, .length = 2},
  [5] = {.index = 3, .length = 2},
  [6] = {.index = 5, .length = 2},
  [7] = {.index = 7, .length = 1},
  [8] = {.index = 8, .length = 1},
  [9] = {.index = 9, .length = 1},
  [10] = {.index = 10, .length = 3},
  [11] = {.index = 13, .length = 2},
  [12] = {.index = 15, .length = 2},
  [13] = {.index = 17, .length = 1},
  [14] = {.index = 18, .length = 1},
  [15] = {.index = 19, .length = 2},
  [16] = {.index = 21, .length = 3},
  [17] = {.index = 24, .length = 2},
  [18] = {.index = 26, .length = 2},
  [19] = {.index = 28, .length = 2},
  [20] = {.index = 30, .length = 1},
  [21] = {.index = 31, .length = 3},
  [22] = {.index = 34, .length = 2},
  [23] = {.index = 36, .length = 2},
  [24] = {.index = 38, .length = 2},
  [25] = {.index = 40, .length = 2},
  [26] = {.index = 42, .length = 3},
  [27] = {.index = 45, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_type, 0},
  [1] =
    {field_argument, 1},
    {field_operator, 0},
  [3] =
    {field_argument, 0},
    {field_operator, 1},
  [5] =
    {field_arguments, 1},
    {field_function, 0},
  [7] =
    {field_label, 0},
  [8] =
    {field_path, 1},
  [9] =
    {field_name, 1},
  [10] =
    {field_body, 2},
    {field_declarator, 1},
    {field_type, 0, .inherited = true},
  [13] =
    {field_declarator, 0},
    {field_parameters, 1},
  [15] =
    {field_body, 2},
    {field_condition, 1},
  [17] =
    {field_value, 1},
  [18] =
    {field_label, 1},
  [19] =
    {field_condition, 1},
    {field_consequence, 2},
  [21] =
    {field_left, 0},
    {field_operator, 1},
    {field_right, 2},
  [24] =
    {field_declarator, 1},
    {field_type, 0, .inherited = true},
  [26] =
    {field_left, 0},
    {field_right, 2},
  [28] =
    {field_name, 1},
    {field_value, 2},
  [30] =
    {field_declarator, 1},
  [31] =
    {field_declarator, 1},
    {field_declarator, 2, .inherited = true},
    {field_type, 0, .inherited = true},
  [34] =
    {field_declarator, 0, .inherited = true},
    {field_declarator, 1, .inherited = true},
  [36] =
    {field_declarator, 0},
    {field_value, 2},
  [38] =
    {field_argument, 0},
    {field_index, 2},
  [40] =
    {field_declarator, 0},
    {field_size, 2},
  [42] =
    {field_alternative, 4},
    {field_condition, 1},
    {field_consequence, 2},
  [45] =
    {field_condition, 3},
    {field_initializer, 2},
    {field_update, 5},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [1] = {
    [0] = sym_primitive_type,
  },
  [3] = {
    [0] = alias_sym_statement_identifier,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 14,
  [22] = 17,
  [23] = 18,
  [24] = 24,
  [25] = 16,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 43,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 42,
  [61] = 39,
  [62] = 62,
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 80,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 90,
  [91] = 91,
  [92] = 92,
  [93] = 93,
  [94] = 94,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
  [99] = 99,
  [100] = 100,
  [101] = 101,
  [102] = 102,
  [103] = 103,
  [104] = 104,
  [105] = 105,
  [106] = 106,
  [107] = 107,
  [108] = 108,
  [109] = 109,
  [110] = 110,
  [111] = 111,
  [112] = 112,
  [113] = 113,
  [114] = 114,
  [115] = 115,
  [116] = 116,
  [117] = 117,
  [118] = 118,
  [119] = 119,
  [120] = 120,
  [121] = 121,
  [122] = 122,
  [123] = 123,
  [124] = 124,
  [125] = 125,
  [126] = 126,
  [127] = 126,
  [128] = 128,
  [129] = 128,
  [130] = 130,
  [131] = 131,
  [132] = 132,
  [133] = 133,
  [134] = 134,
  [135] = 135,
  [136] = 136,
  [137] = 137,
  [138] = 138,
  [139] = 139,
  [140] = 134,
  [141] = 141,
  [142] = 142,
  [143] = 143,
  [144] = 144,
  [145] = 145,
  [146] = 146,
  [147] = 147,
  [148] = 148,
  [149] = 149,
  [150] = 150,
  [151] = 151,
  [152] = 152,
  [153] = 153,
  [154] = 154,
  [155] = 155,
  [156] = 156,
  [157] = 157,
  [158] = 158,
  [159] = 159,
  [160] = 160,
  [161] = 161,
  [162] = 162,
  [163] = 163,
  [164] = 164,
  [165] = 165,
  [166] = 166,
  [167] = 167,
  [168] = 168,
  [169] = 169,
  [170] = 170,
  [171] = 171,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(48);
      if (lookahead == '!') ADVANCE(58);
      if (lookahead == '"') ADVANCE(511);
      if (lookahead == '#') ADVANCE(23);
      if (lookahead == '%') ADVANCE(65);
      if (lookahead == '&') ADVANCE(54);
      if (lookahead == '(') ADVANCE(51);
      if (lookahead == ')') ADVANCE(53);
      if (lookahead == '*') ADVANCE(63);
      if (lookahead == '+') ADVANCE(61);
      if (lookahead == ',') ADVANCE(52);
      if (lookahead == '-') ADVANCE(59);
      if (lookahead == '/') ADVANCE(64);
      if (lookahead == ':') ADVANCE(55);
      if (lookahead == ';') ADVANCE(56);
      if (lookahead == '<') ADVANCE(75);
      if (lookahead == '=') ADVANCE(79);
      if (lookahead == '>') ADVANCE(72);
      if (lookahead == 'A') ADVANCE(351);
      if (lookahead == 'B') ADVANCE(286);
      if (lookahead == 'C') ADVANCE(284);
      if (lookahead == 'D') ADVANCE(165);
      if (lookahead == 'E') ADVANCE(321);
      if (lookahead == 'F') ADVANCE(309);
      if (lookahead == 'G') ADVANCE(401);
      if (lookahead == 'H') ADVANCE(371);
      if (lookahead == 'I') ADVANCE(352);
      if (lookahead == 'J') ADVANCE(476);
      if (lookahead == 'L') ADVANCE(287);
      if (lookahead == 'M') ADVANCE(159);
      if (lookahead == 'N') ADVANCE(160);
      if (lookahead == 'O') ADVANCE(490);
      if (lookahead == 'P') ADVANCE(161);
      if (lookahead == 'Q') ADVANCE(485);
      if (lookahead == 'R') ADVANCE(226);
      if (lookahead == 'S') ADVANCE(101);
      if (lookahead == 'T') ADVANCE(162);
      if (lookahead == 'U') ADVANCE(291);
      if (lookahead == 'V') ADVANCE(227);
      if (lookahead == 'W') ADVANCE(299);
      if (lookahead == 'X') ADVANCE(115);
      if (lookahead == '[') ADVANCE(88);
      if (lookahead == '\\') SKIP(44)
      if (lookahead == ']') ADVANCE(89);
      if (lookahead == '^') ADVANCE(69);
      if (lookahead == 'v') ADVANCE(388);
      if (lookahead == '{') ADVANCE(49);
      if (lookahead == '|') ADVANCE(68);
      if (lookahead == '}') ADVANCE(50);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(510);
      if (('K' <= lookahead && lookahead <= '_') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(8)
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(8)
      if (lookahead == '\r') SKIP(1)
      END_STATE();
    case 3:
      if (lookahead == '\n') SKIP(5)
      END_STATE();
    case 4:
      if (lookahead == '\n') SKIP(5)
      if (lookahead == '\r') SKIP(3)
      END_STATE();
    case 5:
      if (lookahead == '\n') ADVANCE(524);
      if (lookahead == '!') ADVANCE(14);
      if (lookahead == '"') ADVANCE(511);
      if (lookahead == '%') ADVANCE(65);
      if (lookahead == '&') ADVANCE(54);
      if (lookahead == '(') ADVANCE(51);
      if (lookahead == '*') ADVANCE(63);
      if (lookahead == '+') ADVANCE(61);
      if (lookahead == '-') ADVANCE(59);
      if (lookahead == '/') ADVANCE(64);
      if (lookahead == '<') ADVANCE(75);
      if (lookahead == '=') ADVANCE(79);
      if (lookahead == '>') ADVANCE(72);
      if (lookahead == '[') ADVANCE(88);
      if (lookahead == '\\') SKIP(4)
      if (lookahead == '^') ADVANCE(69);
      if (lookahead == '|') ADVANCE(68);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(510);
      END_STATE();
    case 6:
      if (lookahead == '\n') SKIP(9)
      if (lookahead == '"') ADVANCE(511);
      if (lookahead == '/') ADVANCE(512);
      if (lookahead == '\\') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(515);
      if (lookahead != 0) ADVANCE(516);
      END_STATE();
    case 7:
      if (lookahead == '\n') ADVANCE(520);
      if (lookahead == '\r') ADVANCE(519);
      if (lookahead == 'U') ADVANCE(41);
      if (lookahead == 'u') ADVANCE(37);
      if (lookahead == 'x') ADVANCE(35);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(522);
      if (lookahead != 0) ADVANCE(519);
      END_STATE();
    case 8:
      if (lookahead == '!') ADVANCE(14);
      if (lookahead == '%') ADVANCE(65);
      if (lookahead == '&') ADVANCE(54);
      if (lookahead == '(') ADVANCE(51);
      if (lookahead == ')') ADVANCE(53);
      if (lookahead == '*') ADVANCE(63);
      if (lookahead == '+') ADVANCE(61);
      if (lookahead == ',') ADVANCE(52);
      if (lookahead == '-') ADVANCE(59);
      if (lookahead == '/') ADVANCE(64);
      if (lookahead == ':') ADVANCE(55);
      if (lookahead == ';') ADVANCE(56);
      if (lookahead == '<') ADVANCE(75);
      if (lookahead == '=') ADVANCE(79);
      if (lookahead == '>') ADVANCE(72);
      if (lookahead == '[') ADVANCE(88);
      if (lookahead == '\\') SKIP(2)
      if (lookahead == ']') ADVANCE(89);
      if (lookahead == '^') ADVANCE(69);
      if (lookahead == '|') ADVANCE(68);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(8)
      if (('A' <= lookahead && lookahead <= '_') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 9:
      if (lookahead == '"') ADVANCE(511);
      if (lookahead == '/') ADVANCE(10);
      if (lookahead == '\\') ADVANCE(7);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(9)
      END_STATE();
    case 10:
      if (lookahead == '*') ADVANCE(13);
      if (lookahead == '/') ADVANCE(527);
      END_STATE();
    case 11:
      if (lookahead == '*') ADVANCE(13);
      if (lookahead == '/') ADVANCE(527);
      if (lookahead == '=') ADVANCE(81);
      END_STATE();
    case 12:
      if (lookahead == '*') ADVANCE(12);
      if (lookahead == '/') ADVANCE(526);
      if (lookahead != 0) ADVANCE(13);
      END_STATE();
    case 13:
      if (lookahead == '*') ADVANCE(12);
      if (lookahead != 0) ADVANCE(13);
      END_STATE();
    case 14:
      if (lookahead == '=') ADVANCE(71);
      END_STATE();
    case 15:
      if (lookahead == '=') ADVANCE(82);
      END_STATE();
    case 16:
      if (lookahead == '=') ADVANCE(85);
      END_STATE();
    case 17:
      if (lookahead == '=') ADVANCE(80);
      END_STATE();
    case 18:
      if (lookahead == '=') ADVANCE(86);
      END_STATE();
    case 19:
      if (lookahead == '=') ADVANCE(87);
      END_STATE();
    case 20:
      if (lookahead == '>') ADVANCE(517);
      if (lookahead == '\\') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(20);
      END_STATE();
    case 21:
      if (lookahead == '>') ADVANCE(518);
      if (lookahead == '\\') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(20);
      END_STATE();
    case 22:
      if (lookahead == 'c') ADVANCE(30);
      END_STATE();
    case 23:
      if (lookahead == 'd') ADVANCE(25);
      if (lookahead == 'i') ADVANCE(31);
      if (lookahead == '\t' ||
          lookahead == ' ') ADVANCE(23);
      END_STATE();
    case 24:
      if (lookahead == 'd') ADVANCE(27);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(28);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(525);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(523);
      END_STATE();
    case 28:
      if (lookahead == 'f') ADVANCE(29);
      END_STATE();
    case 29:
      if (lookahead == 'i') ADVANCE(32);
      END_STATE();
    case 30:
      if (lookahead == 'l') ADVANCE(33);
      END_STATE();
    case 31:
      if (lookahead == 'n') ADVANCE(22);
      END_STATE();
    case 32:
      if (lookahead == 'n') ADVANCE(26);
      END_STATE();
    case 33:
      if (lookahead == 'u') ADVANCE(24);
      END_STATE();
    case 34:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(519);
      END_STATE();
    case 35:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(34);
      END_STATE();
    case 36:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(35);
      END_STATE();
    case 37:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(36);
      END_STATE();
    case 38:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(37);
      END_STATE();
    case 39:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(38);
      END_STATE();
    case 40:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(39);
      END_STATE();
    case 41:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(40);
      END_STATE();
    case 42:
      if (lookahead != 0 &&
          lookahead != '\r') ADVANCE(527);
      if (lookahead == '\r') ADVANCE(528);
      END_STATE();
    case 43:
      if (eof) ADVANCE(48);
      if (lookahead == '\n') SKIP(0)
      END_STATE();
    case 44:
      if (eof) ADVANCE(48);
      if (lookahead == '\n') SKIP(0)
      if (lookahead == '\r') SKIP(43)
      END_STATE();
    case 45:
      if (eof) ADVANCE(48);
      if (lookahead == '\n') SKIP(47)
      END_STATE();
    case 46:
      if (eof) ADVANCE(48);
      if (lookahead == '\n') SKIP(47)
      if (lookahead == '\r') SKIP(45)
      END_STATE();
    case 47:
      if (eof) ADVANCE(48);
      if (lookahead == '!') ADVANCE(57);
      if (lookahead == '"') ADVANCE(511);
      if (lookahead == '#') ADVANCE(23);
      if (lookahead == '%') ADVANCE(15);
      if (lookahead == '&') ADVANCE(16);
      if (lookahead == '(') ADVANCE(51);
      if (lookahead == ')') ADVANCE(53);
      if (lookahead == '*') ADVANCE(17);
      if (lookahead == '+') ADVANCE(62);
      if (lookahead == '-') ADVANCE(60);
      if (lookahead == '/') ADVANCE(11);
      if (lookahead == ';') ADVANCE(56);
      if (lookahead == '<') ADVANCE(20);
      if (lookahead == '=') ADVANCE(78);
      if (lookahead == 'A') ADVANCE(351);
      if (lookahead == 'B') ADVANCE(286);
      if (lookahead == 'C') ADVANCE(284);
      if (lookahead == 'D') ADVANCE(165);
      if (lookahead == 'E') ADVANCE(321);
      if (lookahead == 'F') ADVANCE(309);
      if (lookahead == 'G') ADVANCE(401);
      if (lookahead == 'H') ADVANCE(371);
      if (lookahead == 'I') ADVANCE(352);
      if (lookahead == 'J') ADVANCE(476);
      if (lookahead == 'L') ADVANCE(287);
      if (lookahead == 'M') ADVANCE(159);
      if (lookahead == 'N') ADVANCE(160);
      if (lookahead == 'O') ADVANCE(490);
      if (lookahead == 'P') ADVANCE(161);
      if (lookahead == 'Q') ADVANCE(485);
      if (lookahead == 'R') ADVANCE(226);
      if (lookahead == 'S') ADVANCE(101);
      if (lookahead == 'T') ADVANCE(162);
      if (lookahead == 'U') ADVANCE(291);
      if (lookahead == 'V') ADVANCE(227);
      if (lookahead == 'W') ADVANCE(299);
      if (lookahead == 'X') ADVANCE(115);
      if (lookahead == '\\') SKIP(46)
      if (lookahead == '^') ADVANCE(18);
      if (lookahead == 'v') ADVANCE(388);
      if (lookahead == '{') ADVANCE(49);
      if (lookahead == '|') ADVANCE(19);
      if (lookahead == '}') ADVANCE(50);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(47)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(510);
      if (('K' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_AMP);
      if (lookahead == '&') ADVANCE(67);
      if (lookahead == '=') ADVANCE(85);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=') ADVANCE(71);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(90);
      if (lookahead == '=') ADVANCE(84);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '=') ADVANCE(84);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '+') ADVANCE(91);
      if (lookahead == '=') ADVANCE(83);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '=') ADVANCE(83);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '=') ADVANCE(80);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '*') ADVANCE(13);
      if (lookahead == '/') ADVANCE(527);
      if (lookahead == '=') ADVANCE(81);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '=') ADVANCE(82);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_PIPE_PIPE);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_AMP_AMP);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '=') ADVANCE(87);
      if (lookahead == '|') ADVANCE(66);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_CARET);
      if (lookahead == '=') ADVANCE(86);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(73);
      if (lookahead == '>') ADVANCE(77);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '<') ADVANCE(76);
      if (lookahead == '=') ADVANCE(74);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(70);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_STAR_EQ);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_SLASH_EQ);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_PERCENT_EQ);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_PLUS_EQ);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_DASH_EQ);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_AMP_EQ);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_CARET_EQ);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_PIPE_EQ);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_PLUS_PLUS);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'A') ADVANCE(474);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('B' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'B') ADVANCE(374);
      if (lookahead == 'Q') ADVANCE(488);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'B') ADVANCE(372);
      if (lookahead == 'M') ADVANCE(236);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'B') ADVANCE(372);
      if (lookahead == 'P') ADVANCE(187);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'B') ADVANCE(372);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'C') ADVANCE(382);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'C') ADVANCE(378);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'C') ADVANCE(453);
      if (lookahead == '_') ADVANCE(96);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'C') ADVANCE(453);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D') ADVANCE(119);
      if (lookahead == 'c') ADVANCE(424);
      if (lookahead == 'e') ADVANCE(278);
      if (lookahead == 'h') ADVANCE(264);
      if (lookahead == 'o') ADVANCE(479);
      if (lookahead == 'p') ADVANCE(303);
      if (lookahead == 'y') ADVANCE(342);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D') ADVANCE(375);
      if (lookahead == 'N') ADVANCE(386);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'D') ADVANCE(180);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E') ADVANCE(221);
      if (lookahead == 'S') ADVANCE(444);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'E') ADVANCE(322);
      if (lookahead == 'I') ADVANCE(365);
      if (lookahead == 'R') ADVANCE(263);
      if (lookahead == 'T') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'F') ADVANCE(489);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'F') ADVANCE(310);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'F') ADVANCE(302);
      if (lookahead == 'L') ADVANCE(314);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'F') ADVANCE(316);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'G') ADVANCE(421);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'L') ADVANCE(134);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'L') ADVANCE(173);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'L') ADVANCE(304);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'L') ADVANCE(312);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'M') ADVANCE(111);
      if (lookahead == 'Y') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'P') ADVANCE(178);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'P') ADVANCE(188);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'Q') ADVANCE(488);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'R') ADVANCE(131);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'R') ADVANCE(238);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'S') ADVANCE(265);
      if (lookahead == 'X') ADVANCE(127);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'S') ADVANCE(293);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(313);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(301);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'T') ADVANCE(230);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'W') ADVANCE(318);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'Y') ADVANCE(128);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'Z') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Y') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(107);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(121);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(92);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(96);
      if (lookahead == 'd') ADVANCE(153);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(96);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(102);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(123);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(116);
      if (lookahead == 't') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(104);
      if (lookahead == 's') ADVANCE(470);
      if (lookahead == 'u') ADVANCE(413);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(95);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(122);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(108);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(94);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(118);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(93);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(105);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(126);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(110);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(103);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(120);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(106);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(125);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(112);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(124);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(117);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(114);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(98);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(109);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(202);
      if (lookahead == 'e') ADVANCE(357);
      if (lookahead == 'o') ADVANCE(219);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(347);
      if (lookahead == 'e') ADVANCE(491);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(362);
      if (lookahead == 'l') ADVANCE(377);
      if (lookahead == 'o') ADVANCE(297);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(191);
      if (lookahead == 'e') ADVANCE(343);
      if (lookahead == 'i') ADVANCE(200);
      if (lookahead == 'r') ADVANCE(174);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(195);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(395);
      if (lookahead == 'i') ADVANCE(215);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(443);
      if (lookahead == 'e') ADVANCE(327);
      if (lookahead == 'i') ADVANCE(412);
      if (lookahead == 'r') ADVANCE(181);
      if (lookahead == 'y') ADVANCE(355);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(326);
      if (lookahead == 'p') ADVANCE(392);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(438);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(193);
      if (lookahead == 'e') ADVANCE(135);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(311);
      if (lookahead == 'o') ADVANCE(294);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(331);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(397);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(346);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(196);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(366);
      if (lookahead == 'e') ADVANCE(240);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(320);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(459);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(415);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(420);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(450);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(455);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(492);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(329);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(273);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 184:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(501);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(334);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(349);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(275);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 188:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(276);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(211);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 191:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(133);
      if (lookahead == 'r') ADVANCE(279);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(373);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 193:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(167);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 194:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(385);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(393);
      if (lookahead == 'm') ADVANCE(252);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(237);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(486);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'b') ADVANCE(487);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 199:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(319);
      if (lookahead == 'n') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 201:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(319);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(414);
      if (lookahead == 'n') ADVANCE(480);
      if (lookahead == 'p') ADVANCE(129);
      if (lookahead == 't') ADVANCE(416);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(484);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 204:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(144);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(464);
      if (lookahead == 'r') ADVANCE(451);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(457);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(454);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(460);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 211:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(465);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(185);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 213:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(466);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(100);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 217:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(176);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(379);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(229);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(305);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 222:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(315);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 223:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(280);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 224:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(282);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 225:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 226:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(166);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 227:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(207);
      if (lookahead == 'i') ADVANCE(260);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 228:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(132);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 229:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(326);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 230:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(495);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 231:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(409);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 232:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(430);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 233:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 234:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(361);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 235:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(404);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 236:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(429);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 237:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(320);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 238:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(433);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 239:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(428);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 240:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 241:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(363);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 242:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(403);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 243:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(459);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 244:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(419);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 245:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 246:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(439);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 247:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(452);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 248:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(407);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 249:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 250:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(241);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 251:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(425);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 252:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(468);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 253:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(408);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 254:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(427);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 255:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(400);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 256:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(148);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 257:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(147);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 258:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(437);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 259:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(348);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 260:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(492);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 261:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(281);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 262:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(213);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 263:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(175);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 264:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(247);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 265:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(341);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 266:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(208);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 267:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(458);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 268:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(205);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 269:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 270:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(469);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 271:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(283);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 272:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(499);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 273:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 274:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(380);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 275:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 276:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 277:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 278:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(348);
      if (lookahead == 'l') ADVANCE(266);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 279:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(245);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 280:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(267);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 281:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(248);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 282:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(246);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 283:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(255);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 284:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(169);
      if (lookahead == 'o') ADVANCE(325);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 285:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 286:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(323);
      if (lookahead == 'l') ADVANCE(370);
      if (lookahead == 'u') ADVANCE(445);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 287:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(360);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 288:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(506);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 289:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(272);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 290:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(494);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 291:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(214);
      if (lookahead == 'n') ADVANCE(218);
      if (lookahead == 'p') ADVANCE(217);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 292:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(214);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 293:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(505);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 294:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 295:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(212);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 296:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(197);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 297:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(361);
      if (lookahead == 'l') ADVANCE(498);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 298:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(206);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 299:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(223);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 300:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 301:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(201);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 302:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(324);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 303:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(423);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 304:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(353);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 305:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 306:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(380);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 307:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(467);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 308:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(384);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 309:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(328);
      if (lookahead == 'u') ADVANCE(354);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 310:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 311:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(359);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 312:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(435);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 313:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(345);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 314:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(434);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 315:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(460);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 316:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(333);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 317:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(198);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 318:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(224);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 319:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'k') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 320:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 321:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(259);
      if (lookahead == 'q') ADVANCE(477);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 322:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(259);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 323:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(336);
      if (lookahead == 't') ADVANCE(344);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 324:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(326);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 325:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(389);
      if (lookahead == 'n') ADVANCE(367);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 326:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 327:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(243);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 328:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 329:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 330:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(184);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 331:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(307);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 332:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 333:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 334:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(146);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 335:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(448);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 336:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(194);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 337:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(179);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 338:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(269);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 339:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(257);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 340:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(338);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 341:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(268);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 342:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(192);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 343:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(398);
      if (lookahead == 'x') ADVANCE(442);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 344:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(171);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 345:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 346:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(298);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 347:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(228);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 348:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(234);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 349:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'm') ADVANCE(270);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 350:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 351:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(277);
      if (lookahead == 'r') ADVANCE(199);
      if (lookahead == 't') ADVANCE(463);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 352:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(396);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 353:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(319);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 354:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 355:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(172);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 356:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 357:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(475);
      if (lookahead == 's') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 358:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(428);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 359:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 360:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(258);
      if (lookahead == 's') ADVANCE(440);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 361:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(439);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 362:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(237);
      if (lookahead == 'r') ADVANCE(163);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 363:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 364:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(471);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 365:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(472);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 366:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(436);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 367:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(269);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 368:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(222);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 369:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(210);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 370:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(190);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 371:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(410);
      if (lookahead == 'y') ADVANCE(399);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 372:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(493);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 373:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(326);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 374:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(496);
      if (lookahead == 'u') ADVANCE(445);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 375:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(203);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 376:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(350);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 377:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(441);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 378:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(340);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 379:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(155);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 380:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(356);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 381:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(478);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 382:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(368);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 383:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(402);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 384:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(358);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 385:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(177);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 386:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(220);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 387:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 388:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 389:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(483);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 390:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(364);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 391:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(422);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 392:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(417);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 393:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(332);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 394:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 395:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(285);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 396:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(482);
      if (lookahead == 's') ADVANCE(244);
      if (lookahead == 't') ADVANCE(261);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 397:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(140);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 398:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(337);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 399:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(242);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 400:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 401:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(164);
      if (lookahead == 'u') ADVANCE(292);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 402:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(508);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 403:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(113);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 404:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(500);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 405:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(204);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 406:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(326);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 407:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 408:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(497);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 409:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(330);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 410:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(288);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 411:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(296);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 412:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(262);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 413:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 414:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(387);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 415:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(216);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 416:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(290);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 417:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 418:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(141);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 419:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(456);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 420:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(186);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 421:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(381);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 422:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(499);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 423:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(175);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 424:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(250);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 425:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(156);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 426:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(317);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 427:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(157);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 428:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 429:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(432);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 430:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 431:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(449);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 432:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(183);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 433:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(481);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 434:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 435:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(439);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 436:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(189);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 437:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(444);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 438:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(256);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 439:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 440:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(99);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 441:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(136);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 442:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(137);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 443:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(168);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 444:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(503);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 445:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(447);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 446:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 447:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(376);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 448:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(428);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 449:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(289);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 450:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 451:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(295);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 452:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(139);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 453:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(406);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 454:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(306);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 455:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(158);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 456:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(142);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 457:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(143);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 458:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(154);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 459:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(249);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 460:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(300);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 461:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(225);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 462:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(232);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 463:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(411);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 464:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(383);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 465:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(308);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 466:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(391);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 467:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(502);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 468:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(251);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 469:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(254);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 470:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(504);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 471:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(185);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 472:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(271);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 473:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(426);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 474:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(473);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 475:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 476:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(431);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 477:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(170);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 478:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(394);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 479:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(405);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 480:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(182);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 481:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(335);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 482:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(446);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 483:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(418);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 484:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(348);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 485:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(235);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 486:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(462);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 487:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(461);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 488:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(253);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 489:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(369);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 490:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'v') ADVANCE(231);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 491:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'w') ADVANCE(130);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 492:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'w') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 493:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'x') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 494:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'x') ADVANCE(507);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 495:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'x') ADVANCE(439);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 496:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'x') ADVANCE(239);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 497:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 498:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(274);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 499:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(133);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 500:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(149);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 501:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(145);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 502:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(152);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 503:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(328);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 504:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'y') ADVANCE(339);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 505:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'z') ADVANCE(233);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'y')) ADVANCE(509);
      END_STATE();
    case 506:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'z') ADVANCE(390);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'y')) ADVANCE(509);
      END_STATE();
    case 507:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '3' ||
          lookahead == '4') ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 508:
      ACCEPT_TOKEN(sym_identifier);
      if (('2' <= lookahead && lookahead <= '4')) ADVANCE(509);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 509:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(509);
      END_STATE();
    case 510:
      ACCEPT_TOKEN(sym_number_literal);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(510);
      END_STATE();
    case 511:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 512:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '*') ADVANCE(514);
      if (lookahead == '/') ADVANCE(516);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(516);
      END_STATE();
    case 513:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '*') ADVANCE(513);
      if (lookahead == '/') ADVANCE(516);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(514);
      END_STATE();
    case 514:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '*') ADVANCE(513);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(514);
      END_STATE();
    case 515:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead == '/') ADVANCE(512);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(515);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(516);
      END_STATE();
    case 516:
      ACCEPT_TOKEN(aux_sym_string_literal_token1);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(516);
      END_STATE();
    case 517:
      ACCEPT_TOKEN(sym_system_lib_string);
      END_STATE();
    case 518:
      ACCEPT_TOKEN(sym_system_lib_string);
      if (lookahead == '>') ADVANCE(517);
      if (lookahead == '\\') ADVANCE(21);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(20);
      END_STATE();
    case 519:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 520:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (lookahead == '\\') ADVANCE(7);
      END_STATE();
    case 521:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(519);
      END_STATE();
    case 522:
      ACCEPT_TOKEN(sym_escape_sequence);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(521);
      END_STATE();
    case 523:
      ACCEPT_TOKEN(aux_sym_preproc_include_token1);
      END_STATE();
    case 524:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(524);
      END_STATE();
    case 525:
      ACCEPT_TOKEN(aux_sym_preproc_def_token1);
      END_STATE();
    case 526:
      ACCEPT_TOKEN(sym_comment);
      END_STATE();
    case 527:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead == '\\') ADVANCE(42);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(527);
      END_STATE();
    case 528:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\\') ADVANCE(527);
      if (lookahead == '\\') ADVANCE(42);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == '\\') SKIP(1)
      if (lookahead == 'b') ADVANCE(2);
      if (lookahead == 'c') ADVANCE(3);
      if (lookahead == 'd') ADVANCE(4);
      if (lookahead == 'e') ADVANCE(5);
      if (lookahead == 'f') ADVANCE(6);
      if (lookahead == 'g') ADVANCE(7);
      if (lookahead == 'i') ADVANCE(8);
      if (lookahead == 'r') ADVANCE(9);
      if (lookahead == 's') ADVANCE(10);
      if (lookahead == 'w') ADVANCE(11);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(0)
      if (lookahead == '\r') SKIP(12)
      END_STATE();
    case 2:
      if (lookahead == 'r') ADVANCE(13);
      END_STATE();
    case 3:
      if (lookahead == 'a') ADVANCE(14);
      if (lookahead == 'o') ADVANCE(15);
      END_STATE();
    case 4:
      if (lookahead == 'e') ADVANCE(16);
      END_STATE();
    case 5:
      if (lookahead == 'l') ADVANCE(17);
      END_STATE();
    case 6:
      if (lookahead == 'o') ADVANCE(18);
      END_STATE();
    case 7:
      if (lookahead == 'o') ADVANCE(19);
      END_STATE();
    case 8:
      if (lookahead == 'f') ADVANCE(20);
      END_STATE();
    case 9:
      if (lookahead == 'e') ADVANCE(21);
      END_STATE();
    case 10:
      if (lookahead == 'w') ADVANCE(22);
      END_STATE();
    case 11:
      if (lookahead == 'h') ADVANCE(23);
      END_STATE();
    case 12:
      if (lookahead == '\n') SKIP(0)
      END_STATE();
    case 13:
      if (lookahead == 'e') ADVANCE(24);
      END_STATE();
    case 14:
      if (lookahead == 's') ADVANCE(25);
      END_STATE();
    case 15:
      if (lookahead == 'n') ADVANCE(26);
      END_STATE();
    case 16:
      if (lookahead == 'f') ADVANCE(27);
      END_STATE();
    case 17:
      if (lookahead == 's') ADVANCE(28);
      END_STATE();
    case 18:
      if (lookahead == 'r') ADVANCE(29);
      END_STATE();
    case 19:
      if (lookahead == 't') ADVANCE(30);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 21:
      if (lookahead == 't') ADVANCE(31);
      END_STATE();
    case 22:
      if (lookahead == 'i') ADVANCE(32);
      END_STATE();
    case 23:
      if (lookahead == 'i') ADVANCE(33);
      END_STATE();
    case 24:
      if (lookahead == 'a') ADVANCE(34);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(35);
      END_STATE();
    case 26:
      if (lookahead == 't') ADVANCE(36);
      END_STATE();
    case 27:
      if (lookahead == 'a') ADVANCE(37);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(38);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 30:
      if (lookahead == 'o') ADVANCE(39);
      END_STATE();
    case 31:
      if (lookahead == 'u') ADVANCE(40);
      END_STATE();
    case 32:
      if (lookahead == 't') ADVANCE(41);
      END_STATE();
    case 33:
      if (lookahead == 'l') ADVANCE(42);
      END_STATE();
    case 34:
      if (lookahead == 'k') ADVANCE(43);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_case);
      END_STATE();
    case 36:
      if (lookahead == 'i') ADVANCE(44);
      END_STATE();
    case 37:
      if (lookahead == 'u') ADVANCE(45);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_goto);
      END_STATE();
    case 40:
      if (lookahead == 'r') ADVANCE(46);
      END_STATE();
    case 41:
      if (lookahead == 'c') ADVANCE(47);
      END_STATE();
    case 42:
      if (lookahead == 'e') ADVANCE(48);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_break);
      END_STATE();
    case 44:
      if (lookahead == 'n') ADVANCE(49);
      END_STATE();
    case 45:
      if (lookahead == 'l') ADVANCE(50);
      END_STATE();
    case 46:
      if (lookahead == 'n') ADVANCE(51);
      END_STATE();
    case 47:
      if (lookahead == 'h') ADVANCE(52);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 49:
      if (lookahead == 'u') ADVANCE(53);
      END_STATE();
    case 50:
      if (lookahead == 't') ADVANCE(54);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_switch);
      END_STATE();
    case 53:
      if (lookahead == 'e') ADVANCE(55);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_default);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_continue);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 47},
  [3] = {.lex_state = 47},
  [4] = {.lex_state = 47},
  [5] = {.lex_state = 47},
  [6] = {.lex_state = 47},
  [7] = {.lex_state = 47},
  [8] = {.lex_state = 47},
  [9] = {.lex_state = 47},
  [10] = {.lex_state = 47},
  [11] = {.lex_state = 47},
  [12] = {.lex_state = 47},
  [13] = {.lex_state = 47},
  [14] = {.lex_state = 8},
  [15] = {.lex_state = 8},
  [16] = {.lex_state = 8},
  [17] = {.lex_state = 8},
  [18] = {.lex_state = 8},
  [19] = {.lex_state = 8},
  [20] = {.lex_state = 8},
  [21] = {.lex_state = 5},
  [22] = {.lex_state = 5},
  [23] = {.lex_state = 5},
  [24] = {.lex_state = 5},
  [25] = {.lex_state = 5},
  [26] = {.lex_state = 47},
  [27] = {.lex_state = 8},
  [28] = {.lex_state = 8},
  [29] = {.lex_state = 8},
  [30] = {.lex_state = 8},
  [31] = {.lex_state = 8},
  [32] = {.lex_state = 8},
  [33] = {.lex_state = 8},
  [34] = {.lex_state = 8},
  [35] = {.lex_state = 8},
  [36] = {.lex_state = 8},
  [37] = {.lex_state = 8},
  [38] = {.lex_state = 8},
  [39] = {.lex_state = 8},
  [40] = {.lex_state = 8},
  [41] = {.lex_state = 8},
  [42] = {.lex_state = 8},
  [43] = {.lex_state = 8},
  [44] = {.lex_state = 8},
  [45] = {.lex_state = 8},
  [46] = {.lex_state = 47},
  [47] = {.lex_state = 8},
  [48] = {.lex_state = 47},
  [49] = {.lex_state = 8},
  [50] = {.lex_state = 8},
  [51] = {.lex_state = 8},
  [52] = {.lex_state = 8},
  [53] = {.lex_state = 8},
  [54] = {.lex_state = 8},
  [55] = {.lex_state = 8},
  [56] = {.lex_state = 8},
  [57] = {.lex_state = 8},
  [58] = {.lex_state = 8},
  [59] = {.lex_state = 5},
  [60] = {.lex_state = 5},
  [61] = {.lex_state = 5},
  [62] = {.lex_state = 47},
  [63] = {.lex_state = 47},
  [64] = {.lex_state = 47},
  [65] = {.lex_state = 47},
  [66] = {.lex_state = 47},
  [67] = {.lex_state = 47},
  [68] = {.lex_state = 47},
  [69] = {.lex_state = 47},
  [70] = {.lex_state = 47},
  [71] = {.lex_state = 47},
  [72] = {.lex_state = 47},
  [73] = {.lex_state = 47},
  [74] = {.lex_state = 47},
  [75] = {.lex_state = 47},
  [76] = {.lex_state = 47},
  [77] = {.lex_state = 47},
  [78] = {.lex_state = 47},
  [79] = {.lex_state = 47},
  [80] = {.lex_state = 47},
  [81] = {.lex_state = 47},
  [82] = {.lex_state = 47},
  [83] = {.lex_state = 47},
  [84] = {.lex_state = 47},
  [85] = {.lex_state = 47},
  [86] = {.lex_state = 47},
  [87] = {.lex_state = 47},
  [88] = {.lex_state = 47},
  [89] = {.lex_state = 47},
  [90] = {.lex_state = 47},
  [91] = {.lex_state = 47},
  [92] = {.lex_state = 47},
  [93] = {.lex_state = 47},
  [94] = {.lex_state = 47},
  [95] = {.lex_state = 47},
  [96] = {.lex_state = 47},
  [97] = {.lex_state = 47},
  [98] = {.lex_state = 47},
  [99] = {.lex_state = 47},
  [100] = {.lex_state = 47},
  [101] = {.lex_state = 47},
  [102] = {.lex_state = 47},
  [103] = {.lex_state = 47},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
  [109] = {.lex_state = 0},
  [110] = {.lex_state = 0},
  [111] = {.lex_state = 0},
  [112] = {.lex_state = 0},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 0},
  [115] = {.lex_state = 0},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 0},
  [123] = {.lex_state = 0},
  [124] = {.lex_state = 5},
  [125] = {.lex_state = 0},
  [126] = {.lex_state = 6},
  [127] = {.lex_state = 6},
  [128] = {.lex_state = 6},
  [129] = {.lex_state = 6},
  [130] = {.lex_state = 6},
  [131] = {.lex_state = 0},
  [132] = {.lex_state = 0},
  [133] = {.lex_state = 0},
  [134] = {.lex_state = 0},
  [135] = {.lex_state = 0},
  [136] = {.lex_state = 0},
  [137] = {.lex_state = 0},
  [138] = {.lex_state = 0},
  [139] = {.lex_state = 0},
  [140] = {.lex_state = 0},
  [141] = {.lex_state = 0},
  [142] = {.lex_state = 0},
  [143] = {.lex_state = 0},
  [144] = {.lex_state = 0},
  [145] = {.lex_state = 0},
  [146] = {.lex_state = 0},
  [147] = {.lex_state = 0},
  [148] = {.lex_state = 0},
  [149] = {.lex_state = 0},
  [150] = {.lex_state = 0},
  [151] = {.lex_state = 0},
  [152] = {.lex_state = 0},
  [153] = {.lex_state = 0},
  [154] = {.lex_state = 0},
  [155] = {.lex_state = 0},
  [156] = {.lex_state = 5},
  [157] = {.lex_state = 5},
  [158] = {.lex_state = 0},
  [159] = {.lex_state = 0},
  [160] = {.lex_state = 0},
  [161] = {.lex_state = 0},
  [162] = {.lex_state = 5},
  [163] = {.lex_state = 0},
  [164] = {.lex_state = 0},
  [165] = {.lex_state = 0},
  [166] = {.lex_state = 0},
  [167] = {.lex_state = 0},
  [168] = {.lex_state = 0},
  [169] = {.lex_state = 0},
  [170] = {.lex_state = 0},
  [171] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_case] = ACTIONS(1),
    [anon_sym_default] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_break] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_continue] = ACTIONS(1),
    [anon_sym_goto] = ACTIONS(1),
    [anon_sym_switch] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_for] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_PIPE_PIPE] = ACTIONS(1),
    [anon_sym_AMP_AMP] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_LT] = ACTIONS(1),
    [anon_sym_GT_GT] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_STAR_EQ] = ACTIONS(1),
    [anon_sym_SLASH_EQ] = ACTIONS(1),
    [anon_sym_PERCENT_EQ] = ACTIONS(1),
    [anon_sym_PLUS_EQ] = ACTIONS(1),
    [anon_sym_DASH_EQ] = ACTIONS(1),
    [anon_sym_AMP_EQ] = ACTIONS(1),
    [anon_sym_CARET_EQ] = ACTIONS(1),
    [anon_sym_PIPE_EQ] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_DASH_DASH] = ACTIONS(1),
    [anon_sym_PLUS_PLUS] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [sym_number_literal] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [aux_sym_preproc_include_token1] = ACTIONS(1),
    [aux_sym_preproc_def_token1] = ACTIONS(1),
    [sym_primitive_type] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
  },
  [1] = {
    [sym_source_file] = STATE(164),
    [sym_function_definition] = STATE(104),
    [sym_compound_statement] = STATE(104),
    [sym__declaration_specifiers] = STATE(131),
    [sym__type_specifier] = STATE(150),
    [sym_preproc_include] = STATE(104),
    [sym_preproc_def] = STATE(104),
    [aux_sym_source_file_repeat1] = STATE(104),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
    [anon_sym_LBRACE] = ACTIONS(9),
    [aux_sym_preproc_include_token1] = ACTIONS(11),
    [aux_sym_preproc_def_token1] = ACTIONS(13),
    [sym_primitive_type] = ACTIONS(15),
    [sym_comment] = ACTIONS(3),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 28,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      sym_primitive_type,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(19), 1,
      anon_sym_RBRACE,
    ACTIONS(21), 1,
      anon_sym_while,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_break,
    ACTIONS(29), 1,
      anon_sym_SEMI,
    ACTIONS(31), 1,
      anon_sym_continue,
    ACTIONS(33), 1,
      anon_sym_goto,
    ACTIONS(35), 1,
      anon_sym_switch,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(39), 1,
      anon_sym_for,
    ACTIONS(43), 1,
      anon_sym_return,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    STATE(50), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(122), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(165), 1,
      sym_comma_expression,
    STATE(169), 1,
      sym__statement_identifier,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(25), 3,
      anon_sym_case,
      anon_sym_default,
      anon_sym_else,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
    STATE(9), 13,
      sym_compound_statement,
      sym_while_statement,
      sym_break_statement,
      sym_labeled_statement,
      sym_continue_statement,
      sym_goto_statement,
      sym_switch_statement,
      sym_if_statement,
      sym_for_statement,
      sym_expression_statement,
      sym_return_statement,
      sym_declaration,
      aux_sym_case_statement_repeat1,
  [106] = 29,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      sym_primitive_type,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(21), 1,
      anon_sym_while,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_break,
    ACTIONS(29), 1,
      anon_sym_SEMI,
    ACTIONS(31), 1,
      anon_sym_continue,
    ACTIONS(33), 1,
      anon_sym_goto,
    ACTIONS(35), 1,
      anon_sym_switch,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(39), 1,
      anon_sym_for,
    ACTIONS(43), 1,
      anon_sym_return,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(49), 1,
      anon_sym_RBRACE,
    ACTIONS(51), 1,
      anon_sym_case,
    ACTIONS(53), 1,
      anon_sym_default,
    STATE(50), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(122), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(165), 1,
      sym_comma_expression,
    STATE(169), 1,
      sym__statement_identifier,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
    STATE(8), 14,
      sym_compound_statement,
      sym_while_statement,
      sym_case_statement,
      sym_break_statement,
      sym_labeled_statement,
      sym_continue_statement,
      sym_goto_statement,
      sym_switch_statement,
      sym_if_statement,
      sym_for_statement,
      sym_expression_statement,
      sym_return_statement,
      sym_declaration,
      aux_sym_compound_statement_repeat1,
  [214] = 29,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(55), 1,
      sym_identifier,
    ACTIONS(58), 1,
      anon_sym_LBRACE,
    ACTIONS(61), 1,
      anon_sym_RBRACE,
    ACTIONS(63), 1,
      anon_sym_while,
    ACTIONS(66), 1,
      anon_sym_LPAREN,
    ACTIONS(69), 1,
      anon_sym_case,
    ACTIONS(72), 1,
      anon_sym_default,
    ACTIONS(75), 1,
      anon_sym_break,
    ACTIONS(78), 1,
      anon_sym_SEMI,
    ACTIONS(81), 1,
      anon_sym_continue,
    ACTIONS(84), 1,
      anon_sym_goto,
    ACTIONS(87), 1,
      anon_sym_switch,
    ACTIONS(90), 1,
      anon_sym_if,
    ACTIONS(93), 1,
      anon_sym_for,
    ACTIONS(99), 1,
      anon_sym_return,
    ACTIONS(102), 1,
      sym_number_literal,
    ACTIONS(105), 1,
      anon_sym_DQUOTE,
    ACTIONS(108), 1,
      sym_primitive_type,
    STATE(50), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(122), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(165), 1,
      sym_comma_expression,
    STATE(169), 1,
      sym__statement_identifier,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(96), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
    STATE(4), 14,
      sym_compound_statement,
      sym_while_statement,
      sym_case_statement,
      sym_break_statement,
      sym_labeled_statement,
      sym_continue_statement,
      sym_goto_statement,
      sym_switch_statement,
      sym_if_statement,
      sym_for_statement,
      sym_expression_statement,
      sym_return_statement,
      sym_declaration,
      aux_sym_compound_statement_repeat1,
  [322] = 28,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      sym_primitive_type,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(21), 1,
      anon_sym_while,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_break,
    ACTIONS(29), 1,
      anon_sym_SEMI,
    ACTIONS(31), 1,
      anon_sym_continue,
    ACTIONS(33), 1,
      anon_sym_goto,
    ACTIONS(35), 1,
      anon_sym_switch,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(39), 1,
      anon_sym_for,
    ACTIONS(43), 1,
      anon_sym_return,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(111), 1,
      anon_sym_RBRACE,
    STATE(50), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(122), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(165), 1,
      sym_comma_expression,
    STATE(169), 1,
      sym__statement_identifier,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(113), 3,
      anon_sym_case,
      anon_sym_default,
      anon_sym_else,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
    STATE(7), 13,
      sym_compound_statement,
      sym_while_statement,
      sym_break_statement,
      sym_labeled_statement,
      sym_continue_statement,
      sym_goto_statement,
      sym_switch_statement,
      sym_if_statement,
      sym_for_statement,
      sym_expression_statement,
      sym_return_statement,
      sym_declaration,
      aux_sym_case_statement_repeat1,
  [428] = 28,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      sym_primitive_type,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(21), 1,
      anon_sym_while,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_break,
    ACTIONS(29), 1,
      anon_sym_SEMI,
    ACTIONS(31), 1,
      anon_sym_continue,
    ACTIONS(33), 1,
      anon_sym_goto,
    ACTIONS(35), 1,
      anon_sym_switch,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(39), 1,
      anon_sym_for,
    ACTIONS(43), 1,
      anon_sym_return,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(115), 1,
      anon_sym_RBRACE,
    STATE(50), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(122), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(165), 1,
      sym_comma_expression,
    STATE(169), 1,
      sym__statement_identifier,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(117), 3,
      anon_sym_case,
      anon_sym_default,
      anon_sym_else,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
    STATE(2), 13,
      sym_compound_statement,
      sym_while_statement,
      sym_break_statement,
      sym_labeled_statement,
      sym_continue_statement,
      sym_goto_statement,
      sym_switch_statement,
      sym_if_statement,
      sym_for_statement,
      sym_expression_statement,
      sym_return_statement,
      sym_declaration,
      aux_sym_case_statement_repeat1,
  [534] = 28,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      sym_primitive_type,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(21), 1,
      anon_sym_while,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_break,
    ACTIONS(29), 1,
      anon_sym_SEMI,
    ACTIONS(31), 1,
      anon_sym_continue,
    ACTIONS(33), 1,
      anon_sym_goto,
    ACTIONS(35), 1,
      anon_sym_switch,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(39), 1,
      anon_sym_for,
    ACTIONS(43), 1,
      anon_sym_return,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(119), 1,
      anon_sym_RBRACE,
    STATE(50), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(122), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(165), 1,
      sym_comma_expression,
    STATE(169), 1,
      sym__statement_identifier,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(121), 3,
      anon_sym_case,
      anon_sym_default,
      anon_sym_else,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
    STATE(9), 13,
      sym_compound_statement,
      sym_while_statement,
      sym_break_statement,
      sym_labeled_statement,
      sym_continue_statement,
      sym_goto_statement,
      sym_switch_statement,
      sym_if_statement,
      sym_for_statement,
      sym_expression_statement,
      sym_return_statement,
      sym_declaration,
      aux_sym_case_statement_repeat1,
  [640] = 29,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      sym_primitive_type,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(21), 1,
      anon_sym_while,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_break,
    ACTIONS(29), 1,
      anon_sym_SEMI,
    ACTIONS(31), 1,
      anon_sym_continue,
    ACTIONS(33), 1,
      anon_sym_goto,
    ACTIONS(35), 1,
      anon_sym_switch,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(39), 1,
      anon_sym_for,
    ACTIONS(43), 1,
      anon_sym_return,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      anon_sym_case,
    ACTIONS(53), 1,
      anon_sym_default,
    ACTIONS(123), 1,
      anon_sym_RBRACE,
    STATE(50), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(122), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(165), 1,
      sym_comma_expression,
    STATE(169), 1,
      sym__statement_identifier,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
    STATE(4), 14,
      sym_compound_statement,
      sym_while_statement,
      sym_case_statement,
      sym_break_statement,
      sym_labeled_statement,
      sym_continue_statement,
      sym_goto_statement,
      sym_switch_statement,
      sym_if_statement,
      sym_for_statement,
      sym_expression_statement,
      sym_return_statement,
      sym_declaration,
      aux_sym_compound_statement_repeat1,
  [748] = 28,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(125), 1,
      sym_identifier,
    ACTIONS(128), 1,
      anon_sym_LBRACE,
    ACTIONS(131), 1,
      anon_sym_RBRACE,
    ACTIONS(133), 1,
      anon_sym_while,
    ACTIONS(136), 1,
      anon_sym_LPAREN,
    ACTIONS(141), 1,
      anon_sym_break,
    ACTIONS(144), 1,
      anon_sym_SEMI,
    ACTIONS(147), 1,
      anon_sym_continue,
    ACTIONS(150), 1,
      anon_sym_goto,
    ACTIONS(153), 1,
      anon_sym_switch,
    ACTIONS(156), 1,
      anon_sym_if,
    ACTIONS(159), 1,
      anon_sym_for,
    ACTIONS(165), 1,
      anon_sym_return,
    ACTIONS(168), 1,
      sym_number_literal,
    ACTIONS(171), 1,
      anon_sym_DQUOTE,
    ACTIONS(174), 1,
      sym_primitive_type,
    STATE(50), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(122), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(165), 1,
      sym_comma_expression,
    STATE(169), 1,
      sym__statement_identifier,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(139), 3,
      anon_sym_case,
      anon_sym_default,
      anon_sym_else,
    ACTIONS(162), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
    STATE(9), 13,
      sym_compound_statement,
      sym_while_statement,
      sym_break_statement,
      sym_labeled_statement,
      sym_continue_statement,
      sym_goto_statement,
      sym_switch_statement,
      sym_if_statement,
      sym_for_statement,
      sym_expression_statement,
      sym_return_statement,
      sym_declaration,
      aux_sym_case_statement_repeat1,
  [854] = 28,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      sym_primitive_type,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(21), 1,
      anon_sym_while,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_break,
    ACTIONS(29), 1,
      anon_sym_SEMI,
    ACTIONS(31), 1,
      anon_sym_continue,
    ACTIONS(33), 1,
      anon_sym_goto,
    ACTIONS(35), 1,
      anon_sym_switch,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(39), 1,
      anon_sym_for,
    ACTIONS(43), 1,
      anon_sym_return,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      anon_sym_case,
    ACTIONS(53), 1,
      anon_sym_default,
    STATE(50), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(122), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(165), 1,
      sym_comma_expression,
    STATE(169), 1,
      sym__statement_identifier,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
    STATE(71), 13,
      sym_compound_statement,
      sym_while_statement,
      sym_case_statement,
      sym_break_statement,
      sym_labeled_statement,
      sym_continue_statement,
      sym_goto_statement,
      sym_switch_statement,
      sym_if_statement,
      sym_for_statement,
      sym_expression_statement,
      sym_return_statement,
      sym_declaration,
  [958] = 28,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      sym_primitive_type,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(21), 1,
      anon_sym_while,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_break,
    ACTIONS(29), 1,
      anon_sym_SEMI,
    ACTIONS(31), 1,
      anon_sym_continue,
    ACTIONS(33), 1,
      anon_sym_goto,
    ACTIONS(35), 1,
      anon_sym_switch,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(39), 1,
      anon_sym_for,
    ACTIONS(43), 1,
      anon_sym_return,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      anon_sym_case,
    ACTIONS(53), 1,
      anon_sym_default,
    STATE(50), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(122), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(165), 1,
      sym_comma_expression,
    STATE(169), 1,
      sym__statement_identifier,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
    STATE(67), 13,
      sym_compound_statement,
      sym_while_statement,
      sym_case_statement,
      sym_break_statement,
      sym_labeled_statement,
      sym_continue_statement,
      sym_goto_statement,
      sym_switch_statement,
      sym_if_statement,
      sym_for_statement,
      sym_expression_statement,
      sym_return_statement,
      sym_declaration,
  [1062] = 28,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      sym_primitive_type,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(21), 1,
      anon_sym_while,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_break,
    ACTIONS(29), 1,
      anon_sym_SEMI,
    ACTIONS(31), 1,
      anon_sym_continue,
    ACTIONS(33), 1,
      anon_sym_goto,
    ACTIONS(35), 1,
      anon_sym_switch,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(39), 1,
      anon_sym_for,
    ACTIONS(43), 1,
      anon_sym_return,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      anon_sym_case,
    ACTIONS(53), 1,
      anon_sym_default,
    STATE(50), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(122), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(165), 1,
      sym_comma_expression,
    STATE(169), 1,
      sym__statement_identifier,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
    STATE(66), 13,
      sym_compound_statement,
      sym_while_statement,
      sym_case_statement,
      sym_break_statement,
      sym_labeled_statement,
      sym_continue_statement,
      sym_goto_statement,
      sym_switch_statement,
      sym_if_statement,
      sym_for_statement,
      sym_expression_statement,
      sym_return_statement,
      sym_declaration,
  [1166] = 28,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(15), 1,
      sym_primitive_type,
    ACTIONS(17), 1,
      sym_identifier,
    ACTIONS(21), 1,
      anon_sym_while,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(27), 1,
      anon_sym_break,
    ACTIONS(29), 1,
      anon_sym_SEMI,
    ACTIONS(31), 1,
      anon_sym_continue,
    ACTIONS(33), 1,
      anon_sym_goto,
    ACTIONS(35), 1,
      anon_sym_switch,
    ACTIONS(37), 1,
      anon_sym_if,
    ACTIONS(39), 1,
      anon_sym_for,
    ACTIONS(43), 1,
      anon_sym_return,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(51), 1,
      anon_sym_case,
    ACTIONS(53), 1,
      anon_sym_default,
    STATE(50), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(122), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(165), 1,
      sym_comma_expression,
    STATE(169), 1,
      sym__statement_identifier,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
    STATE(73), 13,
      sym_compound_statement,
      sym_while_statement,
      sym_case_statement,
      sym_break_statement,
      sym_labeled_statement,
      sym_continue_statement,
      sym_goto_statement,
      sym_switch_statement,
      sym_if_statement,
      sym_for_statement,
      sym_expression_statement,
      sym_return_statement,
      sym_declaration,
  [1270] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(179), 11,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_EQ,
    ACTIONS(177), 25,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_AMP_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [1314] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(183), 11,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_EQ,
    ACTIONS(181), 25,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_AMP_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [1358] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(187), 11,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_EQ,
    ACTIONS(185), 25,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_AMP_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [1402] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(191), 11,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_EQ,
    ACTIONS(189), 25,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_AMP_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [1446] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(195), 11,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_GT,
      anon_sym_LT,
      anon_sym_EQ,
    ACTIONS(193), 25,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_AMP_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [1490] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(201), 1,
      anon_sym_EQ,
    ACTIONS(203), 8,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_AMP_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
    ACTIONS(199), 10,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(197), 17,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [1538] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(201), 1,
      anon_sym_EQ,
    ACTIONS(205), 1,
      sym_identifier,
    ACTIONS(207), 1,
      anon_sym_COLON,
    ACTIONS(203), 8,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_AMP_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
    ACTIONS(199), 10,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(197), 14,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_LBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [1589] = 3,
    ACTIONS(177), 1,
      anon_sym_LF,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(179), 31,
      anon_sym_LPAREN,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_EQ,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_AMP_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_LBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [1629] = 3,
    ACTIONS(189), 1,
      anon_sym_LF,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(191), 31,
      anon_sym_LPAREN,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_EQ,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_AMP_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_LBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [1669] = 3,
    ACTIONS(193), 1,
      anon_sym_LF,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(195), 31,
      anon_sym_LPAREN,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_EQ,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_AMP_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_LBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [1709] = 4,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(211), 1,
      anon_sym_LF,
    ACTIONS(201), 9,
      anon_sym_EQ,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_AMP_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
    ACTIONS(199), 22,
      anon_sym_LPAREN,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_LBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [1751] = 3,
    ACTIONS(185), 1,
      anon_sym_LF,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(187), 31,
      anon_sym_LPAREN,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_EQ,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_AMP_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      anon_sym_LBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [1791] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(213), 14,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_for,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
    ACTIONS(215), 15,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_EQ,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_AMP_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
      sym_number_literal,
      anon_sym_DQUOTE,
  [1828] = 14,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(221), 2,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
    ACTIONS(219), 8,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_CARET,
      anon_sym_RBRACK,
  [1886] = 9,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
    ACTIONS(221), 6,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_PIPE,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(219), 14,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_RBRACK,
  [1934] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
    ACTIONS(221), 7,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_PIPE,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(219), 16,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_RBRACK,
  [1978] = 17,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
    ACTIONS(219), 6,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_RBRACK,
  [2042] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
    ACTIONS(219), 7,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_RBRACK,
  [2104] = 16,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(221), 1,
      anon_sym_PIPE,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(247), 1,
      anon_sym_CARET,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
    ACTIONS(219), 7,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_RBRACK,
  [2166] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
    ACTIONS(249), 5,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_RBRACK,
  [2232] = 15,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(221), 1,
      anon_sym_PIPE,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
    ACTIONS(219), 8,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_CARET,
      anon_sym_RBRACK,
  [2292] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(221), 2,
      anon_sym_AMP,
      anon_sym_PIPE,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
    ACTIONS(219), 10,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_RBRACK,
  [2348] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
    ACTIONS(221), 4,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(219), 12,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_RBRACK,
  [2400] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
    ACTIONS(221), 4,
      anon_sym_AMP,
      anon_sym_PIPE,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(219), 14,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_RBRACK,
  [2450] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(255), 7,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_PIPE,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(253), 18,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_RBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [2492] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(259), 7,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_PIPE,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(257), 20,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [2527] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(199), 7,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_PIPE,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(197), 20,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [2562] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(263), 7,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_PIPE,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(261), 20,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [2597] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(267), 7,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_SLASH,
      anon_sym_PIPE,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(265), 20,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_RPAREN,
      anon_sym_COLON,
      anon_sym_SEMI,
      anon_sym_STAR,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_LBRACK,
      anon_sym_RBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [2632] = 20,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(269), 1,
      anon_sym_COMMA,
    ACTIONS(271), 1,
      anon_sym_RPAREN,
    STATE(18), 1,
      sym_argument_list,
    STATE(140), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [2700] = 20,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(269), 1,
      anon_sym_COMMA,
    ACTIONS(273), 1,
      anon_sym_RPAREN,
    STATE(18), 1,
      sym_argument_list,
    STATE(134), 1,
      aux_sym_argument_list_repeat1,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [2768] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
    ACTIONS(275), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [2831] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(277), 12,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
      aux_sym_preproc_include_token1,
      aux_sym_preproc_def_token1,
    ACTIONS(279), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [2864] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
    ACTIONS(281), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [2927] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(283), 12,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
      aux_sym_preproc_include_token1,
      aux_sym_preproc_def_token1,
    ACTIONS(285), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [2960] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(287), 1,
      anon_sym_COMMA,
    ACTIONS(289), 1,
      anon_sym_SEMI,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [3025] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(287), 1,
      anon_sym_COMMA,
    ACTIONS(291), 1,
      anon_sym_SEMI,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [3090] = 19,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(287), 1,
      anon_sym_COMMA,
    ACTIONS(293), 1,
      anon_sym_SEMI,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [3155] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(295), 1,
      anon_sym_RPAREN,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [3217] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(297), 1,
      anon_sym_RPAREN,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [3279] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(299), 1,
      anon_sym_COLON,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [3341] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(301), 1,
      anon_sym_SEMI,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [3403] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(303), 1,
      anon_sym_RBRACK,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [3465] = 18,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(217), 1,
      anon_sym_LPAREN,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(305), 1,
      anon_sym_RBRACK,
    STATE(18), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [3527] = 17,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(227), 1,
      anon_sym_SLASH,
    ACTIONS(237), 1,
      anon_sym_LBRACK,
    ACTIONS(241), 1,
      anon_sym_AMP,
    ACTIONS(243), 1,
      anon_sym_AMP_AMP,
    ACTIONS(245), 1,
      anon_sym_PIPE,
    ACTIONS(247), 1,
      anon_sym_CARET,
    ACTIONS(251), 1,
      anon_sym_PIPE_PIPE,
    ACTIONS(307), 1,
      anon_sym_LPAREN,
    STATE(23), 1,
      sym_argument_list,
    ACTIONS(223), 2,
      anon_sym_DASH,
      anon_sym_PLUS,
    ACTIONS(225), 2,
      anon_sym_STAR,
      anon_sym_PERCENT,
    ACTIONS(229), 2,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
    ACTIONS(231), 2,
      anon_sym_GT,
      anon_sym_LT,
    ACTIONS(233), 2,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
    ACTIONS(235), 2,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
    ACTIONS(239), 2,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [3586] = 3,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(211), 1,
      anon_sym_LF,
    ACTIONS(199), 22,
      anon_sym_LPAREN,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_LBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [3617] = 3,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(265), 1,
      anon_sym_LF,
    ACTIONS(267), 22,
      anon_sym_LPAREN,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_LBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [3648] = 3,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(257), 1,
      anon_sym_LF,
    ACTIONS(259), 22,
      anon_sym_LPAREN,
      anon_sym_AMP,
      anon_sym_DASH,
      anon_sym_PLUS,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_PIPE_PIPE,
      anon_sym_AMP_AMP,
      anon_sym_PIPE,
      anon_sym_CARET,
      anon_sym_EQ_EQ,
      anon_sym_BANG_EQ,
      anon_sym_GT,
      anon_sym_GT_EQ,
      anon_sym_LT_EQ,
      anon_sym_LT,
      anon_sym_LT_LT,
      anon_sym_GT_GT,
      anon_sym_LBRACK,
      anon_sym_DASH_DASH,
      anon_sym_PLUS_PLUS,
  [3679] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(311), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(309), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [3709] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(315), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(313), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [3739] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(319), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(317), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [3769] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(319), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(317), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [3799] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(323), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(321), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [3829] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(327), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(325), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [3859] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(331), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(329), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [3889] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(335), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(333), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [3919] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(339), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(337), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [3949] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(343), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(341), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [3979] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(347), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(345), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [4009] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(353), 1,
      anon_sym_else,
    ACTIONS(351), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(349), 12,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [4041] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(357), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(355), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [4071] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(361), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(359), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [4101] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(365), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(363), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [4131] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(369), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(367), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [4161] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(331), 9,
      anon_sym_LBRACE,
      anon_sym_RBRACE,
      anon_sym_LPAREN,
      anon_sym_SEMI,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
      sym_number_literal,
      anon_sym_DQUOTE,
    ACTIONS(329), 13,
      anon_sym_while,
      anon_sym_case,
      anon_sym_default,
      anon_sym_break,
      anon_sym_continue,
      anon_sym_goto,
      anon_sym_switch,
      anon_sym_if,
      anon_sym_else,
      anon_sym_for,
      anon_sym_return,
      sym_identifier,
      sym_primitive_type,
  [4191] = 12,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    ACTIONS(373), 1,
      anon_sym_SEMI,
    STATE(49), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(161), 1,
      sym_comma_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4235] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    ACTIONS(375), 1,
      anon_sym_RPAREN,
    STATE(43), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4276] = 13,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(377), 1,
      sym_identifier,
    ACTIONS(379), 1,
      anon_sym_DQUOTE,
    ACTIONS(381), 1,
      sym_system_lib_string,
    STATE(19), 1,
      sym_subscript_expression,
    STATE(24), 1,
      sym_call_expression,
    STATE(58), 1,
      sym__expression,
    STATE(59), 1,
      sym_string_literal,
    STATE(106), 1,
      sym_parenthesized_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 4,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
  [4321] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(51), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(159), 1,
      sym_comma_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4362] = 11,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    ACTIONS(383), 1,
      anon_sym_RPAREN,
    STATE(44), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4403] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(37), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4441] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(34), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4479] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(54), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4517] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(56), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4555] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(45), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4593] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(33), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4631] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(53), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4669] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(47), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4707] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(57), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4745] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(36), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4783] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(35), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4821] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(52), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4859] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(32), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4897] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(55), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4935] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(31), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [4973] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(30), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [5011] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(29), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [5049] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(28), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [5087] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(38), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [5125] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    ACTIONS(45), 1,
      sym_number_literal,
    ACTIONS(47), 1,
      anon_sym_DQUOTE,
    ACTIONS(371), 1,
      sym_identifier,
    STATE(27), 1,
      sym__expression,
    STATE(106), 1,
      sym_parenthesized_expression,
    STATE(19), 2,
      sym_call_expression,
      sym_subscript_expression,
    ACTIONS(41), 3,
      anon_sym_BANG,
      anon_sym_DASH,
      anon_sym_PLUS,
    STATE(40), 5,
      sym_unary_expression,
      sym_binary_expression,
      sym_assignment_expression,
      sym_update_expression,
      sym_string_literal,
  [5163] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(11), 1,
      aux_sym_preproc_include_token1,
    ACTIONS(13), 1,
      aux_sym_preproc_def_token1,
    ACTIONS(15), 1,
      sym_primitive_type,
    ACTIONS(385), 1,
      ts_builtin_sym_end,
    STATE(131), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(105), 5,
      sym_function_definition,
      sym_compound_statement,
      sym_preproc_include,
      sym_preproc_def,
      aux_sym_source_file_repeat1,
  [5198] = 10,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(387), 1,
      ts_builtin_sym_end,
    ACTIONS(389), 1,
      sym_identifier,
    ACTIONS(392), 1,
      anon_sym_LBRACE,
    ACTIONS(395), 1,
      aux_sym_preproc_include_token1,
    ACTIONS(398), 1,
      aux_sym_preproc_def_token1,
    ACTIONS(401), 1,
      sym_primitive_type,
    STATE(131), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(105), 5,
      sym_function_definition,
      sym_compound_statement,
      sym_preproc_include,
      sym_preproc_def,
      aux_sym_source_file_repeat1,
  [5233] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(203), 9,
      anon_sym_EQ,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_AMP_EQ,
      anon_sym_CARET_EQ,
      anon_sym_PIPE_EQ,
  [5248] = 8,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(404), 1,
      anon_sym_LPAREN,
    ACTIONS(406), 1,
      anon_sym_COMMA,
    ACTIONS(408), 1,
      anon_sym_SEMI,
    ACTIONS(410), 1,
      anon_sym_EQ,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    STATE(115), 1,
      sym_parameter_list,
    STATE(139), 1,
      aux_sym_declaration_repeat1,
  [5273] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(416), 1,
      sym_primitive_type,
    ACTIONS(414), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      sym_identifier,
      aux_sym_preproc_include_token1,
      aux_sym_preproc_def_token1,
  [5287] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(420), 1,
      sym_primitive_type,
    ACTIONS(418), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      sym_identifier,
      aux_sym_preproc_include_token1,
      aux_sym_preproc_def_token1,
  [5301] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(422), 6,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_LBRACK,
  [5313] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(426), 1,
      sym_primitive_type,
    ACTIONS(424), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      sym_identifier,
      aux_sym_preproc_include_token1,
      aux_sym_preproc_def_token1,
  [5327] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(428), 6,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_LBRACK,
  [5339] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(430), 6,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_LBRACK,
  [5351] = 7,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(15), 1,
      sym_primitive_type,
    ACTIONS(432), 1,
      anon_sym_RPAREN,
    STATE(132), 1,
      sym_parameter_declaration,
    STATE(141), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
  [5373] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(434), 6,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_LBRACK,
  [5385] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(404), 1,
      anon_sym_LPAREN,
    ACTIONS(410), 1,
      anon_sym_EQ,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    STATE(115), 1,
      sym_parameter_list,
    ACTIONS(436), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [5405] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(438), 6,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_LBRACK,
  [5417] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(440), 6,
      anon_sym_LBRACE,
      anon_sym_LPAREN,
      anon_sym_COMMA,
      anon_sym_SEMI,
      anon_sym_EQ,
      anon_sym_LBRACK,
  [5429] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(444), 1,
      sym_primitive_type,
    ACTIONS(442), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACE,
      sym_identifier,
      aux_sym_preproc_include_token1,
      aux_sym_preproc_def_token1,
  [5443] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(15), 1,
      sym_primitive_type,
    STATE(141), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
    STATE(154), 1,
      sym_parameter_declaration,
  [5462] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(446), 1,
      sym_identifier,
    STATE(116), 1,
      sym__declarator,
    STATE(143), 1,
      sym_init_declarator,
    STATE(117), 2,
      sym_array_declarator,
      sym_function_declarator,
  [5479] = 5,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(446), 1,
      sym_identifier,
    STATE(107), 1,
      sym__declarator,
    STATE(133), 1,
      sym_init_declarator,
    STATE(117), 2,
      sym_array_declarator,
      sym_function_declarator,
  [5496] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(15), 1,
      sym_primitive_type,
    STATE(97), 1,
      sym_declaration,
    STATE(122), 1,
      sym__declaration_specifiers,
    STATE(150), 1,
      sym__type_specifier,
  [5515] = 6,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(448), 1,
      sym_number_literal,
    ACTIONS(450), 1,
      anon_sym_DQUOTE,
    ACTIONS(452), 1,
      anon_sym_LF,
    STATE(157), 1,
      sym_string_literal,
    STATE(162), 1,
      sym_preproc_arg,
  [5534] = 6,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    ACTIONS(404), 1,
      anon_sym_LPAREN,
    ACTIONS(412), 1,
      anon_sym_LBRACK,
    STATE(109), 1,
      sym_compound_statement,
    STATE(115), 1,
      sym_parameter_list,
  [5553] = 5,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(454), 1,
      anon_sym_DQUOTE,
    ACTIONS(456), 1,
      aux_sym_string_literal_token1,
    ACTIONS(458), 1,
      sym_escape_sequence,
    STATE(130), 1,
      aux_sym_string_literal_repeat1,
  [5569] = 5,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(456), 1,
      aux_sym_string_literal_token1,
    ACTIONS(458), 1,
      sym_escape_sequence,
    ACTIONS(460), 1,
      anon_sym_DQUOTE,
    STATE(130), 1,
      aux_sym_string_literal_repeat1,
  [5585] = 5,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(462), 1,
      anon_sym_DQUOTE,
    ACTIONS(464), 1,
      aux_sym_string_literal_token1,
    ACTIONS(466), 1,
      sym_escape_sequence,
    STATE(127), 1,
      aux_sym_string_literal_repeat1,
  [5601] = 5,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(468), 1,
      anon_sym_DQUOTE,
    ACTIONS(470), 1,
      aux_sym_string_literal_token1,
    ACTIONS(472), 1,
      sym_escape_sequence,
    STATE(126), 1,
      aux_sym_string_literal_repeat1,
  [5617] = 5,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(474), 1,
      anon_sym_DQUOTE,
    ACTIONS(476), 1,
      aux_sym_string_literal_token1,
    ACTIONS(479), 1,
      sym_escape_sequence,
    STATE(130), 1,
      aux_sym_string_literal_repeat1,
  [5633] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(446), 1,
      sym_identifier,
    STATE(125), 1,
      sym__declarator,
    STATE(117), 2,
      sym_array_declarator,
      sym_function_declarator,
  [5647] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(482), 1,
      anon_sym_COMMA,
    ACTIONS(484), 1,
      anon_sym_RPAREN,
    STATE(142), 1,
      aux_sym_parameter_list_repeat1,
  [5660] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(406), 1,
      anon_sym_COMMA,
    ACTIONS(486), 1,
      anon_sym_SEMI,
    STATE(138), 1,
      aux_sym_declaration_repeat1,
  [5673] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(269), 1,
      anon_sym_COMMA,
    ACTIONS(488), 1,
      anon_sym_RPAREN,
    STATE(137), 1,
      aux_sym_argument_list_repeat1,
  [5686] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(490), 1,
      anon_sym_COMMA,
    ACTIONS(493), 1,
      anon_sym_SEMI,
    STATE(135), 1,
      aux_sym_declaration_repeat1,
  [5699] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(495), 1,
      anon_sym_COMMA,
    ACTIONS(498), 1,
      anon_sym_RPAREN,
    STATE(136), 1,
      aux_sym_parameter_list_repeat1,
  [5712] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(275), 1,
      anon_sym_RPAREN,
    ACTIONS(500), 1,
      anon_sym_COMMA,
    STATE(137), 1,
      aux_sym_argument_list_repeat1,
  [5725] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(406), 1,
      anon_sym_COMMA,
    ACTIONS(503), 1,
      anon_sym_SEMI,
    STATE(135), 1,
      aux_sym_declaration_repeat1,
  [5738] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(406), 1,
      anon_sym_COMMA,
    ACTIONS(505), 1,
      anon_sym_SEMI,
    STATE(135), 1,
      aux_sym_declaration_repeat1,
  [5751] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(269), 1,
      anon_sym_COMMA,
    ACTIONS(507), 1,
      anon_sym_RPAREN,
    STATE(137), 1,
      aux_sym_argument_list_repeat1,
  [5764] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(509), 1,
      sym_identifier,
    ACTIONS(511), 1,
      anon_sym_AMP,
    STATE(147), 1,
      sym_pointer_declarator,
  [5777] = 4,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(482), 1,
      anon_sym_COMMA,
    ACTIONS(513), 1,
      anon_sym_RPAREN,
    STATE(136), 1,
      aux_sym_parameter_list_repeat1,
  [5790] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(436), 2,
      anon_sym_COMMA,
      anon_sym_SEMI,
  [5798] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(515), 2,
      anon_sym_AMP,
      sym_identifier,
  [5806] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    STATE(13), 1,
      sym_parenthesized_expression,
  [5816] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(517), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [5824] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(517), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [5832] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(9), 1,
      anon_sym_LBRACE,
    STATE(74), 1,
      sym_compound_statement,
  [5842] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    STATE(148), 1,
      sym_parenthesized_expression,
  [5852] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(519), 2,
      anon_sym_AMP,
      sym_identifier,
  [5860] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(23), 1,
      anon_sym_LPAREN,
    STATE(10), 1,
      sym_parenthesized_expression,
  [5870] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(521), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [5878] = 3,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(523), 1,
      sym_identifier,
    STATE(170), 1,
      sym__statement_identifier,
  [5888] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(498), 2,
      anon_sym_COMMA,
      anon_sym_RPAREN,
  [5896] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(205), 2,
      anon_sym_AMP,
      sym_identifier,
  [5904] = 2,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(211), 1,
      anon_sym_LF,
  [5911] = 2,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(525), 1,
      anon_sym_LF,
  [5918] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(527), 1,
      anon_sym_COLON,
  [5925] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(293), 1,
      anon_sym_SEMI,
  [5932] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(207), 1,
      anon_sym_SEMI,
  [5939] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(289), 1,
      anon_sym_SEMI,
  [5946] = 2,
    ACTIONS(209), 1,
      sym_comment,
    ACTIONS(529), 1,
      anon_sym_LF,
  [5953] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(531), 1,
      anon_sym_SEMI,
  [5960] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(533), 1,
      ts_builtin_sym_end,
  [5967] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(291), 1,
      anon_sym_SEMI,
  [5974] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(535), 1,
      sym_identifier,
  [5981] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(537), 1,
      anon_sym_SEMI,
  [5988] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(539), 1,
      anon_sym_LPAREN,
  [5995] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(541), 1,
      anon_sym_COLON,
  [6002] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(543), 1,
      anon_sym_SEMI,
  [6009] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(545), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 106,
  [SMALL_STATE(4)] = 214,
  [SMALL_STATE(5)] = 322,
  [SMALL_STATE(6)] = 428,
  [SMALL_STATE(7)] = 534,
  [SMALL_STATE(8)] = 640,
  [SMALL_STATE(9)] = 748,
  [SMALL_STATE(10)] = 854,
  [SMALL_STATE(11)] = 958,
  [SMALL_STATE(12)] = 1062,
  [SMALL_STATE(13)] = 1166,
  [SMALL_STATE(14)] = 1270,
  [SMALL_STATE(15)] = 1314,
  [SMALL_STATE(16)] = 1358,
  [SMALL_STATE(17)] = 1402,
  [SMALL_STATE(18)] = 1446,
  [SMALL_STATE(19)] = 1490,
  [SMALL_STATE(20)] = 1538,
  [SMALL_STATE(21)] = 1589,
  [SMALL_STATE(22)] = 1629,
  [SMALL_STATE(23)] = 1669,
  [SMALL_STATE(24)] = 1709,
  [SMALL_STATE(25)] = 1751,
  [SMALL_STATE(26)] = 1791,
  [SMALL_STATE(27)] = 1828,
  [SMALL_STATE(28)] = 1886,
  [SMALL_STATE(29)] = 1934,
  [SMALL_STATE(30)] = 1978,
  [SMALL_STATE(31)] = 2042,
  [SMALL_STATE(32)] = 2104,
  [SMALL_STATE(33)] = 2166,
  [SMALL_STATE(34)] = 2232,
  [SMALL_STATE(35)] = 2292,
  [SMALL_STATE(36)] = 2348,
  [SMALL_STATE(37)] = 2400,
  [SMALL_STATE(38)] = 2450,
  [SMALL_STATE(39)] = 2492,
  [SMALL_STATE(40)] = 2527,
  [SMALL_STATE(41)] = 2562,
  [SMALL_STATE(42)] = 2597,
  [SMALL_STATE(43)] = 2632,
  [SMALL_STATE(44)] = 2700,
  [SMALL_STATE(45)] = 2768,
  [SMALL_STATE(46)] = 2831,
  [SMALL_STATE(47)] = 2864,
  [SMALL_STATE(48)] = 2927,
  [SMALL_STATE(49)] = 2960,
  [SMALL_STATE(50)] = 3025,
  [SMALL_STATE(51)] = 3090,
  [SMALL_STATE(52)] = 3155,
  [SMALL_STATE(53)] = 3217,
  [SMALL_STATE(54)] = 3279,
  [SMALL_STATE(55)] = 3341,
  [SMALL_STATE(56)] = 3403,
  [SMALL_STATE(57)] = 3465,
  [SMALL_STATE(58)] = 3527,
  [SMALL_STATE(59)] = 3586,
  [SMALL_STATE(60)] = 3617,
  [SMALL_STATE(61)] = 3648,
  [SMALL_STATE(62)] = 3679,
  [SMALL_STATE(63)] = 3709,
  [SMALL_STATE(64)] = 3739,
  [SMALL_STATE(65)] = 3769,
  [SMALL_STATE(66)] = 3799,
  [SMALL_STATE(67)] = 3829,
  [SMALL_STATE(68)] = 3859,
  [SMALL_STATE(69)] = 3889,
  [SMALL_STATE(70)] = 3919,
  [SMALL_STATE(71)] = 3949,
  [SMALL_STATE(72)] = 3979,
  [SMALL_STATE(73)] = 4009,
  [SMALL_STATE(74)] = 4041,
  [SMALL_STATE(75)] = 4071,
  [SMALL_STATE(76)] = 4101,
  [SMALL_STATE(77)] = 4131,
  [SMALL_STATE(78)] = 4161,
  [SMALL_STATE(79)] = 4191,
  [SMALL_STATE(80)] = 4235,
  [SMALL_STATE(81)] = 4276,
  [SMALL_STATE(82)] = 4321,
  [SMALL_STATE(83)] = 4362,
  [SMALL_STATE(84)] = 4403,
  [SMALL_STATE(85)] = 4441,
  [SMALL_STATE(86)] = 4479,
  [SMALL_STATE(87)] = 4517,
  [SMALL_STATE(88)] = 4555,
  [SMALL_STATE(89)] = 4593,
  [SMALL_STATE(90)] = 4631,
  [SMALL_STATE(91)] = 4669,
  [SMALL_STATE(92)] = 4707,
  [SMALL_STATE(93)] = 4745,
  [SMALL_STATE(94)] = 4783,
  [SMALL_STATE(95)] = 4821,
  [SMALL_STATE(96)] = 4859,
  [SMALL_STATE(97)] = 4897,
  [SMALL_STATE(98)] = 4935,
  [SMALL_STATE(99)] = 4973,
  [SMALL_STATE(100)] = 5011,
  [SMALL_STATE(101)] = 5049,
  [SMALL_STATE(102)] = 5087,
  [SMALL_STATE(103)] = 5125,
  [SMALL_STATE(104)] = 5163,
  [SMALL_STATE(105)] = 5198,
  [SMALL_STATE(106)] = 5233,
  [SMALL_STATE(107)] = 5248,
  [SMALL_STATE(108)] = 5273,
  [SMALL_STATE(109)] = 5287,
  [SMALL_STATE(110)] = 5301,
  [SMALL_STATE(111)] = 5313,
  [SMALL_STATE(112)] = 5327,
  [SMALL_STATE(113)] = 5339,
  [SMALL_STATE(114)] = 5351,
  [SMALL_STATE(115)] = 5373,
  [SMALL_STATE(116)] = 5385,
  [SMALL_STATE(117)] = 5405,
  [SMALL_STATE(118)] = 5417,
  [SMALL_STATE(119)] = 5429,
  [SMALL_STATE(120)] = 5443,
  [SMALL_STATE(121)] = 5462,
  [SMALL_STATE(122)] = 5479,
  [SMALL_STATE(123)] = 5496,
  [SMALL_STATE(124)] = 5515,
  [SMALL_STATE(125)] = 5534,
  [SMALL_STATE(126)] = 5553,
  [SMALL_STATE(127)] = 5569,
  [SMALL_STATE(128)] = 5585,
  [SMALL_STATE(129)] = 5601,
  [SMALL_STATE(130)] = 5617,
  [SMALL_STATE(131)] = 5633,
  [SMALL_STATE(132)] = 5647,
  [SMALL_STATE(133)] = 5660,
  [SMALL_STATE(134)] = 5673,
  [SMALL_STATE(135)] = 5686,
  [SMALL_STATE(136)] = 5699,
  [SMALL_STATE(137)] = 5712,
  [SMALL_STATE(138)] = 5725,
  [SMALL_STATE(139)] = 5738,
  [SMALL_STATE(140)] = 5751,
  [SMALL_STATE(141)] = 5764,
  [SMALL_STATE(142)] = 5777,
  [SMALL_STATE(143)] = 5790,
  [SMALL_STATE(144)] = 5798,
  [SMALL_STATE(145)] = 5806,
  [SMALL_STATE(146)] = 5816,
  [SMALL_STATE(147)] = 5824,
  [SMALL_STATE(148)] = 5832,
  [SMALL_STATE(149)] = 5842,
  [SMALL_STATE(150)] = 5852,
  [SMALL_STATE(151)] = 5860,
  [SMALL_STATE(152)] = 5870,
  [SMALL_STATE(153)] = 5878,
  [SMALL_STATE(154)] = 5888,
  [SMALL_STATE(155)] = 5896,
  [SMALL_STATE(156)] = 5904,
  [SMALL_STATE(157)] = 5911,
  [SMALL_STATE(158)] = 5918,
  [SMALL_STATE(159)] = 5925,
  [SMALL_STATE(160)] = 5932,
  [SMALL_STATE(161)] = 5939,
  [SMALL_STATE(162)] = 5946,
  [SMALL_STATE(163)] = 5953,
  [SMALL_STATE(164)] = 5960,
  [SMALL_STATE(165)] = 5967,
  [SMALL_STATE(166)] = 5974,
  [SMALL_STATE(167)] = 5981,
  [SMALL_STATE(168)] = 5988,
  [SMALL_STATE(169)] = 5995,
  [SMALL_STATE(170)] = 6002,
  [SMALL_STATE(171)] = 6009,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(155),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(166),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(144),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_case_statement, 4, .production_id = 13),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(151),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_case_statement, 4, .production_id = 13),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(163),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(167),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(153),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(149),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(145),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(168),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(129),
  [49] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(158),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(20),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(3),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_compound_statement_repeat1, 2),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(151),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(95),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(86),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(158),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(163),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(76),
  [81] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(167),
  [84] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(153),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(149),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(145),
  [93] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(168),
  [96] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(102),
  [99] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(79),
  [102] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(40),
  [105] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(129),
  [108] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_compound_statement_repeat1, 2), SHIFT_REPEAT(144),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_case_statement, 2),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_case_statement, 2),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_case_statement, 3, .production_id = 13),
  [117] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_case_statement, 3, .production_id = 13),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_case_statement, 3),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_case_statement, 3),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [125] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(20),
  [128] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(3),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_case_statement_repeat1, 2),
  [133] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(151),
  [136] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(95),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_case_statement_repeat1, 2),
  [141] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(163),
  [144] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(76),
  [147] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(167),
  [150] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(153),
  [153] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(149),
  [156] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(145),
  [159] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(168),
  [162] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(102),
  [165] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(79),
  [168] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(40),
  [171] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(129),
  [174] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_case_statement_repeat1, 2), SHIFT_REPEAT(144),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 3),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 3),
  [181] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_subscript_expression, 4, .production_id = 24),
  [183] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_subscript_expression, 4, .production_id = 24),
  [185] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 4),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 4),
  [189] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_argument_list, 2),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_argument_list, 2),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_call_expression, 2, .production_id = 6),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_call_expression, 2, .production_id = 6),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [199] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [201] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [203] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type_specifier, 1, .production_id = 1),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__statement_identifier, 1, .production_id = 3),
  [209] = {.entry = {.count = 1, .reusable = false}}, SHIFT_EXTRA(),
  [211] = {.entry = {.count = 1, .reusable = true}}, SHIFT(108),
  [213] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_parenthesized_expression, 3),
  [215] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parenthesized_expression, 3),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3, .production_id = 16),
  [221] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3, .production_id = 16),
  [223] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [227] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [241] = {.entry = {.count = 1, .reusable = false}}, SHIFT(103),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [245] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [247] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [249] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment_expression, 3, .production_id = 16),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [253] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2, .production_id = 4),
  [255] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2, .production_id = 4),
  [257] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 2),
  [259] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 2),
  [261] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_update_expression, 2, .production_id = 5),
  [263] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_update_expression, 2, .production_id = 5),
  [265] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string_literal, 3),
  [267] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string_literal, 3),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [275] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2),
  [277] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_compound_statement, 3),
  [279] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_compound_statement, 3),
  [281] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_init_declarator, 3, .production_id = 23),
  [283] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_compound_statement, 2),
  [285] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_compound_statement, 2),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [293] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comma_expression, 3, .production_id = 18),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [305] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [307] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [309] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression_statement, 2),
  [311] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_statement, 2),
  [313] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_labeled_statement, 2, .production_id = 7),
  [315] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_labeled_statement, 2, .production_id = 7),
  [317] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_declaration, 3, .production_id = 17),
  [319] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 3, .production_id = 17),
  [321] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_statement, 5, .production_id = 26),
  [323] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_statement, 5, .production_id = 26),
  [325] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_for_statement, 8, .production_id = 27),
  [327] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_statement, 8, .production_id = 27),
  [329] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_declaration, 4, .production_id = 21),
  [331] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declaration, 4, .production_id = 21),
  [333] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_break_statement, 2),
  [335] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_break_statement, 2),
  [337] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_return_statement, 2),
  [339] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_statement, 2),
  [341] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_statement, 3, .production_id = 12),
  [343] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_statement, 3, .production_id = 12),
  [345] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_return_statement, 3),
  [347] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return_statement, 3),
  [349] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_statement, 3, .production_id = 15),
  [351] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_statement, 3, .production_id = 15),
  [353] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [355] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_switch_statement, 3, .production_id = 12),
  [357] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_switch_statement, 3, .production_id = 12),
  [359] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_goto_statement, 3, .production_id = 14),
  [361] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_goto_statement, 3, .production_id = 14),
  [363] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_expression_statement, 1),
  [365] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression_statement, 1),
  [367] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_continue_statement, 2),
  [369] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_continue_statement, 2),
  [371] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [373] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [375] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [377] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [379] = {.entry = {.count = 1, .reusable = true}}, SHIFT(128),
  [381] = {.entry = {.count = 1, .reusable = true}}, SHIFT(156),
  [383] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [385] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [387] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [389] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(155),
  [392] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [395] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(81),
  [398] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(166),
  [401] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(144),
  [404] = {.entry = {.count = 1, .reusable = true}}, SHIFT(114),
  [406] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [408] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [410] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [412] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [414] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_preproc_include, 3, .production_id = 8),
  [416] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_preproc_include, 3, .production_id = 8),
  [418] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_definition, 3, .production_id = 10),
  [420] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_definition, 3, .production_id = 10),
  [422] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 4),
  [424] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_preproc_def, 3, .production_id = 9),
  [426] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_preproc_def, 3, .production_id = 9),
  [428] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_array_declarator, 4, .production_id = 25),
  [430] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 3),
  [432] = {.entry = {.count = 1, .reusable = true}}, SHIFT(118),
  [434] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_declarator, 2, .production_id = 11),
  [436] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, .production_id = 20),
  [438] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__declarator, 1),
  [440] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_list, 2),
  [442] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_preproc_def, 4, .production_id = 19),
  [444] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_preproc_def, 4, .production_id = 19),
  [446] = {.entry = {.count = 1, .reusable = true}}, SHIFT(117),
  [448] = {.entry = {.count = 1, .reusable = false}}, SHIFT(157),
  [450] = {.entry = {.count = 1, .reusable = false}}, SHIFT(128),
  [452] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [454] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [456] = {.entry = {.count = 1, .reusable = true}}, SHIFT(130),
  [458] = {.entry = {.count = 1, .reusable = false}}, SHIFT(130),
  [460] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [462] = {.entry = {.count = 1, .reusable = false}}, SHIFT(61),
  [464] = {.entry = {.count = 1, .reusable = true}}, SHIFT(127),
  [466] = {.entry = {.count = 1, .reusable = false}}, SHIFT(127),
  [468] = {.entry = {.count = 1, .reusable = false}}, SHIFT(39),
  [470] = {.entry = {.count = 1, .reusable = true}}, SHIFT(126),
  [472] = {.entry = {.count = 1, .reusable = false}}, SHIFT(126),
  [474] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2),
  [476] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(130),
  [479] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_string_literal_repeat1, 2), SHIFT_REPEAT(130),
  [482] = {.entry = {.count = 1, .reusable = true}}, SHIFT(120),
  [484] = {.entry = {.count = 1, .reusable = true}}, SHIFT(113),
  [486] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [488] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [490] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, .production_id = 22), SHIFT_REPEAT(121),
  [493] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_declaration_repeat1, 2, .production_id = 22),
  [495] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2), SHIFT_REPEAT(120),
  [498] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameter_list_repeat1, 2),
  [500] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_argument_list_repeat1, 2), SHIFT_REPEAT(88),
  [503] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [505] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [507] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [509] = {.entry = {.count = 1, .reusable = true}}, SHIFT(146),
  [511] = {.entry = {.count = 1, .reusable = true}}, SHIFT(171),
  [513] = {.entry = {.count = 1, .reusable = true}}, SHIFT(110),
  [515] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type_specifier, 1),
  [517] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_declaration, 2, .production_id = 17),
  [519] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__declaration_specifiers, 1, .production_id = 2),
  [521] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pointer_declarator, 2, .production_id = 20),
  [523] = {.entry = {.count = 1, .reusable = true}}, SHIFT(160),
  [525] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_preproc_arg, 1),
  [527] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [529] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [531] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [533] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [535] = {.entry = {.count = 1, .reusable = true}}, SHIFT(124),
  [537] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [539] = {.entry = {.count = 1, .reusable = true}}, SHIFT(123),
  [541] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [543] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [545] = {.entry = {.count = 1, .reusable = true}}, SHIFT(152),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_pl12d(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif