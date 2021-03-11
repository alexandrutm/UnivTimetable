#include "stdafx.h"
#include "InstituteData.h"

bool InstituteData::operator==(const InstituteData & aInfo)
{
  return mSchoolName == aInfo.mSchoolName ? true : false;
}

InstituteData::InstituteData(
  string aName, int aHoursPerDay, int aStartHour, int aFinishHour, int aDaysPerWeek)
  : mSchoolName(aName)
  , mHoursPerDay(aHoursPerDay)
  , mStartHour(aStartHour)
  , mFinishHour(aFinishHour)
  , mDaysPerWeek(aDaysPerWeek)
{
  // default data
  mDaysWeek.resize(mHoursPerDay);
  mDaysWeek[0] = ("Monday");
  mDaysWeek[1] = ("Tuesday");
  mDaysWeek[2] = ("Wednesday");
  mDaysWeek[3] = ("Thursday");
  mDaysWeek[4] = ("Friday");

  mHoursDay.resize(mHoursPerDay);
  mHoursDay[0]  = ("08:00");
  mHoursDay[1]  = ("09:00");
  mHoursDay[2]  = ("10:00");
  mHoursDay[3]  = ("11:00");
  mHoursDay[4]  = ("12:00");
  mHoursDay[5]  = ("13:00");
  mHoursDay[6]  = ("14:00");
  mHoursDay[7]  = ("15:00");
  mHoursDay[8]  = ("16:00");
  mHoursDay[9]  = ("17:00");
  mHoursDay[10] = ("18:00");
  mHoursDay[11] = ("19:00");
}

string InstituteData::GetSchoolName()
{
  return mSchoolName;
}

int InstituteData::GetNumberOfHoursPerDay()
{
  return mHoursPerDay;
}

int InstituteData::GetNumberOfDayPerWeek()
{
  return mDaysPerWeek;
}

int InstituteData::GetStartHour()
{
  return mStartHour;
}

void InstituteData::SetSchoolName(string aSchoolName)
{
  mSchoolName = aSchoolName;
}

void InstituteData::SetHoursPerDay(int aHoursPerDay)
{
  mHoursPerDay = aHoursPerDay;
}

void InstituteData::SetDayPerWeek(int aDayPerWeek)
{
  mDaysPerWeek = aDayPerWeek;
}

void InstituteData::SetStartHour(int startHour)
{
  mStartHour = startHour;
}

vector<string> InstituteData::GetDaysWeek()
{
  return mDaysWeek;
}

vector<string> InstituteData::GetHoursDay()
{
  return mHoursDay;
}

InstituteData & InstituteData::operator=(const InstituteData & aBasicInfo)
{
  if (this != &aBasicInfo)
  {
    mSchoolName  = aBasicInfo.mSchoolName;
    mStartHour   = aBasicInfo.mStartHour;
    mHoursPerDay = aBasicInfo.mHoursPerDay;
    mFinishHour  = aBasicInfo.mFinishHour;
    mDaysPerWeek = aBasicInfo.mDaysPerWeek;
  }

  return *this;
}
