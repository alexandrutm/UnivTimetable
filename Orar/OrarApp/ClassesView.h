#pragma once

#include "ui_ClassesView.h"

class Context;
class TreeModel;

class ClassesView : public QWidget
{
  Q_OBJECT

public:
  ClassesView(TreeModel * aTreeModel, Context & aContext, QWidget * parent = Q_NULLPTR);
  ~ClassesView();
  void ClearData();
  void UpdateActions();

private slots:
  void on_mSplitClass_clicked();
  void on_mAddClass_clicked();
  void on_mEdit_clicked();
  void on_mDelete_clicked();

private:
  Ui::ClassesView ui;

  TreeModel * mTreeModel;

  Context & mContext;
};
