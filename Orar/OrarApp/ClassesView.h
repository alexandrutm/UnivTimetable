#pragma once

#include "ui_ClassesView.h"

class Context;
class ClassTableModel;
class SortFilterProxyModel;

class ClassesView : public QWidget
{
  Q_OBJECT

public:
  ClassesView(Context & aContext, QWidget * parent = Q_NULLPTR);
  ~ClassesView();
  void ClearData();

private slots:
  void on_mAdd_clicked();
  void on_mEdit_clicked();
  void on_mDelete_clicked();
  void on_mConstraints_clicked();

private:
  Ui::ClassesView ui;

  SortFilterProxyModel * proxyModel;
  ClassTableModel *      tableModel;
  Context &              mContext;
};
