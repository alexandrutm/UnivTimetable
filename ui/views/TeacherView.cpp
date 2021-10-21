#include "stdafx.h"
#include "TeacherView.h"
#include "../model/SortFilterProxyModel.h"
#include "../model/TeacherTableModel.h"
#include "../src/containers/Context.h"
#include "../src/containers/Teacher.h"
#include "../ui/dialogs/TeacherDialog.h"

TeacherView::TeacherView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);

  mTeacherTableModel = make_shared<TeacherTableModel>(mContext, this);
  mContext.RegisterObserver(mTeacherTableModel);

  mTeacherProxyModel = make_unique<SortFilterProxyModel>();

  mTeacherProxyModel->setSourceModel(mTeacherTableModel.get());
  mTeacherProxyModel->sort(0, Qt::AscendingOrder);

  ui.mTable->setModel(mTeacherProxyModel.get());
  ui.mTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTable->setSortingEnabled(true);
}

TeacherView::~TeacherView()
{
  mContext.RemoveObserver(mTeacherTableModel);
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
    int     id        = mContext.GenerateTeacherId();

    if (!firstName.isEmpty())
    {
      mTeacherTableModel->PopulateModel(firstName.toStdString(), lastName.toStdString(), id);
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

  firstOldName =
    QString::fromStdString(mContext.GetTeacherByIndex(currentSelectedRowMapped)->GetFirstName());

  lastOldName =
    QString::fromStdString(mContext.GetTeacherByIndex(currentSelectedRowMapped)->GetLastName());

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
    auto result = mContext.SearchTeacher(mContext.GetTeacherByIndex(currentSelectedRowMapped));

    if (!result.empty())
    {
      result.append("\nPlease remove all objects that hold this teacher");
      QMessageBox::about(this, "About", QString::fromStdString(result));
    }
    else
    {
      mTeacherTableModel->removeRows(currentSelectedRowMapped, currentSelectedRowMapped,
                                     QModelIndex());
    }
  }
}
