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
		
	/*loop through all nodes*/
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
		
		/*just this Hypervisor ID needs to have a second option that has a '\r' concatinated at the end. 
		I have no idea why*/
		strcpy(otherOption, current->id);
			strcat(otherOption, "\r");

	    if (strcmp(current->id, id) == 0 || strcmp(otherOption, id) == 0) return current;
        current = current->next;
    }
			
    return NULL;
}
/* =============================================================
Parses lines
=============================================================*/
// Function to parse a line and store the data in the appropriate linked list
void parseLine(char* line, const char* delimiter, void* item, int type) {
   char* token = strtok(line, delimiter); // sets the token to the first section of the string
   if (type == 0) {  // OS
       OS* newOS = (OS*)item;  // casts proper structure
	   /*for all of these, it will only load data if the data is not "?". "?" is the character for no data*/
	   if (strcmp(token, "?")  != 0) strncpy(newOS->category, token ? token : "", sizeof(newOS->category)); // WIP added new "category" for later report printing -LM
	   
	   token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0)  strncpy(newOS->id, token ? token : "", sizeof(newOS->id));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0)  strncpy(newOS->name, token ? token : "", sizeof(newOS->name));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0)  strncpy(newOS->version, token ? token : "", sizeof(newOS->version));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0)  strncpy(newOS->hardware, token ? token : "", sizeof(newOS->hardware));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0)  strncpy(newOS->releaseDate, token ? token : "", sizeof(newOS->releaseDate));
   }
   else if (type == 1) {  // Hypervisor
       Hypervisor* newHV = (Hypervisor*)item; // casts proper structure
	   /*for all of these, it will only load data if the data is not "?"*/
       if (strcmp(token, "?")  != 0) strncpy(newHV->id, token ? token : "", sizeof(newHV->id));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0) strncpy(newHV->name, token ? token : "", sizeof(newHV->name));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0) strncpy(newHV->version, token ? token : "", sizeof(newHV->version));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0) strncpy(newHV->releaseDate, token ? token : "", sizeof(newHV->releaseDate));
   }
   else if (type == 2) {  // Software
       Software* newSoftware = (Software*)item; // casts proper structure
      /*for all of these, it will only load data if the data is not "?"*/
	  if (strcmp(token, "?")  != 0) strncpy(newSoftware->category, token ? token : "", sizeof(newSoftware->category)); // added missing printing data - Ivan
	   
	  token = strtok(NULL, delimiter);
	   if (strcmp(token, "?")  != 0) strncpy(newSoftware->id, token ? token : "", sizeof(newSoftware->id));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0) strncpy(newSoftware->name, token ? token : "", sizeof(newSoftware->name));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0) strncpy(newSoftware->version, token ? token : "", sizeof(newSoftware->version));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0) strncpy(newSoftware->releaseDate, token ? token : "", sizeof(newSoftware->releaseDate));
   }
   else if (type == 3) {  // Product
       Product* newProduct = (Product*)item; // casts proper structure
	   /*for all of these, it will only load data if the data is not "?"*/
       if (strcmp(token, "?")  != 0)  strncpy(newProduct->id, token ? token : "", sizeof(newProduct->id));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0)  strncpy(newProduct->name, token ? token : "", sizeof(newProduct->name));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0)  strncpy(newProduct->version, token ? token : "", sizeof(newProduct->version));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0)  strncpy(newProduct->supportedOS, token ? token : "", sizeof(newProduct->supportedOS));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0)  strncpy(newProduct->supportedSoftware, token ? token : "", sizeof(newProduct->supportedSoftware));

       token = strtok(NULL, delimiter);
       if (strcmp(token, "?")  != 0)  strncpy(newProduct->supportedHypervisors, token ? token : "", sizeof(newProduct->supportedHypervisors));
   }
}
/* =============================================================
Load OS data
=============================================================*/
void loadOSData (const char* filename, struct OS* osHead) { //created a load OS specific structure -ivan
	/*opens file and throws error if not able to open*/
	 FILE* file = fopen(filename, "r"); 
   if (!file) { 
       perror("Failed to open file \"operating_systems.txt\"");
       return;
   }
	
	OS* lastNode = osHead; // set the last node to header so function can add to this node -ivan
   char line[MAX_LINE_LENGTH];
   fgets(line, sizeof(line), file); // gets the Header
   while (fgets(line, sizeof(line), file)) {
       line[strcspn(line, "\r\n")] = 0;  // Remove newline

           OS* newOS = malloc(sizeof(OS)); // new header + error
           if (!newOS) {
               perror("Memory allocation failed");
               fclose(file);
               return;
           }
		   /*parsing data + linked list linking*/
           parseLine(line, "|", newOS, 0); 
			lastNode->next = newOS; 
			lastNode = newOS; 
	   }
   fclose(file);
}// loadOSData
/* =============================================================
Load Hypervisor data
=============================================================*/
void loadHypeData (const char* filename, struct Hypervisor* hypeHead) { //created a load Hypervisor specific structure -ivan
	/*opens filel and throws error if not able to open*/
	 FILE* file = fopen(filename, "r");
   if (!file) {
       perror("Failed to open file \"hypervisors.txt\"");
       return;
   }

	Hypervisor* lastNode = hypeHead; // set the last node to header so function can add to this node -ivan
		char line[MAX_LINE_LENGTH];
		fgets(line, sizeof(line), file); 

   while (fgets(line, sizeof(line), file)) {
       line[strcspn(line, "\r\n")] = 0;  // Remove newline

           Hypervisor* newHype = malloc(sizeof(Hypervisor));
           if (!newHype) {
               perror("Memory allocation failed");
               fclose(file);
               return;
           }
		   /*parsing data + linked list linking*/
           parseLine(line, "|", newHype, 1);
			lastNode->next = newHype; 
			lastNode = newHype; 
			
   }
   fclose(file);
}// loadHypeData
/* =============================================================
Load Software data
=============================================================*/
void loadSoftData (const char* filename, struct Software* softHead) { //created a load Software specific structure -ivan
	 /*opens filel and throws error if not able to open*/
	 FILE* file = fopen(filename, "r");
   if (!file) {
       perror("Failed to open file \"related_software.txt\"");
       return;
   }

	Software* lastNode = softHead; // set the last node to header so function can add to this node -ivan
		char line[MAX_LINE_LENGTH];
		fgets(line, sizeof(line), file);
   while (fgets(line, sizeof(line), file)) {
       line[strcspn(line, "\r\n")] = 0;  // Remove newline

           Software* newSoft= malloc(sizeof(Software));
           if (!newSoft) {
               perror("Memory allocation failed");
               fclose(file);
               return;
           }
		   /*parsing data + linked list linking*/
           parseLine(line, "|", newSoft, 2); 
			lastNode->next = newSoft; 
			lastNode = newSoft; 
   }
   fclose(file);
}// loadSoftData

/* =============================================================
Load product data
=============================================================*/
void loadProductData (const char* filename, struct Product* prodHead) { //created a load Product specific structure -ivan
	 /*opens filel and throws error if not able to open*/
	 FILE* file = fopen(filename, "r");
   if (!file) {
       perror("Failed to open file \"products.txt\"");
       return;
   }

	Product* lastNode = prodHead; // set the last node to header so function can add to this node -ivan
		char line[MAX_LINE_LENGTH];
		fgets(line, sizeof(line), file);
   while (fgets(line, sizeof(line), file)) {
       line[strcspn(line, "\r\n")] = 0;  // Remove newline

           Product* newProd = malloc(sizeof(Product));
           if (!newProd) {
               perror("Memory allocation failed");
               fclose(file);
               return;
           }
			/*parsing data + linked list linking*/
           parseLine(line, "|", newProd, 3); 
			lastNode->next = newProd; 
			lastNode = newProd; 
		}
   fclose(file);
}// loadSoftData

// Function to load category data into linked lists
//Function Retired by Ivan, reason: made specific ones for each data type (note 5-12-25; by the time I realised you could pass in as void and cast it was too late to change)
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
