#pragma once

#include <QWidget>
#include "ui_TeacherView.h"

class INavigator;
class Context;

class TeacherView : public QWidget
{
	Q_OBJECT

public:
	TeacherView(INavigator* aNavigator, Context& aContext,QWidget *parent = Q_NULLPTR);
	~TeacherView();
	void ClearData();

private slots:
	void on_Add_clicked();
	void on_Edit_clicked();
	void on_Delete_clicked();

private:
	Ui::TeacherView ui;
	INavigator* mNavigator;
	Context& mContext;
};
