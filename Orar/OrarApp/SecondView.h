#pragma once

#include <QWidget>
#include "ui_SecondView.h"

class INavigator;

class SecondView : public QWidget
{
	Q_OBJECT

public:
	SecondView(INavigator * navigator,QWidget *parent = Q_NULLPTR);
	~SecondView();

private slots:
	void on_backHome_clicked();
	void on_pushButtonBasicData_clicked();

private:
	Ui::SecondView ui;
	INavigator* mNavigator;
};
