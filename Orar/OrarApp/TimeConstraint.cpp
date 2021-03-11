#include "stdafx.h"
#include "TimeConstraint.h"

TimeConstraint::TimeConstraint(vector<int> days, vector<int> hours, Teacher * aTeacher)
  : mTeacher(aTeacher)
  , mDays(days)
  , mHours(hours)
{
}

bool TimeConstraint::Validate()
{
  return true;
}
