#include "stdafx.h"
#include "InstituteData.h"

bool InstituteData::operator==(const InstituteData & aInfo)
{
  return mId == aInfo.mId;
}

InstituteData::InstituteData(
  string aName, int aAcademicYear, int aHoursPerDay, int aDaysPerWeek, int aId)
  : mSchoolName(aName)
  , mAcademicYear(aAcademicYear)
  , mHoursPerDay(aHoursPerDay)
  , mDayPerWeek(aDaysPerWeek)
  , mId(aId)
{
}

string InstituteData::GetSchoolName()
{
  return mSchoolName;
}

int InstituteData::GetAcademicYear()
{
  return mAcademicYear;
}

int InstituteData::GetHoursPerDay()
{
  return mHoursPerDay;
}

int InstituteData::GetDayPerWeek()
{
  return mDayPerWeek;
}

void InstituteData::SetSchoolName(string aSchoolName)
{
  mSchoolName = aSchoolName;
}

void InstituteData::SetAcademicYear(int aAcademicYear)
{
  mAcademicYear = aAcademicYear;
}

void InstituteData::SetHoursPerDay(int aHoursPerDay)
{
  mHoursPerDay = aHoursPerDay;
}

void InstituteData::SetDayPerWeek(int aDayPerWeek)
{
  mDayPerWeek = aDayPerWeek;
}

int InstituteData::GetId()
{
  return mId;
}

InstituteData & InstituteData::operator=(const InstituteData & aBasicInfo)
{
  if (this != &aBasicInfo)
  {
    mSchoolName   = aBasicInfo.mSchoolName;
    mDayPerWeek   = aBasicInfo.mDayPerWeek;
    mHoursPerDay  = aBasicInfo.mHoursPerDay;
    mAcademicYear = aBasicInfo.mAcademicYear;
    mId           = aBasicInfo.mId;
  }

  return *this;
}
