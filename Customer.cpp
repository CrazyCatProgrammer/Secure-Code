#include "Customer.h"

Customer::Customer(std::string name, float price)
{
	setName(name);
	setPrice(price);
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
