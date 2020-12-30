#pragma once

#include <QWidget>
#include "ui_BasicInfoView.h"
#include"SubjectDialog.h"

class INavigator;
class Context;

class BasicInfoView : public QWidget
{
	Q_OBJECT

public:
	BasicInfoView(INavigator* navigator,Context &aContext,QWidget *parent = Q_NULLPTR);
	~BasicInfoView();

private slots:
	void on_NextButtonBasicInfo_clicked();


private:
	Ui::BasicInfoView ui;
	INavigator *mNavigator;
	Context& mContext;
};
