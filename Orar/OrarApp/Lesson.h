#pragma once

class Subject;
class Teacher;
class StudentYear;

class Lesson
{
public:
  bool     operator==(const Lesson & aLesson);
  Lesson & operator=(const Lesson & l);

  Lesson(shared_ptr<Teacher>, shared_ptr<Subject>, shared_ptr<StudentYear>, int, int);

  void SetTeacher(shared_ptr<Teacher> aTeacher);
  void SetClass(shared_ptr<StudentYear> aClass);
  void SetSubject(shared_ptr<Subject> aSubject);
  void SetNumberOfHours(int aNumberOfHours);

  shared_ptr<Teacher>     GetTeacher();
  shared_ptr<StudentYear> GetClass();
  shared_ptr<Subject>     GetSubject();
  int                     GetNumberOfHours();
  int                     GetId();

private:
  shared_ptr<Subject>     mSubject;
  shared_ptr<Teacher>     mTeacher;
  shared_ptr<StudentYear> mClass;
  int                     mHoursPerWeek;
  int                     mId;
};
