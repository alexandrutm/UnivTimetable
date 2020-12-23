#pragma once

#include <QDialog>
#include "ui_SubjectDialog.h"

class SubjectDialog : public QDialog, public Ui::SubjectDialog
{
	Q_OBJECT

public:
	SubjectDialog(QWidget *parent = Q_NULLPTR);
	~SubjectDialog();
};
