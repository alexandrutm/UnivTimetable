#include"stdafx.h"
#include"Context.h"
#include"Teacher.h"
#include"BasicInfo.h"
#include"Classes.h"
#include"Subject.h"
#include"Lesson.h"
#include"Room.h"

Context::Context()
{

}

void Context::AddTeacher(shared_ptr<Teacher> aTeacher)
{
	mTeachers.push_back(aTeacher);
}

void Context::RemoveTeacher(shared_ptr<Teacher>aTeacher)
{
	mTeachers.erase(remove_if(mTeachers.begin(), mTeachers.end(), [&](auto const& teacher) {
		return *teacher == *aTeacher;
		}), mTeachers.end());

	//erase_if(mTeachers, [&](auto const& teacher) {return *teacher == *aTeacher; });

}

void Context::EditTeacher(shared_ptr<Teacher> aOldTeacher,shared_ptr<Teacher> aNewTeacher)
{
	auto it = find_if(mTeachers.begin(), mTeachers.end(), [&](shared_ptr<Teacher>const& t) {
		return *t == *aOldTeacher;
		});

	if (it != mTeachers.end()) {
		(*it) = aNewTeacher;
	}
}

vector<shared_ptr<Teacher>>& Context::GetTeachers()
{
	return mTeachers;
}

int Context::GetTeacherSize()
{
	return mTeachers.size();
}

shared_ptr<Teacher> Context::GetTeacherByIndex(int i)
{
	return mTeachers[i];
}

void Context::AddSubject(shared_ptr<Subject> aSubject)
{
	mSubjects.push_back(aSubject);
}

void Context::RemoveSubject(shared_ptr<Subject> aSubject)
{
	auto i = begin(mSubjects);

	while (i != end(mSubjects))
	{
		if ((*i) == aSubject)
		{
			i = mSubjects.erase(i);
			break;
		}
		else
			i++;
	}
}

void Context::EditSubject(shared_ptr<Subject> aSubject, shared_ptr<Subject> aNewSubject)
{
	auto i = find_if(mSubjects.begin(), mSubjects.end(), [&](shared_ptr<Subject>const& s)
		{
			return *s == *aSubject;
		});

	if (i != mSubjects.end())
	{
		(*i) = aNewSubject;
	}
}

vector<shared_ptr<Subject>>& Context::GetSubjects()
{
	return mSubjects;
}

int Context::GetSubjectSize()
{
	return mSubjects.size();
}

shared_ptr<Subject> Context::GetSubjectByIndex(int i)
{
	return mSubjects[i];
}

void Context::AddClass(shared_ptr<Classes> aClass)
{
	mClasses.push_back(aClass);
}

void Context::RemoveClass(shared_ptr<Classes> aClass)
{
	auto i = begin(mClasses);

	while (i != end(mClasses))
	{
		if ((*i) == aClass)
		{
			i = mClasses.erase(i);
			break;
		}
		else
			i++;
		
	}
}

void Context::EditClasses(shared_ptr<Classes> aClass, shared_ptr<Classes> aNewClass)
{
	auto it = find_if(mClasses.begin(), mClasses.end(), [&](shared_ptr<Classes>const& c)
		{
			return *c == *aClass;
		});

	if (it != mClasses.end())
	{
		(*it) = aNewClass;
	}
}

vector<shared_ptr<Classes>>& Context::GetClasses()
{
	return mClasses;
}

int Context::GetClassSize()
{
	return mClasses.size();
}

shared_ptr<Classes> Context::GetClassByIndex(int i)
{
	return mClasses[i];
}

void Context::AddLesson(shared_ptr<Lesson> aLesson)
{
	mLessons.push_back(aLesson);
}

void Context::RemoveLesson(shared_ptr<Lesson> aLesson)
{
	auto i = begin(mLessons);

	while (i != end(mLessons))
	{
		if ((*i) == aLesson)
		{
			i = mLessons.erase(i);
			break;
		}
		else
			i++;

	}
}

void Context::EditLesson(shared_ptr<Lesson> aLesson, shared_ptr<Lesson> aNewLesson)
{
	auto it = find_if(mLessons.begin(), mLessons.end(), [&](shared_ptr<Lesson>const& c)
		{
			return *c == *aNewLesson;
		});

	if (it != mLessons.end())
	{
		(*it) = aNewLesson;
	}

}

vector<shared_ptr<Lesson>>& Context::GetLessons()
{
	return mLessons;
}

int Context::GetLessonSize()
{
	return mLessons.size();
}

shared_ptr<Lesson> Context::GetLessonByIndex(int i)
{
	return mLessons[i];
}

void Context::AddRoom(shared_ptr<Room> aRoom)
{
	mRooms.push_back(aRoom);
}

void Context::RemoveRoom(shared_ptr<Room> aRoom)
{
	auto it = begin(mRooms);

	while (it != end(mRooms))
	{
		if (*it == aRoom)
		{
			it = mRooms.erase(it);
			break;
		}
		else
			it++;
	}
}

void Context::EditRoom(shared_ptr<Room> aRoom, shared_ptr<Room> aNewRoom)
{
	auto it = find_if(mRooms.begin(), mRooms.end(), [&](shared_ptr<Room>const& r)
		{
			return *r == *aRoom;
		});

	if (it != mRooms.end())
	{
		(*it) = aNewRoom;
	}
}

vector<shared_ptr<Room>>& Context::GetRooms()
{
	return mRooms;
}

int Context::GetRoomSize()
{
	return mRooms.size();
}

shared_ptr<Room> Context::GetRoomByIndex(int i)
{
	return mRooms[i];
}

void Context::AddBasicInfo(shared_ptr<BasicInfo> aBasicInfo)
{
	mBasicInfo = aBasicInfo;
}

void Context::DeleteData()
{
	mTeachers.clear();
	mSubjects.clear();
	mClasses.clear();
	mLessons.clear();
	mRooms.clear();
	mBasicInfo.reset();
}
