#pragma once

class Teacher
{
public:
  Teacher()                = default;
  ~Teacher()               = default;
  Teacher(const Teacher &) = default;
  bool      operator==(const Teacher & aTeacher);
  Teacher & operator=(const Teacher & aTeacher);

  Teacher(string, string, int);
  string GetLastName();
  string GetFirstName();
  void   SetFirstName(string aName);
  void   SetLastName(string aName);
  int    GetId();

private:
  string mFirstName;
  string mLastName;
  int    mId;
};
