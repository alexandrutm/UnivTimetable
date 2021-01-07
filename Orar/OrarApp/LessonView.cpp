#include "LessonView.h"
#include "INavigator.h"
#include "LessonDialog.h"
#include "Context.h"
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

void LessonView::on_Add_clicked()
{
	LessonDialog AddDialog(this);
	AddDialog.mTeacher->setModel(mContext.GetTeacherModelComboBox());
	AddDialog.mSubject->setModel(mContext.GetSubjectModelComboBox());
	AddDialog.mClasses->setModel(mContext.GetClassModelComboBox());


	if (AddDialog.exec())
	{

		QString teacherName = AddDialog.mTeacher->currentText();
		QString subjectName = AddDialog.mSubject->currentText();
		QString className = AddDialog.mClasses->currentText();
		int HoursPerWeek = AddDialog.mHoursPerWeek->value();

		shared_ptr <string> aTeacher = make_shared<string>(teacherName.toStdString());
		shared_ptr <string>aSubject = make_shared<string>(subjectName.toStdString());
		shared_ptr <string> aClass = make_shared<string>(className.toStdString());
		shared_ptr <int>aHoursPerWeek = make_shared<int>(HoursPerWeek);
		shared_ptr <Lesson> aLesson = make_shared<Lesson>(aTeacher, aSubject, aClass, aHoursPerWeek);
		mContext.AddLesson(aLesson);

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


void LessonView::on_Edit_clicked()
{
	LessonDialog EditDialog(this);
	EditDialog.mTeacher->setModel(mContext.GetTeacherModelComboBox());
	EditDialog.mSubject->setModel(mContext.GetSubjectModelComboBox());
	EditDialog.mClasses->setModel(mContext.GetClassModelComboBox());

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

void LessonView::on_Delete_clicked()
{
}


