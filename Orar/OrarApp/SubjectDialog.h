#pragma once

#include "ui_SubjectDialog.h"
#include <QDialog>

class SubjectDialog
  : public QDialog
  , public Ui::SubjectDialog
{
  Q_OBJECT

private slots:
  void on_Name_textChanged();

public:
  SubjectDialog(QWidget * parent = Q_NULLPTR);
  ~SubjectDialog();
};
