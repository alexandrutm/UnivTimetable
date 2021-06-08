#pragma once

class Context;
class Lesson;

class Solution
{
public:
  Solution(Context & mContext);

  void FillUnassignedLessons();
  void SortUnassignedLessons();

  bool IsUnassignedLesson();
  void SetAssignedLesson(Lesson * aLesson);

  Lesson * GetNextUnassignedLesson();

  void             UnassignLastAssignedLesson();
  vector<Lesson *> GetAssignedLessons();

private:
  Context & mContext;

  vector<Lesson *> mUnassignedLessons;
  vector<Lesson *> mAssignedLessons;
};
