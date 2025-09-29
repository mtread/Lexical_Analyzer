/* 
 * CMSC 430 Project 1 - Lexical Analyzer
 * Author: Mackenzie Treadway
 * Date: August 26, 2025
 *
 * This file defines the lexical analyzer rules using Flex.
 * It breaks the source code into tokens for the parser.
 */

%{
#include "tokens.h"
#include "listing.h"
#include <string>
using namespace std;

int yylex();
%}

%option noyywrap

DIGIT       [0-9]
LETTER      [A-Za-z]
HEXDIGIT    [0-9A-Fa-f]
ID          {LETTER}({LETTER}|{DIGIT}|(_{1,2}(?!_)))*

%%

"--".*                      ;   // New style comment (ignore)
"//".*                      ;   // Old style comment (ignore)

/* Reserved words */
"else"          { return ELSE; }
"elsif"         { return ELSIF; }
"endfold"       { return ENDFOLD; }
"endif"         { return ENDIF; }
"fold"          { return FOLD; }
"if"            { return IF; }
"left"          { return LEFT; }
"real"          { return REAL; }
"right"         { return RIGHT; }
"then"          { return THEN; }

/* Identifiers - allow underscores but no leading/trailing and max 2 in a row */
{ID}            { return IDENTIFIER; }

/* Integer literals */
{DIGIT}+        { return INT_LITERAL; }

/* Hex integer literals */
"#"{HEXDIGIT}+  { return INT_LITERAL; }

/* Real literals (with optional exponent) */
{DIGIT}*"."{DIGIT}+([eE][+-]?{DIGIT}+)?  { return REAL_LITERAL; }

/* Character literals with escape support */
\'([^\'\\]|\\[btnrf\\\'\"])?\'    { return CHAR_LITERAL; }

/* Logical operators */
"&"             { return ANDOP; }
"|"             { return OROP; }
"!"             { return NOTOP; }

/* Relational operators */
"="             { return RELOP; }
"<>"            { return RELOP; }
">"             { return RELOP; }
">="            { return RELOP; }
"<="            { return RELOP; }
"<"             { return RELOP; }

/* Arithmetic operators */
"+"             { return ADDOP; }
"-"             { return ADDOP; }
"*"             { return MULOP; }
"/"             { return MULOP; }
"%"             { return REMOP; }
"^"             { return EXPOP; }
"~"             { return NEGOP; }

/* Punctuation */
","             { return COMMA; }
";"             { return SEMICOLON; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"=>"            { return ARROW; }

/* Whitespace */
[ \t\r\n]+      ;   // Ignore

.               { appendError(LEXICAL, "Invalid Character"); }

%%

