#include <stdio.h>

int main() {
    int menuChoice; //Basic menu for displaying whole Text files (text files just need some fixing to display proper).

    printf("The options for reports to display are:\n"); //Display options. NoteToSelf: (make sure the numbers match the file names in the next step).
    printf("1. Operating Systems\n");
    printf("2. Related Software\n");
    printf("3. Hypervisors\n");
    printf("4. Products\n");
    printf("Which report would you like to see? (enter the number): ");

    scanf("%d", &menuChoice); // USER inputs the number from menu.

    FILE *fptr = NULL; //open file and display the textfile the user wants. 

    if (menuChoice == 1) { 
        fptr = fopen("operatingSystems.txt", "r"); //user input 1
    } else if (menuChoice == 2) {
        fptr = fopen("relatedSoftware.txt", "r"); // user input 2
    } else if (menuChoice == 3) {
        fptr = fopen("hypervisors.txt", "r"); // user input 3
    } else if (menuChoice == 4) {
        fptr = fopen("products.txt", "r"); // user input 4
    } else {
        printf("Invalid choice. Please enter a number between 1 and 4 .\n"); //Wrong input 
		        return 1;
    }

    if (fptr == NULL) {
        printf("Error: Could not open the selected file. Tell admin to check file names \n");
        return 1;
    }

    char ch; // Not entirely sure what this one does, but it was in the example I saw so I'll leave it here meanwhile.
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }

    fclose(fptr); //Closes file. Don't remember what happens if this is not here so I'll leave it. IIRC, nothing major, just closes abruptly.
    return 0;
}