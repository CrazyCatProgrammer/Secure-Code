#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_SecureGui.h"
#include "ui_Info.h"
#include "Reservation.h"

class SecureGui : public QMainWindow
{
	Q_OBJECT

public:
	SecureGui(QWidget *parent = Q_NULLPTR);
	Reservation getReservation() { return reservation; } //added by David Bonney to allow info to be stored and transfered to main

private:
	Ui::SecureGuiClass *ui;
	void on_pushButton_clicked();
	Reservation reservation; //added by David Bonney to allow info to be stored and transfered to main
};
