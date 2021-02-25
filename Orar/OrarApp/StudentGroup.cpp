#include "stdafx.h"
#include "StudentGroup.h"
#include "StudentYear.h"

StudentGroup::StudentGroup(string                  aName,
                           int                     aNumberOfStudents,
                           int                     aId,
                           shared_ptr<StudentYear> aParent)
  : Students(aName, aNumberOfStudents, aId)
  , mParentYear(aParent)
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
