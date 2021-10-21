#pragma once

#include "ui_TeacherDialog.h"

class TeacherDialog
  : public QDialog
  , public Ui::TeacherDialog
{
  Q_OBJECT

public:
  TeacherDialog(QWidget * parent = Q_NULLPTR);
  ~TeacherDialog();

  void EditEntry(QString fName, QString lName);
};
