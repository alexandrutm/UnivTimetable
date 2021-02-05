#pragma once

#include "ui_RoomView.h"
#include <QWidget>

class Context;
class RoomTableModel;

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
  void on_mConstraints_clicked();

private:
  Ui::RoomView ui;

  RoomTableModel * tableModel;
  Context &        mContext;
};
