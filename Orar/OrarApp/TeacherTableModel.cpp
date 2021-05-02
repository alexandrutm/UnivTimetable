#include "stdafx.h"
#include "TeacherTableModel.h"
#include "Context.h"
#include "Teacher.h"

TeacherTableModel::TeacherTableModel(Context & aContext, QObject * parent)
  : QAbstractTableModel(parent)
  , mContext(aContext)
{
  mModelName = "teachermodel";
}

int TeacherTableModel::rowCount(const QModelIndex & parent) const
{
  return parent.isValid() ? 0 : static_cast<int>(mContext.GetTeacherSize());
}

int TeacherTableModel::columnCount(const QModelIndex & parent) const
{
  return parent.isValid() ? 0 : 2;
}

QVariant TeacherTableModel::data(const QModelIndex & index, int role) const
{
  if (!index.isValid() || role != Qt::DisplayRole)
  {
    return QVariant();
  }

  const auto & teacher = mContext.GetTeacherByIndex(index.row());

  switch (index.column())
  {
  case 0:
    return QString::fromStdString((teacher->GetFirstName()));
  case 1:
    return QString::fromStdString((teacher->GetLastName()));
  default:
    break;
  }
  return QVariant();
}

bool TeacherTableModel::setData(const QModelIndex & index, const QVariant & aName, int role)
{
  if (index.isValid() && role == Qt::EditRole)
  {
    auto teacher = mContext.GetTeacherByIndex(index.row());

    switch (index.column())
    {
    case 0:
      teacher->SetFirstName((aName.toString()).toStdString());
      break;
    case 1:
      teacher->SetLastName((aName.toString()).toStdString());
      break;
    default:
      return false;
    }

    emit dataChanged(index, index, { Qt::DisplayRole, Qt::EditRole });

    return true;
  }

  return false;
}

QVariant TeacherTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
  {
    if (section == 0)
    {
      return QString("First Name");
    }
    else if (section == 1)
    {
      return QString("Last Name");
    }
  }
  return QVariant();
}

bool TeacherTableModel::removeRows(int first, int last, const QModelIndex & index)
{
  Q_UNUSED(index);
  beginRemoveRows(QModelIndex(), first, last);

  mContext.RemoveTeacher(first);

  endRemoveRows();
  return true;
}

void TeacherTableModel::PopulateModel(string aFirstName, string aLastName, int aTeacherId)
{
  int row = static_cast<int>(mContext.GetTeacherSize());

  beginInsertRows(QModelIndex(), row, row);

  mContext.AddTeacher(make_shared<Teacher>(aFirstName, aLastName, aTeacherId));

  endInsertRows();
}

void TeacherTableModel::AddNewRow()
{
  if (mContext.GetTeacherSize() == 0)
    return;

  int newRow = static_cast<int>(mContext.GetTeacherSize()) - 1;

  beginInsertRows(QModelIndex(), newRow, newRow);
  endInsertRows();
}

void TeacherTableModel::Update(string aInstruction)
{
  if (aInstruction == "addnewrow")
    AddNewRow();
}

string TeacherTableModel::GetModelName()
{
  return mModelName;
}

void TeacherTableModel::ClearContent()
{
  if (mContext.GetTeacherSize() > 0)
  {
    beginRemoveRows(QModelIndex(), 0, static_cast<int>(mContext.GetTeacherSize()) - 1);
    // emit signal to notify view that a new row is removed
    mContext.DeleteTeachers();
    endRemoveRows();
  }
}
