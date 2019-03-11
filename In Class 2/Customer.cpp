/*
 * Customer.cpp
 *
 *  Last Edited: March 5, 2019
 *
 *      Author: David Bonney, Robyn Collins, Bonnie Rogers
 */

#include "Customer.h"

Customer::Customer(std::string name, double price)
{
	setName(name);
	setPrice(price);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Code by Bonnie Rogers - As If Logic
// this function takes in an int and changes it to a float. Makes sure price won't be set to less than 0.
void Customer::convertPrice(int ChangedPrice) // convert price added by Robyn
{  
	float tempFloat = static_cast<float>(ChangedPrice); // Conversion Rank
	
	float addedPrice = price + tempFloat;  
	
	//checking overflow
	//checks to see if incoming number is positive and if addition is less than original incoming number or original price
	//as-if overflow check. Code by Bonnie, assisted by David
	if(tempFloat > 0 && addedPrice < tempFloat || addedPrice < getPrice()) 
	{
		std::cout << "Overflow error: Not changing price.";
		return;
	}
	//check if incoming number is negative to check if addition is more than incoming number or original price
	//as-if overflow check. Code by Bonnie, assisted by David
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

//takes input variable "name"
void Customer::setName(std::string input) // added by Robyn 3/5
{
	name = input;
}

//takes input variable "input"
void Customer::setPrice(float input)// added by Robyn 3/5
{
	price = input;
}

//prints out name
void Customer::printName()// added by Robyn 3/5
{
	std::cout << "Name: " << name << '\n';
}

//prints out price
void Customer::printPrice()// added by Robyn 3/5
{
	std::cout << "Price: " << price << '\n';
}

//prints all prices and customers
void Customer::printAll()// added by Robyn 3/5
{
	printName();
	printPrice();
}
