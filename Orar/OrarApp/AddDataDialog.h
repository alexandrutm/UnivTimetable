#pragma once

#include <QDialog>
#include "ui_AddDataDialog.h"


class AddDataDialog : public QDialog, public Ui::AddDataDialog
{
  Q_OBJECT

  public:
  AddDataDialog(QWidget *parent = Q_NULLPTR);
  ~AddDataDialog();


  private:
};
