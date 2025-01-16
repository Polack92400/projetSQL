#ifndef BTREE_H
#define BTREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int data
	struct Node* left;
	struct Node* right;
} Node;

Node * createNode(int data) {

	Node * newnode = (Node*)malloc(sizeof(Node));
	
	newnode->data = data;
	newnode->right = NULL;
	newnode->left = NULL;

	return newnode;

}

#endif
