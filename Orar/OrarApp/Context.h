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

  void                          AddTeacher(shared_ptr<Teacher> aTeacher);
  void                          RemoveTeacher(int i);
  vector<shared_ptr<Teacher>> & GetTeachers();
  int                           GetTeacherSize();
  shared_ptr<Teacher>           GetTeacherByIndex(int i);
  void                          DeleteTeachers();
  int                           GenerateTeacherId();

  void                          AddSubject(shared_ptr<Subject> aSubject);
  void                          RemoveSubject(int i);
  vector<shared_ptr<Subject>> & GetSubjects();
  int                           GetSubjectSize();
  shared_ptr<Subject>           GetSubjectByIndex(int i);
  void                          DeleteSubjects();
  int                           GenerateSubjectId();

  void                          AddClass(shared_ptr<Classes> aClass);
  void                          RemoveClass(int i);
  vector<shared_ptr<Classes>> & GetClasses();
  int                           GetClassSize();
  shared_ptr<Classes>           GetClassByIndex(int i);
  void                          DeleteClasses();
  int                           GenerateClassId();

  void                         AddLesson(shared_ptr<Lesson> aLesson);
  void                         RemoveLesson(int i);
  vector<shared_ptr<Lesson>> & GetLessons();
  int                          GetLessonSize();
  shared_ptr<Lesson>           GetLessonByIndex(int i);
  void                         DeleteLessons();
  int                          GenerateLessonId();

  void                       AddRoom(shared_ptr<Room> aRoom);
  void                       RemoveRoom(int i);
  vector<shared_ptr<Room>> & GetRooms();
  int                        GetRoomSize();
  shared_ptr<Room>           GetRoomByIndex(int i);
  void                       DeleteRooms();
  int                        GenerateRoomId();

  void AddInstituteData(shared_ptr<InstituteData> aInstituteData);
  int  GenerateInstituteDataId();

private:
  vector<shared_ptr<Subject>>       mSubjects;
  vector<shared_ptr<Teacher>>       mTeachers;
  vector<shared_ptr<Classes>>       mClasses;
  vector<shared_ptr<Lesson>>        mLessons;
  vector<shared_ptr<Room>>          mRooms;
  vector<shared_ptr<InstituteData>> mInstituteData;
};
