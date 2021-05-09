#pragma once

#include "Observer.h"
class Context;

class TeacherTableModel
  : public QAbstractTableModel
  , public Observer
{
  Q_OBJECT

public:
  TeacherTableModel(Context & aContext, QObject * parent = nullptr);
  int      rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
  int      columnCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
  QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
  QVariant headerData(int             section,
                      Qt::Orientation orientation,
                      int             role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
  bool     setData(const QModelIndex & index, const QVariant & aName, int role) override;

  bool removeRows(int position, int rows, const QModelIndex & index = QModelIndex()) override;

  void PopulateModel(string, string, int);

  void   AddNewRow();
  void   Update(string aInstruction) override;
  string GetModelName() override;

  void ClearContent();

private:
  Context & mContext;
};
