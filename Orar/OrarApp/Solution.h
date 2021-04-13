#pragma once

class Context;
class Lesson;

class Solution
{
public:
  Solution(Context & mContext);

  void FillUnassignedLessons();

  void SortUnassignedLessons();

  vector<Lesson *> GetUnassignedLessons();
  void             SetAssignedLesson(Lesson * aLesson);

  Lesson * GetNextUnassignedLesson();
  void     SetLessonAsUnassigned();

private:
  Context & mContext;

  vector<Lesson *> mUnassignedLessons;
  vector<Lesson *> mAssignedLessons;
};
