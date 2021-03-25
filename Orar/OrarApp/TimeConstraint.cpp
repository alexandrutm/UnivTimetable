#include "stdafx.h"
#include "TimeConstraint.h"
#include "Teacher.h"

TimeConstraint::TimeConstraint(vector<pair<int, int>> aDayAndHour, Teacher * aTeacher)
  : mTeacher(aTeacher)
  , mDayAndHour(aDayAndHour)
{
}

bool TimeConstraint::Validate()
{
  return true;
}

string TimeConstraint::GetConstraintName()
{
  return mTeacher->GetFirstName() + "  " + mTeacher->GetLastName();
}

vector<pair<int, int>> TimeConstraint::GetConstraintDetails()
{
  return mDayAndHour;
}

Teacher * TimeConstraint::GetTeacher()
{
  return mTeacher;
}
