#pragma once

class Subject;
class Teacher;
class Group;

class Lesson
{
public:
  bool     operator==(const Lesson & aLesson);
  Lesson & operator=(const Lesson & l);

  Lesson(shared_ptr<Teacher>, shared_ptr<Subject>, Group *, int, int);

  void SetTeacher(shared_ptr<Teacher> aTeacher);
  void SetClass(Group * aClass);
  void SetSubject(shared_ptr<Subject> aSubject);
  void SetNumberOfHours(int aNumberOfHours);

  shared_ptr<Teacher> GetTeacher();
  Group *             GetGroup();
  shared_ptr<Subject> GetSubject();
  int                 GetNumberOfHours();
  int                 GetId();

private:
  shared_ptr<Subject> mSubject;
  shared_ptr<Teacher> mTeacher;
  Group *             mStudentClass;
  int                 mHoursPerWeek;
  int                 mId;
};
