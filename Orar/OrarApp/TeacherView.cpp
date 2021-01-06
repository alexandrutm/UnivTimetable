#include "TeacherView.h"
#include "INavigator.h"
#include "Context.h"
#include "TeacherDialog.h"

TeacherView::TeacherView(INavigator* aNavigator, Context& aContext,QWidget *parent)
	: QWidget(parent),mNavigator(aNavigator),mContext(aContext)
{
	ui.setupUi(this);
}

TeacherView::~TeacherView()
{
}

void TeacherView::on_Add_clicked()
{
	TeacherDialog Add(this);

	if (Add.exec())
	{
		QString firstName = Add.mFirstName->text();
		QString lastName = Add.mLastName->text();
		if (!firstName.isEmpty())
		{
			QListWidgetItem* item = new QListWidgetItem(firstName, ui.list);
			item->setData(Qt::UserRole,lastName);
			ui.list->setCurrentItem(item);

			//store data
			Teacher newTeacher;
			
			newTeacher.SetFirstName(firstName.toStdString());
			newTeacher.SetLastName(lastName.toStdString());
			mContext.AddTeacher(newTeacher);

			mNavigator->ChangeStatus("New teacher added");
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


