#pragma once

#include "ui_DisplayTimetableView.h"

class TimeTableViewModel;
class TreeModel;
class Context;
class Solution;

class DisplayTimetableView : public QWidget
{
  Q_OBJECT

public:
  DisplayTimetableView(Context & aContex, QWidget * parent = Q_NULLPTR);
  ~DisplayTimetableView();

  void PrintTimeTable(vector<string> aLessonsDetails);
  void AddTreeModel(shared_ptr<TreeModel> aTreeModel);

private:
  Ui::DisplayTimetableView ui;

  Context & mContext;

  TimeTableViewModel *  mTableModel;
  shared_ptr<TreeModel> mTreeModel;
};
