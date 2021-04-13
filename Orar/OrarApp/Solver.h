#pragma once

class Solution;
class Context;
class TerminationCondition;
class SelectPlacement;

class Solver
{
public:
  Solver(Context & aContext);

  Solution * FindSolution();

private:
  unique_ptr<Solution> mSolution;

  Context & mContext;

  unique_ptr<TerminationCondition> mTerminationCondition;
  unique_ptr<SelectPlacement>      mSelectPlacement;
};
