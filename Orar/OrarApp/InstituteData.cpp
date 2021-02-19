#include "stdafx.h"
#include "InstituteData.h"

// bool InstituteData::operator==(const InstituteData & aInfo)
//{
//   return
//}

InstituteData::InstituteData(string aName, string aStartHour = "08:00", int aHoursPerDay = 12)
  : mSchoolName(aName)
  , mStartHour(aStartHour)
  , mHoursPerDay(aHoursPerDay)
{
}

string InstituteData::GetSchoolName()
{
  return mSchoolName;
}

string InstituteData::GetStartHour()
{
  return mStartHour;
}

int InstituteData::GetHoursPerDay()
{
  return mHoursPerDay;
}

void InstituteData::SetSchoolName(string aSchoolName)
{
  mSchoolName = aSchoolName;
}

void InstituteData::SetStartHour(string aStartHour)
{
  mStartHour = aStartHour;
}

void InstituteData::SetHoursPerDay(int aHoursPerDay)
{
  mHoursPerDay = aHoursPerDay;
}

InstituteData & InstituteData::operator=(const InstituteData & aBasicInfo)
{
  if (this != &aBasicInfo)
  {
    mSchoolName  = aBasicInfo.mSchoolName;
    mStartHour   = aBasicInfo.mStartHour;
    mHoursPerDay = aBasicInfo.mHoursPerDay;
  }

  return *this;
}
