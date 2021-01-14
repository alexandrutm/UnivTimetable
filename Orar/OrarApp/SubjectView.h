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
	void ClearData();
	void UpdateList();

private slots:
	void on_mAdd_clicked();
	void on_mEdit_clicked();
	void on_mDelete_clicked();
	void on_mConstraints_clicked();
	void on_mNext_clicked();
	void on_mBack_clicked();

private:
	Ui::SubjectView ui;
	INavigator *mNavigator;
	Context& mContext;
	
};
