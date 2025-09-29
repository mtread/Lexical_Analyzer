/* 
 * CMSC 430 Project 1 - Listing Header
 * Author: Mackenzie Treadway
 * Date: August 26, 2025
 *
 * Declares functions for error handling and compilation listing.
 */

#ifndef LISTING_H
#define LISTING_H

enum ErrorCategory { LEXICAL, SYNTAX, SEMANTIC };

void firstLine();
void nextLine();
int lastLine();
void appendError(ErrorCategory, const char message[]);
void displayErrors();

#endif
