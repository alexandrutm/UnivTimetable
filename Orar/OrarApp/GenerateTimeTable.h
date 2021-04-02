#pragma once

class Context;
class TimeSlot;
class Lesson;
class Room;

class GenerateTimeTable
{
public:
  GenerateTimeTable(Context & aContext);

  bool GetNextAvailableTimeSlot(Lesson * aLesson);
  bool IsGenerated();

private:
  Context &           mContext;
  vector<vector<int>> timeSlotMatrix;
};
