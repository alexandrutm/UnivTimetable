#include "stdafx.h"
#include "XmlParser.h"
#include "Context.h"
#include "Group.h"
#include "InstituteData.h"
#include "Lesson.h"
#include "Room.h"
#include "Subject.h"
#include "Teacher.h"
#include "tinyxml/tinyxml.h"

// save data functions
auto XmlParser::SaveInstituteData(Context & aContext)
{
  auto institutionNode = make_unique<TiXmlElement>("Institution");

  auto institutionData = aContext.GetInstituteData();

  institutionNode->SetAttribute("name", institutionData->GetSchoolName().c_str());
  institutionNode->SetAttribute("nrOfHoursPerDay", institutionData->GetNumberOfHoursPerDay());
  institutionNode->SetAttribute("startHour", institutionData->GetStartHour());
  institutionNode->SetAttribute("endHour", institutionData->GetStartHour() +
                                             institutionData->GetNumberOfHoursPerDay());
  institutionNode->SetAttribute("nrOfDaysPerWeek", institutionData->GetNumberOfDaysPerWeek());

  return institutionNode.release();
}

auto XmlParser::SaveSubjects(Context & aContext)
{
  auto subjectNode = make_unique<TiXmlElement>("Subjects");

  auto subjects = aContext.GetSubjects();

  for (auto subject : subjects)
  {
    auto subjectElement = make_unique<TiXmlElement>("Subject");

    subjectElement->SetAttribute("name", subject->GetName().c_str());
    subjectElement->SetAttribute("id", subject->GetId());

    subjectNode->LinkEndChild(subjectElement.release());
  }

  return subjectNode.release();
}

auto XmlParser::SaveTeachers(Context & aContext)
{
  auto teacherNode = make_unique<TiXmlElement>("Teachers");

  auto teachers = aContext.GetTeachers();

  for (auto teacher : teachers)
  {
    auto teacherElement = make_unique<TiXmlElement>("Teacher");

    teacherElement->SetAttribute("fname", teacher->GetFirstName().c_str());
    teacherElement->SetAttribute("lname", teacher->GetLastName().c_str());
    teacherElement->SetAttribute("id", teacher->GetId());

    teacherNode->LinkEndChild(teacherElement.release());
  }
  return teacherNode.release();
}

auto XmlParser::SaveRooms(Context & aContext)
{
  auto roomNode = make_unique<TiXmlElement>("Rooms");

  auto rooms = aContext.GetRooms();

  for (auto room : rooms)
  {
    auto roomElement = make_unique<TiXmlElement>("Room");

    roomElement->SetAttribute("name", room->GetName().c_str());
    roomElement->SetAttribute("capacity", room->GetCapacity());
    roomElement->SetAttribute("id", room->GetId());
    roomNode->LinkEndChild(roomElement.release());
  }
  return roomNode.release();
}

auto XmlParser::SaveGroups(Context & aContext)
{
  auto groupNode = make_unique<TiXmlElement>("Groups");

  queue<Group *> treeNodes;

  treeNodes.push(aContext.GetRootGroup());

  while (!treeNodes.empty())
  {
    auto frontNode = treeNodes.front();
    treeNodes.pop();

    auto groupElement = make_unique<TiXmlElement>("Group");

    groupElement->SetAttribute("name", frontNode->GetName().c_str());
    groupElement->SetAttribute("nrStudents", frontNode->GetNumberOfStudents());
    groupElement->SetAttribute("id", frontNode->GetId());

    if (frontNode->GetParent() != nullptr)
      groupElement->SetAttribute("parentId", frontNode->GetParent()->GetId());
    else
      groupElement->SetAttribute("parentId", -1);

    for (int i = 0; i < frontNode->GetChildrenSize(); i++)
      treeNodes.push(frontNode->GetChild(i));

    groupNode->LinkEndChild(groupElement.release());
  }

  return groupNode.release();
}

auto XmlParser::SaveLessons(Context & aContext)
{
  auto lessonNode = make_unique<TiXmlElement>("Lessons");

  auto lessons = aContext.GetLessons();

  for (auto lesson : lessons)
  {
    auto lessonElement = make_unique<TiXmlElement>("Lesson");

    lessonElement->SetAttribute("teacherId", lesson->GetTeacher()->GetId());
    lessonElement->SetAttribute("subjectId", lesson->GetSubject()->GetId());
    lessonElement->SetAttribute("groupId", lesson->GetGroup()->GetId());
    lessonElement->SetAttribute("lessonLength", lesson->GetDuration());
    lessonElement->SetAttribute("lessonId", lesson->GetId());

    lessonNode->LinkEndChild(lessonElement.release());
  }

  return lessonNode.release();
}

