#pragma once

#include <QWidget>
#include "ui_BasicInfoView.h"

class Context;

class BasicInfoView : public QWidget
{
	Q_OBJECT

public:
	BasicInfoView(Context &aContext,QWidget *parent = Q_NULLPTR);
	~BasicInfoView();
	void ClearData();

private slots:
	void on_Save_clicked();

private:
	Ui::BasicInfoView ui;
	Context& mContext;
};
