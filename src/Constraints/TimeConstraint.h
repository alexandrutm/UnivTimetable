#pragma once
#include "src/containers/ConstraintTimeslot.h"

class Teacher;
// A TimeConstraint is specific to a teacher- when teacher is not available
class TimeConstraint
{
public:
  TimeConstraint(vector<Timeslot> aTimeslot, Teacher * aTeacher);

  const string             GetConstraintName() const;
  const vector<Timeslot> & GetConstraintDetailsDayAndHour() const;
  const Teacher *          GetTeacher() const;

private:
  Teacher *        mTeacher;
  vector<Timeslot> mUnavailableTimeslots;
};
