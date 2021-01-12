#pragma once


class Subject;
class Teacher;
class Classes;

class Lesson
{
public:

	Lesson() = default;
	~Lesson() = default;
	Lesson(const Lesson&) = default;


	Lesson(shared_ptr<string>, shared_ptr<string>, shared_ptr<string>, shared_ptr<int>);


private:

	shared_ptr<string> mSubject;
	shared_ptr<string> mTeacher;
	shared_ptr<string> mClass;
	shared_ptr<int> mHoursPerWeek;
};

Q_DECLARE_METATYPE(Lesson);