void XmlParser::SaveData(Context & aContext, string aFileName)
{
  if (aFileName.empty())
    return;

  TiXmlDocument doc;
  auto          decl = make_unique<TiXmlDeclaration>("1.0", "", "");
  doc.LinkEndChild(decl.release());

  auto root = make_unique<TiXmlElement>("Context");

  root->LinkEndChild(SaveInstituteData(aContext));
  root->LinkEndChild(SaveSubjects(aContext));
  root->LinkEndChild(SaveTeachers(aContext));
  root->LinkEndChild(SaveRooms(aContext));
  root->LinkEndChild(SaveGroups(aContext));
  root->LinkEndChild(SaveLessons(aContext));

  doc.LinkEndChild(root.release());

  doc.SaveFile(aFileName.c_str());
}

// load data functions
void XmlParser::LoadInstituteData(Context & aContext, TiXmlHandle & hRoot)
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
  aContext.ChangeInstituteData(instituteData);
}

void XmlParser::LoadSubjects(Context & aContext, TiXmlHandle & hRoot)
{
  TiXmlElement * subject = hRoot.FirstChild("Subjects").FirstChild().Element();
  int            id;
  while (subject)
  {
    string name = subject->Attribute("name");
    subject->QueryIntAttribute("id", &id);

    aContext.AddSubject(make_shared<Subject>(name, id));
    aContext.NotifyObserver("subjectmodel", "addnewrow");

    subject = subject->NextSiblingElement();
  }
}

void XmlParser::LoadTeachers(Context & aContext, TiXmlHandle & hRoot)
{
  TiXmlElement * teacher = hRoot.FirstChild("Teachers").FirstChild().Element();
  int            id;

  while (teacher)
  {
    string fname = teacher->Attribute("fname");
    string lname = teacher->Attribute("lname");
    teacher->QueryIntAttribute("id", &id);

    aContext.AddTeacher(make_shared<Teacher>(fname, lname, id));
    // notify teacher model
    aContext.NotifyObserver("teachermodel", "addnewrow");
    teacher = teacher->NextSiblingElement();
  }
}

void XmlParser::LoadRooms(Context & aContext, TiXmlHandle & hRoot)
{
  TiXmlElement * room = hRoot.FirstChild("Rooms").FirstChild().Element();
  int            id;
  int            capacity;

  while (room)
  {
    string name = room->Attribute("name");
    room->QueryIntAttribute("capacity", &capacity);
    room->QueryIntAttribute("id", &id);

    aContext.AddRoom(make_shared<Room>(name, capacity, id));
    aContext.NotifyObserver("roommodel", "addnewrow");

    room = room->NextSiblingElement();
  }
}

void XmlParser::LoadGroups(Context & aContext, TiXmlHandle & hRoot)
{
  struct groupStruct
  {
    int    id;
    int    numberOfStud;
    string fname;
    int    parentId;
  };

  vector<groupStruct> theGroups;

  TiXmlElement * group = hRoot.FirstChild("Groups").FirstChild().Element();

  while (group)
  {
    groupStruct aGroup;
    aGroup.fname = group->Attribute("name");
    group->QueryIntAttribute("nrStudents", &aGroup.numberOfStud);
    group->QueryIntAttribute("id", &aGroup.id);
    group->QueryIntAttribute("parentId", &aGroup.parentId);

    // add new group
    theGroups.push_back(aGroup);
    group = group->NextSiblingElement();
  }

  sort(theGroups.begin(), theGroups.end(),
       [](auto first, auto second)
       {
         return first.parentId < second.parentId;
       });

  for (auto aGroup : theGroups)
  {
    aContext.LoadGroupFromXml(aGroup.fname, aGroup.numberOfStud, aGroup.id, aGroup.parentId);
  }

  // aContext.NotifyObserver("groupmodel", "treeloaded");
}

void XmlParser::LoadLessons(Context & aContext, TiXmlHandle & hRoot)
{
  TiXmlElement * lesson = hRoot.FirstChild("Lessons").FirstChild().Element();
  int            teacherId;
  int            groupId;
  int            subjectId;
  int            numberOfHours;
  int            lessonId;

  while (lesson)
  {
    lesson->QueryIntAttribute("teacherId", &teacherId);
    lesson->QueryIntAttribute("subjectId", &subjectId);
    lesson->QueryIntAttribute("groupId", &groupId);
    lesson->QueryIntAttribute("lessonLength", &numberOfHours);
    lesson->QueryIntAttribute("lessonId", &lessonId);

    aContext.AddLessonFromXml(teacherId, subjectId, groupId, numberOfHours, lessonId);
    aContext.NotifyObserver("lessonmodel", "addnewrow");

    lesson = lesson->NextSiblingElement();
  }
}

void XmlParser::LoadData(Context & aContext, string aFileName)
{
  if (aFileName.empty())
    return;
  // select which document to impor
  TiXmlDocument doc(aFileName.c_str());
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

  LoadInstituteData(aContext, hRoot);
  LoadSubjects(aContext, hRoot);
  LoadTeachers(aContext, hRoot);
  LoadRooms(aContext, hRoot);
  LoadGroups(aContext, hRoot);
  LoadLessons(aContext, hRoot);
}
