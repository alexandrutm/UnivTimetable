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
  void AddClass(string aName, int aNumberOfStudents, int aId, int parentId);

private slots:
  void on_mSplitClass_clicked();
  void on_mAddClass_clicked();
  void on_mEdit_clicked();
  void on_mDelete_clicked();

private:
  Ui::ClassesView ui;

  vector<pair<int, QModelIndex>> idIndexPair;

  TreeModel *                mTreeModel;
  QAbstractItemModelTester * modelTester;
  Context &                  mContext;
};
