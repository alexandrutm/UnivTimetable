#include "stdafx.h"
#include "ClassesView.h"
#include "ClassTableModel.h"
#include "Classes.h"
#include "ClassesDialog.h"
#include "Context.h"
#include "INavigator.h"
#include "SortFilterProxyModel.h"

ClassesView::ClassesView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);
  tableModel = new ClassTableModel(mContext, this);
  proxyModel = new SortFilterProxyModel();

  proxyModel->setSourceModel(tableModel);
  proxyModel->sort(0, Qt::AscendingOrder);
  ui.mTree->setModel(proxyModel);
  // ui.mTree->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTree->setSortingEnabled(true);
}

ClassesView::~ClassesView()
{
}

void ClassesView::ClearData()
{
  tableModel->ClearData();
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
      tableModel->PopulateModel(name, numberOfStudents);
    }
    else
      QMessageBox::about(this, "Name error", "You need to insert a class name");
  }
}

void ClassesView::on_mEdit_clicked()
{
  ClassesDialog EditDialog(this);
  QModelIndex   index;

  // map the current selected row value
  int currentSelectedRowMapped =
    proxyModel->mapToSource(ui.mTree->selectionModel()->currentIndex()).row();

  if (currentSelectedRowMapped < 0)
  {
    QMessageBox::about(this, "No Class Selected", "Please choose a class");
  }
  else if (EditDialog.exec())
  {
    QString oldName;
    int     oldNumberOfStudents;
    QString newName;
    int     newNumberOfStudents;

    QModelIndex nameIndex = tableModel->index(currentSelectedRowMapped, 0, QModelIndex());
    oldName               = (tableModel->data(nameIndex, Qt::DisplayRole)).toString();

    QModelIndex addressIndex = tableModel->index(currentSelectedRowMapped, 1, QModelIndex());
    oldNumberOfStudents      = (tableModel->data(addressIndex, Qt::DisplayRole)).toInt();

    newName             = EditDialog.Name->text();
    newNumberOfStudents = EditDialog.NumberOfStudents->value();

    if (!newName.isEmpty())
    {
      index = tableModel->index(currentSelectedRowMapped, 0, QModelIndex());
      tableModel->setData(index, newName, Qt::EditRole);
      index = tableModel->index(currentSelectedRowMapped, 1, QModelIndex());
      tableModel->setData(index, newNumberOfStudents, Qt::EditRole);
    }
  }
}

void ClassesView::on_mDelete_clicked()
{
  int currentSelectedRowMapped =
    proxyModel->mapToSource(ui.mTree->selectionModel()->currentIndex()).row();

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
      tableModel->RemoveItemFromModel(currentSelectedRowMapped);
    }
  }
}

void ClassesView::on_mConstraints_clicked()
{
}
