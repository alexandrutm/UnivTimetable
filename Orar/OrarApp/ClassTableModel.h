#pragma once
#include <QAbstractTableModel>

class Context;

class ClassTableModel : public QAbstractTableModel
{
  Q_OBJECT

public:
  ClassTableModel(Context & aContext, QObject * parent = nullptr);
  int      rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
  int      columnCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
  QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
  QVariant headerData(int             section,
                      Qt::Orientation orientation,
                      int             role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
  bool     setData(const QModelIndex & index, const QVariant & aName, int role) override;
  bool     insertRows(int position, int rows, const QModelIndex & index = QModelIndex()) override;
  bool     removeRows(int position, int rows, const QModelIndex & index = QModelIndex()) override;

  void RemoveItemFromModel(int aRowSelected);
  void PopulateModel(QString aName, int aNrOfStudents);

  void ClearData();

private:
  Context & mContext;
};
