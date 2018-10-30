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

// static enum tokenID {IDENT_tk, NUM_tk, KW_tk, OP_tk, EOF_tk};
// static const char *tokenNames[] = {"Identifier", "Number", "Keyword", "Operator", "EOF"};

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
	// printf("%d\n", IDENT_tk);
	printf("\nToken type: %s\n", tokenNames[tok ->tokenID%1000]);
	printf("Token Name: %s\n", tok -> tokenName);
	printf("Line Number: %d\n\n", tok -> line);
}