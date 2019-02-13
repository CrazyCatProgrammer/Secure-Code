/*
 * ProjectMain.cpp
 *
 *  Created on:
 *      Author: 
 *		Edited by: Robyn Collins & David Bonney
 */
#define fstackprotectorall //stack canary turned on for all functions. A bit overkill, but works.
#pragma warning(disable : 4996)
#include "Customer.h"
#include "CustomerRewards.h"
#include <iostream>
#include <string>

using namespace std;

void AskForData(CustomerRewards accounts);
void ShowData(CustomerRewards accounts);
void FlushInputBuffer(CustomerRewards);

void FlushInputBuffer(CustomerRewards)
{
	// needs work
	//int character;
	char character;
	while ((character = getchar()) != '\n' && character != EOF);
}
void ShowData(CustomerRewards accounts) //reworked by David
{
	cout << "Showing Customer Data:\n";
	accounts.printAll();
	cout << "\nYour best Customer is:\n";
	accounts.printBest();
}
/*
void AskforData(CustomerRewards accounts)
{
	int stop;
	cout << "\nplease enter customer data\n"
	<< "please enter customer data below\n\n";
	cout << "enter amount\n";
	while (scanf("%f", &den) == 0 || den == 0)
	while (cin >> &accounts.CustomerAmountArray[accounts.NumberOfCustomers] == 0 || den == 0) {}
	cin >> accounts.CustomerAmountArray[accounts.NumberOfCustomers];
	cout << "enter name\n";
	cin >> accounts.CustomerNameArray[accounts.NumberOfCustomers];
	cout << accounts.CustomerNameArray[accounts.NumberOfCustomers] << " and " << accounts.CustomerAmountArray[accounts.NumberOfCustomers] << "\n";
	accounts.NumberOfCustomers++;
}*/

void AskForData(CustomerRewards accounts) {
	Customer tempCust;
	char holder [10];
	string price;
	string name;
	//while(validation = false)
	cout << "Please enter data for a customer:\nName:";
	cin.getline(holder, 10); //cuts off 10 characters for name. 10 should be plenty
	name = holder;
	tempCust.setName(name);
	cout << "\nPlease enter price:";
	cin.getline (holder, 6); //6 characters should be enough for a float
	price = holder; //test line
							 //validate inputs
	tempCust.setPrice(strtof(holder, NULL));
	accounts.add(tempCust);
	
}

int main() {
	CustomerRewards accounts;

	char input = '3'; //initialize with an innocent value
	int errorCount = 0;
	while (errorCount < 3) {
		cout << "Hello this app is our costumer database, to enter a new customer press 1.\nTo see a list of costumers press 2\nPress 0 to exit.\n";
		cin >> input;
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

//runtime protection strategies. https://stackoverflow.com/questions/8015355/are-c-strings-and-streams-buffer-overflow-safe
// http://www.informit.com/articles/article.aspx?p=2036582&seqNum=6
