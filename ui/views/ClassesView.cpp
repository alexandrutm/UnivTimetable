#include "stdafx.h"
#include "ClassesView.h"
#include "src/containers/Context.h"
#include "src/containers/Group.h"
#include "ui/dialogs/ClassesDialog.h"
#include "ui/model/TreeModelClasses.h"

ClassesView::ClassesView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);

  ui.mTreeView->header()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTreeView->setSortingEnabled(true);

  ui.mSplitClass->setHidden(true);
}

ClassesView::~ClassesView()
{
  delete modelTester;
  mContext.RemoveObserver(mTreeModel);
}

void ClassesView::ClearData()
{
  // mStudentGroupModel->ClearData();
}

void ClassesView::UpdateActions()
{
  const bool hasSelection = ui.mTreeView->selectionModel()->selection().isEmpty();
  ui.mSplitClass->setHidden(hasSelection);
  if (!hasSelection)
    ui.mSplitClass->setText("Split Class");
  else
    ui.mSplitClass->setText("Add Class");
}

void ClassesView::AddModel(shared_ptr<TreeModel> aTreeModel)
{
  mTreeModel = aTreeModel;

  modelTester = new QAbstractItemModelTester(
    mTreeModel.get(), QAbstractItemModelTester::FailureReportingMode::Fatal, this);
  ui.mTreeView->setModel(mTreeModel.get());

  mContext.RegisterObserver(mTreeModel);
}

void ClassesView::on_mSplitClass_clicked()
{
  ClassesDialog AddDialog(this);

  if (AddDialog.exec())
  {
    QString name             = AddDialog.Name->text();
    int     numberOfStudents = AddDialog.NumberOfStudents->value();

    const QModelIndex indexParent = ui.mTreeView->selectionModel()->currentIndex();
    auto              parentItem  = mTreeModel->getItem(indexParent);
    int               row         = static_cast<int>(parentItem->GetChildrenSize());

    if (!name.isEmpty())
    {
      // append a single row
      if (!mTreeModel->insertRows(row, mContext.GenerateGroupId(), indexParent))
        return;

      const QModelIndex childIndexName = mTreeModel->index(row, 0, indexParent);
      mTreeModel->setData(childIndexName, name, Qt::EditRole);

      const QModelIndex childIndexNrOfStud = mTreeModel->index(row, 1, indexParent);
      mTreeModel->setData(childIndexNrOfStud, numberOfStudents, Qt::EditRole);
    }
    else
      QMessageBox::about(this, "Name error", "You need to insert a class name");

    ui.mTreeView->selectionModel()->setCurrentIndex(mTreeModel->index(row, 0, indexParent),
                                                    QItemSelectionModel::ClearAndSelect |
                                                      QItemSelectionModel::Rows);
  }

  UpdateActions();
}

void ClassesView::on_mAddClass_clicked()
{
  ClassesDialog AddDialog(this);

  if (AddDialog.exec())
  {
    QString name             = AddDialog.Name->text();
    int     numberOfStudents = AddDialog.NumberOfStudents->value();

    const QModelIndex indexParent = ui.mTreeView->rootIndex();

    auto parentItem = mTreeModel->getItem(indexParent);
    int  row        = static_cast<int>(parentItem->GetChildrenSize());

    if (!name.isEmpty())
    {
      if (!mTreeModel->insertRows(row, mContext.GenerateGroupId(), indexParent))
        return;

      const QModelIndex childIndexName = mTreeModel->index(row, 0, indexParent);
      mTreeModel->setData(childIndexName, name, Qt::EditRole);

      const QModelIndex childIndexNrOfStud = mTreeModel->index(row, 1, indexParent);
      mTreeModel->setData(childIndexNrOfStud, numberOfStudents, Qt::EditRole);
    }
    else
      QMessageBox::about(this, "Name error", "You need to insert a class name");

    ui.mTreeView->selectionModel()->setCurrentIndex(mTreeModel->index(row, 0, indexParent),
                                                    QItemSelectionModel::ClearAndSelect |
                                                      QItemSelectionModel::Rows);
  }

  UpdateActions();
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
  auto indexSelectedGroup = ui.mTreeView->selectionModel()->currentIndex();

  if (!indexSelectedGroup.isValid())
  {
    QMessageBox::about(this, "No Class Selected", "Please choose a class");
    return;
  }

  // if delete a base class search for children to don't be referend into other view
  auto result = mContext.SearchGroup(mTreeModel->getItem(indexSelectedGroup));
  if (!result.empty())
  {
    result.append("Please remove all objects that hold this Group");
    QMessageBox::about(this, "About", QString::fromStdString(result));
  }
  else
    mTreeModel->removeRow(indexSelectedGroup.row(), indexSelectedGroup.parent());

  UpdateActions();
}
