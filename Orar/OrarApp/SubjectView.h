#pragma once

#include "ui_SubjectView.h"

class Context;
class SubjectTableModel;
class SortFilterProxyModel;

class SubjectView : public QWidget
{
  Q_OBJECT

public:
  SubjectView(Context & aContext, QWidget * parent = Q_NULLPTR);
  ~SubjectView();
  void ClearData();

private slots:
  void on_mAdd_clicked();
  void on_mEdit_clicked();
  void on_mDelete_clicked();
  void on_mConstraints_clicked();

private:
  Ui::SubjectView        ui;
  SortFilterProxyModel * proxyModel;
  SubjectTableModel *    tableModel;
  Context &              mContext;
};
