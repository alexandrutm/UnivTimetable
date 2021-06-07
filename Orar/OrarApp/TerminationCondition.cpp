#include "stdafx.h"
#include "TerminationCondition.h"
#include "Solution.h"

bool TerminationCondition::CanContinue(Solution * aSolution)
{
  // if (mMaxIter >= 0 && aCurrentSolution->GetIteration() >= mMaxIter)
  //  if (mTimeOut >= 0 && aCurrentSolution->GetTime() > mTimeOut)
  return aSolution->IsUnassignedLesson();
}
