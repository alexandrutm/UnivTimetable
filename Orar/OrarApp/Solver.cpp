#include "stdafx.h"
#include "Solver.h"
#include "LessonSelection.h"
#include "Solution.h"
#include "TerminationCondition.h"

Solver::Solver(Context & aContext)
  : mContext(aContext)
  , mLessonSelection(new LessonSelection())
  , mTerminationContition(new TerminationCondition())
  ,

{
}

bool Solver::FindSolution()
{
  Solution * solution = new Solution(mContext);
  while (mTerminationContition->CanContinue(solution))
  {
    // select a lesson
    Lesson * lesson = mLessonSelection->SelectLesson(solution);
    // select a time slot and a room(value)

    //(un)assign the selected value to the selected variable
    // if (value != null)
    //  variable.assign(value);
    // else
    //   variable.unassign();

    // if the solution is the best ever found then memorize it
    // if (SolutionComparator.IsBetterThanBest(solution))
    //   solution.saveBest();
  }
  // restore the best ever found solution
  // solution.restoreBest();
  // return solution;
}
