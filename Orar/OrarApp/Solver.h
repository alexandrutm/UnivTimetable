#pragma once

#include "Solution.h"
#include "TerminationCondition.h"

class Context;

class Solver
{
public:
  Solver();

  Solution FindSolution(Context & aContext);

private:
  TerminationCondition mTerminationCondition;
};
