#ifndef TABLE_H
#define TABLE_H

#include "btree.h"

typedef enum {
    INT, STRING, BOOLEAN, DATE, FLOAT
} ColumnType;

typedef struct {
    char *name;
    ColumnType type;
    Node *root;
} Column;

typedef struct {
    char *name;
    int column_count;
    Column **columns;
} Table;

Table *create_table(char *name, int column_count, char **column_names, ColumnType *column_types);

Column *create_column(char *name, ColumnType type);

#endif

