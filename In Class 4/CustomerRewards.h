/*
 * CustomerRewards.h
 *
 *  Last Edited: March 5, 2019
 *
 *      Author: David Bonney, Robyn Collins
 *		New: Pre and Post conditions added by Robyn
 */

#ifndef CUSTOMERREWARDS_H_
#define CUSTOMERREWARDS_H_

#include<string>
#include"Customer.h"

class CustomerRewards {
public:
    //Constructors & destructors
    CustomerRewards();
    CustomerRewards(Customer input);
    ~CustomerRewards();
    CustomerRewards(const CustomerRewards& source); //copy construcor
    CustomerRewards& operator =(const CustomerRewards& source); //assignemnt
    //Member functions
    //getters & setters
    int getUsed() { return used; }
    int getMax() { return max; }
    //other member functions
    //pre condition, get array of characters.
    //post condition, save array of characters.
    void add(Customer input);
    //precondition, index int
    //postcondition, null
    void removeOne(int index);
    void printOne(int index);
    void printBest(); //prints "best" customer, however it's defined within the function
    void printAll();
    Customer operator [] (int const &num);

private:
    int max; //max size of array
    int used; //number of items in array
    Customer* data; //made new class for data storage. Much easier
    void free(); //private function to clear all memory as part of destructor
    void addMemory(int slots); //private function to add memory to the array if full
    void cleanup(); //private function used when removing items to remove excess unused memory
};

#endif /* CUSTOMERREWARDS_H_ */
