#pragma once
class Teacher;
class Subject;
class Classes;
class Lesson;
class BasicInfo;


class Context
{
public:

	Context();

	void AddTeacher(shared_ptr<Teacher> aTeacher);
	void RemoveTeacher(shared_ptr<Teacher>);
	void EditTeacher(shared_ptr<Teacher>,shared_ptr<Teacher>);
	vector<shared_ptr<Teacher>>& GetTeachers();
	//

	void AddSubject(shared_ptr<Subject> aSubject);
	void RemoveSubjectByName(string aName);
	void EditSubjectByName(string aOldName, string aNewName);
	vector<shared_ptr<Subject>>& GetSubjects();
	
	void AddClass(shared_ptr<Classes> aClass);
	void RemoveClassByName(string aName);
	void EditClassesByName(string aOldName, string aNewName, int aNumberOfStudents);
	vector<shared_ptr<Classes>>& GetClasses();

	void AddLesson(shared_ptr<Lesson> aLesson);
	void RemoveLesson();
	void EditLesson();

	void AddBasicInfo(shared_ptr<BasicInfo> aBasicInfo);

	void DeleteData();

private:
	vector<shared_ptr<Subject>>mSubjects;
	vector<shared_ptr<Teacher>>mTeachers;
	vector<shared_ptr<Classes>>mClasses;
	vector<shared_ptr<Lesson>>mLessons;
	shared_ptr<BasicInfo> mBasicInfo;

};
