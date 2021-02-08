#include "stdafx.h"
#include "RoomView.h"
#include "Context.h"
#include "RoomDialog.h"
#include "RoomTableModel.h"
#include "SortFilterProxyModel.h"

RoomView::RoomView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);
  tableModel = new RoomTableModel(mContext, this);

  proxyModel = new SortFilterProxyModel();

  proxyModel->setSourceModel(tableModel);
  proxyModel->sort(0, Qt::AscendingOrder);
  ui.mTable->setModel(proxyModel);
  ui.mTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTable->setSortingEnabled(true);
}

RoomView::~RoomView()
{
}

void RoomView::ClearData()
{
  tableModel->ClearData();
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
  RoomDialog  Edit(this);
  QModelIndex index;

  // map the current selected row value
  int currentSelectedRowMapped =
    proxyModel->mapToSource(ui.mTable->selectionModel()->currentIndex()).row();

  if (currentSelectedRowMapped < 0)
  {
    QMessageBox::about(this, "No item selected", "Please choose an item to edit");
  }
  else if (Edit.exec())
  {
    QString oldName;

    QModelIndex nameIndex = tableModel->index(currentSelectedRowMapped, 0, QModelIndex());
    oldName               = (tableModel->data(nameIndex, Qt::DisplayRole)).toString();

    QString newName = Edit.Name->text();

    if (newName != oldName)
    {
      index = tableModel->index(currentSelectedRowMapped, 0, QModelIndex());
      tableModel->setData(index, newName, Qt::EditRole);
    }
  }
}

void RoomView::on_mDelete_clicked()
{
  int currentSelectedRowMapped =
    proxyModel->mapToSource(ui.mTable->selectionModel()->currentIndex()).row();

  if (currentSelectedRowMapped < 0)
  {
    QMessageBox::about(this, "No item selected", "Please choose an item to delete");
  }
  else
  {
    tableModel->RemoveItemFromModel(currentSelectedRowMapped);
  }
}

void RoomView::on_mConstraints_clicked()
{
}
