#ifndef CODEPARSE_H
#define CODEPARSE_H
#define MAX_LINE_LENGTH 1024

// Structure definitions
typedef struct OS {
   char category[20]; //WIP Added these missing ones -LM
   char id[10];
   char name[50];
   char version[20];
   char hardware[100];
   char releaseDate[20];
   struct OS* next;
} OS;

typedef struct Hypervisor {
   char id[10];
   char name[50];
   char version[20];
   char releaseDate[20];
   struct Hypervisor* next;
} Hypervisor;

typedef struct Software {
   char category[20]; //WIP Added these missing category for printing later  -LM
   char id[10];
   char name[50];
   char version[20];
   char releaseDate[20];
   struct Software* next;
} Software;

typedef struct Product {
   char id[10];
   char name[50];
   char version[20];
   char supportedOS[200];        // Store IDs of related OS (comma-separated)
   char supportedSoftware[200]; // Store IDs of related Software
   char supportedHypervisors[200]; // Store IDs of related Hypervisors
   struct Product* next;
} Product;

extern OS* osHead;
extern Hypervisor* hypervisorHead;
extern Software* softwareHead;
extern Product* productHead;

// Function declarations
void parseLine(char* line, const char* delimiter, void* item, int type);
//void loadData(const char* filename, int type); retired by Ivan
void loadOSData (const char* filename, struct OS* os);
void loadHypeData (const char* filename, struct Hypervisor* hypeHead);
void loadSoftData (const char* filename, struct Software* softHead);
void loadProductData (const char* filename, struct Product* prodHead);

OS* findOSByID(const char* id);
Software* findSoftwareByID(const char* id);
Hypervisor* findHypervisorByID(const char* id);

#endif
