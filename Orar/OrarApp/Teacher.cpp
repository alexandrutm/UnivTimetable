#include"stdafx.h"
#include"Teacher.h"

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
