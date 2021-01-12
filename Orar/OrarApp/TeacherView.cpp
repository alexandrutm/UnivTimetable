#include "stdafx.h"
#include "TeacherView.h"
#include "INavigator.h"
#include "Context.h"
#include "TeacherDialog.h"
#include "Teacher.h"

TeacherView::TeacherView(INavigator* aNavigator, Context& aContext,QWidget *parent)
	: QWidget(parent),mNavigator(aNavigator),mContext(aContext)
{
	ui.setupUi(this);
}

TeacherView::~TeacherView()
{
}

void TeacherView::ClearData()
{
	ui.list->clear();
}

QStringList TeacherView::GetTeacherList()
{
	QStringList list;

	auto mTeachers = mContext.GetTeachers();

	for (auto i : mTeachers)
	{
		list.append(QString::fromStdString((*i).GetFirstName()));
	}

	return list;
}



void TeacherView::on_Add_clicked()
{
	TeacherDialog Add(this);

	if (Add.exec())
	{
		//first store data in context and after that load data from context in ui
		QString firstName = Add.mFirstName->text();
		QString lastName = Add.mLastName->text();
		if (!firstName.isEmpty())
		{
			shared_ptr<Teacher> newTeacher = make_shared<Teacher>(firstName.toStdString(), lastName.toStdString());
			mContext.AddTeacher(newTeacher);

			//load data in ui
			ui.list->clear();
			ui.list->insertItems(0, this->GetTeacherList());

		}

	}

}

void TeacherView::on_Edit_clicked()
{
	TeacherDialog Edit(this);

	QListWidgetItem* item = ui.list->currentItem();

	if (item)
	{
		
		Edit.mFirstName->setText(item->text());
		Edit.mLastName->setText(item->data(Qt::UserRole).toString());

		if (Edit.exec())
		{
			QString firstName = Edit.mFirstName->text();
			QString lastName = Edit.mLastName->text();

			mContext.EditTeacherByFirstName(item->text().toStdString(),firstName.toStdString(),lastName.toStdString());

			item->setText(firstName);
			item->setData(Qt::UserRole, lastName);
		}
	}
}

void TeacherView::on_Delete_clicked()
{
	QListWidgetItem* item = ui.list->currentItem();

	if (item)
	{
		int row = ui.list->row(item);
		ui.list->takeItem(row);

		string name = item->text().toStdString();
		mContext.RemoveTeacherByFirstName(name);
		delete item;

		if (ui.list->count() > 0)
			ui.list->setCurrentRow(row);
	}
}


