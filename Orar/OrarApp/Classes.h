#pragma once

class Classes
{
public:
  Classes()                = default;
  ~Classes()               = default;
  Classes(const Classes &) = default;
  bool                operator==(const Classes & aClass);
  Classes &           operator=(const Classes & aClass);
  shared_ptr<Classes> GetChild(int nr);
  size_t              ChildCount();
  void                AddChild(shared_ptr<Classes> aClass);
  shared_ptr<Classes> Parent();
  void                RemoveChild(shared_ptr<Classes> aClass);

  Classes(string, int, int, shared_ptr<Classes> aParent);
  void   SetNumberOfStudents(int aNrOfStudent);
  int    GetNumberOfStudents();
  void   SetName(string aName);
  string GetName();
  int    GetId();

private:
  string                      mName;
  int                         mNumberOfStudents;
  vector<shared_ptr<Classes>> mChildren;
  int                         mId;
  shared_ptr<Classes>         mParent;
};
