#include "stdafx.h"
#include "TimeTableViewModel.h"
#include "Context.h"

TimeTableViewModel::TimeTableViewModel(Context & aContext, QObject * parent)
  : QAbstractTableModel(parent)
  , mContext(aContext)
{
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
    return "14:00-16:00 (C)  Algoritmi Paraleli Cr. Popirlan  sala 113\n16:00-18:00 (L) Algoritmi "
           "Paraleli Cr.Popirlan\n   ";
  case 1:
    return "14:00-16:00 (C)  Algoritmi Paraleli Cr. Popirlan  sala 113\n16:00-18:00 (L) Algoritmi "
           "Paraleli Cr.Popirlan\n   ";
  case 2:
    return "14:00-16:00 (C)  Algoritmi Paraleli Cr. Popirlan  sala 113\n16:00-18:00 (L) Algoritmi "
           "Paraleli Cr.Popirlan\n   ";
  case 3:
    return "09:00-10:00 (C)  Algoritmi Paraleli Cr. Popirlan  sala 113\n10:00-12:00 (L) Algoritmi "
           "Paraleli Cr.Popirlan\n14:00-16:00 (C) Medii de programare Vizuala Cl. Popirlan sala "
           "305   ";
  case 4:
    return "14:00-16:00 (C)  Algoritmi Paraleli Cr. Popirlan  sala 113\n16:00-18:00 (L) Algoritmi "
           "Paraleli Cr.Popirlan\n   ";
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
