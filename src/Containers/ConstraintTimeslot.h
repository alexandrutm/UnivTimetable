#pragma once
class Timeslot
{
public:
  Timeslot(int aDayNumber, int aHourNumber);
  bool       operator==(const Timeslot & aOther) const;
  Timeslot & operator=(const Timeslot & aOther);

  const int GetDayNumber() const;
  const int GetHourNumber() const;

private:
  int mDayNumber;
  int mHourNumber;
};
