#pragma once
#include "../src/interface/Observer.h"

class Context;

class RoomTableModel
  : public QAbstractTableModel
  , public Observer
{
  Q_OBJECT

public:
  RoomTableModel(Context & aContext, QObject * parent = nullptr);
  int      rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
  int      columnCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
  QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
  QVariant headerData(int             section,
                      Qt::Orientation orientation,
                      int             role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
  bool     setData(const QModelIndex & index, const QVariant & aName, int role) override;
  void     RemoveItemFromModel(int aRowSelected);
  void     PopulateModel(QString aName, int aCapacity, int aId);

  void ClearData();

  void   AddNewRow();
  void   Update(string aInstruction) override;
  string GetModelName() override;

private:
  Context & mContext;
};
