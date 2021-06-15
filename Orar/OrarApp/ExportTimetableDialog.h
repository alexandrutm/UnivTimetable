#pragma once

#include "ui_ExportTimetableDialog.h"

class TreeModel;
class Context;

class ExportTimetableDialog : public QDialog
{
  Q_OBJECT

public:
  ExportTimetableDialog(Context &             aContext,
                        shared_ptr<TreeModel> aGroupModel,
                        QWidget *             parent = Q_NULLPTR);
  ~ExportTimetableDialog();

private slots:

  void on_mPrint_clicked();

private:
  Ui::ExportTimetableDialog ui;

  Context &             mContext;
  shared_ptr<TreeModel> mGroupModel;
};
