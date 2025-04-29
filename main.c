//testing 
#include <stdio.h>
# include "menu.h"
#include "codeParse.h"
//# include "menuTemplate.c"


int main () {
	
	loadData("data/operating_systems.txt", 0);        // Load OS data
    loadData("data/hypervisors.txt", 1); // Load Hypervisor data
    loadData("data/related_software.txt", 2);   // Load Software data
    loadData("data/products.txt", 3);    // Load Product data

printf (" (main) FIXME:I need data input\n");

mainMenu();

return 0;

}
