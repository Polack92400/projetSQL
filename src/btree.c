#include "btree.h"

Node* createNode(int data) {
	 
	   Node* newnode = (Node*)malloc(sizeof(Node));

	   newnode->data = data;
	   newnode->right = NULL;
	   newnode->left = NULL;
	 
	   return newnode;

   }

