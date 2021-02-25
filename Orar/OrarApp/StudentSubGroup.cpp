#include "stdafx.h"
#include "StudentSubGroup.h"

StudentSubGroup::StudentSubGroup(string                   aName,
                                 int                      aNumberOfStudents,
                                 int                      aId,
                                 shared_ptr<StudentGroup> aParent)
  : Students(aName, aNumberOfStudents, aId)
  , mParentGroup(aParent)
{
}

void StudentSubGroup::SetNumberOfStudents(int aNrOfStudent)
{
  mNumberOfStudents = aNrOfStudent;
}

int StudentSubGroup::GetNumberOfStudents()
{
  return mNumberOfStudents;
}

void StudentSubGroup::SetName(string aName)
{
  mName = aName;
}

string StudentSubGroup::GetName()
{
  return mName;
}

int StudentSubGroup::GetId()
{
  return mId;
}
