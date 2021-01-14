#include"stdafx.h"
#include"Subject.h"


bool Subject::operator==(const Subject& aSubject)
{
	if (this->mName == aSubject.mName)
		return true;
	return false;
}

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


