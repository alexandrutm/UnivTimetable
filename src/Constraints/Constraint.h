#pragma once

class Constraint
{
public:
  virtual ~Constraint()                                               = 0;
  virtual const string &                 GetConstraintName() const    = 0;
  virtual const vector<pair<int, int>> & GetConstraintDetails() const = 0;
};
