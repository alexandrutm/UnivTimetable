#pragma once
#include "Students.h"

class StudentGroup;

class StudentYear : public Students
{
public:
  StudentYear(string aName, int aNumberOfStudents, int aId);

  void   SetNumberOfStudents(int aNrOfStudent);
  int    GetNumberOfStudents();
  void   SetName(string aName);
  string GetName();
  int    GetId();

  void AddGroup(shared_ptr<StudentGroup> aGroup);

protected:
  vector<shared_ptr<StudentGroup>> mStudentGroups;
};
