#pragma once


class Subject
{
  public:
  Subject() = default;
  ~Subject() = default;
  Subject(const Subject&) = default;
  bool operator==(const Subject&);
  Subject& operator=(const Subject& aSubject);

  Subject(string, int);
  string GetName();
  void SetName(string aName);
  int GetId();

  private:
  string mName;
  int mId;
};

Q_DECLARE_METATYPE(Subject);
