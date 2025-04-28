
/* THIS IS A TEMPLATE, ONLY COPY DO NOT USE - Ivan */

# include <stdio.h>
# define FLUSH while (getchar() != '\n')

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

