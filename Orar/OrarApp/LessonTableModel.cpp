#include "stdafx.h"
#include "LessonTableModel.h"
#include "Context.h"
#include "Group.h"
#include "Lesson.h"
#include "Room.h"
#include "Subject.h"
#include "Teacher.h"

LessonTableModel::LessonTableModel(Context & aContext, QObject * parent)
  : QAbstractTableModel(parent)
  , mContext(aContext)
{
  mModelName = "lessonmodel";
}

int LessonTableModel::rowCount(const QModelIndex & /*parent*/) const
{
  return static_cast<int>(mContext.GetLessonSize());
}

int LessonTableModel::columnCount(const QModelIndex & /*parent*/) const
{
  return 4;
}

QVariant LessonTableModel::data(const QModelIndex & index, int role) const
{
  if (!index.isValid() || role != Qt::DisplayRole)
  {
    return QVariant();
  }

  if (index.column() == 0)
  {
    auto teacher = mContext.GetLessonByIndex(index.row())->GetTeacher();
    return QString::fromStdString(teacher->GetFirstName());
  }
  else if (index.column() == 1)
  {
    auto subject = mContext.GetLessonByIndex(index.row())->GetSubject();
    return QString::fromStdString(subject->GetName());
  }
  else if (index.column() == 2)
  {
    auto studentClass = mContext.GetLessonByIndex(index.row())->GetGroup();
    return QString::fromStdString(studentClass->GetName());
  }
  else if (index.column() == 3)
  {
    return mContext.GetLessonByIndex(index.row())->GetDuration();
  }
  return QVariant();
}

QVariant LessonTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
  {
    if (section == 0)
    {
      return QString("Teacher Name");
    }
    else if (section == 1)
    {
      return QString("Subject");
    }
    else if (section == 2)
    {
      return QString("Class");
    }
    else if (section == 3)
    {
      return QString("Hours per week");
    }
  }
  return QVariant();
}

bool LessonTableModel::setData(const QModelIndex & index, shared_ptr<Lesson> aLesson, int role)
{
  if (index.isValid() && role == Qt::EditRole)
  {
    auto oldLesson = mContext.GetLessonByIndex(index.row());

    oldLesson->SetTeacher(aLesson->GetTeacher());

    oldLesson->SetSubject(aLesson->GetSubject());

    oldLesson->SetGroup(aLesson->GetGroup());

    oldLesson->SetDuration(aLesson->GetDuration());

    emit dataChanged(index, index, { Qt::DisplayRole, Qt::EditRole });

    return true;
  }

  return false;
}
void LessonTableModel::RemoveItemFromModel(int aRowSelected)
{
  beginRemoveRows(QModelIndex(), aRowSelected, aRowSelected);

  mContext.RemoveLesson(aRowSelected);

  endRemoveRows();
}

void LessonTableModel::PopulateModel(shared_ptr<Lesson> aLesson)
{
  int newRow = static_cast<int>(mContext.GetLessonSize());

  beginInsertRows(QModelIndex(), newRow, newRow);
  mContext.AddLesson(aLesson);

  endInsertRows();
}

void LessonTableModel::ClearContent()
{
  if (mContext.GetLessonSize() > 0)
  {
    beginRemoveRows(QModelIndex(), 0, static_cast<int>(mContext.GetLessonSize()) - 1);
    mContext.DeleteLessons();
    endRemoveRows();
  }
}

void LessonTableModel::AddNewRow()
{
  if (mContext.GetLessonSize() == 0)
    return;

  int newRow = static_cast<int>(mContext.GetLessonSize()) - 1;

  beginInsertRows(QModelIndex(), newRow, newRow);
  endInsertRows();
}
void LessonTableModel::Update(string instruction)
{
  if (instruction == "addnewrow")
    AddNewRow();
}

string LessonTableModel::GetModelName()
{
  return mModelName;
}
