#include "stdafx.h"
#include "ConstraintListModel.h"
#include "Context.h"
#include "TimeConstraint.h"

ConstraintListModel::ConstraintListModel(Context & aContext, QObject * parent)
  : QAbstractListModel(parent)
  , mContext(aContext)
{
}

int ConstraintListModel::rowCount(const QModelIndex & /*parent*/) const
{
  return static_cast<int>(mContext.GetConstraintSize());
}

QVariant ConstraintListModel::data(const QModelIndex & index, int role) const
{
  if (!index.isValid() || role != Qt::DisplayRole)
  {
    return QVariant();
  }

  auto constraint = mContext.GetConstraintByIndex(index.row());

  return QString::fromStdString(constraint->GetConstraintName());
}

bool ConstraintListModel::insertRows(int position, int rows, const QModelIndex & index)
{
  Q_UNUSED(index);
  beginInsertRows(QModelIndex(), position, rows);

  endInsertRows();
  return true;
}

bool ConstraintListModel::removeRows(int position, int rows, const QModelIndex & index)
{
  Q_UNUSED(index);
  beginRemoveRows(QModelIndex(), position, rows);

  mContext.RemoveConstraint(position);

  endRemoveRows();
  return true;
}
