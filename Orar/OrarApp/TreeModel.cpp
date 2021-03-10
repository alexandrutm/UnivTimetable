#include "stdafx.h"
#include "treemodel.h"
#include "Context.h"
#include "Students.h"

TreeModel::TreeModel(Context & aContext, QObject * parent)
  : QAbstractItemModel(parent)
  , mContext(aContext)

{
}

TreeModel::~TreeModel()
{
}

int TreeModel::rowCount(const QModelIndex & parent) const
{
  const auto parentItem = getItem(parent);

  return parentItem ? static_cast<int>(parentItem->GetChildrenSize()) : 0;
}

int TreeModel::columnCount(const QModelIndex & parent) const
{
  Q_UNUSED(parent);
  return mContext.GetRootClass()->GetNumberOfData();
}

QVariant TreeModel::data(const QModelIndex & index, int role) const
{
  if (!index.isValid())
    return QVariant();

  if (role != Qt::DisplayRole && role != Qt::EditRole)
    return QVariant();

  auto item = getItem(index);

  if (index.column() == 0)
  {
    return QString::fromStdString(item->GetName());
  }
  else
  {
    return item->GetNumberOfStudents();
  }
}

Qt::ItemFlags TreeModel::flags(const QModelIndex & index) const
{
  if (!index.isValid())
    return Qt::NoItemFlags;

  return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
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

bool TreeModel::setData(const QModelIndex & index, const QVariant & aClassData, int role)
{
  if (role != Qt::EditRole)
    return false;

  auto item = getItem(index);

  switch (index.column())
  {
  case 0:
    item->SetName(aClassData.toString().toStdString());
    break;
  case 1:
    item->SetNumberOfStudents(aClassData.toInt());
    break;
  }

  emit dataChanged(index, index, { Qt::DisplayRole, Qt::EditRole });

  return true;
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex & parent) const
{
  if (parent.isValid() && parent.column() != 0)
    return QModelIndex();

  auto parentItem = getItem(parent);
  if (!parentItem)
    return QModelIndex();

  auto childItem = parentItem->GetChild(row);
  if (childItem)
    return createIndex(row, column, childItem);
  return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex & index) const
{
  if (!index.isValid())
    return QModelIndex();

  auto childItem  = getItem(index);
  auto parentItem = childItem ? childItem->GetParent() : nullptr;

  if (parentItem == mContext.GetRootClass() || !parentItem)
    return QModelIndex();

  return createIndex(static_cast<int>(parentItem->GetChildrenSize()), 0, parentItem);
}

Students * TreeModel::getItem(const QModelIndex & index) const
{
  if (index.isValid())
  {
    Students * item = static_cast<Students *>(index.internalPointer());
    if (item)
      return item;
  }

  return mContext.GetRootClass();
}

bool TreeModel::insertRows(int position, int rows, const QModelIndex & parent)
{
  // insert one row at position
  auto parentItem = getItem(parent);
  if (!parentItem)
    return false;

  beginInsertRows(parent, position, position + rows - 1);
  parentItem->InsertChild(mContext.GenerateClassId());
  endInsertRows();

  auto b = mContext.GetTeacherSize();

  return true;
}

bool TreeModel::removeRows(int position, int rows, const QModelIndex & parent)
{
  auto parentItem = getItem(parent);
  if (!parentItem)
    return false;

  beginRemoveRows(parent, position, position + rows - 1);
  parentItem->RemoveChild(position);
  endRemoveRows();

  return true;
}
