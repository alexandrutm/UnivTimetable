#include "stdafx.h"
#include "OrarApp.h"
#include "AddDataDialog.h"
#include "TimeTableView.h"

OrarApp::OrarApp(QWidget * parent)
  : QMainWindow(parent)
  , mDataDialog(this)
  , mHomeView(this, this)
  , mClassView(mContext, this)
  , mSubjectView(mContext, this)
  , mRoomView(mContext, this)
  , mTeacherView(mContext, this)
  , mLessonView(mContext, this)
  , mInstituteDataView(mContext, this)

{
  ui.setupUi(this);

  modelTimeTable = new TimeTableView(mContext, this);
  ui.toolBar->hide();
  ui.menuBar->hide();

  ui.mTimeTableView->setModel(modelTimeTable);

  QHeaderView * header = ui.mTimeTableView->horizontalHeader();
  header->setSectionResizeMode(QHeaderView::Stretch);

  mDataDialog.mData->addTab(&mInstituteDataView, "School");
  mDataDialog.mData->addTab(&mSubjectView, "Subjects");
  mDataDialog.mData->addTab(&mClassView, "Classes");
  mDataDialog.mData->addTab(&mRoomView, "Rooms");
  mDataDialog.mData->addTab(&mTeacherView, "Teachers");
  mDataDialog.mData->addTab(&mLessonView, "Lessons");

  setCentralWidget(ui.centralStackWidget);

  ui.centralStackWidget->insertWidget(0, &mHomeView);
  ui.centralStackWidget->setCurrentIndex(0);
}

void OrarApp::ChangeView(INavigator::viewId theView)
{
  if (theView == INavigator::viewId::homepage)
  {
    ui.centralStackWidget->setCurrentIndex(0);
  }
  else if (theView == INavigator::viewId::mainPage)
  {
    ui.centralStackWidget->setCurrentIndex(1);
    ui.toolBar->show();
    ui.menuBar->show();
  }
}

void OrarApp::ChangeStatus(string aStatus)
{
  ui.statusBar->showMessage(QString::fromStdString(aStatus), 5000);
}

void OrarApp::on_mData_triggered()
{
  if (mDataDialog.exec())
  {
  }
}

void OrarApp::on_mNew_triggered()
{
  QMessageBox::StandardButton replay = QMessageBox::question(
    this, "New Timetable", "You lose all data", QMessageBox::Yes | QMessageBox::No);

  if (replay == QMessageBox::Yes)
  {
    // delete data from context and from all models
    ui.centralStackWidget->setCurrentIndex(0);
    mTeacherView.ClearData();
    mSubjectView.ClearData();
    mLessonView.ClearData();
    mClassView.ClearData();
    mRoomView.ClearData();
    ui.toolBar->hide();
    ui.menuBar->hide();
  }
  else
  {
  }
}
