#include "stdafx.h"
#include "ClassTableModel.h"
#include "Context.h"
#include "StudentGroup.h"

ClassTableModel::ClassTableModel(Context & aContext, QObject * parent)
  : QAbstractTableModel(parent)
  , mContext(aContext)
{
}

int ClassTableModel::rowCount(const QModelIndex & /*parent*/) const
{
  return static_cast<int>(mContext.GetGroupSize());
}

int ClassTableModel::columnCount(const QModelIndex & /*parent*/) const
{
  return 2;
}

QVariant ClassTableModel::data(const QModelIndex & index, int role) const
{
  if (!index.isValid() || role != Qt::DisplayRole)
  {
    return QVariant();
  }

  if (index.column() == 0)
  {
    QString aName;
    aName = QString::fromStdString((mContext.GetGroupByIndex(index.row()))->GetName());
    return aName;
  }
  else
  {
    int nrOfStudents;
    nrOfStudents = (mContext.GetGroupByIndex(index.row()))->GetNumberOfStudents();
    return nrOfStudents;
  }
}

QVariant ClassTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
  {
    if (section == 0)
    {
      return QString("Class Name");
    }
    else if (section == 1)
    {
      return QString("Students");
    }
  }
  return QVariant();
}

bool ClassTableModel::setData(const QModelIndex & index, const QVariant & aClassData, int role)
{
  if (index.isValid() && role == Qt::EditRole)
  {
    auto aClass = mContext.GetGroupByIndex(index.row());

    switch (index.column())
    {
    case 0:
      aClass->SetName((aClassData.toString()).toStdString());
      break;
    case 1:
      aClass->SetNumberOfStudents(aClassData.toInt());
      break;
    default:
      return false;
    }

    emit dataChanged(index, index, { Qt::DisplayRole, Qt::EditRole });

    return true;
  }

  return false;
}

void ClassTableModel::RemoveItemFromModel(int aRowSelected)
{
  beginRemoveRows(QModelIndex(), aRowSelected, aRowSelected);

  mContext.RemoveClass(aRowSelected);

  endRemoveRows();
}

void ClassTableModel::PopulateModel(QString aName, int aNrOfStudents)
{
  int newRow = static_cast<int>(mContext.GetGroupSize());

  beginInsertRows(QModelIndex(), newRow, newRow);

  shared_ptr<StudentGroup> newGroup =
    make_shared<StudentGroup>(aName.toStdString(), aNrOfStudents, mContext.GenerateClassId());
  mContext.AddGroup(newGroup);

  endInsertRows();
}

void ClassTableModel::ClearData()
{
  if (mContext.GetGroupSize() > 0)
  {
    beginRemoveRows(QModelIndex(), 0, static_cast<int>(mContext.GetGroupSize()) - 1);
    mContext.DeleteClasses();
    endRemoveRows();
  }
}
