#pragma once
#include "ui/views/ClassesView.h"
#include "ui/views/ConstraintsView.h"
#include "ui/views/LessonView.h"
#include "ui/views/RoomView.h"
#include "ui/views/SubjectView.h"
#include "ui/views/TeacherView.h"
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
