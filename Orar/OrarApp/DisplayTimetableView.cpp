#include "stdafx.h"
#include "DisplayTimetableView.h"
#include "Context.h"
#include "TimeTableViewModel.h"
#include "TreeModel.h"

DisplayTimetableView::DisplayTimetableView(TreeModel * aTreeModel,
                                           Context &   aContext,
                                           QWidget *   parent)
  : QWidget(parent)
  , mContext(aContext)
  , mTreeModel(aTreeModel)
{
  ui.setupUi(this);

  mTableModel = new TimeTableViewModel(mContext, this);

  ui.mTimeTableView->setModel(mTableModel);
  ui.mTreeView->setModel(mTreeModel);

  ui.mTimeTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTimeTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DisplayTimetableView::~DisplayTimetableView()
{
  delete mTableModel;
}
