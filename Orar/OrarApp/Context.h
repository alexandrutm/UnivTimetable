#pragma once
class Teacher;
class Subject;
class Classes;
class Lesson;
class BasicInfo;
class Room;


class Context
{
public:

	Context();

	void AddTeacher(shared_ptr<Teacher> aTeacher);
	void RemoveTeacher(shared_ptr<Teacher>);
	void EditTeacher(shared_ptr<Teacher>,shared_ptr<Teacher>);
	vector<shared_ptr<Teacher>>& GetTeachers();
	int GetTeacherSize();
	shared_ptr<Teacher>GetTeacherByIndex(int i);
	void DeleteTeachers();

	void AddSubject(shared_ptr<Subject> aSubject);
	void RemoveSubject(shared_ptr<Subject> aSubject);
	void EditSubject(shared_ptr<Subject> aSubject, shared_ptr<Subject> aNewSubject);
	vector<shared_ptr<Subject>>& GetSubjects();
	int GetSubjectSize();
	shared_ptr<Subject>GetSubjectByIndex(int i);
	void DeleteSubjects();

	void AddClass(shared_ptr<Classes> aClass);
	void RemoveClass(shared_ptr<Classes> aClass);
	void EditClasses(shared_ptr<Classes> aClass, shared_ptr<Classes> aNewClass);
	vector<shared_ptr<Classes>>& GetClasses();
	int GetClassSize();
	shared_ptr<Classes> GetClassByIndex(int i);
	void DeleteClasses();

	void AddLesson(shared_ptr<Lesson> aLesson);
	void RemoveLesson(shared_ptr<Lesson> aLesson);
	void EditLesson(shared_ptr<Lesson> aLesson, shared_ptr<Lesson> aNewLesson);
	vector<shared_ptr<Lesson>>& GetLessons();
	int GetLessonSize();
	shared_ptr<Lesson>GetLessonByIndex(int i);
	void DeleteLessons();

	void AddRoom(shared_ptr<Room> aRoom);
	void RemoveRoom(shared_ptr<Room> aRoom);
	void EditRoom(shared_ptr<Room> aRoom, shared_ptr<Room> aNewRoom);
	vector<shared_ptr<Room>>& GetRooms();
	int GetRoomSize();
	shared_ptr<Room> GetRoomByIndex(int i);
	void DeleteRooms();

	void AddBasicInfo(shared_ptr<BasicInfo> aBasicInfo);

private:
	vector<shared_ptr<Subject>>mSubjects;
	vector<shared_ptr<Teacher>>mTeachers;
	vector<shared_ptr<Classes>>mClasses;
	vector<shared_ptr<Lesson>>mLessons;
	vector<shared_ptr<Room>>mRooms;
	shared_ptr<BasicInfo> mBasicInfo;

};
