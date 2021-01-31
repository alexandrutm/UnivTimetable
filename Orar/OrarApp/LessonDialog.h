#pragma once

#include <QDialog>
#include "ui_LessonDialog.h"


class LessonDialog : public QDialog, public Ui::LessonDialog
{
  Q_OBJECT

  public:
  LessonDialog(QWidget *parent = Q_NULLPTR);
  ~LessonDialog();
};
