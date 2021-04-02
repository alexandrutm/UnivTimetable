#include "stdafx.h"
#include "TimeTableViewModel.h"
#include "Context.h"
#include "InstituteData.h"

TimeTableViewModel::TimeTableViewModel(Context & aContext, QObject * parent)
  : QAbstractTableModel(parent)
  , mContext(aContext)
{
}

int TimeTableViewModel::rowCount(const QModelIndex & /*parent*/) const
{
  return mContext.GetInstituteData()->GetNumberOfHoursPerDay();
}

int TimeTableViewModel::columnCount(const QModelIndex & /*parent*/) const
{
  return mContext.GetInstituteData()->GetNumberOfDaysPerWeek();
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
      return QString("Monday");
    }
    else if (section == 1)
    {
      return QString("Tuesday");
    }
    else if (section == 2)
    {
      return QString("Wednesday");
    }
    else if (section == 3)
    {
      return QString("Thursday");
    }
    else if (section == 4)
    {
      return QString("Friday");
    }
  }
  return QVariant();
}

void TimeTableViewModel::ClearData()
{
}
