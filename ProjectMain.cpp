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
void FlushInputBuffer(CustomerRewards);

void FlushInputBuffer()
{
	char character;
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

int main() {
	CustomerRewards accounts;

	char input = '3'; //initialize with an innocent value
	int errorCount = 0;
	while (errorCount < 3) {
		cout << "\nHello this app is our costumer database, to enter a new customer press 1.\nTo see a list of costumers press 2\nPress 0 to exit.\n";
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