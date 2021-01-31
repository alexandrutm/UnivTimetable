#pragma once

#include <QWidget>
#include "ui_TeacherView.h"

class Context;
class TableModel;

class TeacherView : public QWidget
{
  Q_OBJECT

  public:
  TeacherView(Context& aContext, QWidget* parent = Q_NULLPTR);
  ~TeacherView();
  void ClearData();

  private slots:
  void on_mAdd_clicked();
  void on_mEdit_clicked();
  void on_mDelete_clicked();
  void on_mConstraints_clicked();

  private:
  Ui::TeacherView ui;
  TableModel* tableModel;
  Context& mContext;
};
