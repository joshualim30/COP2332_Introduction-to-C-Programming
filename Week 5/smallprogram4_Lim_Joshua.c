// Joshua Lim
// Dr. Steinberg
// COP3223C Section 4
// Small Program 4

#include <stdio.h>

void perfectSquare();
void elevator();
void pyramid();
double classAvg(int);

// loops need to break and wait for scanf if invalid input is entered (only fails for type char)
int main() {

    // Problem 1
    perfectSquare();

    // Problem 2
    elevator();

    // Problem 3
    pyramid();

    // Problem 4
    int initiate = 0;
    int classSize = 0;
    while (classSize <= 0 || classSize != (int)classSize) { // loop until valid input is entered for class size
        if (initiate == 0) {
            printf("How many students are in the class: ");
            scanf("%d", &classSize);
            initiate = 1;
        } else {
            printf("Invalid input. Please try again.\n");
            printf("How many students are in the class: ");
            scanf("%d", &classSize);
        }
    }
    double average = classAvg(classSize); // call function to calculate average
    printf("The class average on the field trip exam was a %.4f%%", average);

    return 0;

}

void perfectSquare() {

    // collect size of square
    int size;
    printf("How big would you like the square to be?: ");
    scanf("%d", &size);
    // check if size is entered as a positive integer & an integer
    if (size <= 0 || size != (int)size) {
        // printf("\033[1;31m"); // change text color to red - not needed, example output showcased red styling in result, falsly assumed it was required
        printf("Invalid");
        // printf("\033[0m"); // reset text color - not needed, example output showcased red styling in result, falsly assumed it was required
        printf(" Input. Please try again.\n");
        perfectSquare(); // call function again

    } else {

        // print top row
        for (int i = 0; i < size; i++) {
            printf("*");
        }
        printf("\n");
        // print middle rows
        for (int i = 0; i < size - 2; i++) {
            printf("*");
            for (int j = 0; j < size - 2; j++) {
                printf(" ");
            }
            printf("*\n");
        }
        // print bottom row
        for (int i = 0; i < size; i++) {
            printf("*");
        }
        printf("\n");

    }

}

void elevator() {

    // welcome user
    printf("Welcome to the Elevator Ride.\n");
    // ask which floor
    int floor = 0;
    while (floor != 5) {
        printf("Which floor would you like to go to? ");
        scanf("%d", &floor);
        // check if floor is valid
        if (floor < 1 || floor > 12 || floor != (int)floor) {

            printf("That is not a valid option.\n");

        } else { // print floor

            switch (floor) {
                case 1:
                    printf("Welcome to the first floor.\n");
                    break;
                case 2:
                    printf("Welcome to the second floor.\n");
                    break;
                case 3:
                    printf("Welcome to the third floor.\n");
                    break;
                case 4:
                    printf("Welcome to the fourth floor.\n");
                    break;
                // case 5:
                //     printf("Welcome to the fifth floor.\n"); - not needed because it is the exit
                //     break; 
                case 6:
                    printf("Welcome to the sixth floor.\n");
                    break;
                case 7:
                    printf("Welcome to the seventh floor.\n");
                    break;
                case 8:
                    printf("Welcome to the eighth floor.\n");
                    break;
                case 9:
                    printf("Welcome to the ninth floor.\n");
                    break;
                case 10:
                    printf("Welcome to the tenth floor.\n");
                    break;
                case 11:
                    printf("Welcome to the eleventh floor.\n");
                    break;
                case 12:
                    printf("Welcome to the twelfth floor.\n");
                    break;  

            } 

        }

    }
    // user is on floor 5
    printf("Elevator door is now open. Please exit now.\n");

}

void pyramid() {

    // collect size of pyramid
    int size;
    printf("How many steps would you like in the pyramid? ");
    scanf("%d", &size);
    // check if size is entered as a positive integer & an integer
    if (size <= 0 || size != (int)size) {
        printf("Invalid Input. Please try again.\n");
        pyramid();
    } else { // print pyramid

        // print top half
        int top = 1;
        while (top < size) {
            if (top == 1) { // first row

                printf("-\n");

            } else { // other rows
                for (int i = 0; i < top; i++) {
                    // if (i == 0) {
                    //     printf("-");
                    // } else { - this was used because the example image had a space between each dash, but was wrongly marketed and not needed for the assignment
                    //     printf(" -");
                    // }
                    printf("-");
                }
                printf("\n");
            }
            top++;
        }

        // print middle row
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                printf("-\n");
            } else {
                // printf("- "); - this was used because the example image had a space between each dash, but was wrongly marketed and not needed for the assignment
                printf("-");
            }
        }

        // print bottom half
        int bottom = size - 1;
        while (bottom > 0) {
            if (bottom == 1) { // last row

                printf("-\n");

            } else { // other rows
                for (int i = 0; i < bottom; i++) {
                    // if (i == 0) {
                    //     printf("-");
                    // } else { - this was used because the example image had a space between each dash, but was wrongly marketed and not needed for the assignment
                    //     printf(" -");
                    // }
                    printf("-");
                }
                printf("\n");
            }
            bottom--;
        }

    }

}

double classAvg(int numStudents) {

    // collect grades
    double runningGradeTotal = 0.0; // since I can't use arrays, I will use a running total which is way less efficient
    for (int i = 0; i < numStudents; i++) {
        double grade;
        printf("Enter the student's test score: ");
        scanf("%lf", &grade);
        // check if grade is valid
        if (grade < 0 || grade > 100 || grade != (double)grade) {
            printf("Invalid Student Score. Please try again.\n");
            i--;
        } else { // add grade to running total
            runningGradeTotal += grade;
        }
    }

    // calculate average
    return runningGradeTotal / numStudents;

}