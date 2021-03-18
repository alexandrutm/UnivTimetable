#include "stdafx.h"
#include "ClassesView.h"
#include "ClassesDialog.h"
#include "Context.h"
#include "Group.h"
#include "INavigator.h"
#include "TreeModelClasses.h"

ClassesView::ClassesView(TreeModel * aStudentGroupModel, Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
  , mTreeModel(aStudentGroupModel)
{
  ui.setupUi(this);

  ui.mTreeView->setModel(mTreeModel);
  ui.mTreeView->header()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTreeView->setSortingEnabled(true);
}

ClassesView::~ClassesView()
{
}

void ClassesView::ClearData()
{
  // mStudentGroupModel->ClearData();
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
      const QModelIndex indexParent = ui.mTreeView->selectionModel()->currentIndex();

      auto parentItem = mTreeModel->getItem(indexParent);
      int  row        = static_cast<int>(parentItem->GetChildrenSize());

      // insert a single row before de given row in the child items of the parent index
      if (!mTreeModel->insertRow(row, indexParent))
        return;

      const QModelIndex childIndexName = mTreeModel->index(row, 0, indexParent);
      mTreeModel->setData(childIndexName, name, Qt::EditRole);

      const QModelIndex childIndexNrOfStud = mTreeModel->index(row, 1, indexParent);
      mTreeModel->setData(childIndexNrOfStud, numberOfStudents, Qt::EditRole);
    }
    else
      QMessageBox::about(this, "Name error", "You need to insert a class name");
  }
}

void ClassesView::on_mAddYear_clicked()
{
  ClassesDialog AddDialog(this);

  if (AddDialog.exec())
  {
    QString name             = AddDialog.Name->text();
    int     numberOfStudents = AddDialog.NumberOfStudents->value();

    if (!name.isEmpty())
    {
      const QModelIndex indexParent = ui.mTreeView->rootIndex();

      auto parentItem = mTreeModel->getItem(indexParent);
      int  row        = static_cast<int>(parentItem->GetChildrenSize());

      if (!mTreeModel->insertRow(row, indexParent))
        return;

      const QModelIndex childIndexName = mTreeModel->index(row, 0, indexParent);
      mTreeModel->setData(childIndexName, name, Qt::EditRole);

      const QModelIndex childIndexNrOfStud = mTreeModel->index(row, 1, indexParent);
      mTreeModel->setData(childIndexNrOfStud, numberOfStudents, Qt::EditRole);
    }
    else
      QMessageBox::about(this, "Name error", "You need to insert a class name");
  }
}

void ClassesView::on_mEdit_clicked()
{
  ClassesDialog EditDialog(this);

  QString oldName;
  int     oldNumberOfStudents;

  QString newName;
  int     newNumberOfStudents;

  auto indexRowSelected = ui.mTreeView->selectionModel()->currentIndex();

  if (!indexRowSelected.isValid())
  {
    QMessageBox::about(this, "No Class Selected", "Please choose a class");
    return;
  }

  QModelIndex nameIndex = mTreeModel->index(indexRowSelected.row(), 0, indexRowSelected.parent());
  oldName               = (mTreeModel->data(nameIndex, Qt::DisplayRole)).toString();

  QModelIndex numberOfStudIndex =
    mTreeModel->index(indexRowSelected.row(), 1, indexRowSelected.parent());
  oldNumberOfStudents = (mTreeModel->data(numberOfStudIndex, Qt::DisplayRole)).toInt();

  EditDialog.EditEntry(oldName, oldNumberOfStudents);

  if (EditDialog.exec())
  {
    newName             = EditDialog.Name->text();
    newNumberOfStudents = EditDialog.NumberOfStudents->value();

    if (!newName.isEmpty())
    {
      mTreeModel->setData(nameIndex, newName, Qt::EditRole);

      mTreeModel->setData(numberOfStudIndex, newNumberOfStudents, Qt::EditRole);
    }
  }
}

void ClassesView::on_mDelete_clicked()
{
  auto indexRowSelected = ui.mTreeView->selectionModel()->currentIndex();

  if (!indexRowSelected.isValid())
  {
    QMessageBox::about(this, "No Class Selected", "Please choose a class");
    return;
  }

  mTreeModel->removeRow(indexRowSelected.row(), indexRowSelected.parent());
}

void ClassesView::on_mConstraints_clicked()
{
}
