#pragma once
#include"stdafx.h"
#include "Teacher.h"
#include "Subject.h"
#include "Classes.h"
#include "BasicInfo.h"



class Context
{
public:

	void AddTeacher(Teacher aTeacher);
	void RemoveTeacherByFirstName(string aFirstName);
	void EditTeacherByFirstName(string aOldName, string aNewFirstName, string aNewLastName);
	vector<Teacher>& GetTeachers();
	QStringListModel* GetTeacherModelComboBox();

	void AddSubject(Subject aSubject);
	void RemoveSubjectByName(string aName);
	void EditSubjectByName(string aOldName, string aNewName, int aColorPosition);
	vector<Subject>& GetSubjects();
	QStringListModel* GetSubjectModelComboBox();

	void AddClass(Classes aClass);
	void RemoveClassByName(string aName);
	void EditClassesByName(string aOldName, string aNewName, int aNumberOfStudents);
	vector<Classes>& GetClasses();
	QStringListModel* GetClassModelComboBox();

	void AddBasicInfo(BasicInfo aBasicInfo);



private:
	vector<Subject>mSubjects;
	vector<Teacher>mTeachers;
	vector<Classes>mClasses;
	BasicInfo mBasicInfo;

};
