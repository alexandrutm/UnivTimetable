#pragma once

class Observer
{
public:
  virtual void   Update(string aInstruction) = 0;
  virtual string GetModelName()              = 0;

protected:
  string mModelName;
};
