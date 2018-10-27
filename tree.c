//
//  tree.c
//
//  Created by Ricky Wilson on 4/1/17.
//
//  CS 2750
//  Project 2
//  Mr. Schulte

#include "tree.h"
#include <stdio.h>
#include <stdlib.h>



// A utility function to create a new BST node
TreeNode *newTreenode(int val, char *str)
{
    TreeNode *temp;
    temp = malloc(sizeof(TreeNode));
    temp->key = val;
    temp->head = malloc(sizeof(Node));
    temp->head = listInsert(NULL, str);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void traversePreorder(int lvl, TreeNode *root, FILE * fout)
{

    if (root != NULL)
    {
        fprintf(fout, "\n%d ", root->key);
        for (int i = 0; i < lvl; i++){
            fprintf(fout, "\t");
        }           
        listPrint(root->head, fout);

        traversePreorder(lvl + 1, root->left, fout);
        traversePreorder(lvl + 1, root->right, fout);
    }

}

// A utility function to do inorder traversal of BST
void traverseInorder(int lvl, TreeNode *root, FILE * fout)
{

    if (root != NULL)
    {
        traverseInorder(lvl + 1, root->left, fout);

        fprintf(fout, "%d ", root->key);           
        for (int i = 0; i < lvl; i++){
            fprintf(fout, "\t");
        }
        listPrint(root->head, fout);
        
        traverseInorder(lvl + 1, root->right, fout);
    }

    fprintf(fout, "\n");

}

// A utility function to do inorder traversal of BST
void traversePostorder(int lvl, TreeNode *root, FILE * fout)
{

    if (root != NULL)
    {
        traversePostorder(lvl + 1, root->left, fout);
        traversePostorder(lvl + 1, root->right, fout);

        fprintf(fout, "\n%d ", root->key);   
        for (int i = 0; i < lvl; i++){
            fprintf(fout, "\t");
        }    
        listPrint(root->head, fout);

    }
    
}

/* A utility function to insert a new treenode with given key in BST */
TreeNode *buildTree(TreeNode *treenode, int key, char *str)
{
    // create a new tree if tree is empty
    if (treenode == NULL)
    {
        return newTreenode(key, str);
    }
    
    // if not empty, fill the tree in the correct place after final level of recursion
    if (key < treenode->key)
    {
        treenode->left  = buildTree(treenode->left, key, str);

    }
    else if (key > treenode->key)
    {
        treenode->right = buildTree(treenode->right, key, str);

    } else {
        
        // inserts a new node with a new string if the string isn't already in the linked list
        if(!listSearch(treenode->head, str)){

            treenode->head = listInsert(treenode->head, str);

        }
    }
    
    return treenode;
}

