#pragma once
class Teacher;
class Subject;
class Classes;
class Lesson;
class InstituteData;
class Room;


class Context
{
  public:
  Context();

  void AddTeacher(shared_ptr<Teacher> aTeacher);
  void RemoveTeacher(shared_ptr<Teacher>);
  vector<shared_ptr<Teacher>>& GetTeachers();
  int GetTeacherSize();
  shared_ptr<Teacher> GetTeacherByIndex(int i);
  void DeleteTeachers();
  int GenerateTeacherId();

  void AddSubject(shared_ptr<Subject> aSubject);
  void RemoveSubject(shared_ptr<Subject> aSubject);
  vector<shared_ptr<Subject>>& GetSubjects();
  int GetSubjectSize();
  shared_ptr<Subject> GetSubjectByIndex(int i);
  void DeleteSubjects();
  int GenerateSubjectId();

  void AddClass(shared_ptr<Classes> aClass);
  void RemoveClass(shared_ptr<Classes> aClass);
  vector<shared_ptr<Classes>>& GetClasses();
  int GetClassSize();
  shared_ptr<Classes> GetClassByIndex(int i);
  void DeleteClasses();
  int GenerateClassId();

  void AddLesson(shared_ptr<Lesson> aLesson);
  void RemoveLesson(shared_ptr<Lesson> aLesson);
  vector<shared_ptr<Lesson>>& GetLessons();
  int GetLessonSize();
  shared_ptr<Lesson> GetLessonByIndex(int i);
  void DeleteLessons();
  int GenerateLessonId();

  void AddRoom(shared_ptr<Room> aRoom);
  void RemoveRoom(shared_ptr<Room> aRoom);
  vector<shared_ptr<Room>>& GetRooms();
  int GetRoomSize();
  shared_ptr<Room> GetRoomByIndex(int i);
  void DeleteRooms();
  int GenerateRoomId();

  void AddInstituteData(shared_ptr<InstituteData> aInstituteData);
  int GenerateInstituteDataId();

  private:
  vector<shared_ptr<Subject>> mSubjects;
  vector<shared_ptr<Teacher>> mTeachers;
  vector<shared_ptr<Classes>> mClasses;
  vector<shared_ptr<Lesson>> mLessons;
  vector<shared_ptr<Room>> mRooms;
  vector<shared_ptr<InstituteData>> mInstituteData;
};
