/* Assignment #1 (pre-test) code
* Started 1/31/2019
*
* Team members: David Bonney,
*
* Directions:
*
* Develop the design and code for each of the following programs
*
*   Program #1
*     Write a program that generates a sequence of twenty random values between 0 and 99 in an array. Print the sequence, sort the array, and print the sorted sequence.
*
*   Program #2
*     A supermarket wants to reward its best customer of each day, showing the customer’s name on a screen in the supermarket.
*     For that purpose, the customers’ purchase amount is stored in an array and the customer’s name is stored
*     in a corresponding array.
*     Write a program that prompts the cashier to enter all prices and names, then adds them to two arrays,
*     calls the function that you implemented, and displays the result. Use a price of 0 as a sentinel.
*
* Each program should include COMMENTS (internal), and a structured (functions).
* Each function should indicate who completed the design and code, or sections of the code.
*
* Modify each of the programs to include an example  the following:
*   Mitigation strategies for strings and string handling
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
* Program 2: Robyn, David, Paul
*/

/*
 * Project.cpp
 *  Created on:
 *      Author: Paul Grubb
 *		Edited by: Robyn Collins & David Bonney
 */

#define fstackprotectorall //stack canary turned on for all functions. A bit overkill, but works.
#include "Customer.h"
#include "CustomerRewards.h"
#include <iostream>
#include <string>

using namespace std;

void AskForData(CustomerRewards &accounts);
void ShowData(CustomerRewards &accounts);
void ModifyCustomer(CustomerRewards &accounts);
void FlushInputBuffer(CustomerRewards);

void FlushInputBuffer()
{
	char character;
	cout << "Cleaning input buffer, please hit 'return' to continue.";
	while ((character = getchar()) != '\n' && character != EOF);
}

void ShowData(CustomerRewards &accounts) //reworked by David
{
	cout << "Showing Customer Data:\n";
	accounts.printAll();
	cout << "\nYour best Customer is:\n\n";
	accounts.printBest();
}


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

void ModifyCustomer(CustomerRewards &accounts) { //Added 2/22 by David
	//code to access modify from class goes here
	char tempPrice[100]; //6 characters 
	char input = 48;
	int custNum = 0;
	unsigned int priceToModify = 0;
	int negPrice = 0;
	Customer tempCust;
	while (custNum <= 0 || custNum > accounts.getUsed()) { //check if selected customer to modify is within the list
		while (input < 49 || input > 57) { //check if inputted value falls between 1 and 9 in ASCII codes
			cout << "Which customer do you want to modify?";
			cin.get(input); //will only get 1 character
			cin.ignore(1000, '\n');
		}
		custNum = (input - '0'); //subtract char value of 0 to make the cust num into an integer
	}
	custNum--; //reduce by 1 to prevent an off-by-one error later
	input = 48;
	while (input < 49 || input > 50) { //check if inputted value is 1 or 2 in ASCII codes
		cout << "Do you want to add (Input 1) or subtract (Input 2) a number from the customer?\n";
		cin.get(input); //will only get 1 character
		cin.ignore(1000, '\n');
	}
	while (priceToModify == 0) {
		cout << "Please enter a price to add or subtract. Enter price as a negative value to subtract.\n";
		fgets(tempPrice, 100, stdin);
		try {
			priceToModify = stoul(tempPrice, nullptr, 0); //will throw exceptions based on bad values
		}
		catch (invalid_argument) {
			cout << "\nInvalid Input, please try again.\n";
		}
		catch (out_of_range) {
			cout << "\nNumber too big! Please try a smaller number.\n";
		}
	}
	tempCust = accounts[custNum];
	if (input == '1')
		tempCust.convertPrice(priceToModify);
	else if (input == '2') {
		if (priceToModify <= 2147483647) { //check to ensure price is in range
			negPrice = priceToModify; //implicit conversion from unsigned to signed
			negPrice = -1 * negPrice; //make price negative to pass in
			tempCust.convertPrice(negPrice);
		}
	}
	accounts.removeOne(custNum);
	accounts.add(tempCust);
}

int main() {
	CustomerRewards accounts;

	char input = '3'; //initialize with an innocent value
	int errorCount = 0;
	while (errorCount < 3) {
		cout << "\nHello this app is our costumer database.\nPress 1 to enter a new customer.\nPress 2 to see a list of costumers.\nPress 3 to modify an existing customer.\nPress 0 to exit.\n";
		cin.get(input);
		cin.ignore(1000, '\n');
		cin.clear();
		if (input == '1')
		{
			AskForData(accounts);
		}
		else if (input == '2')
		{
			ShowData(accounts);
		}
		else if (input == '3') //option added 2/22 by David
		{
			ModifyCustomer(accounts);
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

