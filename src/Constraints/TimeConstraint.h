#pragma once

class Teacher;

class TimeConstraint
{
public:
  TimeConstraint(vector<pair<int, int>> aDayAndHour, Teacher * aTeacher);
  bool Validate();

  const string &                 GetConstraintName() const;
  const vector<pair<int, int>> & GetConstraintDetailsDayAndHour() const;
  const Teacher *                GetTeacher() const;

private:
  Teacher *              mTeacher;
  vector<pair<int, int>> mDayAndHour;
};
