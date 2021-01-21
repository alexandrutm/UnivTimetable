#include "stdafx.h"
#include "LessonTableModel.h"
#include"Context.h"
#include"Lesson.h"
#include"Teacher.h"
#include"Subject.h"
#include"Classes.h"
#include"Room.h"

LessonTableModel::LessonTableModel(Context& aContext, QObject* parent)
    :QAbstractTableModel(parent), mContext(aContext)
{

}


int LessonTableModel::rowCount(const QModelIndex& parent) const
{
    return mContext.GetLessonSize();

}

int LessonTableModel::columnCount(const QModelIndex& parent) const
{
    return 4;
}

QVariant LessonTableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if (index.column() == 0) {
        auto teacher = mContext.GetLessonByIndex(index.row())->GetTeacher();
        QString aName;
        aName = QString::fromStdString(teacher->GetFirstName());
        return aName;
    }
    else if(index.column() == 1)
    {
        auto subject = mContext.GetLessonByIndex(index.row())->GetSubject();
        QString aName;
        aName = QString::fromStdString(subject->GetName());
        return aName;
    }
    else if(index.column() == 2)
    {
        auto className = mContext.GetLessonByIndex(index.row())->GetClass();
        QString aName;
        aName = QString::fromStdString(className->GetName());
        return aName;
    }
    else if (index.column() == 3)
    {
        return mContext.GetLessonByIndex(index.row())->GetNumberOfHours();
    }
    return QVariant();
}

QVariant LessonTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("Teacher Name");
        }
        else if (section == 1) {
            return QString("Subject");
        }
        else if (section == 2) {
            return QString("Class");
        }
        else if (section == 3) {
            return QString("Hours per week");
        }
    }
    return QVariant();
}

void LessonTableModel::EditModel(int rowSelected, shared_ptr<Lesson> aLesson)
{

    shared_ptr<Lesson> oldLesson = mContext.GetLessonByIndex(rowSelected);

    mContext.EditLesson(oldLesson,aLesson);

}

void LessonTableModel::RemoveItemFromModel(int aRowSelected)
{
    beginRemoveRows(QModelIndex(), aRowSelected, aRowSelected);//emit signal to notify view that a row is removed

    shared_ptr<Lesson> aLesson = mContext.GetLessonByIndex(aRowSelected);
    mContext.RemoveLesson(aLesson);

    endRemoveRows();
}

void LessonTableModel::PopulateModel(shared_ptr<Lesson> aLesson)
{
    int newRow = mContext.GetLessonSize();

    beginInsertRows(QModelIndex(), newRow, newRow);//emit signal to notify view that a new row is inserted

    mContext.AddLesson(aLesson);

    endInsertRows();
}

void LessonTableModel::ClearContent()
{
    if (mContext.GetLessonSize() > 0) {
        beginRemoveRows(QModelIndex(), 0, mContext.GetLessonSize()-1);
        mContext.DeleteLessons();
        endRemoveRows();
    }
}

