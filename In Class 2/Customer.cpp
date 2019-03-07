// Class by Robyn Collins
#include "Customer.h"

Customer::Customer(std::string name, double price)
{
	setName(name);
	setPrice(price);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Code by Bonnie Rogers - As If Logic
// this function takes in an int and changes it to a float. Makes sure price won't be set to less than 0.
void Customer::convertPrice(int ChangedPrice) 
{  
	float tempFloat = static_cast<float>(ChangedPrice);
	
	float addedPrice = price + tempFloat;  
	
	//checking overflow
	//checks to see if incoming number is positive and if addition is less than original incoming number or original price
	if(tempFloat > 0 && addedPrice < tempFloat || addedPrice < getPrice()) 
	{
		std::cout << "Overflow error: Not changing price.";
		return;
	}
	//check if incoming number is negative to check if addition is more than incoming number or original price
	if(tempFloat < 0 && addedPrice > tempFloat || addedPrice > getPrice())
	{
		std::cout << "Overflow error: Not changing price.";
		return;
	}
	
	//check to make sure price doesn't fall bellow 0 - NO REFUNDS >:(
	if(addedPrice < 0)
	{
		std::cout << "Error: Price input causes price to be less than 0.\n";
		return;
	}
	else
	{
		std::cout << "Setting customer price to " << tempPrice << "\n";
		setPrice(tempPrice);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Customer::setName(std::string input)
{
	name = input;
}

void Customer::setPrice(float input)
{
	price = input;
}

void Customer::printName()
{
	std::cout << "Name: " << name << '\n';
}

void Customer::printPrice()
{
	std::cout << "Price: " << price << '\n';
}

void Customer::printAll()
{
	printName();
	printPrice();
}
