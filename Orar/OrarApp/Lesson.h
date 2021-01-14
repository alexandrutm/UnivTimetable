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

	Lesson(shared_ptr<Teacher>, shared_ptr<Classes>, shared_ptr<Subject>, shared_ptr<int>);

	void SetTeacher(shared_ptr<Teacher>aTeacher);
	void SetClass(shared_ptr<Classes>aClass);
	void SetSubject(shared_ptr<Subject>aSubject);
	void SetNumberOfHours(shared_ptr<int> aNumberOfHours);

	shared_ptr<Teacher> GetTeacher();
	shared_ptr<Classes> GetClass();
	shared_ptr<Subject>GetSubject();
	shared_ptr<int> GetNumberOfHours();

	bool operator==(const Lesson& aLesson);

private:

	shared_ptr<string> mSubject;
	shared_ptr<string> mTeacher;
	shared_ptr<string> mClass;
	shared_ptr<int> mHoursPerWeek;
};

Q_DECLARE_METATYPE(Lesson);
