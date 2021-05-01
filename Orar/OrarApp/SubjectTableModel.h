#pragma once
#include "Observer.h"
class Context;

class SubjectTableModel
  : public QAbstractTableModel
  , public Observer
{
  Q_OBJECT

public:
  SubjectTableModel(Context & aContext, QObject * parent = nullptr);
  int      rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
  int      columnCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
  QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
  QVariant headerData(int             section,
                      Qt::Orientation orientation,
                      int             role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
  bool     SubjectTableModel::setData(const QModelIndex & index,
                                  const QVariant &    aName,
                                  int                 role) override;

  void RemoveItemFromModel(int aRowSelected);
  void PopulateModel(QString aFirstName, int aId);

  void ClearContent();

  void   AddNewRow();
  void   Update(string aInstruction) override;
  string GetModelName() override;

private:
  Context & mContext;
};
