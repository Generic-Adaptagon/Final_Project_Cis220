# include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define FLUSH while (getchar() != '\n')
#include "menu.h"
#include "codeParse.h"
#include "printers.h"
#include "displayProductsUser.h"

/* =============================================================
Menu display
	This function displays a menu header given the menu name and prompts the user
=============================================================*/

void menuDisplay(char menuName[]) {
	
	char menuHeader[20];
	int length = 0; // for length for string 
	int count = 0; // counting var
	
	/*copies the menu name into the menu header*/
	strcpy(menuHeader, menuName);
	/*concatinates " menu"*/
	strcat(menuHeader, " Menu");
	
	/*gets length*/
	length = strlen(menuHeader);

	/*prints out the menu header as triple the length of the menu string*/
	for (count = 1; count < length * 3; count++) {
		printf("=");
	}
	printf("\n");
	
	/*prints out the menu spacing so that menu name appears in the middle*/
	for (count = 1; count < length ; count++) {
		printf(" ");
	}
		// print menu
	printf("%s\n", menuHeader); 

	/*prints out the menu Footer as triple the length of the menu string*/
	for (count = 1; count < length * 3; count++) {
		printf("=");
	}
	printf("\n");
	
	/*prompts user*/
	printf("Select an Option: \n");
	
}

/* =============================================================
Main Menu
 this is the main menu. It branches out to all the other menus and functions. This can be considered the
 central hub
=============================================================*/

void mainMenu (struct OS* osLL, struct Hypervisor* hvLL, struct Software * sLL,  struct Product* pLL) {

int choice = 0; // for the user's choice

/*enumerations to make adding options easy; Shortened for typing convience*/
enum CHOICES {EXIT = 5, HYPEMENU = 1, PRODMENU = 4, OSMENU = 2, RELTSOFTMENU = 3};

/*start of menu loop*/
do {
	
	/*Menu options*/
	/*dispaly Menu title and prompt user*/
	menuDisplay("Main");
	printf("1. Hypervisor Menu\n");
	printf("2. OS Menu\n");
	printf("3. Related Software Menu\n");
	printf("4. Products Menu\n");
	printf("5. Exit Program\n");
	
	/*user choice*/
	scanf (" %d", &choice);
	
	/*Switch statement for  user's choice*/
	switch (choice) 
	{
		
		/*Prints exiting and the current menu*/
		case EXIT:
			printf("Exiting Program\nThanks for Using!\n\n");
			break; // end of EXIT
			
			/*go to hypervisor menu*/
		case HYPEMENU:
			menuHypervisor(hvLL, pLL);
			break;
			
			/*go to Product menu*/
		case PRODMENU:
			menuProducts(pLL);
			break;
			
			/*go to Operating System menu*/
		case OSMENU:
			menuOS(osLL, pLL);
			break;
			
			/*go to Related Software menu*/
		case RELTSOFTMENU:
			menuRelatedSoftware(sLL, pLL);
			break;
						
		/*error message and handeling*/	
		default:
			printf ("\nThat is not a valid option. Please try again\n");
			FLUSH; // flushes buffer
		
	}
	
	/*end of menu loop*/
}  while (choice != EXIT);

} // end of Menu

/* =============================================================
Related software Menu
=============================================================*/
void menuRelatedSoftware (struct Software* sLL, struct Product* pLL) { 

int choice = 0; // for the user's choice
struct Product* userChoice= malloc(sizeof(Product)); // users choice

/*enumerations to make adding options easy*/
enum CHOICES {EXIT = 3, GENERATE = 1, PRINTALL = 2};

/* start of menu*/
do {
	
	/*Menu options*/
	printf("\n"); //spacer
	/*dispaly Menu title and prompt user*/
	menuDisplay("Related Software");
	printf("1. Generate Report based on product\n");
	printf("2. Display all Related Software\n"); 		
	printf("3. Exit Menu\n");
	
	/*user choice*/
	scanf (" %d", &choice);
	
	/*Switch statement for  user's choice*/
	switch (choice) 
	{
	
		/*Prints exiting and the current menu*/
		case EXIT:
			printf("Exiting Related Softwear Menu\n\n");
			break; // end of EXIT
		
		/*print all products*/
		case PRINTALL:
			printAllSoft(sLL);
			break;
			
		/*print software based on user choice*/
		case GENERATE:
			printProductSoft (sLL, pLL);
			break;
			
		/*error message and handeling*/	
		default:
			printf ("\nThat is not a valid option. Please try again\n");
			FLUSH; // flushes buffer
		
	}
	/*only ends if the user's choice is to exit*/
}  while (choice != EXIT);

} // end of Menu

