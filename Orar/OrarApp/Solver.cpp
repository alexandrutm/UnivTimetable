#include "stdafx.h"
#include "Solver.h"
#include "Lesson.h"
#include "SelectPlacement.h"
#include "Solution.h"
#include "TerminationCondition.h"

Solver::Solver(Context & aContext)
  : mContext(aContext)
{
  mSolution             = make_unique<Solution>(mContext);
  mTerminationCondition = make_unique<TerminationCondition>();
  mSelectPlacement      = make_unique<SelectPlacement>(mContext);
}

Solution * Solver::FindSolution()
{
  // Try to place each lesson in an allowed placement
  while (mTerminationCondition->CanContinue(mSolution.get()))
  {
    // select a lesson
    auto currentLesson = mSolution->GetNextUnassignedLesson();
    // Search for an available placement for selected lesson, in which this lesson can be placed
    // respecting the constraints. If more slots are available, choose a random one. If none is
    // available, do recursive swapping:
    currentLesson->SetPlacement(mSelectPlacement->GetPlacement(currentLesson));
  }
  return mSolution.get();
}
