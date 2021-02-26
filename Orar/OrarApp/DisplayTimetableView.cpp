#include "stdafx.h"
#include "DisplayTimetableView.h"
#include "ClassTableModel.h"
#include "Context.h"
#include "TimeTableViewModel.h"

DisplayTimetableView::DisplayTimetableView(ClassTableModel * alistModel,
                                           Context &         aContext,
                                           QWidget *         parent)
  : QWidget(parent)
  , mContext(aContext)
  , listModel(alistModel)
{
  ui.setupUi(this);

  tableModel = new TimeTableViewModel(mContext, this);

  ui.mTimeTableView->setModel(tableModel);
  ui.mGroupList->setModel(listModel);

  ui.mTimeTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTimeTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DisplayTimetableView::~DisplayTimetableView()
{
}
