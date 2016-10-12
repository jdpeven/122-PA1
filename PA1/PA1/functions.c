#include "functions.h"

void read_file (FILE * infile, Inventory* product)
{
	char temp = '\0';
	do
	{
		fscanf(infile, "%c", &temp);
	}while(temp != ':');
	fscanf(infile, "%d", &product->supply);
	fscanf(infile, "%c", &temp);
	fscanf(infile, "%d", &product->cost);
}

void is_valid_option(int * valid, char choice[10])
{
	if(strcmp("apples", choice) != 0 && strcmp("milk", choice) != 0 && strcmp("bread", choice) != 0 && 
			strcmp("candy", choice) != 0 && strcmp("cheese", choice) != 0 && strcmp("oranges", choice) != 0 &&
			strcmp("cherries", choice) != 0)
	{
		*valid = 1;
	}
	return;
}

void print_to_file(FILE * outfile, Inventory product, char name[10])
{
	fprintf(outfile, "%s", name);
	fprintf(outfile, "%c", ':');
	fprintf(outfile, "%d", product.supply);
	fprintf(outfile, "%c", ':');
	fprintf(outfile, "%d\n", product.cost);
}