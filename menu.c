# include <stdio.h>
# define FLUSH while (getchar() != '\n')
#include "menu.h"

void mainMenu () {


int choice = 0; // for the user's choice

/*enumerations to make adding options easy; Shortened for typing convience*/
enum CHOICES {EXIT = 1, HYPEMENU = 2, PRODMENU = 3, OSMENU = 4, RELTSOFTMENU = 5};

/*start of menu loop*/
do {
	
	/*Menu options*/
	printf("Menu: make a choice:\n");
	printf("1. Exit Menu\n");
	printf("2. Hypervisor Menu\n");
	printf("3. Products Menu\n");
	printf("4. OS Menu\n");
	printf("5. Related Software Menu\n");
	
	/*user choice*/
	scanf (" %d", &choice);
	
	/*Switch statement for  user's choice*/
	switch (choice) 
	{
		
		/*Prints exiting and the current menu*/
		case EXIT:
			printf("Exiting [MENU HERE]\n\n");
			break; // end of EXIT
			
		case HYPEMENU:
			menuHypervisor();
			break;
			
		case PRODMENU:
			menuProducts();
			break;
			
		case OSMENU:
			menuOS();
			break;
			
		case RELTSOFTMENU:
			menuRelatedSoftware();
			break;
						
		/*error message and handeling*/	
		default:
			printf ("\nThat is not a valid option. Please try again\n");
			FLUSH; // flushes buffer
		
	}
	
	/*end of menu loop*/
}  while (choice != EXIT);

} // end of Menu



/*Related Software Menu*/
void menuRelatedSoftware () { 

int choice = 0; // for the user's choice

/*enumerations to make adding options easy*/
enum CHOICES {EXIT = 1, GENERATE = 2, PRINTALL = 3};

/* start of menu*/
do {
	
	/*Menu options*/
	printf("Related Softwear Menu:\n    make a choice:\n");
	printf("1. Exit Menu\n");
	printf("2. Generate Report based on product\n"); 
	printf("3. Print all Related Softwear\n"); 
	
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
			printf("(related softaware) FIXME: I need a print all related software menu.\n");
			break;
			
		case GENERATE:
		printf("(related softaware) FIXME: I need the displayProductsUser function AND the printing function.\n");
			break;
			
		/*error message and handeling*/	
		default:
			printf ("\nThat is not a valid option. Please try again\n");
			FLUSH; // flushes buffer
		
	}
	/*only ends if the user's choice is to exit*/
}  while (choice != EXIT);

} // end of Menu
/*Products Menu*/
void menuProducts () { 

int choice = 0; // for the user's choice

/*enumerations to make adding options easy*/
enum CHOICES {EXIT = 1,  PRINTALL = 2};

/* start of menu*/
do {
	
	/*Menu options*/
	printf("Product Menu:\n    make a choice:\n");
	printf("1. Exit Menu\n");
	printf("2. Print all Menu Products\n"); 
	
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
			printf("(product Menu) FIXME: I need a print all related software menu.\n");
			break;

		/*error message and handeling*/	
		default:
			printf ("\nThat is not a valid option. Please try again\n");
			FLUSH; // flushes buffer
		
	}
	/*only ends if the user's choice is to exit*/
}  while (choice != EXIT);

} // end of Menu

/*OS Menu*/
void menuOS () { 

int choice = 0; // for the user's choice

/*enumerations to make adding options easy*/
enum CHOICES {EXIT = 1, GENERATE = 2, PRINTALL = 3};

/* start of menu*/
do {
	
	/*Menu options*/
	printf("Menu OS:\n    make a choice:\n");
	printf("1. Exit Menu\n");
	printf("2. Generate Report based on product\n"); 
	printf("3. Print all OS's\n"); 
	
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
			printf("(OS Menu) FIXME: I need a print all related software menu.\n");
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

/*Hypervisor Menu*/
void menuHypervisor () { 

int choice = 0; // for the user's choice

/*enumerations to make adding options easy*/
enum CHOICES {EXIT = 1, GENERATE = 2, PRINTALL = 3};

/* start of menu*/
do {
	
	/*Menu options*/
	printf("Hypervisor Menu:\n    make a choice:\n");
	printf("1. Exit Menu\n");
	printf("2. Generate Report based on product\n"); 
	printf("3. Print all Hypervisors\n"); 
	
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
			printf("(Hypervisor Menu) FIXME: I need a print all related software menu.\n");
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
