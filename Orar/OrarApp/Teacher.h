#pragma once

class Teacher
{
public:
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
