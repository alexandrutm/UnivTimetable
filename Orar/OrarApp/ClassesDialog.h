#pragma once

#include "ui_ClassesDialog.h"
#include <QDialog>

class ClassesDialog
  : public QDialog
  , public Ui::ClassesDialog
{
  Q_OBJECT

private slots:
  void on_Name_textChanged();

public:
  ClassesDialog(QWidget * parent = Q_NULLPTR);
  ~ClassesDialog();
};
