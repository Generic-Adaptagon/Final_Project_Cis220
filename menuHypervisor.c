# include <stdio.h>
# define FLUSH while (getchar() != '\n')

void menuHypervisor () { // FIXME change function name--------------

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

