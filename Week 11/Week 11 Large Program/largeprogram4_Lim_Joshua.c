// Joshua Lim
// Dr. Steinberg
// COP3223 Section 4
// Large Program 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Structs
typedef struct {
    int id;
    char name[30];
    char type[20];
    int quantity;
    float price;
} inventory;

// Function Prototypes
void displayMenu();
void displayInventory(inventory *inv, int *size);
void insertInventory(inventory *inv, int *size);
void removeInventory(inventory *inv, int *size);
void searchInventory(inventory *inv, int *size);
void hardcodeSix(inventory *inv, int *size);
void writeToFile(inventory *inv, int *size);

int main() {
    // Variables
    int choice, size = 0;
    inventory inv[30];

    // Hardcode 6 records
    hardcodeSix(inv, &size);

    // Welcome Message
    printf("---------------------------------------------------------------\nAye Aye Captain! Welcome to the Krusty Krab Inventory Database!\n---------------------------------------------------------------");

    // Display Menu
    do {

        // Display Menu
        printf("\n");
        displayMenu();
        scanf("%d", &choice);

        // Switch Statement for Menu Options
        switch (choice) {
            case 1: // Insert Inventory
                printf("\n");
                insertInventory(inv, &size);
                break;
            case 2: // Remove Inventory
                printf("\n");
                removeInventory(inv, &size);
                break;
            case 3: // Search Inventory
                printf("\n");
                searchInventory(inv, &size);
                break;
            case 4: // Display Inventory
                printf("\n");
                displayInventory(inv, &size);
                break;
            case 5: // Exit
                printf("----------------------------------------------------------------\nThank you for using the Krusty Krab Inventory Database! Goodbye!\n----------------------------------------------------------------\n");
                exit(0);
                break;
            default:
                printf("Invalid input. Please try again.");
                break;
        }

    } while (choice != 6);

    return 0;

}

// Function Definitions
void displayMenu() { // Displays the menu

    printf("1. Insert\n");
    printf("2. Remove\n");
    printf("3. Search\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    printf("Please enter your choice: ");

}

void displayInventory(inventory *inv, int *size) { // Displays the inventory

   // Initialize MAX Variables for Formatting
    int maxName = 1, maxType = 1;

    // Find MAX Length of ID, Name and Type
    for (int i = 0; i < *size; i++) {
        if (maxName < strlen(inv[i].name)) {
            maxName = strlen(inv[i].name);
        }
        if (maxType < strlen(inv[i].type)) {
            maxType = strlen(inv[i].type);
        }
    }

    // Increase MAX Length by 1 for Formatting
    maxName += 1;
    maxType += 1;

    // Print Column Headers with Equal Spacing (left justified)
    printf("%-*s %-*s %-*s %-*s %-*s\n", 3, "ID", maxName, "Name", maxType, "Type", 10, "Quantity", 10, "Price");
    printf("%-*s %-*s %-*s %-*s %-*s\n", 3, "--", maxName, "----", maxType, "----", 10, "--------", 10, "-----");

    // Print Inventory with Equal Spacing (left justified)
    for (int i = 0; i < *size; i++) {
        printf("%-*d %-*s %-*s %-*d $%-*.2lf\n", 3, inv[i].id, maxName, inv[i].name, maxType, inv[i].type, 10, inv[i].quantity, 10, inv[i].price);
    }

}

void insertInventory(inventory *inv, int *size) { // Inserts a new record into the inventory

    // Check if Inventory is Full
    if (*size == 30) {
        printf("Inventory is full. Please remove an item before inserting a new one.\n");
        return;
    }

    // Get Name with spaces, await input & handle error
    int i = 0;
    do {
        printf("Please enter the name of the item: ");
        scanf(" %[^\n]s", inv[*size].name);
        for (i = 0; i < strlen(inv[*size].name); i++) {
            // check if name contains only letters and spaces
            if (!isalpha(inv[*size].name[i]) && !isspace(inv[*size].name[i])) {
                printf("Invalid input. Please try again.\n");
                break;
            }
        }
    } while (i < strlen(inv[*size].name));

    // Get Type with spaces, await input & handle error
    int j = 0;
    do {
        printf("Please enter the type of the item: ");
        scanf(" %[^\n]s", inv[*size].type);
        for (j = 0; j < strlen(inv[*size].type); j++) {
            // check if type contains only letters and spaces
            if (!isalpha(inv[*size].type[j]) && !isspace(inv[*size].type[j])) {
                printf("Invalid input. Please try again.\n");
                break;
            }
        }
    } while (j < strlen(inv[*size].type));

    // Get Quantity & Handle Error Input (check if quantity is a number and greater than 0, if not, ask for input again)
    int k = 0;
    do {
        printf("Please enter the quantity of the item: ");
        scanf("%d", &inv[*size].quantity);
        fflush(stdin);
        if (inv[*size].quantity <= 0) {
            printf("Invalid input. Please try again.\n");
        } else {
            k = 1;
        }
    } while (k == 0);

    // Get Price & Handle Error Input (check if price is a number and greater than 0, if not, ask for input again)
    int x = 0;
    do {
        printf("Please enter the price of the item: ");
        scanf("%f", &inv[*size].price);
        fflush(stdin);
        if (inv[*size].price <= 0 ) {
            printf("Invalid input. Please try again.\n");
            return;
        } else {
            x = 1;
        }
    } while (x == 0);

    // Increment ID by 1 of previous item
    inv[*size].id = inv[*size - 1].id + 1;

    // Increment Size
    *size += 1;
    
    // Write to File
    writeToFile(inv, size);

}

void removeInventory(inventory *inv, int *size) { // Remove Inventory

    // Ask how to remove
    int choice;
    printf("How would you like to remove an item?\n");
    printf("1. By ID\n");
    printf("2. By Name\n");
    printf("3. By Type\n");
    do {
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > 3) { // check if choice is 1, 2 or 3
            printf("Invalid input. Please try again.\n");
        }
    } while (choice < 1 || choice > 3);

    if (choice == 1) { // Remove by ID
        int id;
        printf("Please enter the ID of the item: ");
        scanf("%d", &id);
        for (int i = 0; i < *size; i++) { // Find ID
            if (inv[i].id == id) { // If ID is found
                for (int j = i; j < *size; j++) { // Shift all items after removed item to the left
                    inv[j] = inv[j + 1];
                }
                *size -= 1;
                printf("Item removed.\n");
                return;
            }
        }
        printf("Item not found.\n");
    } else if (choice == 2) { // Remove by Name
        char name[30];
        printf("Please enter the name of the item: ");
        scanf(" %[^\n]s", name);
        for (int i = 0; i < *size; i++) { // Search for name
            if (strcmp(inv[i].name, name) == 0) { // strcmp returns 0 if strings are equal
                for (int j = i; j < *size; j++) { // Shift all items after removed item to the left
                    inv[j] = inv[j + 1];
                }
                *size -= 1;
                printf("Item removed.\n");
                return;
            }
        }
        printf("Item not found.\n");
    } else if (choice == 3) { // Remove by Type (remove all items of that type)
        char type[30];
        printf("Please enter the type of the item: ");
        scanf(" %[^\n]s", type);
        for (int i = 0; i < *size; i++) { // Loop through inventory
            if (strcmp(inv[i].type, type) == 0) { // If type matches
                for (int j = i; j < *size; j++) { // Loop through inventory starting at match
                    inv[j] = inv[j + 1]; // Shift items to the left
                }
                *size -= 1; // Decrement size
                i--; // Decrement i to check for more matches
            }
        }
        printf("Item(s) removed.\n");
    }

}

