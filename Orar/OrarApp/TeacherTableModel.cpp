#include "stdafx.h"
#include "TeacherTableModel.h"
#include "Context.h"
#include "Teacher.h"

TableModel::TableModel(Context & aContext, QObject * parent)
  : QAbstractTableModel(parent)
  , mContext(aContext)
{
}

int TableModel::rowCount(const QModelIndex & parent) const
{
  return parent.isValid() ? 0 : mContext.GetTeacherSize();
}

int TableModel::columnCount(const QModelIndex & parent) const
{
  return parent.isValid() ? 0 : 2;
}

QVariant TableModel::data(const QModelIndex & index, int role) const
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

bool TableModel::setData(const QModelIndex & index, const QVariant & aName, int role)
{
  if (index.isValid() && role == Qt::EditRole)
  {
    auto & teacher = mContext.GetTeacherByIndex(index.row());

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

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
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

void TableModel::RemoveItemFromModel(int aRowSelected)
{
  beginRemoveRows(QModelIndex(), aRowSelected, aRowSelected);
  // emit signal to notify view that a new row is removed

  mContext.RemoveTeacher(aRowSelected);

  endRemoveRows();
}

void TableModel::PopulateModel(QString aFirstName, QString aLastName)
{
  int newRow = mContext.GetTeacherSize();

  beginInsertRows(QModelIndex(), newRow, newRow);
  // emit signal to notify view that a new row is inserted

  shared_ptr<Teacher> newTeacher = make_shared<Teacher>(
    aFirstName.toStdString(), aLastName.toStdString(), mContext.GenerateTeacherId());
  mContext.AddTeacher(newTeacher);

  endInsertRows();
}

void TableModel::ClearContent()
{
  if (mContext.GetTeacherSize() > 0)
  {
    beginRemoveRows(QModelIndex(), 0, mContext.GetTeacherSize() - 1);
    // emit signal to notify view that a new row is removed

    mContext.DeleteTeachers();
    endRemoveRows();
  }
}
