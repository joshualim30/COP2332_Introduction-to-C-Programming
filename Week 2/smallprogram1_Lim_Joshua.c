// Joshua Lim
// Dr. Steinberg
// COP3223C Section 4
// Small Program 1

#include <stdio.h>

int main() {

    // Problem 1
    printf("VV          VV\n VV        VV\n  VV      VV\n   VV    VV\n    VV  VV\n     VVVV\n      VV\n");

    // Problem 2
    printf("Mileage Reimbursement Calculator\n");
    double beginningOdometer;
    printf("Enter beginning odometer reading=> ");
    scanf("%lf", &beginningOdometer);
    double endingOdometer;
    printf("Enter ending odometer reading=> ");
    scanf("%lf", &endingOdometer);
    double totalMiles = endingOdometer - beginningOdometer;
    printf("You traveled %0.1f miles.\n", totalMiles);
    double totalReimbusement = totalMiles * 2.61;
    printf("At $2.61 per mile, your reimbursement is $%0.2f\n", totalReimbusement);

    // Problem 3
    float weight;
    printf("Enter the weight in pounds: ");
    scanf("%f", &weight);
    float bmiHeight;
    printf("Enter the total height in inches: ");
    scanf("%f", &bmiHeight);
    float bmi = (weight*703)/(bmiHeight*bmiHeight);
    printf("BMI = %0.3f\n", bmi);

    // Problem 4
    double pi = 3.14159;
    double radius;
    printf("Enter the radius: ");
    scanf("%lf", &radius);
    double coneHeight;
    printf("Enter the height: ");
    scanf("%lf", &coneHeight);
    double third = (double) 1/3;
    double volume = (third)*pi*(radius*radius)*coneHeight;
    printf("The volume of the cone is %0.4lf", volume);

    return 0;

}

// Sample Text File 1:

// VV          VV
//  VV        VV
//   VV      VV
//    VV    VV
//     VV  VV
//      VVVV
//       VV
// Mileage Reimbursement Calculator
// Enter beginning odometer reading=> Enter ending odometer reading=> You traveled 7.0 miles.
// At $2.61 per mile, your reimbursement is $18.27
// Enter the weight in pounds: Enter the total height in inches: BMI = 3.649
// Enter the radius: Enter the height: The volume of the cone is 78.5397

// My Output:

// VV          VV
//  VV        VV
//   VV      VV
//    VV    VV
//     VV  VV
//      VVVV
//       VV
// Mileage Reimbursement Calculator
// Enter beginning odometer reading=> 5
// Enter ending odometer reading=> 12
// You traveled 7.0 miles.
// At $2.61 per mile, your reimbursement is $18.27
// Enter the weight in pounds: 6
// Enter the total height in inches: 34
// BMI = 3.649
// Enter the radius: 5
// Enter the height: 3
// The volume of the cone is 78.5397