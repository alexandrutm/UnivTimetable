#pragma once
#include "Students.h"

class StudentSubGroup;
class StudentYear;

class StudentGroup : public Students
{
public:
  StudentGroup(string aName, int aNumberOfStudents, int aId, shared_ptr<StudentYear> aParent);

  void   SetNumberOfStudents(int aNrOfStudent);
  int    GetNumberOfStudents();
  void   SetName(string aName);
  string GetName();
  int    GetId();

private:
  vector<shared_ptr<StudentSubGroup>> mStudentsSubGroups;
  shared_ptr<StudentYear>             mParentYear;
};
