#include "stdafx.h"
#include "ClassesView.h"
#include "ClassTableModel.h"
#include "ClassesDialog.h"
#include "Context.h"
#include "INavigator.h"
#include "SortFilterProxyModel.h"

ClassesView::ClassesView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);
  mStudentGroupModel = new ClassTableModel(mContext, this);
  mProxyModel        = new SortFilterProxyModel();

  mProxyModel->setSourceModel(mStudentGroupModel);
  mProxyModel->sort(0, Qt::AscendingOrder);
  ui.mGroupTable->setModel(mProxyModel);
  ui.mGroupTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mGroupTable->setSortingEnabled(true);
}

ClassesView::~ClassesView()
{
}

void ClassesView::ClearData()
{
  mStudentGroupModel->ClearData();
}

void ClassesView::on_mAddGroup_clicked()
{
  ClassesDialog AddDialog(this);

  if (AddDialog.exec())
  {
    QString name             = AddDialog.Name->text();
    int     numberOfStudents = AddDialog.NumberOfStudents->value();

    if (!name.isEmpty())
    {
      mStudentGroupModel->PopulateModel(name, numberOfStudents);
    }
    else
      QMessageBox::about(this, "Name error", "You need to insert a class name");
  }
}

void ClassesView::on_mEdit_clicked()
{
  ClassesDialog EditDialog(this);
  QModelIndex   index;
  QString       newName;
  int           newNumberOfStudents;

  // map the current selected row value
  int currentSelectedRowMapped =
    mProxyModel->mapToSource(ui.mGroupTable->selectionModel()->currentIndex()).row();

  if (currentSelectedRowMapped < 0)
  {
    QMessageBox::about(this, "No Class Selected", "Please choose a class");
  }
  else if (EditDialog.exec())
  {
    // QString oldName;
    // int     oldNumberOfStudents;

    // QModelIndex nameIndex = tableModel->index(currentSelectedRowMapped, 0, QModelIndex());
    // oldName               = (tableModel->data(nameIndex, Qt::DisplayRole)).toString();

    // QModelIndex addressIndex = tableModel->index(currentSelectedRowMapped, 1, QModelIndex());
    // oldNumberOfStudents      = (tableModel->data(addressIndex, Qt::DisplayRole)).toInt();

    newName             = EditDialog.Name->text();
    newNumberOfStudents = EditDialog.NumberOfStudents->value();

    if (!newName.isEmpty())
    {
      index = mStudentGroupModel->index(currentSelectedRowMapped, 0, QModelIndex());
      mStudentGroupModel->setData(index, newName, Qt::EditRole);
      index = mStudentGroupModel->index(currentSelectedRowMapped, 1, QModelIndex());
      mStudentGroupModel->setData(index, newNumberOfStudents, Qt::EditRole);
    }
  }
}

void ClassesView::on_mDelete_clicked()
{
  int currentSelectedRowMapped =
    mProxyModel->mapToSource(ui.mGroupTable->selectionModel()->currentIndex()).row();

  if (currentSelectedRowMapped < 0)
  {
    QMessageBox::about(this, "No Class Selected", "Please choose class you want to delete");
  }
  else
  {
    if (mContext.GetGroupByIndex(currentSelectedRowMapped).use_count() > 1)
    {
      QMessageBox::about(this, "About", "Please remove all lesson that hold this class first");
    }
    else
    {
      mStudentGroupModel->RemoveItemFromModel(currentSelectedRowMapped);
    }
  }
}

void ClassesView::on_mConstraints_clicked()
{
}
