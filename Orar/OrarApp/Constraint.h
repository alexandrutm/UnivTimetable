#pragma once

class Constraint
{
public:
  virtual ~Constraint()   = 0;
  virtual bool Validate() = 0;
};
