#include "stdafx.h"
#include "Context.h"

void Context::AddTeacher(Teacher aTeacher)
{
	mTeachers.push_back(aTeacher);
}

void Context::RemoveTeacherByFirstName(string aFirstName)
{
	//not optimal ///////// need changes

	auto i = begin(mTeachers);

	while (i != end(mTeachers))
	{
		if ((*i).GetFirstName() == aFirstName)
		{
			i = mTeachers.erase(i);
			break;
		}
		else
			i++;
	}

}

void Context::AddSubject(Subject aSubject)
{
	mSubjects.push_back(aSubject);
}

void Context::RemoveSubjectByName(string aName)
{
	auto i = begin(mSubjects);

	while (i != end(mSubjects))
	{
		if ((*i).GetName() == aName)
		{
			i = mSubjects.erase(i);
			break;
		}
		else
			i++;
	}
}

string Teacher::GetFirstName()
{
	return mFirstName;
}

string Subject::GetName()
{
	return mName;
}

void Subject::SetColor(int i)
{
	//not optimal ///////// need changes
	if (i == 0)
		mColor = Color::red;
	else if (i == 1)
		mColor = Color::green;
}
