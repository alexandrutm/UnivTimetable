#include "stdafx.h"
#include "LessonView.h"
#include "Context.h"
#include "Group.h"
#include "Lesson.h"
#include "LessonDialog.h"
#include "LessonTableModel.h"
#include "RoomTableModel.h"
#include "SortFilterProxyModel.h"
#include "Subject.h"
#include "SubjectTableModel.h"
#include "Teacher.h"
#include "TeacherTableModel.h"
#include "TreeModelClasses.h"

LessonView::LessonView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);

  // models for qcombobox
  mTeacherModel   = new TeacherTableModel(mContext, this);
  mSubjectModel   = new SubjectTableModel(mContext, this);
  mClassModel     = new TreeModel(mContext, this);
  mRoomTableModel = new RoomTableModel(mContext, this);

  tableModel = make_shared<LessonTableModel>(mContext, this);
  proxyModel = new SortFilterProxyModel();

  proxyModel->setSourceModel(tableModel.get());
  proxyModel->sort(0, Qt::AscendingOrder);
  ui.mTable->setModel(proxyModel);
  ui.mTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTable->setSortingEnabled(true);

  mContext.RegisterObserver(tableModel);
}

LessonView::~LessonView()
{
  mContext.RemoveObserver(tableModel);
  delete mTeacherModel;
  delete mSubjectModel;
  delete mClassModel;
  delete mRoomTableModel;
  delete proxyModel;
}

void LessonView::ClearData()
{
  tableModel->ClearContent();
}

void LessonView::on_mAdd_clicked()
{
  LessonDialog aDialog(this);

  aDialog.mTeacher->setModel(mTeacherModel);
  aDialog.mSubject->setModel(mSubjectModel);

  // paint a tree model into class combobox
  unique_ptr<QTreeView> treeViewCombobox = make_unique<QTreeView>(aDialog.mClasses);
  aDialog.mClasses->setView(treeViewCombobox.get());
  aDialog.mClasses->setModel(mClassModel);

  if (aDialog.exec())
  {
    // tree model for classes combo box
    auto selectedRowClass = aDialog.mClasses->view()->selectionModel()->currentIndex();

    int selectedRowTeacher = aDialog.mTeacher->currentIndex();
    int selectedRowSubject = aDialog.mSubject->currentIndex();

    if (selectedRowTeacher >= 0 && selectedRowSubject >= 0 && selectedRowClass.row() >= 0)
    {
      auto classes = mClassModel->getItem(selectedRowClass);

      auto subject      = mContext.GetSubjectByIndex(selectedRowSubject);
      auto teacher      = mContext.GetTeacherByIndex(selectedRowTeacher);
      auto hoursPerWeek = aDialog.mDuration->value();

      shared_ptr<Lesson> newLesson =
        make_shared<Lesson>(teacher, subject, classes, hoursPerWeek, mContext.GenerateLessonId());

      tableModel->PopulateModel(newLesson);
    }
    else
    {
      QMessageBox::about(this, "Error", "Please complete all fields");
    }
  }

  //
}

void LessonView::on_mEdit_clicked()
{
  LessonDialog aDialog(this);
  QModelIndex  index;

  aDialog.mTeacher->setModel(mTeacherModel);
  aDialog.mSubject->setModel(mSubjectModel);

  QTreeView * treeViewCombobox = new QTreeView(aDialog.mClasses);
  aDialog.mClasses->setView(treeViewCombobox);
  aDialog.mClasses->setModel(mClassModel);

  int currentSelectedRowMapped =
    proxyModel->mapToSource(ui.mTable->selectionModel()->currentIndex()).row();

  if (currentSelectedRowMapped < 0)
  {
    QMessageBox::about(this, "No item selected", "Please choose an item to edit");
  }
  else if (aDialog.exec())
  {
    auto selectedTeacher  = aDialog.mTeacher->currentIndex();
    auto selectedSubject  = aDialog.mSubject->currentIndex();
    auto selectedRowClass = aDialog.mClasses->view()->selectionModel()->currentIndex();
    auto hoursPerWeek     = aDialog.mDuration->value();

    if (selectedTeacher >= 0 && selectedSubject >= 0 && selectedRowClass.row() >= 0)
    {
      auto classes = mClassModel->getItem(selectedRowClass);
      auto teacher = mContext.GetTeacherByIndex(selectedTeacher);
      auto subject = mContext.GetSubjectByIndex(selectedSubject);

      shared_ptr<Lesson> newLesson =
        make_shared<Lesson>(teacher, subject, classes, hoursPerWeek, mContext.GenerateLessonId());

      index = tableModel->index(currentSelectedRowMapped, 0, QModelIndex());
      tableModel->setData(index, newLesson, Qt::EditRole);
    }
    else
      QMessageBox::about(this, "Error", "Please complete all fields");
  }
  delete treeViewCombobox;
}

void LessonView::on_mDelete_clicked()
{
  int currentSelectedRowMapped =
    proxyModel->mapToSource(ui.mTable->selectionModel()->currentIndex()).row();

  if (currentSelectedRowMapped < 0)
  {
    QMessageBox::about(this, "No item selected", "Please choose an item to delete");
  }
  else
  {
    tableModel->RemoveItemFromModel(currentSelectedRowMapped);
  }
}
