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

// Search functions
OS* findOSByID(const char* id) {
    OS* current = osHead;
    while (current) {
        if (strcmp(current->id, id) == 0) return current;
        current = current->next;
    }
    return NULL;
}

Software* findSoftwareByID(const char* id) {
    Software* current = softwareHead;
    while (current) {
        if (strcmp(current->id, id) == 0) return current;
        current = current->next;
    }
    return NULL;
}

Hypervisor* findHypervisorByID(const char* id) {
    Hypervisor* current = hypervisorHead;
    while (current) {
        if (strcmp(current->id, id) == 0) return current;
        current = current->next;
    }
    return NULL;
}

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

// Function to load category data into linked lists
void loadData(const char* filename, int type) {
   FILE* file = fopen(filename, "r");
   if (!file) {
       perror("Failed to open file");
       return;
   }

   char line[MAX_LINE_LENGTH];
   while (fgets(line, sizeof(line), file)) {
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
}
