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




/*Pass the Heads to main menu function*/
 mainMenu (osHead, hypervisorHead, softwareHead, productHead);

return 0;

}
