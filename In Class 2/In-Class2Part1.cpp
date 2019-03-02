//============================================================================
//
// Name        : In-Class#2Part1.cpp
// Author      : Bonnie Rogers, Carson Sharpless
// Version     : 1.0.0
// Date        : February th, 2019
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
#include <string>
#include <algorithm>  	// for sort function
#include <stdlib.h>	// rand function
using namespace std;


/////////////////////////////////////////// Function Call ///////////////////////////////////////////

int generate(int s[20], const int l);
void print(int s[20], const int l);
int sort(int s[20], const int l);
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
    
    //creating array
    s[l] = generate(s, l);
    //print original array unsorted
    print(s, l);
    //sort array
    sort(s, l);
    //print array sorted
    print(s, l); 
    //set array to null
    destroyArray(s[l], l);
    
    //ending program
    cout << "End Program - Press any key to continue... ";
    cin.ignore();
    
    return 0;

}

/////////////////////////////////////////// Functions ///////////////////////////////////////////


// sets array to null
// in is array to set null

int destroyArray(int in, int l)
{
    cout << "Setting array to null...\n";
     in = NULL;
    return in;
}


// fills the array with numbers between 0 and 99
// s is the array to be filled, l is length of the array

int generate(int s[20], const int l)
{
    cout << "Generating numbers and putting into array...\n";
    int num = 0;
    for (int i = 0; i < l; i++)     //Range Checking for number of arrays for In-Class #2. Done by Carson Sharpless
    {
        num = rand() % 100;         //Serves as a Precondition test, before inserting the integers into the array for In-Class #2. Done by Carson Sharpless
        if( i <= 99 && i >= 0){     //Range is from 0-99 for In-Class #2. Done by Carson Sharpless
        s[i] = num;             
        }
        else {
            return 0;
        }
    }
    return s[l];
}


// Prints array given
// s is array to be print, l is length of array

void print(int s[20], const int l)      
{
    cout << "Printing...\n";
    
    for (int i = 0; i <= l; i++)
    {
        if( s[i] >= 0 && s[i] <= 99){   //Post condition testing, ensure all integers in array are withiin range for In-Class #2. Done by Carson Sharpless.
        cout << s[i] << " ";
        }
        else {
            cout << "\nArray is out of the range, please check code\n";
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