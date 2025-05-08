#ifndef MENU_H
#define MENU_H
#include "codeParse.h"

void mainMenu (struct OS* osLL, struct Hypervisor* hypervisorHead, 
	struct Software* softwareHead,  struct Product* productLL);
void menuHypervisor (struct Hypervisor* hvLL, struct Product* pLL);
void menuOS (struct OS* os, struct Product* pLL);
void menuProducts (struct Product* pLL);
void menuRelatedSoftware (struct Software* sLL, struct Product* pLL);
void menuDisplay(char menuName[]) ;



#endif
