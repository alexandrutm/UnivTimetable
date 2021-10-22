#include "stdafx.h"
#include "TimeConstraint.h"
#include "src/Containers/Teacher.h"

TimeConstraint::TimeConstraint(vector<pair<int, int>> aDayAndHour, Teacher * aTeacher)
  : mTeacher(aTeacher)
  , mDayAndHour(aDayAndHour)
{
}

bool TimeConstraint::Validate()
{
  return true;
}

const string & TimeConstraint::GetConstraintName() const
{
  return mTeacher->GetFirstName() + "  " + mTeacher->GetLastName();
}

const vector<pair<int, int>> & TimeConstraint::GetConstraintDetailsDayAndHour() const
{
  return mDayAndHour;
}

const Teacher * TimeConstraint::GetTeacher() const
{
  return mTeacher;
}
