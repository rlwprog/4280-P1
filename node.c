//
//  node.c
//
//  Created by Ricky Wilson on 2/19/18.
//  CS 4280
//  Project 0
//


#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "node.h"

Node * nodeConstruct(char *newStr) 
{
	// allocates memory for both a Node's size as well as the input string
	Node * nd = malloc(sizeof(Node));
	nd -> str = malloc(strlen(newStr) + 1);
	
	strcpy(nd -> str, newStr);
	nd -> next = NULL;
	
	return nd;
}

Node * listInsert(Node * head, char *str) 
{
	
	Node * ptr = nodeConstruct(str);
	ptr -> next = head;
	return ptr;

}

bool listSearch(Node *head, char *str) 
{
	Node * ptr = head;
	while (ptr != NULL) {
		if (strcmp(str, ptr->str) == 0){
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

void listPrint(Node *head, FILE * fout)
{
	Node * current = head;

    while (current != NULL) {
    	fprintf(fout, "%s ", current->str);
    	current = current -> next;
    }
}