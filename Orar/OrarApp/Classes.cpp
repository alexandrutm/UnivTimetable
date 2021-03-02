#include "stdafx.h"
#include "Classes.h"

Classes::Classes(string aName, int aNumber, int aId, Classes * aParent)
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

Classes::~Classes()
{  // delete all children
}

Classes * Classes::GetChild(int nr)
{
  if (nr < 0 || nr >= mChildren.size())
    return nullptr;
  return mChildren.at(nr);
}

size_t Classes::GetChildrenSize()
{
  return mChildren.size();
}

int Classes::GetNumberOfData()
{
  // class name and number of students
  return 2;
}

void Classes::InsertChild(int position, int id)
{
  Classes * newClass = new Classes("name", 0, id, this);

  mChildren.insert(mChildren.begin() + position, newClass);
}

Classes * Classes::GetParent()
{
  return mParent;
}

void Classes::RemoveChild(int pos)
{
  mChildren.erase(remove_if(mChildren.begin(), mChildren.end(),
                            [&](auto const & classes) {
                              return mChildren[pos]->GetId() == classes->GetId();
                            }),
                  mChildren.end());
}
