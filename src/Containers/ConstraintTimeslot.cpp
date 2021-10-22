#include "stdafx.h"
#include "ConstraintTimeslot.h"

Timeslot::Timeslot(int aDayNumber, int aHourNumber)
  : mDayNumber(aDayNumber)
  , mHourNumber(aHourNumber)
{
}

bool Timeslot::operator==(const Timeslot & aOther) const
{
  return aOther.GetDayNumber() == mDayNumber && aOther.GetHourNumber() == mHourNumber;
}

Timeslot & Timeslot::operator=(const Timeslot & aOther)
{
  if (this != &aOther)
  {
    mDayNumber  = aOther.mDayNumber;
    mHourNumber = aOther.mHourNumber;
  }
  return *this;
}

const int Timeslot::GetDayNumber() const
{
  return mDayNumber;
}

const int Timeslot::GetHourNumber() const
{
  return mHourNumber;
}
