#ifndef BTREE_H
#define BTREE_H

typedef struct Node {
    void *data;
    struct Node *left;
    struct Node *right;
} Node;

Node *create_node(void *data);
void insert_row(Node **root, void *data, int (*compare)(void *, void *));

#endif

