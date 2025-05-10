#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codeParse.h"

#define MAX_LINE_LENGTH 1024

// Linked lists for each category
OS* osHead = NULL;
Hypervisor* hypervisorHead = NULL;
Software* softwareHead = NULL;
Product* productHead = NULL;
/* =============================================================
Load Search function data
=============================================================*/
// Search functions
OS* findOSByID(const char* id, struct OS* osHead) {
    OS* current = osHead;
    while (current) {
        if (strcmp(current->id, id) == 0) return current;
        current = current->next;
    }
    return NULL;
}

Software* findSoftwareByID(const char* id, struct Software* softwareHead) {
    Software* current = softwareHead;
			

    while (current) {

        if (strcmp(current->id, id) == 0) return current;
        current = current->next;
    }
    return NULL;
}

Hypervisor* findHypervisorByID(const char* id, struct Hypervisor* hypervisorHead) {
    Hypervisor* current = hypervisorHead;
	char otherOption[5];
    while (current) {
		/*printf("id = %s\n", current->id);
		printf("passed inid = %s\n", id);
	int test = 0;
		test = strcmp(current->id, id);
		printf("test = %d\n", test);
		
	int length = strlen(id);
	printf("passed in length: %d\n", length);
	length = strlen(current->id);
	printf("data structure length: %d\n", length);
			strcpy(otherOption, current->id);
			strcat(otherOption, "\0");
		length = strlen(otherOption);
		printf("other option: %s length length: %d\n", otherOption, length);
		test = 0;
		test = strcmp(otherOption, id);
		printf("test = %d\n", test);*/
		
		/*just this Hypervisor ID needs to have a second option that has a '\r' concatinated at the end. 
		I have no idea why*/
		strcpy(otherOption, current->id);
			strcat(otherOption, "\r");

	    if (strcmp(current->id, id) == 0 || strcmp(otherOption, id) == 0) return current;
        current = current->next;
    }
			printf("RETURNED NUL\n");//FIXME
    return NULL;
}
/* =============================================================
Parses lines
=============================================================*/
// Function to parse a line and store the data in the appropriate linked list
void parseLine(char* line, const char* delimiter, void* item, int type) {
   char* token = strtok(line, delimiter);
   if (type == 0) {  // OS
       OS* newOS = (OS*)item;
	   strncpy(newOS->category, token ? token : "", sizeof(newOS->category)); // WIP added new "category" for later report printing -LM
	   
	   token = strtok(NULL, delimiter);
       strncpy(newOS->id, token ? token : "", sizeof(newOS->id));

       token = strtok(NULL, delimiter);
       strncpy(newOS->name, token ? token : "", sizeof(newOS->name));

       token = strtok(NULL, delimiter);
       strncpy(newOS->version, token ? token : "", sizeof(newOS->version));

       token = strtok(NULL, delimiter);
       strncpy(newOS->hardware, token ? token : "", sizeof(newOS->hardware));

       token = strtok(NULL, delimiter);
       strncpy(newOS->releaseDate, token ? token : "", sizeof(newOS->releaseDate));
   }
   else if (type == 1) {  // Hypervisor
       Hypervisor* newHV = (Hypervisor*)item;
       strncpy(newHV->id, token ? token : "", sizeof(newHV->id));

       token = strtok(NULL, delimiter);
       strncpy(newHV->name, token ? token : "", sizeof(newHV->name));

       token = strtok(NULL, delimiter);
       strncpy(newHV->version, token ? token : "", sizeof(newHV->version));

       token = strtok(NULL, delimiter);
       strncpy(newHV->releaseDate, token ? token : "", sizeof(newHV->releaseDate));
   }
   else if (type == 2) {  // Software
       Software* newSoftware = (Software*)item;
      
	  strncpy(newSoftware->category, token ? token : "", sizeof(newSoftware->category)); // added missing printing data - Ivan
	   
	  token = strtok(NULL, delimiter);
	   strncpy(newSoftware->id, token ? token : "", sizeof(newSoftware->id));

       token = strtok(NULL, delimiter);
       strncpy(newSoftware->name, token ? token : "", sizeof(newSoftware->name));

       token = strtok(NULL, delimiter);
       strncpy(newSoftware->version, token ? token : "", sizeof(newSoftware->version));

       token = strtok(NULL, delimiter);
       strncpy(newSoftware->releaseDate, token ? token : "", sizeof(newSoftware->releaseDate));
   }
   else if (type == 3) {  // Product
       Product* newProduct = (Product*)item;
       strncpy(newProduct->id, token ? token : "", sizeof(newProduct->id));

       token = strtok(NULL, delimiter);
       strncpy(newProduct->name, token ? token : "", sizeof(newProduct->name));

       token = strtok(NULL, delimiter);
       strncpy(newProduct->version, token ? token : "", sizeof(newProduct->version));

       token = strtok(NULL, delimiter);
       strncpy(newProduct->supportedOS, token ? token : "", sizeof(newProduct->supportedOS));

       token = strtok(NULL, delimiter);
       strncpy(newProduct->supportedSoftware, token ? token : "", sizeof(newProduct->supportedSoftware));

       token = strtok(NULL, delimiter);
       strncpy(newProduct->supportedHypervisors, token ? token : "", sizeof(newProduct->supportedHypervisors));
   }
}
/* =============================================================
Load OS data
=============================================================*/
void loadOSData (const char* filename, struct OS* osHead) { //created a load OS specific structure -ivan
	 FILE* file = fopen(filename, "r");
   if (!file) {
       perror("Failed to open file");
       return;
   }
	//OS* NodeHead = osHead;
	OS* lastNode = osHead; // set the last node to header so function can add to this node -ivan
   char line[MAX_LINE_LENGTH];
   fgets(line, sizeof(line), file); // gets the Header
   while (fgets(line, sizeof(line), file)) {
       line[strcspn(line, "\n")] = 0;  // Remove newline

           OS* newOS = malloc(sizeof(OS));
           if (!newOS) {
               perror("Memory allocation failed");
               fclose(file);
               return;
           }
		   
           parseLine(line, "|", newOS, 0); // parsing Line os
		   printf("category loaded into Os Structure: %s\n", newOS->category); //CODE PROBE
			lastNode->next = newOS; // links noew node to the previous node - ivan
			lastNode = newOS; // sets the last node to the last node.
	   }
   fclose(file);
}// loadOSData
/* =============================================================
Load Hypervisor data
=============================================================*/
void loadHypeData (const char* filename, struct Hypervisor* hypeHead) { //created a load Hypervisor specific structure -ivan
	 FILE* file = fopen(filename, "r");
   if (!file) {
       perror("Failed to open file");
       return;
   }

	Hypervisor* lastNode = hypeHead; // set the last node to header so function can add to this node -ivan
		char line[MAX_LINE_LENGTH];
		fgets(line, sizeof(line), file); 

   while (fgets(line, sizeof(line), file)) {
       line[strcspn(line, "\n")] = 0;  // Remove newline

           Hypervisor* newHype = malloc(sizeof(Hypervisor));
           if (!newHype) {
               perror("Memory allocation failed");
               fclose(file);
               return;
           }
           parseLine(line, "|", newHype, 1); // parsing Line os
			lastNode->next = newHype; // links noew node to the previous node - ivan
			lastNode = newHype; // sets the last node to the last node.
			
   }
   fclose(file);
}// loadHypeData
/* =============================================================
Load Software data
=============================================================*/
void loadSoftData (const char* filename, struct Software* softHead) { //created a load Software specific structure -ivan
	 FILE* file = fopen(filename, "r");
   if (!file) {
       perror("Failed to open file");
       return;
   }

	Software* lastNode = softHead; // set the last node to header so function can add to this node -ivan
		char line[MAX_LINE_LENGTH];
		fgets(line, sizeof(line), file);
   while (fgets(line, sizeof(line), file)) {
       line[strcspn(line, "\n")] = 0;  // Remove newline

           Software* newSoft= malloc(sizeof(Software));
           if (!newSoft) {
               perror("Memory allocation failed");
               fclose(file);
               return;
           }
           parseLine(line, "|", newSoft, 2); // parsing lines
			lastNode->next = newSoft; // links new node to the previous node - ivan
			lastNode = newSoft; // sets the last node to the last node.
   }
   fclose(file);
}// loadSoftData

