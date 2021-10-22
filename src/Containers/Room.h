#pragma once
#include "TimeSlot.h"

class Room
{
public:
  Room(string aName, int aCapacity, int aId);
  bool   operator==(const Room & aRoom);
  Room & operator=(const Room & aRoom);

  void   SetName(string);
  string GetName();

  void SetCapacity(int aCapacity);
  int  GetCapacity();

  int GetId();

  void AddUnavailableTimeslot(pair<int, int> availability);
  void EraseUnavailableTimeslot(pair<int, int> availability);
  bool IsAvailable(pair<int, int> availability);

private:
  string mName;
  int    mCapacity;
  int    mId;

  vector<pair<int, int>> mAvailability;
};
