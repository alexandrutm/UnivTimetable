#pragma once

#include "ui_ClassesView.h"

class Context;
class TreeModel;

class ClassesView : public QWidget
{
  Q_OBJECT

public:
  ClassesView(Context & aContext, QWidget * parent = Q_NULLPTR);
  ~ClassesView();
  void ClearData();
  void UpdateActions();
  void AddModel(shared_ptr<TreeModel> aTreeModel);

private slots:
  void on_mSplitClass_clicked();
  void on_mAddClass_clicked();
  void on_mEdit_clicked();
  void on_mDelete_clicked();

private:
  Ui::ClassesView ui;

  Context & mContext;

  shared_ptr<TreeModel> mTreeModel;

  QAbstractItemModelTester * modelTester;
};
