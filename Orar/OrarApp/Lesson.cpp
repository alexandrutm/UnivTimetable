#include "stdafx.h"
#include "Lesson.h"

Lesson::Lesson(shared_ptr<Teacher>     aTeacher,
               shared_ptr<Subject>     aSubject,
               shared_ptr<StudentYear> aClass,
               int                     aHoursPerWeek,
               int                     aId)
  : mSubject(aSubject)
  , mTeacher(aTeacher)
  , mClass(aClass)
  , mHoursPerWeek(aHoursPerWeek)
  , mId(aId)
{
}

void Lesson::SetTeacher(shared_ptr<Teacher> aTeacher)
{
  this->mTeacher = aTeacher;
}

void Lesson::SetClass(shared_ptr<StudentYear> aClass)
{
  this->mClass = aClass;
}

void Lesson::SetSubject(shared_ptr<Subject> aSubject)
{
  this->mSubject = aSubject;
}

void Lesson::SetNumberOfHours(int aNumberOfHours)
{
  this->mHoursPerWeek = aNumberOfHours;
}

shared_ptr<Teacher> Lesson::GetTeacher()
{
  return mTeacher;
}

shared_ptr<StudentYear> Lesson::GetClass()
{
  return mClass;
}

shared_ptr<Subject> Lesson::GetSubject()
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
    this->mClass        = lesson.mClass;
    this->mTeacher      = lesson.mTeacher;
    this->mSubject      = lesson.mSubject;
    this->mHoursPerWeek = lesson.mHoursPerWeek;
    this->mId           = lesson.mId;
  }

  return *this;
}
