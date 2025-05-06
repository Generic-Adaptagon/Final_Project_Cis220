#include "menu.h"
#include <stdio.h>
#include "codeParse.h"
#include <stdlib.h>





/* _____________________________________________________________
Print Based on Product functions
If you want to start on these functions start with this as the Base:
void printOsByProduct (struct OS*, os, struct Product* prod) {
	
	struct Product* userChoice = malloc(sizeof(Product)); // this is the users product choice
	
	userChoice = displayProductsUser(prod); // this returns the Product Node that the user chose
	// now using the userChoice product node, print the information required
}
_____________________________________________________________*/





/* _____________________________________________________________
Print All functions
_____________________________________________________________*/


/* =============================================================
Printing  functions
	// print everything
=============================================================*/
void printAllOs (struct OS* os) {
	
	
	while (os != NULL) {
		printf("Os Id:%s is printing\n", os->id);
		
		os = os->next;
	}
	
}
void printAllHype (struct Hypervisor *hype) {
	printf ("in this menu\n"); //test, delete
}
void printAllSoft (struct Software* soft) {
	printf ("in this menu\n"); //test, delete
}
void printAllProduct (struct Product* prod) {
	printf ("in this menu\n"); //test, delete
}


