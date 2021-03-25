#pragma once

class Teacher;

class TimeConstraint
{
public:
  TimeConstraint(vector<pair<int, int>> aDayAndHour, Teacher * aTeacher);
  bool                   Validate();
  string                 GetConstraintName();
  vector<pair<int, int>> GetConstraintDetails();
  Teacher *              GetTeacher();

private:
  Teacher *              mTeacher;
  vector<pair<int, int>> mDayAndHour;
};
