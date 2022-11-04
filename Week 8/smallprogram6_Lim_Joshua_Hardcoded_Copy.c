// Joshua Lim
// Dr. Steinberg
// COP3223C Section 4
// Small Program 6

// #define SIZE 10
#define SIZE 1000
#include <stdio.h>
#include <stdlib.h>

void display(int arr[]);
void meanMinMax(int array[], int size); // function to calculate mean, min, and max
void mySort(int array[], int size); // function to sort array in increasing order
void doubleShift(int array[], int size); // function to shift array values to the right by 2
void reverse(int array[], int size); // function to reverse the array

int main(void) {

	// int arr[10] = { 8, 9, 1, 7, 2, 3, 5, 4, 6, 0 };
	int arr[SIZE] = { 1,1,3,3,5,7,9,10,11,12,12,13,17,18,18,19,20,22,22,22,22,23,24,26,28,28,29,30,31,31,31,32,33,34,35,37,37,37,40,41,42,43,43,43,44,44,47,48,50,50,51,52,53,54,55,56,58,58,58,59,60,60,60,61,63,64,68,68,70,72,72,73,74,75,75,81,82,82,82,82,82,83,83,85,85,85,85,87,88,88,89,91,91,91,92,94,95,96,98,98,98,99,100,101,101,106,108,110,110,115,116,117,118,118,121,122,123,123,124,125,125,126,127,127,128,128,128,128,129,131,132,132,134,135,135,136,137,138,140,140,143,144,145,148,150,150,151,152,153,154,155,155,156,158,158,158,160,160,164,168,169,171,172,172,173,173,173,174,177,178,179,180,180,180,182,182,182,184,185,189,190,190,190,191,191,191,194,196,196,197,198,198,199,200,200,203,203,205,206,206,206,207,208,210,211,212,212,212,215,216,218,218,219,219,220,223,224,225,225,226,227,227,228,229,229,229,230,232,232,232,233,233,234,235,235,236,236,237,238,238,239,245,246,249,250,251,254,254,255,256,256,259,260,261,262,263,263,267,267,270,270,270,271,271,271,273,274,275,276,277,279,279,281,282,282,283,284,284,285,286,286,287,290,290,291,292,292,293,293,293,295,297,298,298,299,299,300,300,302,302,304,304,305,306,306,307,309,309,310,310,311,312,313,313,314,315,315,316,318,321,322,322,325,325,325,326,326,327,328,329,334,335,336,336,336,337,337,337,338,339,339,339,340,341,341,341,341,343,343,344,344,347,347,348,349,349,351,351,351,354,356,356,356,359,359,361,361,363,364,364,365,366,366,368,368,368,369,369,369,369,369,370,371,373,374,376,377,377,378,379,379,380,380,380,380,380,383,383,384,386,387,387,389,391,391,394,394,396,397,399,399,400,404,404,405,405,405,408,413,413,413,414,415,416,416,417,418,418,419,422,422,422,423,423,426,427,427,428,429,429,429,430,430,432,433,434,434,435,435,436,437,438,438,439,441,442,444,444,445,445,446,446,452,453,457,458,459,460,461,461,463,465,466,467,468,469,471,472,475,477,479,480,482,484,484,484,486,487,487,488,489,491,491,492,492,493,493,494,495,498,498,499,500,500,501,501,501,504,504,505,505,506,506,507,507,507,508,513,517,517,519,519,522,523,523,525,525,526,526,527,529,529,529,529,529,530,530,530,531,533,533,536,537,538,538,539,539,540,540,541,542,543,543,544,546,551,552,552,553,553,556,556,557,560,561,561,564,564,567,567,568,568,568,568,569,570,570,571,571,572,574,574,575,575,578,579,580,581,582,583,583,584,585,587,587,588,588,590,591,591,591,594,594,594,596,597,600,601,602,604,605,606,607,607,608,611,611,612,614,614,615,615,619,619,619,620,621,622,622,623,623,625,625,626,627,627,628,630,631,632,634,638,638,640,640,641,641,642,642,644,645,648,648,649,650,652,652,653,654,658,658,659,660,661,662,662,668,669,670,673,673,676,677,678,678,682,682,683,683,683,684,684,685,686,686,686,687,689,690,691,691,692,693,698,699,700,700,702,704,706,709,709,709,710,711,711,712,714,714,714,715,716,716,718,721,721,722,723,723,724,724,726,727,729,730,730,730,730,731,733,733,733,736,737,737,740,741,744,744,744,745,747,747,748,749,751,754,755,755,755,757,757,758,760,762,763,764,764,764,765,765,769,770,771,771,772,773,774,775,776,777,777,777,777,777,778,778,783,784,784,785,785,787,788,789,789,790,792,794,794,795,795,796,796,797,797,798,798,802,803,805,806,806,806,806,807,809,809,811,812,813,814,814,815,815,816,819,819,819,820,820,821,822,823,826,827,828,829,830,830,831,837,840,840,841,842,843,847,847,848,849,850,851,851,851,852,854,857,857,857,858,858,858,858,859,859,860,861,861,863,863,863,866,866,869,869,872,873,874,874,874,876,879,882,883,885,887,887,888,889,889,889,891,891,893,893,893,895,896,899,899,899,900,900,901,903,903,905,905,905,905,908,909,911,912,915,916,917,918,918,919,920,920,921,922,922,925,925,926,926,927,927,928,929,929,930,931,931,932,933,933,934,934,935,937,937,940,941,944,945,946,947,948,950,950,951,951,952,953,955,955,955,956,956,956,957,959,960,960,962,963,964,965,966,968,970,971,971,972,973,974,976,977,978,978,981,982,982,983,983,985,985,988,988,989,990,991,991,992,994,994,995,995,997,997,997,997,997,998,1000 };
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