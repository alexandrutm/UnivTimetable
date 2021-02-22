#include "stdafx.h"
#include "OrarApp.h"
#include "AddDataDialog.h"

OrarApp::OrarApp(QWidget * parent)
  : QMainWindow(parent)
  , mDataDialog(this)
  , mHomeView(mContext, this, this)
  , mClassView(mContext, this)
  , mSubjectView(mContext, this)
  , mRoomView(mContext, this)
  , mTeacherView(mContext, this)
  , mLessonView(mContext, this)
  , mDisplayTimeTableView(mContext, this)

{
  ui.setupUi(this);

  // hide toolBar and menuBar on first page
  ui.toolBar->hide();
  ui.menuBar->hide();

  // Basic data Dialog
  mDataDialog.mData->addTab(&mSubjectView, "Subjects");
  mDataDialog.mData->addTab(&mClassView, "Classes");
  mDataDialog.mData->addTab(&mRoomView, "Rooms");
  mDataDialog.mData->addTab(&mTeacherView, "Teachers");
  mDataDialog.mData->addTab(&mLessonView, "Lessons");

  setCentralWidget(ui.centralStackWidget);
  ui.centralStackWidget->insertWidget(0, &mHomeView);
  ui.centralStackWidget->insertWidget(1, &mDisplayTimeTableView);
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
    mClassView.ClearData();
    mRoomView.ClearData();
    mLessonView.ClearData();

    ui.toolBar->hide();
    ui.menuBar->hide();
  }
}
