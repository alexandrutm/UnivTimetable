#pragma once

class InstituteData
{
public:
  bool            operator==(const InstituteData & aInfo);
  InstituteData & operator=(const InstituteData &);

  InstituteData(string, int, int, int, int);

  string GetSchoolName();
  int    GetNumberOfHoursPerDay();
  int    GetNumberOfDayPerWeek();
  int    GetStartHour();

  void SetSchoolName(string aSchoolName);
  void SetHoursPerDay(int aHoursPerDay);
  void SetDayPerWeek(int aDayPerWeek);
  void SetStartHour(int startHour);

  vector<string> GetDaysWeek();
  vector<string> GetHoursDay();

private:
  vector<string> mDaysWeek;
  vector<string> mHoursDay;

  string mSchoolName;
  int    mHoursPerDay;
  int    mStartHour;
  int    mFinishHour;
  int    mDaysPerWeek;
};
