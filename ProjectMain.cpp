/*
 * ProjectMain.cpp
 *
 *  Created on:
 *      Author: 
 *		Edited by: Robyn Collins & David Bonney
 */
#include <iostream>
#include <string>

using namespace std; //I know we imported this but for safeties sake I added std to cin and cout anyways - Robyn.

class NameAmount
{
public:
	std::string CustomerNameArray[10];
	int CustomerAmountArray[10];
	int NumberOfCustomers = 0;

};

void AskforData(NameAmount);
void ShowData(NameAmount);



void showData(NameAmount accounts)
{
	std::cout << "Showing Customer Data";
	for (int i = 0; i > accounts.NumberOfCustomers; i++)
	{
		std::cout << "Name:		Amount:\n\n";
		std::cout << accounts.CustomerNameArray[i].data() << "		";
		std::cout << accounts.CustomerAmountArray[i] << "\n";

	}
}

void AskforData(NameAmount accounts)
{
	int stop;
	std::cout << "\nplease enter customer data\n"
		<< "please enter customer data below\n\n";
	std::cout << "enter amount\n";
	std::cin >> accounts.CustomerAmountArray[accounts.NumberOfCustomers];
	std::cout << "enter name\n";
	std::cin >> accounts.CustomerNameArray[accounts.NumberOfCustomers];

	std::cout << accounts.CustomerNameArray[accounts.NumberOfCustomers] << " and " << accounts.CustomerAmountArray[accounts.NumberOfCustomers] << "\n";
	accounts.NumberOfCustomers++;

}

int main() {

	NameAmount accounts;

	int input = 10;
	std::cout << "hello this app is our costumer database, to enter a new customer press 1. to see a list of costumers press 2\n\n";
	std::cin >> input;
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

//runtime protection strategies. https://stackoverflow.com/questions/8015355/are-c-strings-and-streams-buffer-overflow-safe
// http://www.informit.com/articles/article.aspx?p=2036582&seqNum=6