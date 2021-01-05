#include "LessonDialog.h"
#include <QStringListModel>
#include "stdafx.h"
#include "Context.h"

LessonDialog::LessonDialog(Context& aContex,QWidget *parent)
	: QDialog(parent),mContext(aContex)
{
	setupUi(this);

	mTeacher->setModel(mContext.GetTeacherModelComboBox());
	mSubject->setModel(mContext.GetSubjectModelComboBox());
	mClasses->setModel(mContext.GetClassModelComboBox());

}

LessonDialog::~LessonDialog()
{
}
