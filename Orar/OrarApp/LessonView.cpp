#include"stdafx.h"
#include "LessonView.h"
#include "INavigator.h"
#include "LessonDialog.h"
#include "Context.h"
#include "Teacher.h"
#include "Classes.h"
#include "Subject.h"
#include "Lesson.h"

LessonView::LessonView(INavigator* aNavigator, Context& aContext, QWidget* parent)
	: QWidget(parent), mNavigator(aNavigator), mContext(aContext)
{
	ui.setupUi(this);
	QHeaderView* header = ui.tableWidget->horizontalHeader();
	header->setSectionResizeMode(QHeaderView::Stretch);
}

LessonView::~LessonView()
{
}

void LessonView::ClearData()
{
	ui.tableWidget->clearContents();
}

void LessonView::UpdateTable()
{
	this->ClearData();

	auto Lessons = mContext.GetLessons();

	for (auto j : Lessons)
	{
		ui.tableWidget->insertRow(ui.tableWidget->rowCount());

		shared_ptr<Teacher> teacherPtr = (*j).GetTeacher();
		QVariant teacherVar;
		teacherVar.setValue(teacherPtr);

		shared_ptr<Subject> subjectPtr = (*j).GetSubject();
		QVariant subjectVar;
		subjectVar.setValue(subjectPtr);

		shared_ptr<Classes> classPtr = (*j).GetClass();
		QVariant classVar;
		classVar.setValue(classPtr);

		int hoursPerWeekPtr = (*j).GetNumberOfHours();
		QVariant hoursPerWeekVar;
		hoursPerWeekVar.setValue(hoursPerWeekPtr);

		for (int i = 0; i < ui.tableWidget->columnCount(); i++)
		{
			QTableWidgetItem* item = new QTableWidgetItem;


			if (i == 0) {
				item->setText(QString::fromStdString((*teacherPtr).GetLastName()));
				//item->setData(Qt::UserRole,teacherVar);
			}
			if (i == 1) {
				item->setText(QString::fromStdString((*subjectPtr).GetName()));
			}
			if (i == 2) {
				item->setText(QString::fromStdString((*classPtr).GetName()));
			}
			if (i == 3){
				item->setText(QString::number(hoursPerWeekPtr));
			}

			item->setTextAlignment(Qt::AlignHCenter);
			ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, i, item);
		}
	}
}

void LessonView::PopulateDialog(QString instruction)
{
	LessonDialog aDialog(this);

	auto mTeachers = mContext.GetTeachers();

	for (auto i : mTeachers)
	{
		QVariant teacher;
		teacher.setValue(i);
		aDialog.mTeacher->addItem(QString::fromStdString((*i).GetLastName()), teacher);
	}


	auto mSubject = mContext.GetSubjects();

	for (auto i : mSubject)
	{
		QVariant subject;
		subject.setValue(i);
		aDialog.mSubject->addItem(QString::fromStdString((*i).GetName()), subject);
	}

	auto mClass = mContext.GetClasses();

	for (auto i : mClass)
	{
		QVariant classes;
		classes.setValue(i);
		aDialog.mClasses->addItem(QString::fromStdString((*i).GetName()), classes);
	}

	if (instruction == "add") {
		if (aDialog.exec())
		{
			//get data from dialog
			shared_ptr<Teacher> aTeacher = qvariant_cast<shared_ptr<Teacher>>(aDialog.mTeacher->currentData());
			shared_ptr<Subject> aSubject = qvariant_cast<shared_ptr<Subject>>(aDialog.mSubject->currentData());
			shared_ptr<Classes> aClass = qvariant_cast<shared_ptr<Classes>>(aDialog.mClasses->currentData());
			int HoursPerWeek = aDialog.mHoursPerWeek->value();

			//Add lesson to context
			shared_ptr <Lesson> aLesson = make_shared<Lesson>(aTeacher, aSubject, aClass, HoursPerWeek);
			mContext.AddLesson(aLesson);

			this->UpdateTable();
		}
	}
	else
	{
		QTableWidgetItem* currentItem = ui.tableWidget->currentItem();

		if (aDialog.exec())
		{
			//get data from dialog
			shared_ptr<Teacher> aTeacher = qvariant_cast<shared_ptr<Teacher>>(aDialog.mTeacher->currentData());
			shared_ptr<Subject> aSubject = qvariant_cast<shared_ptr<Subject>>(aDialog.mSubject->currentData());
			shared_ptr<Classes> aClass = qvariant_cast<shared_ptr<Classes>>(aDialog.mClasses->currentData());
			int HoursPerWeek = aDialog.mHoursPerWeek->value();

			//Add lesson to context
			shared_ptr <Lesson> aLesson = make_shared<Lesson>(aTeacher, aSubject, aClass, HoursPerWeek);
			mContext.AddLesson(aLesson);

			this->UpdateTable();
		}
	}
}

void LessonView::on_mAdd_clicked()
{
	this->PopulateDialog("add");
}

void LessonView::on_mEdit_clicked()
{
	this->PopulateDialog("edit");
}

void LessonView::on_mDelete_clicked()
{
}

void LessonView::on_mConstraints_clicked()
{

}

void LessonView::on_mGenerate_clicked()
{
	//generate timetable
}

void LessonView::on_mBack_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::teacherView);
}

