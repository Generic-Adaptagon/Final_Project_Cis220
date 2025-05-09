#include "menu.h"
#include <stdio.h>
#include "codeParse.h"
#include <stdlib.h>


//Try1
// Moved to printers.c - ivan
/*void printOS() {
    OS* current = osHead;
    printf("\nOperating Systems:\n\n");
	printf("%-15s %-15s %-40s %-15s %-35s %-10s \n", "OS", "ID", "Name", "Version", "Hardware", "Release Date");
    while (current != NULL) {
        printf("%-15s ", current->category);
        printf("%-15s ", current->id);
        printf("%-40s ", current->name);
        printf("%-15s ", current->version);
        printf("%-35s ", current->hardware);
        printf("%-10s\n", current->releaseDate);
        current = current->next;
    }
}
void printHypervisor() {
    Hypervisor* current = hypervisorHead;
    printf("\nHypervisors:\n\n");
	printf("%-15s %-40s %-15s %-10s \n", "ID", "Name", "Version", "Release Date");
    while (current != NULL) {
        printf("%-15s ", current->id);
        printf("%-40s ", current->name);
        printf("%-15s ", current->version);
        printf("%-10s\n", current->releaseDate);
        current = current->next;
    }
}
void printSoftware() {
    Software* current = softwareHead;
    printf("\nSoftware:\n\n");
	printf("%-10s %-15s %-40s %-30s %-10s\n", "OS", "ID", "Name", "Version", "Release Date");
    while (current != NULL) {
        printf("%-10s ", current->category);
        printf("%-15s ", current->id);
        printf("%-40s ", current->name);
        printf("%-30s ", current->version);
        printf("%-10s\n", current->releaseDate);
        current = current->next;
    }
}*/
	


int main () {


/*creating dummy head nodes*/
OS* osHead = malloc(sizeof(OS)); 
Hypervisor* hypervisorHead = malloc(sizeof(Hypervisor));
Software * softwareHead = malloc(sizeof(Software));
Product * productHead = malloc(sizeof(Product));

/*loading all types of data*/
loadOSData("data/operating_systems.txt", osHead);
loadHypeData("data/hypervisors.txt", hypervisorHead);
loadSoftData ("data/related_software.txt", softwareHead);
loadProductData ("data/products.txt", productHead);


/*Pass the Heads to main menu function*/
 mainMenu (osHead, hypervisorHead, softwareHead, productHead);

return 0;

}
