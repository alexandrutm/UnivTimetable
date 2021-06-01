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

int Group::GetChildNumber() const
{
  if (mParent)
  {
    auto it =
      find_if(mParent->mChildren.begin(), mParent->mChildren.end(), [&](auto const & child) {
        return child.get() == this;
      });

    if (it != mParent->mChildren.end())
      return static_cast<int>(it - mParent->mChildren.begin());
  }
  return 0;
}

int Group::GetId()
{
  return mId;
}

void Group::MakeUnavailableTimeSlot(pair<int, int> aTimeSlot)
{
  mAvailability.push_back(aTimeSlot);
}

void Group::MakeAvailableTimeSlot(pair<int, int> aTimeSlot)
{
  mAvailability.erase(remove(mAvailability.begin(), mAvailability.end(), aTimeSlot),
                      mAvailability.end());
}

bool Group::IsAvailable(pair<int, int> aTimeSlot)
{
  auto it = find_if(mAvailability.begin(), mAvailability.end(), [&](const auto & timeslot) {
    return timeslot == aTimeSlot;
  });

  if (it != mAvailability.end())
    return false;

  return true;
}

void Group::DeleteChilds()
{
  mChildren.clear();
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

size_t Group::GetChildrenSize() const
{
  return mChildren.size();
}

int Group::ColumnCount() const
{
  // class name and number of students
  return 2;
}

void Group::AppendChild(int id)
{
  mChildren.emplace_back(make_unique<Group>("name", 0, id, this));
}

void Group::LoadChildFromXml(string aName, int aNrOfStud, int aId)
{
  mChildren.emplace_back(make_unique<Group>(aName, aNrOfStud, aId, this));
}

Group * Group::GetParent()
{
  return mParent != nullptr ? mParent : nullptr;
}

void Group::RemoveChild(int pos)
{
  if (pos < 0 || pos >= mChildren.size())
    return;

  mChildren.erase(mChildren.begin() + pos);
}
