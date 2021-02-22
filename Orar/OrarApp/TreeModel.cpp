#include "stdafx.h"
#include "treemodel.h"
#include "Classes.h"
#include "Context.h"

TreeModel::TreeModel(Context & aContext, QObject * parent)
  : QAbstractItemModel(parent)
  , mContext(aContext)

{
  rootItem = createIndex(0, 0, nullptr);
}

TreeModel::~TreeModel()
{
}

int TreeModel::rowCount(const QModelIndex & parent) const
{
  Q_UNUSED(parent);
  return static_cast<int>(mContext.GetClassSize());
}

int TreeModel::columnCount(const QModelIndex & parent) const
{
  Q_UNUSED(parent);
  return 2;
}

QVariant TreeModel::data(const QModelIndex & index, int role) const
{
  if (!index.isValid())
    return QVariant();

  if (role != Qt::DisplayRole && role != Qt::EditRole)
    return QVariant();

  if (index.column() == 0)
  {
    return QString::fromStdString((mContext.GetClassByIndex(index.row()))->GetName());
  }
  else
  {
    return (mContext.GetClassByIndex(index.row()))->GetNumberOfStudents();
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

bool TreeModel::PopulateModel(QString aName, int NumberOfStudents, const QModelIndex & parent)
{
  if (mContext.GetClassSize() > 0)
  {
    shared_ptr<Classes> parentItem = mContext.GetClassByIndex(parent.row());

    shared_ptr<Classes> childItem = make_shared<Classes>(aName.toStdString(), NumberOfStudents,
                                                         mContext.GenerateClassId(), parentItem);

    int newRow = static_cast<int>(mContext.GetClassSize());

    beginInsertRows(parent, newRow, newRow);
    parentItem->AddChild(childItem);
    endInsertRows();

    return true;
  }
  else
  {
    shared_ptr<Classes> childItem = make_shared<Classes>(aName.toStdString(), NumberOfStudents,
                                                         mContext.GenerateClassId(), rootItem);

    int newRow = static_cast<int>(mContext.GetClassSize());

    beginInsertRows(rootItem, newRow, newRow);
    mContext.AddClass(childItem);
    endInsertRows();
  }
}

bool TreeModel::removeRow(int aRowSelected, const QModelIndex & parent)
{
  shared_ptr<Classes> parentItem = mContext.GetClassByIndex(parent.row());
  if (!parentItem)
    return false;

  beginRemoveRows(parent, aRowSelected, aRowSelected);
  parentItem->RemoveChild(parentItem->GetChild(aRowSelected));
  endRemoveRows();

  return true;
}

bool TreeModel::setData(const QModelIndex & index, const QVariant & aClassData, int role)
{
  if (index.isValid() && role == Qt::EditRole)
  {
    switch (index.column())
    {
    case 0:
      mContext.GetClassByIndex(index.row())->SetName((aClassData.toString()).toStdString());
      break;
    case 1:
      mContext.GetClassByIndex(index.row())->SetNumberOfStudents(aClassData.toInt());
      break;
    default:
      return false;
    }

    emit dataChanged(index, index, { Qt::DisplayRole, Qt::EditRole });

    return true;
  }

  return false;
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex & parent) const
{
  Q_UNUSED(parent);
  // if (parent.isValid() && parent.column() != 0)
  //  return QModelIndex();
  ////! [5]

  ////! [6]
  // TreeItem * parentItem = getItem(parent);
  // if (!parentItem)
  //  return QModelIndex();

  // TreeItem * childItem = parentItem->child(row);
  // if (childItem)
  //  return createIndex(row, column, childItem);
  return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex & index) const
{
  // if (!index.isValid())
  //  return QModelIndex();

  // TreeItem * childItem  = getItem(index);
  // TreeItem * parentItem = childItem ? childItem->parent() : nullptr;

  // if (parentItem == rootItem || !parentItem)
  //  return QModelIndex();

  // return createIndex(parentItem->childNumber(), 0, parentItem);

  return QModelIndex();
}
