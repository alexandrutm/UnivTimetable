#pragma once

#include "ui_TeacherView.h"

class Context;
class TableModel;
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
  void on_mConstraints_clicked();

private:
  Ui::TeacherView        ui;
  SortFilterProxyModel * proxyModel;
  TableModel *           tableModel;
  Context &              mContext;
};
