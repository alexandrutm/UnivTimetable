#include "stdafx.h"
#include "TerminationCondition.h"
#include "Context.h"
#include "Lesson.h"
#include "Solution.h"

bool TerminationCondition::CanContinue(Solution * aCurrentSolution)
{
  if (mMaxIter >= 0 && aCurrentSolution->GetIteration() >= mMaxIter)
  {  // maximum number of iteration reached.
    return false;
  }

  if (mTimeOut >= 0 && aCurrentSolution->GetTime() > mTimeOut)
  {
    // timeout reached
    return false;
  }

  if (mStopWehnComplete)
  {
    // Complete solution found
    return !aCurrentSolution->GetContext()->GetUnassignedLessons().empty() ? true : false;
  }

  return true;
}
