#pragma once


class Subject;
class Teacher;
class Classes;

class Lesson
{


private:

	Subject* mSubject;
	Teacher* mTeacher;
	Classes* mClass;
	int mHoursPerWeek;
};
