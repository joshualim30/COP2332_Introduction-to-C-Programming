// Joshua Lim
// Dr. Steinberg
// COP3223C Section 4
// Small Program 6

#define SIZE 1000
#include <stdio.h>
#include <stdlib.h>

void display(int arr[]);
void meanMinMax(int array[], int size); // function to calculate mean, min, and max
void mySort(int array[], int size); // function to sort array in increasing order
void doubleShift(int array[], int size); // function to shift array values to the right by 2
void reverse(int array[], int size); // function to reverse the array

int main(void) {

	int arr[SIZE];
	int seed;
	printf("Enter a seed: ");
	
	scanf("%d", &seed);
	srand(seed);
	
	//generate numbers for the array
	for (int x = 0; x < SIZE; x++)
	{
		arr[x] = (rand() % (1000 - 1 + 1)) + 1; //1-1000
	}
	
	//call your functions for small program 6
	// Problem 1
	meanMinMax(arr, SIZE);

	// Problem 2
	mySort(arr, SIZE);
	display(arr);

	// Problem 3
	doubleShift(arr, SIZE);
	display(arr);

	// Problem 4
	reverse(arr, SIZE);
	display(arr);

	return 0;
	
}

void display(int arr[]) {

	for (int x = 0; x < SIZE; x++)
		printf("%6d ", arr[x]);
	
	printf("\n");

}

void meanMinMax(int array[], int size) {

	// initialize variables
	int min = array[0];
	int max = array[0];
	int sum = 0;
	double mean = 0.0;
	
	for (int i = 0; i < size; i++) { // loop through array

		if (array[i] < min) // if current element is less than min, set min to current element
			min = array[i];
		if (array[i] > max) // if current element is greater than max, set max to current element
			max = array[i];
		sum += array[i]; // add current element to sum

	}
	
	// get decimal value of mean
	mean = (double) sum / size;

	// print out results
	printf("Average: %f\n", mean);
	printf("Max: %d\n", max);
	printf("Min: %d\n\n", min);

}

void mySort(int array[], int size) { // function to sort array in increasing order

	int temp = 0; // temporary variable to hold value of array[i] while swapping
	
	for (int i = 0; i < size; i++) { // loop through array

		for (int j = i + 1; j < size; j++) { // loop through array again to compare values

			if (array[i] > array[j]) { // if array[i] is greater than array[j], swap values

				// swap values
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;

			} // end if

		} // end of inner for loop

	} // end of outer for loop

}

void doubleShift(int array[], int size) { // function to shift array values to the right by 2 (move each value 2 indices to the right)

	// create temporary copy of array
	int arrayCopy[SIZE];
	for (int i = 0; i < size; i++)
		arrayCopy[i] = array[i];

	for (int i = 0; i < size; i++) { // loop through array

		if (i + 2 < size) // if i + 2 is less than size, shift value 2 indices to the right
			array[i + 2] = arrayCopy[i];
		else // if i + 2 is greater than size, shift value to the beginning of the array
			array[i + 2 - size] = arrayCopy[i];

	} // end of for loop

}

void reverse(int array[], int size) { // function to reverse the array backwards

	// initialize variables
	int temp = 0;
	int j = size - 1;

	for (int i = 0; i < size / 2; i++) { // loop through array

		// swap values
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;

		j--; // decrement j

	} // end of for loop

}