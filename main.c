#include "menu.h"
#include <stdio.h>
#include "codeParse.h"
#include <stdlib.h>

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

/*debugging Printing data in OS structure*/
OS* current = malloc(sizeof(OS)); 
current = osHead;

while (current != NULL) {
        printf("%-10s", current->category);
        printf("%-8s ", current->id);
        printf("%-30s ", current->name);
        printf("%-8s ", current->version);
        printf("%-30s ", current->hardware);
        printf("%-10s\n", current->releaseDate);
        current = current->next;
}



/*Pass the Heads to main menu function*/
 mainMenu (osHead, hypervisorHead, softwareHead, productHead);

return 0;

}
