#pragma once

#include "ui_RoomView.h"

class Context;
class RoomTableModel;
class SortFilterProxyModel;

class RoomView : public QWidget
{
  Q_OBJECT

public:
  RoomView(Context &, QWidget * parent = Q_NULLPTR);
  ~RoomView();
  void ClearData();

private slots:
  void on_mAdd_clicked();
  void on_mEdit_clicked();
  void on_mDelete_clicked();

private:
  Ui::RoomView ui;
  Context &    mContext;

  shared_ptr<RoomTableModel>       tableModel;
  unique_ptr<SortFilterProxyModel> proxyModel;
};
