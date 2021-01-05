#pragma once

#include <QDialog>
#include "ui_LessonDialog.h"

class Context;

class LessonDialog : public QDialog, public Ui::LessonDialog
{
	Q_OBJECT

public:
	LessonDialog(Context& aContext,QWidget *parent = Q_NULLPTR);
	~LessonDialog();

private:
	Context& mContext;
};
