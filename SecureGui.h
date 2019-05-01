/*
DISCLAIMER!!!
This program has created a GUI using the Qt software, liscened under open source.
In compliance with (L)GPL regulations, this banner is the acknowledgement of Qt usage. For more information, visit https://www.qt.io/
This software is, and will remain, free of DRM locks and patents in compliance with these regulations.
This software is developed for educationial purposes as part of a project at Red Rocks Community College class CSC 245 040 Spring 2019
The students involved are Robyn Collins, Carson Sharpless
*/

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

private slots:
	void on_pushButton_clicked(); //moved to slots for use with GUI
	void person_pushButton_clicked();
private: 
	Ui::SecureGuiClass ui;	
	Reservation reservation; //added by David Bonney to allow info to be stored and transfered to main
};
