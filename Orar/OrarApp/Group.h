#pragma once

class Group
{
public:
  Group(string, int, int, Group * aParent = nullptr);
  bool    operator==(const Group & aClass);
  Group & operator=(const Group & aClass);

  ~Group();

  size_t GetChildrenSize() const;
  int    ColumnCount() const;

  void AppendChild(int id);
  void LoadChildFromXml(string aName, int aNrOfStud, int aId);
  void RemoveChild(int pos);

  void   SetNumberOfStudents(int aNrOfStudent);
  int    GetNumberOfStudents();
  void   SetName(string aName);
  string GetName();
  int    GetChildNumber() const;

  Group * GetParent();
  Group * GetChild(int nr);

  int GetId();

  void MakeUnavailableTimeSlot(pair<int, int> aTimeSlot);
  void MakeAvailableTimeSlot(pair<int, int> aTimeSlot);
  bool IsAvailable(pair<int, int> availability);

private:
  string mName;
  int    mNumberOfStudents;
  int    mId;

  vector<unique_ptr<Group>> mChildren;
  Group *                   mParent;

  vector<pair<int, int>> mAvailability;
};
