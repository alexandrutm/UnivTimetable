#include"stdafx.h"
#include "ClassesView.h"
#include "INavigator.h"
#include "Context.h"
#include "ClassesDialog.h"
#include "Classes.h"
#include "ClassTableModel.h"




ClassesView::ClassesView(Context & aContext,QWidget *parent)
	: QWidget(parent),mContext(aContext)
{
	ui.setupUi(this);
	tableModel = new ClassTableModel(mContext, this);

	ui.mTable->setModel(tableModel);

	QHeaderView* header = ui.mTable->horizontalHeader();
	header->setSectionResizeMode(QHeaderView::Stretch);
}

ClassesView::~ClassesView()
{
}

void ClassesView::ClearData()
{
	tableModel->ClearData();
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
			tableModel->PopulateModel(name, numberOfStudents);
		}
		else
			QMessageBox::about(this, "Name error", "You need to insert a class name");
	}

}

void ClassesView::on_mEdit_clicked()
{
	ClassesDialog EditDialog(this);
	auto selectedRow = ui.mTable->selectionModel()->currentIndex().row();

	if (selectedRow < 0)
	{
		QMessageBox::about(this, "No Class Selected", "Please choose a class");
	}
	else
		if (EditDialog.exec())
		{
			QString aName = EditDialog.Name->text();
			int aNumberOfStudents = EditDialog.NumberOfStudents->value();

			tableModel->EditModel(selectedRow, aName, aNumberOfStudents);
		}

}

void ClassesView::on_mDelete_clicked()
{
	auto selectedRow = ui.mTable->selectionModel()->currentIndex().row();

	if (selectedRow < 0)
	{
		QMessageBox::about(this, "No Class Selected", "Please choose class you want to delete");
	}
	else
		tableModel->RemoveItemFromModel(selectedRow);
}

void ClassesView::on_mConstraints_clicked()
{

}
