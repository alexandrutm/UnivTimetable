#pragma once

#include <QDialog>
#include "ui_RoomDialog.h"

class RoomDialog : public QDialog, public Ui::RoomDialog
{
	Q_OBJECT

public:
	RoomDialog(QWidget *parent = Q_NULLPTR);
	~RoomDialog();
};
