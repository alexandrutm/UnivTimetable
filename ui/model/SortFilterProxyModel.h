#pragma once

class SortFilterProxyModel : public QSortFilterProxyModel
{
  Q_OBJECT

public:
  SortFilterProxyModel(QObject * parent = 0);

protected:
  bool lessThan(const QModelIndex & left, const QModelIndex & right) const override;
};
