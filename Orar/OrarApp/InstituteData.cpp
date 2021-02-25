#include "stdafx.h"
#include "InstituteData.h"

bool InstituteData::operator==(const InstituteData & aInfo)
{
  return mSchoolName == aInfo.mSchoolName ? true : false;
}

InstituteData::InstituteData(string aName, int aHoursPerDay, int aStartHour, int aFinishHour)
  : mSchoolName(aName)
  , mHoursPerDay(aHoursPerDay)
  , mStartHour(aStartHour)
  , mFinishHour(aFinishHour)
{
}

string InstituteData::GetSchoolName()
{
  return mSchoolName;
}

int InstituteData::GetHoursPerDay()
{
  return mHoursPerDay;
}

int InstituteData::GetDayPerWeek()
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
  mStartHour = aDayPerWeek;
}

InstituteData & InstituteData::operator=(const InstituteData & aBasicInfo)
{
  if (this != &aBasicInfo)
  {
    mSchoolName  = aBasicInfo.mSchoolName;
    mStartHour   = aBasicInfo.mStartHour;
    mHoursPerDay = aBasicInfo.mHoursPerDay;
    mStartHour   = aBasicInfo.mStartHour;
    mFinishHour  = aBasicInfo.mFinishHour;
  }

  return *this;
}
