#include "stdafx.h"
#include "TimeTableViewModel.h"
#include "Classes.h"
#include "Context.h"

TimeTableViewModel::TimeTableViewModel(Context & aContext, QObject * parent)
  : QAbstractTableModel(parent)
  , mContext(aContext)
{
}

int TimeTableViewModel::rowCount(const QModelIndex & /*parent*/) const
{
  return 4;
}

int TimeTableViewModel::columnCount(const QModelIndex & /*parent*/) const
{
  return 30;
}

QVariant TimeTableViewModel::data(const QModelIndex & index, int role) const
{
  if (!index.isValid() || role != Qt::DisplayRole)
  {
    return QVariant();
  }

  return QVariant();
}

QVariant TimeTableViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
  {
    if (section == 0)
    {
      return QString("Class");
    }
    else if (section == 1)
    {
      return QString("Monday");
    }
    else if (section == 2)
    {
      return QString("Tuesday");
    }
    else if (section == 3)
    {
      return QString("Wednesday");
    }
    else if (section == 4)
    {
      return QString("Thursday");
    }
    else if (section == 5)
    {
      return QString("Friday");
    }
  }
  return QVariant();
}

// void TimeTableViewModel::EditModel(int rowSelected, QString aName, int aNumberOfStudents)
//{
//}
//
// void TimeTableViewModel::RemoveItemFromModel(int aRowSelected)
//{
//  beginRemoveRows(QModelIndex(), aRowSelected,
//                  aRowSelected);  // emit signal to notify view that a new row is removed
//
//  endRemoveRows();
//}
//
// void TimeTableViewModel::PopulateModel(QString aName, int aNrOfStudents)
//{
//  int newRow = mContext.GetClassSize();
//
//  endInsertRows();
//}

void TimeTableViewModel::ClearData()
{
}
