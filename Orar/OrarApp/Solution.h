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

  // get next available lesson
  Lesson * GetNextUnassignedLesson();

  void             UnassignLastAssignedLesson();
  vector<Lesson *> GetAssignedLessons();

private:
  Context & mContext;

  vector<Lesson *> mUnassignedLessons;
  vector<Lesson *> mAssignedLessons;
};
