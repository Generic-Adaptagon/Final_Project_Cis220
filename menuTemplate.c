
/* THIS IS A TEMPLATE, ONLY COPY DO NOT USE - Ivan */

# include <stdio.h>
# define FLUSH while (getchar() != '\n')

void MenuTemplate () { // FIXME change function name

int choice = 0; // for the user's choice


enum CHOICES {EXIT = 1};

do {
	
	printf("Menu: make a choice:\n");
	printf("1. Exit Menu\n");
	printf("2. other option FIXME\n"); //FIXME options
	
	scanf (" %d", &choice);
	
	switch (choice) 
	{
		
		
		case EXIT:
			printf("Exiting [MENU HERE]\n\n");
			break; // end of EXIT
			
		default:
			printf ("\nThat is not a valid option. Please try again\n");
			FLUSH;
		
	}
	
}  while (choice != EXIT);


}//mm

