#pragma once

#include "ui_TeacherConstraintDialog.h"

class Context;

class TeacherConstraintDialog
  : public QDialog
  , public Ui::TeacherConstraintDialog
{
  Q_OBJECT

public:
  TeacherConstraintDialog(Context & aContext, QWidget * parent = Q_NULLPTR);
  ~TeacherConstraintDialog();

public slots:

  void ColumnClicked(int i);
  void RowClicked(int i);
  void ItemClicked(QTableWidgetItem * item);

private:
  Context & mContext;
};
