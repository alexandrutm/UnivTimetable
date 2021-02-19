#pragma once

#include "ui_HomeView.h"

class INavigator;
class Context;

class HomeView : public QWidget
{
  Q_OBJECT

public:
  HomeView(Context & aContext, INavigator * navigator, QWidget * parent = Q_NULLPTR);
  ~HomeView();

private slots:
  void on_mCreateNewTimetable_clicked();

private:
  Ui::HomeView ui;
  INavigator * mNavigator;
  Context &    mContext;
};
