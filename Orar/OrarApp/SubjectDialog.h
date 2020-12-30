#pragma once

#include <QDialog>
#include "ui_SubjectDialog.h"

class SubjectDialog : public QDialog, public Ui::SubjectDialog
{
	Q_OBJECT

private slots:
	void on_Name_textChanged();

public:
	SubjectDialog(QWidget *parent = Q_NULLPTR);
	~SubjectDialog();
};
