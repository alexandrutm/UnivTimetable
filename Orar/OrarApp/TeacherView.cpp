#include "stdafx.h"
#include "TeacherView.h"
#include "Context.h"
#include "SortFilterProxyModel.h"
#include "Teacher.h"
#include "TeacherDialog.h"
#include "TeacherTableModel.h"

TeacherView::TeacherView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);

  tableModel = new TableModel(mContext, this);
  proxyModel = new SortFilterProxyModel();

  proxyModel->setSourceModel(tableModel);
  proxyModel->sort(0, Qt::AscendingOrder);
  ui.mTable->setModel(proxyModel);
  ui.mTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTable->setSortingEnabled(true);
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
    QString lastName  = Add.mLastName->text();
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
  TeacherDialog Dialog(this);
  QModelIndex   index;

  // map the current selected row value
  int currentSelectedRowMapped =
    proxyModel->mapToSource(ui.mTable->selectionModel()->currentIndex()).row();

  if (currentSelectedRowMapped < 0)
  {
    QMessageBox::about(this, "No item selected", "Please choose an item to edit");
  }
  else if (Dialog.exec())
  {
    QString firstOldName;
    QString lastOldName;

    QModelIndex nameIndex = tableModel->index(currentSelectedRowMapped, 0, QModelIndex());
    firstOldName          = (tableModel->data(nameIndex, Qt::DisplayRole)).toString();

    QModelIndex addressIndex = tableModel->index(currentSelectedRowMapped, 1, QModelIndex());
    lastOldName              = (tableModel->data(addressIndex, Qt::DisplayRole)).toString();

    // new teacher name
    QString firstName = Dialog.mFirstName->text();
    QString lastName  = Dialog.mLastName->text();

    if (!(firstName.isEmpty()) && !(lastName.isEmpty()))
    {
      index = tableModel->index(currentSelectedRowMapped, 0, QModelIndex());
      tableModel->setData(index, firstName, Qt::EditRole);

      index = tableModel->index(currentSelectedRowMapped, 1, QModelIndex());
      tableModel->setData(index, lastName, Qt::EditRole);
    }
  }
}

void TeacherView::on_mDelete_clicked()
{
  int currentSelectedRowMapped =
    proxyModel->mapToSource(ui.mTable->selectionModel()->currentIndex()).row();

  if (currentSelectedRowMapped < 0)
  {
    QMessageBox::about(this, "No item selected", "Please choose an item to delete");
  }
  else
  {
    if (mContext.GetTeacherByIndex(currentSelectedRowMapped).use_count() > 1)
    {
      QMessageBox::about(this, "About", "Please remove all lesson that hold this teacher first");
    }
    else
    {
      tableModel->RemoveItemFromModel(currentSelectedRowMapped);
    }
  }
}

void TeacherView::on_mConstraints_clicked()
{
}
