#pragma once
#include "../src/interface/Observer.h"

class Context;
class Lesson;

class LessonTableModel
  : public QAbstractTableModel
  , public Observer
{
  Q_OBJECT

public:
  LessonTableModel(Context & aContext, QObject * parent = nullptr);
  int      rowCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
  int      columnCount(const QModelIndex & parent = QModelIndex()) const Q_DECL_OVERRIDE;
  QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
  QVariant headerData(int             section,
                      Qt::Orientation orientation,
                      int             role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
  bool     setData(const QModelIndex & index, shared_ptr<Lesson> aLesson, int role);
  void     RemoveItemFromModel(int aRowSelected);
  void     PopulateModel(shared_ptr<Lesson> aLesson);

  void ClearContent();

  void   Update(string instruction) override;
  string GetModelName() override;
  void   AddNewRow();

private:
  Context & mContext;
};
