#include <stdio.h>
#include <stdlib.h>
#include "repl.c"
#include <stdbool.h>
#include <string.h>


int main(int argc, char* argv[], char* envp[]){
  printf("\nWelcome to mini-sql CLI\n--------------------\nIf you get lost, write .help and hit enter\n\n");

  repl();
  return 0;
  
}
