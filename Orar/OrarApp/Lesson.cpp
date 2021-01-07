#include "stdafx.h"
#include "Lesson.h"

Lesson::Lesson(shared_ptr<string> aSubject, shared_ptr<string> aTeacher, shared_ptr<string>aClass, shared_ptr<int> aHoursPerWeek):
	mSubject(aSubject),mTeacher(aTeacher),mClass(aClass),mHoursPerWeek(aHoursPerWeek)
{
}
