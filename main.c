#include "menu.h"
#include <stdio.h>
#include "codeParse.h"

//Try1
void printAllData();

//Try1
void printOS() {
    OS* current = osHead;
    printf("\nOperating Systems:\n\n");
	printf("%-10s %-10s %-30s %-10s %-30s %-10s", "OS", "ID", "Name", "Version", "Hardware", "Release Date\n");
    while (current != NULL) {
        printf("%-10s ", current->category);
        printf("%-10s ", current->id);
        printf("%-30s ", current->name);
        printf("%-10s ", current->version);
        printf("%-30s ", current->hardware);
        printf("%-10s\n", current->releaseDate);
        current = current->next;
    }
}
	


int main () {

	/*initializing structures
		struct Product product1 = {
		"P1", //ID
		"WebSphere Application Server", //name
		"9.0.5", //version
		"OS2,OS3,OS6,OS7,OS13,OS14,OS15", 
		"SS1,SS2,SS3,SS4,SS5,SS7,SS8,SS9,SS10,SS11,SS12,SS13,SS14,SS15",
		"HV1,HV5",
		NULL};
		
	OS* osHead = NULL;
	Hypervisor* hypervisorHead = NULL;
	Software* softwareHead = NULL;
	Product* productHead = &product1;


	struct Product product2 = {
		"P2", //ID
		"IBM Cognos Analytics11.2.4", //name
		"11.2.4", //version
		"OS2,OS3,OS4,OS5,OS6,OS7,OS12,OS13,OS14,OS15,OS16", 
		"SS1,SS3,SS4,SS5,SS6,SS7,SS8,SS9,SS10,SS11,SS12,SS13,SS14,SS15",
		"HV2,HV3",
		NULL};
	product1.next = &product2;

	struct Product product3 = {

		"P3", //ID
		"Tivoli Business Service Manager", //name
		"6.2.0", //version
		"OS14", 
		"",
		"",
		NULL};
	product2.next = &product3;
	
	struct Product product4 = {
		"P4", //ID
		"DB2 Enterprise Server Edition11.5.9", //name
		"11.5.9", //version
		"OS1,OS2,OS3,OS4,OS5,OS6,OS7,OS8,OS9,OS10,OS11,OS12,OS13,OS14,OS15,OS16", 
		"SS12",
		"",
		NULL};
	product3.next = &product4; */ //Commented it out for testing-LM

	
	/*Jade something like this (below)*/
	//loadData("data/file_name", #, &osHead);
	
	/*FIXME: pass in heads as pointers to load the data into*/
	//loadData("data/operating_systems.txt", 0);        // Load OS data
    //loadData("data/hypervisors.txt", 1); // Load Hypervisor data
    //loadData("data/related_software.txt", 2);   // Load Software data
    //loadData("data/products.txt", 3);    // Load Product data

//Try1-LM
loadData("data/operating_systems.txt", 0);  // Load OS data
loadData("data/hypervisors.txt", 1);        // Load Hypervisor data
loadData("data/related_software.txt", 2);   // Load Software data
loadData("data/products.txt", 3);           // Load Product data
//Try1
printOS(); //Prints everything on the OS file 

printf (" (main) FIXME:I need data input\n");

/*Pass the Heads as pointers here to access the data later*/
 mainMenu (osHead, productHead);

return 0;

}
