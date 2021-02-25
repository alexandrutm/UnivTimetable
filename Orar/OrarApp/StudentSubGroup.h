#pragma once
#include "Students.h"

class StudentGroup;

class StudentSubGroup : public Students
{
public:
  StudentSubGroup(string aName, int aNumberOfStudents, int aId, shared_ptr<StudentGroup> aParent);

  void   SetNumberOfStudents(int aNrOfStudent);
  int    GetNumberOfStudents();
  void   SetName(string aName);
  string GetName();
  int    GetId();

private:
  shared_ptr<StudentGroup> mParentGroup;
};
