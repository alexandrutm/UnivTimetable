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

  void ChangeAvailability(pair<int, int> availability);
  bool IsAvailable(pair<int, int> availability);

private:
  string mFirstName;
  string mLastName;
  int    mId;

  vector<pair<int, int>> mAvailability;
};
