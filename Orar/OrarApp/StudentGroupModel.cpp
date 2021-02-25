#include "stdafx.h"
#include "StudentGroupModel.h"
#include "Context.h"
#include "StudentGroup.h"
#include "StudentYear.h"

StudentGroupModel::StudentGroupModel(Context & aContext, QObject * parent)
  : QAbstractTableModel(parent)
  , mContext(aContext)
{
}

int StudentGroupModel::rowCount(const QModelIndex & /*parent*/) const
{
  return static_cast<int>(mContext.GetClassSize());
}

int StudentGroupModel::columnCount(const QModelIndex & /*parent*/) const
{
  return 2;
}

QVariant StudentGroupModel::data(const QModelIndex & index, int role) const
{
  if (!index.isValid() || role != Qt::DisplayRole)
  {
    return QVariant();
  }

  if (index.column() == 0)
  {
    QString aName;
    aName = QString::fromStdString((mContext.GetClassByIndex(index.row()))->GetName());
    return aName;
  }
  else
  {
    int nrOfStudents;
    nrOfStudents = (mContext.GetClassByIndex(index.row()))->GetNumberOfStudents();
    return nrOfStudents;
  }
}

QVariant StudentGroupModel::headerData(int section, Qt::Orientation orientation, int role) const
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

bool StudentGroupModel::setData(const QModelIndex & index, const QVariant & aClassData, int role)
{
  if (index.isValid() && role == Qt::EditRole)
  {
    auto aClass = mContext.GetClassByIndex(index.row());

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

void StudentGroupModel::RemoveItemFromModel(int aRowSelected)
{
  beginRemoveRows(QModelIndex(), aRowSelected, aRowSelected);

  mContext.RemoveClass(aRowSelected);

  endRemoveRows();
}

void StudentGroupModel::PopulateModel(QString aName, int aNrOfStudents, int index)
{
  int newRow = static_cast<int>(mContext.GetClassSize());

  beginInsertRows(QModelIndex(), newRow, newRow);

  shared_ptr<StudentGroup> newGroup =
    make_shared<StudentGroup>(aName.toStdString(), aNrOfStudents, mContext.GenerateClassId(),
                              mContext.GetClassByIndex(index));
  mContext.AddGroup(newGroup, index);

  endInsertRows();
}

void StudentGroupModel::ClearData()
{
  if (mContext.GetClassSize() > 0)
  {
    beginRemoveRows(QModelIndex(), 0, static_cast<int>(mContext.GetClassSize()) - 1);
    mContext.DeleteClasses();
    endRemoveRows();
  }
}
