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
  return HoursPerDay;
}

int TimeTableViewModel::columnCount(const QModelIndex & /*parent*/) const
{
  return 3;
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
  }
  else if (role == Qt::DisplayRole && orientation == Qt::Vertical)
  {
    switch (section)
    {
    case 0:
      return QString("08:00");
    case 1:
      return QString("09:00");
    case 2:
      return QString("10:00");
    case 3:
      return QString("11:00");
    case 4:
      return QString("12:00");
    case 5:
      return QString("13:00");
    case 6:
      return QString("14:00");
    case 7:
      return QString("15:00");
    case 8:
      return QString("16:00");
    case 9:
      return QString("17:00");
    case 10:
      return QString("18:00");
    case 11:
      return QString("19:00");
    case 12:
      return QString("20:00");
    default:
      break;
    }
  }
  return QVariant();
}

void TimeTableViewModel::ClearData()
{
}
