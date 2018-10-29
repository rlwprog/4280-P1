//
//  testScanner.c
//
//  Created by Ricky Wilson on 10/26/18.
//  CS 4280
//  Project 1
//

#include <stdio.h>
#include <stdlib.h>
#include "testScanner.h"

// driver to test the scanner 
void tester(FILE *fin) {

	
	while (fgets(buffer,sizeof buffer, fin) != NULL) {
		filter(buffer);
		
	}
}