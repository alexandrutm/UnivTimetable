#include"stdafx.h"
#include "ClassesView.h"
#include "INavigator.h"
#include "Context.h"
#include "ClassesDialog.h"
#include"Classes.h"



ClassesView::ClassesView(INavigator* aNavigator,Context & aContext,QWidget *parent)
	: QWidget(parent),mContext(aContext),mNavigator(aNavigator)
{
	ui.setupUi(this);
}

ClassesView::~ClassesView()
{
}

void ClassesView::ClearData()
{
	ui.mList->clear();
}

void ClassesView::UpdateList()
{
	this->ClearData();

	auto mClasses = mContext.GetClasses();

	for (auto i : mClasses)
	{
		QVariant classes;
		classes.setValue(i);

		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString((*i).GetName()), ui.mList);
		item->setData(Qt::UserRole, classes);
		ui.mList->setCurrentItem(item);
	}
}

void ClassesView::on_mAdd_clicked()
{
	ClassesDialog AddDialog(this);

	if (AddDialog.exec())
	{
		QString name = AddDialog.Name->text();
		int numberOfStudents = AddDialog.NumberOfStudents->value();

		if (!name.isEmpty())
		{
			shared_ptr<Classes> newClass = make_shared<Classes>(name.toStdString(), numberOfStudents);
			mContext.AddClass(newClass);

			this->UpdateList();
		}
		else
			QMessageBox::about(this, "Name error", "You need to insert a class name");
	}

}

void ClassesView::on_mEdit_clicked()
{
	ClassesDialog EditDialog(this);
	QListWidgetItem* item = ui.mList->currentItem();

	if (item)
	{
		if (EditDialog.exec()) {
			
			QString name = EditDialog.Name->text();
			int numberOfStudents = EditDialog.NumberOfStudents->value();

			shared_ptr<Classes> oldClass=qvariant_cast<shared_ptr<Classes>>(item->data(Qt::UserRole));

			mContext.EditClasses(oldClass,make_shared<Classes>(name.toStdString(),numberOfStudents));

			this->UpdateList();
		}
	}

}

void ClassesView::on_mDelete_clicked()
{
	QListWidgetItem* item = ui.mList->currentItem();

	if (item)
	{
		mContext.RemoveClass(qvariant_cast<shared_ptr<Classes>>(item->data(Qt::UserRole)));
		delete item;

		this->UpdateList();
	}
}

void ClassesView::on_mConstraints_clicked()
{

}

void ClassesView::on_mNext_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::roomView);
}

void ClassesView::on_mBack_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::subjectView);
}
