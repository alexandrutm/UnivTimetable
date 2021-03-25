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
  void SetGroup(Group * aGroup);
  void SetSubject(Subject * aSubject);
  void SetNumberOfHours(int aNumberOfHours);

  Teacher * GetTeacher();
  Group *   GetGroup();
  Subject * GetSubject();
  int       GetNumberOfHours();
  int       GetId();

private:
  Subject * mSubject;
  Teacher * mTeacher;
  Group *   mGroup;
  int       mHoursPerWeek;
  int       mId;
};
