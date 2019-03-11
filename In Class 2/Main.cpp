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

using namespace std;

void AskForData(CustomerRewards &accounts);
void ShowData(CustomerRewards &accounts);
void ModifyCustomer(CustomerRewards &accounts);
void FlushInputBuffer(CustomerRewards);

//precondition: Take in char from customerRewards
//postcondition: clear out char? ***
void FlushInputBuffer()			// function for cleaning out the buffer
{
	char character;
	cout << "Cleaning input buffer, please hit 'return' to continue.";
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
	accounts.printAll();
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
	
	for(int i = 0; i < 100; i++) //added 3/11 by David Bonney to keep tempPrice c-string secure and reset
	       tempPrice[i] = \0; //reset contents of tempPrice
	
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

	char input = '3'; //initialize with an innocent value
	int errorCount = 0; //set error count to zero 
	while (errorCount < 3) { //if wrong input is entered 3 times then the program closes.
		cout << "\nHello this app is our costumer database.\nPress 1 to enter a new customer.\nPress 2 to see a list of costumers.\nPress 3 to modify an existing customer.\nPress 0 to exit.\n";
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
