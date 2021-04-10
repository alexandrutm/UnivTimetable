#pragma once

// It combines room and time classes
class Room;
class TimeSlot;

class Placement
{
public:
  Placement(Room * aRoom, TimeSlot * aTimeSlot);

  TimeSlot * GetTimeSlot();
  Room *     GetRoom();

private:
  TimeSlot * mTimeSlot;
  Room *     mRoom;
};
