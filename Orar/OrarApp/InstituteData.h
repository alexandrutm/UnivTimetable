#pragma once


class InstituteData
{
  public:
  InstituteData() = default;
  ~InstituteData() = default;
  InstituteData(const InstituteData&) = default;
  bool operator==(const InstituteData& aInfo);

  InstituteData(string, int, int, int, int);

  string GetSchoolName();
  int GetAcademicYear();
  int GetHoursPerDay();
  int GetDayPerWeek();

  void SetSchoolName(string aSchoolName);
  void SetAcademicYear(int aAcademicYear);
  void SetHoursPerDay(int aHoursPerDay);
  void SetDayPerWeek(int aDayPerWeek);

  int GetId();


  InstituteData& operator=(const InstituteData&);

  private:
  string mSchoolName;
  int mAcademicYear;
  int mHoursPerDay;
  int mDayPerWeek;
  int mId;
};

