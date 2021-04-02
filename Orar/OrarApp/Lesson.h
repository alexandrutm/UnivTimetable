#pragma once
#include "timeSlot.h"

class Subject;
class Teacher;
class Group;
class Room;

class Lesson
{
public:
  bool     operator==(const Lesson & aLesson);
  Lesson & operator=(const Lesson & l);

  Lesson(Teacher *, Subject *, Group *, int, int);

  void     SetTimeSlot(TimeSlot aTimeSlot);
  TimeSlot GetTimeSlot();

  void   SetRoom(Room * aRoom);
  Room * GetRoom();

  void      SetTeacher(Teacher * aTeacher);
  Teacher * GetTeacher();

  void    SetGroup(Group * aGroup);
  Group * GetGroup();

  void      SetSubject(Subject * aSubject);
  Subject * GetSubject();

  void SetDuration(int aNumberOfHours);
  int  GetDuration();

  int GetId();

private:
  int mId;

  TimeSlot mTimeSlot;

  Room * mRoom;

  Subject * mSubject;
  Teacher * mTeacher;
  Group *   mGroup;

  int mDuration;
};
