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

	void on_pushBtnAdd_clicked();
	void on_pushBtnEdit_clicked();
	void on_pushBtnDelete_clicked();
	void on_pushBtnNext_clicked();
	void on_pushBtnBack_clicked();

private:
	Ui::LessonView ui;
	INavigator* mNavigator;
	Context& mContext;
};
