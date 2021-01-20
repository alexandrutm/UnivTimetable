#include "stdafx.h"
#include "ClassTableModel.h"
#include "Context.h"
#include "Classes.h"

ClassTableModel::ClassTableModel(Context& aContext, QObject* parent)
    :QAbstractTableModel(parent), mContext(aContext)
{

}


int ClassTableModel::rowCount(const QModelIndex& parent) const
{
    return mContext.GetClassSize();

}

int ClassTableModel::columnCount(const QModelIndex& parent) const
{
    return 2;
}

QVariant ClassTableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (index.column() == 0) {
        QString aName;
        aName = QString::fromStdString((mContext.GetClassByIndex(index.row()))->GetName());
        return aName;
    }
    else
    {
        int nrOfStudents;
        nrOfStudents = (mContext.GetClassByIndex(index.row()))->GetNumberOfStudents();
        return nrOfStudents;
    }
    return QVariant();
}

QVariant ClassTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("Class Name");
        }
        else if (section == 1) {
            return QString("Students");
        }
    }
    return QVariant();
}

void ClassTableModel::EditModel(int rowSelected, QString aName, int aNumberOfStudents)
{

    shared_ptr<Classes> oldClass = mContext.GetClassByIndex(rowSelected);
    shared_ptr<Classes> newClass = make_shared<Classes>(aName.toStdString(), aNumberOfStudents);

    mContext.EditClasses(oldClass,newClass);

}

void ClassTableModel::RemoveItemFromModel(int aRowSelected)
{
    beginRemoveRows(QModelIndex(), aRowSelected, aRowSelected);//emit signal to notify view that a new row is removed

    shared_ptr<Classes> oldClass = mContext.GetClassByIndex(aRowSelected);
    mContext.RemoveClass(oldClass);

    endRemoveRows();
}

void ClassTableModel::PopulateModel(QString aName, int aNrOfStudents)
{
    int newRow = mContext.GetClassSize();

    beginInsertRows(QModelIndex(), newRow, newRow);//emit signal to notify view that a new row is inserted

    shared_ptr<Classes> newClass = make_shared<Classes>(aName.toStdString(), aNrOfStudents);
    mContext.AddClass(newClass);

    endInsertRows();
}

