#pragma once

#include "ui_AviabilityConstraintDialog.h "

class Context;

class AvibilityConstraintDialog
  : public QDialog
  , public Ui::AviabilityConstraintDialog
{
  Q_OBJECT

public:
  AvibilityConstraintDialog(Context & aContext, QWidget * parent = Q_NULLPTR);
  ~AvibilityConstraintDialog();

public slots:

  void ColumnClicked(int i);
  void RowClicked(int i);
  void ItemClicked(QTableWidgetItem * item);

private:
  Context & mContext;
};
