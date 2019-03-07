#include "Customer.h"

Customer::Customer(std::string name, double price)
{
	setName(name);
	setPrice(price);
}

// this function takes in an int and changes it to a float. Makes sure price won't be set to less than 0.
void Customer::convertPrice(int ChangedPrice) {  
	float tempFloat = static_cast<float>(ChangedPrice);
	
	float tempPrice = price + tempFloat;  //logic checking by Bonnie Rogers
	if(tempPrice < 0)
	{
		cout << "Error: Price input causes price to be less than 0.\n";
	}
	else
	{
		cout << "Setting customer price to " << tempPrice << "\n";
		setPrice(tempPrice);
	}
}


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
