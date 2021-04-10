#pragma once

class Context;
class Lesson;
class TerminationCondition;
class LessonSelection;
class ValueSelection;
class SolutionComparator;

class Solver
{
public:
  Solver(Context & aContext);

  bool FindSolution();

private:
  Context & mContext;

  TerminationCondition * mTerminationContition;
  LessonSelection *      mLessonSelection;
  ValueSelection *       mValueSelection;
  SolutionComparator *   mSolutionComparator;
};
