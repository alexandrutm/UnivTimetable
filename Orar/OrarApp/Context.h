#pragma once
#include"stdafx.h"
class Teacher;
class Subject;
class Classes;
class BasicInfo;


class Context
{
public:

	Context();

	void AddTeacher(shared_ptr<Teacher> aTeacher);
	void RemoveTeacherByFirstName(string aFirstName);
	void EditTeacherByFirstName(string aOldName, string aNewFirstName, string aNewLastName);
	vector<shared_ptr<Teacher>>& GetTeachers();
	QStringListModel* GetTeacherModelComboBox();

	void AddSubject(shared_ptr<Subject> aSubject);
	void RemoveSubjectByName(string aName);
	void EditSubjectByName(string aOldName, string aNewName);
	vector<shared_ptr<Subject>>& GetSubjects();
	QStringListModel* GetSubjectModelComboBox();

	void AddClass(shared_ptr<Classes> aClass);
	void RemoveClassByName(string aName);
	void EditClassesByName(string aOldName, string aNewName, int aNumberOfStudents);
	vector<shared_ptr<Classes>>& GetClasses();
	QStringListModel* GetClassModelComboBox();

	void AddBasicInfo(shared_ptr<BasicInfo> aBasicInfo);



private:
	vector<shared_ptr<Subject>>mSubjects;
	vector<shared_ptr<Teacher>>mTeachers;
	vector<shared_ptr<Classes>>mClasses;
	shared_ptr<BasicInfo> mBasicInfo;

};
