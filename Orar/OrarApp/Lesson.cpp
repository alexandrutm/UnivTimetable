#include "stdafx.h"
#include "Lesson.h"

Lesson::Lesson(shared_ptr<string> aSubject, shared_ptr<string> aTeacher, shared_ptr<string>aClass, shared_ptr<int> aHoursPerWeek):
	mSubject(aSubject),mTeacher(aTeacher),mClass(aClass),mHoursPerWeek(aHoursPerWeek)
{
}

void Lesson::SetTeacher(shared_ptr<Teacher> aTeacher)
{
	this->mTeacher = aTeacher;
}

void Lesson::SetClass(shared_ptr<Classes> aClass)
{
	this->mClass = aClass;
}

void Lesson::SetSubject(shared_ptr<Subject> aSubject)
{
	this->mSubject = aSubject;
}

void Lesson::SetNumberOfHours(shared_ptr<int> aNumberOfHours)
{
	this->mHoursPerWeek = aNumberOfHours;
}

shared_ptr<Teacher> Lesson::GetTeacher()
{
	return mTeacher;
}

shared_ptr<Classes> Lesson::GetClass()
{
	return mClass);
}

shared_ptr<Subject> Lesson::GetSubject()
{
	return mSubject;
}

shared_ptr<int> Lesson::GetNumberOfHours()
{
	return mHoursPerWeek;
}

bool Lesson::operator==(const Lesson& aLesson)
{
	if (this->mTeacher == aLesson.mTeacher &&
		this->mClass == aLesson.mClass &&
		this->mSubject == aLesson.mSubject &&
		this->mHoursPerWeek == aLesson.mHoursPerWeek)
		return true;

	return false;
}
