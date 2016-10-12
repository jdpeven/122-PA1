#include "functions.h"

/*
Assignment: Assignment #1: Grocery Store 

Description: This program draws upon several concepts that were covered in CptS 121 and should serve as a 
good refresher for CptS 122.  Our store, Cougar Mart, maintains its inventory in a text file.  
Not being very tech savvy, the owner of Cougar Mart needs you to build a C program to read from and maintain 
the list of currently stocked items.  The program will also simulate a simple shopping cart in which customers 
may add items.   

Author: Jackson David Peven
Completion Time:

In completing this program, I received help from the following people:
I saw a comment by Kayl Coulston posted on osbide which helped my understand a problem I was having
*/
int main(void)
{
	FILE* infile = NULL, *outfile = NULL;
	int money = 0, total_money = 0;
	Inventory apples = {0,0}, milk = {0,0}, bread = {0,0}, candy = {0,0}, cheese = {0,0}, oranges = {0,0}, cherries = {0,0};
	char temp = '\0';
	char cont = '\0';
	char purchase[10];
	int i = 0, k = 0;
	char* bought[20] = {NULL};
	int valid_option = 0;

	infile = fopen("grocery_list.txt", "r");

	read_file(infile, &apples);
	read_file(infile, &milk);
	read_file(infile, &bread); 
	read_file(infile, &candy);
	read_file(infile, &cheese);
	read_file(infile, &oranges);
	read_file(infile, &cherries);

	do
	{
		money = 0;
		system("cls");
		printf("Welcome to Cougar Mart!\n\n");
		printf("How much money do you have?\n");
		scanf("%d", &money);
		/*if(scanf("%d%c", &money, &term) != 2 || term != '\n')
		{
			printf("Invalid input, please try again\n");
			system("pause");
			money = -1;
		}*/
	}while(money < 0);
	total_money = money;

	do{
		do{
		i++;
		system("cls");
		valid_option = 0;
		printf("Here's what we have in stock today:\n");
		if(apples.supply > 0){
			printf("*** apples     $%d     (qty: %d)\n", apples.cost, apples.supply);}
		if(milk.supply > 0){
			printf("*** milk       $%d     (qty: %d)\n", milk.cost, milk.supply);}
		if(bread.supply > 0){
			printf("*** bread      $%d     (qty: %d)\n", bread.cost, bread.supply);}
		if(candy.supply > 0){
			printf("*** candy      $%d     (qty: %d)\n", candy.cost, candy.supply);}
		if(cheese.supply > 0){
			printf("*** cheese     $%d     (qty: %d)\n", cheese.cost, cheese.supply);}
		if(oranges.supply > 0){
			printf("*** oranges    $%d     (qty: %d)\n", oranges.cost, oranges.supply);}
		if(cherries.supply > 0){
			printf("*** cherries   $%d     (qty: %d)\n\n", cherries.cost, cherries.supply);}
		 
		printf("You have $%d\n", money);
		
		printf("What would you like to put into your cart: ");
		scanf("%s", &purchase);
		is_valid_option(&valid_option, purchase);
		if(valid_option == 1)
		{
			printf("Please choose a valid product\n");
			i--;
			system("pause");
		}
		if(strcmp("apples", purchase) == 0)
		{
			if(money >= apples.cost)
			{
				apples.supply -=1;
				money -= apples.cost;
				bought[i] = "apples";
			}
			else
			{
				printf("Sorry you do not have enough money!\n");
				i -= 1;
				system("pause");
			}
		}
		if(strcmp("milk", purchase) == 0)
		{
			if(money >= milk.cost)
			{
				milk.supply -=1;
				money -= milk.cost;
				bought[i] = "milk";
			}
			else
			{
				printf("Sorry you do not have enough money!\n");
				i -= 1;
				system("pause");
			}
		}
		if(strcmp("bread", purchase) == 0)
		{
			if(money >= bread.cost)
			{
				bread.supply -=1;
				money -= bread.cost;
				bought[i] = "bread";
			}
			else
			{
				printf("Sorry you do not have enough money!\n");
				i -= 1;
				system("pause");			
			}
		}
		if(strcmp("candy", purchase) == 0)
		{
			if(money >= candy.cost)
			{
				candy.supply -=1;
				money -= candy.cost;
				bought[i] = "candy";
			}
			else
			{
				printf("Sorry you do not have enough money!\n");
				i -= 1;
				system("pause");
			}
		}
		if(strcmp("cheese", purchase) == 0)
		{
			if(money >= cheese.cost)
			{
				cheese.supply -=1;
				money -= cheese.cost;
				bought[i] = "cheese";
			}
			else
			{
				printf("Sorry you do not have enough money!\n");
				i -= 1;
				system("pause");
			}
		}
		if(strcmp("oranges", purchase) == 0)
		{
			if(money >= oranges.cost)
			{
				oranges.supply -=1;
				money -= oranges.cost;
				bought[i] = "oranges";
			}
			else
			{
				printf("Sorry you do not have enough money!\n");
				i -= 1;
				system("pause");
			}
		}
		if(strcmp("cherries", purchase) == 0)
		{
			if(money >= cherries.cost)
			{
				cherries.supply -=1;
				money -= cherries.cost;
				bought[i] = "cherries";
			}
			else
			{
				printf("Sorry you do not have enough money!\n");
				i -= 1;
				system("pause");
			}
		}
		}while(valid_option == 1);
		if(money > 0)
		{
			do
			{
			printf("Would you like to continue shopping? (y/n):");
			scanf(" %c", &cont);
			if(cont != 'y' && cont != 'n')
			{
				cont = '\0';
			}
			}while(cont == '\0');
		}
		if(money == 0)
		{
			printf("You have run out of money!\n");
			system("pause");
			cont = 'n';
		}
	}while(cont != 'n' && money > 0);
	fclose(infile);
	system("cls");
	printf("You spent $%d and have $%d left over\n\n", total_money - money, money);
	printf("Here's what you've added to your shopping card\n");
	for(k = 1; k <= i; k++)
	{
		printf("* %s\n", bought[k]);
	}
	printf("Thank you come again!\n\n");
	outfile = fopen("grocery_list.txt", "w");
	print_to_file(outfile, apples, "apples");
	print_to_file(outfile, milk, "milk");
	print_to_file(outfile, bread, "bread");
	print_to_file(outfile, candy, "candy");
	print_to_file(outfile, cheese, "cheese");
	print_to_file(outfile, oranges, "oranges");
	print_to_file(outfile, cherries, "cherries");
	fclose(outfile);
	return 0;
}