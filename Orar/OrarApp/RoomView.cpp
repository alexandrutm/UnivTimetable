#include"stdafx.h"
#include "RoomView.h"
#include "Context.h"
#include"INavigator.h"
#include"RoomDialog.h"
#include"RoomTableModel.h"

RoomView::RoomView(INavigator* aNavigator, Context& aContext, QWidget* parent)
	: QWidget(parent), mNavigator(aNavigator), mContext(aContext)
{
	ui.setupUi(this);
	tableModel = new RoomTableModel(mContext, this);

	ui.mTable->setModel(tableModel);

	QHeaderView* header = ui.mTable->horizontalHeader();
	header->setSectionResizeMode(QHeaderView::Stretch);
}

RoomView::~RoomView()
{

}


void RoomView::on_mAdd_clicked()
{
	RoomDialog Add(this);

	if (Add.exec())
	{
		QString aName = Add.Name->text();

		if (!aName.isEmpty())
		{
			tableModel->PopulateModel(aName);
		}
		else
		{
			QMessageBox::about(this, "Name eror", "You need to fill all fields with *");
		}
	}
}
void RoomView::on_mEdit_clicked()
{
	RoomDialog Edit(this);
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

void RoomView::on_mDelete_clicked()
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

void RoomView::on_mConstraints_clicked()
{
}

void RoomView::on_mNext_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::teacherView);
}

void RoomView::on_mBack_clicked()
{
	mNavigator->ChangeView(INavigator::viewId::classesView);
}
