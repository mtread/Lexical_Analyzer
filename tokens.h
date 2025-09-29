/* 
 * CMSC 430 Project 1 - Tokens Header
 * Author: Mackenzie Treadway
 * Date: August 26, 2025
 *
 * This file defines token values returned by the scanner.
 */

#ifndef TOKENS_H
#define TOKENS_H

// Reserved words
#define ELSE        270
#define ELSIF       271
#define ENDFOLD     273
#define ENDIF       272
#define FOLD        275
#define IF          277
#define LEFT        280
#define REAL        284
#define RIGHT       286
#define THEN        288

// Identifiers & Literals
#define IDENTIFIER  290
#define INT_LITERAL 291
#define REAL_LITERAL 293
#define CHAR_LITERAL 292

// Operators
#define ANDOP       262
#define OROP        263
#define NOTOP       264
#define RELOP       256
#define ADDOP       257
#define MULOP       258
#define REMOP       259
#define EXPOP       260
#define NEGOP       261

// Punctuation
#define COMMA       44
#define SEMICOLON   59
#define LPAREN      40
#define RPAREN      41
#define ARROW       265

#endif
