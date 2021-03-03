#pragma once

#include "ui_DisplayTimetableView.h"

class TimeTableViewModel;
class TreeModel;
class Context;

class DisplayTimetableView : public QWidget
{
  Q_OBJECT

public:
  DisplayTimetableView(TreeModel * classesModel, Context & aContex, QWidget * parent = Q_NULLPTR);
  ~DisplayTimetableView();

private:
  Ui::DisplayTimetableView ui;

  TimeTableViewModel * tableModel;
  TreeModel *          mClassesModel;
  Context &            mContext;
};
