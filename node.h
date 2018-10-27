//
// node.h
//
// Created by Ricky Wilson on 2/19/18.
// CS 4280
// Project 0
//

#include <stdbool.h>

//structure for a node in the linked list containing the strings within the bst
typedef struct node
{
    char *str;
    struct node *next;

} Node;

// constructs a node in the linked list
Node * nodeConstruct(char *str);

//inserts a new node into the linked list
Node * listInsert(Node *head, char *str);

// searches the linked list for a particular string and returns true if there, false if not
bool listSearch(Node *head, char *str);

// prints the linked list in order from latest to oldest
void listPrint(Node *head, FILE * fout);

