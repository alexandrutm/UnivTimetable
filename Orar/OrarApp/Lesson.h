#pragma once

class Subject;
class Teacher;
class Group;

class Lesson
{
public:
  bool     operator==(const Lesson & aLesson);
  Lesson & operator=(const Lesson & l);

  Lesson(Teacher *, Subject *, Group *, int, int);

  void SetTeacher(Teacher * aTeacher);
  void SetClass(Group * aClass);
  void SetSubject(Subject * aSubject);
  void SetNumberOfHours(int aNumberOfHours);

  Teacher * GetTeacher();
  Group *   GetStudentClass();
  Subject * GetSubject();
  int       GetNumberOfHours();
  int       GetId();

private:
  Subject * mSubject;
  Teacher * mTeacher;
  Group *   mStudentClass;
  int       mHoursPerWeek;
  int       mId;
};
