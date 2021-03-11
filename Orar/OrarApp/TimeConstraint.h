#pragma once
#include "Constraints.h"

class Teacher;

class TimeConstraint : public Constraints
{
public:
  TimeConstraint(vector<int> aHours, vector<int> aDays, Teacher * aTeacher);
  bool Validate();

private:
  Teacher *   mTeacher;
  vector<int> mDays;
  vector<int> mHours;
};
