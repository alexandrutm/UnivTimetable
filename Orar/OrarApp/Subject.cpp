#include "stdafx.h"
#include "Subject.h"

Subject::Subject(string aName, int aId)
  : mName(aName)
  , mId(aId)
{
}

bool Subject::operator==(const Subject & aSubject)
{
  return mId == aSubject.mId;
}

Subject & Subject::operator=(const Subject & aSubject)
{
  if (this != &aSubject)
  {
    this->mName = aSubject.mName;
    this->mId   = aSubject.mId;
  }
  return *this;
}

string Subject::GetName()
{
  return mName;
}

void Subject::SetName(string aName)
{
  mName = aName;
}

int Subject::GetId()
{
  return mId;
}
