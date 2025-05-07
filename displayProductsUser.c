// Products - Ana

#include <stdio.h>
#include <stdlib.h>
#include "displayProductsUser.h"
#include "codeParse.h"
#include "menu.h"
# define FLUSH while (getchar() != '\n')
// gcc main.c menu.c codeParse.c displayProductsUser.c printers.c
// menu calls though this "void menuProducts (struct Product* productLL)"
struct Product* displayProductsUser(struct Product* p) {
	Product* currentProduct;
	Product* nextProduct;
	
	currentProduct = p;
	nextProduct = p;
	
	// currentProduct = currentProduct->next;
	
	printf("ID     Name\n");
	while (currentProduct != NULL) {
		//printf("\nID\t\t:%s ;", currentProduct->id);
		//printf("Name\t\t:%s ",currentProduct->name);
		printf("%-4s ", currentProduct->id);
		printf("%-8s \n",currentProduct->name);
		/*printf("\nVersion\t\t:%s ",currentProduct->version);
		printf("\nSupported OS\t\t:%s ",currentProduct->supportedOS);
		printf("\nSupported Software\t\t:%s ",currentProduct->supportedSoftware);
		printf("\nSupported Hypervisors\t:%s",currentProduct->supportedHypervisors);*/
		
		currentProduct = currentProduct->next;
	}

// this can be the start of the Do-while loop
	int userChoice = -1;
	int option = 0;

	printf("\nPlease enter the ID of product choice\nP:");
	scanf("%d", &userChoice);
	FLUSH; // Flushes the buffer so the program Doesn't loop

	ListSearch(p, userChoice);
	// this is the end and only exits if the ListSearch returns != NULL
}

/* Section that inputs user's choice and returns it */
// Function searches for a node with a specific data value, pseudocode found in PA 4.3.1 
struct Product* ListSearch(struct Product* p, int userChoice) {
	
	//Also please handle the user error if the the program didn't find the 
		//ID in the  DisplayProductUser function
    struct Product* currProd = p; 		// productHead ??
    while (currProd != NULL) {
        if (*currProd->id == userChoice) {  //THIS should be string not integer, ID = "P1" not an interger
            return currProd;
        }
        currProd = currProd->next;
    }
    return NULL;
}

