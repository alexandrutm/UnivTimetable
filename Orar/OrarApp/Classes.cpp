#include "Classes.h"

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
