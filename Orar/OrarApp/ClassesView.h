#pragma once

#include <QWidget>
#include "ui_ClassesView.h"

class Context;
class INavigator;

class ClassesView : public QWidget
{
	Q_OBJECT

public:
	ClassesView(INavigator *aNavigator,Context & aContext,QWidget *parent = Q_NULLPTR);
	~ClassesView();

private slots:
	void on_Add_clicked();
	void on_Edit_clicked();
	void on_Delete_clicked();
	void on_Constraints_clicked();

private:
	Ui::ClassesView ui;

	Context& mContext;
	INavigator* mNavigator;
};
