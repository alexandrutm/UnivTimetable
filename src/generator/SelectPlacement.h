#pragma once
#include "src/containers/Placement.h"

class Lesson;
class Context;

class SelectPlacement
{
public:
  SelectPlacement(Context & aContext);
  Placement        GetPlacement(Lesson * aLesson);
  vector<TimeSlot> GetAvailableTimeslots(Lesson * aLesson, Room * aRoom);
  vector<Room *>   GetRoomsSortedByCapacity(Lesson * aLesson);
  void             MakePlacementAvailable(Lesson * aLesson);

private:
  Context & mContext;

  vector<vector<int>> mTimeSlotMatrix;
};
