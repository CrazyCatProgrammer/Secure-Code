#include <iostream> //input + output stream
#include <string> //string class and string library file
#include <fstream> //ifstream and ofstream

#include "Person.h"
#include "Reservation.h"

using namespace std;

int priceCalc(Person p, Reservation r);

int main()
{
	//main program
	//tbd

	//end program
	if (cin.peek() == '\n')
		cin.ignore();
	cin.get();
	return 0;
}

int priceCalc(Person p, Reservation r)
{
	unsigned int finalPrice = 0;

	// setting prices
	unsigned int bagPrice = 30; //price per bag
	// prices for 3 different classes
	unsigned int economyClass = 20;
	unsigned int businessClass = 45;
	unsigned int firstClass = 80;
	// prices for flight type
	unsigned int roundTrip = 100;
	unsigned int oneWay = 80;
	unsigned int directFlight = 35;

	unsigned int destination = 0;
	//

	//switch statement for how many bags someone has. Max 6 bags total
	switch (r.getBags())
	{
	case 0:
		//no addition because no bags
	case 1:
		finalPrice += bagPrice;
	case 2:
		finalPrice = finalPrice + (bagPrice * 2);
	case 3:
		finalPrice = finalPrice + (bagPrice * 3);
	case 4:
		finalPrice = finalPrice + (bagPrice * 4);
	case 5:
		finalPrice = finalPrice + (bagPrice * 5);
	default: //limit of 6 bags 
		finalPrice = finalPrice + (bagPrice * 6);
	}

	// checking seat class
	if (r.getQuality() == "Economy")
		finalPrice += economyClass;
	if (r.getQuality() == "Business")
		finalPrice += businessClass;
	if (r.getQuality() == "First")
		finalPrice += firstClass;

	//check if round trip. If it isn't, is a one way flgiht
	if (r.getRoundTrip())
		finalPrice += roundTrip;
	else
		finalPrice += oneWay;

	//fee if flight is nonstop
	if (r.getNonStop())
		finalPrice += directFlight;
}
