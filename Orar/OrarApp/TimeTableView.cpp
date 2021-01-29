#include "stdafx.h"
#include "TimeTableView.h"
#include "Context.h"
#include "Classes.h"

TimeTableView::TimeTableView(Context& aContext, QObject* parent)
    :QAbstractTableModel(parent), mContext(aContext)
{

}


int TimeTableView::rowCount(const QModelIndex& parent) const
{
    return mContext.GetClassSize();

}

int  TimeTableView::columnCount(const QModelIndex& parent) const
{
    return 6;
}

QVariant  TimeTableView::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
    {
        return QVariant();
    }

    return QVariant();
}

QVariant TimeTableView::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("Class");
        }
        else if (section == 1) {
            return QString("Monday");
        }
        else if (section == 2) {
            return QString("Tuesday");
        }
        else if (section == 3) {
            return QString("Wednesday");
        }
        else if (section == 4) {
            return QString("Thursday");
        }
        else if (section == 5) {
            return QString("Friday");
        }
    }
    return QVariant();
}

void  TimeTableView::EditModel(int rowSelected, QString aName, int aNumberOfStudents)
{


}

void  TimeTableView::RemoveItemFromModel(int aRowSelected)
{
    beginRemoveRows(QModelIndex(), aRowSelected, aRowSelected);//emit signal to notify view that a new row is removed

    endRemoveRows();
}

void  TimeTableView::PopulateModel(QString aName, int aNrOfStudents)
{
    int newRow = mContext.GetClassSize();

    endInsertRows();
}

void  TimeTableView::ClearData()
{

}

