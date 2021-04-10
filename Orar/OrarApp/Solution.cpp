#include "stdafx.h"
#include "Solution.h"
#include "Context.h"
#include "Lesson.h"

Solution::Solution(Context &                       aContext,
                   vector<pair<Lesson, Placement>> aAssignment,
                   long                            aIteration,
                   double                          aTime)
  : mContext(aContext)
  , mAssignament(aAssignment)
  , mIteration(aIteration)
  , mTime(aTime)
{
}

// get assignment associated with this solution
vector<pair<Lesson, Placement>> Solution::GetAssignment()
{
  return mAssignament;
}

void Solution::SetAssignment(vector<pair<Lesson, Placement>> aAssignment)
{
  mAssignament = aAssignment;
}

// current solution time (time in seconds from the start of the solver)
double Solution::GetTime()
{
  return mTime;
}

long Solution::GetIteration()
{
  return mIteration;
}

Context * Solution::GetContext()
{
  return &mContext;
}

void Solution::SaveBestSolution()
{
  mContext.getbest
}
