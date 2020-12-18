#pragma once

#include <QWidget>
#include "ui_HomePage.h"

class OrarApp;

class HomePage : public QWidget
{
	Q_OBJECT

public:
	HomePage(OrarApp* parentView, QWidget *parent = Q_NULLPTR);
	~HomePage();
private slots:
	void on_okButton_clicked();

	void createNewTimeTable();

private:
	Ui::HomePage ui;
	OrarApp* parentview;

};
