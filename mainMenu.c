# include <stdio.h>
# define FLUSH while (getchar() != '\n')

void mainMenu () {


int choice = 0; // for the user's choice

/*enumerations to make adding options easy*/
enum CHOICES {EXIT = 1};

/*start of menu loop*/
do {
	
	/*Menu options*/
	printf("Menu: make a choice:\n");
	printf("1. Exit Menu\n");
	printf("2. other option FIXME\n"); //FIXME options--------------
	
	/*user choice*/
	scanf (" %d", &choice);
	
	/*Switch statement for  user's choice*/
	switch (choice) 
	{
		
		/*Prints exiting and the current menu*/
		case EXIT:
			printf("Exiting [MENU HERE]\n\n");
			break; // end of EXIT
			
		/*error message and handeling*/	
		default:
			printf ("\nThat is not a valid option. Please try again\n");
			FLUSH; // flushes buffer
		
	}
	
	/*end of menu loop*/
}  while (choice != EXIT);

} // end of Menu

