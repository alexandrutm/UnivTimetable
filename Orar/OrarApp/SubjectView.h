#pragma once

#include <QWidget>
#include "ui_SubjectView.h"

class INavigator;
class Context;

class SubjectView : public QWidget
{
	Q_OBJECT

public:
	SubjectView(INavigator* aNavigator,Context& aContext,QWidget *parent = Q_NULLPTR);
	~SubjectView();

private slots:
	void on_Add_clicked();
	void on_Edit_clicked();
	void on_Delete_clicked();

private:
	Ui::SubjectView ui;
	INavigator *mNavigator;
	Context& mContext;
	
};
