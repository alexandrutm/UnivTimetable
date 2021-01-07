#include"stdafx.h"
#include"Subject.h"


Subject::Subject(string aName):mName(aName)
{
}

string Subject::GetName()
{
	return mName;
}

void Subject::SetName(string aName)
{
	mName = aName;
}


