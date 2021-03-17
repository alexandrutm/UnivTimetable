#include "stdafx.h"
#include "Group.h"

Group::Group(string aName, int aNumber, int aId, Group * aParent)
  : mName(aName)
  , mNumberOfStudents(aNumber)
  , mId(aId)
  , mParent(aParent)

{
}

void Group::SetNumberOfStudents(int aNrOfStudent)
{
  mNumberOfStudents = aNrOfStudent;
}

int Group::GetNumberOfStudents()
{
  return mNumberOfStudents;
}

void Group::SetName(string aName)
{
  mName = aName;
}

string Group::GetName()
{
  return mName;
}

int Group::GetId()
{
  return mId;
}

bool Group::operator==(const Group & aClass)
{
  return mId == aClass.mId;
}

Group & Group::operator=(const Group & aClass)
{
  if (this != &aClass)
  {
    this->mName             = aClass.mName;
    this->mNumberOfStudents = aClass.mNumberOfStudents;
    this->mId               = aClass.mId;
  }

  return *this;
}

Group::~Group()
{
}

Group * Group::GetChild(int nr)
{
  if (nr < 0 || nr >= mChildren.size())
    return nullptr;
  return mChildren.at(nr).get();
}

size_t Group::GetChildrenSize()
{
  return mChildren.size();
}

int Group::GetNumberOfData()
{
  // class name and number of students
  return 2;
}

void Group::InsertChild(int id)
{
  shared_ptr<Group> newClass = make_shared<Group>("name", 0, id, this);

  mChildren.push_back(move(newClass));
}

Group * Group::GetParent()
{
  return mParent;
}

void Group::RemoveChild(int pos)
{
  if (pos >= mChildren.size())
    return;

  mChildren.erase(mChildren.begin() + pos);
}
