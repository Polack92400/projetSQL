#ifndef TABLE_H
#define TABLE_H

typedef enum {
    INT, STRING, BOOLEAN, DATE, FLOAT
} ColumnType;

typedef struct {
    char *name;
} Column;

typedef struct {
    Column *column;
    char *name;
} Table;

Table *create_table(char *name);

#endif
