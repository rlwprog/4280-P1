//
//  scanner.c
//
//  Created by Ricky Wilson on 3/19/18.
//  CS 4280
//  Project 1
//

#include <stdio.h>
#include <stdlib.h>
#include "scanner.h"

int lineNum = 1;


void filter(char *lineBuffer) {
	Token * tok = NULL;


	scanner(lineBuffer, sizeof(lineBuffer), lineNum);

	tok = tokenConstruct(lineNum, lineBuffer, lineNum);
	tokenPrint(tok);

	lineNum++;
}

void scanner(char *lineBuffer, int length, int line){
	i = 0;
	ch = lineBuffer[i];
	while(i < length){
		ch = lineBuffer[++i];
	}


}