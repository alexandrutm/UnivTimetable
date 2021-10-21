#include "stdafx.h"
#include "TimeTableViewModel.h"
#include "../src/containers/InstituteData.h"

TimeTableViewModel::TimeTableViewModel(QObject * parent)
  : QAbstractTableModel(parent)
{
  mTimetable.resize(5, vector<string>());
  mLessonsDetails.resize(5);
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
    return QString::fromStdString(mLessonsDetails[0]);
    break;
  case 1:
    return QString::fromStdString(mLessonsDetails[1]);
    break;
  case 2:
    return QString::fromStdString(mLessonsDetails[2]);
    break;
  case 3:
    return QString::fromStdString(mLessonsDetails[3]);
    break;
  case 4:
    return QString::fromStdString(mLessonsDetails[4]);
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
  beginResetModel();
  mLessonsDetails.clear();
  mTimetable.clear();
  endResetModel();

  mTimetable.resize(5, vector<string>());
  mLessonsDetails.resize(5);
}

void TimeTableViewModel::AddData(vector<vector<string>> aLessonsDetails)
{
  mTimetable = aLessonsDetails;

  mLessonsDetails.clear();
  mLessonsDetails.resize(5);

  int i = 0;
  for (auto day : mTimetable)
  {
    for (auto lesson : day)
    {
      mLessonsDetails[i].append(lesson);
    }
    i++;
  }
}

void TimeTableViewModel::FilterData(vector<string> pattern)
{
  if (!pattern.empty())
  {
    mLessonsDetails.clear();
    mLessonsDetails.resize(5);

    int i = 0;

    for (auto day : mTimetable)
    {
      for (auto lesson : day)
      {
        for (auto groupName : pattern)
        {
          auto pos = lesson.find(groupName);
          if (pos != std::string::npos)
          {
            mLessonsDetails[i].append(lesson);
          }
        }
      }
      i++;
    }
  }
}

vector<vector<string>> TimeTableViewModel::GetTiemtableData()
{
  return mTimetable;
}
