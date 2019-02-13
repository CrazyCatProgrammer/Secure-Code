#include "Customer.h"

Customer::Customer(std::string name, double price)
{
}

void Customer::setName(std::string input)
{
	name = input;
}


void Customer::setPrice(int input) {
	price = input;
}


void Customer::printName() {
	std::cout << name;
}

void Customer::printPrice() {
	std::cout << price;
}

void Customer::printAll() {
	printName();
	printPrice();
}