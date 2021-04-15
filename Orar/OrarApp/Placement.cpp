#include "stdafx.h"
#include "Placement.h"
#include "Room.h"

Placement::Placement()
{
  mRoom = nullptr;
}

Placement::Placement(Room * aRoom, TimeSlot aTimeSlot)
  : mRoom(aRoom)
  , mTimeSlot(aTimeSlot)
{
}

void Placement::SetRoom(Room * aRoom)
{
  mRoom = aRoom;
}

void Placement::SetTimeSlot(TimeSlot aTimeSlot)
{
  mTimeSlot = aTimeSlot;
}

Room * Placement::GetRoom()
{
  return mRoom;
}

TimeSlot Placement::GetTimeSlot()
{
  return mTimeSlot;
}

bool Placement::IsValid()
{
  return mRoom == nullptr ? false : true;
}
