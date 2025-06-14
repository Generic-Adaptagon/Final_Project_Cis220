#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>
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
				printf("%-10s %-5s %-30s %-8s %-30s %-10s \n", 
				"OS", "ID", "Name", "Version", "Hardware", "Release Date");
		} else { // if no Id's 
			printf("No Operating Systems supported.\n");
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
	 printf("\nSupported Hypervisors:\n");
				printf("%-5s %-30s %-8s %-10s \n",  "ID", "Name", "Version", "Release Date");
		} else { // if no Id's 
			printf("\nNo Hypervisors supported.\n");
		}
		
		/*printing all of the information*/
	while (token != NULL) { // itterates until the string is empty	
	
	token[strcspn(token, "\r\n")] = 0;
	
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
	 printf("\nSupported Related Software:\n");
				printf("%-18s %-5s %-50s %-8s  %-10s \n", "OS", "ID", "Name", "Version",  "Release Date");
		} else { // if no Id's 
			printf("\nNo Related Software supported.\n");
		}
		
		/*printing all of the information*/
	while (token != NULL) { // itterates until the string is empty	
	
	printingSoft = findSoftwareByID(token, sof); // this Finds the Software
		if (printingSoft != NULL) {       
	   printf("%-18s ", printingSoft->category);
		printf("%-5s ", printingSoft->id);
        printf("%-50s ", printingSoft->name);
        printf("%-8s ", printingSoft->version);
        printf("%-10s\n", printingSoft->releaseDate);
		} else {printf("Something went wrong\n");}
	/*itterates to the next SubString ID*/
	token = strtok(NULL, ","); 
	}
	
		
	return;

}


void overflowPrint (char* osString, char* softString, char* hypeString) {

int osCursor = 0;
int softCursor = 0;
int hypeCursor = 0;
bool osOverflow = false;
bool softOverFlow = false;
bool hypeOverflow = false;

/*determines of the software string is over the text wrap amount*/
if (strlen(osString) < 40) { 
	osOverflow = false;
		if (strlen(osString) == 0) { 
		printf("%-*s", 40, "No Operating Systems");
	} else {
		printf("%-40s ", osString);
	}
} else { // if does over flow print until overflow limit and put cursor at overflow limit to print rest later
	osOverflow = true;
	printf("%-.39s", osString);
	printf("- ");
	osCursor = 39;
}

/*determines of the software string is over the text wrap amount*/
if (strlen(softString) < 40) { 
	softOverFlow = false;
	/*checks if string is empty; if it is print data empt; if not print*/
	if (strlen(softString) == 0) { 
		printf("%-*s", 41, "No Software");
	} else {
		printf("%-40s ", softString);
	}
} else { // if does over flow print until overflow limit and put cursor at overflow limit to print rest later
	softOverFlow = true;
	printf("%-.39s", softString);
	printf("- ");
	softCursor = 39;
}


/*determines of the software string is over the text wrap amount*/
if (strlen(hypeString) < 40) { 
	hypeCursor = false;
			if (strlen(hypeString) == 0) { 
		printf("%-*s", 40, "No Hypervisors");
	} else {
	printf("%-40s ", hypeString);
	}
} else { // if does over flow print until overflow limit and put cursor at overflow limit to print rest later
	hypeCursor = true;
	printf("%-.39s", hypeString);
	printf("- ");
	hypeCursor = 39;
}
      printf("\n"); // end first row

/*print even if one overflows*/
while (osOverflow == true || softOverFlow == true ||hypeOverflow == true){
	
if (osOverflow == true) { // if operating system overflows
char temp[1000] = {0}; // for sub string stuff
int test = 0; //for comparison later

strcpy(temp, osString + osCursor);
test = strlen(temp);

	if ( test < osCursor + 39) { // if test string is greater than current cursor place + the next wrap text length
		printf("%*s%-40s ", 62, " ", osString + osCursor); //print string as normal with spacing
		osOverflow = false;
	} else {
		printf("%-.39s", osString); // print only to the wrap limit
		printf("- ");
		osCursor += 39; // update cursor spot
	}
} else { // it OS not overflowing just print spacing
	printf("%-62s%*s ", "  ", 40, " ");
}

if (softOverFlow == true) {
char temp[1000] = {0}; // for sub string stuff
int test = 0; //for comparison later

strcpy(temp, softString + softCursor);
test = strlen(temp);

	if ( test < softCursor + 39) { // if test string is greater than current cursor place + the next wrap text length
		printf("%-40s ", softString + softCursor); //print string as normal
		softOverFlow = false;
	} else {
		printf("%-.39s", softString + softCursor); // print only to the wrap limit
		printf("- ");
		softCursor += 39;
	}
} else { // if Software not overflowing just print spacing
	printf("%-40s ", "  ");
}


if (hypeOverflow == true) {
char temp[1000] = {0}; // for sub string stuff
int test = 0; //for comparison later

strcpy(temp, hypeString + hypeCursor);
test = strlen(temp);

	if ( test < hypeCursor + 39) { // if test string is greater than current cursor place + the next wrap text length
		printf("%-40s ", hypeString + hypeCursor); //print string
		hypeOverflow = false;
	} else {
		printf("%-.39s", hypeString); // print up to limit
		printf("- ");
		hypeCursor += 39; // update cursor position
	}
} else {// if Software not overflowing just print spacing
	printf("%-40s ", "  ");
}

printf("\n");// end of row
}
	
	
}

/* =============================================================
Printing  functions
	// prints all the node
=============================================================*/
void printAllOs (struct OS* os) {
	
		    OS* current = os;
			current = current->next;// skips head
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
			current = current->next;// skips head
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
	current = current->next;// skips head
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
     
	 prod = prod->next;// skips dummy
	 printf("\nAll Products:\n\n");
		/*printing header*/
    printf("%-4s %-47s %-8s %-40s %-40s %-40s\n", 
	"ID", "Name", "Version",  "Supported OS ID's", "Supported Software ID's", "Supported Hypervisors ID's");
		/*printing all of the nodes*/
        while (prod != NULL) {
        printf("%-4s ", prod->id);
        printf("%-47s ", prod->name);
        printf("%-8s ", prod->version);
		overflowPrint(prod->supportedOS, prod->supportedSoftware, prod->supportedHypervisors);
    prod = prod->next;// itterates to next
    }
}

