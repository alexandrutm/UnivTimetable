#pragma once

class Solution;

class TerminationCondition
{
public:
  bool CanContinue(Solution * aCurrentSolution);

private:
  int    mMaxIter;
  double mTimeOut;
  bool   mStopWehnComplete;
};
