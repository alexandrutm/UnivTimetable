#pragma once
class Teacher;
class Subject;
class Group;
class Lesson;
class InstituteData;
class Room;
class TimeConstraint;

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
  string    SearchTeacher(Teacher * aTeacher);

  void      AddSubject(shared_ptr<Subject> aSubject);
  void      RemoveSubject(int i);
  size_t    GetSubjectSize();
  Subject * GetSubjectByIndex(int i);
  void      DeleteSubjects();
  int       GenerateSubjectId();
  string    SearchSubject(Subject * aSubject);

  int     GenerateGroupId();
  Group * GetRootGroup();
  Group * GetGroupById(int id);
  string  SearchGroup(Group * aGroup);

  void     AddLesson(shared_ptr<Lesson> aLesson);
  void     RemoveLesson(int i);
  size_t   GetLessonSize();
  Lesson * GetLessonByIndex(int i);
  void     DeleteLessons();
  int      GenerateLessonId();

  void   AddRoom(shared_ptr<Room> aRoom);
  void   RemoveRoom(int i);
  size_t GetRoomSize();
  Room * GetRoomByIndex(int i);
  void   DeleteRooms();
  int    GenerateRoomId();

  void            AddInstituteData(shared_ptr<InstituteData> aInstituteData);
  InstituteData * GetInstituteData();

  void             AddConstraint(unique_ptr<TimeConstraint> aConstr);
  size_t           GetConstraintSize();
  TimeConstraint * GetConstraintByIndex(int index);
  void             RemoveConstraint(int index);

private:
  vector<unique_ptr<TimeConstraint>> mConstraints;
  vector<shared_ptr<Subject>>        mSubjects;
  vector<shared_ptr<Teacher>>        mTeachers;
  unique_ptr<Group>                  mRootNodeStudents;
  vector<shared_ptr<Lesson>>         mLessons;
  vector<shared_ptr<Room>>           mRooms;
  shared_ptr<InstituteData>          mInstituteData;
};
