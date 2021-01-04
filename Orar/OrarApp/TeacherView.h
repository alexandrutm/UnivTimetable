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
private slots:
	void on_pushBtnAdd_clicked();
	void on_pushBtnEdit_clicked();
	void on_pushBtnDelete_clicked();
	void on_pushBtnBack_clicked();
	void on_pushBtnNext_clicked();

private:
	Ui::TeacherView ui;
	INavigator* mNavigator;
	Context& mContext;
};
