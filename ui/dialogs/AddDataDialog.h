#pragma once
#include "../views/ClassesView.h"
#include "../views/ConstraintsView.h"
#include "../views/LessonView.h"
#include "../views/RoomView.h"
#include "../views/SubjectView.h"
#include "../views/TeacherView.h"
#include "ui_AddDataDialog.h"

class Context;

class AddDataDialog
  : public QDialog
  , public Ui::AddDataDialog
{
  Q_OBJECT

public:
  AddDataDialog(Context & aContext, QWidget * parent = Q_NULLPTR);
  ~AddDataDialog();
  void AddTreeModel(shared_ptr<TreeModel> aClassesModel);

private:
  Context & mContext;

  SubjectView     mSubjectView;
  ClassesView     mClassView;
  RoomView        mRoomView;
  TeacherView     mTeacherView;
  LessonView      mLessonView;
  ConstraintsView mConstraintsView;
};