/* =============================================================
Products Menu
=============================================================*/
void menuProducts (struct Product* productLL) { 

int choice = 0; // for the user's choice

/*enumerations to make adding options easy*/
enum CHOICES {EXIT = 2,  PRINTALL = 1};

/* start of menu*/
do {
	
	/*Menu options*/
	printf("\n"); //spacer
	/*dispaly Menu title and prompt user*/
	menuDisplay("Product");
	printf("1. Display all Menu Products\n"); 
	printf("2. Exit Menu\n");
	
	/*user choice*/
	scanf (" %d", &choice);
	
	/*Switch statement for  user's choice*/
	switch (choice) 
	{
		
		/*Prints exiting and the current menu*/
		case EXIT:
			printf("Exiting Products Menu\n\n");
			break; // end of EXIT

		/*print all products*/		
		case PRINTALL:
			printAllProduct(productLL);
			break;

		/*error message and handeling*/	
		default:
			printf ("\nThat is not a valid option. Please try again\n");
			FLUSH; // flushes buffer
		
	}
	/*only ends if the user's choice is to exit*/
}  while (choice != EXIT);

} // end of Menu
/* =============================================================
OS Menu
=============================================================*/
/*OS Menu*/
void menuOS (struct OS* os, struct Product* pLL){ 

int choice = 0; // for the user's choice

/*enumerations to make adding options easy*/
enum CHOICES {EXIT = 3, GENERATE = 1, PRINTALL = 2};

/* start of menu*/
do {
	
	/*Menu options*/
	printf("\n"); //spacer
	/*dispaly Menu title and prompt user*/
	menuDisplay("OS");
	printf("1. Generate Report based on product\n"); 
	printf("2. Display all OS's\n"); 
	printf("3. Exit Menu\n");
	
	/*user choice*/
	scanf (" %d", &choice);
	
	/*Switch statement for  user's choice*/
	switch (choice) 
	{
		
		/*Prints exiting and the current menu*/
		case EXIT:
			printf("Exiting OS Menu\n\n");
			break; // end of EXIT
		
		/*prints all Operating systems*/
		case PRINTALL:
			printAllOs(os);
			break;
			
		/*print Operating systems based on user choice*/
		case GENERATE:
			printProductOs (os, pLL);		
			break;
			
		/*error message and handeling*/	
		default:
			printf ("\nThat is not a valid option. Please try again\n");
			FLUSH; // flushes buffer
		
	}
	/*only ends if the user's choice is to exit*/
}  while (choice != EXIT);

} // end of Menu
/* =============================================================
Hypervisor Menu
=============================================================*/

void menuHypervisor (struct Hypervisor* hvLL, struct Product* pLL) { 

int choice = 0; // for the user's choice

/*enumerations to make adding options easy*/
enum CHOICES {EXIT = 3, GENERATE = 1, PRINTALL = 2};

/* start of menu*/
do {
	
	/*Menu options*/
	printf("\n"); //spacer
	/*dispaly Menu title and prompt user*/
	menuDisplay("Hypervisor");
	printf("1. Generate Report based on product\n"); 
	printf("2. Display all Hypervisors\n"); 
	printf("3. Exit Menu\n");
	
	/*user choice*/
	scanf (" %d", &choice);
	
	/*Switch statement for  user's choice*/
	switch (choice) 
	{
		
		/*Prints exiting and the current menu*/
		case EXIT:
			printf("Exiting Hypervisor Menu\n\n");
			break; // end of EXIT
		
		/*print ALL hypervisors*/
		case PRINTALL:
			printAllHype(hvLL);
			break;
			
			/*print Hypervisros based on the user's choice*/
		case GENERATE:
			printProductHype (hvLL, pLL);
			break;
			
		/*error message and handeling*/	
		default:
			printf ("\nThat is not a valid option. Please try again\n");
			FLUSH; // flushes buffer
		
	}
	/*only ends if the user's choice is to exit*/
}  while (choice != EXIT);

} // end of Menu
