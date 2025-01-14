#include <stdio.h>
#include <stdlib.h>
#include "repl.c"
#include <stdbool.h>
#include <string.h>
#include "table.c"


int main(int argc, char* argv[], char* envp[]){
  printf("\nWelcome to mini-sql CLI\n--------------------\nIf you get lost, write .help and hit enter\n\n");

  Table * table = NULL;
  table = create_table("table1");
  printf("%p\n", (void*)&table); 
  printf("%s\n", table->name);
  repl();
  return 0;
  
}
