#include "stdafx.h"
#include "DisplayTimetableView.h"
#include "Context.h"
#include "TimeTableViewModel.h"

DisplayTimetableView::DisplayTimetableView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);

  tableModel = new TimeTableViewModel(mContext, this);
  ui.mTimeTableView->setModel(tableModel);

  ui.mTimeTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTimeTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DisplayTimetableView::~DisplayTimetableView()
{
}
