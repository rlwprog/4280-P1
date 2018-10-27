//
//  testScanner.c
//
//  Created by Ricky Wilson on 3/19/18.
//  CS 4280
//  Project 1
//

#include <stdio.h>
#include <stdlib.h>
#include "testScanner.h"

// driver to test the scanner 
void driver(FILE *fin) {

	
	while (fgets(buffer,sizeof buffer, fin) != NULL) {
		filter(buffer);

		
	}
}