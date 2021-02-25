#pragma once

class Subject;
class Teacher;
class StudentGroup;

class Lesson
{
public:
  bool     operator==(const Lesson & aLesson);
  Lesson & operator=(const Lesson & l);

  Lesson(shared_ptr<Teacher>, shared_ptr<Subject>, shared_ptr<StudentGroup>, int, int);

  void SetTeacher(shared_ptr<Teacher> aTeacher);
  void SetClass(shared_ptr<StudentGroup> aClass);
  void SetSubject(shared_ptr<Subject> aSubject);
  void SetNumberOfHours(int aNumberOfHours);

  shared_ptr<Teacher>      GetTeacher();
  shared_ptr<StudentGroup> GetGroup();
  shared_ptr<Subject>      GetSubject();
  int                      GetNumberOfHours();
  int                      GetId();

private:
  shared_ptr<Subject>      mSubject;
  shared_ptr<Teacher>      mTeacher;
  shared_ptr<StudentGroup> mGroup;
  int                      mHoursPerWeek;
  int                      mId;
};
