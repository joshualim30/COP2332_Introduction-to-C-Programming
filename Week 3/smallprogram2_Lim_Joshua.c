// Joshua Lim
// Dr. Steinberg
// COP3223C Section 4
// Small Program 2

#include <stdio.h>
#include <math.h>

float coneSurfaceArea(double radius, double height, double pi);
void parkingCharge();
void wakandaPopulation();
double factorialApprox(int value);

int main() {
    
    // Problem 1
    double radius;
    printf("Enter the radius: ");
    scanf("%lf", &radius);
    double height;
    printf("Enter the height: ");
    scanf("%lf", &height);
    double pi = 3.14;
    float surfaceArea = coneSurfaceArea(radius, height, pi);
    printf("The total surface area of the cone is %0.2f\n", surfaceArea);

    // Problem 2
    parkingCharge();

    // Problem 3
    int year;
    printf("Enter a year after 2016: ");
    scanf("%d", &year);
    wakandaPopulation(year);

    // Problem 4
    int value;
    printf("Enter the value for n: ");
    scanf("%d", &value);
    double approx = factorialApprox(value);
    printf("%d! is approximately %0.4lf", value, approx);

    return 0;

}

float coneSurfaceArea(double radius, double height, double pi) {

    float surfaceArea = pi * radius * (radius + sqrt(pow(radius, 2) + pow(height, 2)));
    return surfaceArea;

}

void parkingCharge() {

    printf("Welcome to the Parking Garage! \n How many hours will you keep your car parked here> ");
    int hours;
    scanf("%d", &hours);
    float charge = hours * 4.21;
    printf("Car will be parked for %d hours and will be charged $%0.2lf.\n", hours, charge);

}

void wakandaPopulation(int year) {

    int time = year - 2016;
    float population = 51.451 + 4.239 * time;
    printf("Predicted Wakanda's population for %d (in thousands): %0.3lf\n", year, population);

}

double factorialApprox(int value) {

    double approx = pow(value, value) * exp(-value) * sqrt(((2 * value) + 1.0/3.0) * 3.14);
    return approx;

}