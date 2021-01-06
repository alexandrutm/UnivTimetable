#include"stdafx.h"
#include "BasicInfo.h"


string BasicInfo::getSchoolName()
{
	return mSchoolName;
}

int BasicInfo::getAcademicYear()
{
	return mAcademicYear;
}

int BasicInfo::getHoursPerDay()
{
	return mHoursPerDay;
}

int BasicInfo::getDayPerWeek()
{
	return mDayPerWeek;
}

void BasicInfo::setSchoolName(string aSchoolName)
{
	mSchoolName = aSchoolName;
}

void BasicInfo::setAcademicYear(int aAcademicYear)
{
	mAcademicYear = aAcademicYear;
}

void BasicInfo::setHoursPerDay(int aHoursPerDay)
{
	mHoursPerDay = aHoursPerDay;
}

void BasicInfo::setDayPerWeek(int aDayPerWeek)
{
	mDayPerWeek = aDayPerWeek;
}

BasicInfo& BasicInfo::operator=(const BasicInfo& aBasicInfo)
{
	if (this == &aBasicInfo)
	{
		return *this;
	}
	
	mSchoolName = aBasicInfo.mSchoolName;
	mAcademicYear = aBasicInfo.mAcademicYear;
	mHoursPerDay = aBasicInfo.mHoursPerDay;
	mDayPerWeek = aBasicInfo.mDayPerWeek;
	
	return *this;
}
