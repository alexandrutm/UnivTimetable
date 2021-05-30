#include "stdafx.h"
#include "SortFilterProxyModel.h"

SortFilterProxyModel::SortFilterProxyModel(QObject * parent)
  : QSortFilterProxyModel(parent)
{
}

// void SortFilterProxyModel::setFilterRegularExpression(const QString & pattern)
//{
//  if (!pattern.isEmpty())
//  {
//  }
//}

bool SortFilterProxyModel::lessThan(const QModelIndex & left, const QModelIndex & right) const
{
  QVariant leftData  = sourceModel()->data(left);
  QVariant rightData = sourceModel()->data(right);

  QString leftString = leftData.toString();

  QString rightString = rightData.toString();

  return QString::localeAwareCompare(leftString, rightString) < 0;
}
