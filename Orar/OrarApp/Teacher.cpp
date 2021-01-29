#include"stdafx.h"
#include"Teacher.h"

bool Teacher::operator==(const Teacher& aTeacher)
{
	if (mLastName == aTeacher.mLastName && 
		mFirstName ==aTeacher.mFirstName)
	{
		return true;
	}
	return false;
}

Teacher& Teacher::operator=(const Teacher& aTeacher)
{
	if (this != &aTeacher)
	{
		this->mFirstName = aTeacher.mFirstName;
		this->mLastName = aTeacher.mLastName;
	}
	return *this;
}

Teacher::Teacher(string aFirstName, string aLastName, int aTeacherId):mFirstName(aFirstName),mLastName(aLastName),
mTeacherId(aTeacherId)
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

int Teacher::GetId()
{
	return mTeacherId;
}
