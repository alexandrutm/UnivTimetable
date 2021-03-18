#pragma once
#include "Constraint.h"

class Teacher;

class TimeConstraint : public Constraint
{
public:
  TimeConstraint(vector<pair<int, int>> aDayAndHour, shared_ptr<Teacher> aTeacher);
  bool                   Validate();
  string                 GetConstraintName();
  vector<pair<int, int>> GetConstraintDetails();

private:
  shared_ptr<Teacher>    mTeacher;
  vector<pair<int, int>> mDayAndHour;
};
