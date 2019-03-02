/*
 * Customer.h
 *
 *  Created on: Feb 3, 2019
 *      Author: David Bonney
 *		Edited by: Robyn Collins
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>
#include<string>

class Customer {
public:
	//Constructors and Destructors


	Customer(std::string name = "", double price = 0); //make sure the 0 sentinel value is in constructor logic
	//No destructor needed as no heap memory used
  //Member Functions
		//getters & setters

	void convertPrice(int);//ROBYN DID A THING :D, this is to take in an int and convert to float.



	std::string getName() { return name; }
	float getPrice() { return price; }
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


#endif /* CUSTOMER_H_ */