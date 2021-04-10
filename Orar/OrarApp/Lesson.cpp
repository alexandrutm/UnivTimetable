#include "stdafx.h"
#include "Lesson.h"
#include "Placement.h"

Lesson::Lesson(Teacher * aTeacher, Subject * aSubject, Group * aClass, int aHoursPerWeek, int aId)
  : mSubject(aSubject)
  , mTeacher(aTeacher)
  , mGroup(aClass)
  , mDuration(aHoursPerWeek)
  , mId(aId)

{
}

void Lesson::Unassign()
{
  Placement * oldValuePlacement = mPlacement;

  mPlacement = nullptr;
  // unassign all constraint that contain this lesson
  // ----
  // ----
  // ----
}

void Lesson::Assign(Placement aPlacement)
{
  // if (mTimeSlotRoom.first != nullptr && mTimeSlotRoom.second != nullptr)
  // if placement is valid
  Unassign();
  mTimeSlotRoom = aTimeSlotRoom;

  // assign all constraint that contain this lesson
  // ----
  // ----
  // ----
}

pair<TimeSlot *, Room *> Lesson::GetTimeSlotRoom()
{
  return mTimeSlotRoom;
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

TimeSlot Lesson::GetTimeSlot()
{
  return mTimeSlot.IsValid() ? mTimeSlot : TimeSlot();
}

Room * Lesson::GetRoom()
{
  return mRoom ? mRoom : nullptr;
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
