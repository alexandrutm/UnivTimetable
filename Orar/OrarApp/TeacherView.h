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
  void AddTeacher(string aFirstName, string aLastName, int aId);

private slots:
  void on_mAdd_clicked();
  void on_mEdit_clicked();
  void on_mDelete_clicked();

public:
  Ui::TeacherView ui;

private:
  SortFilterProxyModel * mTeacherProxyModel;
  TeacherTableModel *    mTeacherTableModel;

  Context & mContext;
};
