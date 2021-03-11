#pragma once

class Constraints
{
public:
  virtual ~Constraints()  = 0;
  virtual bool Validate() = 0;
};
