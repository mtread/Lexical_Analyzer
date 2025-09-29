/* 
 * CMSC 430 Project 1 - Lexer Driver
 * Author: Mackenzie Treadway
 * Date: August 26, 2025
 *
 * This is the driver program that runs the scanner.
 */

#include <iostream>
#include "listing.h"
#include "tokens.h"
using namespace std;

int yylex();
extern char* yytext;

int main() {
    firstLine();
    int token;
    while ((token = yylex()) != 0) {
        cout << token << " " << yytext << endl;
    }
    return lastLine();
}
