#include "stdafx.h"
#include "TimeTableViewModel.h"
#include "InstituteData.h"

TimeTableViewModel::TimeTableViewModel(QObject * parent)
  : QAbstractTableModel(parent)
{
  mLessonsDetails.resize(5, vector<string>(1));
}

int TimeTableViewModel::rowCount(const QModelIndex & /*parent*/) const
{
  return 1;
}

int TimeTableViewModel::columnCount(const QModelIndex & /*parent*/) const
{
  return 5;
}

QVariant TimeTableViewModel::data(const QModelIndex & index, int role) const
{
  if (!index.isValid() || role != Qt::DisplayRole)
  {
    return QVariant();
  }

  switch (index.column())
  {
  case 0:
    return QString::fromStdString(mLessonsDetails[0][0]);
    break;
  case 1:
    return QString::fromStdString(mLessonsDetails[1][0]);
    break;
  case 2:
    return QString::fromStdString(mLessonsDetails[2][0]);
    break;
  case 3:
    return QString::fromStdString(mLessonsDetails[3][0]);
    break;
  case 4:
    return QString::fromStdString(mLessonsDetails[4][0]);
    break;
  default:
    break;
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

void TimeTableViewModel::AddData(vector<vector<string>> aLessonsDetails)
{
  mLessonsDetails = aLessonsDetails;
}
