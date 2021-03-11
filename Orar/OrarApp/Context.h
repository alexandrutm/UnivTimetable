#pragma once
class Teacher;
class Subject;
class Students;
class Lesson;
class InstituteData;
class Room;
class Constraints;

class Context
{
public:
  Context();
  ~Context();

  void      AddTeacher(shared_ptr<Teacher> aTeacher);
  void      RemoveTeacher(int i);
  size_t    GetTeacherSize();
  Teacher * GetTeacherByIndex(int i);
  void      DeleteTeachers();
  int       GenerateTeacherId();

  void      AddSubject(shared_ptr<Subject> aSubject);
  void      RemoveSubject(int i);
  size_t    GetSubjectSize();
  Subject * GetSubjectByIndex(int i);
  void      DeleteSubjects();
  int       GenerateSubjectId();

  int        GenerateClassId();
  Students * GetRootClass();

  void                 AddLesson(shared_ptr<Lesson> aLesson);
  void                 RemoveLesson(int i);
  size_t               GetLessonSize();
  shared_ptr<Lesson> & GetLessonByIndex(int i);
  void                 DeleteLessons();
  int                  GenerateLessonId();

  void   AddRoom(shared_ptr<Room> aRoom);
  void   RemoveRoom(int i);
  size_t GetRoomSize();
  Room * GetRoomByIndex(int i);
  void   DeleteRooms();
  int    GenerateRoomId();

  void                      AddInstituteData(shared_ptr<InstituteData> aInstituteData);
  shared_ptr<InstituteData> GetInstituteData();

  void AddConstraint(unique_ptr<Constraints> aConstr);
  void DeleteConstraint();

private:
  vector<unique_ptr<Constraints>> mConstraints;
  vector<shared_ptr<Subject>>     mSubjects;
  vector<shared_ptr<Teacher>>     mTeachers;
  unique_ptr<Students>            mRootNodeStudents;
  vector<shared_ptr<Lesson>>      mLessons;
  vector<shared_ptr<Room>>        mRooms;
  shared_ptr<InstituteData>       mInstituteData;
};
