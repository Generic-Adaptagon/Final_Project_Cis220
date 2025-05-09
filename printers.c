#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "codeParse.h"
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
	
	    printf("%-3s ", userChoice->id);
        printf("%-30s ", userChoice->name);
        printf("%-8s \n", userChoice->version);
        printf("%-70s \n ", userChoice->supportedOS);
        printf("%-61s \n", userChoice->supportedSoftware);
        printf("%s\n \n", userChoice->supportedHypervisors);
		
	//loop through the String and pull out and search for the OS
	int count = 0; //counting car
	int idCount = 0;// counting var for IDString
	int length = strlen(userChoice->supportedOS); // length for the string
	char test = 'a';
	char test2 = userChoice->supportedOS[count]; //initilizating
	char idString[10];
		//pull out the string unil ',' then search that ID of that string
		
		printf("%d\n", length);
		
		for (count = 1; count <= length;count++) {
		//while (test2 !='\n') {
			//printf("%c", userChoice->supportedOS[count]);
			printf("count = %d\n", count);
			printf("idCount = %d\n", idCount);
			

			printf("userChoice:%c\n", userChoice->supportedOS[count]);
			
			//load char into idString
			
			//if (strcmp(&userChoice->supportedOS[count], ",")== 0) {
			test = userChoice->supportedOS[count];
			printf("test = %c\n", test);
			
			if (test == '\n') printf("HOLY MOTH"); // this isnot itterating correctly
			
			if (test == ',') {
				//search for using ID
				//print information
				//reset String
				printf("idString:%s\n", idString);
				printf("\n =============\n");
				idCount = 0; // reset idCount
			} else {
				idString[count] = userChoice->supportedOS[count];

			}
			
			idCount ++;
			//count ++;
		}
		//print OS

		
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
		/*printing header*/
	printf("%-10s %-8s %-30s %-8s %-30s %-10s \n", "OS", "ID", "Name", "Version", "Hardware", "Release Date");
		/*printing all of the nodes*/
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
		/*printing header*/
	printf("%-8s %-30s %-8s %-10s \n", "ID", "Name", "Version", "Release Date");
		/*printing all of the nodes*/
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
		/*printing header*/
	printf("%-15s %-8s %-40s %-10s %-10s\n", "Category", "ID", "Name", "Version", "Release Date");
		/*printing all of the nodes*/
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
		/*printing header*/
    printf("%-3s %-47s %-8s %-70s %-61s %s\n", "ID", "Name", "Version",  "Supported OS", "Supported Software", "Supported Hypervisors");
		/*printing all of the nodes*/
        while (prod != NULL) {
        printf("%-3s ", prod->id);
        printf("%-47s ", prod->name);
        printf("%-8s ", prod->version);
        printf("%-70s ", prod->supportedOS);
        printf("%-61s ", prod->supportedSoftware);
        printf("%s\n", prod->supportedHypervisors);
    prod = prod->next;
    }
}

