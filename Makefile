CC=gcc
CFLAGS=-o
DIR=src
OBJDIR=obj

main: $(DIR)/main.c $(DIR)/btree.c $(DIR)/repl.c
	$(CC) $(DIR)/main.c $(DIR)/btree.c $(DIR)/repl.c $(CFLAGS) program


