#pragma once
#include <QAbstractTableModel>

class Context;
class RoomTableModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	RoomTableModel(Context& aContext, QObject* parent = nullptr);
	int rowCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;
	int columnCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

	void EditModel(int aRowSelected, QString aName);
	void RemoveItemFromModel(int aRowSelected);
	void PopulateModel(QString aName);

private:

	Context& mContext;

};
