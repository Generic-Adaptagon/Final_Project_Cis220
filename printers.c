#include "menu.h"
#include <stdio.h>
#include "codeParse.h"
#include <stdlib.h>
#include "displayProductsUser.h"


/* =============================================================
Print Based on Product functions
=============================================================*/

void printProductOs (struct OS* os, struct Product* p) {
	
	
	struct Product* userChoice = malloc(sizeof(Product)); // this is the users product choice
	
	userChoice = displayProductsUser(p); // this returns the Product Node that the user chose
	
	/*if user choose to skip product selection*/
	if (userChoice == NULL) {
	return;
	} 
	
	/*printing functions here*/
	// userChoice has the product node containing everything that nodes has to offer

		
	return;
	
}

void printProductHype (struct Hypervisor *hype, struct Product* p) {
	
	struct Product* userChoice = malloc(sizeof(Product)); // this is the users product choice
	
	userChoice = displayProductsUser(p); // this returns the Product Node that the user chose
	/*if user choose to skip product selection*/
	if (userChoice == NULL) {
	return;
	} 
	
	/*printing functions here*/
	// userChoice has the product node containing everything that nodes has to offer

		
	return;
}

void printProductSoft (struct Software* sof, struct Product* p) {
	
	struct Product* userChoice = malloc(sizeof(Product)); // this is the users product choice
	
	userChoice = displayProductsUser(p); // this returns the Product Node that the user chose
	/*if user choose to skip product selection*/
	if (userChoice == NULL) {
	return;
	} 
	
	/*printing functions here*/
	// userChoice has the product node containing everything that nodes has to offer

		
	return;
}




/* =============================================================
Printing  functions
	// print everything
=============================================================*/
void printAllOs (struct OS* os) {
	
		    OS* current = os;
    printf("\nOperating Systems:\n\n");
	printf("%-10s %-8s %-30s %-8s %-30s %-10s \n", "OS", "ID", "Name", "Version", "Hardware", "Release Date");
    while (current != NULL) {
        printf("%-10s ", current->category);
        printf("%-8s ", current->id);
        printf("%-30s ", current->name);
        printf("%-8s ", current->version);
        printf("%-30s ", current->hardware);
        printf("%-10s\n", current->releaseDate);
        current = current->next;
	}

	
}
void printAllHype (struct Hypervisor *hype) {
		
		    Hypervisor* current = hype;
    printf("\nHypervisors:\n\n");
	printf("%-8s %-30s %-8s %-10s \n", "ID", "Name", "Version", "Release Date");
    while (current != NULL) {

        printf("%-8s ", current->id);
        printf("%-30s ", current->name);
        printf("%-8s ", current->version);
        printf("%-10s\n", current->releaseDate);
        current = current->next;
    }
}
void printAllSoft (struct Software* soft) {
	
	    Software* current = soft;
    printf("\nSoftware:\n\n");
	printf("%-15s %-8s %-40s %-10s %-10s\n", "Category", "ID", "Name", "Version", "Release Date");
    while (current != NULL) {
        printf("%-15s ", current->category);
        printf("%-8s ", current->id);
        printf("%-40s ", current->name);
        printf("%-10s ", current->version);
        printf("%-10s\n", current->releaseDate);
        current = current->next;
    }
	
}
void printAllProduct (struct Product* prod) {
     printf("\nProduct:\n\n");
    printf("%-3s %-47s %-8s %-70s %-61s %s\n", "ID", "Name", "Version",  "Supported OS", "Supported Software", "Supported Hypervisors");

        while (prod != NULL) {
//printf("Prod Id:%s is printing\n", prod->id);
        printf("%-3s ", prod->id);
        printf("%-47s ", prod->name);
        printf("%-8s ", prod->version);
        printf("%-70s ", prod->supportedOS);
        printf("%-61s ", prod->supportedSoftware);
        printf("%s\n", prod->supportedHypervisors);
    prod = prod->next;
    }
//    printf ("(Printers.c) FIXME need code for printing all\n"); //delete
}

