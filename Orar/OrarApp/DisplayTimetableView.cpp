#include "stdafx.h"
#include "DisplayTimetableView.h"
#include "Context.h"
#include "Lesson.h"
#include "TimeTableViewModel.h"
#include "TreeModelClasses.h"

DisplayTimetableView::DisplayTimetableView(Context & aContext, QWidget * parent)
  : QWidget(parent)
  , mContext(aContext)
{
  ui.setupUi(this);

  mTableModel = new TimeTableViewModel(this);

  ui.mTimeTableView->setModel(mTableModel);

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

void DisplayTimetableView::AddTreeModel(shared_ptr<TreeModel> aTreeModel)
{
  mTreeModel = aTreeModel;
  ui.mTreeView->setModel(mTreeModel.get());
}

void DisplayTimetableView::Update()
{
  ui.mTreeView->resizeColumnToContents(0);
  ui.mTimeTableView->repaint();
}
