#pragma once

#include "ui_DisplayTimetableView.h"

class TimeTableViewModel;
class ClassTableModel;
class Context;

class DisplayTimetableView : public QWidget
{
  Q_OBJECT

public:
  DisplayTimetableView(ClassTableModel * listModelContext,
                       Context &         aContex,
                       QWidget *         parent = Q_NULLPTR);
  ~DisplayTimetableView();

private:
  Ui::DisplayTimetableView ui;

  TimeTableViewModel * tableModel;
  ClassTableModel *    listModel;
  Context &            mContext;
};
