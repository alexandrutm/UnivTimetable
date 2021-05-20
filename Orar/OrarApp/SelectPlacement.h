#pragma once
#include "Placement.h"

class Lesson;
class Context;

class SelectPlacement
{
public:
  SelectPlacement(Context & aContext);
  Placement        GetPlacement(Lesson * aLesson);
  vector<TimeSlot> GetAvailableTimeslotForTeacherAndGroup(Lesson * aLesson);

private:
  Context & mContext;

  vector<vector<int>> mTimeSlotMatrix;
};
