#include "stdafx.h"
#include "Placement.h"
#include "TimeSlot.h"

Placement::Placement(Room * aRoom, TimeSlot * aTimeSlot)
  : mRoom(aRoom)
  , mTimeSlot(aTimeSlot)
{
}

TimeSlot * Placement::GetTimeSlot()
{
  return mTimeSlot ? mTimeSlot : nullptr;
}

Room * Placement::GetRoom()
{
  return mRoom ? mRoom : nullptr;
}
