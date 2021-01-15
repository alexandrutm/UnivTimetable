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
	void ClearData();
	void UpdateTable();
	void PopulateDialog(QString instuction);

private slots:

	void on_mAdd_clicked();
	void on_mEdit_clicked();
	void on_mDelete_clicked();
	void on_mConstraints_clicked();
	void on_mGenerate_clicked();
	void on_mBack_clicked();


private:
	Ui::LessonView ui;
	INavigator* mNavigator;
	Context& mContext;
};
