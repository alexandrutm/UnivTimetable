#pragma once

class Context;

class ConstraintListModel : public QAbstractListModel
{
  Q_OBJECT

public:
  ConstraintListModel(Context & aContext, QObject * parent = nullptr);

  int      rowCount(const QModelIndex & parent = QModelIndex()) const override;
  QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;
  bool     insertRows(int position, int rows, const QModelIndex & index = QModelIndex()) override;
  bool     removeRows(int position, int rows, const QModelIndex & index = QModelIndex()) override;

private:
  Context & mContext;
};
