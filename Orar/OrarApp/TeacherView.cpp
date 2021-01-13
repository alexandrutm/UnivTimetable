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

QStandardItemModel* TeacherView::GetTeacherTableModel()
{

	QStandardItemModel* model = new QStandardItemModel(0, 2, this);
	QStringList horizontalHeader;

	horizontalHeader.append("First name");
	horizontalHeader.append("Last name");

	model->setHorizontalHeaderLabels(horizontalHeader);
	
	auto mTeachers = mContext.GetTeachers();

	for (auto i : mTeachers)
	{
		QVariant stored;
		stored.setValue(*i);

		QStandardItem* item = new QStandardItem();
		item->setData(stored);

		model->appendRow(item);
	}

	return model;
}



void TeacherView::on_mAdd_clicked()
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
			ui.mTable->model()->clear();
		//	ui.mTable->insertItems(0, this->GetTeacherList());

		}



	}

}

void TeacherView::on_mEdit_clicked()
{
	TeacherDialog Edit(this);

	QListWidgetItem* item = ui.mTable->currentItem();

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

void TeacherView::on_mDelete_clicked()
{
	QListWidgetItem* item = ui.mTable->currentItem();

	if (item)
	{
		int row = ui.mTable->row(item);
		ui.mTable->takeItem(row);

		string name = item->text().toStdString();
		mContext.RemoveTeacherByFirstName(name);
		delete item;

		if (ui.mTable->count() > 0)
			ui.mTable->setCurrentRow(row);
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


