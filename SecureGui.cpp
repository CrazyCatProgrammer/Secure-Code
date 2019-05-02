/*

DISCLAIMER!!!

This program has created a GUI using the Qt software, liscened under open source.

In compliance with (L)GPL regulations, this banner is the acknowledgement of Qt usage. For more information, visit https://www.qt.io/

This software is, and will remain, free of DRM locks and patents in compliance with these regulations.

This software is developed for educationial purposes as part of a project at Red Rocks Community College class CSC 245 040 Spring 2019

The students involved are Robyn Collins, Carson Sharpless

*/



#include "SecureGui.h"

#include "ui_SecureGui.h"

#include "ui_Info.h"

#include "Reservation.h"

#include "Person.h"





SecureGui::SecureGui(QWidget *parent) //constructor

	: QMainWindow(parent)

{

	ui.setupUi(this);

	connect(ui.pushButton_2, SIGNAL(pressed()), this, SLOT(on_pushButton_clicked())); //connect button to function in code

	connect(ui.pushButton, SIGNAL(pressed()), this, SLOT(person_pushButton_clicked())); //connect button to function in code

}





void SecureGui::on_pushButton_clicked()

{

	//connect pushButton to the next widget

	//https://www.youtube.com/watch?v=tP70B-pdTH0



	//TODO add error conditions to be displayed in THANKYOULABEL

	//The following lines of code were coded by David Bonney



	if (ui.radioButton->isChecked()) //one way is checked

		reservation.setRoundTrip(false);

	else if (ui.radioButton_2->isChecked()) //round trip is checked

		reservation.setRoundTrip(true);

	if (ui.radioButton_6->isChecked()) //direct is checked

		reservation.setNonStop(true);

	else if (ui.radioButton_7->isChecked()) //layover trip is checked

		reservation.setNonStop(false);

	if (ui.firstRadioButton->isChecked())

		reservation.setQuality("First"); //name changed to comply with main.cpp price setter code

	else if (ui.economyRadioButton->isChecked())

		reservation.setQuality("Economy");

	else if (ui.coachRadioButton->isChecked())

		reservation.setQuality("Business"); //name changed to comply with main.cpp price setter code

	int bags = ui.spinBox_2->value();



	reservation.setBags(bags);



	QString tempQString; //temp Qstring for holding values

	std::string tempString; //string placeholder to build and store destination

	tempQString = (ui.comboBox->currentData()).toString();

	tempString += tempQString.toUtf8().constData(); //convert to utf8 encoding to store in std::string

	tempString += " to ";

	tempQString = (ui.comboBox_2->currentData()).toString();

	tempString += tempQString.toUtf8().constData(); //convert to utf8 encoding to store in std::string



	reservation.setDestination(tempString); //set destination string in reservation

	std::string creditCardString;

	tempQString = (ui.lineEdit_4->text());

	creditCardString = tempQString.toUtf8().constData(); //convert to utf8 encoding to store in std::string

	std::string CIDString;

	tempQString = (ui.lineEdit_5->text());

	CIDString = tempQString.toUtf8().constData(); //convert to utf8 encoding to store in std::string

	std::string cardType;

	tempQString = (ui.comboBox_2->currentData()).toString();

	cardType = tempQString.toUtf8().constData();

	std::string expDate;

	tempQString = ui.dateEdit->date().toString("dd/MM/yyyy");

	expDate = tempQString.toUtf8().constData();

	//ui.ThankYouLabel->setText("Thank you for your reservation!"); //need to have some error messages if invalid inputs later.
	ui.label_13->setText(QString::number(priceCalc())); //display price
}



void SecureGui::person_pushButton_clicked()

{

	Person tempP; //temporary person to add to reservation

	QString tempQString; //temp Qstring for holding values

	std::string tempString; //temp string for holding values

	tempQString = ui.lineEdit->text(); //get text from first name box

	tempString = tempQString.toUtf8().constData(); //convert to utf8 encoding to store in std::string

	tempP.setFirstName(tempString); //set data in our person

	tempQString = ui.lineEdit_2->text(); //get text from last name box

	tempString = tempQString.toUtf8().constData(); //convert to utf8 encoding to store in std::string

	tempP.setLastName(tempString); //set data in our person

	tempQString = ui.lineEdit_3->text(); //get text from middle initial box

	tempString = tempQString.toUtf8().constData(); //convert to utf8 encoding to store in std::string

	tempP.setMiddleInitial(tempString.at(0)); //set data in our person. Uses the at(0) to only get the one char



	tempQString = ui.plainTextEdit->toPlainText(); //get text from diet restrictions box

	tempString = tempQString.toUtf8().constData(); //convert to utf8 encoding to store in std::string

	tempP.setMeal(tempString); //set data in our person



	if (ui.radioButton_3->isChecked()) //MR is checked

		tempP.setPrefix("MR");

	else if (ui.radioButton_4->isChecked()) //MRS is checked

		tempP.setPrefix("MRS");

	else if (ui.radioButton_5->isChecked()) //MS is checked

		tempP.setPrefix("MS");

	//if none checked, prefix string will remain an empty string



	reservation.add(tempP); //Add our person into our reservation list.



}

int SecureGui::priceCalc()

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

	switch (reservation.getBags())

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

	if (reservation.getQuality() == "Economy")
		finalPrice += economyClass;
	if (reservation.getQuality() == "Business")
		finalPrice += businessClass;
	if (reservation.getQuality() == "First")
		finalPrice += firstClass;



	//check if round trip. If it isn't, is a one way flgiht

	if (reservation.getRoundTrip())
		finalPrice += roundTrip;
	else
		finalPrice += oneWay;

	//fee if flight is nonstop

	if (reservation.getNonStop())
		finalPrice += directFlight;

	return finalPrice;
}
