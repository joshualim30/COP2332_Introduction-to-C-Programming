// Joshua Lim
// Dr. Steinberg
// COP3223C Section 4
// Small Program 3

#include <stdio.h>

void letters();
void greenLawyer();
void coordinates(double x, double y);
int triangle(int a, int b, int c);

int main() {

    // Problem 1
    letters();

    // Problem 2
    greenLawyer();

    // Problem 3
    double xCoordinate;
    double yCoordinate;
    printf("Enter the x-coordinate: ");
    scanf("%lf", &xCoordinate);
    printf("Enter the y-coordinate: ");
    scanf("%lf", &yCoordinate);
    coordinates(xCoordinate, yCoordinate);

    // Problem 4
    int a;
    int b;
    int c;
    printf("Enter three sides separated by a whitespace: ");
    scanf("%d %d %d", &a, &b, &c);
    int validation = triangle(a, b, c);
    if (validation == 1) {
        printf("Triangle!");
    } else if (validation == -1) {
        printf("Not Triangle!");
    } else {
        printf("Error!");
    }

    return 0;

}

void letters() {

    char letter;
    printf("Enter a key from the keyboard: ");
    scanf("%c", &letter);
    if (letter >= 'a' && letter <= 'z') {
        printf("Lower!\n");
    } else if (letter >= 'A' && letter <= 'Z') {
        printf("Upper!\n");
    } else {
        printf("Not a letter!\n");
    }

}

void greenLawyer() {

    printf("Hi! Thank you for calling the Superhuman Law Division at GLK&H!\n");
    printf("Our associates are currently working hard for super people like you.\n");
    printf("Please listen carefully to the options of who you would like to speak to in regards to your situation.\n");
    printf("Option 1: Fined for thousands of dollars worth of damage to the city you were trying to protect.\n");
    printf("Option 2: Accidentally create a sentient robot who got the feels and tried to destroy the world.\n");
    printf("Option 3: You are an Asgardian god who unintentionally leaves a giant burning imprint on private\nproperty every time you visit Earth.\n");
    printf("Option 4: You just gained new superhero strength that is not recognized by the department of\ndamage control, and they are chasing you down after you performed a good deed.\n");
    printf("Option 5: Your secret identity was revealed by a notorious person and now your personal life\nis no longer the same.\n");
    printf("Option 6: Another super being issue that was not mentioned previously in the options given.\n");
    int option;
    printf("Selection: ");
    scanf("%d", &option);
    switch (option) {
        case 1:
            printf("You have selected option 1. Do not worry! I will make sure you don't give up that green.\n");
            break;
        case 2:
            printf("You have selected option 2. Do not worry! You probably had a good intention that just didn't work out propperly\n");
            break;
        case 3:
            printf("You have selected option 3. Do not worry! I understand you like to make a grand entrance.\n");
            break;
        case 4:
            printf("You have selected option 4. Do not worry! We will talk to the department of damage control.\n");
            break;
        case 5:
            printf("You have selected option 5. Do not worry! We will make sure you are protected. Please be cautious if you decide to seek Dr. Strange's help.\n");
            break;
        case 6:
            printf("You have selected option 6. Do not worry! I will make sure to use my superhero mind to solve your problem!\n");
            break;
        default:
            printf("I'm sorry. I don't recognize that super being option.\n");
            break;

    }

}

void coordinates(double x, double y) {

    if (x > 0 && y > 0) {
        printf("(%.2lf, %.2lf) is in quadrant I.\n", x, y);
    } else if (x < 0 && y > 0) {
        printf("(%.2lf, %.2lf) is in quadrant II.\n", x, y);
    } else if (x < 0 && y < 0) {
        printf("(%.2lf, %.2lf) is in quadrant III.\n", x, y);
    } else if (x > 0 && y < 0) {
        printf("(%.2lf, %.2lf) is in quadrant IV.\n", x, y);
    } else if (x == 0 && y == 0) {
        printf("(%.2lf, %.2lf) is at the origin.\n", x, y);
    } else if (x == 0 && y != 0) {
        printf("(%.2lf, %.2lf) is on the y-axis.\n", x, y);
    } else if (x != 0 && y == 0) {
        printf("(%.2lf, %.2lf) is on the x-axis.\n", x, y);
    }

}

int triangle(int a, int b, int c) {

    int validation = 0;
    printf("Checking these logistics from the input.\n");
    printf("%d + %d > %d\n", a, b, c);
    printf("%d + %d > %d\n", a, c, b);
    printf("%d + %d > %d\n", b, c, a);
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        return 1;
    } else {
        return -1;
    }

}