#pragma once
#include "Students.h"

class StudentGroup : public Students
{
public:
  StudentGroup(string aName, int aNumberOfStudents, int aId);

  void   SetNumberOfStudents(int aNrOfStudent);
  int    GetNumberOfStudents();
  void   SetName(string aName);
  string GetName();
  int    GetId();

private:
};
