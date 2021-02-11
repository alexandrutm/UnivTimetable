#include "stdafx.h"
#include "InstituteData.h"

bool InstituteData::operator==(const InstituteData & aInfo)
{
  return mId == aInfo.mId;
}

InstituteData::InstituteData(
  string aName, int aHoursPerDay, int aStartHour, int aFinishHour, int aId)
  : mSchoolName(aName)
  , mHoursPerDay(aHoursPerDay)
  , mStartHour(aStartHour)
  , mFinishHour(aFinishHour)
  , mId(aId)
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

int InstituteData::GetId()
{
  return mId;
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
    mId          = aBasicInfo.mId;
  }

  return *this;
}
