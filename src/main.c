#include <stdio.h>
#include <stdlib.h>
#include "repl.c"
#include <stdbool.h>
#include <string.h>


int main(int argc, char* argv[], char* envp[]){
  printf("Welcome to mini-sql CLI\n");

  repl();
  return 0;
  
}
