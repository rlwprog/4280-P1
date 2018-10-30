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
	
	while (state >= 0 && state < 1000){
		if (checkIfLowerCase(bufInt)){
			state = FATable[state][1];
		} else if (checkIfUpperCase(bufInt)){
			state = FATable[state][2];
		} else if (checkIfUnderScore(bufInt)){
			state = FATable[state][3];
		} else if (checkIfDigit(bufInt)){
			state = FATable[state][4];
		} else if (checkIfWhitespace(bufInt)){
			state = FATable[state][5];
		} else if (checkIfSymbol(bufInt)){
			state = FATable[state][0];
		} else if (checkIfEOF(lineBuffer[bufIndex-1], lineBuffer[bufIndex])){
			state = FATable[state][6];
		} else if (checkIfNewLine(lineBuffer[bufIndex-1], lineBuffer[bufIndex])){
			break;
		} else {	
			state = -1;
			fprintf(stderr, "Error: Unknown character: %c\n", ch);
			exit(1);
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

int checkIfUnderScore(int bInt){
	if (bInt == '_'){
		return 1;
	} else {
		return 0;
	}
}

int checkIfDigit(int bInt){
	if (isdigit(bInt) != 0){
		return 1;
	} else {
		return 0;
	}
}

int checkIfLowerCase(int bInt){
	if (bInt >= 'a' && bInt <= 'z'){
		return 1;
	} else {
		return 0;
	}

}

int checkIfUpperCase(int bInt){
	if (bInt >= 'A' && bInt <= 'Z'){
		return 1;
	} else {
		return 0;
	}
}

int checkIfWhitespace(int bInt){
	if (bInt == ' ' || bInt == '\t' || bInt == '\n' || bInt == 10){
		return 1;
	} else {
		return 0;
	}
}

int checkIfSymbol(int bInt){
	int i;
	for (i = 0; i < 18; i++){
		if(bInt == opsAndDelimiters[i]){
			return 1;
		} 
	} 
	return 0;
}

int checkIfEOF(int lastChar, int currChar){
	if (currChar == 0 && lastChar != 10){
		return 1;
	}
	return 0;

}

int checkIfNewLine(int lastChar, int currChar){
	if (currChar == 0 && lastChar == 10){
		return 1;
	}
	return 0;}
