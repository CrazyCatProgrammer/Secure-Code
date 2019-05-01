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
	//The following lines of code (32-90) Were coded by David Bonney

	if (ui.radioButton->isChecked()) //one way is checked
		reservation.setRoundTrip(false);
	else if (ui.radioButton_2->isChecked()) //round trip is checked
		reservation.setRoundTrip(true);
	if (ui.checkBox->isChecked())
		reservation.setQuality("First"); //name changed to comply with main.cpp price setter code
	else if (ui.checkBox_2->isChecked())
		reservation.setQuality("Economy");
	else if (ui.checkBox_3->isChecked())
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

	ui.ThankYouLabel->setText("Thank you for your reservation!"); //need to have some error messages if invalid inputs later.
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
