// Joshua Lim
// Dr. Steinberg
// COP3223 Section 4
// Small Program 8

// Importing libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 50

// Structure for the records
typedef struct{
    char * fname; //first name
	char * lname; //last name
	char * show; //favorite show
} record_t;

// Function prototypes
record_t * createArray(int maxsize);
record_t * insert(record_t *myarray, int *maxsize, int *currentsize); 
void display(record_t *myarray, int currentsize);
record_t * doubleIt(record_t *arr, int size); 
int removeRecord(record_t *arr, int size, int index); 
void freeRecords(record_t *arr, int size); 

// Main function
int main(void) {

    // Declaring variables
	int maxsize;
    // Ask user for the max size of the array
	printf("Enter a size for the dynamic array: ");
	scanf("%d", &maxsize);
    // Create the array
	record_t *myarray = createArray(maxsize);
	// Declaring variables
	int currentsize = 0;
	int option = -1;
    // While loop to keep the program running
	while(option != 0) { 
        // Ask user for the option
        printf("What would you like to do?\n");
        printf("1: Insert a record\n");
        printf("2: Display records\n");
        printf("3: Remove record\n");
        printf("4: Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);
        // Switch statement to determine the option
        switch(option) {

            case 1: // Insert a record
                printf("Insert was selected...\n");
                myarray = insert(myarray, &maxsize, &currentsize);
                break;

            case 2: // Display records
                printf("Display was selected...\n");
                display(myarray, currentsize);
                break;

            case 3: // Remove record
                printf("Remove was selected...\n");
                printf("Select an index of record to remove...\n");
                int index;
                scanf("%d", &index);
                currentsize = removeRecord(myarray,currentsize,index);
                break;

            case 4: // Exit
                printf("Exiting...\n");
                option = 0;
				break;

            default: // Invalid option
                printf("Invalid Selection...\n");

        }

    }
	// Free the memory
	freeRecords(myarray, currentsize);
	free(myarray);
    myarray = NULL;
	// Return 0
	return 0;

}

// Function to create the array
record_t * createArray(int maxsize) {
    // Allocate memory for the array
	record_t * arr = (record_t *) malloc(maxsize * sizeof(record_t));
	// Error allocating memory
	if (arr == NULL) {
		printf("malloc error in createArray...program exiting\n");
		exit(1);
	}
	// Return the array
	return arr;

}
// Function to display the records
void display(record_t *myarray, int currentsize) {

	printf("---------------------------------\n");
	for(int x = 0; x < currentsize; ++x) { // Loop through the array
        printf("myarray[%d].fname = %s\n", x, myarray[x].fname);
        printf("myarray[%d].lname = %s\n", x, myarray[x].lname);
        printf("myarray[%d].show = %s\n", x, myarray[x].show);
	}
	printf("---------------------------------\n");
    
}
// Function to insert a record
record_t * insert(record_t *myarray, int *maxsize, int *currentsize) {
    // Check if the array is full
    if (*currentsize == *maxsize) {
        // Double the size of the array
        printf("Array is full...Need to doubleIt...\n");
        myarray = doubleIt(myarray, *maxsize);
        *maxsize = *maxsize * 2;
    }
    // Allocate memory for the first name
    char firstName[LIMIT];
    char lastName[LIMIT];
    char show[LIMIT];
    // Ask user for the first name
    printf("Enter the first name: ");
    scanf("%s", firstName);
    // Aak user for the last name
    printf("Enter the last name: ");
    scanf("%s", lastName);
    // Ask user for the favorite show
    printf("Enter favorite show: ");
    getchar();
    fgets(show, LIMIT, stdin);
    // Allocate memory for the first name
    (myarray + *currentsize)->fname = (char *) malloc(sizeof(char) * strlen(firstName) + 1);
    strcpy((myarray + *currentsize)->fname, firstName);
    // Allocate memory for the last name
    (myarray + *currentsize)->lname = (char *) malloc(sizeof(char) * strlen(lastName) + 1);
    strcpy((myarray + *currentsize)->lname, lastName);
    // Allocate memory for the favorite show
    (myarray + *currentsize)->show = (char *) malloc(sizeof(char) * strlen(show) + 1);
    strcpy((myarray + *currentsize)->show, show);
    // Increment the current size
    *currentsize = *currentsize + 1;
    // Return the array
    return myarray;

}
// Function to double the size of the array
record_t * doubleIt(record_t *arr, int size) {
    // Allocate memory for the array
    record_t *temp = (record_t *) malloc(2 * size * sizeof(record_t));
    // Error allocating memory
    if (temp == NULL) {
        printf("malloc error in doubleIt...program exiting\n");
        exit(1);
    }
    // Copy the array
    for(int i = 0; i < size; ++i) {
        temp[i].fname = arr[i].fname;
        temp[i].lname = arr[i].lname;
        temp[i].show = arr[i].show;
    }
    // Free the memory
    free(arr);
    arr = NULL;
    // Return the array
    return temp;
}
// Function to insert a record
int removeRecord(record_t *arr, int size, int index) {
    // Check if the index is valid
    if (index < 0 || index >= size) {
        printf("Invalid index\n");
        return size;
    }
    // Free the memory
    free(arr[index].fname);
    free(arr[index].lname);
    free(arr[index].show);
    // Shift the array
    for(int i = index; i < size - 1; ++i) {
        arr[i].fname = arr[i + 1].fname;
        arr[i].lname = arr[i + 1].lname;
        arr[i].show = arr[i + 1].show;
    }
    // Return the size
    return size - 1;

}
// Function to free the memory
void freeRecords(record_t *arr, int size) {
    // Free the memory
    for (int i = 0; i < size; ++i) {
        free(arr[i].fname);
        free(arr[i].lname);
        free(arr[i].show);
    }

}