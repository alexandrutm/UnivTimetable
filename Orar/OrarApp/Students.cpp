#include "stdafx.h"
#include "Students.h"

Students::Students(string aName, int aNumber, int aId, Students * aParent)
  : mName(aName)
  , mNumberOfStudents(aNumber)
  , mId(aId)
  , mParent(aParent)
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

Students::~Students()
{
}

Students * Students::GetChild(int nr)
{
  if (nr < 0 || nr >= mChildren.size())
    return nullptr;
  return mChildren.at(nr).get();
}

size_t Students::GetChildrenSize()
{
  return mChildren.size();
}

int Students::GetNumberOfData()
{
  // class name and number of students
  return 2;
}

void Students::InsertChild(int id)
{
  unique_ptr<Students> newClass = make_unique<Students>("name", 0, id, this);

  mChildren.push_back(move(newClass));
}

Students * Students::GetParent()
{
  return mParent.get();
}

void Students::RemoveChild(int pos)
{
  mChildren.erase(remove_if(mChildren.begin(), mChildren.end(),
                            [&](auto const & classes) {
                              return mChildren[pos]->GetId() == classes->GetId();
                            }),
                  mChildren.end());
}
