//============================================================================
// Name        : Pretest_Question1.cpp
// Author      : Bonnie Rogers, Carson Sharpless
// Version     : 1.0.0
// Date		   : February 7th, 2019
// Description : generates a sequence of twenty random values between 0 and 99 in an array.
//				 Print the sequence, sort the array, and print the sorted sequence.
// Functions   : zzzz
//============================================================================

#include <iostream>
#include <algorithm>  	// for sort function
#include <stdlib.h>		// rand function
using namespace std;

/////////////////////////////////////////// Function Call ///////////////////////////////////////////
wchar_t generate(wchar_t s, int l);
void print(wchar_t s, int l);
wchar_t sort(wchar_t s, int l);

//create and destroy
wchar_t createArray(int l);
wchar_t destroyArray(wchar_t in, int l);

/////////////////////////////////////////// Main ///////////////////////////////////////////
int main()
{


	//static function pointer for print
	static void (*funcPrint)(wchar_t s, int l);
	funcPrint = &print;

	//ending program
	char end = "";	//character to end program
	cout << "End Program. Press any key to continue... ";
	cin >> end;
	return 0;
}

/////////////////////////////////////////// Functions ///////////////////////////////////////////

// fills the array with numbers between 0 and 99
// s is the array to be filled, l is length of the array
wchar_t generate(wchar_t s, int l)
{

	for(int i = 0; i < l; i++)
	{
		int num = rand() % 100;
		itoa(num, s, i);
	}
	return s;
}

// Prints array given
// s is array to be print, l is length of array
void print(wchar_t s, int l)
{
	cout << "Printing...\n";
	for(int i = 0; i <= l; i++)
	{
		if(s[i] == nullptr)
		{
			//skip nulls
		}
		else
		{
			cout << s[i] << " ";
		}
	}
	cout << "\nEnd Print Statement.\n";
}

// calls sort algorithm to sort array
// s is array to sort, l is length of array
wchar_t sort(wchar_t s, int l)
{
	cout << "Sorting array...\n";
	sort(s, s+l);
	return s;
}

//create and destroy arrays
// l is length of array to create
wchar_t createArray(int l)
{
	cout << "Creating Array of " << l << " length...\n";
	wchar_t array[l];

	cout << "Generating numbers and putting into array...\n";
	generate(array, l);

	return array;
}

// sets array to null
// in is array to set null
wchar_t destroyArray(wchar_t in, int l)
{
	cout << "Setting array to null...\n";
	in = nullptr;
	return in;
}
