//============================================================================

//

// Name        : Pretest_Question1.cpp

// Author      : Paul Grubb, Carson Sharpless

// Version     : 1.0.0

// Date        : February 7th, 2019

// Description : generates a sequence of twenty random values between 0 and 99 in an array.

//				 Print the sequence, sort the array, and print the sorted sequence.

// Functions   : int generate(int string[20 length], constant int length) - Generates numbers to fill array

//               void print(int string[20 length], constant int length) - prints out array

//               int sort(int string[20 length], constant int length) - sorts numbers in array

//               int destroyArray(int string[20 length], constant int length) - sets array to NULL to erase data

//

//============================================================================





#define fstackprotectorall //stack canary 

//#include "stdafx.h"    // 

#include <iostream>  // for cout and basic inputs and outputs. Done by Paul Grubb.

#include <stdio.h>

#include <cmath>    // for the Random Number Gen. Done by Paul Grubb.

#include <math.h>

using namespace std;





/////////////////////////////////////////// Function Call ///////////////////////////////////////////







class Class					//Done by Paul Grubb for In-Class 2.

{

public:

	int array[20];   // the array that holds all of the data for the program. Done by Paul Grubb.

};



void generate(Class&); // Function that generates the random numbers. Done by Paul Grubb.

void print(Class&); // Function that prints the numbers. Done by Paul Grubb.

void sort(Class&); // Function that sort the numbers from largest to smallest. Done by Paul Grubb.

int destroyArray(Class&); // Function that zeros out all the data in the array. Done by Paul Grubb.



/////////////////////////////////////////// Main ///////////////////////////////////////////



int main()

{

	Class Agr;							//Call the class Done by Paul Grubb.

	destroyArray(Agr);					//Ensure there is nothing within the class Array. Done by Paul Grubb.

	generate(Agr);						//Generate the array and list of random numbers from 0-99. Done by Paul Grubb.

	print(Agr);							//Prints out the array. Done by Paul Grubb.

	sort(Agr);							//Sorts the array from largest to  smallest numbers Done by Paul Grubb.

	print(Agr);							//Prints the sorted array Done by Paul Grubb.

	destroyArray(Agr);					//Destroys array and its contents Done by Paul Grubb.


										//ending program
										//character to end program

	cout << "End Program - Press any key to continue... ";

	return 0;



}



/////////////////////////////////////////// Functions ///////////////////////////////////////////

// Arg.array is the array to be destroyed

int destroyArray(Class& Arg) {							//Done by Paul Grubb for In-Class 2.

	for (int i = 0; i < 20; i++) { Arg.array[i] = 0; } // zeros out the array and removes data. Done by Paul Grubb.

	return 0;

}


// fills the array with numbers between 0 and 99
// Arg.array is the array to be filled


void generate(Class& Arg)								//Done by Paul Grubb for In-Class 2.

{

	cout << "Generating numbers and putting into array...\n";

	int num = 1; // int to hold generated numbers. Done by Paul Grubb.

	for (int i = 0; i < 20; i++) // for loop that loops though and generates the numbers. Done by Paul Grubb.

	{

		num = rand() % 105;  // ran
		if (i <= 99 && i >= 0) {     //Range is from 0-99 for In-Class #2. Done by Carson Sharpless
			Arg.array[i] = num;
		}
		else {						//Example of Verifiably in Range Operation for In-Class #2. Done By Carson Sharpless
			num = 99;				//If number falls outside of the pre-set range (0-99), num is set to the max value.
			Arg.array[i] = num;		//Then num is put into the array as the max value of the range.
		}
	}

}


// Prints array given
// Arg.array is array to be print


void print(Class& Arg)

{

	cout << "Printing...\n"; //Done by Paul Grubb.



	for (int i = 0; i < 20; i++) // loops though array and prints array. Done by Paul Grubb.
	{
		if (Arg.array[i] >= 0 && Arg.array[i] <= 99)	//Post condition testing, ensure all integers in array are withiin range for In-Class #2. Done by Carson Sharpless.
		{
			cout << Arg.array[i] << " "; // prints contents of array. Done by Paul Grubb.
		}
	}



	cout << "\nEnd Print Statement.\n";

}


// calls sort algorithm to sort array
// Arg.array is array to sort


void sort(Class& Arg) {									//Done by Paul Grubb for In-Class 2.

	for (int i = 0; i <= 19; i++) // loops though array of numbers checking for if smaller number is before a larger number. Done by Paul Grubb.

	{

		for (int j = i + 1; j <= 20; j++) //loops though array of numbers checking for if smaller number is before a larger number. Done by Paul Grubb.

		{

			int temp = 0; // temp value to hold number while being switched 

			if (Arg.array[i] < Arg.array[j]) // checks the value of the two number and if true sorts those numbers. Done by Paul Grubb.

			{

				temp = Arg.array[i];				//Temporary stores the smaller number. Done by Paul Grubb.

				Arg.array[i] = Arg.array[j];		//Puts the large number in place of the smaller. Done by Paul Grubb.

				Arg.array[j] = temp;				//Sets the small number back to where the large number was. Done by Paul Grubb.

			}

		}

	}

}
