#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct inventory
{
	int cost;
	int supply;
} Inventory;


void read_file (FILE * infile, Inventory* product);
void is_valid_option(int * valid, char choice[10]);
void print_to_file(FILE * outfile, Inventory product, char name[10]);


#endif