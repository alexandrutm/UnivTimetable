#pragma once

#include "ui_ExportTimetableDialog.h"

class TreeModel;
class Context;

class ExportTimetableDialog : public QDialog
{
  Q_OBJECT

public:
  ExportTimetableDialog(Context &              aContext,
                        vector<vector<string>> aLessons,
                        shared_ptr<TreeModel>  aGroupModel,
                        QWidget *              parent = Q_NULLPTR);
  ~ExportTimetableDialog();

  vector<string> FilterData(vector<string> pattern);
  void           PrintTimetable(vector<string> aLessonsDetails);

private slots:

  void on_mPrint_clicked();

private:
  Ui::ExportTimetableDialog ui;

  Context &              mContext;
  vector<vector<string>> mTimetable;
  shared_ptr<TreeModel>  mGroupModel;
};
