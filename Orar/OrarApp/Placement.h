#pragma once
#include "TimeSlot.h"
// combine time slot and room
class Room;

class Placement
{
public:
  Placement();
  Placement(Room * aRoom, TimeSlot aTimeSlot);
  void SetRoom(Room * aRoom);
  void SetTimeSlot(TimeSlot aTimeSlot);

  Room *   GetRoom();
  TimeSlot GetTimeSlot();

  bool IsValid();

private:
  Room *   mRoom;
  TimeSlot mTimeSlot;
};
