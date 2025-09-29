/* 
 * CMSC 430 Project 1 - Listing Implementation
 * Author: Mackenzie Treadway
 * Date: August 26, 2025
 *
 * Implements error tracking and program listing output.
 */

#include <iostream>
#include <queue>
#include <string>
#include "listing.h"
using namespace std;

static int lineNumber;
static int lexicalErrors = 0;
static int syntaxErrors = 0;
static int semanticErrors = 0;
static queue<string> errorQueue;

void firstLine() {
    lineNumber = 1;
    cout << lineNumber << " ";
}

void nextLine() {
    lineNumber++;
    cout << endl << lineNumber << " ";
    displayErrors();
}

int lastLine() {
    cout << endl;
    displayErrors();
    if (lexicalErrors + syntaxErrors + semanticErrors > 0) {
        cout << "Lexical Errors " << lexicalErrors << endl;
        cout << "Syntax Errors " << syntaxErrors << endl;
        cout << "Semantic Errors " << semanticErrors << endl;
    } else {
        cout << "Compiled Successfully" << endl;
    }
    return lexicalErrors + syntaxErrors + semanticErrors;
}

void appendError(ErrorCategory category, const char message[]) {
    string fullMessage;
    switch(category) {
        case LEXICAL: fullMessage = "Lexical Error, "; lexicalErrors++; break;
        case SYNTAX: fullMessage = "Syntax Error, "; syntaxErrors++; break;
        case SEMANTIC: fullMessage = "Semantic Error, "; semanticErrors++; break;
    }
    fullMessage += message;
    errorQueue.push(fullMessage);
}

void displayErrors() {
    while (!errorQueue.empty()) {
        cout << endl << errorQueue.front();
        errorQueue.pop();
    }
}
