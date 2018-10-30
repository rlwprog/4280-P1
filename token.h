//
//  token.h
//
//  Created by Ricky Wilson on 10/26/18.
//  CS 4280
//  Project 1
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum tokenID {IDENT_tk, NUM_tk, KW_tk, OP_tk, EOF_tk};
static const char *tokenNames[] = {"Identifier", "Number", "Keyword", "Operator", "EOF"};
static const char *keywordNames[] = {"start", "stop", "iter", "void", "var", "return", "read", "print", "program", "iff", "then", "let"};
static char opsAndDelimiters[] = {'=', '<', '>', ':', '+', '-', '*', '/', '%', '.', '(', ')', ',', '{', '}', ';', '[', ']'};

typedef struct token
{
    int tokenID;
    char *tokenName;
    int line;

} Token;



Token * tokenConstruct(int tokenID, char *tokenName, int line);

void tokenPrint(Token *tok);

