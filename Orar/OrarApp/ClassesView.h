#pragma once

#include <QWidget>
#include "ui_ClassesView.h"

class ClassesView : public QWidget
{
	Q_OBJECT

public:
	ClassesView(QWidget *parent = Q_NULLPTR);
	~ClassesView();

private:
	Ui::ClassesView ui;
};
