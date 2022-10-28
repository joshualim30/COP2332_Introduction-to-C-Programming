// Joshua Lim
// Dr. Steinberg
// COP3223C Section 4
// Small Program 5

#include <stdio.h>

void change(double *amountPaid, double *amountDue); // find change due
void resterauntReceipt(); // professor spelled restaurant wrong? required to spell functions as professor declares
void gradeDistribution(); // read grades.txt and print out a grade distribution
void incrementUpdate(int *val); // increment val by 1

// not done
int main(void) { // main function

    // Problem 1
    double amountPaid, amountDue;
    double *amountPaidPtr = &amountPaid;
    double *amountDuePtr = &amountDue;
    printf("Amount Due: ");
    scanf("%lf", &amountDue);
    printf("Amount Paid: ");
    scanf("%lf", &amountPaid);
    change(amountPaidPtr, amountDuePtr);

    // Problem 2
    resterauntReceipt();

    // Problem 3
    gradeDistribution();

    // Problem 4
    int val = 0;
    int *valPtr = &val;
    printf("Before calling incrementUpdate\n");
    printf("val = %d\n", val);
    incrementUpdate(valPtr);
    printf("val is now done updating...\n");
    printf("After calling incrementUpdate\n");
    printf("val = %d\n", val);

    return 0;

}

// done
void change(double *amountPaid, double *amountDue) { // find change due

    // initialize remaining and change
    double change = *amountPaid - *amountDue;
    int dollars = 0;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    double pennies = 0;

    while (change >= 1) { // find dollars
        dollars++;
        change = change - 1;
    }

    while ((change >= 0.25) && (change < 1)) { // find quarters
        quarters++;
        change = change - 0.25;
    }

    while ((change >= 0.10) && (change < 0.25)) { // find dimes
        dimes++;
        change = change - .1;
    }

    while ((change >= 0.05) && (change < 0.10)) { // find nickels
        nickels++;
        change = change - 0.05;
    }

    pennies = change * 100; // find pennies

    // print out change
    printf("Change\n");
    printf("%d dollars\n", dollars);
    printf("%d quarters\n", quarters);
    printf("%d dimes\n", dimes);
    printf("%d nickels\n", nickels);
    printf("%0.0lf pennies\n", pennies);

}

// done
void resterauntReceipt() { // print receipt, professor said not to worry about valid input in this function
    
    // Option | Item       | Price | Terminal Displays
    // 1      | Regular    | $5.00 | Adding regular to your order.
    // 2      | Special    | $5.95 | Adding special to your order.
    // 3      | Cheese     | $5.50 | Adding cheese to your order.
    // 4      | Fries      | $2.00 | Adding fries to your order.
    // 5      | Salad      | $2.50 | Adding salad to your order.
    // 6      | Soft Drink | $2.00 | Adding soft drink to your order.

    printf("Welcome to Bob's Burgers! Our burger of the day is Say Cheese Burger!\n");
    int runningOrder[6] = {0, 0, 0, 0, 0, 0}; // 0 index is regular, 1 index is special, 2 index is cheese, 3 index is fries, 4 index is salad, 5 index is soft drink
    int choice = 1; // initialize choice to 1 so that the while loop runs at least once
    while (choice != 0) { // loop until user enters 0, if 0, print receipt to myreceipt.txt and exit loop

        printf("Please enter your order by selecting the option number. Otherwise type 0 and your order receipt will be printed.\n");
        printf("-----------------------\n");
        printf("1: Regular	$5.00\n");
        printf("2: Special	$5.95\n");
        printf("3: Cheese	$5.50\n");
        printf("4: Fries	$2.00\n");
        printf("5: Salad	$2.50\n");
        printf("6: Soft Drink	$2.00\n");
        printf("-----------------------\n");
        printf("What will you add to your order: ");
        scanf("%d", &choice);

        switch (choice) {

            case 0: // generate & print receipt to myreceipt.txt file
            {
                printf("Order is now placed. Printing receipt.\n");
                FILE *receipt = fopen("myreceipt.txt", "w");
                fprintf(receipt, "Bob's Burgers Restaurant Receipt Order\n");
                fprintf(receipt, ("-----------------------\n"));
                fprintf(receipt, "%d Regular(s)\n", runningOrder[0]);
                fprintf(receipt, "%d Special(s)\n", runningOrder[1]);
                fprintf(receipt, "%d Cheese(s)\n", runningOrder[2]);
                fprintf(receipt, "%d Fries\n", runningOrder[3]);
                fprintf(receipt, "%d Salad(s)\n", runningOrder[4]);
                fprintf(receipt, "%d Soft Drink(s)\n", runningOrder[5]);
                fprintf(receipt, ("-----------------------\n"));
                fprintf(receipt, "Total: $%.2f\n", ((runningOrder[0] * 5.00) + (runningOrder[1] * 5.95) + (runningOrder[2] * 5.50) + (runningOrder[3] * 2.00) + (runningOrder[4] * 2.50) + (runningOrder[5] * 2.00)));
                fprintf(receipt, "Thank you and come again!\n");
                fclose(receipt);
                break;
            }
            case 1:
            {
                runningOrder[0]++;
                printf("Adding regular to your order.\n");
                break;
            }
            case 2:
            {
                runningOrder[1]++;
                printf("Adding special to your order.\n");
                break;
            }
            case 3:
            {
                runningOrder[2]++;
                printf("Adding cheese to your order.\n");
                break;
            }
            case 4:
            {
                runningOrder[3]++;
                printf("Adding fries to your order.\n");
                break;
            }
            case 5:
            {
                runningOrder[4]++;
                printf("Adding salad to your order.\n");
                break;
            }
            case 6:
            {
                runningOrder[5]++;
                printf("Adding soft drink to your order.\n");
                break;
            }
            default:
            {
                printf("Invalid choice, please try again.\n");
                break;
            }

        } 

    }

}

// done
void gradeDistribution() { // read grades.txt and print out a grade distribution

    // read grades.txt
    FILE *gradesTxt;
    gradesTxt = fopen("grades.txt", "r");

    if (gradesTxt == NULL) { // check if grades.txt exists
        printf("Error opening file.\n");
    }

    // initialize variables
    char grade; // initialize grade to be read from grades.txt
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    int F = 0;

    // read the letter of each line in grades.txt until it reaches the end of the file
    while (fscanf(gradesTxt, "%c", &grade) != EOF) {

        switch (grade) {

            case 'A':
            {
                A += 1;
                break;

            }
            case 'B':
            {
                B += 1;
                break;

            }
            case 'C':
            {
                C += 1;
                break;

            }
            case 'D':
            {
                D += 1;
                break;

            }
            case 'F':
            {
                F += 1;
                break;

            }

        }

    }

    // print grade distribution
    printf("Here is the grade distribution.\n");
    printf("A: %d\n", A);
    printf("B: %d\n", B);
    printf("C: %d\n", C);
    printf("D: %d\n", D);
    printf("F: %d\n", F);

    // close grades.txt
    fclose(gradesTxt);

}

// done
void incrementUpdate(int *val) { // increment val by 1

    int choice = 0;
    while (choice == 0) {
        
        printf("Updating val now...\n");
        *val += 1;
        printf("Would you like to update ...\n");
        printf("Enter 0 if you would like to update again. Anything else will exit the update.\n");
        printf("Option: ");
        scanf("%d", &choice);

    }

}