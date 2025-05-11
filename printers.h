#ifndef PRINTSMENU_H
#define PRINTSMENU_H
#include "codeParse.h"
#include "menu.h"


void printAllOs (struct OS* os);
void printAllHype (struct Hypervisor* hype);
void printAllSoft (struct Software* soft);
void printAllProduct (struct Product* prod);

void printProductOs (struct OS* os, struct Product* p);
void printProductHype (struct Hypervisor *hype, struct Product* p);
void printProductSoft (struct Software* soft, struct Product* p);
void overflowPrint (char* osString, char* softString, char* hypeString);


#endif
