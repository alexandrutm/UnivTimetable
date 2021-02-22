#include "stdafx.h"
#include "ClassesView.h"
#include "Classes.h"
#include "ClassesDialog.h"
#include "Context.h"
#include "INavigator.h"
#include "SortFilterProxyModel.h"
#include "TreeModel.h"

ClassesView::ClassesView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);
  treeModel = new TreeModel(mContext, this);

  ui.mTree->setModel(treeModel);
}

ClassesView::~ClassesView()
{
}

void ClassesView::ClearData()
{
  // treeModel->ClearData();
}

void ClassesView::on_mAddClass_clicked()
{
  ClassesDialog AddDialog(this);

  if (AddDialog.exec())
  {
    QString name             = AddDialog.Name->text();
    int     numberOfStudents = AddDialog.NumberOfStudents->value();

    if (!name.isEmpty())
    {
      const QModelIndex index = ui.mTree->selectionModel()->currentIndex();

      treeModel->PopulateModel(name, numberOfStudents, index);
    }
    else
      QMessageBox::about(this, "Name error", "You need to insert a class name");
  }
}

void ClassesView::on_mEdit_clicked()
{
  ClassesDialog EditDialog(this);
  QModelIndex   index;

  int currentSelectedRow = ui.mTree->selectionModel()->currentIndex().row();

  if (currentSelectedRow < 0)
  {
    QMessageBox::about(this, "No Class Selected", "Please choose a class");
  }
  else if (EditDialog.exec())
  {
    QString oldName;
    int     oldNumberOfStudents;
    QString newName;
    int     newNumberOfStudents;

    QModelIndex nameIndex = treeModel->index(currentSelectedRow, 0, QModelIndex());
    oldName               = (treeModel->data(nameIndex, Qt::DisplayRole)).toString();

    QModelIndex addressIndex = treeModel->index(currentSelectedRow, 1, QModelIndex());
    oldNumberOfStudents      = (treeModel->data(addressIndex, Qt::DisplayRole)).toInt();

    newName             = EditDialog.Name->text();
    newNumberOfStudents = EditDialog.NumberOfStudents->value();

    if (!newName.isEmpty())
    {
      index = treeModel->index(currentSelectedRow, 0, QModelIndex());
      treeModel->setData(index, newName, Qt::EditRole);

      index = treeModel->index(currentSelectedRow, 1, QModelIndex());
      treeModel->setData(index, newNumberOfStudents, Qt::EditRole);
    }
  }
}

void ClassesView::on_mDelete_clicked()
{
  int currentSelectedRowMapped = ui.mTree->selectionModel()->currentIndex().row();

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
    }
  }
}

void ClassesView::on_mConstraints_clicked()
{
}
