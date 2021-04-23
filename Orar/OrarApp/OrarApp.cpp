#include "stdafx.h"
#include "OrarApp.h"
#include "AddDataDialog.h"
#include "AppData.h"
#include "DisplayTimetableView.h"
#include "InstitutionDetailsDialog.h"
#include "Solution.h"
#include "Solver.h"
#include "TransformLessonDetails.h"
#include "TreeModelClasses.h"
#include "tinyxml/tinyxml.h"

OrarApp::OrarApp(QWidget * parent)
  : QMainWindow(parent)
  , mClassesModel(new TreeModel(mContext, this))
  , mDataDialog(this)
  , mHomeView(this, this)
  , mClassView(mClassesModel, mContext, this)
  , mSubjectView(mContext, this)
  , mRoomView(mContext, this)
  , mTeacherView(mContext, this)
  , mLessonView(mContext, this)
  , mDisplayTimeTableView(mClassesModel, mContext, this)
  , mConstraintsView(mContext, this)

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
  mDataDialog.mData->addTab(&mConstraintsView, "Constraints");

  setCentralWidget(ui.centralStackWidget);
  ui.centralStackWidget->insertWidget(0, &mHomeView);
  ui.centralStackWidget->insertWidget(1, &mDisplayTimeTableView);
  ui.centralStackWidget->setCurrentIndex(0);
}

OrarApp::~OrarApp()
{
  delete mClassesModel;
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
  AppData data;
  QString text = QInputDialog::getText(this, "Save data", "Give a name to this data set");

  data.SaveData(mContext, (text.toStdString() + ".xml"));
}

void OrarApp::on_mData_triggered()
{
  if (mDataDialog.exec())
  {
  }
}

void OrarApp::on_mGenerate_triggered()
{
  TransformLessonDetails lessonDetails;
  Solver                 solver = Solver(mContext);

  Solution * solution = solver.FindSolution();

  mDisplayTimeTableView.PrintTimeTable(
    lessonDetails.GetLessonDetails(mContext.GetInstituteData(), solution));
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

void OrarApp::on_mImport_data_triggered()
{
  // select witch document to import
  string filename = "context.xml";

  TiXmlDocument doc(filename.c_str());
  if (!doc.LoadFile())
    return;

  TiXmlHandle    hDoc(&doc);
  TiXmlElement * pElem;
  TiXmlHandle    hRoot(0);

  {
    pElem = hDoc.FirstChildElement().Element();
    if (!pElem)
      return;
    // save this for later
    hRoot = TiXmlHandle(pElem);
  }

  // block: InstitutionDetails
  {
    TiXmlElement * institData = hRoot.FirstChildElement().Element();

    int dayWeek;
    int hourDay;
    int startHour;
    int endHour;

    string name = institData->Attribute("name");
    institData->QueryIntAttribute("nrOfDaysPerWeek", &dayWeek);
    institData->QueryIntAttribute("nrOfHoursPerDay", &hourDay);
    institData->QueryIntAttribute("startHour", &startHour);
    institData->QueryIntAttribute("endHour", &endHour);

    shared_ptr<InstituteData> instituteData =
      make_shared<InstituteData>(name, hourDay, startHour, endHour, dayWeek);
    mContext.ChangeInstituteData(instituteData);
  }

  // block Subjects
  {
    TiXmlElement * subject = hRoot.FirstChild("Subjects").FirstChild().Element();
    int            id;
    while (subject)
    {
      string name = subject->Attribute("name");
      subject->QueryIntAttribute("id", &id);

      mSubjectView.AddSubject(name, id);

      subject = subject->NextSiblingElement();
    }
  }

  // block Teachers
  {
    TiXmlElement * teacher = hRoot.FirstChild("Teachers").FirstChild().Element();
    int            id;

    while (teacher)
    {
      string fname = teacher->Attribute("fname");
      string lname = teacher->Attribute("lname");
      teacher->QueryIntAttribute("id", &id);

      mTeacherView.AddTeacher(fname, lname, id);

      teacher = teacher->NextSiblingElement();
    }
  }

  // block room
  {
    TiXmlElement * room = hRoot.FirstChild("Rooms").FirstChild().Element();
    int            id;
    int            capacity;

    while (room)
    {
      string name = room->Attribute("name");
      room->QueryIntAttribute("capacity", &capacity);
      room->QueryIntAttribute("id", &id);

      mRoomView.AddRoom(name, capacity, id);

      room = room->NextSiblingElement();
    }
  }

  // block groups
  {
    TiXmlElement * group = hRoot.FirstChild("Groups").FirstChild().Element();
    struct groupStructure
    {
      int    id;
      int    numberOfStud;
      string fname;
      int    parentId;
    };
    vector<groupStructure> theGroups;

    while (group)
    {
      groupStructure currentGroup;
      currentGroup.fname = group->Attribute("name");
      group->QueryIntAttribute("nrStudents", &currentGroup.numberOfStud);
      group->QueryIntAttribute("id", &currentGroup.id);
      group->QueryIntAttribute("parentId", &currentGroup.parentId);

      theGroups.push_back(currentGroup);

      group = group->NextSiblingElement();
    }

    sort(theGroups.begin(), theGroups.end(), [](auto first, auto second) {
      return first.parentId < second.parentId;
    });

    for (auto currentGroup : theGroups)
    {
      mClassView.AddClass(currentGroup.fname, currentGroup.numberOfStud, currentGroup.id,
                          currentGroup.parentId);
    }
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
  else
  {
  }
}
