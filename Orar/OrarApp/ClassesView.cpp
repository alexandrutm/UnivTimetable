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
	ui.List->clear();
}

void ClassesView::on_Add_clicked()
{
	ClassesDialog AddDialog(this);

	if (AddDialog.exec())
	{
		QString name = AddDialog.Name->text();
		int numberOfStudents = AddDialog.NumberOfStudents->value();

		if (!name.isEmpty())
		{
			QListWidgetItem* item = new QListWidgetItem(name, ui.List);
			item->setData(Qt::UserRole, numberOfStudents);
			ui.List->setCurrentItem(item);

			//store data
			shared_ptr<Classes> newClass = make_shared<Classes>(name.toStdString(),numberOfStudents);
			mContext.AddClass(newClass);
		}
	}

}

void ClassesView::on_Edit_clicked()
{
	ClassesDialog EditDialog(this);
	QListWidgetItem* item = ui.List->currentItem();

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

void ClassesView::on_Delete_clicked()
{
	QListWidgetItem* item = ui.List->currentItem();

	if (item)
	{
		int row = ui.List->row(item);
		ui.List->takeItem(row);

		string name = item->text().toStdString();

		mContext.RemoveClassByName(name);
		delete item;

		if (ui.List->count() > 0)
			ui.List->setCurrentRow(row);
	}
}

void ClassesView::on_Constraints_clicked()
{

}
