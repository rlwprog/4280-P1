//
//  main.c
//
//  Created by Ricky Wilson on 2/19/18.
//  CS 4280
//  Project 1
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "testScanner.h"


int main(int argc, char *argv[]){
	
	// make sure there are only zero or one arguments 
	if (argc > 2) {
		errno = 8;
		perror("Error: Too many arguments, run the program P1 with either zero or 1 argument");
		return 1;
	}
	// allocating buffer and strings to handle input fromt he file pointer
	// char buffer[100];
	// char *charBuff;
	char *infile;

	FILE * fp = stdin;


	if (argc == 2){
		
		// concatenates the strings of the first passed argument and extension ".sp18"
		infile = malloc(strlen(argv[1]) + strlen(".fs182") + 1);
		strcpy(infile, argv[1]);
		strcat(infile, ".fs182");
		fp = fopen(infile, "r");


	} 

	// gets input from input pointer and feeds one string at a time and its length to build a tree
	// while (fscanf(fp, "%s", buffer) != EOF) {
		
	// 	printf("%s", buffer);
	// }
	// while (fgets(buffer,sizeof buffer, fp) != NULL) {
		
	// 	printf("%s", buffer);
	// }
	driver(fp);
	// close the input file
	fclose(fp);
	
	return 0;
}