#pragma once

class Subject;
class Teacher;
class Students;

class Lesson
{
public:
  bool     operator==(const Lesson & aLesson);
  Lesson & operator=(const Lesson & l);

  Lesson(Teacher *, Subject *, Students *, int, int);

  void SetTeacher(Teacher * aTeacher);
  void SetClass(Students * aClass);
  void SetSubject(Subject * aSubject);
  void SetNumberOfHours(int aNumberOfHours);

  Teacher *  GetTeacher();
  Students * GetStudentClass();
  Subject *  GetSubject();
  int        GetNumberOfHours();
  int        GetId();

private:
  Subject *  mSubject;
  Teacher *  mTeacher;
  Students * mStudentClass;
  int        mHoursPerWeek;
  int        mId;
};
