#ifndef RESERVATION_H
#define RESERVATION_H

#include "Person.h"
#include <string>
#include <iostream>

/*
Class to hold info for a reservation, including array of Person objects
Written by David Bonney
*/

class Reservation
{
public:
	Reservation();
	~Reservation();

	//getters
	std::string getDestination() { return destination; }
	bool getRoundTrip() { return roundTrip; }
	bool getNonStop() { return nonStop; }
	int getBags() { return bags; }
	int getMax() { return max; }
	int getUsed() { return used; }
	//setters
	void setDestination(std::string destIn) { destination = destIn; }
	void setRoundTrip(bool roundTripIn) { roundTrip = roundTripIn; }
	void setNonStop(bool nonStopIn) { nonStop = nonStopIn; }
	void setBags(int bagsIn) { bags = bagsIn; }

	//other member functions
	void add(Person personIn);
	Person operator [] (int const &num);

private:
	std::string destination; //to-from
	bool roundTrip; //bool because is either one-way or round trip. True indicates round trip, while false is one way
	bool nonStop; //bool for nonstop or has layovers
	int bags; //number of checked bags
	Person* people; //list of people, dynamic array
	int max; //max size of people list
	int used; // number of people in list
	void free(); //free memory
	void addMemory(int slots); // add memory to the array
	


};

#endif