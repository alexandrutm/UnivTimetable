#pragma once
#include"stdafx.h"


class Teacher
{
public:
	string GetFirstName();
	void SetFirstName(string aName);
	void SetLastName(string aName);

private:
	string mFirstName;
	string mLastName;

};
