#include "stdafx.h"
#include "AppData.h"
#include "Context.h"
#include "Group.h"
#include "InstituteData.h"
#include "Lesson.h"
#include "Room.h"
#include "Subject.h"
#include "Teacher.h"
#include "tinyxml/tinyxml.h"

void AppData::SaveData(Context & aContext, string aFileName)
{
  TiXmlDocument doc;
  auto          decl = make_unique<TiXmlDeclaration>("1.0", "", "");
  doc.LinkEndChild(decl.release());

  auto root = make_unique<TiXmlElement>("Context");
  doc.LinkEndChild(root.release());

  // block: InstitutionDetails
  {
    auto institutionNode = make_unique<TiXmlElement>("Institution");
    root->LinkEndChild(institutionNode.release());

    auto institutionData = aContext.GetInstituteData();

    institutionNode->SetAttribute("name", institutionData->GetSchoolName().c_str());
    institutionNode->SetAttribute("nrOfHoursPerDay", institutionData->GetNumberOfHoursPerDay());
    institutionNode->SetAttribute("startHour", institutionData->GetStartHour());
    institutionNode->SetAttribute("endHour", institutionData->GetStartHour() +
                                               institutionData->GetNumberOfHoursPerDay());
    institutionNode->SetAttribute("nrOfDaysPerWeek", institutionData->GetNumberOfDaysPerWeek());
  }

  // block: Subjects
  {
    auto subjectNode = make_unique<TiXmlElement>("Subjects");
    root->LinkEndChild(subjectNode.release());

    auto subjects = aContext.GetSubjects();

    for (auto subject : subjects)
    {
      auto subjectElement = make_unique<TiXmlElement>("Subject");

      subjectNode->LinkEndChild(subjectElement.release());

      subjectElement->SetAttribute("name", subject->GetName().c_str());
      subjectElement->SetAttribute("id", subject->GetId());
    }
  }

  // block: Teachers
  {
    auto teacherNode = make_unique<TiXmlElement>("Teachers");
    root->LinkEndChild(teacherNode.release());

    auto teachers = aContext.GetTeachers();

    for (auto teacher : teachers)
    {
      auto teacherElement = make_unique<TiXmlElement>("Teacher");

      teacherNode->LinkEndChild(teacherElement.release());

      teacherElement->SetAttribute("fname", teacher->GetFirstName().c_str());
      teacherElement->SetAttribute("lname", teacher->GetLastName().c_str());
      teacherElement->SetAttribute("id", teacher->GetId());
    }
  }

  // block: Groups
  {
    auto groupNode = make_unique<TiXmlElement>("Groups");
    root->LinkEndChild(groupNode.release());

    queue<Group *> treeNodes;

    treeNodes.push(aContext.GetRootGroup());

    while (!treeNodes.empty())
    {
      auto frontNode = treeNodes.front();
      treeNodes.pop();

      auto groupElement = make_unique<TiXmlElement>("Group");
      groupNode->LinkEndChild(groupElement.release());
      groupElement->SetAttribute("name", frontNode->GetName().c_str());
      groupElement->SetAttribute("nrStudents", frontNode->GetNumberOfStudents());
      groupElement->SetAttribute("id", frontNode->GetId());

      if (frontNode->GetParent() != nullptr)
        groupElement->SetAttribute("parentId", frontNode->GetParent()->GetId());
      else
        groupElement->SetAttribute("parentId", -1);

      for (int i = 0; i < frontNode->GetChildrenSize(); i++)
        treeNodes.push(frontNode->GetChild(i));
    }
  }

  // block: Rooms
  {
    auto roomNode = make_unique<TiXmlElement>("Rooms");
    root->LinkEndChild(roomNode.release());

    auto rooms = aContext.GetRooms();

    for (auto room : rooms)
    {
      auto roomElement = make_unique<TiXmlElement>("Room");

      roomNode->LinkEndChild(roomElement.release());

      roomElement->SetAttribute("name", room->GetName().c_str());
      roomElement->SetAttribute("capacity", room->GetCapacity());
      roomElement->SetAttribute("id", room->GetId());
    }
  }

  // block: Lessons
  {
    auto lessonNode = make_unique<TiXmlElement>("Lessons");
    root->LinkEndChild(lessonNode.release());

    auto lessons = aContext.GetLessons();

    for (auto lesson : lessons)
    {
      auto lessonElement = make_unique<TiXmlElement>("Lesson");

      lessonNode->LinkEndChild(lessonElement.release());

      lessonElement->SetAttribute("teacherId", lesson->GetTeacher()->GetId());
      lessonElement->SetAttribute("subjectId", lesson->GetSubject()->GetId());
      lessonElement->SetAttribute("groupId", lesson->GetGroup()->GetId());
      lessonElement->SetAttribute("lessonLength", lesson->GetDuration());
    }
  }

  doc.SaveFile(aFileName.c_str());
}

void AppData::LoadData(Context & aContext, string aFileName)
{
  // select witch document to import
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
    aContext.ChangeInstituteData(instituteData);
  }

  //// block Subjects
  //{
  //  TiXmlElement * subject = hRoot.FirstChild("Subjects").FirstChild().Element();
  //  int            id;
  //  while (subject)
  //  {
  //    string name = subject->Attribute("name");
  //    subject->QueryIntAttribute("id", &id);

  //    mSubjectView.AddSubject(name, id);

  //    subject = subject->NextSiblingElement();
  //  }
  //}

  // block Teachers
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

  //// block room
  //{
  //  TiXmlElement * room = hRoot.FirstChild("Rooms").FirstChild().Element();
  //  int            id;
  //  int            capacity;

  //  while (room)
  //  {
  //    string name = room->Attribute("name");
  //    room->QueryIntAttribute("capacity", &capacity);
  //    room->QueryIntAttribute("id", &id);

  //    mRoomView.AddRoom(name, capacity, id);

  //    room = room->NextSiblingElement();
  //  }
  //}

  //// block groups
  //{
  //  TiXmlElement * group = hRoot.FirstChild("Groups").FirstChild().Element();
  //  struct groupStructure
  //  {
  //    int    id;
  //    int    numberOfStud;
  //    string fname;
  //    int    parentId;
  //  };
  //  vector<groupStructure> theGroups;

  //  while (group)
  //  {
  //    groupStructure currentGroup;
  //    currentGroup.fname = group->Attribute("name");
  //    group->QueryIntAttribute("nrStudents", &currentGroup.numberOfStud);
  //    group->QueryIntAttribute("id", &currentGroup.id);
  //    group->QueryIntAttribute("parentId", &currentGroup.parentId);

  //    theGroups.push_back(currentGroup);

  //    group = group->NextSiblingElement();
  //  }

  //  sort(theGroups.begin(), theGroups.end(), [](auto first, auto second) {
  //    return first.parentId < second.parentId;
  //  });

  //  for (auto currentGroup : theGroups)
  //  {
  //    mClassView.AddClass(currentGroup.fname, currentGroup.numberOfStud, currentGroup.id,
  //                        currentGroup.parentId);
  //  }
  //}
}
