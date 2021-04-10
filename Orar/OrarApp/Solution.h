#pragma once

class Context;
class Lesson;
class Placement;

class Solution
{
public:
  Solution(Context &                       aContext,
           vector<pair<Lesson, Placement>> aAssignment,
           long                            iteration,
           double                          time);

  vector<pair<Lesson, Placement>> GetAssignment();
  void                            SetAssignment(vector<pair<Lesson, Placement>> aAssignment);

  double    GetTime();
  long      GetIteration();
  Context * GetContext();

  void SaveBestSolution();
  void RestoreBestSolution();

private:
  Context & mContext;

  vector<pair<Lesson, Placement>> mAssignament;

  double mTime;
  long   mIteration;
};
