#pragma once

#include "AddDataDialog.h"
#include "ClassesView.h"
#include "ConstraintsView.h"
#include "Context.h"
#include "DisplayTimetableView.h"
#include "HomeView.h"
#include "INavigator.h"
#include "InstituteData.h"
#include "LessonView.h"
#include "RoomView.h"
#include "SubjectView.h"
#include "TeacherView.h"
#include "ui_OrarApp.h"

class TreeModel;

class OrarApp
  : public QMainWindow
  , public INavigator
{
  Q_OBJECT

public:
  OrarApp(QWidget * parent = Q_NULLPTR);
  ~OrarApp();
  void ChangeView(INavigator::viewId theView);
  void ChangeStatus(string);

private slots:
  // toolbar actions
  void on_mNew_triggered();
  void on_mData_triggered();
  void on_mGenerate_triggered();
  void on_mInstitutionData_triggered();

private:
  Ui::OrarAppClass ui;

  Context mContext;

  TreeModel * mClassesModel;

  AddDataDialog mDataDialog;

  HomeView             mHomeView;
  SubjectView          mSubjectView;
  ClassesView          mClassView;
  RoomView             mRoomView;
  TeacherView          mTeacherView;
  LessonView           mLessonView;
  DisplayTimetableView mDisplayTimeTableView;
  ConstraintsView      mConstraintsView;
};
