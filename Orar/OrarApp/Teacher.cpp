#include "stdafx.h"
#include "Teacher.h"

Teacher::Teacher(string aFirstName, string aLastName, int aTeacherId):
  mFirstName(aFirstName), mLastName(aLastName), mId(aTeacherId)
{
}

bool Teacher::operator==(const Teacher& aTeacher) { return mId == aTeacher.mId; }

Teacher& Teacher::operator=(const Teacher& aTeacher)
{
  if (this != &aTeacher) {
    this->mFirstName = aTeacher.mFirstName;
    this->mLastName = aTeacher.mLastName;
    this->mId == aTeacher.mId;
  }
  return *this;
}

string Teacher::GetLastName() { return mLastName; }

string Teacher::GetFirstName() { return mFirstName; }

void Teacher::SetFirstName(string aName) { mFirstName = aName; }

void Teacher::SetLastName(string aName) { mLastName = aName; }

int Teacher::GetId() { return mId; }
