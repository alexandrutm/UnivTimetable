#include"stdafx.h"
#include "SubjectView.h"
#include "Context.h"
#include "SubjectDialog.h"
#include "Subject.h"
#include "SubjectTableModel.h"

SubjectView::SubjectView(Context& aContext,QWidget *parent)
	: QWidget(parent),mContext(aContext)
{
	ui.setupUi(this);
	tableModel = new SubjectTableModel(mContext, this);

	ui.mTable->setModel(tableModel);

	QHeaderView* header = ui.mTable->horizontalHeader();
	header->setSectionResizeMode(QHeaderView::Stretch);
}

SubjectView::~SubjectView()
{
}

void SubjectView::ClearData()
{
	tableModel->ClearContent();
}

void SubjectView::on_mAdd_clicked()
{
	SubjectDialog AddSubject(this);

	if (AddSubject.exec())
	{
		QString subjectName = AddSubject.Name->text();

		if (!subjectName.isEmpty())
		{
			tableModel->PopulateModel(subjectName);
		}
		else
			QMessageBox::about(this, "Name eror", "You need to fill all fields with *");

	}

}

void SubjectView::on_mEdit_clicked()
{
	SubjectDialog Edit(this);
	auto selectedRow = ui.mTable->selectionModel()->currentIndex().row();

	if (selectedRow < 0)
	{
		QMessageBox::about(this, "No item selected", "Please choose an item to edit");
	}
	else
		if (Edit.exec())
		{
			QString aName = Edit.Name->text();

			tableModel->EditModel(selectedRow, aName);

		}
}

void SubjectView::on_mDelete_clicked()
{
	auto selectedRow = ui.mTable->selectionModel()->currentIndex().row();

	if (selectedRow < 0)
	{
		QMessageBox::about(this, "No item selected", "Please choose an item to delete");
	}
	else
	{
		tableModel->RemoveItemFromModel(selectedRow);
	}
}

void SubjectView::on_mConstraints_clicked()
{
}

