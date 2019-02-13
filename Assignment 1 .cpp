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
*\

#define fstack-protector-all //stack canary turned on for all functions. A bit overkill, but works.
#include "Customer.h"
#include "CustomerRewards.h"
#include <iostream>
#include <string>

using namespace std;

void AskforData(CustomerRewards);
void ShowData(CustomerRewards);
void FlushInputBuffer(CustomerRewards);

void FlushInputBuffer(CustomerRewards)
{
	// needs work
	int character;
	char character;
	while ((character = getchar()) != '\n' && character != EOF);
}
void showData(CustomerRewards accounts) //reworked by David
{
	cout << "Showing Customer Data";
	accounts.printAll();
	cout << "Your best Customer is:\n";
	accounts.printBest();
}
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
}
int main() {
	CustomerRewards accounts;

	int input = 10;
	int errorCount = 0;
	while (errorCount < 3) {
		cout << "hello this app is our costumer database, to enter a new customer press 1. to see a list of costumers press 2\n\nPress 0 to exit.";
		cin >> input;
		if (input == 1)
		{
			AskforData(accounts);
		}
		else if (input == 2)
		{
			showData(accounts);
		}
		else if (input == 0)
		{
			return 0; //0 is a proper exit
		}
		else //if anything unexpected, post error thing
		{
			errorCount++;
			cout << "There was an error with that input, please try again.";
		}
	}
	return -1; //-1 indicated bad exit
}



