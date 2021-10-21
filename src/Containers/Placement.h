#pragma once
#include "TimeSlot.h"
// combine time slot and room
class Room;

class Placement
{
public:
  Placement();
  Placement(Room * aRoom, TimeSlot aTimeSlot);
  bool operator==(const Placement & aPlacement);
  void SetRoom(Room * aRoom);
  void SetTimeSlot(TimeSlot aTimeSlot);

  Room *   GetRoom();
  TimeSlot GetTimeSlot();

  bool IsValid();

  void Clear();

private:
  Room *   mRoom;
  TimeSlot mTimeSlot;
};
