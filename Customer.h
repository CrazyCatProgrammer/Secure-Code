/*
 * Customer.h
 *
 *  Created on: Feb 3, 2019
 *      Author: David Bonney
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>
#include<string>

class Customer {
public:
	//Constructors and Destructors
<<<<<<< HEAD
=======
	Customer();
>>>>>>> df4795d2ae798a3cc8367812b7db4f4b0021f89a
	Customer(std::string name = "", double price = 0); //make sure the 0 sentinel value is in constructor logic
	//No destructor needed as no heap memory used
  //Member Functions
		//getters & setters
<<<<<<< HEAD
	std::string getName() { return name; }
	double getPrice() { return price; }
=======
	std::string getName() {return name;}
	double getPrice() {return price;}
>>>>>>> df4795d2ae798a3cc8367812b7db4f4b0021f89a
	void setName(std::string input);
	void setPrice(int input);
	//prints
	void printName();
	void printPrice();
	void printAll();

private:
	double price;
	std::string name;
};

//Overload "<, >, <=, >=, ==" operators?

#endif /* CUSTOMER_H_ */