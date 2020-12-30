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
	void on_NextButtonSubject_clicked();
	void on_AddSubjectButton_clicked();
	void on_pushButtonBackSubject_clicked();
	void on_DeleteSubjectButton_clicked();
	void on_EditSubjectButton_clicked();

	void on_listWidgetSubject_currentItemChanged();
	

private:
	Ui::SubjectView ui;
	INavigator *mNavigator;
	Context& mContext;
	
};
