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
	ui.mList->clear();
}

void TeacherView::UpdateList()
{
	this->ClearData();

	auto mTeachers = mContext.GetTeachers();

	for (auto i : mTeachers)
	{
		QVariant teacher;
		teacher.setValue(i);

		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString((*i).GetFirstName()), ui.mList);
		item->setData(Qt::UserRole,teacher);
		ui.mList->setCurrentItem(item);
	}

}

void TeacherView::on_mAdd_clicked()
{
	TeacherDialog Add(this);

	if (Add.exec())
	{
		
		QString firstName = Add.mFirstName->text();
		QString lastName = Add.mLastName->text();
		if (!firstName.isEmpty())
		{
			//first store data in context and after that load data from context in ui
			shared_ptr<Teacher> newTeacher = make_shared<Teacher>(firstName.toStdString(), lastName.toStdString());
			mContext.AddTeacher(newTeacher);

			//update ui
			this->UpdateList();
		}
		else
		{
			QMessageBox::about(this, "Name eror", "You need to fill all fields with *");
		}

	}

}

void TeacherView::on_mEdit_clicked()
{
	TeacherDialog Edit(this);

	QListWidgetItem* item = ui.mList->currentItem();

	if (item)
	{

		if (Edit.exec())
		{
			QString firstName = Edit.mFirstName->text();
			QString lastName = Edit.mLastName->text();

			shared_ptr<Teacher> oldTeacher = qvariant_cast<shared_ptr<Teacher>>(item->data(Qt::UserRole));
			shared_ptr<Teacher>newTeacher = make_shared<Teacher>(firstName.toStdString(), lastName.toStdString());

			mContext.EditTeacher(oldTeacher, newTeacher);

			this->UpdateList();
		}
	}
}

void TeacherView::on_mDelete_clicked()
{
	QListWidgetItem* item = ui.mList->currentItem();

	if (item)
	{
		mContext.RemoveTeacher(qvariant_cast<shared_ptr<Teacher>>(item->data(Qt::UserRole)));
		delete item;

		this->UpdateList();
	}
	else
	{
		QMessageBox::about(this, "Delete", "Please choose what you want to delete");
	}
}

void TeacherView::on_mConstraints_clicked()
{
}

void TeacherView::on_mNext_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::lessonView);
}

void TeacherView::on_mBack_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::roomView);
}


