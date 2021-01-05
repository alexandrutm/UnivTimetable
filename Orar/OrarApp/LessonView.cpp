#include "LessonView.h"
#include"INavigator.h"
#include "LessonDialog.h"

LessonView::LessonView(INavigator * aNavigator,Context& aContext,QWidget *parent)
	: QWidget(parent),mNavigator(aNavigator),mContext(aContext)
{
	ui.setupUi(this);
}

LessonView::~LessonView()
{
}

void LessonView::on_pushBtnEdit_clicked()
{
}

void LessonView::on_pushBtnDelete_clicked()
{
}

void LessonView::on_pushBtnNext_clicked()
{
}

void LessonView::on_pushBtnBack_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::teacherView);
}

void LessonView::on_pushBtnAdd_clicked()
{
	LessonDialog AddDialog(mContext,this);
	int column = 4;
	int static row = 0;


	if (AddDialog.exec())
	{
		QString teacherName = AddDialog.mTeacher->currentText();
			//get data AddDialog.mTeacher->itemData(AddDialog.mTeacher->currentIndex());
		QString subjectName = AddDialog.mSubject->currentText();
		QString className = AddDialog.mClasses->currentText();
		int HoursPerWeek = AddDialog.mHoursPerWeek->value();
		
		ui.tableWidget->insertRow(ui.tableWidget->rowCount());
		QTableWidgetItem* item;
		for (int i = 0; i < column; i++)
		{
			item = new QTableWidgetItem;

			if (i == 0)
				item->setText(teacherName);
			if (i == 1)
				item->setText(subjectName);
			if (i == 2)
				item->setText(className);
			if (i == 3)
				item->setText(QString::number(HoursPerWeek));

			item->setTextAlignment(Qt::AlignHCenter);
			ui.tableWidget->setItem(ui.tableWidget->rowCount() - 1,i,item);
		}
	}

	row++;
}
