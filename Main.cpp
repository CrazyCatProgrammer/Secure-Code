
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
void showData(NameAmount);
void FlushInputBuffer(NameAmount);
void OverWriteData(NameAmount);

void OverWriteData(NameAmount accounts)
{
	for (int i = 0; i < 10; i++)
	{
		accounts.CustomerAmountArray[i] = 0;
		//cout << "\noverright number " << i;
	}
}

void FlushInputBuffer(NameAmount)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);  // remove bad characters from the input buffer
}
void showData(NameAmount accounts)
{
	cout << "\n\n showing Custumer Data\n\n";
	for (int i = 0; i < accounts.NumberOfCustomers; i++)
	{
		cout << "Name:			Amount:\n\n";
		cout << accounts.CustomerNameArray[i].data() << "			";
		cout << accounts.CustomerAmountArray[i] << "\n";
		//cout << "\n\n" << accounts.NumberOfCustomers << "\n\n";

	}
}

void AskforData(NameAmount accounts)
{
	cout << "\nplease enter customer data\n"
		<< "please enter customer data below\n\n";
	cout << "enter amount\n";
	cin >> accounts.CustomerAmountArray[accounts.NumberOfCustomers];
	cout << "enter name\n";
	cin >> accounts.CustomerNameArray[accounts.NumberOfCustomers];

	cout << accounts.CustomerNameArray[accounts.NumberOfCustomers] << " and " << accounts.CustomerAmountArray[accounts.NumberOfCustomers] << "\n";
	accounts.NumberOfCustomers++;
	showData(accounts);

}

int main() {

	NameAmount accounts;
	OverWriteData(accounts);
	int input = 10;
	cout << "hello this app is our costumer database,\n to enter a new customer press 1.\n to see a list of costumers press 2\n\n to quit select 0\n\n";
	cin >> input;
	while (input != 0)	
		if (input == 1)
		{
			AskforData(accounts);
		}
		else if (input == 2)
		{
			showData(accounts);
		}
		else
		{
			input = 0;
			OverWriteData(accounts);
		}
			return 0;

}


