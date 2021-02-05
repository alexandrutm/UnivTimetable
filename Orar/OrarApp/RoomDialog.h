#pragma once

#include "ui_RoomDialog.h"
#include <QDialog>

class RoomDialog
  : public QDialog
  , public Ui::RoomDialog
{
  Q_OBJECT

public:
  RoomDialog(QWidget * parent = Q_NULLPTR);
  ~RoomDialog();
};
