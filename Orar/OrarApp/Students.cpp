#include "stdafx.h"
#include "Students.h"

Students::Students(string aName, int aNumber, int aId)
  : mName(aName)
  , mNumberOfStudents(aNumber)
  , mId(aId)
{
}

void Students::SetNumberOfStudents(int aNrOfStudent)
{
  mNumberOfStudents = aNrOfStudent;
}

int Students::GetNumberOfStudents()
{
  return mNumberOfStudents;
}

void Students::SetName(string aName)
{
  mName = aName;
}

string Students::GetName()
{
  return mName;
}

int Students::GetId()
{
  return mId;
}

bool Students::operator==(const Students & aClass)
{
  return mId == aClass.mId;
}

Students & Students::operator=(const Students & aClass)
{
  if (this != &aClass)
  {
    this->mName             = aClass.mName;
    this->mNumberOfStudents = aClass.mNumberOfStudents;
    this->mId               = aClass.mId;
  }

  return *this;
}
