#include "stdafx.h"
#include "ClassesView.h"
#include "ClassTableModel.h"
#include "ClassesDialog.h"
#include "Context.h"
#include "INavigator.h"
#include "SortFilterProxyModel.h"
#include "Students.h"

//
#include "StudentGroupModel.h"

ClassesView::ClassesView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);
  mStudentYearModel = new ClassTableModel(mContext, this);
  mProxyModel       = new SortFilterProxyModel();

  mStudentGroupModel = new StudentGroupModel(mContext, this);

  mProxyModel->setSourceModel(mStudentYearModel);
  mProxyModel->sort(0, Qt::AscendingOrder);
  ui.mYearTable->setModel(mProxyModel);
  ui.mYearTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mYearTable->setSortingEnabled(true);

  ui.mGroupTable->setModel(mStudentGroupModel);
}

ClassesView::~ClassesView()
{
}

void ClassesView::ClearData()
{
  mStudentYearModel->ClearData();
}

void ClassesView::on_mAdd_clicked()
{
  ClassesDialog AddDialog(this);

  if (AddDialog.exec())
  {
    QString name             = AddDialog.Name->text();
    int     numberOfStudents = AddDialog.NumberOfStudents->value();

    if (!name.isEmpty())
    {
      mStudentYearModel->PopulateModel(name, numberOfStudents);
    }
    else
      QMessageBox::about(this, "Name error", "You need to insert a class name");
  }
}

void ClassesView::on_mAddGroup_clicked()
{
  ClassesDialog AddDialog(this);
  QString       name;
  int           numberOfStudents;

  int currentSelectedRowMapped =
    mProxyModel->mapToSource(ui.mYearTable->selectionModel()->currentIndex()).row();
  if (currentSelectedRowMapped < 0)
  {
    QMessageBox::about(this, "No Class Selected", "Please choose a Year");
  }
  else if (AddDialog.exec())
  {
    name             = AddDialog.Name->text();
    numberOfStudents = AddDialog.NumberOfStudents->value();

    if (!name.isEmpty())
    {
      mStudentGroupModel->PopulateModel(name, numberOfStudents, currentSelectedRowMapped);
    }
  }
}

void ClassesView::on_mAddSubgroup_clicked()
{
}

void ClassesView::on_mEdit_clicked()
{
  ClassesDialog EditDialog(this);
  QModelIndex   index;
  QString       newName;
  int           newNumberOfStudents;

  // map the current selected row value
  int currentSelectedRowMapped =
    mProxyModel->mapToSource(ui.mYearTable->selectionModel()->currentIndex()).row();

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
      index = mStudentYearModel->index(currentSelectedRowMapped, 0, QModelIndex());
      mStudentYearModel->setData(index, newName, Qt::EditRole);
      index = mStudentYearModel->index(currentSelectedRowMapped, 1, QModelIndex());
      mStudentYearModel->setData(index, newNumberOfStudents, Qt::EditRole);
    }
  }
}

void ClassesView::on_mDelete_clicked()
{
  int currentSelectedRowMapped =
    mProxyModel->mapToSource(ui.mYearTable->selectionModel()->currentIndex()).row();

  if (currentSelectedRowMapped < 0)
  {
    QMessageBox::about(this, "No Class Selected", "Please choose class you want to delete");
  }
  else
  {
    if (mContext.GetClassByIndex(currentSelectedRowMapped).use_count() > 1)
    {
      QMessageBox::about(this, "About", "Please remove all lesson that hold this class first");
    }
    else
    {
      mStudentYearModel->RemoveItemFromModel(currentSelectedRowMapped);
    }
  }
}

void ClassesView::on_mConstraints_clicked()
{
}
