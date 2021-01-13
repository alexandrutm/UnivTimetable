#pragma once


class Teacher
{
public:

	Teacher() = default;
	~Teacher() = default;
	Teacher(const Teacher&) = default;

	Teacher(string, string);
	string GetFirstName();
	string GetLastName();
	void SetFirstName(string aName);
	void SetLastName(string aName);

private:
	string mFirstName;
	string mLastName;

};


Q_DECLARE_METATYPE(Teacher);
