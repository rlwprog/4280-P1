//
//  tree.h
//
//  Created by Ricky Wilson on 2/19/18.
//  CS 4280
//  Project 0
//

#include <stdio.h>
#include "node.h"

// struct for a tree node within the bst
typedef struct treenode
{
    int key;
    struct node * head;
    struct treenode *left;
    struct treenode *right;

}TreeNode;

// function creates a new treenode for the bst
TreeNode *newTreenode(int item, char *str);

// traverses the file in preorder, at each treenode traverses each list of unique strings
void traversePreorder(int lvl, TreeNode *root, FILE * fout);

// traverses the file in order, at each treenode traverses each list of unique strings
void traverseInorder(int lvl, TreeNode *root, FILE * fout);

// traverses the file in postorder, at each treenode traverses each list of unique strings
void traversePostorder(int lvl, TreeNode *root, FILE * fout);

// builds the bst with a linked list of unique strings and a key depicting their length (all same length in a particular node)
TreeNode* buildTree(TreeNode* treenode, int key, char *str);


