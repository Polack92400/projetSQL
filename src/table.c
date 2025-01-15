#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"

Table *create_table(char *name) 
{	
	Table *table = NULL;
	
	if (name==NULL){
		printf("non");
		return NULL;
	}
	if ( !(table = malloc(sizeof(Table))))
	{
		printf("Attention, impossiblar de créer la table eeeeh degats");
		exit(EXIT_FAILURE);
	}	
	table->name = NULL;
	if ( !(table->name = malloc(strlen(name)+1)))
	{
		printf("Attention, impossiblar de créer la table eeeeh degats");
		exit(EXIT_FAILURE);
	}
	strncpy(table->name, name, strlen(name));
	return table;
}
