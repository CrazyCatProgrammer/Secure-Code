/*
* Modify each of the programs to include an example  the following :
*Mitigation strategies for strings and string handling
*   String handling functions
*   Dynamic Allocation functions
*   Runtime Protection Strategies
*   Stack Canaries
*   Null Pointers
*   Allocation Functions
*
* Version number 1.00
*
* Program 1: Carson, Bonnie
* Program 2 : Robyn, David, Paul
* New: Pre/post conditions added -by Robyn Collins
*	   As if - by David Bonney
*/

/*
 * Project.cpp
 *  Created on:
 *      Author: Paul Grubb
 *		Edited by: Robyn Collins & David Bonney
 * New: In range function
 */

#define fstackprotectorall //stack canary turned on for all functions. A bit overkill, but works.
#include "Customer.h"
#include "CustomerRewards.h"
#include <iostream>
#include <string>
#include <stdint.h>
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable : 4996)
using namespace std;


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Part 1 consolidated into 1 document for ease of  viewing
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





//#include "stdafx.h"    //
#include <stdio.h>

#include <cmath>    // for the Random Number Gen. Done by Paul Grubb.

#include <math.h>


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



int part1main()

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

    cout << "End Program 1 - Press any key to continue... ";

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



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Part 2 Starts Here

void AskForData(CustomerRewards &accounts);
void ShowData(CustomerRewards &accounts);
void ModifyCustomer(CustomerRewards &accounts);
void FlushInputBuffer(CustomerRewards);


int sprintf(char *string);

//precondition: Take in char from customerRewards
//postcondition: clear out char? ***
void FlushInputBuffer()			// function for cleaning out the buffer
{
    char character;
    cout << "Cleaning input buffer, please hit 'return' to continue.\n";
    while ((character = getchar()) != '\n' && character != EOF);
}

//in Range Function
//precondition: price should be within the high and low numbers
//postcondition: price should be between the low and high digits or it gets ignored.
bool inRange(int low, int high, int price)	//should unsigned be int?
{
    return  ((price - low) <= (high - low) && price >= low);
}
//inRange(0, 99999, tempPrice); //if price is too big or too small than price is set 0? where do put this?***


//precondition: Pass in a Customer Reward reference to print data
//postcondition: Will print all Data as well as the Best customer. Returns Nothing.
void ShowData(CustomerRewards &accounts) //reworked by David
{
    cout << "Showing Customer Data:\n";
    //loop added 3/27 by David as example of dynamic stack usage with strings
    for (int i = 0; i < accounts.getUsed(); i++) { //loop to show all customers
	char *custName;
	custName = (char*)malloc(accounts[i].getName().size()); //allocate memory for string
	strcpy(custName, accounts[i].getName().c_str());
	char *custPrice;
	custPrice = (char*)malloc(to_string(accounts[i].getPrice()).size()); //allocate memory for string
	strcpy(custPrice, to_string(accounts[i].getPrice()).c_str());
	int len = printf("%d) %s: %s%c", (i+1), custName, custPrice, '\n'); //display name
	
	free(custName); //free to de-allocate memory used
	free(custPrice); //free to de-allocate memory used 
	}
	//accounts.printAll();
	cout << "\nYour best Customer is:\n\n";
    accounts.printBest();
}

//precondition: input char for customer and price
//postcondition: if input is valid set to customer and price
void AskForData(CustomerRewards &accounts) {
    Customer tempCust;
    char tempName[20]; // for name
    char tempPrice[6]; //for price
    float price = 0.0;
    string name = "";
    cout << "Please enter data for a customer:\n";
    cout << "Name:\n";
    fgets(tempName, 20, stdin); //Tip from paul, fgets is WAY easier than .get
    name = tempName;
    tempCust.setName(name);
    FlushInputBuffer(); //Thanks paul for the code!
    while (price <= 0.0) //uses 0.0 sentinel value, as well as default of strtof to prevent non-inputs
    {
        cout << "Please enter price:\n";
        cin.clear();
        fgets(tempPrice, 6, stdin);
        price = strtof(tempPrice, NULL); //will store 0.0 if invalid conversion
    }
    tempCust.setPrice(price);
    accounts.add(tempCust);
    FlushInputBuffer();
}


