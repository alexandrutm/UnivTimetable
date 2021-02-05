#pragma once

class Classes
{
public:
  Classes()                = default;
  ~Classes()               = default;
  Classes(const Classes &) = default;
  bool      operator==(const Classes & aClass);
  Classes & operator=(const Classes & aClass);

  Classes(string, int, int);
  void   SetNumberOfStudents(int aNrOfStudent);
  int    GetNumberOfStudents();
  void   SetName(string aName);
  string GetName();
  int    GetId();

private:
  string mName;
  int    mNumberOfStudents;
  int    mId;
};
