#include "stdafx.h"
#include "Lesson.h"
#include "Group.h"
#include "Room.h"
#include "Teacher.h"

Lesson::Lesson(Teacher * aTeacher, Subject * aSubject, Group * aClass, int aHoursPerWeek, int aId)
  : mSubject(aSubject)
  , mTeacher(aTeacher)
  , mGroup(aClass)
  , mDuration(aHoursPerWeek)
  , mId(aId)
{
}

void Lesson::SetTeacher(Teacher * aTeacher)
{
  this->mTeacher = aTeacher;
}

void Lesson::SetGroup(Group * aClass)
{
  this->mGroup = aClass;
}

void Lesson::SetSubject(Subject * aSubject)
{
  this->mSubject = aSubject;
}

void Lesson::SetDuration(int aNumberOfHours)
{
  this->mDuration = aNumberOfHours;
}

Teacher * Lesson::GetTeacher()
{
  return mTeacher;
}

Group * Lesson::GetGroup()
{
  return mGroup;
}

Subject * Lesson::GetSubject()
{
  return mSubject;
}

int Lesson::GetDuration()
{
  return mDuration;
}

int Lesson::GetId()
{
  return mId;
}

void Lesson::SetPlacement(Placement aPlacement)
{
  mPlacement = aPlacement;
}

Placement Lesson::GetPlacement()
{
  return mPlacement;
}

void Lesson::ClearAssingnedData()
{
  for (auto hour = GetPlacement().GetTimeSlot().GetStartTime();
       hour < GetPlacement().GetTimeSlot().GetEndTime(); hour++)
  {
    GetTeacher()->EraseUnavailableTimeslot(
      Timeslot(GetPlacement().GetTimeSlot().GetDayOfWeek(), hour));

    if (GetPlacement().GetRoom())
      GetPlacement().GetRoom()->EraseUnavailableTimeslot(
        pair<int, int>(GetPlacement().GetTimeSlot().GetDayOfWeek(), hour));

    GetGroup()->EraseUnavailableTimeslot(
      pair<int, int>(GetPlacement().GetTimeSlot().GetDayOfWeek(), hour));
  }

  mVisited.clear();
  mPlacement.Clear();
}

void Lesson::AddVisitedPlacement(Placement aPlacement)
{
  mVisited.push_back(aPlacement);
}

bool Lesson::IsVisited(Placement aPlacement)
{
  auto it = find_if(mVisited.begin(), mVisited.end(),
                    [&](auto placement)
                    {
                      return placement == aPlacement;
                    });

  if (it != mVisited.end())
    return true;
  return false;
}

void Lesson::ClearVisitedPlacements()
{
  mVisited.clear();
}

int Lesson::GetWeight()
{
  return mGroup->GetWeight() + mTeacher->GetTeacherWeight();
}

bool Lesson::operator==(const Lesson & aLesson)
{
  return mId == aLesson.mId;
}

Lesson & Lesson::operator=(const Lesson & lesson)
{
  if (this != &lesson)
  {
    this->mGroup    = lesson.mGroup;
    this->mTeacher  = lesson.mTeacher;
    this->mSubject  = lesson.mSubject;
    this->mDuration = lesson.mDuration;
    this->mId       = lesson.mId;
  }

  return *this;
}
