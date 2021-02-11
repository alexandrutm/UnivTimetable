#pragma once

#include "ui_InstituteDataView.h"

class Context;
class INavigator;
class InstituteDataView : public QWidget
{
  Q_OBJECT

public:
  InstituteDataView(Context & aContext, INavigator * aNavigator, QWidget * parent = Q_NULLPTR);
  ~InstituteDataView();
  void ClearData();

private slots:
  void on_mSave_clicked();

private:
  Ui::InstituteDataView ui;
  Context &             mContext;
  INavigator *          mNavigator;
};
