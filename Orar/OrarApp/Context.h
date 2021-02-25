#pragma once
class Teacher;
class Subject;
class StudentGroup;
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
  size_t                        GetTeacherSize();
  shared_ptr<Teacher> &         GetTeacherByIndex(int i);
  void                          DeleteTeachers();
  int                           GenerateTeacherId();

  void                          AddSubject(shared_ptr<Subject> aSubject);
  void                          RemoveSubject(int i);
  vector<shared_ptr<Subject>> & GetSubjects();
  size_t                        GetSubjectSize();
  shared_ptr<Subject> &         GetSubjectByIndex(int i);
  void                          DeleteSubjects();
  int                           GenerateSubjectId();

  void                               AddGroup(shared_ptr<StudentGroup> aClass);
  void                               RemoveClass(int i);
  vector<shared_ptr<StudentGroup>> & GetGroups();
  size_t                             GetGroupSize();
  shared_ptr<StudentGroup> &         GetGroupByIndex(int i);
  void                               DeleteClasses();
  int                                GenerateClassId();

  void                         AddLesson(shared_ptr<Lesson> aLesson);
  void                         RemoveLesson(int i);
  vector<shared_ptr<Lesson>> & GetLessons();
  size_t                       GetLessonSize();
  shared_ptr<Lesson> &         GetLessonByIndex(int i);
  void                         DeleteLessons();
  int                          GenerateLessonId();

  void                       AddRoom(shared_ptr<Room> aRoom);
  void                       RemoveRoom(int i);
  vector<shared_ptr<Room>> & GetRooms();
  size_t                     GetRoomSize();
  shared_ptr<Room> &         GetRoomByIndex(int i);
  void                       DeleteRooms();
  int                        GenerateRoomId();

  void AddInstituteData(shared_ptr<InstituteData> aInstituteData);

private:
  vector<shared_ptr<Subject>>      mSubjects;
  vector<shared_ptr<Teacher>>      mTeachers;
  vector<shared_ptr<StudentGroup>> mGroup;
  vector<shared_ptr<Lesson>>       mLessons;
  vector<shared_ptr<Room>>         mRooms;
  shared_ptr<InstituteData>        mInstituteData;
};
