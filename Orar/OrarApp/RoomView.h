#pragma once

#include <QWidget>
#include "ui_RoomView.h"

class INavigator;
class Context;

class RoomView : public QWidget
{
	Q_OBJECT

public:
	RoomView(INavigator* , Context&,QWidget *parent = Q_NULLPTR);
	~RoomView();
private slots:
	void on_mAdd_clicked();
	void on_mEdit_clicked();
	void on_mDelete_clicked();
	void on_mConstraints_clicked();
	void on_mNext_clicked();
	void on_mBack_clicked();

private:
	Ui::RoomView ui;

	INavigator *mNavigator;
	Context& mContext;
};
