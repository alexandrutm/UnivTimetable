#pragma once


class BasicInfo {
public:

	BasicInfo(string, int, int, int);

	string getSchoolName();
	int getAcademicYear();
	int getHoursPerDay();
	int getDayPerWeek();

	void setSchoolName(string aSchoolName);
	void setAcademicYear(int aAcademicYear);
	void setHoursPerDay(int aHoursPerDay);
	void setDayPerWeek(int aDayPerWeek);

	BasicInfo& operator =(const BasicInfo&);

private:

	string mSchoolName;
	int mAcademicYear;
	int mHoursPerDay;
	int mDayPerWeek;

};
