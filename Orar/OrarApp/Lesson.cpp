#include "stdafx.h"
#include "Lesson.h"

Lesson::Lesson(Teacher * aTeacher, Subject * aSubject, Group * aClass, int aHoursPerWeek, int aId)
  : mSubject(aSubject)
  , mTeacher(aTeacher)
  , mGroup(aClass)
  , mDuration(aHoursPerWeek)
  , mId(aId)
  , mRoom(nullptr)
  , mTimeSlot(TimeSlot())
{
}

void Lesson::SetTimeSlot(TimeSlot aTimeSlot)
{
  mTimeSlot = aTimeSlot;
}

void Lesson::SetRoom(Room * aRoom)
{
  mRoom = aRoom;
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

void Lesson::AssignPlacement(Placement * aPlacement)
{
  mPlacement = aPlacement;
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
