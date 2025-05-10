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
	struct OS* printingOS = malloc(sizeof(OS)); // This is the OS that is going to be printed
	char supportedOss[100]; // used for strtok function to get a substring

	userChoice = displayProductsUser(p); // this returns the Product Node that the user chose
	
	/*if user choose to skip product selection*/
	if (userChoice == NULL) {
	return;
	} 
		
	/*transfers OS Information*/
	strcpy (supportedOss, userChoice->supportedOS);
	/*gets the first OS Id from the Os String*/
	char* token = strtok(supportedOss, ","); 

	
		/*printing header*/
		if (token != NULL){
	 printf("\nSupported Operating Systems:\n");
				printf("%-10s %-5s %-30s %-8s %-30s %-10s \n", "OS", "ID", "Name", "Version", "Hardware", "Release Date");
		printf("%s\n", userChoice->supportedOS);
		} else { // if no Id's 
			printf("No Operating systems supported.\n");
		}
		
		/*printing all of the information*/
	while (token != NULL) { // itterates until the string is empty	
	
	printingOS = findOSByID(token, os); // this Finds the OS
        printf("%-10s ", printingOS->category);
		printf("%-5s ", printingOS->id);
        printf("%-30s ", printingOS->name);
        printf("%-8s ", printingOS->version);
        printf("%-30s ", printingOS->hardware);
        printf("%-10s\n", printingOS->releaseDate);
	/*itterates to the next SubString ID*/
	token = strtok(NULL, ","); //Holy Frick thank you God; this function is soo much simplier than the code I was trying to do
	}
	
		
	return;
	
}

void printProductHype (struct Hypervisor *hype, struct Product* p) {
	
	struct Product* userChoice = malloc(sizeof(Product)); // this is the users product choice
	struct Hypervisor* printingOS = malloc(sizeof(Hypervisor)); // This is the OS that is going to be printed
	char supportedOss[100]; // used for strtok function to get a substring

	userChoice = displayProductsUser(p); // this returns the Product Node that the user chose
	
	/*if user choose to skip product selection*/
	if (userChoice == NULL) {
	return;
	} 
		
	/*transfers OS Information*/
	strcpy (supportedOss, userChoice->supportedHypervisors);
	/*gets the first OS Id from the Os String*/
	char* token = strtok(supportedOss, ","); 

	
		/*printing header*/
		if (token != NULL && strcmp(token, "\r") != 0){
	 printf("\nSupported Operating Systems:\n");
				printf("%-10s %-5s %-30s %-8s %-30s %-10s \n", "OS", "ID", "Name", "Version", "Hardware", "Release Date");
		printf("%s\n", userChoice->supportedHypervisors);
		} else { // if no Id's 
			printf("No Operating systems supported.\n");
		}
		
		/*printing all of the information*/
	while (token != NULL) { // itterates until the string is empty	
	
	int length = strlen(token);//FIXME debugging code
	printf("length: %d\n", length);
	int count = 0; //FIXMEprint as ascii
	for (count = 0; count < length; count++){
	int charAsInt= 0;
	charAsInt = token[count];
	printf("char: %c\t num:%d\n", token[count], token[count]);
	}
	
	
	/*length = strlen("HV5");
	printf("Mlength: %d", length);*/
	
	printingOS = findHypervisorByID(token, hype); // this Finds the OS
		if (printingOS != NULL) {
		printf("%-5s ", printingOS->id);
        printf("%-30s ", printingOS->name);
        printf("%-8s ", printingOS->version);
        printf("%-10s\n", printingOS->releaseDate);
		}
	/*itterates to the next SubString ID*/
	token = strtok(NULL, ","); //Holy Frick thank you God; this function is soo much simplier than the code I was trying to do
	}
	
		
	return;
}

void printProductSoft (struct Software* sof, struct Product* p) {
	
		struct Product* userChoice = malloc(sizeof(Product)); // this is the users product choice
	struct Software* printingOS = malloc(sizeof(Software)); // This is the OS that is going to be printed
	char supportedOss[100]; // used for strtok function to get a substring

	userChoice = displayProductsUser(p); // this returns the Product Node that the user chose
	
	/*if user choose to skip product selection*/
	if (userChoice == NULL) {
	return;
	} 
		
	/*transfers OS Information*/
	strcpy (supportedOss, userChoice->supportedSoftware);
	/*gets the first OS Id from the Os String*/
	char* token = strtok(supportedOss, ","); 

	
		/*printing header*/
		if (token != NULL){
	 printf("\nSupported Operating Systems:\n");
				printf("%-18s %-5s %-30s %-8s %-30s %-10s \n", "OS", "ID", "Name", "Version", "Hardware", "Release Date");
		printf("%s\n", userChoice->supportedSoftware);
		} else { // if no Id's 
			printf("No Operating systems supported.\n");
		}
		
		/*printing all of the information*/
	while (token != NULL) { // itterates until the string is empty	
	
	printingOS = findSoftwareByID(token, sof); // this Finds the OS
		if (printingOS != NULL) {       
	   printf("%-18s ", printingOS->category);
		printf("%-5s ", printingOS->id);
        printf("%-30s ", printingOS->name);
        printf("%-8s ", printingOS->version);
        printf("%-10s\n", printingOS->releaseDate);
		}
	/*itterates to the next SubString ID*/
	token = strtok(NULL, ","); //Holy Frick thank you God; this function is soo much simplier than the code I was trying to do
	}
	
		
	return;
	

		
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

