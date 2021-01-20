#include "stdafx.h"
#include "RoomTableModel.h"
#include"Context.h"
#include"Room.h"

RoomTableModel::RoomTableModel(Context& aContext, QObject* parent)
    :QAbstractTableModel(parent), mContext(aContext)
{

}


int RoomTableModel::rowCount(const QModelIndex& parent) const
{
    return mContext.GetRoomSize();

}

int RoomTableModel::columnCount(const QModelIndex& parent) const
{
    return 1;
}

QVariant RoomTableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (index.column() == 0) {
        QString aName;
        aName = QString::fromStdString((mContext.GetRoomByIndex(index.row()))->GetNume());
        return aName;
    }

    return QVariant();
}

QVariant RoomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("Room Name");
        }
    }
    return QVariant();
}

void RoomTableModel::EditModel(int rowSelected, QString aName)
{

    shared_ptr<Room> oldRoom = mContext.GetRoomByIndex(rowSelected);
    shared_ptr<Room>newRoom = make_shared<Room>(aName.toStdString());

    mContext.EditRoom(oldRoom, newRoom);

}

void RoomTableModel::RemoveItemFromModel(int aRowSelected)
{
    beginRemoveRows(QModelIndex(), aRowSelected, aRowSelected);//emit signal to notify view that a new row is removed

    shared_ptr<Room> oldRoom = mContext.GetRoomByIndex(aRowSelected);
    mContext.RemoveRoom(oldRoom);

    endRemoveRows();
}

void RoomTableModel::PopulateModel(QString aName)
{
    int newRow = mContext.GetRoomSize();

    beginInsertRows(QModelIndex(), newRow, newRow);//emit signal to notify view that a new row is inserted

    shared_ptr<Room> newRoom = make_shared<Room>(aName.toStdString());
    mContext.AddRoom(newRoom);

    endInsertRows();
}

