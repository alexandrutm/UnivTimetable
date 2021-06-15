#include "stdafx.h"
#include "OrarApp.h"
#include "ExportTimetableDialog.h"
#include "Group.h"
#include "InstituteData.h"
#include "InstitutionDetailsDialog.h"
#include "SortFilterProxyModel.h"
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

  CreateModels();

  connect(ui.mTreeView->selectionModel(), &QItemSelectionModel::currentChanged, this,
          &OrarApp::ClassChanged);
}

void OrarApp::CreateModels()
{
  mTableModel = make_unique<TimeTableViewModel>();

  ui.mTimeTableView->setModel(mTableModel.get());

  ui.mTimeTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  ui.mTimeTableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

  mGroupModel = make_shared<TreeModel>(mContext, this);
  ui.mTreeView->setModel(mGroupModel.get());
  mDataDialog.AddTreeModel(mGroupModel);
}

OrarApp::~OrarApp()
{
}

void OrarApp::ChangeView(INavigator::viewId theView)
{
  if (theView == INavigator::viewId::homepage)
  {
    //   ui.centralStackWidget->setCurrentIndex(0);
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

void OrarApp::ClassChanged()
{
  auto indexRowSelected = ui.mTreeView->selectionModel()->currentIndex();

  if (!indexRowSelected.isValid())
  {
    QMessageBox::about(this, "No Class Selected", "Please choose a class");
    return;
  }

  QModelIndex nameIndex = mGroupModel->index(indexRowSelected.row(), 0, indexRowSelected.parent());

  auto parentGroup = mGroupModel->getItem(nameIndex);

  mTableModel->FilterData(mContext.GetGroupsNameToFilter(parentGroup));
  ui.mTimeTableView->repaint();
}

void OrarApp::on_mSave_triggered()
{
  XmlParser data;

  QString fileName = QFileDialog::getSaveFileName(this, tr("Save data"), "",
                                                  tr("Orar File (*.orar);;All Files (*)"));

  data.SaveData(mContext, (fileName.toStdString()));
}

void OrarApp::on_mOpen_triggered()
{
  XmlParser data;

  // choose which file to open
  auto fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Orar File (*.orar)"));
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
  if (mContext.GetLessonSize() == 0)
  {
    QMessageBox::information(this, "Insert lessons",
                             "Please insert lessons before generate timetable");
    return;
  }

  // check if we have a generated timetable
  if (mContext.IsTimetableGenerated())
  {
    // already have a timetable generated-> delete lesson placement and generated another timetable
    mContext.DeleteLessonsPlacements();
    mTableModel->AddData((mContext.GetTimeTable()));
  }
  else
  {
    mTableModel->AddData((mContext.GetTimeTable()));
  }
  // notify tableview about changes

  ui.mTimeTableView->repaint();
}

void OrarApp::on_mExport_triggered()
{
  if (!mContext.IsTimetableGenerated())
    return;

  auto exportTimetable =
    make_unique<ExportTimetableDialog>(mContext, mTableModel->GetTiemtableData(), mGroupModel);

  if (exportTimetable->exec())
  {
  }
}

void OrarApp::on_mInstitutionData_triggered()
{
  auto institutionDialog = make_unique<InstitutionDetailsDialog>();

  if (institutionDialog->exec())
  {
    QString name = institutionDialog->SchoolName->text();

    int hoursPerDay = institutionDialog->HoursPerDay->value();
    int startTime   = institutionDialog->mStartTime->value();
    int endTime     = institutionDialog->mEndTime->value();
    int daysPerWeek = institutionDialog->mDaysPerWeek->value();

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

    mContext.DeleteData();
    mTableModel->ClearData();

    ui.toolBar->hide();
    ui.menuBar->hide();
  }
  else
  {
  }
}
