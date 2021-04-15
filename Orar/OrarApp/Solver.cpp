#include "stdafx.h"
#include "Solver.h"
#include "Lesson.h"

Solver::Solver(Context & aContext)
  : mContext(aContext)
  , mSolution(Solution(mContext))
  , mTerminationCondition(TerminationCondition())
  , mSelectPlacement(SelectPlacement(mContext))
{
}

Solution * Solver::FindSolution()
{
  // Try to place each lesson in an allowed placement
  while (mTerminationCondition.CanContinue(&mSolution))
  {
    // select a lesson and remove it from unassigned lessons;
    auto currentLesson = mSolution.GetNextUnassignedLesson();
    // Search for an available placement for selected lesson, in which this lesson can be placed
    // respecting the constraints. If more slots are available, choose a random one. If none is
    // available, do recursive swapping:
    if (mSelectPlacement.GetPlacement(currentLesson).IsValid())
    {
      currentLesson->SetPlacement(mSelectPlacement.GetPlacement(currentLesson));
      // make lesson unavailable for placement
      mSolution.SetAssignedLesson(currentLesson);
    }
    else
    {
      // we didn't found a placement for the lesson
      // we need to take a step back
    }
  }
  return &mSolution;
}
