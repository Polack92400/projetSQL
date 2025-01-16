#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"


Table *create_table(char *name, int column_count, char **column_names, ColumnType *column_types) {
    if (!name || column_count <= 0 || !column_names || !column_types) {
        fprintf(stderr, "Invalid table creation parameters\n");
        return NULL;
    }

    Table *table = (Table *)malloc(sizeof(Table));
    if (!table) {
        fprintf(stderr, "Memory allocation failed for Table\n");
        exit(EXIT_FAILURE);
    }

    table->name = strdup(name);
    table->column_count = column_count;
    table->columns = (Column **)malloc(sizeof(Column *) * column_count);
    if (!table->columns) {
        fprintf(stderr, "Memory allocation failed for Columns\n");
        free(table);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < column_count; i++) {
        table->columns[i] = create_column(column_names[i], column_types[i]);
    }

    return table;
}

Column *create_column(char *name, ColumnType type) {
    Column *column = (Column *)malloc(sizeof(Column));
    if (!column) {
        fprintf(stderr, "Memory allocation failed for Column\n");
        exit(EXIT_FAILURE);
    }
    column->name = strdup(name);
    column->type = type;
    column->root = NULL;
    return column;
}


