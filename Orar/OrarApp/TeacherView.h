#pragma once

#include <QWidget>
#include "ui_TeacherView.h"

class INavigator;
class Context;
class TableModel;

class TeacherView : public QWidget
{
	Q_OBJECT

public:
	TeacherView(INavigator* aNavigator, Context& aContext,QWidget *parent = Q_NULLPTR);
	~TeacherView();


private slots:
	void on_mAdd_clicked();
	void on_mEdit_clicked();
	void on_mDelete_clicked();
	void on_mConstraints_clicked();
	void on_mNext_clicked();
	void on_mBack_clicked();

private:
	Ui::TeacherView ui;
	INavigator* mNavigator;
	TableModel* tableModel;
	Context& mContext;
};
