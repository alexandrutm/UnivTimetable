#include "stdafx.h"
#include "RoomView.h"
#include "src/containers/Context.h"
#include "ui/dialogs/RoomDialog.h"
#include "ui/model/RoomTableModel.h"
#include "ui/model/SortFilterProxyModel.h"

RoomView::RoomView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);
  tableModel = make_shared<RoomTableModel>(mContext, this);

  proxyModel = make_unique<SortFilterProxyModel>();

  proxyModel->setSourceModel(tableModel.get());
  proxyModel->sort(0, Qt::AscendingOrder);

  ui.mTable->setModel(proxyModel.get());
  ui.mTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTable->setSortingEnabled(true);

  mContext.RegisterObserver(tableModel);
}

RoomView::~RoomView()
{
  mContext.RemoveObserver(tableModel);
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
    int     id       = mContext.GenerateRoomId();
    QString aName    = Add.mName->text();
    int     capacity = Add.mCapacity->value();

    if (!aName.isEmpty())
    {
      tableModel->PopulateModel(aName, capacity, id);
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
    int     oldCapacity;

    QModelIndex nameIndex = tableModel->index(currentSelectedRowMapped, 0, QModelIndex());
    oldName               = (tableModel->data(nameIndex, Qt::DisplayRole)).toString();

    QModelIndex capacityIndex = tableModel->index(currentSelectedRowMapped, 1, QModelIndex());
    oldCapacity               = (tableModel->data(capacityIndex, Qt::DisplayRole)).toInt();

    QString newName     = Edit.mName->text();
    int     newCapacity = Edit.mCapacity->value();

    if (newName != oldName || newCapacity != oldCapacity)
    {
      index = tableModel->index(currentSelectedRowMapped, 0, QModelIndex());
      tableModel->setData(index, newName, Qt::EditRole);

      index = tableModel->index(currentSelectedRowMapped, 1, QModelIndex());
      tableModel->setData(index, newCapacity, Qt::EditRole);
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
