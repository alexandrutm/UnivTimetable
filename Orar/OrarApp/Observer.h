#pragma once

class string;

class Observer
{
public:
  virtual void Update(string aInstruction) = 0;
};
