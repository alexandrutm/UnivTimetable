#pragma once

#include <QWidget>
#include "ui_HomePage.h"

class INavigator;

class HomePage : public QWidget
{
	Q_OBJECT

public:
	HomePage(INavigator* navigator, QWidget *parent = Q_NULLPTR);
	~HomePage();

private slots:
	void on_pushButtonSecondView_clicked();

private:
	Ui::HomePage ui;
	INavigator *mNavigator;
};
