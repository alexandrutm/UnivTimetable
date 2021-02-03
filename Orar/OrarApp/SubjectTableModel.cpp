#include "stdafx.h"
#include "SubjectTableModel.h"
#include "Context.h"
#include "Subject.h"

SubjectTableModel::SubjectTableModel(Context& aContext, QObject* parent): QAbstractTableModel(parent), mContext(aContext) { }
int SubjectTableModel::rowCount(const QModelIndex& parent) const { return mContext.GetSubjectSize(); }

int SubjectTableModel::columnCount(const QModelIndex& parent) const { return 1; }

QVariant SubjectTableModel::data(const QModelIndex& index, int role) const
{
  if (!index.isValid() || role != Qt::DisplayRole) {
    return QVariant();
  }

  if (index.column() == 0) {
    QString Name;
    Name = QString::fromStdString((mContext.GetSubjectByIndex(index.row()))->GetName());
    return Name;
  }
  return QVariant();
}
QVariant SubjectTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
    if (section == 0) {
      return QString("Subject Name");
    }
  }
  return QVariant();
}

void SubjectTableModel::EditModel(int aRowSelected, QString aName)
{
  mContext.GetSubjectByIndex(aRowSelected)->SetName(aName.toStdString());

}

void SubjectTableModel::RemoveItemFromModel(int aRowSelected)
{
  beginRemoveRows(QModelIndex(), aRowSelected, aRowSelected); //emit signal to notify view that a new row is removed

  shared_ptr<Subject> oldSubject = mContext.GetSubjectByIndex(aRowSelected);
  mContext.RemoveSubject(oldSubject);

  endRemoveRows();
}

void SubjectTableModel::PopulateModel(QString aName)
{
  int newRow = mContext.GetSubjectSize();

  beginInsertRows(QModelIndex(), newRow, newRow); //emit signal to notify view that a new row is inserted

  shared_ptr<Subject> newSubject = make_shared<Subject>(aName.toStdString(), mContext.GenerateSubjectId());
  mContext.AddSubject(newSubject);

  endInsertRows();
}

void SubjectTableModel::ClearContent()
{
  if (mContext.GetSubjectSize() > 0) {
    beginRemoveRows(QModelIndex(), 0, mContext.GetSubjectSize() - 1); //emit signal to notify view that a new row is removed
    mContext.DeleteSubjects();
    endRemoveRows();
  }
}
