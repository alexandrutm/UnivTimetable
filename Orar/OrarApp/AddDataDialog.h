#pragma once

#include "ui_AddDataDialog.h"
#include <QDialog>

class AddDataDialog
  : public QDialog
  , public Ui::AddDataDialog
{
  Q_OBJECT

public:
  AddDataDialog(QWidget * parent = Q_NULLPTR);
  ~AddDataDialog();

private:
};