/* =============================================================
Load product data
=============================================================*/
void loadProductData (const char* filename, struct Product* prodHead) { //created a load Product specific structure -ivan
	 FILE* file = fopen(filename, "r");
   if (!file) {
       perror("Failed to open file");
       return;
   }

	Product* lastNode = prodHead; // set the last node to header so function can add to this node -ivan
		char line[MAX_LINE_LENGTH];
		fgets(line, sizeof(line), file);
   while (fgets(line, sizeof(line), file)) {
       line[strcspn(line, "\n")] = 0;  // Remove newline

           Product* newProd = malloc(sizeof(Product));
           if (!newProd) {
               perror("Memory allocation failed");
               fclose(file);
               return;
           }
           parseLine(line, "|", newProd, 3); // parsing lines
			lastNode->next = newProd; // links to the end of the list - Ivan  
			lastNode = newProd; // sets the last node to the last node.
		}
   fclose(file);
}// loadSoftData

// Function to load category data into linked lists
//Function Retired by Ivan, reason: made specific ones for each data type
/*void loadData(const char* filename, int type) {
   FILE* file = fopen(filename, "r");
   if (!file) {
       perror("Failed to open file");
       return;
   }

   char line[MAX_LINE_LENGTH];
   while (fgets(line, sizeof(line), file)) { // while file not empty
       line[strcspn(line, "\n")] = 0;  // Remove newline

       if (type == 0) {  // OS
           OS* newOS = malloc(sizeof(OS));
           if (!newOS) {
               perror("Memory allocation failed");
               fclose(file);
               return;
           }
           parseLine(line, "|", newOS, 0);
		   printf("%s \n", newOS->id); 			//changed %c to %s so it prints the whole string instead of first character -LM Change back if wrong lol 
           newOS->next = osHead;
           osHead = newOS;
       }
       else if (type == 1) {  // Hypervisor
           Hypervisor* newHV = malloc(sizeof(Hypervisor));
           if (!newHV) {
               perror("Memory allocation failed");
               fclose(file);
               return;
           }
           parseLine(line, "|", newHV, 1);
           newHV->next = hypervisorHead;
           hypervisorHead = newHV;
       }
       else if (type == 2) {  // Software
           Software* newSoftware = malloc(sizeof(Software));
           if (!newSoftware) {
               perror("Memory allocation failed");
               fclose(file);
               return;
           }
           parseLine(line, "|", newSoftware, 2);
           newSoftware->next = softwareHead;
           softwareHead = newSoftware;
       }
       else if (type == 3) {  // Product
           Product* newProduct = malloc(sizeof(Product));
           if (!newProduct) {
               perror("Memory allocation failed");
               fclose(file);
               return;
           }
           parseLine(line, "|", newProduct, 3);
           newProduct->next = productHead;
           productHead = newProduct;
       }
   }

   fclose(file);
} */
