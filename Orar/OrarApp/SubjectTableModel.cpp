#include "stdafx.h"
#include "SubjectTableModel.h"
#include "Context.h"
#include "Subject.h"

SubjectTableModel::SubjectTableModel(Context & aContext, QObject * parent)
  : QAbstractTableModel(parent)
  , mContext(aContext)
{
}
int SubjectTableModel::rowCount(const QModelIndex & /*parent*/) const
{
  return static_cast<int>(mContext.GetSubjectSize());
}

int SubjectTableModel::columnCount(const QModelIndex & /*parent*/) const
{
  return 1;
}

QVariant SubjectTableModel::data(const QModelIndex & index, int role) const
{
  if (!index.isValid() || role != Qt::DisplayRole)
  {
    return QVariant();
  }

  if (index.column() == 0)
  {
    QString Name;
    Name = QString::fromStdString((mContext.GetSubjectByIndex(index.row()))->GetName());
    return Name;
  }
  return QVariant();
}

QVariant SubjectTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
  {
    if (section == 0)
    {
      return QString("Subject Name");
    }
  }
  return QVariant();
}

bool SubjectTableModel::setData(const QModelIndex & index, const QVariant & aName, int role)
{
  if (index.isValid() && role == Qt::EditRole)
  {
    auto subject = mContext.GetSubjectByIndex(index.row());

    switch (index.column())
    {
    case 0:
      subject->SetName((aName.toString()).toStdString());
      break;
    default:
      return false;
    }

    emit dataChanged(index, index, { Qt::DisplayRole, Qt::EditRole });

    return true;
  }

  return false;
}

void SubjectTableModel::RemoveItemFromModel(int aRowSelected)
{
  beginRemoveRows(QModelIndex(), aRowSelected, aRowSelected);

  mContext.RemoveSubject(aRowSelected);

  endRemoveRows();
}

void SubjectTableModel::PopulateModel(QString aName)
{
  int newRow = static_cast<int>(mContext.GetSubjectSize());

  beginInsertRows(QModelIndex(), newRow, newRow);

  shared_ptr<Subject> newSubject =
    make_shared<Subject>(aName.toStdString(), mContext.GenerateSubjectId());
  mContext.AddSubject(newSubject);

  endInsertRows();
}

void SubjectTableModel::ClearContent()
{
  int subjectSize = static_cast<int>(mContext.GetSubjectSize());
  if (subjectSize > 0)
  {
    beginRemoveRows(QModelIndex(), 0, subjectSize - 1);

    mContext.DeleteSubjects();

    endRemoveRows();
  }
}
