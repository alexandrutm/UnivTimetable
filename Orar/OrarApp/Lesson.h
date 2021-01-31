#pragma once


class Subject;
class Teacher;
class Classes;

class Lesson
{
  public:
  Lesson() = default;
  ~Lesson() = default;
  Lesson(const Lesson&) = default;
  bool operator==(const Lesson& aLesson);
  Lesson& operator=(const Lesson& l);

  Lesson(shared_ptr<Teacher>, shared_ptr<Subject>, shared_ptr<Classes>, int, int);

  void SetTeacher(shared_ptr<Teacher> aTeacher);
  void SetClass(shared_ptr<Classes> aClass);
  void SetSubject(shared_ptr<Subject> aSubject);
  void SetNumberOfHours(int aNumberOfHours);

  shared_ptr<Teacher> GetTeacher();
  shared_ptr<Classes> GetClass();
  shared_ptr<Subject> GetSubject();
  int GetNumberOfHours();
  int GetId();


  private:
  shared_ptr<Subject> mSubject;
  shared_ptr<Teacher> mTeacher;
  shared_ptr<Classes> mClass;
  int mHoursPerWeek;
  int mId;
};

