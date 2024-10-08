#include "stdafx.h"
#include "TimeSlot.h"

TimeSlot::TimeSlot(int aDayOfWeek, int aStartTime, int aEndTime)
  : mDayOfWeek(aDayOfWeek)
  , mStartTime(aStartTime)
  , mEndTime(aEndTime)
{
}

bool TimeSlot::operator==(const TimeSlot & aTimeSlot)
{
  if (this->mDayOfWeek == aTimeSlot.mDayOfWeek && this->mStartTime == aTimeSlot.mStartTime &&
      this->mEndTime == aTimeSlot.mEndTime)
    return true;

  return false;
}

TimeSlot & TimeSlot::operator=(const TimeSlot & aTimeSlot)
{
  if (this != &aTimeSlot)
  {
    this->mDayOfWeek = aTimeSlot.mDayOfWeek;
    this->mStartTime = aTimeSlot.mStartTime;
    this->mEndTime   = aTimeSlot.mEndTime;
  }
  return *this;
}

bool TimeSlot::IsValid()
{
  if (mStartTime != -1 && mEndTime != -1 && mDayOfWeek != -1)
    return true;
  return false;
}

TimeSlot::TimeSlot()

{
  mStartTime = -1;
  mDayOfWeek = -1;
  mEndTime   = -1;
}

void TimeSlot::SetStartTime(int aStartTime)
{
  mStartTime = aStartTime;
}

void TimeSlot::SetEndTime(int aEndTime)
{
  mEndTime = aEndTime;
}

void TimeSlot::SetDayOfWeek(int aDayOfWeek)
{
  mDayOfWeek = aDayOfWeek;
}

// int TimeSlot::GetId()
//{
//  return mId;
//}

int TimeSlot::GetDayOfWeek()
{
  return mDayOfWeek;
}

int TimeSlot::GetStartTime()
{
  return mStartTime;
}

int TimeSlot::GetEndTime()
{
  return mEndTime;
}
