//
//  scanner.h
//
//  Created by Ricky Wilson on 3/19/18.
//  CS 4280
//  Project 1
//


#include <stdio.h>
#include <stdlib.h>
#include "token.h"


char ch;
int i;

void filter(char *lineBuffer);

void scanner(char *lineBuffer, int length, int line);