#include "menu.h"
#include <stdio.h>
#include "codeParse.h"
#include <stdlib.h>
#include "displayProductsUser.h"




/* _____________________________________________________________
Print Based on Product functions
If you want to start on these functions start with this as the Base:
void printOsByProduct (struct OS*, os, struct Product* prod) {
	
	struct Product* userChoice = malloc(sizeof(Product)); // this is the users product choice
	
	userChoice = displayProductsUser(prod); // this returns the Product Node that the user chose
	// now using the userChoice product node, print the information required
}
_____________________________________________________________*/

void printProductOs (struct OS* os, struct Product* p) {
	
	
	struct Product* userChoice = malloc(sizeof(Product)); // this is the users product choice
	
	userChoice = displayProductsUser(p); // this returns the Product Node that the user chose
	printf("Returned node: ID = %s\n", userChoice->id);
	
	return;
	
}
void printProductHype (struct Hypervisor *hype, struct Product* p) {
	
	struct Product* userChoice = malloc(sizeof(Product)); // this is the users product choice
	
	userChoice = displayProductsUser(p); // this returns the Product Node that the user chose
	printf("Returned node: ID = %s\n", userChoice->id);
	
	return;
}
void printProductSoft (struct Software* sof, struct Product* p) {
	
	struct Product* userChoice = malloc(sizeof(Product)); // this is the users product choice
	
	userChoice = displayProductsUser(p); // this returns the Product Node that the user chose
	printf("Returned node: ID = %s\n", userChoice->id);
	
	return;
}



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
	printf ("(Printers.c) FIXME need code for printing all\n"); //delete

	
}
void printAllHype (struct Hypervisor *hype) {
		while (hype != NULL) {
		printf("Hype Id:%s is printing\n", hype->id);
		
		hype = hype->next;
	}
	
	printf ("(Printers.c) FIXME need code for printing all\n"); //delete
}
void printAllSoft (struct Software* soft) {
	
	/*testing please delete*/
	while (soft != NULL) {
		printf("%-5s %-5s%-5s%-6s \n", soft->category, soft->id, soft->name, soft->version);
		soft = soft->next;
	}
	
		

	
	printf ("(Printers.c) FIXME need code for printing all\n"); //delete
}
void printAllProduct (struct Product* prod) {
		while (prod != NULL) {
		printf("Prod Id:%s is printing\n", prod->id);
		
		prod = prod->next;
	}
	printf ("(Printers.c) FIXME need code for printing all\n"); //delete
}


