#pragma once

//materii, profesori,grupe,sali,constrageri
class Subject
{
public:
	enum class Color
	{
		red,
		green,
		black,
		yellow
	};



private:


	string mName;
	Color mColor;

};

class Teacher
{
public:

private:
	string mFirstName;
	string mLastName;

};

class Context
{
public:
	void AddTeacher(Teacher aTeacher);
	void RemoveTeacherByFirstName(string aFirstName);


private:
	vector<Subject>mSubjects;
	vector<Teacher>mTeachers;


};
