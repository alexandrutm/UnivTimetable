#include"stdafx.h"
#include "LessonView.h"
#include "INavigator.h"
#include "LessonDialog.h"
#include "Context.h"
#include "Teacher.h"
#include "Classes.h"
#include "Subject.h"
#include "Lesson.h"
#include "TeacherTableModel.h"
#include "SubjectTableModel.h"
#include "ClassTableModel.h"
#include "RoomTableModel.h"
#include "LessonTableModel.h"


LessonView::LessonView(INavigator* aNavigator, Context& aContext, QWidget* parent)
	: QWidget(parent), mNavigator(aNavigator), mContext(aContext)
{
	ui.setupUi(this);

	mTeacherModel = new TableModel(mContext,this);
	mSubjectModel = new SubjectTableModel(mContext, this);
	mClassModel = new ClassTableModel(mContext, this);
	mRoomTableModel = new RoomTableModel(mContext, this);

	tableModel = new LessonTableModel(mContext, this);

	ui.mTable->setModel(tableModel);

	QHeaderView* header = ui.mTable->horizontalHeader();
	header->setSectionResizeMode(QHeaderView::Stretch);;
}

LessonView::~LessonView()
{
}

void LessonView::on_mAdd_clicked()
{
	LessonDialog aDialog(this);

	aDialog.mTeacher->setModel(mTeacherModel);
	aDialog.mSubject->setModel(mSubjectModel);
	aDialog.mClasses->setModel(mClassModel);

	if (aDialog.exec())
	{
		auto selectedTeacher = aDialog.mTeacher->currentIndex();
		auto teacher = mContext.GetTeacherByIndex(selectedTeacher);

		auto selectedSubject = aDialog.mSubject->currentIndex();
		auto subject = mContext.GetSubjectByIndex(selectedSubject);

		auto selectedClass = aDialog.mClasses->currentIndex();
		auto classes = mContext.GetClassByIndex(selectedClass);

		auto hoursPerWeek = aDialog.mHoursPerWeek->value();

		shared_ptr<Lesson> newLesson = make_shared<Lesson>(teacher, subject, classes, hoursPerWeek);

		tableModel->PopulateModel(newLesson);
	}
}

void LessonView::on_mEdit_clicked()
{
	LessonDialog aDialog(this);

	aDialog.mTeacher->setModel(mTeacherModel);
	aDialog.mSubject->setModel(mSubjectModel);
	aDialog.mClasses->setModel(mClassModel);

	auto selectedRow = ui.mTable->selectionModel()->currentIndex().row();
	
	if (selectedRow < 0)
	{
		QMessageBox::about(this, "No item selected", "Please choose an item to edit");
	}
	else
		if (aDialog.exec())
		{
			auto selectedTeacher = aDialog.mTeacher->currentIndex();
			auto teacher = mContext.GetTeacherByIndex(selectedTeacher);

			auto selectedSubject = aDialog.mSubject->currentIndex();
			auto subject = mContext.GetSubjectByIndex(selectedSubject);

			auto selectedClass = aDialog.mClasses->currentIndex();
			auto classes = mContext.GetClassByIndex(selectedClass);

			auto hoursPerWeek = aDialog.mHoursPerWeek->value();

			shared_ptr<Lesson> newLesson = make_shared<Lesson>(teacher, subject, classes, hoursPerWeek);

			tableModel->EditModel(selectedRow,newLesson);

		}

}

void LessonView::on_mDelete_clicked()
{
	auto selectedRow = ui.mTable->selectionModel()->currentIndex().row();

	if (selectedRow < 0)
	{
		QMessageBox::about(this, "No item selected", "Please choose an item to delete");
	}
	else
	{
		tableModel->RemoveItemFromModel(selectedRow);
	}
}

void LessonView::on_mConstraints_clicked()
{

}

void LessonView::on_mBack_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::teacherView);
}

