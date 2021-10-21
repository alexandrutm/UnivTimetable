#include "stdafx.h"
#include "ExportTimetableDialog.h"
#include "src/containers/Context.h"
#include "src/xml/ExportTimeTable.h"
#include "ui/model/TreeModelClasses.h"

ExportTimetableDialog::ExportTimetableDialog(Context &             aContext,
                                             shared_ptr<TreeModel> aGroupModel,
                                             QWidget *             parent)
  : mContext(aContext)
  , mGroupModel(aGroupModel)
  , QDialog(parent)
{
  ui.setupUi(this);
  ui.treeView->setModel(mGroupModel.get());
}

ExportTimetableDialog::~ExportTimetableDialog()
{
}

void ExportTimetableDialog::on_mPrint_clicked()
{
  ExportTimetable exportTimetable(mContext);

  auto indexRowSelected = ui.treeView->selectionModel()->currentIndex();

  if (!indexRowSelected.isValid())
  {
    QMessageBox::about(this, "No Class Selected", "Please choose a class");
    return;
  }

  QModelIndex nameIndex =
    ui.treeView->model()->index(indexRowSelected.row(), 0, indexRowSelected.parent());

  auto parentGroup = mGroupModel->getItem(nameIndex);

  exportTimetable.PrintTimetable(mContext.GetGroupsNameToFilter(parentGroup));
}
