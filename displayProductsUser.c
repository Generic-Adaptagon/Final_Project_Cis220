// Products - Ana

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "displayProductsUser.h"
#include "codeParse.h"
#include "menu.h"

# define FLUSH while (getchar() != '\n')

// gcc main.c menu.c codeParse.c displayProductsUser.c printers.c
// menu calls though this "void menuProducts (struct Product* productLL)"

	/* =============================================================
userSkip
this function returns true if the user input is the same as the exit input
returns false if thethe input is not set to the exit string

=============================================================*/
int userSkip(char userInput[]){
	int ptrue = 1;
	int pfalse = 0;
	
	if (strcmp(userInput, "exit") == 0 || strcmp(userInput, "Exit") == 0) { // note to self, has to be set to 0 because of the way string compare works 0 = matches
			return ptrue;
		}
		
	return pfalse;
}
/* =============================================================
displayProducts menu
returns the product node if user selected something
returns NULL if user exited menu // as per Ana's request to exit printing function

=============================================================*/
struct Product* displayProductsUser(struct Product* p) {
	Product* currentProduct;
	Product* check = NULL;
	
	currentProduct = p;
	
	printf("\n");
	printf("ID   Name \t\t\t\t\t       Version\n");
	printf("---------------------------------------------------------------\n");
	while (currentProduct != NULL) {
		printf("%-5s%-50s%5s \n", currentProduct->id, currentProduct->name, currentProduct->version);
		currentProduct = currentProduct->next;
	}


/* Section that inputs user's choice and returns it */
	char userChoice[10];
	Product product;
	Software software;
	
	printf("\nPlease enter the ID of product choice - Example:[P1]\nIf you wish to exit type \"exit\"\nProduct:");
	scanf("%s", userChoice);
	
	
/*check if user wishes to skip*/
		if (userSkip(userChoice)) {
			printf("Exiting Selection\n");
			return NULL;
		}
	
	check = ListSearch(p, userChoice);
	
	if (check == NULL) { // if errors
		do {
			flush_input( );
			
			printf("\n---------------------------------------------------------------\n\nUh oh! Invalid ID.\n\nPlease enter 'P' and the number of product choice ~ Example:[P1]\nIf you wish to exit type \"exit\"\n");
			// printf("\n\t\t\t\t-or-\n\nEnter 'r' to return to \"Related Software Menu\"\n");
			printf("\nChoice: ");
			scanf("%s", userChoice);
			
			/*if (strcmp(userChoice, "r") == 0) {
				menuRelatedSoftware(&software, &product); 		// FIX: When called does NOT display product node datas AHHHH
			} */
			
		/*returns NULL to escape from product selection*/
		/*check if user wishes to skip*/
		if (userSkip(userChoice)) {
			printf("Exiting Selection\n");
			return NULL;
		}


			check = ListSearch(p, userChoice);
			
		} while (check == NULL);
		// this is the end and only exits if (check = ListSearch) returns != NULL
	}
	return check;
}

// Function searches for a node with a specific data value, pseudocode found in PA 4.3.1 
struct Product* ListSearch(struct Product* p, char* userChoice) {
    struct Product* currProd = p;
	int i;
	
    while (currProd != NULL) {
		for (i = 0; userChoice[i] != '\0'; i++) {
		userChoice[i] = toupper(userChoice[i]);
		}
        if (strcmp(currProd->id, userChoice) == 0) {
            return currProd;
        }
        currProd = currProd->next;
    }
    return NULL;
}

// Function flushes input to prevent loop bugs
void flush_input( ) {
	int check;
	while ((check = getchar( )) != '\n' && check != EOF);
}

