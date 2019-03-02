#include "Customer.h"

Customer::Customer(std::string name, double price)
{
	setName(name);
	setPrice(price);
}

void Customer::convertPrice(int ChangedPrice) {  // this function takes in an int and changes it to a float.
	float tempFloat = static_cast<float>(ChangedPrice);

	setPrice(price + tempFloat);

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