//============================================================================
//
// Name        : Pretest_Question1.cpp
// Author      : Bonnie Rogers, Carson Sharpless
// Version     : 1.0.0
// Date        : February 7th, 2019
// Description : generates a sequence of twenty random values between 0 and 99 in an array.
//				 Print the sequence, sort the array, and print the sorted sequence.
// Functions   : zzzz
//
//============================================================================


#define fstackprotectorall //stack canary 
#include <iostream>
#include <string>
#include <algorithm>  	// for sort function
#include <stdlib.h>	// rand function
using namespace std;


/////////////////////////////////////////// Function Call ///////////////////////////////////////////

int generate(int s[20], const int l);
void print(int s[20], const int l);
int sort(int s[20], const int l);
string intToStrong(int s[20], const int l);

//create and destroy

int createArray(const int l);
int destroyArray(int in, const int l);


/////////////////////////////////////////// Main ///////////////////////////////////////////

int main()
{
    //setting constant size for array
    const int l = 20;
    int s[l];
    //static function pointer for print
    static void(*funcPrint)(int s[20], const int l);
    funcPrint = &print;
    
    s[l] = createArray(l);
    print(s, l);
    sort(s, l);
    print(s, l); 
    destroyArray(s[l], l);
    
    //ending program
    char end = NULL;	//character to end program
    cout << "End Program. Press any key to continue... ";
    cin >> end;
    
    return 0;

}

/////////////////////////////////////////// Functions ///////////////////////////////////////////


// fills the array with numbers between 0 and 99
// s is the array to be filled, l is length of the array

int generate(int s[20], const int l)
{
    int num = 0;
    for (int i = 0; i < l; i++)
    {
        num = rand() % 100;
        s[i] = num;
        cout << num << " ";
    }
    return s[l];
}


// Prints array given
// s is array to be print, l is length of array

void print(char s[20], const int l)
{

    cout << "Printing...\n";
    
    for (int i = 0; i <= l; i++)
    {
        if (s[i] == NULL)

        {
            //skip nulls - end of the character
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

int sort(int s[20], const int l)
{
    cout << "Sorting array...\n";
    sort(s, s + l);
    return s[l];
}

//turns int array into string array
//is is int array, l is length
string intToStrong(int s[20], const int l)
{
    
}

//create and destroy arrays
// l is length of array to create

int createArray(const int l)
{
    cout << "Creating Array of " << l << " length...\n";
    int s[20];
    
    cout << "Generating numbers and putting into array...\n";
    generate(s, l);

    return s[l];
}


// sets array to null
// in is array to set null

int destroyArray(char in, int l)
{
    cout << "Setting array to null...\n";
    in = NULL;
    return in;
}
