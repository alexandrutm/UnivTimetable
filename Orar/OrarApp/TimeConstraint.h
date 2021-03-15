#pragma once
#include "Constraint.h"

class Teacher;

class TimeConstraint : public Constraint
{
public:
  TimeConstraint(vector<pair<int, int>> aDayAndHour, Teacher * aTeacher);
  bool Validate();

private:
  Teacher *              mTeacher;
  vector<pair<int, int>> mDayAndHour;
};
