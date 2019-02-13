#include "Customer.h"

Customer::Customer(std::string name, double price)
{
	setName(name);
	setPrice(price);
}

void Customer::setName(std::string input)
{
	name = input;
}

void Customer::setPrice(int input)
{
	price = input;
}

void Customer::printName()
{
	std::cout << "Name: " << name;
}

void Customer::printPrice()
{
	std::cout << "Price: " << price;
}

void Customer::printAll()
{
	printName();
	printPrice();
}
