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
  DisplayTimetableView(TreeModel * classesModel, Context & aContex, QWidget * parent = Q_NULLPTR);
  ~DisplayTimetableView();

  void PrintTimeTable(vector<string> aLessonsDetails);

private:
  Ui::DisplayTimetableView ui;

  TimeTableViewModel * mTableModel;
  TreeModel *          mTreeModel;
  Context &            mContext;
};
