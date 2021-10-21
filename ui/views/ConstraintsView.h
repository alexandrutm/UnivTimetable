#pragma once

#include "ui_ConstraintsView.h"

class Context;
class TeacherTableModel;
class ConstraintListModel;

class ConstraintsView : public QWidget
{
  Q_OBJECT

public:
  ConstraintsView(Context & Context, QWidget * parent = Q_NULLPTR);
  ~ConstraintsView();
public slots:
  void on_mAdd_clicked();
  void on_mDelete_clicked();

  void ListItemChanged(QModelIndex index);
  void AddTeacherConstraint();

private:
  Ui::ConstraintsView ui;

  TeacherTableModel *   mTeacherModel;
  ConstraintListModel * mListModel;

  QMenu *   addButtonMenu;
  Context & mContext;
};
