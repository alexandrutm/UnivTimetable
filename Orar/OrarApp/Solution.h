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

  // get next available lesson and remove it from unassigned lessons
  Lesson * GetNextUnassignedLesson();

  void             UnassignLastAssignedLesson();
  void             SetUnassignedLesson(Lesson * aLesson);
  vector<Lesson *> GetAssignedLessons();

  //

private:
  Context & mContext;

  vector<Lesson *> mUnassignedLessons;
  vector<Lesson *> mAssignedLessons;
};
