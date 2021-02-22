#include "stdafx.h"
#include "Classes.h"

Classes::Classes(string aName, int aNumber, int aId, shared_ptr<Classes> aParent)
  : mName(aName)
  , mNumberOfStudents(aNumber)
  , mId(aId)
  , mParent(aParent)
{
}

void Classes::SetNumberOfStudents(int aNrOfStudent)
{
  mNumberOfStudents = aNrOfStudent;
}

int Classes::GetNumberOfStudents()
{
  return mNumberOfStudents;
}

void Classes::SetName(string aName)
{
  mName = aName;
}

string Classes::GetName()
{
  return mName;
}

int Classes::GetId()
{
  return mId;
}

bool Classes::operator==(const Classes & aClass)
{
  return mId == aClass.mId;
}

Classes & Classes::operator=(const Classes & aClass)
{
  if (this != &aClass)
  {
    this->mName             = aClass.mName;
    this->mNumberOfStudents = aClass.mNumberOfStudents;
    this->mId               = aClass.mId;
  }

  return *this;
}

shared_ptr<Classes> Classes::GetChild(int nr)
{
  if (nr < 0 || nr >= mChildren.size())
    return nullptr;
  return mChildren.at(nr);
}

size_t Classes::ChildCount()
{
  return mChildren.size();
}

void Classes::AddChild(shared_ptr<Classes> aClass)
{
  mChildren.push_back(aClass);
}

shared_ptr<Classes> Classes::Parent()
{
  return mParent;
}

void Classes::RemoveChild(shared_ptr<Classes> aClass)
{
  mChildren.erase(remove_if(mChildren.begin(), mChildren.end(),
                            [&](auto const & classes) {
                              return aClass->GetId() == classes->GetId();
                            }),
                  mChildren.end());
}
