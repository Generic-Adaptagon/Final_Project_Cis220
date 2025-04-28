# include <stdio.h>
# define FLUSH while (getchar() != '\n')
#include "menuHypervisor.c"
#include "menuOS.c"
#include "menuProducts.c"
#include "menuRelatedSoftware.c"

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

