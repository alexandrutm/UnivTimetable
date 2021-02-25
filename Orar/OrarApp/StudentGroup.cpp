#include "stdafx.h"
#include "StudentGroup.h"

StudentGroup::StudentGroup(string aName, int aNumberOfStudents, int aId)
  : Students(aName, aNumberOfStudents, aId)
{
}

void StudentGroup::SetNumberOfStudents(int aNrOfStudent)
{
  mNumberOfStudents = aNrOfStudent;
}

int StudentGroup::GetNumberOfStudents()
{
  return mNumberOfStudents;
}

void StudentGroup::SetName(string aName)
{
  mName = aName;
}

string StudentGroup::GetName()
{
  return mName;
}

int StudentGroup::GetId()
{
  return mId;
}
