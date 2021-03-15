#include "stdafx.h"
#include "TeacherView.h"
#include "Context.h"
#include "InstituteData.h"
#include "SortFilterProxyModel.h"
#include "Teacher.h"
#include "TeacherConstraintDialog.h"
#include "TeacherDialog.h"
#include "TeacherTableModel.h"
#include "TimeConstraint.h"

TeacherView::TeacherView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);

  mTeacherTableModel = new TeacherTableModel(mContext, this);
  mTeacherProxyModel = new SortFilterProxyModel();

  mTeacherProxyModel->setSourceModel(mTeacherTableModel);
  mTeacherProxyModel->sort(0, Qt::AscendingOrder);

  ui.mTable->setModel(mTeacherProxyModel);
  ui.mTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTable->setSortingEnabled(true);
}

TeacherView::~TeacherView()
{
  delete mTeacherProxyModel;
  delete mTeacherTableModel;
}

void TeacherView::ClearData()
{
  mTeacherTableModel->ClearContent();
}

void TeacherView::on_mAdd_clicked()
{
  TeacherDialog Dialog(this);

  if (Dialog.exec())
  {
    QString firstName = Dialog.mFirstName->text();
    QString lastName  = Dialog.mLastName->text();
    if (!firstName.isEmpty())
    {
      int newRow = static_cast<int>(mContext.GetTeacherSize());
      mTeacherTableModel->insertRows(newRow, newRow, QModelIndex());

      QModelIndex index = mTeacherTableModel->index(newRow, 0, QModelIndex());
      mTeacherTableModel->setData(index, firstName, Qt::EditRole);
      index = mTeacherTableModel->index(newRow, 1, QModelIndex());
      mTeacherTableModel->setData(index, lastName, Qt::EditRole);
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
  QString       firstOldName;
  QString       lastOldName;
  // map the current selected row value
  int currentSelectedRowMapped =
    mTeacherProxyModel->mapToSource(ui.mTable->selectionModel()->currentIndex()).row();

  Dialog.setWindowTitle(tr("Edit Teacher"));

  QModelIndex nameIndex = mTeacherTableModel->index(currentSelectedRowMapped, 0, QModelIndex());
  firstOldName          = (mTeacherTableModel->data(nameIndex, Qt::DisplayRole)).toString();

  QModelIndex addressIndex = mTeacherTableModel->index(currentSelectedRowMapped, 1, QModelIndex());
  lastOldName              = (mTeacherTableModel->data(addressIndex, Qt::DisplayRole)).toString();

  Dialog.EditEntry(firstOldName, lastOldName);

  if (currentSelectedRowMapped < 0)
  {
    QMessageBox::about(this, "No item selected", "Please choose an item to edit");
  }
  else if (Dialog.exec())
  {
    // new teacher name
    QString firstName = Dialog.mFirstName->text();
    QString lastName  = Dialog.mLastName->text();

    if (!(firstName.isEmpty()) && !(lastName.isEmpty()))
    {
      index = mTeacherTableModel->index(currentSelectedRowMapped, 0, QModelIndex());
      mTeacherTableModel->setData(index, firstName, Qt::EditRole);

      index = mTeacherTableModel->index(currentSelectedRowMapped, 1, QModelIndex());
      mTeacherTableModel->setData(index, lastName, Qt::EditRole);
    }
  }
}

void TeacherView::on_mDelete_clicked()
{
  int currentSelectedRowMapped =
    mTeacherProxyModel->mapToSource(ui.mTable->selectionModel()->currentIndex()).row();

  if (currentSelectedRowMapped < 0)
  {
    QMessageBox::about(this, "No item selected", "Please choose an item to delete");
  }
  else
  {
    // if (mContext.GetTeacherByIndex(currentSelectedRowMapped).use_count() > 1)
    //{
    //  QMessageBox::about(this, "About", "Please remove all lesson that hold this teacher first");
    //}
    // else
    //{
    mTeacherTableModel->removeRows(currentSelectedRowMapped, currentSelectedRowMapped,
                                   QModelIndex());
    //}
  }
}
