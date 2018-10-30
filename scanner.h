//
//  scanner.h
//
//  Created by Ricky Wilson on 10/26/18.
//  CS 4280
//  Project 1
//


#include <stdio.h>
#include <stdlib.h>
#include "token.h"

int bufInt;
char ch;
int bufferIndex;
int length;

void filter(char *lineBuffer);

int scanner(char *lineBuffer, int bufIndex, int line);

int checkIfDigit(char ch);

int checkIfUpperCase(char ch);

int checkIfLowerCase(char ch);

int checkIfSymbol(char ch);

int checkIfWhitespace(char ch);

int checkIfUnderScore(char ch);

int checkIfIdentifierIsKeyword(char *tk);