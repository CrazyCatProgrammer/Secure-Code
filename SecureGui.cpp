#include "SecureGui.h"
#include "ui_SecureGui.h"
#include "ui_Info.h"

SecureGui::SecureGui(QWidget *parent) //constructor
	: QMainWindow(parent)
{
	ui->setupUi(this);
}

void SecureGui::on_pushButton_clicked()
{
	//connect pushButton to the next widget
	//https://www.youtube.com/watch?v=tP70B-pdTH0

	//TODO also code buttons doing things here
	//The following lines of code (18-) Were coded by David Bonney
	if (ui->radioButton->isChecked()) //one way is checked
		reservation.setRoundTrip(false);
	else if (ui->radioButton_2->isChecked()) //round trip is checked
		reservation.setRoundTrip(true);
	if (ui->checkBox->isChecked())
		reservation.setQuality("First"); //name changed to comply with main.cpp price setter code
	else if (ui->checkBox_2->isChecked())
		reservation.setQuality("Economy");
	else if (ui->checkBox_3->isChecked())
		reservation.setQuality("Business"); //name changed to comply with main.cpp price setter code
	int bags = ui->spinBox_2->value();
	reservation.setBags(bags);

	//TODO: need destination, nonstop, people thing (might add a counter for use in transfering info)

}
