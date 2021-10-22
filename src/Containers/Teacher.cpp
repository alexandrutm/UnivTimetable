#include "stdafx.h"
#include "Teacher.h"

Teacher::Teacher(string aFirstName, string aLastName, int aTeacherId)
  : mFirstName(move(aFirstName))
  , mLastName(move(aLastName))
  , mId(aTeacherId)
{
}

bool Teacher::operator==(const Teacher & aTeacher)
{
  return mId == aTeacher.mId;
}

Teacher & Teacher::operator=(const Teacher & aTeacher)
{
  if (this != &aTeacher)
  {
    mFirstName = aTeacher.mFirstName;
    mLastName  = aTeacher.mLastName;
    mId        = aTeacher.mId;
  }
  return *this;
}

string Teacher::GetLastName()
{
  return mLastName;
}

string Teacher::GetFirstName()
{
  return mFirstName;
}

void Teacher::SetFirstName(string aName)
{
  mFirstName = aName;
}

void Teacher::SetLastName(string aName)
{
  mLastName = aName;
}

int Teacher::GetId()
{
  return mId;
}

void Teacher::AddUnavailableTimeslot(const Timeslot aUnavailableTimeslott)
{
  mAvailability.push_back(aUnavailableTimeslott);
}

void Teacher::EraseUnavailableTimeslot(const Timeslot aTimeslot)
{
  mAvailability.erase(remove(mAvailability.begin(), mAvailability.end(), aTimeslot),
                      mAvailability.end());
}

bool Teacher::IsAvailable(const Timeslot aTimeslot)
{
  auto it = find_if(mAvailability.begin(), mAvailability.end(),
                    [&](const auto & timeslot)
                    {
                      return timeslot == aTimeslot;
                    });

  if (it != mAvailability.end())
    return false;

  return true;
}

int Teacher::GetTeacherWeight()
{
  return static_cast<int>(mAvailability.size());
}
