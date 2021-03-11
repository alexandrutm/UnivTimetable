#include "stdafx.h"
#include "Lesson.h"

Lesson::Lesson(
  Teacher * aTeacher, Subject * aSubject, Students * aClass, int aHoursPerWeek, int aId)
  : mSubject(aSubject)
  , mTeacher(aTeacher)
  , mStudentClass(aClass)
  , mHoursPerWeek(aHoursPerWeek)
  , mId(aId)
{
}

void Lesson::SetTeacher(Teacher * aTeacher)
{
  this->mTeacher = aTeacher;
}

void Lesson::SetClass(Students * aClass)
{
  this->mStudentClass = aClass;
}

void Lesson::SetSubject(Subject * aSubject)
{
  this->mSubject = aSubject;
}

void Lesson::SetNumberOfHours(int aNumberOfHours)
{
  this->mHoursPerWeek = aNumberOfHours;
}

Teacher * Lesson::GetTeacher()
{
  return mTeacher;
}

Students * Lesson::GetStudentClass()
{
  return mStudentClass;
}

Subject * Lesson::GetSubject()
{
  return mSubject;
}

int Lesson::GetNumberOfHours()
{
  return mHoursPerWeek;
}

int Lesson::GetId()
{
  return mId;
}

bool Lesson::operator==(const Lesson & aLesson)
{
  return mId == aLesson.mId;
}

Lesson & Lesson::operator=(const Lesson & lesson)
{
  if (this != &lesson)
  {
    this->mStudentClass = lesson.mStudentClass;
    this->mTeacher      = lesson.mTeacher;
    this->mSubject      = lesson.mSubject;
    this->mHoursPerWeek = lesson.mHoursPerWeek;
    this->mId           = lesson.mId;
  }

  return *this;
}
