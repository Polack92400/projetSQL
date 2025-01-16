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

