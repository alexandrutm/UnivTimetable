#include "stdafx.h"
#include "LessonView.h"
#include "ClassTableModel.h"
#include "Classes.h"
#include "Context.h"
#include "Lesson.h"
#include "LessonDialog.h"
#include "LessonTableModel.h"
#include "RoomTableModel.h"
#include "SortFilterProxyModel.h"
#include "Subject.h"
#include "SubjectTableModel.h"
#include "Teacher.h"
#include "TeacherTableModel.h"

LessonView::LessonView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);

  mTeacherModel   = new TableModel(mContext, this);
  mSubjectModel   = new SubjectTableModel(mContext, this);
  mClassModel     = new ClassTableModel(mContext, this);
  mRoomTableModel = new RoomTableModel(mContext, this);

  tableModel = new LessonTableModel(mContext, this);
  proxyModel = new SortFilterProxyModel();

  proxyModel->setSourceModel(tableModel);
  proxyModel->sort(0, Qt::AscendingOrder);
  ui.mTable->setModel(proxyModel);
  ui.mTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTable->setSortingEnabled(true);
}

LessonView::~LessonView()
{
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
  aDialog.mClasses->setModel(mClassModel);

  if (aDialog.exec())
  {
    int selectedRowTeacher = aDialog.mTeacher->currentIndex();
    int selectedRowSubject = aDialog.mSubject->currentIndex();
    int selectedRowClass   = aDialog.mClasses->currentIndex();

    if (selectedRowTeacher >= 0 && selectedRowClass >= 0 && selectedRowSubject >= 0)
    {
      auto classes      = mContext.GetClassByIndex(selectedRowClass);
      auto subject      = mContext.GetSubjectByIndex(selectedRowSubject);
      auto teacher      = mContext.GetTeacherByIndex(selectedRowTeacher);
      auto hoursPerWeek = aDialog.mHoursPerWeek->value();

      shared_ptr<Lesson> newLesson =
        make_shared<Lesson>(teacher, subject, classes, hoursPerWeek, mContext.GenerateLessonId());

      tableModel->PopulateModel(newLesson);
    }
    else
    {
      QMessageBox::about(this, "Error", "Please complete all fields");
    }
  }
}

void LessonView::on_mEdit_clicked()
{
  LessonDialog aDialog(this);
  QModelIndex  index;

  aDialog.mTeacher->setModel(mTeacherModel);
  aDialog.mSubject->setModel(mSubjectModel);
  aDialog.mClasses->setModel(mClassModel);

  int currentSelectedRowMapped =
    proxyModel->mapToSource(ui.mTable->selectionModel()->currentIndex()).row();

  if (currentSelectedRowMapped < 0)
  {
    QMessageBox::about(this, "No item selected", "Please choose an item to edit");
  }
  else if (aDialog.exec())
  {
    auto selectedTeacher = aDialog.mTeacher->currentIndex();
    auto teacher         = mContext.GetTeacherByIndex(selectedTeacher);

    auto selectedSubject = aDialog.mSubject->currentIndex();
    auto subject         = mContext.GetSubjectByIndex(selectedSubject);

    auto selectedClass = aDialog.mClasses->currentIndex();
    auto classes       = mContext.GetClassByIndex(selectedClass);

    auto hoursPerWeek = aDialog.mHoursPerWeek->value();

    shared_ptr<Lesson> newLesson =
      make_shared<Lesson>(teacher, subject, classes, hoursPerWeek, mContext.GenerateLessonId());

    index = tableModel->index(currentSelectedRowMapped, 0, QModelIndex());
    tableModel->setData(index, newLesson, Qt::EditRole);
  }
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

void LessonView::on_mConstraints_clicked()
{
}
