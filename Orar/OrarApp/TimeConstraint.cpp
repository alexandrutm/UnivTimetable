#include "stdafx.h"
#include "TimeConstraint.h"

TimeConstraint::TimeConstraint(vector<pair<int, int>> aDayAndHour, Teacher * aTeacher)
  : mTeacher(aTeacher)
  , mDayAndHour(aDayAndHour)
{
}

bool TimeConstraint::Validate()
{
  return true;
}
