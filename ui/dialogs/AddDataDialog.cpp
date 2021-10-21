#include "stdafx.h"
#include "AddDataDialog.h"
#include "Context.h"

AddDataDialog::AddDataDialog(Context & aContext, QWidget * parent)
  : QDialog(parent)
  , mContext(aContext)
  , mClassView(mContext, this)
  , mSubjectView(mContext, this)
  , mRoomView(mContext, this)
  , mTeacherView(mContext, this)
  , mLessonView(mContext, this)
  , mConstraintsView(mContext, this)
{
  setupUi(this);
  // Basic data Dialog

  mData->addTab(&mSubjectView, "Subjects");
  mData->addTab(&mClassView, "Classes");
  mData->addTab(&mRoomView, "Rooms");
  mData->addTab(&mTeacherView, "Teachers");
  mData->addTab(&mLessonView, "Lessons");
  mData->addTab(&mConstraintsView, "Constraints");
}

AddDataDialog::~AddDataDialog()
{
}

void AddDataDialog::AddTreeModel(shared_ptr<TreeModel> aClassesModel)
{
  mClassView.AddModel(aClassesModel);
}
