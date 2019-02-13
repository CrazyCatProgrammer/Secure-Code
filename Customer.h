/*
 * Customer.h
 *
 *  Created on: Feb 3, 2019
 *      Author: David Bonney
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include<string>
#include<iostream>

class Customer {
public:
	//Constructors and Destructors
	Customer(std::string name = "", float price = 0); //make sure the 0 sentinel value is in constructor logic
	//No destructor needed as no heap memory used
  //Member Functions
		//getters & setters
	std::string getName() { return name; }
	double getPrice() { return price; }
	void setName(std::string input);
	void setPrice(float input);
	//prints
	void printName();
	void printPrice();
	void printAll();

private:
	float price;
	std::string name;
};

//Overload "<, >, <=, >=, ==" operators?

#endif /* CUSTOMER_H_ */
