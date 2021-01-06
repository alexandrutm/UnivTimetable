#include"stdafx.h"
#include"Subject.h"


string Subject::GetName()
{
	return mName;
}

void Subject::SetName(string aName)
{
	mName = aName;
}

void Subject::SetColor(int i)
{
	//not optimal ///////// need changes
	if (i == 0)
		mColor = Color::red;
	else if (i == 1)
		mColor = Color::green;
}
