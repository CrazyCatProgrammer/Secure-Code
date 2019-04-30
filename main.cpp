/*
DISCLAIMER!!!
This program has created a GUI using the Qt software, liscened under open source.
In compliance with (L)GPL regulations, this banner is the acknowledgement of Qt usage. For more information, visit https://www.qt.io/
This software is, and will remain, free of DRM locks and patents in compliance with these regulations.

This software is developed for educationial purposes as part of a project at Red Rocks Community College class CSC 245 040 Spring 2019
The students involved are [Please add your names here]
*/

#include "SecureGui.h"
#include <QtWidgets/QApplication> //brings in widgets for the application
#include <qlabel.h> //for labels in the application - HAHA JK
#include "Person.h" //Add class
#include "Reservation.h" //Add class

int priceCalc(Person p, Reservation r); //Price calculator function written by Bonnie Rogers

int main(int argc, char *argv[])
{
	QApplication a(argc, argv); //opens up the application
	SecureGui w; //just an empty window
	Reservation reservation;
	w.show();
	reservation = w.getReservation;
	std::cout << reservation.getQuality(); //Test line to see if any of this worked...
	//likely transfer window control here


	return a.exec();
}

int priceCalc(Person p, Reservation r)
/*
Function to calculate price of trip, based on bag count, type of flight, quality of seat, and destination
Precondition: Takes in information within the Person and Reservation classes
Postcondition: Outputs price as an integer.

Function written by Bonnie Rogers
*/
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