void searchInventory(inventory *inv, int *size) { // Search Inventory

    // Ask how to search
    printf("Would you like to search by?\n");
    printf("1. ID\n");
    printf("2. Name\n");
    printf("3. Type\n");
    printf("Please enter your selection: ");
    int selection;
    do { // Handle Error Input
        scanf("%d", &selection);
        if (selection < 1 || selection > 3) {
            printf("Invalid input. Please try again.\n");
        }
    } while (selection < 1 || selection > 3);

    // Toggle Selection
    switch (selection) {
        case 1: // Search by ID
            if (*size == 0) { // Check if Inventory is Empty
                printf("Inventory is empty. Please insert an item before searching.\n");
                return;
            }
            int id;
            int index;
            // check if id exists
            do { // Handle Error Input
                printf("Please enter the ID of the item: ");
                scanf("%d", &id);
                for (int i = 0; i < *size; i++) {
                    if (inv[i].id == id) { // If ID exists
                        index = i;
                        break;
                    }
                    if (i == *size - 1) { // If ID does not exist
                        printf("Item not found. Please try again.\n");
                    }
                }
            } while (inv[index].id != id);
            // print item
            printf("ID found with the following information:\n");
            printf("--------------------\nID: %d\nName: %s\nType: %s\nQuantity: %d\nPrice: %.2f\n--------------------\n", inv[index].id, inv[index].name, inv[index].type, inv[index].quantity, inv[index].price);
            break;
        case 2: // Search by Name
            if (*size == 0) { // Check if inventory is empty
                printf("Inventory is empty. Please insert an item before searching.\n");
                return;
            }
            char name[20];
            int i = 0;
            do { // Handle Error Input
                printf("Please enter the name of the item you would like to search for: ");
                scanf("%s", name);
                for (int i = 0; i < strlen(name); i++) {
                    // check if name contains only letters and spaces
                    if (!isalpha(name[i]) && !isspace(name[i])) {
                        printf("Invalid input. Please try again.\n");
                        break;
                    }
                }
            } while (i < strlen(name));
            // check if name exists in inventory
            for (i = 0; i < *size; i++) {
                if (strcmp(inv[i].name, name) == 0) { // if name matches
                    printf("Name found with the following information:\n");
                    printf("--------------------\nID: %d\nName: %s\nType: %s\nQuantity: %d\nPrice: $%.2lf\n--------------------\n", inv[i].id, inv[i].name, inv[i].type, inv[i].quantity, inv[i].price);
                    break;
                } else if (i == *size - 1) { // if name not found
                    printf("Item not found in inventory.\n");
                }
            }
            break;
        case 3: // Search by Type
            if (*size == 0) { // Check if inventory is empty
                printf("Inventory is empty. Please insert an item before searching.\n");
                return;
            }
            char type[20];
            int j = 0;
            do { // Handle Error Input
                printf("Please enter the type of the item you would like to search for: ");
                scanf("%s", type);
                for (int j = 0; j < strlen(type); j++) {
                    // check if type contains only letters and spaces
                    if (!isalpha(type[j]) && !isspace(type[j])) {
                        printf("Invalid input. Please try again.\n");
                        break;
                    }
                }
            } while (j < strlen(type));
            for (int i = 0; i < *size; i++) { // Loop through inventory
                if (strcmp(inv[i].type, type) == 0) { // If type matches
                    printf("The type '%s' has the following items:\n", type);
                    while (strcmp(inv[i].type, type) == 0) { // Loop through inventory starting at match
                        printf("--------------------\nID: %d\nName: %s\nType: %s\nQuantity: %d\nPrice: $%.2lf\n--------------------\n", inv[j].id, inv[j].name, inv[j].type, inv[j].quantity, inv[j].price);
                        i++;
                    }
                } else if (i == *size - 1) { // If type doesn't match
                    printf("Item with given type not found in inventory.\n");
                }
            }
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

}

void hardcodeSix(inventory *inv, int *size) { // Hardcode 6 items

    inv[0].id = 1;
    strcpy(inv[0].name, "Krabby Patty");
    strcpy(inv[0].type, "Sandwich");
    inv[0].quantity = 100;
    inv[0].price = 1.99;

    inv[1].id = 2;
    strcpy(inv[1].name, "Kelp Shake");
    strcpy(inv[1].type, "Drink");
    inv[1].quantity = 50;
    inv[1].price = 2.99;

    inv[2].id = 3;
    strcpy(inv[2].name, "Kelp Rings");
    strcpy(inv[2].type, "Appetizer");
    inv[2].quantity = 25;
    inv[2].price = 1.49;

    inv[3].id = 4;
    strcpy(inv[3].name, "Kelp Fries");
    strcpy(inv[3].type, "Appetizer");
    inv[3].quantity = 25;
    inv[3].price = 1.49;

    inv[4].id = 5;
    strcpy(inv[4].name, "Kelp Soda");
    strcpy(inv[4].type, "Drink");
    inv[4].quantity = 50;
    inv[4].price = 1.99;

    inv[5].id = 6;
    strcpy(inv[5].name, "Krabby Deluxe");
    strcpy(inv[5].type, "Sandwich");
    inv[5].quantity = 100;
    inv[5].price = 2.99;

    *size = 6;

    // Write to file
    writeToFile(inv, size);

}

void writeToFile(inventory *inv, int *size) { // Write to file

    // Initialize MAX Variables for Formatting
    int maxName = 0, maxType = 0;

    // Find MAX Length of ID, Name and Type
    for (int i = 0; i < *size; i++) {
        if (maxName < strlen(inv[i].name)) {
            maxName = strlen(inv[i].name);
        }
        if (maxType < strlen(inv[i].type)) {
            maxType = strlen(inv[i].type);
        }
    }

    // Increment MAX Variables by 1 for Formatting
    maxName += 1;
    maxType += 1;

    // Open File
    FILE *fp;
    fp = fopen("Records.txt", "w");

    // Write Column Headers with Equal Spacing (left justified)
    fprintf(fp, "%-*s %-*s %-*s %-*s %-*s\n", 3, "ID", maxName, "Name", maxType, "Type", 10, "Quantity", 10, "Price");
    fprintf(fp, "%-*s %-*s %-*s %-*s %-*s\n", 3, "--", maxName, "----", maxType, "----", 10, "--------", 10, "-----");

    // Write Inventory with Equal Spacing (left justified)
    for (int i = 0; i < *size; i++) {
        fprintf(fp, "%-*d %-*s %-*s %-*d $%-*.2lf\n", 3, inv[i].id, maxName, inv[i].name, maxType, inv[i].type, 10, inv[i].quantity, 10, inv[i].price);
    }

    fclose(fp);

}