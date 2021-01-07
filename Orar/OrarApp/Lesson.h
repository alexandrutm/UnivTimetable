#pragma once


class Subject;
class Teacher;
class Classes;

class Lesson
{
public:
	Lesson(shared_ptr<string>, shared_ptr<string>, shared_ptr<string>, shared_ptr<int>);


private:

	shared_ptr<string> mSubject;
	shared_ptr<string> mTeacher;
	shared_ptr<string> mClass;
	shared_ptr<int> mHoursPerWeek;
};
