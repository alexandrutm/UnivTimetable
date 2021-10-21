#pragma once

class InstituteData
{
public:
  bool            operator==(const InstituteData & aInfo);
  InstituteData & operator=(const InstituteData &);

  InstituteData(string aName      = "Institution name",
                int    aNrOfHours = 12,
                int    aStartHour = 8,
                int    aEndHour   = 20,
                int    aDayWeek   = 5);

  string GetSchoolName();
  int    GetNumberOfHoursPerDay();
  int    GetNumberOfDaysPerWeek();
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
  int    mNumberOfHoursPerDay;
  int    mStartHour;
  int    mFinishHour;
  int    mNumberOfDaysPerWeek;
};
