#include "stdafx.h"
#include "OrarApp.h"
#include "InstituteData.h"
#include "InstitutionDetailsDialog.h"
#include "TimeTableViewModel.h"
#include "TreeModelClasses.h"
#include "XmlParser.h "

OrarApp::OrarApp(QWidget * parent)
  : QMainWindow(parent)
  , mDataDialog(mContext, this)
  , mHomeView(this, this)

{
  ui.setupUi(this);

  // hide toolBar and menuBar on first page
  ui.toolBar->hide();
  ui.menuBar->hide();

  setCentralWidget(ui.centralStackWidget);
  ui.centralStackWidget->insertWidget(0, &mHomeView);
  ui.centralStackWidget->setCurrentIndex(0);

  // display results
  mTableModel = new TimeTableViewModel(this);
  ui.mTimeTableView->setModel(mTableModel);
  ui.mTimeTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTimeTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

  //
  mClassesModel = make_shared<TreeModel>(mContext, this);
  ui.mTreeView->setModel(mClassesModel.get());
  mDataDialog.AddTreeModel(mClassesModel);
}

OrarApp::~OrarApp()
{
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

void OrarApp::on_mSave_triggered()
{
  XmlParser data;

  QString fileName =
    QFileDialog::getSaveFileName(this, tr("Save data"), "", tr("Xml File (*.xml);;All Files (*)"));

  data.SaveData(mContext, (fileName.toStdString()));
}

void OrarApp::on_mOpen_triggered()
{
  XmlParser data;

  // choose which file to open
  auto fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Xml File (*.xml)"));
  data.LoadData(mContext, fileName.toStdString());

  // notify tableview about changes
  ui.mTreeView->resizeColumnToContents(0);
}

void OrarApp::on_mData_triggered()
{
  if (mDataDialog.exec())
  {
  }
}

void OrarApp::on_mGenerate_triggered()
{
  mTableModel->AddData((mContext.GetTimeTable()));

  // notify tableview about changes

  ui.mTimeTableView->repaint();
}

void OrarApp::on_mInstitutionData_triggered()
{
  InstitutionDetailsDialog institutionDialog = new InstitutionDetailsDialog(this);

  if (institutionDialog.exec())
  {
    QString name = institutionDialog.SchoolName->text();

    int hoursPerDay = institutionDialog.HoursPerDay->value();
    int startTime   = institutionDialog.mStartTime->value();
    int endTime     = institutionDialog.mEndTime->value();
    int daysPerWeek = institutionDialog.mDaysPerWeek->value();

    shared_ptr<InstituteData> InstitutionData =
      make_shared<InstituteData>(name.toStdString(), hoursPerDay, startTime, endTime, daysPerWeek);
    mContext.ChangeInstituteData(InstitutionData);
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

    // mTeacherView.ClearData();
    // mSubjectView.ClearData();
    // mClassView.ClearData();
    // mRoomView.ClearData();
    // mLessonView.ClearData();

    ui.toolBar->hide();
    ui.menuBar->hide();
  }
  else
  {
  }
}
