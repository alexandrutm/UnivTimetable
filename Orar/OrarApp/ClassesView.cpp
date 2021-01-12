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

void ClassesView::on_mAdd_clicked()
{
	ClassesDialog AddDialog(this);

	if (AddDialog.exec())
	{
		QString name = AddDialog.Name->text();
		int numberOfStudents = AddDialog.NumberOfStudents->value();

		if (!name.isEmpty())
		{
			QListWidgetItem* item = new QListWidgetItem(name, ui.mList);
			item->setData(Qt::UserRole, numberOfStudents);
			ui.mList->setCurrentItem(item);

			//store data
			shared_ptr<Classes> newClass = make_shared<Classes>(name.toStdString(),numberOfStudents);
			mContext.AddClass(newClass);
		}
	}

}

void ClassesView::on_mEdit_clicked()
{
	ClassesDialog EditDialog(this);
	QListWidgetItem* item = ui.mList->currentItem();

	if (item)
	{
		EditDialog.Name->setText(item->text());
		EditDialog.Abbreviation->setText(item->text().left(2));
		EditDialog.NumberOfStudents->setValue(item->data(Qt::UserRole).toInt());

		if (EditDialog.exec()) {
			
			QString name = EditDialog.Name->text();
			int numberOfStudents = EditDialog.NumberOfStudents->value();

			mContext.EditClassesByName(item->text().toStdString(), name.toStdString(), numberOfStudents);

			item->setText(name);
			item->setData(Qt::UserRole, numberOfStudents);
		}
	}


}

void ClassesView::on_mDelete_clicked()
{
	QListWidgetItem* item = ui.mList->currentItem();

	if (item)
	{
		int row = ui.mList->row(item);
		ui.mList->takeItem(row);

		string name = item->text().toStdString();

		mContext.RemoveClassByName(name);
		delete item;

		if (ui.mList->count() > 0)
			ui.mList->setCurrentRow(row);
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
