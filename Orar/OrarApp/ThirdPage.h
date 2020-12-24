#pragma once

#include <QWidget>
#include "ui_ThirdPage.h"
#include"SubjectDialog.h"

class INavigator;
class Context;

class ThirdPage : public QWidget
{
	Q_OBJECT

public:
	ThirdPage(INavigator* navigator,Context &aContext,QWidget *parent = Q_NULLPTR);
	~ThirdPage();

private slots:
	void on_NextButtonBasicInfo_clicked();
	void on_NextButtonSubject_clicked();
	void on_AddSubjectButton_clicked();

	void on_listWidgetSubject_currentItemChanged();


private:
	Ui::ThirdPage ui;
	INavigator* mNavigator;
	Context& mContext;
};
