#include "stdafx.h"
#include "SubjectView.h"
#include "Context.h"
#include "SortFilterProxyModel.h"
#include "Subject.h"
#include "SubjectDialog.h"
#include "SubjectTableModel.h"

SubjectView::SubjectView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);

  tableModel = new SubjectTableModel(mContext, this);
  proxyModel = new SortFilterProxyModel();

  ui.mTable->setModel(tableModel);

  proxyModel->setSourceModel(tableModel);
  proxyModel->sort(0, Qt::AscendingOrder);
  ui.mTable->setModel(proxyModel);
  ui.mTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTable->setSortingEnabled(true);
}

SubjectView::~SubjectView()
{
  delete tableModel;
  delete proxyModel;
}

void SubjectView::ClearData()
{
  tableModel->ClearContent();
}

void SubjectView::on_mAdd_clicked()
{
  SubjectDialog AddSubject(this);

  if (AddSubject.exec())
  {
    QString subjectName = AddSubject.Name->text();

    if (!subjectName.isEmpty())
    {
      tableModel->PopulateModel(subjectName);
    }
    else
      QMessageBox::about(this, "Name eror", "You need to fill all fields with *");
  }
}

void SubjectView::on_mEdit_clicked()
{
  SubjectDialog Edit(this);
  QModelIndex   index;

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
    QVariant    varName   = tableModel->data(nameIndex, Qt::DisplayRole);
    oldName               = varName.toString();

    QString newName = Edit.Name->text();

    if (newName != oldName)
    {
      index = tableModel->index(currentSelectedRowMapped, 0, QModelIndex());
      tableModel->setData(index, newName, Qt::EditRole);
    }
  }
}

void SubjectView::on_mDelete_clicked()
{
  // map selected row in the view with the one stored in context using proxy model
  int selectedRowMapped =
    proxyModel->mapToSource(ui.mTable->selectionModel()->currentIndex()).row();

  if (selectedRowMapped < 0)
  {
    QMessageBox::about(this, "No item selected", "Please choose an item to delete");
  }
  else
  {
    auto result = mContext.SearchSubject(mContext.GetSubjectByIndex(selectedRowMapped));
    if (!result.empty())
    {
      result.append("\nPlease remove all objects that hold this Subject");
      QMessageBox::about(this, "About", QString::fromStdString(result));
    }
    else
      tableModel->RemoveItemFromModel(selectedRowMapped);
  }
}

void SubjectView::on_mConstraints_clicked()
{
}
