#pragma once

#include "ui_DisplayTimetableView.h"

class TimeTableViewModel;
class LessonTableModel;
class ClassTableModel;
class Context;

class DisplayTimetableView : public QWidget
{
  Q_OBJECT

public:
  DisplayTimetableView(Context & aContex, QWidget * parent = Q_NULLPTR);
  ~DisplayTimetableView();

private:
  Ui::DisplayTimetableView ui;

  TimeTableViewModel * timetableModel;
  //  ClassTableModel *    classTableModel;
  // LessonTableModel *   lessonTableModel;
  Context & mContext;
};
