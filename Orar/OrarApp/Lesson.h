#pragma once

class Subject;
class Teacher;
class Group;
class Placement;

class Lesson
{
public:
  bool     operator==(const Lesson & aLesson);
  Lesson & operator=(const Lesson & l);

  Lesson(Teacher *, Subject *, Group *, int, int);

  void      SetTeacher(Teacher * aTeacher);
  Teacher * GetTeacher();

  void    SetGroup(Group * aGroup);
  Group * GetGroup();

  void      SetSubject(Subject * aSubject);
  Subject * GetSubject();

  void SetDuration(int aNumberOfHours);
  int  GetDuration();

  int GetId();

  void AssignPlacement(Placement * aPlacement);

private:
  int mId;

  Placement * mPlacement;

  Subject * mSubject;
  Teacher * mTeacher;
  Group *   mGroup;

  int mDuration;
};
