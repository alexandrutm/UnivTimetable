#include "stdafx.h"
#include "Classes.h"

Classes::Classes(string aName, int aNumber): mName(aName),mNumberOfStudents(aNumber)
{
}

void Classes::SetNumberOfStudents(int aNrOfStudent)
{
	mNumberOfStudents = aNrOfStudent;
}

int Classes::GetNumberOfStudents()
{
	return mNumberOfStudents;
}

void Classes::SetName(string aName)
{
	mName = aName;
}

string Classes::GetName()
{
	return mName;
}

bool Classes::operator==(const Classes& aClass)
{
	if (this->mName == aClass.mName &&
		this->mNumberOfStudents == aClass.mNumberOfStudents)
		return true;
	return false;
}

Classes& Classes::operator=(const Classes& aClass)
{
	if (this != &aClass)
	{
		this->mName = aClass.mName;
		this->mNumberOfStudents = aClass.mNumberOfStudents;
	}

	return *this;
}
