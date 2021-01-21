#include "stdafx.h"
#include "TeacherView.h"
#include "INavigator.h"
#include "Context.h"
#include "TeacherDialog.h"
#include "Teacher.h"
#include "TeacherTableModel.h"

TeacherView::TeacherView(INavigator* aNavigator, Context& aContext, QWidget* parent)
	: QWidget(parent), mNavigator(aNavigator), mContext(aContext)
{
	ui.setupUi(this);
	tableModel = new TableModel(mContext, this);

	ui.mTable->setModel(tableModel);

	QHeaderView* header = ui.mTable->horizontalHeader();
	header->setSectionResizeMode(QHeaderView::Stretch);

}

TeacherView::~TeacherView()
{
}

void TeacherView::ClearData()
{
	tableModel->ClearContent();
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
			tableModel->PopulateModel(firstName, lastName);
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
	auto selectedRow = ui.mTable->selectionModel()->currentIndex().row();

	if (selectedRow<0)
	{
		QMessageBox::about(this, "No item selected", "Please choose an item to edit");
	}
	else
		if (Edit.exec())
		{
			QString firstName = Edit.mFirstName->text();
			QString lastName = Edit.mLastName->text();

			tableModel->EditModel(selectedRow, firstName, lastName);

		}
}

void TeacherView::on_mDelete_clicked()
{
	auto selectedRow = ui.mTable->selectionModel()->currentIndex().row();

	if (selectedRow<0)
	{
		QMessageBox::about(this, "No item selected", "Please choose an item to delete");
	}
	else
	{
		tableModel->RemoveItemFromModel(selectedRow);
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


