#include "stdafx.h"
#include "DisplayTimetableView.h"
//#include "ClassTableModel.h"
#include "Context.h"
//#include "LessonTableModel.h"
#include "TimeTableViewModel.h"

DisplayTimetableView::DisplayTimetableView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);

  timetableModel = new TimeTableViewModel(mContext, this);
  ui.mTimeTableView->setModel(timetableModel);

  QHeaderView * header = ui.mTimeTableView->horizontalHeader();
  header->setSectionResizeMode(QHeaderView::Stretch);

  ui.mTimeTableView->setSpan(0, 0, 2, timetableModel->columnCount());
  ui.mTimeTableView->setSpan(2, 0, 2, timetableModel->columnCount());
  ui.mTimeTableView->setSpan(4, 0, 2, timetableModel->columnCount());
  ui.mTimeTableView->setSpan(6, 0, 2, timetableModel->columnCount());
}

DisplayTimetableView::~DisplayTimetableView()
{
}
