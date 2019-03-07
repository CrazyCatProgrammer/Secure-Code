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

#include <iostream>

#include <stdio.h>

#include <cmath>

#include <math.h>

using namespace std;





/////////////////////////////////////////// Function Call ///////////////////////////////////////////







class Class					//Done by Paul Grubb for In-Class 2.

{

public:

	int array[20];

};



void generate(Class&);

void print(Class&);

void sort(Class&);

int destroyArray(Class&);



/////////////////////////////////////////// Main ///////////////////////////////////////////



int main()

{

	Class Agr;							//Call the class

	destroyArray(Agr);					//Ensure there is nothing within the class Array

	generate(Agr);						//Generate the array and list of random numbers from 0-99

	print(Agr);							//Prints out the array
	
	sort(Agr);							//Sorts the array from largest to smallest numbers

	print(Agr);							//Prints the sorted array

	destroyArray(Agr);					//Destroys array and its contents
	






	//ending program
	//character to end program

	cout << "End Program - Press any key to continue... ";



	return 0;



}



/////////////////////////////////////////// Functions ///////////////////////////////////////////

// Arg.array is the array to be destroyed

int destroyArray(Class& Arg) {							//Done by Paul Grubb for In-Class 2.

	for (int i = 0; i < 20; i++) { Arg.array[i] = 0; }

	return 0;

}


// fills the array with numbers between 0 and 99
// Arg.array is the array to be filled


void generate(Class& Arg)								//Done by Paul Grubb for In-Class 2.

{

	cout << "Generating numbers and putting into array...\n";

	int num = 1;

	for (int i = 0; i < 20; i++)

	{
	
		num = rand() % 100;
		if( i <= 99 && i >= 0){     //Range is from 0-99 for In-Class #2. Done by Carson Sharpless
		Arg.array[i] = num;
		}
	}

}


// Prints array given
// Arg.array is array to be print


void print(Class& Arg)

{

	cout << "Printing...\n";



	for (int i = 0; i < 20; i++)
	{
		if( Arg.array[i] >= 0 && Arg.array[i] <= 99)	//Post condition testing, ensure all integers in array are withiin range for In-Class #2. Done by Carson Sharpless.
		{   													
		cout << Arg.array[i] << " ";
		}
	}



	cout << "\nEnd Print Statement.\n";

}


// calls sort algorithm to sort array
// Arg.array is array to sort


void sort(Class& Arg){									//Done by Paul Grubb for In-Class 2.

		for (int i = 0; i <= 19; i++)

		{

			for (int j = i + 1; j <= 20; j++)

			{

				int temp = 0;

				if (Arg.array[i] < Arg.array[j])

				{

					temp = Arg.array[i];				//Temporary stores the smaller number

					Arg.array[i] = Arg.array[j];		//Puts the large number in place of the smaller
	
					Arg.array[j] = temp;				//Sets the small number back to where the large number was

				}

			}

		}

	}