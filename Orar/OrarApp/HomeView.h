#pragma once

#include "ui_HomeView.h"
#include <QWidget>

class INavigator;

class HomeView : public QWidget
{
  Q_OBJECT

public:
  HomeView(INavigator * navigator, QWidget * parent = Q_NULLPTR);
  ~HomeView();

private slots:
  void on_mCreateNewTimetable_clicked();

private:
  Ui::HomeView ui;
  INavigator * mNavigator;
};
