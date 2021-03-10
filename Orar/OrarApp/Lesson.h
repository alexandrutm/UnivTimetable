#pragma once

class Subject;
class Teacher;
class Students;

class Lesson
{
public:
  bool     operator==(const Lesson & aLesson);
  Lesson & operator=(const Lesson & l);

  Lesson(shared_ptr<Teacher>, shared_ptr<Subject>, shared_ptr<Students>, int, int);

  void SetTeacher(shared_ptr<Teacher> aTeacher);
  void SetClass(shared_ptr<Students> aClass);
  void SetSubject(shared_ptr<Subject> aSubject);
  void SetNumberOfHours(int aNumberOfHours);

  shared_ptr<Teacher>  GetTeacher();
  shared_ptr<Students> GetGroup();
  shared_ptr<Subject>  GetSubject();
  int                  GetNumberOfHours();
  int                  GetId();

private:
  shared_ptr<Subject>  mSubject;
  shared_ptr<Teacher>  mTeacher;
  shared_ptr<Students> mGroup;
  int                  mHoursPerWeek;
  int                  mId;
};
