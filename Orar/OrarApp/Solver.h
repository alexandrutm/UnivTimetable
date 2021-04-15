#pragma once

#include "SelectPlacement.h"
#include "Solution.h"
#include "TerminationCondition.h"

class Context;

class Solver
{
public:
  Solver(Context & aContext);

  Solution * FindSolution();

private:
  Context & mContext;

  Solution mSolution;

  TerminationCondition mTerminationCondition;
  SelectPlacement      mSelectPlacement;
};
