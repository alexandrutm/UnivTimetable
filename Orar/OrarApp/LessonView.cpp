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

void LessonView::on_mAdd_clicked()
{
	LessonDialog AddDialog(this);
	AddDialog.mTeacher->setModel(this->GetTeacherModelComboBox());
	AddDialog.mSubject->setModel(this->GetSubjectModelComboBox());
	AddDialog.mClasses->setModel(this->GetClassModelComboBox());


	if (AddDialog.exec())
	{
		//get data from dialog
		QString teacherName = AddDialog.mTeacher->currentText();
		QString subjectName = AddDialog.mSubject->currentText();
		QString className = AddDialog.mClasses->currentText();
		int HoursPerWeek = AddDialog.mHoursPerWeek->value();

		//Add lesson to context
		shared_ptr <string> aTeacher = make_shared<string>(teacherName.toStdString());
		shared_ptr <string>aSubject = make_shared<string>(subjectName.toStdString());
		shared_ptr <string> aClass = make_shared<string>(className.toStdString());
		shared_ptr <int>aHoursPerWeek = make_shared<int>(HoursPerWeek);
		shared_ptr <Lesson> aLesson = make_shared<Lesson>(aTeacher, aSubject, aClass, aHoursPerWeek);
		mContext.AddLesson(aLesson);

		//add data to ui(table)
		ui.tableWidget->insertRow(ui.tableWidget->rowCount());
		for (int i = 0; i < ui.tableWidget->columnCount(); i++)
		{
			QTableWidgetItem* item = new QTableWidgetItem;

			if (i == 0)
				item->setText(teacherName);
			if (i == 1)
				item->setText(subjectName);
			if (i == 2)
				item->setText(className);
			if (i == 3)
				item->setText(QString::number(HoursPerWeek));

			item->setTextAlignment(Qt::AlignHCenter);
			ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1, i, item);
		}



	}
}


void LessonView::on_mEdit_clicked()
{
	LessonDialog EditDialog(this);
	EditDialog.mTeacher->setModel(this->GetTeacherModelComboBox());
	EditDialog.mSubject->setModel(this->GetSubjectModelComboBox());
	EditDialog.mClasses->setModel(this->GetClassModelComboBox());

	if (EditDialog.exec()) {

		QString teacherName = EditDialog.mTeacher->currentText();
		QString subjectName = EditDialog.mSubject->currentText();
		QString className = EditDialog.mClasses->currentText();
		int HoursPerWeek = EditDialog.mHoursPerWeek->value();

		int row = ui.tableWidget->currentRow();

		for (int i = 0; i < ui.tableWidget->columnCount(); i++)
		{

			QTableWidgetItem* item = new QTableWidgetItem;

			if (i == 0)
				item->setText(teacherName);
			if (i == 1)
				item->setText(subjectName);
			if (i == 2)
				item->setText(className);
			if (i == 3)
				item->setText(QString::number(HoursPerWeek));

			item->setTextAlignment(Qt::AlignHCenter);
			ui.tableWidget->setItem(row, i, item);

		}
	}
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


QStringListModel* LessonView::GetTeacherModelComboBox()
{
	QStringList listOfNames;

	auto mTeachers = mContext.GetTeachers();

	for (int i = 0; i < mTeachers.size(); i++)
	{
		listOfNames << QString::fromStdString(mTeachers[i]->GetFirstName());
	}

	QStringListModel* model = new QStringListModel();
	model->setStringList(listOfNames);

	return model;
}

QStringListModel* LessonView::GetSubjectModelComboBox()
{
	QStringList listOfNames;
	auto mSubjects = mContext.GetSubjects();
	for (int i = 0; i < mSubjects.size(); i++)
	{
		listOfNames << QString::fromStdString(mSubjects[i]->GetName());
	}

	QStringListModel* model = new QStringListModel();
	model->setStringList(listOfNames);

	return model;
}

QStringListModel* LessonView::GetClassModelComboBox()
{
	QStringList listOfNames;
	
	auto mClasses = mContext.GetClasses();

	for (int i = 0; i < mClasses.size(); i++)
	{
		listOfNames << QString::fromStdString(mClasses[i]->GetName());
	}

	QStringListModel* model = new QStringListModel();
	model->setStringList(listOfNames);

	return model;
}
