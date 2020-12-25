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


	string GetName();
	void SetColor(int i);

private:

	string mName;
	Color mColor;

};

class Teacher
{
public:
	string GetFirstName();

private:
	string mFirstName;
	string mLastName;

};

class Context
{
public:
	void AddTeacher(Teacher aTeacher);
	void RemoveTeacherByFirstName(string aFirstName);
	void AddSubject(Subject aSubject);
	void RemoveSubjectByName(string aName);

private:
	vector<Subject>mSubjects;
	vector<Teacher>mTeachers;


};
