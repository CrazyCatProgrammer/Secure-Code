#include "Customer.h"


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