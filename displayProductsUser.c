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
struct Product* displayProductsUser(struct Product* p) {
	Product* currentProduct;
	Product* nextProduct;
	Product* check = NULL;
	
	currentProduct = p;
	nextProduct = p;
	
	printf("\n");
	printf("-----------------------------------------------------------\n");
	while (currentProduct != NULL) {
		printf("%-5s%-5s%-6s \n", currentProduct->id, currentProduct->name, currentProduct->version);
		currentProduct = currentProduct->next;
	}
	
	
/* Section that inputs user's choice and returns it */
	char userChoice[10];

	printf("\nPlease enter the ID of product choice:   Example: [P1]\n");
	scanf("%s", userChoice);
	check = ListSearch(p, userChoice);
	if (check == NULL) {
		do {
			printf("\nPlease enter 'P' and the number of product choice:   Example[P1]:\n");
			scanf("%s", userChoice);
			
			check = ListSearch(p, userChoice);
			
			/* if (strcmp(userChoice, "r") == 0) {
				mainMenu (osHead, hypervisorHead, softwareHead, productHead);
			} */ //makes an infinite loop when going through 4, then 1 again SAD 		// I want an option where entering 'r' returns to Related Software Menu
			
		} while (check == NULL);
		// this is the end and only exits if the ListSearch returns != NULL
	}
	FLUSH; // Flushes the buffer so the program Doesn't loop  // Where do I put this? - Ana
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