//precondition: Enter a char customer to modify
//postcondition: IF customer exsists in the list then modify the price
void ModifyCustomer(CustomerRewards &accounts) { //Added 2/22 by David
    //code to access modify from class goes here
    char tempPrice[100]; //100 characters
    char input = 48; //initialize to ASCII '0'
    int custNum = 0; //initialize to 0 to keep inRange working
    unsigned int priceToModify = 0;
    int negPrice = 0;
    Customer tempCust;

    while (!(inRange(1, accounts.getUsed(), custNum))) { //check if selected customer to modify is within the list (Thank you Robyn for range checker!)
        cout << "Which customer do you want to modify?"; //loop modified 3/11 by David Bonney to include range checking and allow multi-digit customer number
        fgets(tempPrice, 100, stdin);
        try {
            custNum = stoul(tempPrice, nullptr, 0); // will throw exceptions based on bad values, transforming tempPrice into an int
            //stoul = string to unsigned long
        }
        catch (invalid_argument) {
            cout << "\nInvalid Input, please try again.\n";
        }
        catch (out_of_range) {
            cout << "\nNumber too big! Please try a smaller number.\n";
        }
    }
    custNum--; //reduce by 1 to prevent an off-by-one error later

    for (int i = 0; i < 100; i++) //added 3/11 by David Bonney to keep tempPrice c-string secure and reset
        tempPrice[i] = '\0'; //reset contents of tempPrice

    while (input < 49 || input > 50) { //check if inputted value is 1 or 2 in ASCII codes
        cout << "Do you want to add (Input 1) or subtract (Input 2) a number from the customer?\n";
        cin.get(input); //will only get 1 character
        cin.ignore(1000, '\n');
    }

    while (priceToModify == 0) {
        cout << "Please enter a price to add or subtract. Enter price as a negative value to subtract.\n";
        fgets(tempPrice, 100, stdin);
        try {
            priceToModify = stoul(tempPrice, nullptr, 0); // will throw exceptions based on bad values, transforming tempPrice into an int
            //stoul = string to unsigned long
        }
        catch (invalid_argument) {
            cout << "\nInvalid Input, please try again.\n";
        }
        catch (out_of_range) {
            cout << "\nNumber too big! Please try a smaller number.\n";
        }
    }

    tempCust = accounts[custNum]; //grabs customer at the array location and stores in variable tempCust
    if (input == '1')
        tempCust.convertPrice(priceToModify); //call customer method to alter price from unsigned to signed.
    else if (input == '2') {
        if (priceToModify <= 2147483647) { //check to ensure price is in range
            negPrice = priceToModify; //implicit conversion from unsigned to signed
            negPrice = -1 * negPrice; //make price negative to pass in
            tempCust.convertPrice(negPrice); //call customer method to alter price
        }
    }
    accounts.removeOne(custNum); //Removes old instance of the customer, because the class uses objects, rather than references, to modify
    accounts.add(tempCust);	     //re-add the customer to ensure it remains in the lsit.
}

int main() {
	CustomerRewards accounts;
	char input = '5'; //initialize with an innocent value
	char buffer[200]; // set buffer size for output stream  - Robyn 3/24/19
	const char* s = "Hello and Welcome to the program!"; //output for output stream, is const because there will be an error otherwise. - Robyn 3/24/19
	int j = snprintf(buffer, 200, "%.184s\n", s); //formatting output of output stream example - Robyn 3/24/19
												  //"%.184s" added by David Bonney 3/24 to prevent buffer overflow on 200 size buffer (184 = 200-16)
	int errorCount = 0; //set error count to zero
	while (errorCount < 3) { //if wrong input is entered 3 times then the program closes.
		
		printf(buffer, "string:\n%s\ncharacter count = %d\n", j); // Output Stream Example Added by Robyn 3/24/19
		
		for(int x = 0; x < 200; x++)
		{
			buffer[x] = '/0';
		}
		j = '/0'; 
		// clearing buffer and j variable to prevent incrimenting for overwrite - Bonnie Rogers 3/24/19
		
		cout << "\nHello this app is our costumer database.\nPress 1 to enter a new customer.\nPress 2 to see a list of costumers.\nPress 3 to modify an existing customer.\nPress 4 to run the function from Part 1 of Assignment.\nPress 0 to exit.\n";
		cin.get(input); //grab only one character
		FlushInputBuffer(); //clean out the buffer
		if (input == '1')
		{
			AskForData(accounts); //call to AskForData function
		}
		else if (input == '2')
		{
			ShowData(accounts); //call to ShowData function
		}
		else if (input == '3') //option added 2/22 by David
		{
			ModifyCustomer(accounts); // call to ModifyCustomer function
		}
		else if (input == '4') //option added 3/11 by David to consolidate both parts
		{
			part1main(); // call to part 1 of assignmnet
		}
		else if (input == '0')
		{
			return 0; //0 is a proper exit
		}
		else //if anything unexpected, post error thing
		{
			errorCount++;
			cout << "There was an error with that input, please try again.\n";
		}

	}
	return -1; //-1 indicated bad exit
}


