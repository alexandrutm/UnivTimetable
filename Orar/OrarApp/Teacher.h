#pragma once


class Teacher
{
public:
	Teacher(string, string);
	string GetFirstName();
	void SetFirstName(string aName);
	void SetLastName(string aName);

private:
	string mFirstName;
	string mLastName;

};
