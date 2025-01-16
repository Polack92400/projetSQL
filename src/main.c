#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "repl.c"
#include "table.c"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(int argc, char* argv[], char* envp[]) {
    printf("\nWelcome to mini-sql CLI\n--------------------\nIf you get lost, write .help and hit enter\n\n");
	
	printf("This project is a one-table database architectured with a binary tree\n");
	printf("I am, first, going to walk you through the creation of the table\n");

    char table_name[50];
    printf("Choose a name for your table: ");
    scanf("%49s", table_name);
    clear_input_buffer();

    int column_count;
    printf("Enter the number of columns: ");
    scanf("%d", &column_count);
    clear_input_buffer();

    char **column_names = malloc(sizeof(char *) * column_count);
    ColumnType *column_types = malloc(sizeof(ColumnType) * column_count);

    if (!column_names || !column_types) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < column_count; i++) {

        column_names[i] = malloc(50 * sizeof(char)); 
        if (!column_names[i]) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        printf("Enter name for column %d: ", i + 1);
        scanf("%49s", column_names[i]);
        clear_input_buffer();

        printf("Enter type for column %d (Int=0, String=1, Boolean=2, Date=3, Float=4): ", i + 1);
        int type;
        scanf("%d", &type);
        clear_input_buffer();

        if (type < 0 || type > 4) {
            fprintf(stderr, "Invalid column type. Please enter a valid type.\n");
            i--;
            continue;
        }
        column_types[i] = (ColumnType)type;
    }

    Table *table = create_table(table_name, column_count, column_names, column_types);
    if (!table) {
        fprintf(stderr, "Failed to create table\n");
        exit(EXIT_FAILURE);
    }

    printf("\nTable '%s' created with %d columns.\n", table->name, table->column_count);
    for (int i = 0; i < column_count; i++) {
        printf("Column %d: Name='%s', Type=%d\n", i + 1, table->columns[i]->name, table->columns[i]->type);
    }

    for (int i = 0; i < column_count; i++) {
        free(column_names[i]);
    }
    free(column_names);
    free(column_types);

    repl();
    return 0;
}

