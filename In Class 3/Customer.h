/*
 * Customer.h
 *
 *  Last Edited: March 5, 2019
 *
 *      Author: David Bonney, Robyn Collins
 *		New: Pre and Post conditions added by Robyn
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <iostream>
#include<string>

class Customer {
public:
    //Constructors and Destructors

    //precondition: String and double
    //postcondition: Char and Int, transformed in main.cpp
    Customer(std::string name = "", double price = 0); //make sure the 0 sentinel value is in constructor logic
//No destructor needed as no heap memory used
//Member Functions
//getters & setters

    //precondition variable convertPrice should be an int
    //postcondition convertPrice should end as a float
    void convertPrice(int);// this is to take in an int and convert to float - added by Robyn



    std::string getName() { return name; }
    float getPrice() { return price; }

    //precondition take in a string
    //postcondition set string to char
    void setName(std::string input);

    //precondition take in a float
    //postcondition set a float
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

