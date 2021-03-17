#pragma once

class Constraint
{
public:
  virtual ~Constraint()                                 = 0;
  virtual string                 GetConstraintName()    = 0;
  virtual vector<pair<int, int>> GetConstraintDetails() = 0;
  virtual bool                   Validate()             = 0;
};
