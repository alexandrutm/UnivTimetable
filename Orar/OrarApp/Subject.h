#pragma once

class Subject
{
public:
  bool      operator==(const Subject &);
  Subject & operator=(const Subject & aSubject);

  Subject(string, int);
  string GetName();
  void   SetName(string aName);
  int    GetId();

private:
  string mName;
  int    mId;
};
