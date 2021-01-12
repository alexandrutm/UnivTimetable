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
	void ClearData();

private slots:
	void on_mAdd_clicked();
	void on_mEdit_clicked();
	void on_mDelete_clicked();
	void on_mConstraints_clicked();
	void on_mNext_clicked();
	void on_mBack_clicked();
private:
	Ui::ClassesView ui;

	Context& mContext;
	INavigator* mNavigator;
};
