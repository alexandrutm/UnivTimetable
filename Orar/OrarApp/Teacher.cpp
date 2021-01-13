#include"stdafx.h"
#include"Teacher.h"

Teacher::Teacher(string aFirstName, string aLastName):mFirstName(aFirstName),mLastName(aLastName)
{
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
