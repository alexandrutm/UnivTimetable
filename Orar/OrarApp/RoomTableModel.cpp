#include "stdafx.h"
#include "RoomTableModel.h"
#include "Context.h"
#include "Room.h"

RoomTableModel::RoomTableModel(Context & aContext, QObject * parent)
  : QAbstractTableModel(parent)
  , mContext(aContext)
{
}

int RoomTableModel::rowCount(const QModelIndex & /*parent*/) const
{
  return static_cast<int>(mContext.GetRoomSize());
}

int RoomTableModel::columnCount(const QModelIndex & /*parent*/) const
{
  return 2;
}

QVariant RoomTableModel::data(const QModelIndex & index, int role) const
{
  if (!index.isValid() || role != Qt::DisplayRole)
  {
    return QVariant();
  }

  if (index.column() == 0)
  {
    QString aName;
    aName = QString::fromStdString((mContext.GetRoomByIndex(index.row()))->GetNume());
    return aName;
  }

  return QVariant();
}

QVariant RoomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
  {
    if (section == 0)
    {
      return QString("Room Name");
    }
    else if (section == 1)
    {
      return QString("Capacity");
    }
  }
  return QVariant();
}

bool RoomTableModel::setData(const QModelIndex & index, const QVariant & aName, int role)
{
  if (index.isValid() && role == Qt::EditRole)
  {
    auto room = mContext.GetRoomByIndex(index.row());

    switch (index.column())
    {
    case 0:
      room->SetName((aName.toString()).toStdString());
      break;
    default:
      return false;
    }

    emit dataChanged(index, index, { Qt::DisplayRole, Qt::EditRole });

    return true;
  }

  return false;
}

void RoomTableModel::RemoveItemFromModel(int aRowSelected)
{
  beginRemoveRows(QModelIndex(), aRowSelected,
                  aRowSelected);  // emit signal to notify view that a new row is removed

  mContext.RemoveRoom(aRowSelected);

  endRemoveRows();
}

void RoomTableModel::PopulateModel(QString aName)
{
  int newRow = static_cast<int>(mContext.GetRoomSize());

  beginInsertRows(QModelIndex(), newRow,
                  newRow);  // emit signal to notify view that a new row is inserted

  shared_ptr<Room> newRoom = make_shared<Room>(aName.toStdString(), mContext.GenerateRoomId());
  mContext.AddRoom(newRoom);

  endInsertRows();
}

void RoomTableModel::ClearData()
{
  if (mContext.GetRoomSize() > 0)
  {
    beginRemoveRows(QModelIndex(), 0, static_cast<int>(mContext.GetRoomSize()) - 1);
    mContext.DeleteRooms();
    endRemoveRows();
  }
}
