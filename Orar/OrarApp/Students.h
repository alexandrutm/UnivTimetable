#pragma once

class Students
{
public:
  Students(string, int, int, Students * aParent = nullptr);
  bool       operator==(const Students & aClass);
  Students & operator=(const Students & aClass);

  ~Students();

  size_t GetChildrenSize();
  int    GetNumberOfData();

  void InsertChild(int id);
  void RemoveChild(int pos);

  void SetNumberOfStudents(int aNrOfStudent);
  int  GetNumberOfStudents();

  void   SetName(string aName);
  string GetName();

  Students * GetParent();
  Students * GetChild(int nr);

  int GetId();

private:
  string mName;
  int    mNumberOfStudents;
  int    mId;

  vector<unique_ptr<Students>> mChildren;
  unique_ptr<Students>         mParent;
};
