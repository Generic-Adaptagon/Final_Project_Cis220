#ifndef CODEPARSE_H
#define CODEPARSE_H
#define MAX_LINE_LENGTH 1024

// Structure definitions
typedef struct OS {
   char category[20]; //category String
   char id[10]; // Id string
   char name[50]; //name string
   char version[20]; // the version of the item
   char hardware[100];
   char releaseDate[20];// release date string
   struct OS* next; // pointer to next
} OS;

typedef struct Hypervisor {
   char id[10]; // Id string
   char name[50]; //name string
   char version[20]; // the version of the item
   char releaseDate[20];// release date string
   struct Hypervisor* next; // pointer to next
} Hypervisor;

typedef struct Software {
   char category[20]; //category String
   char id[10]; //id string
   char name[50]; //name string
   char version[20]; // the version of the item
   char releaseDate[20];// release date string
   struct Software* next; // pointer to next
} Software;

typedef struct Product {
   char id[10]; // Id string
   char name[50]; //name string
   char version[20]; // the version of the item
   char supportedOS[200];        // Store IDs of related OS (comma-separated)
   char supportedSoftware[200]; // Store IDs of related Software
   char supportedHypervisors[200]; // Store IDs of related Hypervisors
   struct Product* next; // pointer to next
} Product;

/*external declarations*/
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

OS* findOSByID(const char* id, struct OS* osHead);
Software* findSoftwareByID(const char* id, struct Software* softwareHead);
Hypervisor* findHypervisorByID(const char* id, struct Hypervisor* hypervisorHead);

#endif
