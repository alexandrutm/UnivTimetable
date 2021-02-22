#pragma once

class Classes;
class Context;

class TreeModel : public QAbstractItemModel
{
  Q_OBJECT

public:
  TreeModel(Context & aContext, QObject * parent = nullptr);
  ~TreeModel();

  QVariant data(const QModelIndex & index, int role) const override;
  QVariant headerData(int             section,
                      Qt::Orientation orientation,
                      int             role = Qt::DisplayRole) const override;

  int rowCount(const QModelIndex & parent = QModelIndex()) const override;
  int columnCount(const QModelIndex & parent = QModelIndex()) const override;

  Qt::ItemFlags flags(const QModelIndex & index) const override;
  bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;

  bool PopulateModel(QString aName, int NumberOfStudents, const QModelIndex & parent);
  bool removeRow(int aRowSelected, const QModelIndex & parent = QModelIndex());

  QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex()) const override;
  QModelIndex parent(const QModelIndex & index) const override;

private:
  Context &   mContext;
  QModelIndex rootItem;
};
