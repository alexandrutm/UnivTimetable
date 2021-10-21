#include "stdafx.h"
#include "ui/model/SubjectTableModel.h"
#include "src/containers/Context.h"
#include "src/containers/Subject.h"

SubjectTableModel::SubjectTableModel(Context & aContext, QObject * parent)
  : QAbstractTableModel(parent)
  , mContext(aContext)
{
  mModelName = "subjectmodel";
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
    return QString::fromStdString((mContext.GetSubjectByIndex(index.row()))->GetName());
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

void SubjectTableModel::PopulateModel(QString aName, int aId)
{
  int newRow = static_cast<int>(mContext.GetSubjectSize());

  beginInsertRows(QModelIndex(), newRow, newRow);

  shared_ptr<Subject> newSubject = make_shared<Subject>(aName.toStdString(), aId);
  mContext.AddSubject(newSubject);

  endInsertRows();
}

void SubjectTableModel::ClearContent()
{
  if (mContext.GetSubjectSize() > 0)
  {
    beginRemoveRows(QModelIndex(), 0, static_cast<int>(mContext.GetSubjectSize()) - 1);

    mContext.DeleteSubjects();

    endRemoveRows();
  }
}

void SubjectTableModel::AddNewRow()
{
  if (mContext.GetSubjectSize() == 0)
    return;

  int newRow = static_cast<int>(mContext.GetSubjectSize()) - 1;

  beginInsertRows(QModelIndex(), newRow, newRow);
  endInsertRows();
}

void SubjectTableModel::Update(string aInstruction)
{
  if (aInstruction == "addnewrow")
    AddNewRow();
  else if (aInstruction == "cleardata")
  {
    beginResetModel();
    mContext.DeleteSubjects();
    endResetModel();
  }
}

string SubjectTableModel::GetModelName()
{
  return mModelName;
}
