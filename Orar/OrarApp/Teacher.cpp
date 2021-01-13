#include"stdafx.h"
#include"Teacher.h"

bool Teacher::operator==(const Teacher& aTeacher)
{
	if (mLastName == aTeacher.mLastName && mFirstName ==aTeacher.mFirstName)
	{
		return true;
	}
	return false;
}

Teacher::Teacher(string aFirstName, string aLastName):mFirstName(aFirstName),mLastName(aLastName)
{
}

string Teacher::GetLastName()
{
	return mLastName;
}

string Teacher::GetFirstName()
{
	return mFirstName;
}

void Teacher::SetFirstName(string aName)
{
	mFirstName = aName;
}

void Teacher::SetLastName(string aName)
{
	mLastName = aName;
}
