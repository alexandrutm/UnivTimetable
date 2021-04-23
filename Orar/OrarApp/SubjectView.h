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
  void AddSubject(string aName, int aId);

private slots:
  void on_mAdd_clicked();
  void on_mEdit_clicked();
  void on_mDelete_clicked();

private:
  Ui::SubjectView ui;

  SortFilterProxyModel * proxyModel;
  SubjectTableModel *    tableModel;
  Context &              mContext;
};
