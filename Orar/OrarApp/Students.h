#pragma once

class Students
{
public:
  bool       operator==(const Students & aClass);
  Students & operator=(const Students & aClass);

  Students(string, int, int);
  void   SetNumberOfStudents(int aNrOfStudent);
  int    GetNumberOfStudents();
  void   SetName(string aName);
  string GetName();
  int    GetId();

protected:
  string mName;
  int    mNumberOfStudents;
  int    mId;
};
