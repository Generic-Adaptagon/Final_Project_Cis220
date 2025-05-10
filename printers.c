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
		if (printingOS != NULL) {
        printf("%-10s ", printingOS->category);
		printf("%-5s ", printingOS->id);
        printf("%-30s ", printingOS->name);
        printf("%-8s ", printingOS->version);
        printf("%-30s ", printingOS->hardware);
        printf("%-10s\n", printingOS->releaseDate);
		} else {printf("Something went wrong\n");}

	/*itterates to the next SubString ID*/
	token = strtok(NULL, ","); //Holy Frick thank you God; this function is soo much simplier than the code I was trying to do
	}
	
		
	return;
	
}

void printProductHype (struct Hypervisor *hype, struct Product* p) {
	
	struct Product* userChoice = malloc(sizeof(Product)); // this is the users product choice
	struct Hypervisor* printingHype = malloc(sizeof(Hypervisor)); // This is the Hypervisor that is going to be printed
	char supportedHypes[100]; // used for strtok function to get a substring

	userChoice = displayProductsUser(p); // this returns the Product Node that the user chose
	
	/*if user choose to skip product selection*/
	if (userChoice == NULL) {
	return;
	} 
		
	/*transfers Hypervisor Information*/
	strcpy (supportedHypes, userChoice->supportedHypervisors);
	/*gets the first Hypervisor Id from the Hypervisor String*/
	char* token = strtok(supportedHypes, ","); 

	
		/*printing header*/
		if (token != NULL && strcmp(token, "\r") != 0){
	 printf("\nSupported Operating Systems:\n");
				printf("%-5s %-30s %-8s %-10s \n",  "ID", "Name", "Version", "Release Date");
		printf("%s\n", userChoice->supportedHypervisors);
		} else { // if no Id's 
			printf("No Operating systems supported.\n");
		}
		
		/*printing all of the information*/
	while (token != NULL) { // itterates until the string is empty	
	
	/*int length = strlen(token);//FIXME debugging code
	printf("length: %d\n", length);
	int count = 0; //FIXMEprint as ascii
	for (count = 0; count < length; count++){
	int charAsInt= 0;
	charAsInt = token[count];
	printf("char: %c\t num:%d\n", token[count], token[count]);
	}*/
	
	printingHype = findHypervisorByID(token, hype); // this Finds the Hypervisor
		if (printingHype != NULL) {
		printf("%-5s ", printingHype->id);
        printf("%-30s ", printingHype->name);
        printf("%-8s ", printingHype->version);
        printf("%-10s\n", printingHype->releaseDate);
		} else {printf("Something went wrong\n");}
	/*itterates to the next SubString ID*/
	token = strtok(NULL, ","); 
	}
	
		
	return;
}

void printProductSoft (struct Software* sof, struct Product* p) {
	
		struct Product* userChoice = malloc(sizeof(Product)); // this is the users product choice
	struct Software* printingSoft = malloc(sizeof(Software)); // This is the Software that is going to be printed
	char supportedSoft[100]; // used for strtok function to get a substring

	userChoice = displayProductsUser(p); // this returns the Product Node that the user chose
	
	/*if user choose to skip product selection*/
	if (userChoice == NULL) {
	return;
	} 
		
	/*transfers SoftwareInformation*/
	strcpy (supportedSoft, userChoice->supportedSoftware);
	/*gets the first SoftwareId from the SoftwareString*/
	char* token = strtok(supportedSoft, ","); 

	
		/*printing header*/
		if (token != NULL){
	 printf("\nSupported Operating Systems:\n");
				printf("%-18s %-5s %-30s %-8s  %-10s \n", "OS", "ID", "Name", "Version",  "Release Date");
		printf("%s\n", userChoice->supportedSoftware);
		} else { // if no Id's 
			printf("No Operating systems supported.\n");
		}
		
		/*printing all of the information*/
	while (token != NULL) { // itterates until the string is empty	
	
	printingSoft = findSoftwareByID(token, sof); // this Finds the Software
		if (printingSoft != NULL) {       
	   printf("%-18s ", printingSoft->category);
		printf("%-5s ", printingSoft->id);
        printf("%-30s ", printingSoft->name);
        printf("%-8s ", printingSoft->version);
        printf("%-10s\n", printingSoft->releaseDate);
		} else {printf("Something went wrong\n");}
	/*itterates to the next SubString ID*/
	token = strtok(NULL, ","); 
	}
	
		
	return;

}

/* =============================================================
Printing  functions
	// prints all the node
=============================================================*/
void printAllOs (struct OS* os) {
	
		    OS* current = os;
    printf("\nAll Operating Systems:\n\n");
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
    printf("\nAll Hypervisors:\n\n");
		/*printing header*/
	printf("%-8s %-30s %-8s %-10s \n", "ID", "Name", "Version", "Release Date");
		/*printing all of the nodes*/
    while (current != NULL) {
        printf("%-8s ", current->id);
        printf("%-30s ", current->name);
        printf("%-8s ", current->version);
        printf("%-10s\n", current->releaseDate);
        current = current->next;// itterates to next
    }
}
void printAllSoft (struct Software* soft) {
	
	    Software* current = soft;
    printf("\nAll Software:\n\n");
		/*printing header*/
	printf("%-15s %-8s %-40s %-10s %-10s\n", "Category", "ID", "Name", "Version", "Release Date");
		/*printing all of the nodes*/
    while (current != NULL) {
        printf("%-15s ", current->category);
        printf("%-8s ", current->id);
        printf("%-40s ", current->name);
        printf("%-10s ", current->version);
        printf("%-10s\n", current->releaseDate);
        current = current->next;// itterates to next
    }
	
}
void printAllProduct (struct Product* prod) {
     
	 printf("\nAll Product:\n\n");
		/*printing header*/
    printf("%-3s %-47s %-8s %-70s %-61s %s\n", 
	"ID", "Name", "Version",  "Supported OS ID's", "Supported Software ID's", "Supported Hypervisors ID's");
		/*printing all of the nodes*/
        while (prod != NULL) {
        printf("%-4s ", prod->id);
        printf("%-47s ", prod->name);
        printf("%-8s ", prod->version);
        printf("%-70s ", prod->supportedOS);
        printf("%-61s ", prod->supportedSoftware);
        printf("%s\n", prod->supportedHypervisors);
    prod = prod->next;// itterates to next
    }
}

