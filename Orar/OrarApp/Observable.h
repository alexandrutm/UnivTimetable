#pragma once

class Observer;

class Observable
{
protected:
  virtual void RegisterObserver(Observer * aObserver) = 0;
  virtual void RemoveObserver(Observer * aObserver)   = 0;
  virtual void NotifyObserver(Observer * aObserver)   = 0;
};
