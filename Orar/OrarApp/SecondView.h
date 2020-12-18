#pragma once

#include <QWidget>
#include "ui_SecondView.h"

class SecondView : public QWidget
{
	Q_OBJECT

public:
	SecondView(QWidget *parent = Q_NULLPTR);
	~SecondView();

private:
	Ui::SecondView ui;
};
