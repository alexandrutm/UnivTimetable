#include "stdafx.h"
#include "DisplayTimetableView.h"
#include "Context.h"
#include "Lesson.h"
#include "TimeTableViewModel.h"
#include "TreeModelClasses.h"

DisplayTimetableView::DisplayTimetableView(TreeModel * aTreeModel,
                                           Context &   aContext,
                                           QWidget *   parent)
  : QWidget(parent)
  , mContext(aContext)
  , mTreeModel(aTreeModel)
{
  ui.setupUi(this);

  mTableModel = new TimeTableViewModel(this);

  ui.mTimeTableView->setModel(mTableModel);
  ui.mTreeView->setModel(mTreeModel);

  ui.mTimeTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTimeTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DisplayTimetableView::~DisplayTimetableView()
{
  delete mTableModel;
}

void DisplayTimetableView::PrintTimeTable(vector<string> aLessonsDetails)
{
  mTableModel->AddData(aLessonsDetails);
}
