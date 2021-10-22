#pragma once
#include "src/containers/ConstraintTimeslot.h"

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

  void AddUnavailableTimeslot(const Timeslot aUnavailableTimeslot);
  void EraseUnavailableTimeslot(const Timeslot aTimeslot);
  bool IsAvailable(const Timeslot aTimeslot);

  // the size of mAvailability
  // used for sort lesson by teacher constraint
  int GetTeacherWeight();

private:
  string mFirstName;
  string mLastName;
  int    mId;

  vector<Timeslot> mAvailability;
};
