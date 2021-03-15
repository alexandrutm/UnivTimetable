#pragma once

class Group
{
public:
  Group(string, int, int, Group * aParent = nullptr);
  bool    operator==(const Group & aClass);
  Group & operator=(const Group & aClass);

  ~Group();

  size_t GetChildrenSize();
  int    GetNumberOfData();

  void InsertChild(int id);
  void RemoveChild(int pos);

  void SetNumberOfStudents(int aNrOfStudent);
  int  GetNumberOfStudents();

  void   SetName(string aName);
  string GetName();

  Group * GetParent();
  Group * GetChild(int nr);

  int GetId();

private:
  string mName;
  int    mNumberOfStudents;
  int    mId;

  vector<unique_ptr<Group>> mChildren;
  Group *                   mParent;
};
