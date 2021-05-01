#pragma once

class SortFilterProxyModel : public QSortFilterProxyModel
{
  Q_OBJECT

public:
  SortFilterProxyModel(QObject * parent = 0);

protected:
  //  bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
  bool lessThan(const QModelIndex & left, const QModelIndex & right) const override;
};
