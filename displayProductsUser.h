#ifndef DISPLAYPRODUCTSUSER_H
#define DISPLAYPRODUCTSUSER_H


// The function exists to display all available data within Products
struct Product* displayProductsUser(struct Product* p);

// Function searches for a node with a specific data value, pseudocode found in PA 4.3.1 
struct Product* ListSearch(struct Product* p, char* userChoice);

// Function flushes input to prevent loop bugs
void flush_input( );
// of use skips the product selection
int userSkip(char userInput[]);

#endif 