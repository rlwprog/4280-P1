//
//  scanner.c
//
//  Created by Ricky Wilson on 10/26/18.
//  CS 4280
//  Project 1
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
#include "table.h"

int lineNum = 1;


void filter(char *lineBuffer) {
	// printf("Enterred filter\n");
	bufferIndex = 0;
	char * bufString = lineBuffer;
	int length = strlen(bufString);
	while(bufferIndex < length){
		bufferIndex = scanner(bufString, bufferIndex, lineNum);

	}

	
	lineNum++;
}

int scanner(char *lineBuffer, int bufIndex, int line){
	
	char tokn[9] = "";
	int tokenIndex = 0;
	int state = 0;
	char tmp[2];

	bufInt = lineBuffer[bufIndex];
	ch = lineBuffer[bufIndex];
	printf("BufInt: %d\n", bufInt);
	
	while (state >= 0 && state < 1000){
		if (checkIfLowerCase(ch)){
			state = FATable[state][1];
		} else if (checkIfUpperCase(ch)){
			state = FATable[state][2];
		} else if (checkIfUnderScore(ch)){
			state = FATable[state][3];
		} else if (checkIfDigit(ch)){
			state = FATable[state][4];
		} else if (checkIfWhitespace(ch)){
			state = FATable[state][5];
		} else if (checkIfSymbol(ch)){
			state = FATable[state][0];
		} else {
			state = -1;
			fprintf(stderr, "Error: Unknown character: %c\n", ch);
			// exit(1);
		}
		
		if (state >= 0 && state < 1000){
			if (!checkIfWhitespace(ch)){	
				tmp[0] = ch;
				tokn[tokenIndex] = tmp[0];
				tokenIndex += 1;
			}
			bufIndex += 1;
			ch = lineBuffer[bufIndex];
			bufInt = lineBuffer[bufIndex];
			printf("BufInt: %d\n", bufInt);

		}
	}

	if (state >= 1000){
		if(state == 1000){
			state = checkIfIdentifierIsKeyword(tokn);
		}
		Token * tok = NULL;
		tok = tokenConstruct(state, tokn, line);
		tokenPrint(tok);
	}
	if (state == -2){
		fprintf(stderr, "Error: Can't begin ID with: %c\n", ch);
		exit(1);
	}

	return bufIndex;

}

int checkIfIdentifierIsKeyword(char *tk){
	int k;
	for(k = 0; k < 12; k++){
		if (strcmp(tk, keywordNames[k]) == 0){
			return 1002;
		}
	}
	return 1000; 
}

int checkIfUnderScore(char ch){
	if (ch == '_'){
		return 1;
	} else {
		return 0;
	}
}

int checkIfDigit(char ch){
	if (isdigit(ch) != 0){
		return 1;
	} else {
		return 0;
	}
}

int checkIfLowerCase(char ch){
	if (ch >= 'a' && ch <= 'z'){
		return 1;
	} else {
		return 0;
	}

}

int checkIfUpperCase(char ch){
	if (ch >= 'A' && ch <= 'Z'){
		return 1;
	} else {
		return 0;
	}
}

int checkIfWhitespace(char ch){
	if (ch == ' ' || ch == '\t' || ch == '\n'){
		return 1;
	} else {
		return 0;
	}
}

int checkIfSymbol(char ch){
	int i;
	for (i = 0; i < 18; i++){
		if(ch == opsAndDelimiters[i]){
			return 1;
		} 
	} 
	return 0;
}
