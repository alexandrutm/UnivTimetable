#include "stdafx.h"
#include "TimeConstraint.h"
#include "src/Containers/Teacher.h"

TimeConstraint::TimeConstraint(vector<Timeslot> aTimeslot, Teacher * aTeacher)
  : mTeacher(aTeacher)
  , mUnavailableTimeslots(move(aTimeslot))
{
}

const string TimeConstraint::GetConstraintName() const
{
  return mTeacher->GetFirstName() + "  " + mTeacher->GetLastName();
}

const vector<Timeslot> & TimeConstraint::GetConstraintDetailsDayAndHour() const
{
  return mUnavailableTimeslots;
}

const Teacher * TimeConstraint::GetTeacher() const
{
  return mTeacher;
}
