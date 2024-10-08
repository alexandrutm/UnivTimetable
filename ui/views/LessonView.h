#pragma once

#include "ui_LessonView.h"

class Context;

class TeacherTableModel;
class SortFilterProxyModel;
class SubjectTableModel;
class TreeModel;
class RoomTableModel;
class LessonTableModel;

class LessonView : public QWidget
{
  Q_OBJECT

public:
  LessonView(Context & aContext, QWidget * parent = Q_NULLPTR);
  ~LessonView();
  void ClearData();

private slots:

  void on_mAdd_clicked();
  void on_mEdit_clicked();
  void on_mDelete_clicked();

private:
  Ui::LessonView ui;
  Context &      mContext;

  TeacherTableModel *          mTeacherModel;
  SubjectTableModel *          mSubjectModel;
  TreeModel *                  mClassModel;
  RoomTableModel *             mRoomTableModel;
  shared_ptr<LessonTableModel> tableModel;
  SortFilterProxyModel *       proxyModel;
};
