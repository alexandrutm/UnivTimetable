#pragma once
class Teacher;
class Subject;
class Group;
class Lesson;
class InstituteData;
class Room;
class Constraint;

class Context
{
public:
  Context();
  ~Context();

  void                AddTeacher(shared_ptr<Teacher> aTeacher);
  void                RemoveTeacher(int i);
  size_t              GetTeacherSize();
  shared_ptr<Teacher> GetTeacherByIndex(int i);
  void                DeleteTeachers();
  int                 GenerateTeacherId();

  void                AddSubject(shared_ptr<Subject> aSubject);
  void                RemoveSubject(int i);
  size_t              GetSubjectSize();
  shared_ptr<Subject> GetSubjectByIndex(int i);
  void                DeleteSubjects();
  int                 GenerateSubjectId();

  int     GenerateClassId();
  Group * GetRootClass();
  Group * GetClassById(int id);

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

  void            AddInstituteData(shared_ptr<InstituteData> aInstituteData);
  InstituteData * GetInstituteData();

  void         AddConstraint(unique_ptr<Constraint> aConstr);
  void         DeleteConstraint();
  size_t       GetConstraintSize();
  Constraint * GetConstraintByIndex(int index);
  void         RemoveConstraint(int index);

private:
  vector<unique_ptr<Constraint>> mConstraints;
  vector<shared_ptr<Subject>>    mSubjects;
  vector<shared_ptr<Teacher>>    mTeachers;
  unique_ptr<Group>              mRootNodeStudents;
  vector<shared_ptr<Lesson>>     mLessons;
  vector<shared_ptr<Room>>       mRooms;
  shared_ptr<InstituteData>      mInstituteData;
};
