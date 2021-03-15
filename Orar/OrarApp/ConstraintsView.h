#pragma once

#include "ui_ConstraintsView.h"

class Context;

class ConstraintsView : public QWidget
{
  Q_OBJECT

public:
  ConstraintsView(Context & Context, QWidget * parent = Q_NULLPTR);
  ~ConstraintsView();
public slots:
  void on_mAdd_clicked();
  void on_mEdit_clicked();
  void on_mDelete_clicked();

  void AddTeacherConstraint();

private:
  Ui::ConstraintsView ui;

  QMenu *   addButtonMenu;
  Context & mContext;
};
