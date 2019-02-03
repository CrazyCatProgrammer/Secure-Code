/*
 * Customer.h
 *
 *  Created on: Feb 3, 2019
 *      Author: David Bonney
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include<string>

class Customer {
public:
	//Constructors and Destructors
	Customer();
	Customer(std::string name = "", int price = 0); //make sure the 0 sentinel value is in constructor logic
	//No destructor needed as no heap memory used
  //Member Functions
		//getters & setters
	std::string getName() {return name;}
	int getPrice() {return price;}
	void setName(std::string input);
	void setPrice(int input);
		//prints
	void printName();
	void printPrice();
	void printAll();

private:
	int price;
	std::string name;
};

//Overload "<, >, <=, >=, ==" operators?

#endif /* CUSTOMER_H_ */
