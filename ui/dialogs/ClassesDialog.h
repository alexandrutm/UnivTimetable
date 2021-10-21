#pragma once

#include "ui_ClassesDialog.h"

class ClassesDialog
  : public QDialog
  , public Ui::ClassesDialog
{
  Q_OBJECT

private slots:
  void on_Name_textChanged();

public:
  ClassesDialog(QWidget * aParent = Q_NULLPTR);
  ~ClassesDialog();
  void EditEntry(QString aName, int aNumberOfStudent);
};
