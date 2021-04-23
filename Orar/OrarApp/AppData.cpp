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
  TiXmlDocument      doc;
  TiXmlDeclaration * decl = new TiXmlDeclaration("1.0", "", "");
  doc.LinkEndChild(decl);

  TiXmlElement * root = new TiXmlElement("Context");
  doc.LinkEndChild(root);

  // block: InstitutionDetails
  {
    TiXmlElement * institutionNode = new TiXmlElement("Institution");
    root->LinkEndChild(institutionNode);

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
    TiXmlElement * subjectNode = new TiXmlElement("Subjects");
    root->LinkEndChild(subjectNode);

    auto subjects = aContext.GetSubjects();

    for (auto subject : subjects)
    {
      TiXmlElement * subjectElement = new TiXmlElement("Subject");

      subjectNode->LinkEndChild(subjectElement);

      subjectElement->SetAttribute("name", subject->GetName().c_str());
      subjectElement->SetAttribute("id", subject->GetId());
    }
  }

  // block: Teachers
  {
    TiXmlElement * teacherNode = new TiXmlElement("Teachers");
    root->LinkEndChild(teacherNode);

    auto teachers = aContext.GetTeachers();

    for (auto teacher : teachers)
    {
      TiXmlElement * teacherElement = new TiXmlElement("Teacher");

      teacherNode->LinkEndChild(teacherElement);

      teacherElement->SetAttribute("fname", teacher->GetFirstName().c_str());
      teacherElement->SetAttribute("lname", teacher->GetLastName().c_str());
      teacherElement->SetAttribute("id", teacher->GetId());
    }
  }

  // block: Groups
  {
    TiXmlElement * groupNode = new TiXmlElement("Groups");
    root->LinkEndChild(groupNode);

    queue<Group *> treeNodes;

    treeNodes.push(aContext.GetRootGroup());

    while (!treeNodes.empty())
    {
      auto frontNode = treeNodes.front();
      treeNodes.pop();

      TiXmlElement * groupElement = new TiXmlElement("Group");
      groupNode->LinkEndChild(groupElement);
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
    TiXmlElement * roomNode = new TiXmlElement("Rooms");
    root->LinkEndChild(roomNode);

    auto rooms = aContext.GetRooms();

    for (auto room : rooms)
    {
      TiXmlElement * roomElement = new TiXmlElement("Room");

      roomNode->LinkEndChild(roomElement);

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
      TiXmlElement * lessonElement = new TiXmlElement("Lesson");

      lessonNode->LinkEndChild(lessonElement);

      lessonElement->SetAttribute("teacherId", lesson->GetTeacher()->GetId());
      lessonElement->SetAttribute("subjectId", lesson->GetSubject()->GetId());
      lessonElement->SetAttribute("groupId", lesson->GetGroup()->GetId());
      lessonElement->SetAttribute("lessonLength", lesson->GetDuration());
    }
  }

  doc.SaveFile(aFileName.c_str());
}
