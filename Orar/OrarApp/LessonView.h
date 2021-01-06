#pragma once

#include <QWidget>
#include "ui_LessonView.h"

class INavigator;
class Context;

class LessonView : public QWidget
{
	Q_OBJECT

public:
	LessonView(INavigator* aNavigator, Context& aContext,QWidget *parent = Q_NULLPTR);
	~LessonView();

private slots:

	void on_Add_clicked();
	void on_Edit_clicked();
	void on_Delete_clicked();

private:
	Ui::LessonView ui;
	INavigator* mNavigator;
	Context& mContext;
};
