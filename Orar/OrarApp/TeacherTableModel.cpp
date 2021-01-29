#include "stdafx.h"
#include "TeacherTableModel.h"
#include"Context.h"
#include"Teacher.h"

TableModel::TableModel(Context &aContext,QObject* parent)
    :QAbstractTableModel(parent),mContext(aContext)
{
    
}


int TableModel::rowCount(const QModelIndex& parent) const
{
    return parent.isValid()? 0:mContext.GetTeacherSize();

}

int TableModel::columnCount(const QModelIndex& parent) const
{
    return parent.isValid() ? 0 : 2;
}

QVariant TableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (index.column() == 0) {
        QString firstName;
        firstName = QString::fromStdString((mContext.GetTeacherByIndex(index.row()))->GetFirstName());
        return firstName;
    }
    else
    {
        QString lastName;
        lastName = QString::fromStdString((mContext.GetTeacherByIndex(index.row()))->GetLastName());
        return lastName;
    }
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("First Name");
        }
        else if (section == 1) {
            return QString("Last Name");
        }
    }
    return QVariant();
}

void TableModel::EditModel(int rowSelected, QString aFirstName, QString aLastName)
{

   // shared_ptr<Teacher> oldTeacher = mContext.GetTeacherByIndex(rowSelected);
    //shared_ptr<Teacher>newTeacher = make_shared<Teacher>(aFirstName.toStdString(), aLastName.toStdString(),);

   // mContext.EditTeacher(oldTeacher, newTeacher);

}

void TableModel::RemoveItemFromModel(int aRowSelected)
{
    beginRemoveRows(QModelIndex(),aRowSelected,aRowSelected);//emit signal to notify view that a new row is removed

    shared_ptr<Teacher> oldTeacher = mContext.GetTeacherByIndex(aRowSelected);
    mContext.RemoveTeacher(oldTeacher);

    endRemoveRows();
}

void TableModel::PopulateModel(QString aFirstName, QString aLastName)
{
    int newRow = mContext.GetTeacherSize();

    beginInsertRows(QModelIndex(), newRow, newRow);//emit signal to notify view that a new row is inserted

    shared_ptr<Teacher> newTeacher = make_shared<Teacher>(aFirstName.toStdString(), aLastName.toStdString(),mContext.GenerateTeacherId());
    mContext.AddTeacher(newTeacher);

    endInsertRows();
}

void TableModel::ClearContent()
{
    if (mContext.GetTeacherSize() > 0) {
        beginRemoveRows(QModelIndex(), 0, mContext.GetTeacherSize()-1);//emit signal to notify view that a new row is removed
        mContext.DeleteTeachers();
        endRemoveRows();
    }
}


