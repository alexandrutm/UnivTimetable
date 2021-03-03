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
  , mClassesModel(aTreeModel)
{
  ui.setupUi(this);

  tableModel = new TimeTableViewModel(mContext, this);

  ui.mTimeTableView->setModel(tableModel);
  ui.mTreeView->setModel(mClassesModel);

  ui.mTimeTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTimeTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DisplayTimetableView::~DisplayTimetableView()
{
}
