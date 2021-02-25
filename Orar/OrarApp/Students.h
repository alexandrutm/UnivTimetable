#pragma once

class Students
{
public:
  bool       operator==(const Students & aClass);
  Students & operator=(const Students & aClass);

  Students(string, int, int);
  virtual void   SetNumberOfStudents(int aNrOfStudent);
  virtual int    GetNumberOfStudents();
  virtual void   SetName(string aName);
  virtual string GetName();
  virtual int    GetId();

protected:
  string mName;
  int    mNumberOfStudents;
  int    mId;
};
