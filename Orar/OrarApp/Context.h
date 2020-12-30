#pragma once
#include "Teacher.h"
#include "Subject.h"


class Context
{
public:

	void AddTeacher(Teacher aTeacher);
	void RemoveTeacherByFirstName(string aFirstName);


	void AddSubject(Subject aSubject);
	void RemoveSubjectByName(string aName);
	void EditSubjectByName(string aOldName, string aNewName, int aColorPosition);

private:
	vector<Subject>mSubjects;
	vector<Teacher>mTeachers;
};
