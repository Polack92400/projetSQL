#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

Node *create_node(void *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed for Node\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_row(Node **root, void *data, int (*compare)(void *, void *)) {
    if (!root || !data || !compare) {
        fprintf(stderr, "Invalid parameters for insert_row\n");
        return;
    }

    if (*root == NULL) {
        *root = create_node(data);
        return;
    }

    if (compare(data, (*root)->data) < 0) {
        insert_row(&(*root)->left, data, compare);
    } else {
        insert_row(&(*root)->right, data, compare);
    }
}

void inorderTraversal(Node* root)
{
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

Node* search(Node* root, int data)
{
    if (root == NULL) {
        return NULL;
    }

    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        temp = queue[++front];

        if (temp->data == data) {
            return temp;
        }

        if (temp->left != NULL) {
            queue[++rear] = temp->left;
        }

        if (temp->right != NULL) {
            queue[++rear] = temp->right;
        }
    }
    return NULL;

}

