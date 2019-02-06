
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class NameAmount
{
public:
	string CustomerNameArray[10];
	int CustomerAmountArray[10];
	int NumberOfCustomers = 0;

};

void AskforData(NameAmount);
void ShowData(NameAmount);



/*
class NameAmount 
{
	public:
		string CustomerNameArray[10];
		int CustomerAmountArray[10];
		int NumberOfCustomers = 10;

};
*/
void showData(NameAmount accounts) 
{
	cout << "Showing Customer Data";
	for (int i = 0; i > accounts.NumberOfCustomers; i++) 
	{
		cout << "Name:		Amount:\n\n";
		cout << accounts.CustomerNameArray[i].data() << "		";
		cout << accounts.CustomerAmountArray[i] << "\n";

	}
}

void AskforData(NameAmount accounts)
{
	int stop;
	cout << "\nplease enter customer data\n"
	<< "please enter customer data below\n\n";
	cout << "enter amount\n";
	cin >> accounts.CustomerAmountArray[accounts.NumberOfCustomers];
	cout << "enter name\n";
	cin >> accounts.CustomerNameArray[accounts.NumberOfCustomers];

	cout << accounts.CustomerNameArray[accounts.NumberOfCustomers] << " and " << accounts.CustomerAmountArray[accounts.NumberOfCustomers] << "\n";
	accounts.NumberOfCustomers++;

}

int main() {

	NameAmount accounts;
	
	int input = 10;
	cout << "hello this app is our costumer database, to enter a new customer press 1. to see a list of costumers press 2\n\n";
	cin >> input;
	if (input == 1)
	{
		AskforData(accounts);
	}
	else if (input == 2);
	{
		showData(accounts);
	}
	return 0;

}


