#include "repl.h"

InputBuffer* new_input_buffer() {
	InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
	input_buffer->buffer = NULL;
	input_buffer->buffer_length = 0;
	input_buffer->input_length = 0;

	return input_buffer;
}

void print_prompt() { printf("db > "); }

void read_input(InputBuffer* input_buffer) {
	ssize_t bytes_read =
		getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

	if (bytes_read <= 0) {
		printf("Error reading input\n");
		exit(EXIT_FAILURE);
	}

	input_buffer->input_length = bytes_read - 1;
	input_buffer->buffer[bytes_read - 1] = 0;
}

void close_input_buffer(InputBuffer* input_buffer) {
	free(input_buffer->buffer);
	free(input_buffer);
}

void display_commands() {
	printf("\n.exit -> use that to exit the prompt\nSelect -> use that to print members of the table\nInsert -> use that to insert new data into the table\nDelete -> use that to delete data from the table\n\n");
}

MetaCommandResult do_meta_command(InputBuffer* input_buffer) {
	if (strcmp(input_buffer->buffer, ".exit") == 0) {
		close_input_buffer(input_buffer);
		exit(EXIT_SUCCESS);
	} else if  (strcmp(input_buffer->buffer, ".help") == 0) {
		display_commands();
		return META_COMMAND_SUCCESS;
	}
	else {
		return META_COMMAND_UNRECOGNIZED_COMMAND;
	}
}

/*
bool check_argument(const char* argument, const Table* table) {
	if (strcmp(argument, "*") == 0) {
		printf("Argument is '*', selecting all columns.\n");
		return true;
	}

	for (int i = 0; i < table->column_count; i++) {
		if (strcmp(argument, table->columns[i]->name) == 0) {
			printf("Argument matches column: %s\n", argument);
			return true;
		}
	}

	printf("Argument '%s' is not a valid column in table '%s'.\n", argument, table->name);
	return false;
}
*/

PrepareResult prepare_statement(InputBuffer* input_buffer,
		Statement* statement) {
	if (strncmp(input_buffer->buffer, "insert", 6) == 0) {
		statement->type = STATEMENT_INSERT;
		return PREPARE_SUCCESS;
	}
	if (strncmp(input_buffer->buffer, "select", 6) == 0) {
		statement->type = STATEMENT_SELECT;
		return PREPARE_SUCCESS;
	}

	return PREPARE_UNRECOGNIZED_STATEMENT;
}


int count_arguments(InputBuffer* input_buffer) {
    char* buffer_copy = strdup(input_buffer->buffer);
    if (!buffer_copy) {
        perror("Failed to duplicate input buffer");
        exit(EXIT_FAILURE);
    }

    char* token = strtok(buffer_copy, " ,.-");
    int cpt = 0;
    while (token != NULL) {
        cpt++;
        token = strtok(NULL, " ,.-");
    }

    free(buffer_copy);
    //printf("cpt = %d\n", cpt);
    return cpt;
}

char** split(InputBuffer* input_buffer) {
    int32_t nbr_arguments = count_arguments(input_buffer);
    char** arguments = malloc(nbr_arguments * sizeof(char*));
    if (!arguments) {
        perror("Failed to allocate memory for arguments");
        exit(EXIT_FAILURE);
    }

    char* buffer_copy = strdup(input_buffer->buffer);
    if (!buffer_copy) {
        perror("Failed to duplicate input buffer");
        free(arguments);
        exit(EXIT_FAILURE);
    }

    char* token = strtok(buffer_copy, " ,.-");
    for (int i = 0; i < nbr_arguments; i++) {
        arguments[i] = strdup(token); 
        if (!arguments[i]) {
            perror("Failed to allocate memory for argument");
            for (int j = 0; j < i; j++) {
                free(arguments[j]); 
            }
            free(arguments);
            free(buffer_copy);
            exit(EXIT_FAILURE);
        }
        token = strtok(NULL, " ,.-");
    }

    free(buffer_copy); 
    return arguments;
}


/*
check_arguments_select(int nbr_arguments, char** arguments) {

	for (int i = 0; i < nbr_arguments; i++) {
		//printf("%s\n", arguments[i]);
		if (arguments[1]=="*" && arguments[2] == NULL){
			print_table()
		}

		free(arguments[i]);     }
	free(arguments); 



}
 */

void execute_statement(Statement* statement, InputBuffer* input_buffer) {
	int nbr_arguments = count_arguments(input_buffer);
	char** arguments = split(input_buffer);
	for (int i = 0; i < nbr_arguments; i++) {
		printf("%s\n", arguments[i]);
		if (strcmp(arguments[1], "*") == 0 && arguments[2] == NULL){
			//print_table()
		}

		free(arguments[i]);     }
	free(arguments); 


	switch (statement->type) {
		case (STATEMENT_INSERT):
			// TODO: Implement the INSERT command here
			break;
		case (STATEMENT_SELECT):
			// TODO: Implement the SELECT command here
			break;
	}
}

void repl(){
	InputBuffer* input_buffer = new_input_buffer();
	while (true) {
		print_prompt();
		read_input(input_buffer);
		if (input_buffer->buffer[0] == '.') {
			switch (do_meta_command(input_buffer)) {
				case (META_COMMAND_SUCCESS):
					continue;
				case (META_COMMAND_UNRECOGNIZED_COMMAND):
					printf("Unrecognized command '%s'\n", input_buffer->buffer);
					continue;
			}
		}
		Statement statement;
		switch (prepare_statement(input_buffer, &statement)) {
			case (PREPARE_SUCCESS):
				printf("recognized statement\n");
				break;
			case (PREPARE_UNRECOGNIZED_STATEMENT):
				printf("Unrecognized keyword at start of '%s'.\n",
						input_buffer->buffer);
				continue;
		}
		execute_statement(&statement, input_buffer);
		printf("Executed.\n");
	}
}

