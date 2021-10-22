#include "stdafx.h"
#include "ConstraintTimeslot.h"

Timeslot::Timeslot(int aDayNumber, int aHourNumber)
  : mDayNumber(aDayNumber)
  , mHourNumber(aHourNumber)
{
}

const int Timeslot::GetDayNumber() const
{
  return mDayNumber;
}

const int Timeslot::GetHourNumber() const
{
  return mHourNumber;
}
