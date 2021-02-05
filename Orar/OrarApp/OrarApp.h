#pragma once

#include "AddDataDialog.h"
#include "ClassesView.h"
#include "Context.h"
#include "HomeView.h"
#include "INavigator.h"
#include "InstituteDataView.h"
#include "LessonView.h"
#include "RoomView.h"
#include "SubjectView.h"
#include "TeacherView.h"
#include "ui_OrarApp.h"

class TimeTableView;

class OrarApp
  : public QMainWindow
  , public INavigator
{
  Q_OBJECT

public:
  OrarApp(QWidget * parent = Q_NULLPTR);
  void ChangeView(INavigator::viewId theView);
  void ChangeStatus(string);

private slots:

  void on_mNew_triggered();
  void on_mData_triggered();

private:
  Ui::OrarAppClass ui;

  Context mContext;

  TimeTableView * modelTimeTable;

  AddDataDialog     mDataDialog;
  HomeView          mHomeView;
  SubjectView       mSubjectView;
  ClassesView       mClassView;
  RoomView          mRoomView;
  TeacherView       mTeacherView;
  LessonView        mLessonView;
  InstituteDataView mInstituteDataView;
};
