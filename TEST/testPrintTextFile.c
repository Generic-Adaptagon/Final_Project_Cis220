#include <stdio.h>
//This one displays a whole text file.
int main() {

//Selects which whole textfile the user wants to see:

//printf("Please input the report you want to see");
//scanf(


    // Open file in read mode
    FILE *fptr = fopen("hypervisors.txt", "r");

    // Check if the file was opened successfully
    if (fptr == NULL) {
		printf("failed to display text file");
        return 1;
    }

    // Read and print each character from the file
    char ch;
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }

    // Close the file after reading
    fclose(fptr);
    return 0;
}