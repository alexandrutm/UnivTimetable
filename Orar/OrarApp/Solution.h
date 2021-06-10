#pragma once

class Context;
class Lesson;

class Solution
{
public:
  Solution(Context & mContext);
  Solution & operator=(const Solution & aSolution);

  void FillUnassignedLessons();
  void SortUnassignedLessons();

  bool IsUnassignedLesson();
  void SetAssignedLesson(Lesson * aLesson);

  Lesson * GetNextUnassignedLesson();

  void             UnassignLastAssignedLesson();
  vector<Lesson *> GetAssignedLessons();

  bool IsComplete();

private:
  Context & mContext;

  vector<Lesson *> mUnassignedLessons;
  vector<Lesson *> mAssignedLessons;
};
