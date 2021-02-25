#include "stdafx.h"
#include "StudentYear.h"
#include "StudentGroup.h"

StudentYear::StudentYear(string aName, int aNumberOfStudents, int aId)
  : Students(aName, aNumberOfStudents, aId)
{
}

void StudentYear::SetNumberOfStudents(int aNrOfStudent)
{
  mNumberOfStudents = aNrOfStudent;
}

int StudentYear::GetNumberOfStudents()
{
  return mNumberOfStudents;
}

void StudentYear::SetName(string aName)
{
  mName = aName;
}

string StudentYear::GetName()
{
  return mName;
}

int StudentYear::GetId()
{
  return mId;
}

void StudentYear::AddGroup(shared_ptr<StudentGroup> aGroup)
{
  mStudentGroups.push_back(aGroup);
}
