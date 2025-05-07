// Products - Ana

#include <stdio.h>
#include <stdlib.h>
#include "displayProductsUser.h"
#include "codeParse.h"
#include "menu.h"
// gcc main.c menu.c codeParse.c displayProductsUser.c printers.c
// menu calls though this "void menuProducts (struct Product* productLL)"
struct Product* displayProductsUser(struct Product* p) {
	Product* currentProduct;
	Product* nextProduct;
	
	currentProduct = p;
	nextProduct = p;
	
	// currentProduct = currentProduct->next;
	
	
	while (currentProduct != NULL) {
		printf("\nID\t\t:%s ", currentProduct->id);
		printf("\nName\t\t:%s ",currentProduct->name);
		printf("\nVersion\t\t:%s ",currentProduct->version);
		printf("\nSupported OS\t\t:%s ",currentProduct->supportedOS);
		printf("\nSupported Software\t\t:%s ",currentProduct->supportedSoftware);
		printf("\nSupported Hypervisors\t:%s",currentProduct->supportedHypervisors);
		
		currentProduct = currentProduct->next;
	}
	int userChoice = -1;
	int option = 0;

	printf("\nPlease enter the ID of product choice\nP:");
	scanf("%d", &userChoice);

	ListSearch(p, userChoice);
}

/* Section that inputs user's choice and returns it */
// Function searches for a node with a specific data value, pseudocode found in PA 4.3.1 
struct Product* ListSearch(struct Product* p, int userChoice) {
    Product* currProd = productHead; 		// productHead ??
    while (currProd != NULL) {
        if (*currProd->id == userChoice) { 
            return currProd;
        }
        currProd = currProd->next;
    }
    return NULL;
}

