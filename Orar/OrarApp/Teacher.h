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

  void MakeUnavailableTimeSlot(pair<int, int> aTimeSlot);
  void MakeAvailableTimeSlot(pair<int, int> aTimeSlot);
  bool IsAvailable(pair<int, int> availability);

  // the size of mAvailability
  // used for sort lesson by teacher constraint
  int GetTeacherWeight();

private:
  string mFirstName;
  string mLastName;
  int    mId;

  int mWeight;

  vector<pair<int, int>> mAvailability;
};
