#include "stdafx.h"
#include "Classes.h"

Classes::Classes(string aName, int aNumber, int aId): mName(aName), mNumberOfStudents(aNumber), mId(aId) { }

void Classes::SetNumberOfStudents(int aNrOfStudent) { mNumberOfStudents = aNrOfStudent; }

int Classes::GetNumberOfStudents() { return mNumberOfStudents; }

void Classes::SetName(string aName) { mName = aName; }

string Classes::GetName() { return mName; }

int Classes::GetId() { return mId; }

bool Classes::operator==(const Classes& aClass) { return mId == aClass.mId; }

Classes& Classes::operator=(const Classes& aClass)
{
  if (this != &aClass) {
    this->mName = aClass.mName;
    this->mNumberOfStudents = aClass.mNumberOfStudents;
    this->mId = aClass.mId;
  }

  return *this;
}
