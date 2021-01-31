#pragma once

#include <QWidget>
#include "ui_InstituteDataView.h"

class Context;

class InstituteDataView : public QWidget
{
  Q_OBJECT

  public:
  InstituteDataView(Context &aContext, QWidget *parent = Q_NULLPTR);
  ~InstituteDataView();
  void ClearData();

  private slots:
  void on_Save_clicked();

  private:
  Ui::InstituteDataView ui;
  Context &mContext;
};
