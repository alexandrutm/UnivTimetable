#pragma once

#include "ui_LessonDialog.h"
#include <QDialog>

class LessonDialog
  : public QDialog
  , public Ui::LessonDialog
{
  Q_OBJECT

public:
  LessonDialog(QWidget * parent = Q_NULLPTR);
  ~LessonDialog();
};
