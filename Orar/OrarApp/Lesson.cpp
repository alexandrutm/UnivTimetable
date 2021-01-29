#include "stdafx.h"
#include "Lesson.h"

Lesson::Lesson(shared_ptr<Teacher> aTeacher,  shared_ptr<Subject>aSubject, shared_ptr<Classes> aClass, int aHoursPerWeek):
	mSubject(aSubject),mTeacher(aTeacher),mClass(aClass),mHoursPerWeek(aHoursPerWeek)
{
	//generate unique id
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

void Lesson::SetNumberOfHours(int aNumberOfHours)
{
	this->mHoursPerWeek = aNumberOfHours;
}

shared_ptr<Teacher> Lesson::GetTeacher()
{
	return mTeacher;
}

shared_ptr<Classes> Lesson::GetClass()
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

bool Lesson::operator==(const Lesson& aLesson)
{
	if (this->mTeacher == aLesson.mTeacher &&
		this->mClass == aLesson.mClass &&
		this->mSubject == aLesson.mSubject &&
		this->mHoursPerWeek == aLesson.mHoursPerWeek)
		return true;

	return false;
}

Lesson& Lesson::operator=(const Lesson& l)
{
	if (this != &l)
	{
		this->mClass = l.mClass;
		this->mTeacher = l.mTeacher;
		this->mSubject = l.mSubject;
		this->mHoursPerWeek = l.mHoursPerWeek;
	}

	return *this;
}
