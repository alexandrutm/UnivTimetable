#include "ClassesView.h"
#include "INavigator.h"
#include "Context.h"
#include "ClassesDialog.h"
#include "Classes.h"


ClassesView::ClassesView(INavigator* aNavigator,Context & aContext,QWidget *parent)
	: QWidget(parent),mContext(aContext),mNavigator(aNavigator)
{
	ui.setupUi(this);
}

ClassesView::~ClassesView()
{
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
			Classes newClass;
			newClass.SetName(name.toStdString());
			newClass.SetNumberOfStudents(numberOfStudents);
			mContext.AddClass(newClass);

			mNavigator->ChangeStatus("You have successfully added a new class");
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

void ClassesView::on_Next_clicked()
{
}

void ClassesView::on_Back_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::subjectView);
}
