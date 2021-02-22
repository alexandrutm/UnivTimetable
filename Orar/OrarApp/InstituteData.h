#pragma once

class InstituteData
{
public:
  InstituteData()                      = default;
  ~InstituteData()                     = default;
  InstituteData(const InstituteData &) = default;
  // bool operator==(const InstituteData & aInfo);

  InstituteData(string, string, int);

  string GetSchoolName();
  string GetStartHour();
  int    GetHoursPerDay();

  void SetSchoolName(string aSchoolName);
  void SetStartHour(string aStartHour);
  void SetHoursPerDay(int aHoursPerDay);

  InstituteData & operator=(const InstituteData &);

private:
  string mSchoolName;
  string mStartHour;
  int    mHoursPerDay;
};
