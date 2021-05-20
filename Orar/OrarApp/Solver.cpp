#include "stdafx.h"
#include "Solver.h"
#include "Lesson.h"
#include "SelectPlacement.h"

Solver::Solver()
  : mTerminationCondition(TerminationCondition())
{
}

Solution Solver::FindSolution(Context & aContext)
{
  SelectPlacement selectPlacement(aContext);
  Solution        solution(aContext);

  // Try to place each lesson in an allowed placement && give a timer
  while (mTerminationCondition.CanContinue(&solution))
  {
    // select a lesson and remove it from unassigned lessons;
    auto currentLesson = solution.GetNextUnassignedLesson();
    // Search for an available placement for selected lesson, in which this lesson can be placed
    // respecting the constraints. If more slots are available, choose a random one. If none is
    // available, do backtr
    auto placement = selectPlacement.GetPlacement(currentLesson);

    if (placement.IsValid())
    {
      currentLesson->SetPlacement(placement);
      // make lesson unavailable for placement
      solution.SetAssignedLesson(currentLesson);
    }
    else
    {
      // we didn't found a placement for the lesson
      solution.SetUnassignedLesson(currentLesson);
      currentLesson->ClearVisitedPlacements();
      // we need to take a step back
      // pop_back last lesson and choose another placement for it

      solution.UnassignLastAssignedLesson();
    }
  }
  return solution;
}
