#pragma once

class Classes
{
public:
  Classes(string, int, int, Classes * aParent = nullptr);
  bool      operator==(const Classes & aClass);
  Classes & operator=(const Classes & aClass);

  ~Classes();

  size_t GetChildrenSize();
  int    GetNumberOfData();

  void InsertChild(int position, int id);
  void RemoveChild(int pos);

  void SetNumberOfStudents(int aNrOfStudent);
  int  GetNumberOfStudents();

  void   SetName(string aName);
  string GetName();

  Classes * GetParent();
  Classes * GetChild(int nr);

  int GetId();

private:
  string mName;
  int    mNumberOfStudents;
  int    mId;

  vector<Classes *> mChildren;
  Classes *         mParent;
};
