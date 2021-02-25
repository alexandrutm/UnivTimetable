#pragma once

class InstituteData
{
public:
  bool operator==(const InstituteData & aInfo);

  InstituteData(string, int, int, int);

  string GetSchoolName();
  int    GetHoursPerDay();
  int    GetDayPerWeek();

  void SetSchoolName(string aSchoolName);
  void SetHoursPerDay(int aHoursPerDay);
  void SetDayPerWeek(int aDayPerWeek);

  InstituteData & operator=(const InstituteData &);

private:
  string mSchoolName;
  int    mHoursPerDay;
  int    mStartHour;
  int    mFinishHour;
};
