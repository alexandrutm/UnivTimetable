#pragma once

#include "ui_TeacherDialog.h"
#include <QDialog>

class TeacherDialog
  : public QDialog
  , public Ui::TeacherDialog
{
  Q_OBJECT

public:
  TeacherDialog(QWidget * parent = Q_NULLPTR);
  ~TeacherDialog();
};
