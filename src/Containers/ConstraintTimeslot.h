#pragma once
class Timeslot
{
public:
  Timeslot(int aDayNumber, int aHourNumber);

  const int GetDayNumber() const;
  const int GetHourNumber() const;

private:
  int mDayNumber;
  int mHourNumber;
};
