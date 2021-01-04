#pragma once

#include <QDialog>
#include "ui_TeacherDialog.h"

class TeacherDialog : public QDialog, public Ui::TeacherDialog
{
	Q_OBJECT

public:
	TeacherDialog(QWidget *parent = Q_NULLPTR);
	~TeacherDialog();
};
