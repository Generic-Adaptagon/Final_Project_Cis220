# include <stdio.h>
# define FLUSH while (getchar() != '\n')
#include "menu.h"
#include "codeParse.h"
#include "printers.h"
#include "displayProductsUser.h"

/* =============================================================
Main Menu
=============================================================*/

void mainMenu (struct OS* osLL, struct Hypervisor* hvLL, struct Software * sLL,  struct Product* pLL) {

int choice = 0; // for the user's choice

/*enumerations to make adding options easy; Shortened for typing convience*/
enum CHOICES {EXIT = 5, HYPEMENU = 1, PRODMENU = 2, OSMENU = 3, RELTSOFTMENU = 4};

/*start of menu loop*/
do {
	
	/*Menu options*/
	printf("Menu: make a choice:\n");
	printf("1. Hypervisor Menu\n");
	printf("2. Products Menu\n");
	printf("3. OS Menu\n");
	printf("4. Related Software Menu\n");
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
			
		case HYPEMENU:
			menuHypervisor(hvLL, pLL);
			break;
			
		case PRODMENU:
			menuProducts(pLL);
			break;
			
		case OSMENU:
			menuOS(osLL, pLL);
			break;
			
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

/*Related Software Menu*/
void menuRelatedSoftware (struct Software* sLL, struct Product* pLL) { 

int choice = 0; // for the user's choice

/*enumerations to make adding options easy*/
enum CHOICES {EXIT = 3, GENERATE = 1, PRINTALL = 2};

/* start of menu*/
do {
	
	/*Menu options*/
	printf("\n"); //spacer
	printf("Related Softwear Menu:\n    make a choice:\n");
	printf("1. Generate Report based on product\n"); 
	printf("2 Print all Related Softwear\n"); 
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
		
		case PRINTALL:
			printAllSoft(sLL);
			break;
			
		case GENERATE:
		displayProductsUser(pLL);
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
/*Products Menu*/
void menuProducts (struct Product* productLL) { 

int choice = 0; // for the user's choice

/*enumerations to make adding options easy*/
enum CHOICES {EXIT = 2,  PRINTALL = 1};

/* start of menu*/
do {
	
	/*Menu options*/
	printf("\n"); //spacer
	printf("Product Menu:\n    make a choice:\n");
	printf("1. Print all Menu Products\n"); 
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
	printf("Menu OS:\n    make a choice:\n");
	printf("1. Generate Report based on product\n"); 
	printf("2. Print all OS's\n"); 
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
		
		case PRINTALL:
			printAllOs(os);
			break;
			
		case GENERATE:
		printf("(OS Menu) FIXME: I need the displayProductsUser function AND the printing function.\n");
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
	printf("Hypervisor Menu:\n    make a choice:\n");
	printf("1. Generate Report based on product\n"); 
	printf("2. Print all Hypervisors\n"); 
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
		
		case PRINTALL:
			printAllHype(hvLL);
			break;
			
		case GENERATE:
		printf("(Hypervisor Menu) FIXME: I need the displayProductsUser function AND the printing function.\n");
			break;
			
		/*error message and handeling*/	
		default:
			printf ("\nThat is not a valid option. Please try again\n");
			FLUSH; // flushes buffer
		
	}
	/*only ends if the user's choice is to exit*/
}  while (choice != EXIT);

} // end of Menu
