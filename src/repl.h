#ifndef REPL_H
#define REPL_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h>

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum { PREPARE_SUCCESS, PREPARE_UNRECOGNIZED_STATEMENT } PrepareResult;

typedef enum { STATEMENT_INSERT, STATEMENT_SELECT } StatementType;

typedef struct {
  StatementType type;
} Statement;

typedef struct {
  char* buffer;
  size_t buffer_length;
  ssize_t input_length;
} InputBuffer;

InputBuffer* new_input_buffer();

void print_prompt();

void read_input(InputBuffer* input_buffer);

void close_input_buffer(InputBuffer* input_buffer);

void display_commands();

MetaCommandResult do_meta_command(InputBuffer* input_buffer);

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);

void execute_statement(Statement* statement);

void repl(void);

#endif

