#pragma once

#include "ui_TeacherView.h"

class Context;
class TeacherTableModel;
class SortFilterProxyModel;

class TeacherView : public QWidget
{
  Q_OBJECT

public:
  TeacherView(Context & aContext, QWidget * parent = Q_NULLPTR);
  ~TeacherView();
  void ClearData();

private slots:
  void on_mAdd_clicked();
  void on_mEdit_clicked();
  void on_mDelete_clicked();

private:
  Ui::TeacherView ui;

  SortFilterProxyModel * mTeacherProxyModel;
  TeacherTableModel *    mTeacherTableModel;

  Context & mContext;
};
