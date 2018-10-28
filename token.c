 //
//  token.c
//
//  Created by Ricky Wilson on 10/26/18.
//  CS 4280
//  Project 1
//

#include <stdio.h>
#include <stdlib.h>

#include "token.h"

const char *tokenNames[] = {"Identifier", "Number", "Keyword", "Operator", "EOF"};
const char *keywordNames[] = {"start", "stop", "iter", "void", "var", "return", "read", "print", "program", "iff", "then", "let"};
const char *opsAndDelimiters[] = {"=", "<", ">", ":", "+", "-", "*", "/", "%", ".", "(", ")", ",", "{", "}", ";", "[", "]"};


Token * tokenConstruct(int tokenID, char *tokenName, int line)
{
	// allocates memory for both a Token's size as well as the input string
	Token * tok = malloc(sizeof(Token));
	tok -> tokenID = tokenID;
	tok -> tokenName = malloc(strlen(tokenName) + 1);
	tok -> line = line;
	strcpy(tok -> tokenName, tokenName);
	
	return tok;
}

void tokenPrint(Token *tok)
{
	printf("\nToken ID: %d\n", tok -> tokenID);
	printf("Token Name: %s\n", tok -> tokenName);
	printf("Line Number: %d\n\n", tok -> line);
}