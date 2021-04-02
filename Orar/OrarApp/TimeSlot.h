#pragma once

class TimeSlot
{
public:
  TimeSlot();
  TimeSlot(int aDayOfWeek, int aStartTime, int aEndTime);

  bool IsValid();

  void SetStartTime(int aStartTime);
  void SetEndTime(int aEndTime);
  void SetDayOfWeek(int aDayOfWeek);

  /*int GetId();*/
  int GetDayOfWeek();
  int GetStartTime();
  int GetEndTime();

private:
  /* int mId;*/

  int mDayOfWeek;
  int mStartTime;
  int mEndTime;
};
